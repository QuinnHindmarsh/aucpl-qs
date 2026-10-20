from sortedcontainers import SortedList


def main():

    _ = int(input())
    tmp = list(map(int, input().split()))

    s = SortedList(tmp)
    _ = int(input())
    nums = list(map(int, input().split()))
    for num in nums:
        p = s.bisect_right(num)
        if s[p-1] == num:
            continue
        elif p != len(s):
            print(
                f'A greedy member at {num} has pushed in front of the member at {s[p]}, this is terrible')
        s.add(num)


main()
