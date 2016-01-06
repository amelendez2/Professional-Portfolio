# Armor and Weapons class will start with base equipment and later be altered
from ArmorDB import ArmorQuery
from WeaponDB import WeaponQuery
armor_query = ArmorQuery()
weapon_query = WeaponQuery()

'''
The Armor and Weapon classes are used to perform database queries for Gear specifics such as
type, name, etc. This isn't a final version as it will be extended if there are additional entries
in armor such as special characteristics.
It may seem redundant with ArmorDB and WeaponDB, however, this script will be useful for determining specific slot
requirements and weapon proficiencies. Furthermore, it should help reduce the functions being tasked rather than
calling the same function for every piece of gear and weapon.
'''


class Armor:

    # This is the natural armor that our heroes have regardless of gear

    def natural_armor(self, heroclass):
        self.heroclass = heroclass
        armor = 0
        if heroclass is 'Warrior':
            armor = 2
        elif heroclass is 'Archer':
            armor = 1
        elif heroclass is 'Wizard':
            armor = 1
        return armor

# ****** Chest Armor **********

    def chest_armor_name(self, armor_name):
        self.armor_name = armor_name
        armor_query_name = armor_query.armor_query_name(armor_name)
        return armor_query_name

    def chest_armor_type(self, armor_name):
        self.armor_name = armor_name
        armor_query_type = armor_query.armor_query_type(armor_name)
        return armor_query_type

    def chest_armor_slot(self, armor_name):
        self.armor_name = armor_name
        armor_query_slot = armor_query.armor_query_slot(armor_name)
        return armor_query_slot

    def chest_armor_weight(self, armor_name):
        self.armor_name = armor_name
        armor_query_weight = armor_query.armor_query_weight(armor_name)
        return armor_query_weight

    def chest_armor_defense(self, armor_name):
        self.armor_name = armor_name
        armor_query_defense = armor_query.armor_query_defense(armor_name)
        return armor_query_defense

# ****** Leg Armor **********

    def leg_armor_name(self, armor_name):
        self.armor_name = armor_name
        armor_query_name = armor_query.armor_query_name(armor_name)
        return armor_query_name

    def leg_armor_type(self, armor_name):
        self.armor_name = armor_name
        armor_query_type = armor_query.armor_query_type(armor_name)
        return armor_query_type

    def leg_armor_slot(self, armor_name):
        self.armor_name = armor_name
        armor_query_slot = armor_query.armor_query_slot(armor_name)
        return armor_query_slot

    def leg_armor_weight(self, armor_name):
        self.armor_name = armor_name
        armor_query_weight = armor_query.armor_query_weight(armor_name)
        return armor_query_weight

    def leg_armor_defense(self, armor_name):
        self.armor_name = armor_name
        armor_query_defense = armor_query.armor_query_defense(armor_name)
        return armor_query_defense

# ****** Hand Armor **********

    def hand_armor_name(self, armor_name):
        self.armor_name = armor_name
        armor_query_name = armor_query.armor_query_name(armor_name)
        return armor_query_name

    def hand_armor_type(self, armor_name):
        self.armor_name = armor_name
        armor_query_type = armor_query.armor_query_type(armor_name)
        return armor_query_type

    def hand_armor_slot(self, armor_name):
        self.armor_name = armor_name
        armor_query_slot = armor_query.armor_query_slot(armor_name)
        return armor_query_slot

    def hand_armor_weight(self, armor_name):
        self.armor_name = armor_name
        armor_query_weight = armor_query.armor_query_weight(armor_name)
        return armor_query_weight

    def hand_armor_defense(self, armor_name):
        self.armor_name = armor_name
        armor_query_defense = armor_query.armor_query_defense(armor_name)
        return armor_query_defense

# ****** Head Armor **********

    def head_armor_name(self, armor_name):
        self.armor_name = armor_name
        armor_query_name = armor_query.armor_query_name(armor_name)
        return armor_query_name

    def head_armor_type(self, armor_name):
        self.armor_name = armor_name
        armor_query_type = armor_query.armor_query_type(armor_name)
        return armor_query_type

    def head_armor_slot(self, armor_name):
        self.armor_name = armor_name
        armor_query_slot = armor_query.armor_query_slot(armor_name)
        return armor_query_slot

    def head_armor_weight(self, armor_name):
        self.armor_name = armor_name
        armor_query_weight = armor_query.armor_query_weight(armor_name)
        return armor_query_weight

    def head_armor_defense(self, armor_name):
        self.armor_name = armor_name
        armor_query_defense = armor_query.armor_query_defense(armor_name)
        return armor_query_defense

# ****** Offhand **********

    def shield_armor_name(self, armor_name):
        self.armor_name = armor_name
        armor_query_name = armor_query.armor_query_name(armor_name)
        return armor_query_name

    def shield_armor_type(self, armor_name):
        self.armor_name = armor_name
        armor_query_type = armor_query.armor_query_type(armor_name)
        return armor_query_type

    def shield_armor_slot(self, armor_name):
        self.armor_name = armor_name
        armor_query_slot = armor_query.armor_query_slot(armor_name)
        return armor_query_slot

    def shield_armor_weight(self, armor_name):
        self.armor_name = armor_name
        armor_query_weight = armor_query.armor_query_weight(armor_name)
        return armor_query_weight

    def shield_armor_defense(self, armor_name):
        self.armor_name = armor_name
        armor_query_defense = armor_query.armor_query_defense(armor_name)
        return armor_query_defense


class Weapons:

    # ****** Swords **********

    def sword_weapon_name(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_name = weapon_query.weapon_query_name(weapon_name)
        return weapon_query_name

    def sword_weapon_slot(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_slot = weapon_query.weapon_query_slot(weapon_name)
        return weapon_query_slot

    def sword_weapon_type(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_type = weapon_query.weapon_query_type(weapon_name)
        return weapon_query_type

    def sword_weapon_weight(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_weight = weapon_query.weapon_query_weight(weapon_name)
        return weapon_query_weight

    def sword_weapon_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_damage = weapon_query.weapon_query_damage(weapon_name)
        return weapon_query_damage

    def sword_weapon_critical_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_critical_damage = weapon_query.weapon_query_critical_damage(weapon_name)
        return weapon_query_critical_damage

    # ****** Maces **********

    def mace_weapon_name(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_name = weapon_query.weapon_query_name(weapon_name)
        return weapon_query_name

    def mace_weapon_slot(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_slot = weapon_query.weapon_query_slot(weapon_name)
        return weapon_query_slot

    def mace_weapon_type(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_type = weapon_query.weapon_query_type(weapon_name)
        return weapon_query_type

    def mace_weapon_weight(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_weight = weapon_query.weapon_query_weight(weapon_name)
        return weapon_query_weight

    def mace_weapon_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_damage = weapon_query.weapon_query_damage(weapon_name)
        return weapon_query_damage

    def mace_weapon_critical_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_critical_damage = weapon_query.weapon_query_critical_damage(weapon_name)
        return weapon_query_critical_damage

    # ****** Axes **********

    def axe_weapon_name(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_name = weapon_query.weapon_query_name(weapon_name)
        return weapon_query_name

    def axe_weapon_slot(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_slot = weapon_query.weapon_query_slot(weapon_name)
        return weapon_query_slot

    def axe_weapon_type(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_type = weapon_query.weapon_query_type(weapon_name)
        return weapon_query_type

    def axe_weapon_weight(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_weight = weapon_query.weapon_query_weight(weapon_name)
        return weapon_query_weight

    def axe_weapon_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_damage = weapon_query.weapon_query_damage(weapon_name)
        return weapon_query_damage

    def axe_weapon_critical_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_critical_damage = weapon_query.weapon_query_critical_damage(weapon_name)
        return weapon_query_critical_damage

    # ****** Bows **********

    def bow_weapon_name(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_name = weapon_query.weapon_query_name(weapon_name)
        return weapon_query_name

    def bow_weapon_slot(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_slot = weapon_query.weapon_query_slot(weapon_name)
        return weapon_query_slot

    def bow_weapon_type(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_type = weapon_query.weapon_query_type(weapon_name)
        return weapon_query_type

    def bow_weapon_weight(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_weight = weapon_query.weapon_query_weight(weapon_name)
        return weapon_query_weight

    def bow_weapon_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_damage = weapon_query.weapon_query_damage(weapon_name)
        return weapon_query_damage

    def bow_weapon_critical_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_critical_damage = weapon_query.weapon_query_critical_damage(weapon_name)
        return weapon_query_critical_damage

    # ****** Staves **********

    def staff_weapon_name(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_name = weapon_query.weapon_query_name(weapon_name)
        return weapon_query_name

    def staff_weapon_slot(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_slot = weapon_query.weapon_query_slot(weapon_name)
        return weapon_query_slot

    def staff_weapon_type(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_type = weapon_query.weapon_query_type(weapon_name)
        return weapon_query_type

    def staff_weapon_weight(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_weight = weapon_query.weapon_query_weight(weapon_name)
        return weapon_query_weight

    def staff_weapon_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_damage = weapon_query.weapon_query_damage(weapon_name)
        return weapon_query_damage

    def staff_weapon_critical_damage(self, weapon_name):
        self.weapon_name = weapon_name
        weapon_query_critical_damage = weapon_query.weapon_query_critical_damage(weapon_name)
        return weapon_query_critical_damage
