from math import sqrt


class node:
    def __init__(self, x, y, r):
        self.edges = []
        self.colour = 0
        self.x = x
        self.y = y
        self.r = r


def main():
    cnt = int(input())
    nodes = []

    for _ in range(cnt):
        x, y, r = map(int, input().split())
        nodes.append(node(x, y, r))

    for i, n in enumerate(nodes):
        x, y, r = n.x, n.y, n.r

        for j, other_node in enumerate(nodes):
            if j == i:
                continue

            diff_x = abs(other_node.x - x)
            diff_y = abs(other_node.y - y)

            if sqrt(diff_x**2 + diff_y**2) <= r + other_node.r:
                n.edges.append(other_node)

    stack = []
    visited = set()

    for i in range(len(nodes)):
        if nodes[i] in visited:
            continue
        nodes[i].colour = 1
        stack.append(nodes[i])
        visited.add(nodes[i])

        while stack:
            n = stack.pop()
            for e in n.edges:
                if e.colour == n.colour:
                    print('No')
                    return
                e.colour = 1 if n.colour == 2 else 2
                if e not in visited:
                    stack.append(e)
                    visited.add(e)
    print('Yes')


main()
