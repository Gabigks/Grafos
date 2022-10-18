#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "grafo.c"

int main(){
    int num_v, test=1, n;
    Grafo *g = malloc(sizeof(*g));
    Aresta *a = malloc(sizeof(Aresta));
    printf("Numero de vertices do grafo: ");
    scanf("%d", &num_v);
    g = GRAFOconstroi(num_v);

    while(test!=0){
        printf("\nEscreva a operação que deseja realizar: \n");
        printf("(1) Adiciona uma aresta no grafo\n");
        printf("(2) Remove uma aresta do grafo\n");
        printf("(3) Numero de aresta total do grafo\n");
        printf("(4) Numero de vertices total do grafo\n");
        printf("(5) Imprime o grafo\n");
        printf("(0) Finaliza o programa\n");
        scanf("%d", &test);
        printf("\n");
        switch (test)
        {
        case 1:
            printf("Primeiro vertice: ");
            scanf("%d", &a->v1);
            printf("Segundo vertice: ");
            scanf("%d", &a->v2);
            GRAFOinsere_aresta(g, *a);
            break;
        case 2:
            printf("Primeiro vertice: ");
            scanf("%d", &a->v1);
            printf("Segundo vertice: ");
            scanf("%d", &a->v2);
            GRAFOremove_aresta(g, *a);
            break;
        case 3:
            n = GRAFOget_num_aresta(g);
            printf("Total de arestas: %d\n", n);
            break;
        case 4: 
            n = GRAFOget_num_vertice(g);
            printf("Total de vertices: %d\n", n);
            break;
        case 5:
            GRAFOimprime(g);
            break;
        case 0:
        GRAFOdestroi(g);
            break;
        }
    }

    return 0;
}