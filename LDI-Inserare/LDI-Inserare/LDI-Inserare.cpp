
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
void inserareInceput(Nod*& cap, int valoare) {
	Nod* elem = new Nod;
	elem->numar = valoare;
	elem->urmator = cap;
	elem->anterior = NULL;
	if (cap != NULL)
		cap->anterior = elem;
	cap = elem;
}
int main() {
	inserareInceput(cap, 10);
	afisareLista(cap);
	return 0;
}

