from ..models import Article
from django.views.generic import DetailView
from django import forms


class Detail(DetailView):
    template_name = "ex/detail.html"
    model = Article

def get_context_data(self, **kwargs):
        # Call the base implementation first to get a context
        context = super().get_context_data(**kwargs)
        # Add in a QuerySet of all the article
        context['object'] = Article.objects.filter(id = self.request.user.id)
        return context
