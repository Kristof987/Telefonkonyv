#include "search.h"

Book* search(Book* inputBook, int param, string data) //keresofuggveny stringekre
{
	Book* result; //itt taroljuk a talalt rekordot/rekordokat
	result = new Book; //letrehozzuk
	Student* currentStudent = inputBook->studentBook;
	while (currentStudent != NULL) //vegigjarunk a diakokon
	{
		if (1 == param) // nev vizsgalata
		{
			if (currentStudent->getName() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}
		}
		else if (2 == param) // becenev vizsgalata
		{
			if (currentStudent->getNickname() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}

		}
		else if (4 == param) // email vizsgalata
		{
			if (currentStudent->getEmail() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}
		}
		else if (5 == param) // komment vizsgalata
		{
			if (currentStudent->getComment() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}
		}
		else if (8 == param) // iskola vizsgalata
		{
			if (currentStudent->getSchool() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}
		}
		currentStudent = currentStudent->nextElement;
	}

	Adult* currentAdult = inputBook->adultBook;
	//Loop in the Adult
	while (currentAdult != NULL) //ugyanez...
	{
		if (1 == param)
		{
			if (currentAdult->getName() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}
		}
		else if (2 == param)
		{
			if (currentAdult->getNickname() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}

		}
		else if (4 == param)
		{
			if (currentAdult->getEmail() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}
		}
		else if (5 == param)
		{
			if (currentAdult->getComment() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}
		}
		else if (9 == param) // csak most munkahelyet vizsgalunk
		{
			if (currentAdult->getWorkplace() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}
		}
		currentAdult = currentAdult->nextElement;
	}

	Retired* currentRetired = inputBook->retiredBook;
	//Loop in the Retired
	while (currentRetired != NULL) //ugyanez...
	{
		if (1 == param)
		{
			if (currentRetired->getName() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		else if (2 == param)
		{
			if (currentRetired->getNickname() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		else if (4 == param)
		{
			if (currentRetired->getEmail() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		else if (5 == param)
		{
			if (currentRetired->getComment() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		else if (10 == param) //csak most hobbit vizsgalunk
		{
			if (currentRetired->getHobby() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		currentRetired = currentRetired->nextElement;
	}
	return result; //visszaterunk a talalt rekorddal/rekordokkal

}

Book* search(Book* inputBook, int param, Number data) //keresofuggveny Number tipusra
{
	Book* result;
	result = new Book;
	Student* currentStudent = inputBook->studentBook;
	//Loop in the Student
	while (currentStudent != NULL)
	{
		if (6 == param) // Munkahelyi telefonszam
		{
			if (currentStudent->getWorknumber() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}
		}
		else if (9 == param) // Maganszam
		{
			if (currentStudent->getPhonenumber() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}
		}
		currentStudent = currentStudent->nextElement;
	}
	Adult* currentAdult = inputBook->adultBook;
	//Loop in the Adult
	while (currentAdult != NULL)
	{
		if (6 == param) // Név
		{
			if (currentAdult->getWorknumber() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}
		}
		else if (9 == param) // Becenév
		{
			if (currentAdult->getPhonenumber() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}

		}
		currentAdult = currentAdult->nextElement;
	}

	Retired* currentRetired = inputBook->retiredBook;
	//Loop in the Retired
	while (currentRetired != NULL)
	{
		if (6 == param) // Név
		{
			if (currentRetired->getWorknumber() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		else if (9 == param) // Becenév
		{
			if (currentRetired->getPhonenumber() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		currentRetired = currentRetired->nextElement;
	}
	return result;
}

Book* search(Book* inputBook, int param, Address data) //keresofuggveny Address tipusra
{
	Book* result;
	result = new Book;
	Student* currentStudent = inputBook->studentBook;
	//Loop in the Student
	while (currentStudent != NULL)
	{
		if (3 == param) // Munkahelyi telefonszam
		{
			if (currentStudent->getAddress() == data)
			{
				inputBook->cutByPointer(currentStudent);
				result->add(currentStudent);
			}
		}
		currentStudent = currentStudent->nextElement;
	}
	Adult* currentAdult = inputBook->adultBook;
	//Loop in the Adult
	while (currentAdult != NULL)
	{
		if (3 == param) // Név
		{
			if (currentAdult->getAddress() == data)
			{
				inputBook->cutByPointer(currentAdult);
				result->add(currentAdult);
			}
		}
		currentAdult = currentAdult->nextElement;
	}

	Retired* currentRetired = inputBook->retiredBook;
	//Loop in the Retired
	while (currentRetired != NULL)
	{
		if (3 == param) // Név
		{
			if (currentRetired->getAddress() == data)
			{
				inputBook->cutByPointer(currentRetired);
				result->add(currentRetired);
			}
		}
		currentRetired = currentRetired->nextElement;
	}
	return result;
}
