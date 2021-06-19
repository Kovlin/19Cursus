from django.shortcuts import render, redirect
from .forms import InputForm
from django.contrib import messages
from django.conf import settings
import datetime, pytz

def form(request):    
    try:
        f = open(settings.LOGFILE, 'r')
        historic = [line for line in f.readlines() if line != '\n']
        lst = [line.split(']')[1].strip() for line in historic if line != '\n']
        f.close()
    except:
        historic = []
        lst = []
    if request.method == 'POST':
        new_entries = []
        dt = datetime.datetime.now(pytz.timezone('Europe/Brussels'))
        form = InputForm(request.POST)
        if form.is_valid():
            new_entries.append(form.data["input1"])
            try:
                f = open(settings.LOGFILE, 'w')
                for line in historic:
                    f.write( line + '\n')
                for line in new_entries:
                    f.write('[' + dt.strftime("%d-%m-%Y %H:%M:%S")+ '] ' + line + '\n')
                f.close()
            except:
                return(print("Couldn't write to logfile"))
            return redirect('ex02-form')
    else:
        form = InputForm()
    return render(request, 'ex02/form.html', {'form' : form, 'inputs': lst})

