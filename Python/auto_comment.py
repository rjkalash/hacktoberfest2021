import keyboard
import pyautogui
import time
from keyboard import press

comments=[]
for i in range(20): 
    comments.append("Auto commenting post in facebook post")

time.sleep(3)
"""
range(20) indicate there are 20 content in comments=[] and post 20 comment in facebook
all you have to do is run the script and take you pointer to comment section
"""
for i in range(20):
    pyautogui.typewrite(comments[i])
    time.sleep(0.3)
    keyboard.press('enter')
    pyautogui.typewrite("\n")
    keyboard.press('enter')
    time.sleep(0.2)


