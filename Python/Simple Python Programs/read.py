from tkinter import *
import pyttsx3
from tkinter import filedialog

window = Tk()
window.title("Text to Speech")
window.geometry("420x320")
window.configure(background = "Black")
window.iconbitmap('onepiece.ico')


#---------Creating menu----------
main = Menu(window)
window.configure(menu = main)

def helper():
	help_window = Toplevel()
	help_window.title("Help")
	help_window.configure(background = "Black")
	help_window.geometry("320x450")
	help_window.iconbitmap('help_icon.ico')
	
	header = Label(help_window, text ="Help",font = ('Bold',25), fg = "green", bg = "black")
	header.grid(row = 0, column = 1, columnspan = 2, pady = 10)

	info_header = Label(help_window, text = "** Info **", font = ('Bold', 20), fg = "green", bg = "black")
	info_header.grid(row = 1, column = 1, columnspan = 1, pady = 3)
	info_text1= Label(help_window, text = "This Program allows you to listen", font = 20, fg = "green", bg = "black")
	info_text1.grid(row = 2, column = 1, columnspan = 1)
	info_text2= Label(help_window, text = "text files into audio format.", font = 20, fg = "green", bg = "black")
	info_text2.grid(row = 3, column = 1, columnspan = 1, pady = 10)

	note_line1 = Label(help_window, text = "** Note **", font = ('Bold', 20), fg = "green", bg = "black")
	note_line1.grid(row = 4, column = 1, columnspan = 1, pady = 3)
	note_line2 = Label(help_window, text = "This Program does not create output file.", font = 20, fg = "green", bg = "black") 
	note_line2.grid(row = 5, column = 1, columnspan = 1, pady = 10)

	help_header = Label(help_window, text = "** Help **", font = ('Bold', 20), fg = "green", bg = "black")
	help_header.grid(row = 6, column = 1, columnspan = 1, pady = 3)
	help_text1 = Label(help_window, text = "Enter the speech speed rate at the entrybox.", font = 20, fg = "green", bg = "black")
	help_text1.grid(row = 7, column = 1, columnspan = 1, pady = 10)
	help_text2 = Label(help_window, text = "Click on choosefile Button to choose", font = 20, fg = "green", bg = "black")
	help_text2.grid(row = 9, column = 1, columnspan = 1)
	help_text3 = Label(help_window, text = "the file you want to listen as audio.", font = 20, fg = "green", bg = "black")
	help_text3.grid(row = 10, column = 1, columnspan = 1)
	help_text4 = Label(help_window, text = "Click on Start Reading Button to convert.", font = 20, fg = "green", bg = "black")
	help_text4.grid(row = 11, column = 1, columnspan = 1, pady = 10)

#--------File menu-------
file_menu = Menu(main)
main.add_cascade(label="File", menu = file_menu)
#----------File Sub menu Quit -------
file_menu.add_command(label = "Quit", command = window.quit)

#Help Menu
help_menu = Menu(main)
main.add_cascade(label = "Help", menu = help_menu)
#-------Sub menu of help------
help_menu.add_command(label ="Help", command = helper)

#-----------Heading-----------
Heading = Label(window, text = "Text To Speech Converter", font = ('Bold',25), fg = "white", bg = "black")
Heading.grid(column = 1, row = 0, columnspan = 3,pady = 20)

def choosefile():
	global filepath
	#----------Getting Filepath-------
	filepath = filedialog.askopenfilename()

def read():
	#-------Opening File Path------
	file = open(filepath , 'r')
	#-------Initializing function-------
	engine = pyttsx3.init()
	#-------If Given Input = True Try Block--- Otherwise except Block----
	try:
		 engine.setProperty('rate', int(Set_speed.get()))
	except:
		engine.setProperty('rate', 130)

	#-------Speaking contents Inside the file		
	engine.say(file.read())
	engine.runAndWait()

	file.close()

# ---------Recommended Label----------
recommended = Label(window, text = "Recommended Speed : 130 ", font = 20, fg = "white", bg = "black")
recommended.grid(column= 1 , row = 1 ,columnspan = 2,pady = 10)

#----------Setting Speech Speed Label--------
setspeed = Label(window, text = "Set Speech Speed ", font = 20, fg = "white", bg = "black")
setspeed.grid(column= 0 , row = 2 ,columnspan = 2, padx= 10)

#----------Setting Speech Speed --------
Set_speed = Entry(window, width = 25, font = 20,bd = 3, fg = "white", bg = "black")
Set_speed.grid(column = 2, row = 2, pady = 10, columnspan = 2)


#----------Choose File------------
choose_file = Button(window, text  = "Choose File", command = choosefile , padx = 20,pady = 5, bd= 5, font = 20, fg = "white", bg = "black")
choose_file.grid(row = 4,column = 2,pady = 10)

#----------Start Reading Button ----------
Open = Button(window, text = "Start Reading", command = read , padx = 20,pady = 5, bd= 5, font = 20, fg = "white", bg = "black")
Open.grid(row = 5, column = 2 ,pady = 10, padx = 20)

window.mainloop()