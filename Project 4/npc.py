from observe import observable
from random import *

#create the super NPC class
class npc(observable):

	#constructor
	def __init__(self):
		self.npcName
		self.health
		self.attackStrength
		self.weaponDamage = {}
	#set the NPC name
	def setname(self, name)
		self.npcName = name

	#set the NPC health points
	def setHealth(self, health)
		self.health = health

	#set the NPC attack strength
	def setAttackStrength(self, attackStrength)
		self.attackStrength = attackStrength

	#get the NPC name
	def getName(self):
		return self.name

	#get the health points from the NPC
	def getHealth(self):
		return self.health

	#get the attack strength of the NPC
	def getAttackStrength(self)
		return self.attackStrength


#create the NPC class for a Person
class Person(NPC):
	def __init__(self):
		super(Person,self).__init__()
		self.name = "Person"
		self.health = 100
		self.attackStrength = -1
		self.weaponDamage = {"HersheyKisses" : 0,
				     "SourStaws": 0,
				     "ChocolateBars" : 0,
				     "NerdBombs" : 0;
				    }

#create the NPC class for a Zombie
class Zombie(NPC):
	def __inti__(self):
		super(Zombie,self).__init__()
		self.name = "Zombie"
		self.health = randint(50, 100)
		self.attackStrength = randint(0, 10)
		self.weaponDamage = {"HersheyKisses" : 1,
				     "SourStaws": 2,
				     "ChocolateBars" : 1,
				     "NerdBombs" : 1;
				    }
#create the NPC class for a Vampire
class Vampire(NPC):
	def __inti__(self):
		super(Vampire,self).__init__()
		self.name = "Vampire"
		self.health = randint(100, 200)
		self.attackStrength = randint(10, 20)
		self.weaponDamage = {"HersheyKisses" : 1,
				     "SourStaws": 1,
				     "ChocolateBars" : 0,
				     "NerdBombs" : 1;
				    }
#create the NPC class for a Ghouls
class Ghouls(NPC):
	def __inti__(self):
		super(Ghouls,self).__init__()
		self.name = "Ghoul"
		self.health = randint(40, 80)
		self.attackStrength = randint(15, 30)
		self.weaponDamage = {"HersheyKisses" : 1,
				     "SourStaws": 1,
				     "ChocolateBars" : 1,
				     "NerdBombs" : 5;
				    }
#create the NPC class for a Werewolf
class Werewolf(NPC):
	def __inti__(self):
		super(Werewolf,self).__init__()
		self.name = "Werewolf"
		self.health = 200
		self.attackStrength = randint(0, 40)
		self.weaponDamage = {"HersheyKisses" : 1,
				     "SourStaws": 0,
				     "ChocolateBars" : 0,
				     "NerdBombs" : 1;
				    }
