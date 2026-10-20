

def main():
    n = int(input())
    foods = []
    total_time = 0

    for _ in range(n):
        temp, time = input().split()
        temp, time = int(temp), int(time)

        foods.append([temp, time])

    foods.sort(reverse=True)

    while foods:
        temp, time = foods.pop()
        if time <= 0:
            continue
        total_time += time

        for i in range(len(foods)-1, -1, -1):
            if foods[i][0] - temp > 10:
                break
            foods[i][1] -= time

    print(total_time)


main()
