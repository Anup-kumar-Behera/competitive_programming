if __name__ == "__main__":
   
    n,h,x = list(map(int,input().split()))
    l = list(map(int,input().split()))
   
    mx = 0
   
    for i in l :
        mx=max(i,mx)
   
    if mx+h >= x :
        print("YES")
    else :
        print("NO")
        