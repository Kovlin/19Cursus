#!/usr/bin/python3

import requests, sys
from bs4 import BeautifulSoup
def to_philo():
    if len(sys.argv) != 2:
        print("wrong number of arguments")
        exit(1)
    r = requests.Session()
    url = "https://en.wikipedia.org/wiki/chocolatine"
    html_text = r.get(url).text
    soup = BeautifulSoup(html_text,'html.parser')
    for link in soup.find_all('a'):
        print(link.get('href'))

if __name__ == '__main__':
    to_philo()