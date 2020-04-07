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
		morse_keys = morse.keys()
		morse_values = morse.values()		
		aux = {}

		for i in range(0, len(ret)):		
			for j in range(0, len(morse_keys)):		
				if ret[i] == morse_keys[j]:	
					aux[i] = morse_values[j]
											
		ret = aux.values()
		ret = "".join(ret)
		print(ret)

	else:
		print("usage: " + sys.argv[0] + " " + "a-zA-Z string")

if __name__ == "__main__":
	main()