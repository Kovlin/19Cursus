from django import forms

class InputForm(forms.Form):
    input1 = forms.CharField(label='Enter a value', max_length=100)
    
    def __str__(self):
        print(self.input1)