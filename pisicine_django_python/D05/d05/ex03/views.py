from django.http import HttpResponse
from django.shortcuts import render
import psycopg2
from .models import Movies

def populate(request):
	ret_str = ""
	try:
		if Movies.objects.filter(episode_nb = 1).count() == 0:
			ret_str += 'OK </br>'
			m = Movies('The Phantom Menace', '1', None, 'George Lucas', 'Rick McCallum', '1999-05-19')
			m.save() #la méthode save enregistre un objet dans la base de données

		if Movies.objects.filter(episode_nb = 2).count() == 0:
			ret_str += 'OK </br>'
			m = Movies('Attack of the Clones', '2', None, 'George Lucas', 'Rick McCallum', '2002-05-16')
			m.save()

		if Movies.objects.filter(episode_nb = 3).count() == 0:
			ret_str += 'OK </br>'
			m = Movies('Revenge of the Sith', '3', None, 'George Lucas', 'Rick McCallum', '2005-05-19')
			m.save()

		if Movies.objects.filter(episode_nb = 4).count() == 0:
			ret_str += 'OK </br>'
			m = Movies('A New Hope', '4', None, 'Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1977-05-25')
			m.save()

		if Movies.objects.filter(episode_nb = 5).count() == 0:
			ret_str += 'OK </br>'
			m = Movies('The Empire Strikes Back', '5', None, 'Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1980-05-17')
			m.save()

		if Movies.objects.filter(episode_nb = 6).count() == 0:
			ret_str += 'OK </br>'
			m = Movies('Return of the Jedi', '6', None, 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25')
			m.save()

		if Movies.objects.filter(episode_nb = 7).count() == 0:
			ret_str += 'OK </br>'
			m = Movies('The Force Awakens', '7', None, 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
			m.save()

	except psycopg2.Error as e:
		return HttpResponse(ret_str + str(e))
	return HttpResponse(ret_str)

def display(request):
	try:
	# 	con_string = "host = 'localhost' dbname = 'djangotraining' user = 'djangouser' password = 'secrect'" #params for the connexion to the db

	# 	conn = psycopg2.connect(con_string) #used to connect to the db

	# 	cursor = conn.cursor() #used to perform queries on the database connected to
	# 	query = "SELECT * FROM ex02_movies"
	# 	cursor.execute(query) #used to execute a query in a the database
	# 	response = cursor.fetchall()
	# 	context = {}
	# 	context["Films"] = response

	# 	cursor.close() #used to close the cursor on the database
	# 	conn.commit() #used to make the request persistent
	# 	conn.close() #used to close the connection to the database


		lst = Movies.objects.all() #renvoie une liste de tous les objets de la classe
		if not lst:
			return HttpResponse('No data available')
		context = {}
		context['Films'] = lst

	except psycopg2.Error as e:
		return HttpResponse(e)
	return render(request, "ex03/display.html", context)