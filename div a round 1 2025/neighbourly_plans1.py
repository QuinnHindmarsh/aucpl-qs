from math import sqrt
def main(): 
    n = int(input())
    tom = []
    patrick = []
    for _ in range(n): 
        x,y = map(int,input().split())

        tom.append((x,y))

    m = int(input())

    for _ in range(m): 
        x,y = map(int,input().split())
        patrick.append((x,y))

    mn = float('inf')
    mn_pair = []
    for i in range(n): 
        for      j in range(m): 
            x1,y1 = tom[i]
            x2,y2 = patrick[j]

            distance = sqrt(abs(x1-x2)**2 + abs(y1-y2)**2)
            if distance < mn and distance != 0 : 
                mn = distance
                mn_pair = [(x1,y1),(x2,y2)]
    
    print(f'{mn_pair[0][0]} {mn_pair[0][1]}')
    print(f'{mn_pair[1][0]} {mn_pair[1][1]}')

main()
