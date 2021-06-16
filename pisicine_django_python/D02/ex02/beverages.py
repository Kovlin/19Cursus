class HotBeverage:

    name = "hot beverage"
    price = 0.30

    def description(self):
        return  "Just some hot water in a cup."

    def __str__(self):
        s = "name : " + self.name + "\nprice : " + "{0:.2f}".format(self.price) + "\ndescription : " + self.description()
        return s

class Coffee(HotBeverage):

    name = "coffee"
    price = 0.40

    def description(self):
        return "A coffee, to stay awake."

class Tea(HotBeverage):

    name = "tea"

class Chocolate(HotBeverage):

    name = "chocolate"
    price = 0.50

    def description(self):
        return "Chocolate, sweet chocolate..."

class Cappuccino(HotBeverage):

    name = "cappuccino"
    price = 0.45

    def description(self):
        return "Un po’ di Italia nella sua tazza!"

def test_beverage():

    print(HotBeverage())
    print(Coffee())
    print(Tea())
    print(Chocolate())
    print(Cappuccino())


if __name__ == '__main__':
    test_beverage()