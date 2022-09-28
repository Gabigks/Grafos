/*
 * Tarefa de laboratorio 00_a - Pilha
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef GRAFO_H

#define GRAFO_H

#include <stdbool.h>
#include "item.h"
#include "aresta.h"

typedef struct grafo Grafo;

Grafo *GRAFOconstroi();

void GRAFOinsere_aresta(Grafo *g, Aresta a);

Item GRAFOremove_aresta(Grafo *g, Aresta a);

int GRAFOget_num_aresta(Grafo *g);

int GRAFOget_num_vertice(Grafo *g);

void GRAFOimprime(Grafo *g);

void GRAFOdestroi(Grafo *g);

#endif /* PILHA_H */
