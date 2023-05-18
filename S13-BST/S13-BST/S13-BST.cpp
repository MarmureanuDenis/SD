#include <iostream>

struct Nod {
    int valoare;
    Nod* stanga;
    Nod* dreapta;
};

// functie pentru crearea unui nod nou
Nod* creazaNod(int valoare) {
    Nod* nodNou = new Nod();
    if (!nodNou) {
        std::cout << "Memorie insuficienta!\n";
        return nullptr;
    }
    nodNou->valoare = valoare;
    nodNou->stanga = nodNou->dreapta = nullptr;
    return nodNou;
}

// functie pentru a insera o valoare in arbore
Nod* insereaza(Nod* radacina, int valoare) {
    if (radacina == nullptr) {
        radacina = creazaNod(valoare);
    }
    else if (valoare < radacina->valoare) {
        radacina->stanga = insereaza(radacina->stanga, valoare);
    }
    else {
        radacina->dreapta = insereaza(radacina->dreapta, valoare);
    }

    return radacina;
}

void parcurgereInordine(Nod* radacina) {
    if (radacina == nullptr)
        return;
    parcurgereInordine(radacina->stanga);
    std::cout << radacina->valoare << " -> ";
    parcurgereInordine(radacina->dreapta);
}

int main() {
    Nod* radacina = nullptr;
    radacina = insereaza(radacina, 8); 
    insereaza(radacina, 3);
    insereaza(radacina, 1);
    insereaza(radacina, 6);
    insereaza(radacina, 7);
    insereaza(radacina, 10);
    insereaza(radacina, 14);
    insereaza(radacina, 4);

    std::cout << "Parcurgere arbore (inordine): ";
    parcurgereInordine(radacina);

    return 0;
}