from django.views.generic import FormView
from django.urls import reverse_lazy
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import authenticate, login
from django.shortcuts import redirect
from django.contrib import messages
from django.http import HttpResponse, HttpRequest
from ..forms import LoginForm



class Login(FormView):
	template_name = "ex/login.html" #template utilisé par la classe pour afficher la page
	form_class = AuthenticationForm #classe de formulaire utilisée par la FormView (login et password)
	success_url = reverse_lazy('home') #url de redirection si le login est successfull

	def get(self, request):
		if request.user.is_authenticated:
			return redirect('home')
		return super().get(self.request)

	def form_valid(self, form):
		username = form.cleaned_data['username']
		password = form.cleaned_data['password']
		user = authenticate(username = username, password = password)
		if user is None :
			return super().form_invalid(form) #permet de revenir sur la page en affichant le bon message d'erreur
		else :
			login(self.request, user) #connecte l'utilisateur
		return redirect('home')

	def form_invalid(self, form):
		return super().form_invalid(form) #permet de revenir sur la page en affichant le bon message d'erreur

	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		context["login_form"] = LoginForm()
		return context
