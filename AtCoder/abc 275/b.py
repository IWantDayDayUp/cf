
def main():
    a, b, c, d, e, f = [int(c) for c in input().split(' ')]
    
    ans = a * b * c - d * e * f
    ans %= 998244353
    
    print(ans)
    

if __name__ == "__main__":
    main()
    