def classe_interne():
    
    if len(sys.argv) != 2:
        print("Enter one and only one argument")
        sys.exit(1)
    filepath = sys.argv[1]
    if not os.path.exists(filepath):
        print("File not found")
        sys.exit(1)
    if not os.path.isfile(filepath):
        print("Path is not a file")
    elif not filepath.endswith('.template'):
        print("Wrong file extension")
        sys.exit(1)
    file = open(filepath, "r")
    cv_content = file.read()
    file.close()
    cv_content = cv_content.format(title = settings.title, name = settings.name, 
        surname = settings.surname, age = settings.age, job = settings.job)
    file = open("rlinkov_cv.html", "w")
    file.write(cv_content)
    file.close()

if __name__ == '__main__':
	classe_interne()

class Intern: