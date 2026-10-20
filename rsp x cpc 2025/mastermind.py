

def main():
    n = int(input())
    yes = []
    no = []
    valid = set([i for i in range(1, 101)])

    for _ in range(n):
        d, yn = input().split()
        d = int(d)
        if yn == 'Yes':
            yes.append(d)
        else:
            no.append(d)

    for num in yes:
        for i in range(1, 101):
            if i % num != 0:
                valid.discard(i)
    for num in no:
        for i in range(num, 101, num):
            valid.discard(i)

    print(list(valid)[0])


main()
