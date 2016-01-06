import pymongo

'''
The ArmorDB class directly queries the MongoDB database for all the Armor specifications. We import the
pymongo plugin to incorporate  MongoDB with python.
We initially setup a client to run mongoDB, then we specify which Database we will be accessing
via (db = client.armory). Where client.armory specifies the armory database, thus, armory must exist in the
MongoDB database. Next we access the armory Collections by using db.armor.find() where armor is the Collection that
we are browsing. Additionally this script could be used to insert and delete database entries, However currently
I am using the Mongo Explorer Tool in Pycharm to access the databases rather than writing them in code here.

'''


class ArmorQuery:

    def armor_query_name(self, armor_name):
        self.armor_name = armor_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.armor.find()
        for a in armory:
            if a['Armor Name'] == armor_name:
                armor_name = a['Armor Name']
        return armor_name

    def armor_query_type(self, armor_name):
        self.armor_name = armor_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.armor.find()
        for a in armory:
            if a['Armor Name'] == armor_name:
                armor_type = a['Armor Type']
        return armor_type

    def armor_query_slot(self, armor_name):
        self.armor_name = armor_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.armor.find()
        for a in armory:
            if a['Armor Name'] == armor_name:
                armor_slot = a['Armor Slot']
        return armor_slot

    def armor_query_weight(self, armor_name):
        self.armor_name = armor_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.armor.find()
        for a in armory:
            if a['Armor Name'] == armor_name:
                weight = a['Weight']
        return weight

    def armor_query_defense(self, armor_name):
        self.armor_name = armor_name
        client = pymongo.MongoClient()
        db = client.armory
        armory = db.armor.find()
        for a in armory:
            if a['Armor Name'] == armor_name:
                armor_defense = a['Armor Defense']
        return armor_defense


#a = ArmorQuery()
#print(a.armor_query_name('Skyguard'))
