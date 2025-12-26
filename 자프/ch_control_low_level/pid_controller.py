import numpy as np
import matplotlib.pyplot as plt

# Parameters
m = 1000      # mass of vehicle (kg)
c = 100000    # electro-mechanical transfer coefficient
gamma = 0.02  # wind resistance coefficient
v_ref = 60    # reference speed (e.g., km/h)
dt = 0.1      # time step (s)
t_end = 10    # total simulation time (s)
Kp = 100      # proportional gain
Ki = 0.2      # integral gain
Kd = 10       # derivative gain

# Time vector
t = np.arange(0, t_end, dt)
v = np.zeros_like(t)
u = np.zeros_like(t)

# Simulation loop
E = 0
old_e = v_ref - v[0]
for i in range(1, len(t)):
    e = v_ref - v[i-1]
    E = e + E
    e_dot = e - old_e
    u[i] = Kp * e + Ki * E + Kd * e_dot
    dv = (m / c * u[i] - gamma * v[i-1]) * dt
    v[i] = v[i-1] + dv
    old_e = e

# Plotting
plt.figure(figsize=(7, 5))
plt.plot(t, v, label='Vehicle Speed')
plt.axhline(v_ref, color='red', linestyle='--', label='Reference Speed')
plt.xlabel('Time (s)')
plt.ylabel('Speed (kmph)')
plt.title('(Kp, Ki, Kd) = (%.1f, %.1f, %.1f)' % (Kp, Ki, Kd))
plt.legend()
plt.grid(True)
plt.show()