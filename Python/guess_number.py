from random import *
from copy import *


def score_cal(rlst, tlst, glst, cdcp, cdwp):
    if glst == rlst:
        print("You have guessed the number correctly. You won the game.")
        return 1
    else:
        for i in range(0, 4):
            if glst[i] in tlst:
                if glst[i] == rlst[i]:
                    cdcp.append(glst[i])
                else:
                    cdwp.append(glst[i])
                tlst[tlst.index(glst[i])] = -35487
        print(len(cdcp), " correct digits at correct position: ", cdcp)
        print(len(cdwp), " correct digits at wrong position ", cdwp)
        return 0


def result(ch):
    while ch == 1:
        ran, score = randint(1000, 9999), 20
        rlst, ng = [int(i) for i in str(ran)], 10
        while ng > 0:
            tlst, cdcp, cdwp = deepcopy(rlst), [], []
            guess = int(input("Guess the 4 digit number : "))
            glst = [int(i) for i in str(guess)]

            rtd=score_cal(rlst, tlst, glst, cdcp, cdwp)

            if(rtd==1):
                score+=5
                break
            else:
                score-=2
            ng -= 1
            print("Sorry wrong number. Guess again.\nGuesses left : ",ng)

        print("Your score is : ", score)
        ch = int(input("You have finished the game. Do you want to play again?\n1 - Yes\n0 - No\n"))


result(int(input("Do you want to play the MASTERMIND GAME?\n1 - Yes\n0 - No\n")))
