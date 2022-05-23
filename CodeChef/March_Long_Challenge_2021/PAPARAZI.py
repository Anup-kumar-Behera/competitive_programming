# cook your code here
if __name__ == '__main__':
    t = int(input())
    
    while t :
        n = int(input())
        arr = list(map(int, input().split()))
        
        if n <= 2:
            print(1)
        else:
            ans = 1
            a = []
            for x in range(n):
                a.append([x, arr[x]])
            #print(a)
            b = []
            b.append(a[0])
            b.append(a[1])
            l = len(b)
            
            for x in range(2, n):
                while l >= 2:
                    s1 = (b[l-1][1]-b[l-2][1]) / (b[l-1][0]-b[l-2][0])
                    s2 = (a[x][1]-b[l-1][1]) / (a[x][0]-b[l-1][0])
                    
                    if s2 >= s1:
                        b.pop()
                        l -=1
                    else:
                        break
                
                b.append(a[x])
                l += 1
                ans = max(ans, abs(b[l-1][0] - b[l-2][0]))    
            print(ans)
        t -= 1
