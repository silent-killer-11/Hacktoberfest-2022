s=input()
c=0
k=[]
for i in range(len(s)):
    if(s[i]==' '):
        c=c+1
    if s[i]!=' ' and c!=0:
        k.append(c)
        c=0
    i=i+1
x=s.split()
m=[]
n=0
l=k[::-1]
for i in l:
    m.append(x[n])
    for p in range(i):
        m.append(' ')
    n=n+1
m.append(x[n])
print(''.join(m))
