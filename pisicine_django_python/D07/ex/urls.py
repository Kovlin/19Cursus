from django.urls import path
from .views.articles import ArticlesListView
from .views.home import Home
from .views.login import Login
from .views.publications import Publications
from .views.detail import Detail
from .views.logout import Logout
from .views.favourites import Favourites
from .views.register import Register
from .views.publish import Publish

urlpatterns = [
    path('articles/', ArticlesListView.as_view(), name = 'articles'),
	path('', Home.as_view(), name='home'),
	path('login/', Login.as_view(), name = 'login'),
	path('publications/', Publications.as_view(), name = 'publication'),
	path('articles/<slug:pk>/', Detail.as_view(), name='articles_detail'),
	path('logout/', Logout.as_view(), name='logout'),
	path('favourites/', Favourites.as_view(), name='favourites'),
	path('register/', Register.as_view(), name='register'),
	path('publish/', Publish.as_view(), name='publish'),
]