from django.views.generic import ListView
from ..models import UserFavouriteArticle
from django.shortcuts import redirect

class Favourites(ListView):
    template_name = "ex/favourites.html"
    model = UserFavouriteArticle

    def get(self, request):
        if not request.user.is_authenticated:
            return redirect('home')
        return super().get(self.request)

    def get_queryset(self): #on surcharge la methode get query set pour ne voir que les article du user
        return self.model.objects.filter(user = self.request.user)