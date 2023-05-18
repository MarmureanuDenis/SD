#include <iostream>
#include <queue>

#define V 5  //numarul de noduri din graf

void BFS(int graf[V][V], int start) {
    std::queue<int> coada;
    bool vizitat[V];

    
    for (int i = 0; i < V; i++)
        vizitat[i] = false;

    
    coada.push(start);
    vizitat[start] = true;

    while (!coada.empty()) {
        int nod = coada.front();
        std::cout << nod << " ";
        coada.pop();

        for (int i = 0; i < V; i++) {
            if (graf[nod][i] == 1 && !vizitat[i]) {
                coada.push(i);
                vizitat[i] = true;
            }
        }
    }
}

int main() {
    int graf[V][V] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    std::cout << "Parcurgere in latime incepand cu nodul 0: ";
    BFS(graf, 0);

    return 0;
}