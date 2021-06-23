from django.urls import path
from .views.articles import ArticlesListView
from .views.home import Home
from .views.login import Login

urlpatterns = [
    path('articles/', ArticlesListView.as_view(), name = 'articles'),
	path('', Home.as_view(), name='home'),
	path('login/', Login.as_view(), name = 'login'),
]