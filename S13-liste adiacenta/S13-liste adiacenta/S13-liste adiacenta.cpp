#include <iostream>
#include <vector>

void adaugaMuchie(std::vector<std::vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void afiseazaGraf(const std::vector<std::vector<int>>& adj) {
    int V = adj.size();
    for (int v = 0; v < V; ++v) {
        std::cout << "\n Lista de adiacenta a nodului "
            << v << "\n cap ";
        for (auto x : adj[v])
            std::cout << "-> " << x;
        std::cout << std::endl;
    }
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> adj(V);
    adaugaMuchie(adj, 0, 1);
    adaugaMuchie(adj, 0, 4);
    adaugaMuchie(adj, 1, 2);
    adaugaMuchie(adj, 1, 3);
    adaugaMuchie(adj, 1, 4);
    adaugaMuchie(adj, 2, 3);
    adaugaMuchie(adj, 3, 4);
    afiseazaGraf(adj);
    return 0;
}