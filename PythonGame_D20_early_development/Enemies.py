"""
This is the Dynamic enemy class. Whenever an enemy is created in the game their attributes are
passed here so that we can manipulate their Health pool and determine how much each swing of damage will
create. Additionally this Class gives the condition for when an enemies Health reaches or goes beyond 0
meaning that the enemy is dead.
"""


class Enemy:

    def __init__(self, name, attack_damage, health):
        self.name = name
        self.attack_damage = attack_damage
        self.health = health

    def enemy_stats(self):
        print(self.name, "\n", str(self.attack_damage) + ' Attack Damage', "\n", str(self.health) + ' HP', sep='')

    def enemy_damaged_health(self, damage_taken):
        self.health -= damage_taken
        if self.health <= 0:
            print(str(self.name) + ' is dead\n')
        else:
            print(str(damage_taken) + ' Damage taken', "\n", str(self.health) + ' Health left', sep='')

'''e = Enemy('gnoll', 5, 10)
e.enemy_stats()
e.enemy_damaged_health(3)
e.enemy_damaged_health(3)
e.enemy_damaged_health(5)

e2 = Enemy('troll', 5, 10)
e2.enemy_stats()
e2.enemy_damaged_health(3)
e2.enemy_damaged_health(3)
e2.enemy_stats()
e2.enemy_damaged_health(5)'''
