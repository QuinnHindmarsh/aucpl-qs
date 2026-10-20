from collections import defaultdict


def main():
    n = int(input())
    freq = defaultdict(int)
    mx_freq = 0
    mx_key = ''

    for _ in range(n):
        freq[input()] += 1

    for key, value in freq.items():
        if value > mx_freq or (value == mx_freq and len(key) < len(mx_key)):
            mx_key = key
            mx_freq = value

    print(mx_key)


main()
