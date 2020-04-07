#!/usr/bin/env python3

import sys
    	
morse = {'a': ".-",
		'b': "-...",
		'c': "-.-.",
		'd': "-..",
		'e': ".",
		'f': "..-.",
		'g': "--.",
		'h': "....",
		'i': "..",
		'j': ".---",
		'k': "-.-",
		'l': ".-..",
		'm': "--",
		'n': "-.",
		'o': "---",
		'p': ".--.",
		'q': "--.-",
		'r': ".-.",
		's': "...",
		't': "-",
		'u': "..-",
		'v': "...-",
		'w': ".--",
		'x': "-..-",
		'y': "-.--",
		'z': "--.."}

def main():
    	
	if len(sys.argv) == 2:
		ret = sys.argv[1].split(" ")
		ret = "".join(ret)

	if len(sys.argv) == 2 and ret != "" and ret.isalpha():
		ret = ret.lower()	
		aux = ""

		for i in ret:		
			for j, k in morse.items():
    				if i == j:		
    					aux += k
										
		print(aux)

	else:
		print("usage: " + sys.argv[0] + " " + "a-zA-Z string")

if __name__ == "__main__":
    	
	main()