# Generated by Django 3.2.4 on 2021-06-27 15:54

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('messenger', '0002_rename_reveiver_message_receiver'),
    ]

    operations = [
        migrations.DeleteModel(
            name='UserFavouriteArticle',
        ),
    ]
