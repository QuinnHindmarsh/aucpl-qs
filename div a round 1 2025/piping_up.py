from copy import deepcopy


def floyd(matrix):
    ans = deepcopy(matrix)

    for k in range(len(matrix)):
        for j in range(len(matrix)):
            for i in range(len(matrix)):
                if min(ans[i][k], ans[k][j]) > ans[i][j]:
                    ans[i][j] = min(ans[i][k], ans[k][j])
                    ans[j][i] = ans[i][j]
    return ans


def main():
    # precompute this in some way?
    # floyd wharshals

    n = int(input())
    matrix = [[-1] * n for _ in range(n)]

    m = int(input())
    for _ in range(m):
        a, b, w = map(int, input().split())
        a, b = a - 1, b-1
        matrix[a][b] = w
        matrix[b][a] = w

    ans = floyd(matrix)

    q = int(input())
    for _ in range(q):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        print(f'{ans[a][b]}')


main()
