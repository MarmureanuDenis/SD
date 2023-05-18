#include <iostream>
#include <stack>

#define V 5  //numarul de noduri din graf

void DFS(int graf[V][V], int start) {
    std::stack<int> stiva;
    bool vizitat[V];

    //initializam vectorul de vizitare cu false
    for (int i = 0; i < V; i++)
        vizitat[i] = false;

    
    stiva.push(start);
    vizitat[start] = true;

    while (!stiva.empty()) {
        int nod = stiva.top();
        std::cout << nod << " ";
        stiva.pop();

        for (int i = 0; i < V; i++) {
            if (graf[nod][i] == 1 && !vizitat[i]) {
                stiva.push(i);
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

    std::cout << "Parcurgere in adancime incepand cu nodul 0: ";
    DFS(graf, 0);

    return 0;
}