def print_state():
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
    to_print = "Unknown capital city"
    capital = sys.argv[1]
    for key, value in capital_cities.items():
        if value == capital:
            for key2, value2 in states.items():
                if value2 == key:
                    to_print = key2
    print (to_print)

if __name__ == '__main__':
	print_state()
