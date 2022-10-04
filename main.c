#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "grafo.c"

int main(){
    int nv = 3;
    Grafo *g = malloc(sizeof(*g));

    g = GRAFOconstroi(nv);
    printf("%d", g->num_v);
    GRAFOimprime(g);

    return 0;
}