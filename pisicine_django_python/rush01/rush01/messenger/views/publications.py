from django.views.generic import ListView
from ..models import Message
from django.shortcuts import redirect

class Publications(ListView):
    template_name = "messenger/publications.html"
    model = Message

    def get(self, request):
        if not request.user.is_authenticated:
            return redirect('home')
        return super().get(self.request)

    def get_queryset(self): #on surcharge la methode get query set pour ne voir que les article du user
        return self.model.objects.filter(sender = self.request.user)