import pymongo

'''
Just like ArmorDB, WeaponDB serves to directly query the MongoDB armory database, specifically in the weapons
collection.
'''


class WeaponQuery:

    def weapon_query_name(self, weapon_name):
        self.weapon_name = weapon_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.weapons.find()
        for a in armory:
            if a['Weapon Name'] == weapon_name:
                weapon_name = a['Weapon Name']
        return weapon_name

    def weapon_query_slot(self, weapon_name):
        self.weapon_name = weapon_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.weapons.find()
        for a in armory:
            if a['Weapon Name'] == weapon_name:
                slot = a['Weapon Slot']
        return slot

    def weapon_query_type(self, weapon_name):
        self.weapon_name = weapon_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.weapons.find()
        for a in armory:
            if a['Weapon Name'] == weapon_name:
                weapon_type = a['Weapon Type']
        return weapon_type

    def weapon_query_weight(self, weapon_name):
        self.weapon_name = weapon_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.weapons.find()
        for a in armory:
            if a['Weapon Name'] == weapon_name:
                weight = a['Weapon Weight']
        return weight

    def weapon_query_damage(self, weapon_name):
        self.weapon_name = weapon_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.weapons.find()
        for a in armory:
            if a['Weapon Name'] == weapon_name:
                damage = a['Weapon Damage']
        return damage

    def weapon_query_critical_damage(self, weapon_name):
        self.weapon_name = weapon_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.weapons.find()
        for a in armory:
            if a['Weapon Name'] == weapon_name:
                critical_damage = a['Weapon Critical Damage']
        return critical_damage

'''w = WeaponQuery()
print(w.weapon_query_name('Longsword'))
print(w.weapon_query_slot('Longsword'))
print(w.weapon_query_type('Longsword'))
print(w.weapon_query_weight('Longsword'))
print(w.weapon_query_damage('Longsword'))
print(w.weapon_query_critical_damage('Longsword'))'''
