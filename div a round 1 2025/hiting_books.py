

def main():
    book = input()
    n = int(input())
    keywords = {}

    for _ in range(n):
        word, utility = input().split()
        utility = int(utility)

        keywords[word] = utility

    # map each start point, to slow?
    # Aho–Corasick 
