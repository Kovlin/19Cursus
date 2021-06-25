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


class UserFavouriteArticle(models.Model):
	user = models.ForeignKey(User, on_delete = models.CASCADE, null = False)
	article = models.ForeignKey(Article, on_delete = models.CASCADE, null = False)
	def __str__(self):
		return self.article.title