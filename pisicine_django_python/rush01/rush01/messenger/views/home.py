from django.views.generic import RedirectView, CreateView
from django.urls import reverse_lazy
from django.shortcuts import render
from ..forms import LoginForm

def home(request):

	f = LoginForm(auto_id=False)
	context = {}
	context["login_form"] = f
	return render(request, "messenger/index.html", context)