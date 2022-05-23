def nfa(s):
    a = 0
    b = 0
    c = 0

    l,i = len(s),0

    for i in range(l):
        if s[i] == 'a':
            a += 1
        elif s[i] == 'b':
            b += 1
        elif s[i] == 'c':
            c += 1
    if a%3 == 0 or b%3 == 0 or c%3 == 0:
        print('ACCEPTED')
    else:
        print('NOT ACCEPTED')

if __name__ == '__main__':
    s = input('Enter a string consists of only a,b and c : ')

    nfa(s)
        
        
