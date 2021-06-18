from django.urls import path

from . import views

urlpatterns = [
    path('django/', views.index, name='django'),
    path('base/', views.base, name='base'),
    path('display/', views.display, name='display'),
    path('templates/', views.templates, name='templates'),
]