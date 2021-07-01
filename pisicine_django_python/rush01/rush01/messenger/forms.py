from django import forms
from django.forms.widgets import Textarea
from .models import Article
from .models import Profile
from .models import Message
from django.forms.widgets import HiddenInput
from django.contrib.auth.forms import AuthenticationForm, UsernameField
from typing import Any


class MessageForm(forms.ModelForm):
    
    class Meta:
        model = Message
        exclude = ['sender']
    content = forms.CharField(widget=Textarea(), required=True)


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

class UserProfile(forms.ModelForm):
    class Meta:
        model = Profile
        exclude = ['user']

    name = forms.CharField(max_length = 50, required = False)
    surname = forms.CharField(max_length = 50, required = False)
    email = forms.EmailField(max_length = 254, required = False)
    desc = forms.CharField(max_length = 512, required=False)
