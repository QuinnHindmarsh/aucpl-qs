from bisect import bisect_right


def pre_process():
    n = 10**15 + 1
    cnt = 0
    arr = []
    levels = 1

    while cnt <= n:
        cnt += levels * (levels + 1) / 2
        levels += 1
        arr.append(cnt)

    return arr


def main():
    arr = pre_process()
    ans = []

    n = int(input())

    for _ in range(n):
        num = int(input())
        ans.append(bisect_right(arr, num))

    for num in ans:
        print(num)


main()
