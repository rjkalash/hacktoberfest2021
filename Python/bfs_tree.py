# BFS algorithm in Python


import collections

# BFS algorithm
def bfs(graph, root):

    visited, queue = set(), collections.deque([root])
    visited.add(root)

    while queue:

        # Dequeue a vertex from queue
        vertex = queue.popleft()
        print(str(vertex) + " ", end=" ")

        # If not visited, mark it as visited, and
        # enqueue it
        if vertex in graph:
            for neighbour in graph[vertex]:
                if neighbour not in visited:
                    visited.add(neighbour)
                    queue.append(neighbour)


if __name__ == '__main__':
    graph = {
        0:[1,3],
        1:[2,4],
        2:[5],
        3:[4,6],
        4:[5,7],
        6:[4,7],
        7:[5,8]}
    print("Following is Breadth First Traversal: ")
    bfs(graph, 0)
