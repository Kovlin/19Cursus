from django.shortcuts import render

def index(request):
    return render(request, 'ex01/django.html')

def base(request):
    return render(request, 'ex01/base.html')

def display(request):
    return render(request, 'ex01/display.html')

def templates(request):
    return render(request, 'ex01/templates.html')