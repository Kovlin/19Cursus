from django.db import models


class Image(models.Model):
    title = models.CharField(max_length = 64, null = False)
    file = models.ImageField(upload_to = 'images/' , null = False)