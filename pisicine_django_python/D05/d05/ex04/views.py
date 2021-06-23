from django.http import HttpResponse
from django.shortcuts import render
import psycopg2

def init(request):
	try:
		con_string = "host = 'localhost' dbname = 'djangotraining' user = 'djangouser' password = 'secrect'" #params for the connexion to the db

		conn = psycopg2.connect(con_string) #used to connect to the db

		cursor = conn.cursor() #used to perform queries on the database connected to

		query = """ CREATE TABLE IF NOT EXISTS ex04_movies (
			title VARCHAR(64) NOT NULL,
			episode_nb INTEGER PRIMARY KEY, 
			opening_crawl TEXT,
			director VARCHAR(32) NOT NULL,
			producer VARCHAR(128) NOT NULL,
			release_date date NOT NULL
			)
			"""
		cursor.execute(query) #used to execute a query in a the database
		cursor.close() #used to close the cursor on the database
		conn.commit() #used to send the request
		conn.close() #used to close the connection to the database
	except psycopg2.Error as e:
		return HttpResponse(e)
	return HttpResponse('OK')

def populate(request):
	ret_str = ""
	try:
		con_string = "host = 'localhost' dbname = 'djangotraining' user = 'djangouser' password = 'secrect'" #params for the connexion to the db

		conn = psycopg2.connect(con_string) #used to connect to the db
		cursor = conn.cursor() #used to perform queries on the database connected to

	
		query = """ INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date) 
					VALUES ('1', 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19') 
					ON CONFLICT (episode_nb) DO NOTHING
				"""
		cursor.execute(query)
		if cursor.rowcount != 0: #permet de connaitre combien de row ont ete modifiee par la query
			ret_str += "OK </br>"

		query = """ INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date)
                    VALUES ('2', 'Attack of the Clones', 'George Lucas', 'Rick McCallum', '2002-05-16') 
					ON CONFLICT (episode_nb) DO NOTHING
			    """
		cursor.execute(query)
		if cursor.rowcount != 0:
			ret_str += "OK </br>"

		query = """ INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date)
                    VALUES ('3', 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19') 
					ON CONFLICT (episode_nb) DO NOTHING
			    """
		cursor.execute(query)
		if cursor.rowcount != 0:
			ret_str += "OK </br>"

		query = """ INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date)
                    VALUES ('4', 'A New Hope', 'Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1977-05-25') 
					ON CONFLICT (episode_nb) DO NOTHING
			    """
		cursor.execute(query)
		if cursor.rowcount != 0:
			ret_str += "OK </br>"

		query = """ INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date)
                    VALUES ('5', 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1980-05-17') 
					ON CONFLICT (episode_nb) DO NOTHING
			    """
		cursor.execute(query)
		if cursor.rowcount != 0:
			ret_str += "OK </br>"

		query = """ INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date)
                    VALUES ('6', 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25') 
					ON CONFLICT (episode_nb) DO NOTHING
			    """
		cursor.execute(query)
		if cursor.rowcount != 0:
			ret_str += "OK </br>"

		query = """ INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date)
                    VALUES ('7', 'The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
					ON CONFLICT (episode_nb) DO NOTHING
			    """
		cursor.execute(query)
		if cursor.rowcount != 0:
			ret_str += "OK </br>"
        
		cursor.close() #used to close the cursor on the database
		conn.commit() #used to send the request
		conn.close() #used to close the connection to the database
	except psycopg2.Error as e:
		return HttpResponse(ret_str + str(e))
	return HttpResponse(ret_str)

def display(request):
	try:
		con_string = "host = 'localhost' dbname = 'djangotraining' user = 'djangouser' password = 'secrect'" #params for the connexion to the db

		conn = psycopg2.connect(con_string) #used to connect to the db

		cursor = conn.cursor() #used to perform queries on the database connected to
		query = "SELECT * FROM ex04_movies"
		cursor.execute(query) #used to execute a query in a the database
		response = cursor.fetchall()
		if not response:
			return HttpResponse('No data available')
		context = {}
		context["Films"] = response

		cursor.close() #used to close the cursor on the database
		conn.commit() #used to make the request persistent
		conn.close() #used to close the connection to the database
	except psycopg2.Error as e:
		return HttpResponse(e)
	return render(request, "ex04/display.html", context)

def remove(request):
	try:
		con_string = "host = 'localhost' dbname = 'djangotraining' user = 'djangouser' password = 'secrect'" #params for the connexion to the db
		conn = psycopg2.connect(con_string) #used to connect to the db
		cursor = conn.cursor() #used to perform queries on the database connected to

		if request.method == 'POST':
			query = """	DELETE FROM ex04_movies
						WHERE episode_nb = {id}
					""".format(id = request.POST['Key'])
			cursor.execute(query)
			conn.commit()
		query = "SELECT * FROM ex04_movies"
		cursor.execute(query) #used to execute a query in a the database
		response = cursor.fetchall()
		if not response:
			return HttpResponse('No data available')
		context = {}
		context["Films"] = response
		cursor.close()
		conn.commit()
		conn.close()
	except psycopg2.Error as e:
		return HttpResponse(e)
	return render(request, "ex04/remove.html", context)