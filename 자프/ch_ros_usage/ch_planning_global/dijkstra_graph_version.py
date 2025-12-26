import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    predecessors = {node: None for node in graph}
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        
        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                predecessors[neighbor] = current_node
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances, predecessors

def reconstruct_path(predecessors, start, end):
    path = []
    current = end
    while current is not None:
        path.append(current)
        current = predecessors[current]
    path.reverse()
    if path[0] == start:
        return path
    else:
        return []  # No path found

def main():
    graph = {
        'A': [ ('B', 7), ('E', 3), ('F', 10) ],
        'B': [ ('A', 7), ('C', 4), ('D', 10), ('E', 2), ('F', 6) ],
        'C': [ ('B', 4), ('D', 2) ],
        'D': [ ('B', 10), ('C', 2), ('E', 11), ('F', 9), ('G', 4) ],
        'E': [ ('A', 3), ('B', 2), ('D', 11), ('G', 5)],
        'F': [ ('A', 10), ('B', 6), ('D', 9) ],
        'G': [ ('D', 4), ('E', 5) ],
    }
    start = 'A'
    distances, predecessors = dijkstra(graph, start)
    print(f"Shortest paths from {start}:")
    for node in graph:
        path = reconstruct_path(predecessors, start, node)
        if path:
            print(f"Path to {node}: {' -> '.join(path)} (Distance: {distances[node]})")
        else:
            print(f"No path to {node}")

if __name__ == "__main__":
    main()
