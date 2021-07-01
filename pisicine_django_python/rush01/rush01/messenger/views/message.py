from django.views.generic import CreateView
from django.urls import reverse_lazy
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth import authenticate, login
from django.contrib.auth.models import User
from django.shortcuts import redirect
from django.contrib import messages
from django.http import HttpResponse, HttpRequest
from django.contrib import messages
from ..forms import MessageForm
from ..models import Message
from django.db import DatabaseError
from ..forms import LoginForm



class Publish(CreateView):
	template_name = "messenger/publish.html" #template utilisé par la classe pour afficher la page
	form_class = MessageForm #classe de formulaire utilisée par la FormView (login et password)
	success_url = reverse_lazy('publication') #url de redirection si le login est successfull

	def get(self, request):
		if not request.user.is_authenticated:
			return redirect('home')
		return super().get(self.request)

	def form_valid(self, form):
		content = form.cleaned_data['content']
		sender = self.request.user
		if form.cleaned_data['receiver'] == sender :
			messages.add_message(self.request, messages.INFO, 'Hello world.')
			return super().form_invalid(form)
		try:
			Message.objects.create(sender = sender, receiver = form.cleaned_data['receiver'], content = content)
			form.save()
		except DatabaseError as e:
			messages.success(self.request, "Unsuccessful post. DatabaseError")
			return redirect('publication')
		messages.success(self.request, "Successful post.")
		return super().form_valid(form)

	def form_invalid(self, form):
		messages.error(self.request, 'Cannot create the message')
		return super().form_invalid(form) #permet de revenir sur la page en affichant le bon message d'erreur

	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		context["login_form"] = LoginForm()
		return context
