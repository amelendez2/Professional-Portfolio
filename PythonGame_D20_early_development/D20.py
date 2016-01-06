import random

'''
The game is based on a D20 system so this class allows the game to determine what range of random numbers to search
through based on die type. For example if the user rolls a d8 for a weapon damage swing then this class will
 determine the damage based on a random number between 1 and 8.
'''


class DiceRoll:

    def d4(self):
        diceroll = random.randrange(1, 5)
        return diceroll

    def d6(self):
        diceroll = random.randrange(1, 7)
        return diceroll

    def d8(self):
        diceroll = random.randrange(1, 9)
        return diceroll

    def d10(self):
        diceroll = random.randrange(1, 11)
        return diceroll

    def d12(self):
        diceroll = random.randrange(1, 13)
        return diceroll

    def d20(self):
        diceroll = random.randrange(1, 21)
        return diceroll

#d = DiceRoll()
#print(d.d20())
