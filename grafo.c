#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo {
    int num_vertices;
    int num_arestas;
    int **matriz_adj;
};

int **constroi_matriz_int(int m, int n) {
    int **matriz = malloc(m * sizeof(*matriz));

    for (int i = 0; i < m; i++) {
        matriz[i] = malloc(n * sizeof(*(matriz[i])));

        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

void destroi_matriz_int(int **matriz, int m) {
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

bool GRAFOvertice_valido(Grafo *g, int v) {
    if ((v >= 0) && (v <= (g->num_vertices - 1))) {
        return true;
    }

    return false;
}

bool GRAFOaresta_valida(Grafo *g, Aresta e) {
    if (GRAFOvertice_valido(g, e.v1) && GRAFOvertice_valido(g, e.v2)) {
        return true;
    }

    return false;
}

Grafo *GRAFOconstroi(int num_vertices) {
    Grafo *g = malloc(sizeof(*g));

    g->num_vertices = num_vertices;
    g->num_arestas = 0;
    g->matriz_adj = constroi_matriz_int(num_vertices, num_vertices);

    return g;
}

int GRAFOnum_vertices(Grafo *g) {
    return g->num_vertices;
}

int GRAFOnum_arestas(Grafo *g) {
    return g->num_arestas;
}

bool GRAFOtem_aresta(Grafo *g, Aresta e) {
    if (!GRAFOaresta_valida(g, e)) {
        printf("Erro na operacao GRAFOtem_aresta: a aresta %d %d eh "
            "invalida!\n", e.v1, e.v2);
        exit(EXIT_FAILURE);
    }

    return (g->matriz_adj[e.v1][e.v2] != 0);
}

void GRAFOinsere_aresta(Grafo *g, Aresta e) {
    if (!GRAFOaresta_valida(g, e)) {
        printf("Erro na operacao GRAFOinsere_aresta: a aresta %d %d eh "
            "invalida!\n", e.v1, e.v2);
        exit(EXIT_FAILURE);
    }

    if (GRAFOtem_aresta(g, e) || (e.v1 == e.v2)) {
        return;
    }

    g->matriz_adj[e.v1][e.v2] = 1;
    g->matriz_adj[e.v2][e.v1] = 1;

    g->num_arestas++;
}

void GRAFOremove_aresta(Grafo *g, Aresta e) {
    if (!GRAFOaresta_valida(g, e)) {
        printf("Erro na operacao GRAFOremove_aresta: a aresta %d %d eh "
            "invalida!\n", e.v1, e.v2);
        exit(EXIT_FAILURE);
    }

    if (!GRAFOtem_aresta(g, e)) {
        return;
    }

    g->matriz_adj[e.v1][e.v2] = 0;
    g->matriz_adj[e.v2][e.v1] = 0;

    g->num_arestas--;
}

void GRAFOdestroi(Grafo *g) {
    destroi_matriz_int(g->matriz_adj, g->num_vertices);

    free(g);
}

static bool caminho(Grafo *g, int v, int w, int marcado[], int indent) {
    for (int i = 0; i < indent; i++) printf("    ");
    printf("caminho | v1: %d, v2: %d\n", v, w);

    if (v == w) {
        printf("%d ", v);
        return true;
    }

    marcado[v] = 1;
    for (int u = 0; u < g->num_vertices; u++)
        if (g->matriz_adj[v][u] != 0)
            if (marcado[u] == 0)
                if (caminho(g, u, w, marcado, indent + 1)) {
                    printf("%d ", v);
                    return true;
                }
    return false;
}

bool GRAFOcaminho(Grafo *g, int v, int w) {
    int marcado[g->num_vertices];

    for (int i = 0; i < g->num_vertices; i++) {
        marcado[i] = 0;
    }

    bool has_path = caminho(g, w, v, marcado, 0);
    printf("\n");
    return has_path;
}

int GRAFOconexo(Grafo *g){
    for(int i = 0; i < g->num_vertices; i++){
        for(int j = i + 1; j < g->num_vertices; j++){
            if(i != j)
                if(GRAFOcaminho(g, i, j) == false) return 1;
        }
    }
    return 0;
}

int GRAFOciclo(Grafo *g){
    for(int i = 0; i < g->num_vertices; i++){
        for(int j = i+1; j < g->num_vertices; j++){
            if(GRAFOtem_aresta(g, ARESTA(i, j))){
                GRAFOremove_aresta(g, ARESTA(i, j));
                if(GRAFOcaminho(g, i, j)){
                    GRAFOinsere_aresta(g, ARESTA(i, j));
                    return 1;
                }
                else{
                    GRAFOinsere_aresta(g, ARESTA(i, j));
                }
            }                
        }
    }
    return 0;
}