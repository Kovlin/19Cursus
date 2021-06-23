from django.db import models

class Movies(models.Model):

	title = models.CharField(max_length = 64, null = False, unique = True) #champ de caractere de taille 64 non null et unique
	episode_nb = models.IntegerField(primary_key = True) #champ se remplissant automatiquement designé comme PRIMARY KEY
	opening_crawl = models.TextField(null = True) #champ de texte pouvant etre null
	director = models.CharField(max_length = 32, null = False) #champ de caractere de taille 32 non null et unique
	producer = models.CharField(max_length = 128, null = False) #champ de caractere de taille 128 non null et unique
	release_date = models.DateField(null = False) #champ de date non null
	created = models.DateTimeField(auto_now_add=True, null=False) #champ DateTime qui se set a NOW a sa creation
	updated = models.DateTimeField(auto_now=True, null=False) #champ DateTime qui se set a NOW a sa creation et qui s'update 
															  #a chaque fois que save() est appelé

	def __str__(self):
		return self.title