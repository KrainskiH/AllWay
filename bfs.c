#include <stdio.h>
#include "grafo.h"

//Base para alteração
void bfs(int matriz[MAX][MAX], int vertices, int origem)
{
    int visitado[MAX] = {0};
    int fila[MAX];

    int inicio = 0;
    int fim = 0;

    visitado[origem] = 1;
    fila[fim++] = origem;

    printf("\n=== SIMULACAO DE ENTREGA (BFS) ===\n");
    printf("Ordem de visita dos locais:\n");

    while (inicio < fim)
    {
        int atual = fila[inicio++];

        printf("%d ", atual);

        for (int i = 0; i < vertices; i++)
        {
            if (matriz[atual][i] != 0 && !visitado[i])
            {
                visitado[i] = 1;
                fila[fim++] = i;
            }
        }
    }

    printf("\n\nLocais alcancados:\n");

    for (int i = 0; i < vertices; i++)
    {
        if (visitado[i])
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}
