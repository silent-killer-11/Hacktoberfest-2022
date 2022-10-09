'''This is a computer based Break Timer program to remind you to take regular breaks while working on your desk for good health. 
Some of us spend at least sixty per cent (if not more) of our day sitting on a chair working on a computer or for some other work.
This physical inactivity for such long durations causes diseases like varicose veins, weak bones, back problems, weak digestion and 
can even increase the risk of cancer. Doctors around the world suggest good posture while sitting and taking regular breaks from your work. 
You can walk around and stretch a little bit for a healthy life.

Here is what the code does. Once you run it on your computer or in any shell, it reminds you to take a break 
after a predetermined time through an audio announcement. It also randomly selects a video from a list (already fed in the program) 
and plays it to further motivate you to leave the desk and move around.'''


from pygame import mixer
from datetime import datetime
from time import time

def musiconloop(file,stopper):
    mixer.init()
    mixer.music.load(file)
    mixer.music.play(-1)
    while True:
        a = input()
        if a == stopper:
            mixer.music.stop()
            break

def logs(user_log):
    with open("logs.txt", "a") as log_file:
        log_file.write(f"{user_log} at {datetime.now()}\n")
        print("logs has been saved")



if __name__ == "__main__":

    init_water = time()
    init_eyes_exercise = time()
    init_excercise = time()
    water_in_sec = 2400
    eyes_excercise_in_sec = 1800
    excercise_in_sec = 2700

    while True:
        if time() - init_water > water_in_sec:
            print("Its time to drink your water, type stop to stop the music ")
            musiconloop("water.mp3","stop")
            logs("drank water")
            init_water = time()

        if time() - init_eyes_exercise > eyes_excercise_in_sec:
            print("Its time for  your eyes exercise, type done to stop the music ")
            musiconloop("eyes.mp3","done")
            logs("eyes exercise done")
            init_eyes_exercise = time()

        
        if time() - init_excercise > excercise_in_sec:
            print("Its time for a exercise, type done to stop the music ")
            musiconloop("excercise.mp3","done")
            logs("exercise done")
            init_excercise = time()

        
