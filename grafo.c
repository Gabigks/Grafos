/*
 * Tarefa de laboratorio 00_a - Pilha
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "aresta.h"

struct grafo {
    int num_v;
    int num_a;
    int **matriz;
};

Grafo *GRAFOconstroi(int num_v) {
    Grafo *g;

    g = malloc(sizeof(*g));

    g->num_v = num_v;
    g->num_a = 0;

    g->matriz = malloc(num_v * sizeof(int*));
    
    for (int i = 0; i < num_v; i++)
    {
        g->matriz[i] = malloc(num_v * sizeof(int));
    }

    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            g->matriz[i][j] = 0;
        }
        
    }
    
    return g;
}

void GRAFOinsere_aresta(Grafo *g, Aresta a){
    g->matriz[a.v1][a.v2] = 1;
    g->matriz[a.v2][a.v1] = 1;
}

void GRAFOremove_aresta(Grafo *g, Aresta a){
    g->matriz[a.v1][a.v2] = 0;
    g->matriz[a.v2][a.v1] = 0;
}

int GRAFOget_num_aresta(Grafo *g){
    int count = 0;
    for (int i = 0; i < g->num_v; i++)
    {
        for (int j = 0; j < g->num_v; j++)
        {
            if(g->matriz[i][j] == 1){
                count++;
            }
        }
    }
    return count/2;
}

int GRAFOget_num_vertice(Grafo *g){
    return g->num_v;
}

void GRAFOimprime(Grafo *g){
    for (int i = 0; i < g->num_v; i++)
    {
        for (int j = 0; j < g->num_v; j++)
        {
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
}

void GRAFOdestroi(Grafo *g) {
    
    for (int i = 0; i < g->num_v; i++){
        free(g->matriz[i]);
    }

    free(g->matriz);
    free(g);
}
