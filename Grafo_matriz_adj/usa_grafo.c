#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    int teste;
    Grafo *grafo = GRAFOconstroi(5);
    GRAFOinsere_aresta(grafo, ARESTA(0, 1));
    GRAFOinsere_aresta(grafo, ARESTA(1, 3));
    GRAFOinsere_aresta(grafo, ARESTA(4, 3));
    GRAFOinsere_aresta(grafo, ARESTA(4, 0));
    
    //GRAFOinsere_aresta(grafo, ARESTA(3, 2));
    /*
    teste = GRAFOconexo(grafo);
    if (teste == 1) printf("não é conexo\n");
    else    printf("é conexo\n");
    
    GRAFOcaminho(grafo, 0, 4);
    */

    teste = GRAFOciclo(grafo);
    if (teste == 1) printf("Tem ciclo\n");
    else printf("Acíclico\n");

    GRAFOdestroi(grafo);
    return 0;
}