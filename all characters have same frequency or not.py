#python code
s=input('')
l=list(s)
z=set(l)
z1=list(z)
c=[]
for i in z1:
    c.append(l.count(i))
m=set(c)
n=list(m)
z=[max(c)-i for i in c]
if len(m)==1:
    print('valid string')
elif sum(z)==1 or (sum(z)==2 and c.count(min(c))==1):
    print('make it valid')
else:
    print('not valid' )
