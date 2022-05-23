
def countSubstring(s,l):
    ans = 0
    i = 0
    while i < l:
        cnt0 = 0
        cnt1 = 0

        if s[0] == '0':
            while i < l and s[i] == '0':
                cnt0 += 1
                i += 1

            j = i

            while j < l and s[j] == '1':
                cnt1 += 1
                j += 1
        else :
            while i < l and s[i] == '1' :
                cnt1 += 1
                i += 1
            j = i

            while j < l and s[j] == '0':
                cnt0 += 1
                j += 1
        ans += min(cnt0,cnt1)

def main():
    s = input("Enter a string of 0's and 1's: ")

    l = len(s)
    c = countSubstring(s,l)
    print('No. of substrings are: ',c)

if __name__ == '__main__':

    main()
    
