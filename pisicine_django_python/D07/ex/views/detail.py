from ..models import Article, UserFavouriteArticle
from django.views.generic import DetailView
from django import forms
from django.views.generic.edit import FormMixin
from ..forms import FavouriteForm
from django.shortcuts import redirect
from ..forms import LoginForm



class Detail(DetailView):
    template_name = "ex/detail.html"
    model = Article
    form_class = FavouriteForm
    url_success = "ex/detail.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        f = FavouriteForm(initial={'article': context["article"]})
        f.fields['article'].widget = forms.HiddenInput()
        context["form"] = f
        context["login"] = self.request.user.is_authenticated
        context["login_form"] = LoginForm()
        return context

    def post(self, request, pk):
        article = request.POST.get("article")
        article = Article.objects.get(id=article)
        fav = UserFavouriteArticle(article = article, user = request.user)
        fav.save()
        return redirect("articles_detail", pk = pk)

