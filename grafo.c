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

void GRAFOdestroi(Grafo *g) {
    
    for (int i = 0; i < g->num_v; i++){
        free(g->matriz[i]);
    }

    free(g->matriz);
    free(g);
}
