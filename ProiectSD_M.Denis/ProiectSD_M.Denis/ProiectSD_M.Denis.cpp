#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int n, s, contor_pagina, contor_elemente;

struct masini {
    int an;
    string nume;
    string firma;
    string culoare;

    long pret;
    bool disponibilitate;
    int nr_locuri;
    int indice_ordine;
}v[1000];


void inserare_elemente()
{
    contor_elemente++;
    n++;
    cout << "Introducere date masina:" << endl;
    cout << "Nume: ";            cin >> v[contor_elemente].nume;               cout << endl;
    cout << "An: ";              cin >> v[contor_elemente].an;                 cout << endl;
    cout << "Firma: ";           cin >> v[contor_elemente].firma;              cout << endl;
    cout << "Pret: ";            cin >> v[contor_elemente].pret;               cout << endl;
    cout << "Numar locuri: ";    cin >> v[contor_elemente].nr_locuri;          cout << endl;
    cout << "Culoare: ";         cin >> v[contor_elemente].culoare;            cout << endl;
    cout << "Disponibilitate: "; cin >> v[contor_elemente].disponibilitate;    cout << endl;

    system("cls");
}

void afisare_elemente()
{
    int inapoi;
    cout << "Lista de masini:" << endl << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Nume: ";         cout << v[i].nume;               cout << endl;
        cout << "An: ";              cout << v[i].an;                 cout << endl;
        cout << "Firma: ";           cout << v[i].firma;              cout << endl;
        cout << "Pret: ";            cout << v[i].pret;               cout << endl;
        cout << "Numar locuri: ";    cout << v[i].nr_locuri;          cout << endl;
        cout << "Culoare: ";         cout << v[i].culoare;            cout << endl;
        cout << "Disponibilitate: "; cout << v[i].disponibilitate;    cout << endl << endl << endl << endl << endl;
    }

    cout << "                                    " << "Inapoi(5):";
    cin >> inapoi;

    system("cls");
}
void numarul_de_masini()
{
    int inapoi;
    cout << "Numarul de masini este de " << n << "." << endl;

    cout << "                                    " << "Inapoi(5):";
    cin >> inapoi;
}

void pret_mediu()
{
    int inapoi;

    for (int i = 1; i <= n; i++)
        s = s + v[i].pret;

    s = s/n;

    cout << "Pretul mediu este de " << s << endl;

    cout << "                                    " << "Inapoi(5):";
    cin >> inapoi;
}

void ordinea_anilor()
{
    system("cls");
    int contor_indici = 0, min_temp, temp, inapoi;
    cout << "Masinile in ordine crescatoare in functie de an:" << endl;
    for (int i = 1; i <= n; i++)
        v[i].indice_ordine = 0;


    while (contor_indici < n)
    {
        min_temp = 3000;

        for (int i = 1; i <= n; i++)
            if (min_temp > v[i].an && v[i].indice_ordine != 1)
            {
                temp = i;
                min_temp = v[i].an;
            }


        v[temp].indice_ordine = 1;
        cout << v[temp].nume << "-" << v[temp].an << endl;
        contor_indici++;
    }


    cout << "                                    " << "Inapoi(5):";
    cin >> inapoi;

}

void sortare_nume()
{
    system("cls");
    int contor_indici = 0, temp, inapoi;
    string min_temp;
    cout << "Masinile in ordine crescatoare in functie de nume:" << endl;
    for (int i = 1; i <= n; i++)
        v[i].indice_ordine = 0;


    while (contor_indici < n)
    {
        min_temp = "zzzzzzzzzzzzzz";

        for (int i = 1; i <= n; i++)
            if (v[i].nume.compare(min_temp) < 0 && v[i].indice_ordine != 1)
            {
                temp = i;
                min_temp = v[i].nume;
            }


        v[temp].indice_ordine = 1;
        cout << v[temp].nume << endl;
        contor_indici++;
    }


    cout << "                                    " << "Inapoi(5):";
    cin >> inapoi;
}

void ordinea_pretului()
{
    system("cls");
    int contor_indici = 0, min_temp, temp, inapoi;
    cout << "Masinile in ordine crescatoare in functie de pret:" << endl;
    for (int i = 1; i <= n; i++)
        v[i].indice_ordine = 0;


    while (contor_indici < n)
    {
        min_temp = 999000000;

        for (int i = 1; i <= n; i++)
            if (min_temp > v[i].pret && v[i].indice_ordine != 1)
            {
                temp = i;
                min_temp = v[i].pret;
            }


        v[temp].indice_ordine = 1;
        cout << v[temp].nume << "-" << v[temp].pret << endl;
        contor_indici++;
    }


    cout << "                                    " << "Inapoi(5):";
    cin >> inapoi;
}



void date_exacte()
{
    int contor_functie;
    cout << "Functii disponibile:" << endl << endl;
    cout << "1-Numarul de masini" << endl;
    cout << "2-Pretul mediu al masinilor" << endl;
    cout << "3-Masinile afisate dupa ordinea anilor" << endl;
    cout << "4-Masinile afisate dupa ordinea pretului,crescator" << endl;
    cout << "5-Masinile ordonate in functie de nume, crescator" << endl << endl;

    cout << "Optiunea:"; cin >> contor_functie;

    if (contor_functie == 1)
    {
        system("cls");
        numarul_de_masini();
    }
    else if (contor_functie == 2)
    {
        system("cls");
        pret_mediu();
    }
    else if (contor_functie == 3)
    {
        system("cls");
        ordinea_anilor();
    }
    else if (contor_functie == 4)
    {
        system("cls");
        ordinea_pretului();
    }
    else if (contor_functie == 5)
    {
        system("cls");
        sortare_nume();
    }




}
int main()
{
    n = 0;
    contor_elemente = 0;
    while (contor_pagina != 4)
    {
        system("cls");

        cout << "                                                        Proiect SD- ""Registru masini" << endl << endl;

        cout << "Pagina 1- Adaugare masina." << endl;
        cout << "Pagina 2- Interogare date specifice." << endl;
        cout << "Pagina 3- Afisare lista masini." << endl;
        cout << "Pagina 4-Iesire." << endl << endl;
        cout << "Pagina:";
        cin >> contor_pagina;

        if (contor_pagina == 1)
        {
            system("cls");
            inserare_elemente();
        }

        else if (contor_pagina == 2)
        {
            system("cls");
            date_exacte();
        }

        else if (contor_pagina == 3)
        {
            system("cls");
            afisare_elemente();
        }
        else if (contor_pagina == 4)
            continue;
        else
        {
            cout << "Pagina selectata nu exista!" << endl << endl;

        }



    }
    return 0;
}