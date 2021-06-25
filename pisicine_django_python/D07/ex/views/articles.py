from ..models import Article
from django.views.generic import ListView
from ..forms import LoginForm

class ArticlesListView(ListView):
	queryset = Article.objects.order_by('-created')
	template_name = 'ex/articles.html' #on surcharge le nom du template utiliser par la vue quand on appelle ArticlesListView.as_view()
	model = Article

	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		f = LoginForm(auto_id=False)
		context["login_form"] = f
		return context