from observer import *
from random import uniform

class Weapon(Observable):
	
	def __init__(self):
		self.weaponName = ""
		self.strength = 0
		self.numberOfUses = 0

	def getMod(self):
		return self.mod

	def getUses(self):
		return self.numberOfUses

	def getWeaponName(self):
		return self.weaponName

	def useWeapom(self):
		self.numberOfUses = numberOfUses - 1

class HersheyKiss(Weapon):
	
	def __init__(self):
		Weapon().__init__()
		self.weaponName = "HerseyKiss"
		self.strength = 1
		self.numberOfUses = 10000000


class SourStraw(Weapon):

	def __init__(self):
		Weapon().__init__()
		self.weaponName = "SourStraw"
		self.strength = uniform(1.0, 1.75)
		self.numberOfUses = 2

class ChocolateBar(Weapon):

	def __init__(self):
		Weapon().__init__()
		self.weaponName = "ChocolateBar"
		self.strength = uniform(2.0, 2.4)
		self.numberOfUses = 4


class NerdBomb(Weapon):

	def __init__(self):
		Weapon().__init__()
		self.weaponName = "NerdBomb"
		self.strength = uniform(3.5, 5.0)
		self.numberOfUses = 1
