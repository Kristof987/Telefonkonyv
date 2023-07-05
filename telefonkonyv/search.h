#ifndef SEARCH_H
#define SEARCH_H

#include "book.h"

/*
	3 parameteres fuggveny, melyek egy book pointer, egy int ertek, es egy string
	visszateresi erteke book* tipus
	a talalt rekordot/rekordokat fuzi be egy lancolt listaba
*/
Book* search(Book* inputBook, int param, string data);

/*
	3 parameteres fuggveny, melyek egy book pointer, egy int ertek, es egy number
	visszateresi erteke book* tipus
	a talalt rekordot/rekordokat fuzi be egy lancolt listaba
*/
Book* search(Book* inputBook, int param, Number data);

/*
	3 parameteres fuggveny, melyek egy book pointer, egy int ertek, es egy address
	visszateresi erteke book* tipus
	a talalt rekordot/rekordokat fuzi be egy lancolt listaba
*/
Book* search(Book* inputBook, int param, Address data);

#endif