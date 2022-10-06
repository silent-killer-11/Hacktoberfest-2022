n=int(input())
arr=[]
elements_count={}
for i in range(n):
    s=input()
    arr.append(s)
for element in arr:
   if element in elements_count:
      elements_count[element] += 1
   else:
      elements_count[element] = 1
sorted_values=sorted(elements_count, key=lambda k: (-elements_count[k], k))
print(len(elements_count))
for val in sorted_values:
    print(val)


