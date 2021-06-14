def print_capital():
    import sys
    if len(sys.argv) != 2:
        sys.exit(1)
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
    to_print = "Unknown State"
    state = sys.argv[1]
    if state in states:
        if states[state] in capital_cities:
            to_print = capital_cities[states[state]]
    print (to_print)

if __name__ == '__main__':
	print_capital()
