print("+-----------------------------------+")
print("|   Finding Average from 5 Number   |")
print("+-----------------------------------+")
inputan = input("Type 5 Number (Separate with comma) : ")
num = inputan.split(',')

summ = 0
for i in range(len(num)):
    summ += int(num[i])

print("\n Average from 5 number is : " + str(summ/5)+'\n\n')