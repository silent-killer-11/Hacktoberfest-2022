alphabet_numbers = [None,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

user_input = input("Enter a word : ").upper()
arr=[]
for val in user_input : 
    if val in alphabet_numbers:
        arr.append(alphabet_numbers.index(val))
print(sum(arr))