import sys


def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    tablets = data[1:1 + n]

    # 52 possible feature-nodes:
    #   0..25  -> a letter sitting in position 1 (left glyph)
    #   26..51 -> a letter sitting in position 2 (right glyph)
    # A tablet "XY" is an EDGE from node(pos1, X) to node(pos2, Y).
    NODES = 52

    def node(pos, ch):                       # pos: 0 = left, 1 = right
        return (ord(ch) - 65) + (0 if pos == 0 else 26)

    adj = [[] for _ in range(NODES)]         # adj[u] = list of (neighbour, edge_id)
    deg = [0] * NODES

    for eid, t in enumerate(tablets):
        u = node(0, t[0])
        v = node(1, t[1])
        adj[u].append((v, eid))
        adj[v].append((u, eid))
        deg[u] += 1
        deg[v] += 1

    # An Eulerian trail exists only with 0 or 2 odd-degree nodes.
    odd = [x for x in range(NODES) if deg[x] & 1]
    if len(odd) not in (0, 2):
        print("IMPOSSIBLE")
        return

    # Start at an odd node if one exists (forced top/bottom of the stack),
    # otherwise any node that actually has edges.
    start = odd[0] if odd else next((x for x in range(NODES) if deg[x] > 0), -1)
    if start == -1:                          # no tablets at all
        print("POSSIBLE")
        return

    # Hierholzer's algorithm (iterative), recording the ORDER OF EDGES (tablets).
    used = [False] * n
    ptr = [0] * NODES                        # next-unexamined edge index per node
    stack = [(start, -1)]                    # (vertex, edge used to arrive here)
    trail = []                               # edge ids, collected in reverse
    while stack:
        u, e = stack[-1]
        while ptr[u] < len(adj[u]) and used[adj[u][ptr[u]][1]]:
            ptr[u] += 1
        if ptr[u] == len(adj[u]):
            stack.pop()
            if e != -1:
                trail.append(e)
        else:
            v, eid = adj[u][ptr[u]]
            ptr[u] += 1
            used[eid] = True
            stack.append((v, eid))
    trail.reverse()

    # If the graph was disconnected, the trail can't cover every tablet.
    if len(trail) != n:
        print("IMPOSSIBLE")
        return

    print("POSSIBLE")
    print("\n".join(tablets[eid] for eid in trail))   # top -> bottom


solve()
