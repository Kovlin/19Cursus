from django.shortcuts import render


# Create your views here.
def table(request):
    context = {}
    context["table"] = []
    for i in range(50):
        hx = '{0:02x}'.format(int(255 - 255/50 * i)) 
        context["table"].append(list())
        context["table"][i].append("style=" + "background-color:#" + "{hx}{hx}{hx}".format(hx=hx) + ";") #black
        context["table"][i].append("style=" + "background-color:#" + "{hx}0000".format(hx=hx) + ";") #red 
        context["table"][i].append("style=" + "background-color:#" + "00{hx}00".format(hx=hx) + ";") #green
        context["table"][i].append("style=" + "background-color:#" + "0000{hx}".format(hx=hx) + ";") #blue
    return render(request, 'ex03/table.html', context)