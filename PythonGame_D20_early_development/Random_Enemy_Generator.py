import pymongo
from D20 import DiceRoll

'''
Whenever a random enemy is encountered the game will search the database and assign an appropriate enemy
based on level and current area in the game. Attributes for the enemy will be allocated at the time of the
enemies creation(I may change to allow for more random attacks during the confrontation rather than assigning
a static attack_damage based on a die roll at the time of creation).

The Database for the Enemy Bestiary will immense and will require very in depth thought to determine creatures
and abilities that are appropriate and balanced.
'''


class RandomEnemy:

    """
    The first part of this class is the generator method where we determine an enemy based on level and area
    (Still need to add areas to the game). When a random enemy is encountered we also determine if it will be
    a "Boss" or a "Minion." Bosses are much more difficult enemies with varying degrees of difficulty. Random bosses
    will be less difficult as apposed to scripted Boss encounters that are in line with the game flow. Minions
    are weak enemies, however depending on the type and number of minions that are encountered there may be
    a challenge as chance will often not be in favor of the player. The player will have to be able to determine
    a strategy to survive the encounter.
    """

    def generator(self, level, enemy_type):
        self.level = level
        self.type = enemy_type
        client = pymongo.MongoClient()
        db = client.enemies
        if enemy_type == 'Boss':
            enemies = db.boss.find()
            for e in enemies:
                if e['Enemy Level'] == level:
                    enemy = e['Enemy Name']
            return enemy
        elif enemy_type == 'Minion':
            enemies = db.minion.find()
            for e in enemies:
                if e['Enemy Level'] == level:
                    enemy = e['Enemy Name']
            return enemy

    '''
    assign_attack_damage method assigns Enemy attack damage based on querying the mongoDB database for the
    randomly generated enemy. The database contains separate collections based on Boss and minion so we have to
    determine that when its generated. Once we know if the enemy is a boss or minion and we know the name of
    the enemy we query the corresponding database to determine attack damage.
    In the database the 'Enemy Attack Damage' is dynamically allocated based on a dice roll such that when we
    pass the enemy through this method it will extract the type of dice to use and how many dice of that type
    need to be rolled.

    Currently the program only takes one dice roll then multiplies it rather than adding 3 separate dice rolls
    '''

    def assign_attack_damage(self, enemy_name, enemy_type):
        self.enemy_name = enemy_name
        self.enemy_type = enemy_type
        diceroll = DiceRoll()
        client = pymongo.MongoClient()
        db = client.enemies
        if enemy_type == 'Boss':
            enemies = db.boss.find()
            for e in enemies:
                if e['Enemy Name'] == enemy_name:
                    attack_damage = e['Enemy Attack Damage']
                    if '+' in attack_damage[:4]:
                        temp_ad = attack_damage[:3]
                        multiplier = temp_ad[0]
                        multiplier = int(multiplier)
                        dice = temp_ad[1:3]
                        print('Enemy Attack Damage Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_attack = getattr(diceroll, dice)()
                        attack_damage = (base_attack*multiplier) + int(attack_damage[-1:])
                        return attack_damage
                    else:
                        temp_ad = attack_damage[:4]
                        multiplier = temp_ad[0]
                        multiplier = int(multiplier)
                        dice = temp_ad[1:4]
                        print('Enemy Attack Damage Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_attack = getattr(diceroll, dice)()
                        attack_damage = (base_attack*multiplier) + int(attack_damage[-1:])
                        return attack_damage
        elif enemy_type == 'Minion':
            enemies = db.minion.find()
            for e in enemies:
                if e['Enemy Name'] == enemy_name:
                    attack_damage = e['Enemy Attack Damage']
                    if '+' in attack_damage[:4]:
                        temp_ad = attack_damage[:3]
                        multiplier = temp_ad[0]
                        multiplier = int(multiplier)
                        dice = temp_ad[1:3]
                        print('Enemy Attack Damage Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_attack = getattr(diceroll, dice)()
                        attack_damage = (base_attack*multiplier) + int(attack_damage[-1:])
                        return attack_damage
                    else:
                        temp_ad = attack_damage[:4]
                        multiplier = temp_ad[0]
                        multiplier = int(multiplier)
                        dice = temp_ad[1:4]
                        print('Enemy Attack Damage Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_attack = getattr(diceroll, dice)()
                        attack_damage = (base_attack*multiplier) + int(attack_damage[-1:])
                        return attack_damage

    '''
    The assign_health method works similarly to the assign_attack_damage except in this case the method
    extracts the diceroll for the health of the enemy being created.
    '''

    def assign_health(self, enemy_name, enemy_type):
        self.enemy_name = enemy_name
        self.enemy_type = enemy_type
        diceroll = DiceRoll()
        client = pymongo.MongoClient()
        db = client.enemies
        if enemy_type == 'Boss':
            enemies = db.boss.find()
            for e in enemies:
                if e['Enemy Name'] == enemy_name:
                    enemy_health = e['Enemy Health']
                    if '+' in enemy_health[:4]:
                        temp_hp = enemy_health[:3]
                        multiplier = temp_hp[0]
                        multiplier = int(multiplier)
                        dice = temp_hp[1:3]
                        print('Enemy Health Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_health = getattr(diceroll, dice)()
                        enemy_health = (base_health*multiplier) + int(temp_hp[-2:])
                        return enemy_health
                    else:
                        temp_hp = enemy_health[:4]
                        multiplier = temp_hp[0]
                        multiplier = int(multiplier)
                        dice = temp_hp[1:4]
                        print('Enemy Health Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_health = getattr(diceroll, dice)()
                        enemy_health = (base_health*multiplier) + int(temp_hp[-2:])
                        return enemy_health
        elif enemy_type == 'Minion':
            enemies = db.minion.find()
            for e in enemies:
                if e['Enemy Name'] == enemy_name:
                    enemy_health = e['Enemy Health']
                    if '+' in enemy_health[:4]:
                        temp_hp = enemy_health[:3]
                        multiplier = temp_hp[0]
                        multiplier = int(multiplier)
                        dice = temp_hp[1:3]
                        print('Enemy Health Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_health = getattr(diceroll, dice)()
                        enemy_health = (base_health*multiplier) + int(enemy_health[-2:])
                        return enemy_health
                    else:
                        temp_hp = enemy_health[:4]
                        multiplier = temp_hp[0]
                        multiplier = int(multiplier)
                        dice = temp_hp[1:4]
                        print('Enemy Health Dice Roll= %s with a %sx Multiplier' % (dice, multiplier))
                        base_health = getattr(diceroll, dice)()
                        print(int(enemy_health[:-2]))
                        enemy_health = (base_health*multiplier) + int(enemy_health[-2:])
                        return enemy_health
