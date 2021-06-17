# #!/usr/bin/python3

import requests, json, dewiki, sys
def remove_html_markup(s):
    tag = False
    quote = False
    out = ""
    for c in s:
            if c == '<' and not quote:
                tag = True
            elif c == '>' and not quote:
                tag = False
            elif (c == '"' or c == "'") and tag:
                quote = not quote
            elif not tag:
                out = out + c
    return out
def askToWiki(arg):
    if len(arg) != 2:
        print ("Bad number of arguments")
        sys.exit()
    S = requests.Session()
    #api renvoyant un tableau avec les noms les plus proches de ce qui a ete envoyé
    URL = "https://fr.wikipedia.org/w/api.php?action=opensearch&search={link}&limit=1&format=json".format(link=arg[1])
    R = S.get(url=URL)
    DATA = R.json()
    #DATA[1] est le resultat le plus proche
    PARAMS = {
        "action": "parse",
        "page": DATA[1],
        "prop": "wikitext",
        "format": "json",
        "redirects": "true"
    }
    prefix = arg[1]
    prefix = prefix + '.wiki'
    R2 = S.get(url=URL, params=PARAMS)
    DATA = R2.json()
    #Premiere ecriture
    my_file = open(prefix, "w")
    #ecrit dans le fichier les clés parse wikitext et * du dictionnaire
    my_file.write(DATA["parse"]["wikitext"]["*"])
    my_file.close()
    # Recu + modif
    with open(prefix, 'r') as my_file:
        dataToMyFile = my_file.read()
    result = dewiki.from_string(dataToMyFile)
    # result = dataToMyFile
    # result = remove_html_markup(result)
    # result = result.replace('[', '').replace(']', '') \
    #     .replace('{', '').replace('}', '').replace('\'', '') \
    #         .replace('https://', '\nsource: https://') \
    #             .replace('http://', '\nsource: https://')
    my_file.close()
    # Reecriture
    my_file = open(prefix, "w")
    my_file.write(result)
    my_file.close()

if __name__ == '__main__':
    askToWiki(sys.argv)