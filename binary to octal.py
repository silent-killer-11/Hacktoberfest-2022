num=input()
n=list(num)
k=0
re=1
for i in n:
    if i=='0' or i=='1':
        continue
    else:
        print ("Invalid input")
        k=1
        break
if k==1:
    exit
else:
    x=int(''.join(n))
    print(oct(x))
