from django.urls import path
from .views.articles import ArticlesListView
from .views.home import Home
from .views.login import Login
from .views.publications import Publications
from .views.detail import Detail

urlpatterns = [
    path('articles/', ArticlesListView.as_view(), name = 'articles'),
	path('', Home.as_view(), name='home'),
	path('login/', Login.as_view(), name = 'login'),
	path('publications/', Publications.as_view(), name = 'publication'),
	path('articles/<slug:pk>/', Detail.as_view(), name='articles_detail'),
]