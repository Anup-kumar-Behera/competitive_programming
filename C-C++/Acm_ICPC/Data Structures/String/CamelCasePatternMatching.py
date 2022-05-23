s = input("Enter as string: ")

def camelCase(s):
    l = len(s)
    a = ''
    i = 0
    while i < l:
        if(s[i] >= 'A' and s[i] <= 'Z'):
          a = a+s[i]
    return a

    
a = camelCase(s)
print(a)
