

def main():
    n = input()
    cnt = int(input())
    seen = {}
    arr = []
    arr.append(n)
    seen[n] = 0

    while True:
        asc = sorted(list(n))
        desc = sorted(list(n), reverse=True)

        n = str(abs(int(''.join(asc)) - int(''.join(desc))))

        n = ('0' * (4 - len(n))) + n
        if n in seen:
            cycle_length = len(arr) - seen[n] 
            break
        seen[n] = len(arr)
        arr.append(n)

    if cnt < len(arr): 
        print(arr[cnt])
    else:
        pre_cycle = len(arr) - cycle_length
        cnt -= pre_cycle
        print(arr[pre_cycle + (cnt % cycle_length)])


main()
