#!/usr/bin/python3
# coding : utf8

import sys, antigravity

def geoh(lat, lon, datedow):
    antigravity.geohash(lat, lon, datedow)

if __name__ == '__main__':
    if len(sys.argv) == 4:
        try :
            lat = float(sys.argv[1])
            lon = float(sys.argv[2])
        except:
            print("float required for Latitude & Longitude.")
            sys.exit(1)
        datedow = sys.argv[3].encode('utf-8')
        geoh(lat, lon, datedow)
    else:
        print("wrong number of arguments. try : 37.421542 -122.085589 ""2005-05-26-10458.68"" for example")
        sys.exit(1)
