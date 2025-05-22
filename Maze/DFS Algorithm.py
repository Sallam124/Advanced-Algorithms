def dfs(graph, start, goal, path=None, visited=None):
    if path is None:
        path = []
    if visited is None:
        visited = set()

    path.append(start)
    visited.add(start)

    if start == goal:
        return path

    for neighbor in graph[start]:
        if neighbor not in visited:
            result = dfs(graph, neighbor, goal, path, visited)
            if result:
                return result

    path.pop()
    return None



graph = {
    'A': ['B'],
    'B': ['C', 'D'],
    'C': [],
    'D': ['E'],
    'E': ['F', 'K'],
    'F': ['G'],
    'G': [],
    'H': ['I', 'D'],
    'I': [],
    'J': ['N'],
    'K': ['M'],
    'L': ['O', 'P'],
    'M': ['O', 'R'],
    'N': ['O'],
    'O': ['P', 'T'],
    'P': ['Q'],
    'Q': ['D'],
    'R': ['T', 'X'],
    'S': ['U'],
    'T': ['R', 'V'],
    'U': ['O', 'S'],
    'V': ['W'],
    'W': ['X'],
    'X': ['G'],
    'Y': ['S'],
    'Z': ['Y'],
    'AA': ['Z'],
    'AB': ['AC'],
    'AC': ['AF'],
    'AD': [],
    'AE': [],
    'AF': ['AE']
}


start_node = 'A'
goal_node = 'AD'
path = dfs(graph, start_node, goal_node)

print("Path:", path)
