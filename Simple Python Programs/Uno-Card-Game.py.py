
#Author: Sujal Samai
#Date Created: 1 Aug 2021
#Title: UNO CARD GAME



# Importing libraries
import random


def buildDeck():
    deck = []
    colors = ["Red","Green","Yellow","Blue"]
    values = [0,1,2,3,4,5,6,7,8,9,"Draw Two","Skip","Reverse", "Draw Four"]

    # appending combination of all this 3 list into the deck using for loops
    for color in colors:
        for value in values:
            card="{} {}".format(color, value)              
            deck.append(card)
            if value !=0:
                deck.append(card)
    
    wilds = ["Wild","Wild draw four"]
    for wild in range(4):
        deck.append(wilds[0])
        deck.append(wilds[1])
    
    #print(deck)
    return deck



def shuffleDeck(deck):
    for card_position in range(len(deck)):               
        random_position = random.randint(0, 107)                 
        deck[card_position],deck[random_position]= deck[random_position],deck[card_position]  

    return deck




def drawCards(numCards):
    cardDrawn = []
    for cards in range(numCards):
        cardDrawn.append(unoDeck.pop(0))
    return cardDrawn



def showHand(player, playerHand):
    # printing whose turn it is with +1 for index
    print("Player {}'s Turn".format(player+1))
    print("Your Hand")
    print("*****************************")
    x = 1 # index for the cards
    for card in playerHand:
        print("{}. {}".format(x,card))                   
        x+=1                         
    print("")


def canPlay(color, value, playerHand):
    # checking cards in playerHand returning true if color or value is present or the card is wild else returning false
    for card in playerHand:
        if "Wild" in card:
            return True
        elif color in card or value in card:
            return True
    return False


unoDeck = buildDeck()                               # storing the cards in a variable
unoDeck = shuffleDeck(unoDeck)                      # storing shuffled deck in a variable
# print(unoDeck)
discards = []                                       # list for our discard pile

players = []

colors = ["Red", "Green", "Yellow", "Blue"]
# taking number of players as input we will be having 2 to 4 players
print("")
numPlayers = int(input("Enter the number of players (2/3/4): "))
if numPlayers<2 or numPlayers>4:
    numPlayers = int(input("Invalid input... Please Enter the number of players between 2-4: "))
num=int(input("Enter How many cards you want to draw for each player (4-7): "))
print("")
print("Let's begin the Game!!")
print("")
for player in range(numPlayers):
    players.append(drawCards(num))

# print(players)


playerTurn = 0
playDirection = 1
playing = True
discards.append(unoDeck.pop(0))          # appending top card from unodeck to our discard pile

splitCard= discards[0].split(" ",1)
currentcolor= splitCard[0]
if currentcolor!= "Wild":
    cardValue= splitCard[1]
else:
    cardValue="Any"
while playing:
    showHand(playerTurn,players[playerTurn])
    print("Card available on top of discard pile is {}".format(discards[-1]))
    if canPlay(currentcolor,cardValue,players[playerTurn]):
        cardChoice= int(input("Which Card do you want to play? "))
        while not canPlay(currentcolor,cardValue,[players[playerTurn][cardChoice-1]]):
            cardChoice= int(input("Invalid Card... Which Card do you want to play? "))
        print("Player {} played: {}".format(playerTurn+1,players[playerTurn][cardChoice-1]))
        discards.append(players[playerTurn].pop(cardChoice-1))
    #check winner
        if len(players[playerTurn])==0:
            playing= False
            winner="Player {}".format(playerTurn+1)
    #special cards
        else:
            splitCard= discards[-1].split(" ",1)
            currentcolor= splitCard[0]
            if len(splitCard)==1:
                cardValue="Any"
            else:
                cardValue=splitCard[1]
            if currentcolor=="Wild":
                if cardValue=="draw four":
                    for x in range(len(colors)):
                        print("{}. {}".format(x+1,colors[x]))
                    userChoice= int(input("Which color would you like to choose? "))
                    currentcolor=colors[userChoice-1]
                    print("Choosen color is {}".format(currentcolor))
                    while userChoice<1 or userChoice>4:
                        userChoice= int(input("Sorry, Invalid Option!! Which color would you like to choose? "))
                    currentcolor=colors[userChoice-1]            #colors = ["Red", "Green", "Yellow", "Blue"]
                    playerDraw = playerTurn+playDirection
                    if playerDraw>=numPlayers:
                        playerDraw= 0
                    elif playerDraw<0:
                        playerDraw=numPlayers-1
                    players[playerDraw].extend(drawCards(4))
                else:
                    for x in range(len(colors)):
                        print("{}. {}".format(x+1,colors[x]))
                    userChoice= int(input("Which color would you like to choose? "))
                    currentcolor=colors[userChoice-1]
                    print("Choosen color is {}".format(currentcolor))
                    while userChoice<1 or userChoice>4:
                        userChoice= int(input("Sorry, Invalid Option!! Which color would you like to choose? "))
                    currentcolor=colors[userChoice-1] 
            elif cardValue=="Reverse":
                playDirection= playDirection* -1
            elif cardValue=="Skip":
                playerTurn= playerTurn+playDirection
                if playerTurn>=numPlayers:
                    playerTurn= 0
                elif playerTurn<0:
                    playerTurn=numPlayers-1
            elif cardValue=="Draw Two":
                playerDraw = playerTurn+playDirection
                if playerDraw>=numPlayers:
                    playerDraw= 0
                elif playerDraw<0:
                    playerDraw=numPlayers-1
                players[playerDraw].extend(drawCards(2))
            elif cardValue=="Draw Four":
                playerDraw = playerTurn+playDirection
                if playerDraw>=numPlayers:
                    playerDraw= 0
                elif playerDraw<0:
                    playerDraw=numPlayers-1
                players[playerDraw].extend(drawCards(4))
            print("")
    else:
        print("Sorry! You can't play. Please draw a card.")
        players[playerTurn].extend(drawCards(1))
    print("")


    playerTurn+= playDirection
    if playerTurn>=numPlayers:
        playerTurn= 0
    elif playerTurn<0:
        playerTurn=numPlayers-1

print("Game Over...")
print("Congratulations! {}...".format(winner))
print("You are the winner!!")
print("")