import math as m
def solve(n):
    k = int(m.log2(n)+1)
    p = 2 ** k
    p -= 1
    t1 = n ^ p
    k = n + t1
    k = k // 2
    ans = n ^ k
    ans = ans * k
    return ans
    
if __name__ == "__main__":
   t = int(input())
   while t:
       n = int(input())
       print(solve(n))
       t -= 1
    
