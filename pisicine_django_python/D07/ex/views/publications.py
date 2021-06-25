from django.views.generic import ListView
from ..models import Article
from django.shortcuts import redirect

class Publications(ListView):
    template_name = "ex/publications.html"
    model = Article

    def get(self, request):
        if not request.user.is_authenticated:
            return redirect('home')
        return super().get(self.request)

    def get_queryset(self): #on surcharge la methode get query set pour ne voir que les article du user
        return self.model.objects.filter(author = self.request.user)