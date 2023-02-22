"""
basic breadth first search syntax

"""

q = []
while q:
    node, level = q.pop()
    node.pop()
    for i in edges[node]:
        if not visited:
            q.append(i)
