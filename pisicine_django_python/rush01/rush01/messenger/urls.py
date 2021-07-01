from django.urls import path
from .views.discussion import ArticlesListView
from .views.home import home
from .views.login import Login
from .views.publications import Publications
from .views.detail import Detail
from .views.logout import Logout
from .views.profile import ProfileView
from .views.register import Register
from .views.message import Publish

urlpatterns = [
    path('discussions/', ArticlesListView.as_view(), name = 'discussions'),
	path('', home, name='home'),
	path('login/', Login.as_view(), name = 'login'),
	path('publications/', Publications.as_view(), name = 'publication'),
	path('message/', Detail.as_view(), name='message_detail'),
	path('logout/', Logout.as_view(), name='logout'),
	path('profile/', ProfileView.as_view(), name='profile'),
	path('register/', Register.as_view(), name='register'),
	path('publish/', Publish.as_view(), name='publish'),
]