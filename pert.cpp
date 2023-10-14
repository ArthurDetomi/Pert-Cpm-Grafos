#include <bits/stdc++.h>

using namespace std;

#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0);                                                                \
    cout.tie(0);

#define endl '\n'

#define pb push_back

#define f first

#define s second

#define mp make_pair

#define debug printf

map<int, set< pair<int, int> > > grafo;

map<int, set< pair<int, int> > > grafo_inverso;

set<int> all_vertices;

map<int, pair<int, int> > tempos;

int get_vertice_inicial() {
    for (auto vr: all_vertices) {
        if (grafo_inverso.find(vr) == grafo_inverso.end()) {
            return vr;
        }
    }
    cout << "Erro - Grafo não possui um vertice inicial";
    exit(1);
}

int get_vertice_final() {
    for (auto vr : all_vertices) {
        if (grafo[vr].size() == 0) {
            return vr;
        }
    }
    cout << "Erro - Grafo não possui um vertice final";
    exit(1);
}

bool contem_subconjunto(const set<int> &conjunto,const set< pair<int, int> > &subconjunto) {
    for (auto par : subconjunto) {
        if (conjunto.find(par.first) == conjunto.end()) {
            return false;
        }
    }
    return true;
}

void pert() {
    queue<int> fila;
    set<int> cache;
    
    int vr_inicio = get_vertice_inicial();
    
    fila.push(vr_inicio);
    cache.insert(vr_inicio);
    tempos[vr_inicio].f = 0;


    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (auto par : grafo[atual]) {
            int vizinho = par.first;
            int peso_para_vizinho = par.second;

            if (cache.find(vizinho) == cache.end()) {
                tempos[vizinho].f = tempos[atual].f + peso_para_vizinho;
                tempos[vizinho].s = tempos[vizinho].f;

                cache.insert(vizinho);
                fila.push(vizinho);
            } else {
                tempos[vizinho].f = max(tempos[vizinho].f, tempos[atual].f + peso_para_vizinho);
                tempos[vizinho].s = tempos[vizinho].f;
            }

            if (contem_subconjunto(cache, grafo_inverso[vizinho])) {
                fila.push(vizinho);
            }
        }
    }

    int vr_final = get_vertice_final();
    cache.clear();
    cache.insert(vr_final);
    fila.push(vr_final);

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (auto par : grafo_inverso[atual]) {
            int vizinho = par.first;
            int peso_para_vizinho = par.second;

            if (cache.find(vizinho) == cache.end()) {
                tempos[vizinho].s = tempos[atual].s - peso_para_vizinho;

                cache.insert(vizinho);
            } else {
                tempos[vizinho].s = min(tempos[vizinho].s, tempos[atual].s - peso_para_vizinho);
            }

            if (contem_subconjunto(cache, grafo[vizinho])) {
                fila.push(vizinho);
            }
        }
    }
}

set<int> get_caminho_critico() {
    set<int> caminho_critico;

    for (auto p : tempos) {
        if (p.second.first == p.second.second) {
            caminho_critico.insert(p.f);
        }
    }

    return caminho_critico;
}

void imprime_caminho(const set<int> &dados);

void imprime_tempos();

int main() {
    fastio;

    int vertice, vizinho, peso;

    while (cin >> vertice >> vizinho >> peso) {
        grafo[vertice].insert(mp(vizinho, peso));
        grafo_inverso[vizinho].insert(mp(vertice, peso));

        all_vertices.insert(vertice);
        all_vertices.insert(vizinho);
    }

    pert();

    set<int> caminho_critico = get_caminho_critico();

    imprime_tempos();
    
    imprime_caminho(caminho_critico);

    return 0;
}

void imprime_caminho(const set<int> &dados) {
    int tam = dados.size(), cont = 0;

    printf("\nCaminho Crítico:\n");
    for (auto v : dados) {
        if (cont != tam - 1) {
            printf("%d -> ", v);
        } else {
            printf("%d", v);
        }
        cont++;
    }
    printf("\n");
}

void imprime_tempos() {
    printf("  Tempos mais cedo e mais tarde:\n");
    printf(" vr  cedo  tarde\n"); 
    for (auto p : tempos) {
        printf("%3d %3d  %3d\n",p.f,p.s.f,p.s.s);
    }
    cout << endl;
}

