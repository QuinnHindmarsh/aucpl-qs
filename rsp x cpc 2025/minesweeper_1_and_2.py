def main():
    x, y = map(int, input().split())
    print(len(bin(x+y+1))-3)


main()
