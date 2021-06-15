def get_elem_name(elem):
    name = elem[0].split('=')
    return name[0]

def get_elem_pos(elem):
    pos = elem[0].split(':')
    return int(pos[1])

def get_elem_num(elem):
    num = elem[1].split(':')
    return num[1]

def get_elem_small(elem):
    small = elem[2].split(':')
    return small[1]

def get_elem_molar(elem):
    molar = elem[3].split(':')
    return molar[1]

def get_elem_electron(elem):
    electron = elem[4].split(':')
    return electron[1]

def periodic_table():

    HTML = """
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>periodic_table</title>
  <style>
    table{{
      border-collapse: collapse;
    }}
    h4 {{
      text-align: center;
      color: blue;
    }}
    li {{
        color: green;
    }}
    ul {{
      list-style:none;
      padding-left:0px;
    }}
  </style>
</head>
<body>
  <table>
    {body}
  </table>
</body>
</html>
"""

    TO_FILL = """
        <td style="border: 1px solid red; padding:10px">
            <h4>{name}</h4>
                <ul>
                    <li>No {number}</li>
                    <li>{small}</li>
                    <li>{molar}</li>
                    <li>{electron} electron</li>
                </ul>
        </td>
"""

    fichier = open("periodic_table.txt", "r")
    lines = fichier.readlines()
    fichier.close()
    list_elem = []
    for line in lines:
        list_elem.append(line.strip().replace(" ", "").split(','))
    body = "<tr>"
    position = 0
    for elem in list_elem:
        if position > get_elem_pos(elem):
            body += "    </tr>\n    <tr>"
            position = 0
        for _ in range(position, get_elem_pos(elem) - 1):
            body += "        <td></td>\n"
        position = get_elem_pos(elem)
        body += TO_FILL.format(name = get_elem_name(elem), number = get_elem_num(elem), small = get_elem_small(elem),
            molar = get_elem_molar(elem), electron = get_elem_electron(elem))
    body += "    </tr>\n"
    HTML = HTML.format(body = body)
    fichier = open("periodic_table.html", "w")
    fichier.write(HTML)
    fichier.close()

if __name__ == '__main__':
	periodic_table()