#!/usr/bin/python3

import random
from beverages import HotBeverage, Coffee, Tea, Cappuccino, Chocolate

class CoffeeMachine():
    
    def __init__(self):
        self.count = 0

    class EmptyCup(HotBeverage):
        
        name = "empty cup"
        price = 0.90
        desc = "An empty cup?! Gimme my money back!"
    
    class BrokenMachineException(Exception):
        def __init__(self):
            super().__init__("This coffee machine has to be repaired.")

    def repair(self):
        self.count = 0

    def serve(self, beverage):

        if self.count > 9:
            raise self.BrokenMachineException()
        self.count += 1
        res = beverage
        r = random.randint(0, 4)
        if r == 4:
            res = self.EmptyCup()
        return res


def test_machine():

    coffeeMachine = CoffeeMachine()
    for _ in range(23):
        try:
            print(coffeeMachine.serve(random.choice([Coffee(), Tea(), Cappuccino(), Chocolate()])))
        except coffeeMachine.BrokenMachineException as e:
            print(e)
            coffeeMachine.repair()
if __name__ == '__main__':
    test_machine()