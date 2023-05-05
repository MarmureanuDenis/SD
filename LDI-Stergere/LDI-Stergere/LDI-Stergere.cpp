#include <iostream>
using namespace std;

struct Nod {
	int numar;
	Nod* urmator;
	Nod* anterior;
};

Nod* cap = NULL;
void afisareLista(Nod* cap) {
	while (cap != NULL) {
		cout << cap->numar << "\n";
		cap = cap->urmator;
	}
}
Nod* cautarePozitie(Nod* cap, int pozitie)
{
	int i = 0;  //Pozitia curenta
	
	while (cap != NULL && i < pozitie)
	{
		cap = cap->urmator;
		i++;
	}
	//In cazul in care am gasit pozitia ceruta, o returnam
	if (i == pozitie)
		return cap;
	else
		return NULL;
}
void inserareInceput(Nod*& cap, int valoare)
{
	//Creeam noul nod si ii atribuim valoarea din paramentru
	Nod* elem = new Nod;
	elem->numar = valoare;
	elem->urmator = cap; 
	elem->anterior = NULL;
	if (cap != NULL)
		cap->anterior = elem;

	cap = elem; 
}
void stergereElement(Nod* elem)
{
	elem->anterior->urmator = elem->urmator;
	elem->urmator->anterior = elem->anterior;
	delete elem;
}
void stergereElementPozitie(Nod*& cap, int pozitie)
{
	if (pozitie == 0)
	{
		Nod* victima = cap;
		cap = cap->urmator;
		cap->anterior = NULL;
		delete victima;
	}
	else
	{
		Nod* predecesor = cautarePozitie(cap, pozitie);
		stergereElement(predecesor);
	}
}
int main() {
	inserareInceput(cap, 3);
	inserareInceput(cap, 1);
	inserareInceput(cap, 2);
	stergereElementPozitie(cap, 1);
	afisareLista(cap);
	return 0;
}

