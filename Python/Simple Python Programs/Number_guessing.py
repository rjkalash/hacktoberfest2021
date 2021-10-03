import random

try: 
	i = 1
	while i <= 5 :

		attempts = 5
		guess = input("Enter a number between 1 to 5: ")
		guess = int(guess)
		number = random.randint(1,5)
		number_range = range(1,6)
		print(number)
		if number == guess and attempts != 0 :
			print("Your guess "+ str(number) + " is correct.")
			break
		elif number != guess and attempts !=0 :
	 		print("Your guess was incorrect.")
	 		print("\n")
	 		attempts = attempts - i 
	 		print("You have " + str(attempts) + " attempts left.")
		elif number != guess and attempts == 0 :
	 		print("Your guess was incorrect.")
	 		print("\n")
	 		print("You are out of attempts")	

		i += 1
except:
	if not type(guess) is int:
		print("Invalid input")
		print("Please enter a integer")		