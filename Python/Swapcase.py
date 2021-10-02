print('Swapcase')

s = input()

sn = ''

for i in s:
    if i.islower() == True:
        sn += i.upper()
    elif i.isupper() == True:
        sn += i.lower()
    else:
        sn += i
        
print(sn)
