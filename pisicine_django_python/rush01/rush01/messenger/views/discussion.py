from ..models import Message, Profile
from django.contrib.auth.models import User
from django.views.generic import ListView
from ..forms import LoginForm
from django.db.models import Q
from django.db.models import Count, Max

class ArticlesListView(ListView):
	template_name = 'messenger/discussions.html' #on surcharge le nom du template utiliser par la vue quand on appelle ArticlesListView.as_view()
	model = Message

	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		f = LoginForm(auto_id=False)
		context["login_form"] = f
		return context

	def get_queryset(self): #on surcharge la methode get query set pour ne voir que les article du user
		ret = self.model.objects.filter((Q(sender = self.request.user) | Q(receiver = self.request.user)))
		ret = ret.filter().order_by('-created')
		return ret