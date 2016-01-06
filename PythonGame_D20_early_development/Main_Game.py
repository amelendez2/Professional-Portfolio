from Heroes import Heroes
from D20 import DiceRoll
from Enemies import Enemy
from Random_Enemy_Generator import RandomEnemy

'''
This is the Main Class for the game. This is the class that will be called when other programs or applications
attempt to start the game.
'''


class Game:

    level = 0
    hero_select = 0
    diceroll = DiceRoll()

    print('Welcome Adventurer to the Land of Blank \n'
          'To begin your adventure you must first select your starting level and class! \n'
          'The higher level you choose the more difficult the game will be \n')
    while level == ((level < 1) and (level > 16)):
        level = input('Select the Level(Between 1 and 15) to begin your adventure: ')
        if (level < '1') and (level > '16'):
            print('\nIncorrect input, please try again\n')
        else:
            level = int(level)              # Type cast to int to pass to Heroes()
            break
    champion = Heroes(level)
    print('There are 3 classes available \n'
          'Choose wisely \n'
          '1. Wizard \n'
          '2. Warrior \n'
          '3. Archer \n')
    while hero_select != (1 | 2 | 3):
        hero_select = input('Select a Hero Class by entering a number: ')
        if hero_select is '1':
            champion.wizard()
            break
        elif hero_select is '2':
            champion.warrior()
            break
        elif hero_select is '3':
            champion.archer()
            break
        else:
            print('\nIncorrect input, please try again\n')

# -----------------------------------------------------------------------------------------------------------

    print("\nThe Following is a list of your Hero's stats")
    print(str(Heroes.life) + ' Hit Points')
    print(str(Heroes.ranged_damage) + ' Damage versus Ranged')
    print(str(Heroes.spell_damage) + ' Damage with spells')
    print(str(Heroes.melee_damage) + ' Damage with a melee weapon')
    print(str(Heroes.armor) + ' Armor')
    print('---------------------------------')
    print("\nLet the Adventure Begin\n")

# -----------------------------------------------------------------------------------------------------------

    # Insert Condition statement whether our Adventurer runs into an enemy

# -----------------------------------------------------------------------------------------------------------

    # Create Random Enemy Minion Based on Location and Level
    map_Location = 'Black Forest'
    randEnemy1 = RandomEnemy()
    randEnemy1_Name = randEnemy1.generator(level, 'Minion')
    print("As you walk through the %s you encounter a %s" % (map_Location, randEnemy1_Name))
    randEnemy1_attack_damage = randEnemy1.assign_attack_damage(randEnemy1_Name, 'Minion')
    randEnemy1_health = randEnemy1.assign_health(randEnemy1_Name, 'Minion')

# -----------------------------------------------------------------------------------------------------------

    Minion1 = Enemy(randEnemy1_Name, randEnemy1_attack_damage, randEnemy1_health)
    Minion1.enemy_stats()
    print("\nWhat would you like to do\n"
          "Attack With Melee weapon\n"
          "Attack With Ranged weapon\n"
          "Attack with Spell\n")
    Minion1.enemy_damaged_health(Heroes.melee_damage)
    print("\nGnoll swings at you and hits you for " + str(Minion1.attack_damage))
    Heroes.life -= Minion1.attack_damage
    print("You have " + str(Heroes.life) + " Hit points left")
