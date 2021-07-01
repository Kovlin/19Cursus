from django.contrib.auth import logout
from django.contrib.auth.mixins import LoginRequiredMixin
from django.views.generic import RedirectView
from django.urls import reverse_lazy


class Logout(RedirectView):
    url = reverse_lazy('home')

    def get_redirect_url(self):
        logout(self.request)
        return super().get_redirect_url()