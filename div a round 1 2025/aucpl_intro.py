

def main():
    x = int(input())
    mx_team = ''
    mx_qs = 0
    mx_time = 0

    for _ in range(x):
        name = input()
        n = int(input())
        qs = time = 0
        comps = []

        for _ in range(n):
            q, t = map(int, input().split())
            comps.append((q, t))
        comps.sort(key=lambda x: (-x[0], x[1]))

        for i in range(min(6, len(comps))):
            qs += comps[i][0]
            time += comps[i][1]

        if qs > mx_qs or (qs == mx_qs and time < mx_time):
            mx_team = name
            mx_qs = qs
            mx_time = time

    print(mx_team)


main()
