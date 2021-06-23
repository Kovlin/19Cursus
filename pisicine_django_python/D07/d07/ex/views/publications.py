from django.views.generic import ListView
from ..models import Article

class Publications(ListView):
    template_name = "ex/publications.html"
    model = Article

    def get_queryset(self): #on surcharge la methode get query set pour ne voir que les article du user
        return self.model.objects.filter(author = self.request.user)