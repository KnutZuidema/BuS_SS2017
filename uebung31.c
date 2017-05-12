#include <stdio.h>
#include <limits.h>

int main(int argc ,char** argv){
	char i;
	for(i=0;i <1;i++)
		printf("%i ",i);
		
	unsigned int x = CHAR_BIT;
	printf("%i\n", x);
	return 0;
}

/*
	a) 	Beispielsweise kill -9 -1 bricht alle momentan laufenden Prozesse, bis auf kill und init, ab.
	
	b) 	ps gibt ein Schnappschuss aller laufenden Prozesse aus.
		top zeigt alle momentan laufenden Prozesse in einem Real-Time Interface an, welches bedingt interaktiv ist.
		
	c)	Das Program terminiert nicht, da die Variable i als char intialisiert wurde und der signed char-Typ eine Groesse von 8 Bit hat. Die so maximal darstellbare Menge ist [+127, -128]. Da die Terinierungsklausel fuer die for-Schleife als i<500 gewaehlt wurde, "resettet" sich die Variable i sobald die Schleife 127-mal durchlaufen wurde.