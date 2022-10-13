import random


def game(comp,you):
    if (comp==you):
        return None
    elif (comp=="paper"):
        if (you=="rock"):
            return False
        elif (you=="scissor"):
            return True
    elif (comp=="rock"):
        if (you=="paper"):
            return True
        elif (you=="scissor"):
            return False
    elif (comp=="scissor"):
        if (you=="rock"):
            return True
        elif (you=="paper"):
            return False
    

print("comp turn: paper(1),rock(2),scissor(3)")
randno = random.randint(1,3)
if (randno==1):
    comp = "paper"
elif (randno==2):
    comp = "rock"
elif (randno==3):
    comp = "scissor"

you = input("your turn: paper,rock,scissor\t")

print(f"computer choice = {comp}  ,  your choice = {you}")
a = game(comp,you)
if a == False:
    print("you lose")
elif a == True:
    print("you won")
elif a == None:
    print("it's a tie")
    