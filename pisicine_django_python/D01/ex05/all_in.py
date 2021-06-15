def print_state():
    import sys
    if len(sys.argv) != 2:
        sys.exit(1)
    string = sys.argv[1]
    states = {
		"Oregon":"OR",
		"Alabama":"AL",
		"New Jersey":"NJ",
		"Colorado":"CO"
	}
    capital_cities = {
		"OR":"Salem",
		"AL":"Montgomery",
		"NJ":"Trenton",
		"CO":"Denver"
	}
    list_arg = string.split(',')
    for x in list_arg:
        if not x.isspace() and len(x) != 0:
            x =  " ".join(x.split())
            to_print = x + " is neither a capital city nor a state"
            for key, value in capital_cities.items():
                if value.capitalize() == x.capitalize():
                    for key2, value2 in states.items():
                        if value2 == key:
                            to_print = x.capitalize() + " is the capital of " + key2
            for key in states:
                if x.capitalize() == key.capitalize():
                    to_print = capital_cities[states[key]] + " is the capital of " + key
            print (to_print)

if __name__ == '__main__':
	print_state()