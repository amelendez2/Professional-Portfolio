'''
At the start of the game the user selects class, based on that selection the users hero will be assigned
attributes correlating to the type of hero. Attributes determine the hero's ability to use certain spell and weapons
and also determine the amount of health that the character has at the start of the game.
'''

base = 10


class Attributes:

    # Constitution will determine starting hit points

    def constitution(self, heroclass):
        self.heroclass = heroclass
        conmodifier = 0
        if heroclass is 'Wizard':
            print('---------------------------------\n'
                  'Wizard'
                  '\n---------------------------------')
            conmodifier = 5

        elif heroclass is 'Warrior':
            print('---------------------------------\n'
                  'Warrior'
                  '\n---------------------------------')
            conmodifier = 15

        elif heroclass is 'Archer':
            print('---------------------------------\n'
                  'Archer'
                  '\n---------------------------------')
            conmodifier = 10

        life = base + conmodifier
        return life

# Strength Attribute will determine melee damage

    def strength(self, heroclass):
        self.heroclass = heroclass
        strmodifier = 0
        if heroclass is 'Wizard':
            strmodifier = 0

        elif heroclass is 'Warrior':
            strmodifier = 10

        elif heroclass is 'Archer':
            strmodifier = 2

        base_melee_damage = base + strmodifier
        return base_melee_damage

# Intelligence will determine spell damage

    def intelligence(self, heroclass):
        self.heroclass = heroclass
        intmodifier = 0
        if heroclass is 'Wizard':
            intmodifier = 10

        elif heroclass is 'Warrior':
            intmodifier = 0

        elif heroclass is 'Archer':
            intmodifier = 0

        base_spell_damage = base + intmodifier
        return base_spell_damage

# Dexterity will determine ranged damage and dodge percentage

    def dexterity(self, heroclass):
        self.heroclass = heroclass
        dexmodifier = 0
        if heroclass is 'Wizard':
            dexmodifier = 2

        elif heroclass is 'Warrior':
            dexmodifier = 4

        elif heroclass is 'Archer':
            dexmodifier = 10

        base_ranged_damage = base + dexmodifier
        return base_ranged_damage
