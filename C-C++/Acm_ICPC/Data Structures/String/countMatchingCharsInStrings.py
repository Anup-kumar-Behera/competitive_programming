def countChar(s1,s2):

    c = 0
    j = 0

    for i in range(len(s1)):

        if s1[i] in s2:
            c += 1
        j += 1
    print('No of matching characters are :',c)

if __name__ == '__main__':
    s1 = input('Enter 1st string: ')
    s2 = input('Enter 2nd string: ')

    countChar(s1,s2)
