from django.http import HttpResponse
from django.shortcuts import render, redirect
from .forms import ImageForm
from .models import Image
  
def index(request):
    """Process images uploaded by users"""

    if request.method == 'POST':
        form = ImageForm(request.POST, request.FILES)
  
        if form.is_valid():
            form.save()
            gallery = Image.objects.all().order_by('-id')
            return redirect('index')
    else:
        form = ImageForm()
        gallery = Image.objects.all().order_by('-id')
    return render(request, 'ex/index.html', {'form' : form, 'gallery': gallery})
  