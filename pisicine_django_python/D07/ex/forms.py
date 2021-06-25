from django import forms
from django.forms.widgets import Textarea
from .models import Article
from .models import UserFavouriteArticle
from django.forms.widgets import HiddenInput
from django.contrib.auth.forms import AuthenticationForm, UsernameField
from typing import Any


class PublishForm(forms.ModelForm):
    
    class Meta:
        model = Article
        exclude = ['author']
    title = forms.CharField(max_length=64, required=True)
    synopsis = forms.CharField(max_length=312, required=True)
    content = forms.CharField(widget=Textarea(), required=True)
    
class FavouriteForm(forms.ModelForm):
	class Meta:
		model = UserFavouriteArticle
		fields = ['article']

class LoginForm(AuthenticationForm):
    username = UsernameField(widget=forms.TextInput(
        attrs={'autofocus': True, 'class': 'form-control', 'placeholder': 'username'}),
        label = False
    )
    password = forms.CharField(
        strip=False,
        widget=forms.PasswordInput(
            attrs={'autocomplete': 'current-password', 'class': 'form-control', 'placeholder': 'password'}),
            label=False
    )