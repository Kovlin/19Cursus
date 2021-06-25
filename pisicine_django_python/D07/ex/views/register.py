from django.views.generic import CreateView
from django.urls import reverse_lazy
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth import authenticate, login
from django.contrib.auth.models import User
from django.shortcuts import redirect
from django.contrib import messages
from django.http import HttpResponse, HttpRequest
from django.contrib import messages
from ..forms import LoginForm



class Register(CreateView):
	template_name = "ex/register.html" #template utilisé par la classe pour afficher la page
	form_class = UserCreationForm #classe de formulaire utilisée par la FormView (login et password)
	success_url = reverse_lazy('home') #url de redirection si le login est successfull

	def get(self, request):
		if request.user.is_authenticated:
			return redirect('home')
		return super().get(self.request)

	def form_valid(self, form):
		form.save()
		valid = super(Register, self).form_valid(form)
		new_user = authenticate(username = form.cleaned_data['username'], password = form.cleaned_data['password1'])
		if new_user:
			login(self.request, new_user)
		return valid

	def form_invalid(self, form):
		messages.success(self.request, 'Account NOT created successfully')
		return super().form_invalid(form) #permet de revenir sur la page en affichant le bon message d'erreur
    
	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		context["login_form"] = LoginForm()
		return context


