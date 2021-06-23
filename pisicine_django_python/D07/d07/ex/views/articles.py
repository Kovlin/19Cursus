from ..models import Article
from django.views.generic import ListView

class ArticlesListView(ListView):
	template_name = 'ex/articles.html' #on surcharge le nom du template utiliser par la vue quand on appelle ArticlesListView.as_view()
	model = Article