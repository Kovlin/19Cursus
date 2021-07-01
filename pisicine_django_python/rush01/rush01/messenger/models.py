from django.db import models
from django.contrib.auth.models import User
from datetime import datetime


class Article(models.Model):

	title = models.CharField(max_length = 64, null = False) #champ de caractere de taille 64 non null
	# ◦ author: Article’s author. References a record of the User model. Non null.
	author = models.ForeignKey(User, on_delete = models.CASCADE, null = False) #clé étrangère référençant l'auteur
	created = models.DateTimeField(auto_now_add = True, null = False) #champ DateTime qui se set a NOW a sa creation
	synopsis = models.CharField(max_length = 312, null = False) #champ de caractere de taille 312 non null
	content = models.TextField(null = False) # champ de texte non null

	def __str__(self):
		return self.title

class Profile(models.Model):
	user = models.OneToOneField(User, on_delete=models.CASCADE, related_name='profile')
	name = models.CharField(max_length = 50, null = False)
	surname = models.CharField(max_length = 50, null = False)
	email = models.EmailField(max_length = 254, null = False)
	desc = models.TextField(null = False)

	def __str__(self):
		return self.name

class Message(models.Model):
	
	sender = models.ForeignKey(User, on_delete = models.CASCADE, null = False, related_name='sender') #clé étrangère référençant la personne envoyant le msg
	receiver = models.ForeignKey(User, on_delete = models.CASCADE, null = False, related_name='receiver') #clé étrangère référençant la personne envoyant le msg
	created = models.DateTimeField(auto_now_add = True, null = False) #champ DateTime qui se set a NOW a sa creation, correspond à l'envoi du message
	content = models.TextField(null = False) # champ de texte, le contenu du message

	def __str__(self):
		return self.content