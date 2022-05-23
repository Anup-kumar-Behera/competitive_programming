arr = ["geeks",'for','coding']
def countVowel(s):
    l = len(s)
    d = {}
    c,i = 0,0
    
    while i < l:
        for j in range(len(s[i])) :
            if s[i][j] == 'a' or  s[i][j] == 'e' or  s[i][j] == 'i' or  s[i][j] == 'o' or  s[i][j] == 'u':
                c +=1
        d[s[i]] = c


d = {}
d = countVowel(arr)
print(d)
