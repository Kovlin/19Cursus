def print_numbers_from_file():
    fichier = open("numbers.txt", "r")
    text = fichier.read()
    fichier.close()
    numbers = text.split(',')
    for x in numbers:
        print(x)


if __name__ == '__main__':
	print_numbers_from_file()
