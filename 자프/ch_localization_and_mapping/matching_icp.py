import sys
import math
import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial import KDTree

def read_scan_points(file):
  fp = open(file, 'r')
  points = []
  for data in fp:
    data = data.replace('\n', '')
    data = data.split(' ')
    x = float(data[0])
    y = float(data[1])
    points.append([x, y])
  fp.close()
  return points

def make_transformation_matrix(tx, ty, theta):
  mat = np.array([
    [np.cos(theta), -np.sin(theta), tx],
    [np.sin(theta), np.cos(theta), ty],
    [0.0, 0.0, 1.0]
  ])
  return mat

def transform_points(mat, points):
  for i in range(len(points)):
    point = np.array([points[i][0], points[i][1], 1.0])
    transformed_point = np.dot(mat, point)
    points[i] = [transformed_point[0], transformed_point[1]]
  return points

def skewd(v):
  return np.array([v[1], -v[0]])

def expmap(v):
  t = v[2]
  c = np.cos(t)
  s = np.sin(t)
  if np.abs(t) < 1e-10:
    V = np.eye(2)
  else:
    a = (1.0 - c) / t
    V = np.array([[s / t, -a], [a, s / t]])
  R = np.array([[c, -s], [s, c]])
  u = np.array([v[0], v[1]])
  t = np.dot(V, u)
  T = np.eye(3)
  T[:2, :2] = R
  T[0, 2] = t[0]
  T[1, 2] = t[1]
  return T

def plot_points(points1, points2, title, block):
  x1, y1 = zip(*points1)
  x2, y2 = zip(*points2)
  plt.clf()
  plt.xlim(-10.0, 15.0)
  plt.ylim(-10.0, 15.0)
  plt.scatter(x2, y2, color='blue', label='Target points', s=20)
  plt.scatter(x1, y1, color='red', label='Source points', s=10)
  plt.legend()
  plt.grid(True)
  plt.title(title)
  plt.xlabel('X [m]')
  plt.ylabel('Y [m]')
  plt.legend(loc='upper left', fontsize=12)
  plt.show(block=block)
  plt.draw()
  plt.pause(0.2)
  return

def icp_scan_matching(trans_mat, source_points, target_points):
  max_iter_num = 30
  scan_step = 10
  max_dist = 3.0
  epsilon = 1e-4
  kdtree = KDTree(target_points)

  for iter_num in range(max_iter_num):
    H = np.zeros((3, 3))
    g = np.zeros(3)
    R = trans_mat[:2, :2]
    corresponding_points_num = 0

    for i in range(0, len(source_points), scan_step):
      point = np.array([source_points[i][0], source_points[i][1], 1.0])
      transformed_point = np.dot(trans_mat, point)
      query = [transformed_point[0], transformed_point[1]]
      dist, idx = kdtree.query(query)
      if dist > max_dist:
        continue

      target = target_points[idx]
      error = np.array([target[0] - query[0], target[1] - query[1], 0.0])
      v = np.dot(R, skewd(source_points[i]))
      J = np.zeros((3, 3))
      #J[0:2, 0:2] = -R
      J[0:2, 0:2] = -np.identity(2)
      J[0, 2] = v[0]
      J[1, 2] = v[1]
      H += np.dot(J.T, J)
      g += np.dot(J.T, error)
      corresponding_points_num += 1

    delta = np.linalg.solve(H, -g)
    update = np.dot(delta, delta)
    trans_mat = np.dot(trans_mat, expmap(delta))
    title = 'ICP scan matching (' + str(iter_num + 1) + " iteration)"
    plot_points(transform_points(trans_mat, source_points), target_points, title, False)
    print(iter_num, update)
    # if iter_num in [ 3, 6, 9, 12, 15, 18, 21, 24 ]:
    #   plt.show()
    if update < epsilon:
      print('ICP scan matching has converged')
      plot_points(transform_points(trans_mat, source_points), target_points, title, True)
      #plt.show()
      break

  return trans_mat

def main():
  scan_points1 = read_scan_points('./data/scan_1.txt')
  scan_points2 = read_scan_points('./data/scan_2.txt')
  trans_mat1 = make_transformation_matrix(0.0, 0.0, 0.0)
  trans_mat2 = make_transformation_matrix(1.0, 0.0, 0.5)
  transformed_points1 = transform_points(trans_mat1, scan_points1)
  transformed_points2 = transform_points(trans_mat2, scan_points2)
  plot_points(transformed_points1, transformed_points2, '', True)
  #plt.show()
  trans_mat1 = icp_scan_matching(trans_mat1, transformed_points1, transformed_points2)
  return

if __name__ == '__main__':
    main()
