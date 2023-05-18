#include<iostream>
using namespace std;

struct Nod {
    int val;
    struct Nod* stanga, * dreapta;
    int inaltime;
};

int inaltime(Nod* N) {
    if (N == NULL)
        return 0;
    return N->inaltime;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Nod* creazaNod(int val) {
    Nod* nodNou = new Nod();
    nodNou->val = val;
    nodNou->stanga = NULL;
    nodNou->dreapta = NULL;
    nodNou->inaltime = 1;
    return(nodNou);
}

Nod* rotireDreapta(Nod* y) {
    Nod* x = y->stanga;
    Nod* T2 = x->dreapta;
    x->dreapta = y;
    y->stanga = T2;
    y->inaltime = max(inaltime(y->stanga), inaltime(y->dreapta)) + 1;
    x->inaltime = max(inaltime(x->stanga), inaltime(x->dreapta)) + 1;
    return x;
}

Nod* rotireStanga(Nod* x) {
    Nod* y = x->dreapta;
    Nod* T2 = y->stanga;
    y->stanga = x;
    x->dreapta = T2;
    x->inaltime = max(inaltime(x->stanga), inaltime(x->dreapta)) + 1;
    y->inaltime = max(inaltime(y->stanga), inaltime(y->dreapta)) + 1;
    return y;
}

int echilibru(Nod* N) {
    if (N == NULL)
        return 0;
    return inaltime(N->stanga) - inaltime(N->dreapta);
}

Nod* insereaza(Nod* nod, int val) {
    if (nod == NULL)
        return(creazaNod(val));
    if (val < nod->val)
        nod->stanga = insereaza(nod->stanga, val);
    else if (val > nod->val)
        nod->dreapta = insereaza(nod->dreapta, val);
    else
        return nod;

    nod->inaltime = 1 + max(inaltime(nod->stanga), inaltime(nod->dreapta));
    int balanta = echilibru(nod);

    // cazul stanga-stanga
    if (balanta > 1 && val < nod->stanga->val)
        return rotireDreapta(nod);

    // cazul dreapta-dreapta
    if (balanta < -1 && val > nod->dreapta->val)
        return rotireStanga(nod);

    // cazul stanga-dreapta
    if (balanta > 1 && val > nod->stanga->val) {
        nod->stanga = rotireStanga(nod->stanga);
        return rotireDreapta(nod);
    }

    // cazul dreapta-stanga
    if (balanta < -1 && val < nod->dreapta->val) {
        nod->dreapta = rotireDreapta(nod->dreapta);
        return rotireStanga(nod);
    }

    return nod;
}

void preordine(Nod* radacina) {
    if (radacina != NULL) {
        cout << radacina->val << " ";
        preordine(radacina->stanga);
        preordine(radacina->dreapta);
    }
}

int main() {
    Nod* radacina = NULL;

    radacina = insereaza(radacina, 9);
    radacina = insereaza(radacina, 5);
    radacina = insereaza(radacina, 10);
    radacina = insereaza(radacina, 0);
    radacina = insereaza(radacina, 6);
    radacina = insereaza(radacina, 11);
    radacina = insereaza(radacina, 3);
    radacina = insereaza(radacina, 1);
    radacina = insereaza(radacina, 2);

    cout << "Parcurgere arbore (preordine): ";
    preordine(radacina);

    return 0;
}
