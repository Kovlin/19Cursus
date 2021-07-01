from django.views.generic import CreateView
from ..models import Profile
from ..forms import UserProfile
from django.shortcuts import redirect
from django.db import DatabaseError
from django.contrib.auth.models import User
from django.shortcuts import render


class ProfileView(CreateView):
    template_name = "messenger/profile.html"
    form_class = UserProfile

    def get(self, request):
        if not request.user.is_authenticated:
            return redirect('home')
        return super().get(self.request)

    def post(self, request, *args, **kwargs):
        profile = Profile.objects.filter(user = request.user).first()
        if profile: 
            form = UserProfile(request.POST, instance=profile)
        else:
            form = UserProfile(request.POST)
        if form.is_valid():
            profile_obj = form.save(commit=False)
            profile_obj.user = request.user
            profile_obj.save()
        return render(request, self.template_name, {'form': form})