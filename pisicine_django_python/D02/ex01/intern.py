class Intern:
    
    class Coffee:
        def __str__(self):
            return "This is the worst coffee you ever tasted."

    def __init__(self, Name="My name? I’m nobody, an intern, I have no name."):
        self.Name = Name
    
    def __str__(self):
        return self.Name

    def work(self):
        raise Exception("I’m just an intern, I can’t do that...")

    def make_coffee(self):
        return Intern.Coffee()

def test_intern():
    
    intern = Intern()
    mark = Intern("Mark")

    print(intern)
    print(mark)

    try :
        mark.work()
    except Exception as e:
        print(e)
    
    print(mark.make_coffee())

if __name__ == '__main__':
    test_intern()