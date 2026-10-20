def main(): 
    n = int(input())
    cnt = 0    
    levels = 0 

    while cnt <= n: 
        cnt += levels * (levels +1) /2
        levels += 1

    print(levels -2)

main()
