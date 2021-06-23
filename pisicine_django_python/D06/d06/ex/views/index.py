from django.shortcuts import render
from django.conf import settings
import random

def index(request):
    if (request.COOKIES.get('duration-cookie')):
        current_user = request.COOKIES.get('duration-cookie')
        return  render(request, 'ex/index.html', {'current_user': current_user})
    else:
        current_user = random.choice(settings.SESSION_NAMES)
        response = render(request, 'ex/index.html', {'current_user': current_user})
        response.set_cookie('duration-cookie', current_user, max_age=settings.COOKIE_AGE) 
    return response