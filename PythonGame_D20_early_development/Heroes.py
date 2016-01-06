from Hero_Attributes import Attributes
from Armor_Weapons import Armor
from D20 import DiceRoll

'''
The Heroes Class is the Dynamic representation of the Character in the current world. Attributes are passed over to
the class along with any weapons or armor that the player may have currently equipped. Initially when the Player
begins the game he/she will have a choice to pick a level up to level 15. This is to allow users to have a more
advanced experience rather than starting with limited spell, weapons, armor.

Heroes.life is dynamic based on current status in game. Initially the player's health will be their Constitution
modifier + their corresponding die roll multiplied by level.

Currently the Class is incomplete as we would prefer to dynamically change the players attributes such as
melee_damage based on all factors such as weapons and armor with special attributes. An example of this will
be like when a player defeats an enemy and the loot table contains a new piece of armor that will increase
defense of our Player's character. When the player equips that piece of armor Heroes.armor will change to match
armor with the new piece of gear equipped and the old one removed.
'''


class Heroes:

    def __init__(self, level):
        self.level = level

    # Each Hero function will be an individual 'class' that will contain all attributes of the Hero
    def wizard(self):
        wizard_player = Attributes()
        wizard_armor = Armor()
        diceroll = DiceRoll()

        # *** Attributes ***
        Heroes.life = wizard_player.constitution('Wizard') + (self.level*diceroll.d4())
        Heroes.ranged_damage = wizard_player.dexterity('Wizard')
        Heroes.spell_damage = wizard_player.intelligence('Wizard')
        Heroes.melee_damage = wizard_player.strength('Wizard')

        # *** Armor Section ***
        Heroes.armor = (wizard_armor.natural_armor('Wizard') +
                        wizard_armor.chest_armor_defense('Robes of the Invoker'))

        # *** Weapon Section ***

    def warrior(self):
        warrior_player = Attributes()
        warrior_armor = Armor()
        diceroll = DiceRoll()

        # *** Attributes ***
        Heroes.life = warrior_player.constitution('Warrior') + (self.level*diceroll.d10())
        Heroes.ranged_damage = warrior_player.dexterity('Warrior')
        Heroes.spell_damage = warrior_player.intelligence('Warrior')
        Heroes.melee_damage = warrior_player.strength('Warrior')

        # *** Armor Section***
        Heroes.armor = (warrior_armor.natural_armor('Warrior') +
                        warrior_armor.chest_armor_defense('Heart of Ares') +
                        warrior_armor.head_armor_defense("Drago's Visor of the Damned") +
                        warrior_armor.leg_armor_defense("Legguards of the Fallen King"))

        # *** Weapon Section ***

    def archer(self):
        archer_player = Attributes()
        archer_armor = Armor()
        diceroll = DiceRoll()

        # *** Attributes ***
        Heroes.life = archer_player.constitution('Archer') + (self.level*diceroll.d6())
        Heroes.ranged_damage = archer_player.dexterity('Archer')
        Heroes.spell_damage = archer_player.intelligence('Archer')
        Heroes.melee_damage = archer_player.strength('Archer')

        # *** Armor Section ***
        Heroes.armor = archer_armor.natural_armor('Archer')

        # *** Weapon Section ***
