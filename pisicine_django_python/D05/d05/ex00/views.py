from django.http import HttpResponse
import psycopg2

def init(request):
	try:
		con_string = "host = 'localhost' dbname = 'djangotraining' user = 'djangouser' password = 'secrect'" #params for the connexion to the db

		conn = psycopg2.connect(con_string) #used to connect to the db

		cursor = conn.cursor() #used to perform queries on the database connected to

		query = """ CREATE TABLE IF NOT EXISTS ex00_movies (
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
		conn.commit() #used to make the request persistent
		conn.close() #used to close the connection to the database
	except psycopg2.Error as e:
		return HttpResponse(e)
	return HttpResponse('OK')