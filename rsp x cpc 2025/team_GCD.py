from math import gcd


class union_find:
    def __init__(self):
        self.productivity = None
        self.parent = None
        self.rank = 1

    def find(node):
        if node.parent != node:
            node.parent = union_find.find(node.parent)
            return node.parent

        return node

    def union(n1, n2):
        p1 = union_find.find(n1)
        p2 = union_find.find(n2)

        if p1 == p2:
            return p1.productivity

        if p1.rank > p2.rank:
            p2.parent = p1
            p2.rank += 1
            p1.productivity = gcd(p1.productivity, p2.productivity)
            return p1.productivity
        else:
            p1.parent = p2
            p1.rank += 1
            p2.productivity = gcd(p1.productivity, p2.productivity)
            return p2.productivity


def main():
    n = int(input())
    employees = input().split()

    for i in range(len(employees)):
        uf = union_find()
        uf.parent = uf
        uf.productivity = int(employees[i])
        employees[i] = uf

    days = int(input())

    for _ in range(days):
        i, j = map(int, input().split())
        i -= 1
        j -= 1
        print(union_find.union(employees[i], employees[j]))


main()
