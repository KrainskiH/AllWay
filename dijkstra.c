#include <stdio.h>
#include "grafo.h"

void dijkstra(int matriz[MAX][MAX], int vertices, int origem)
{
    int dist[MAX];
    int visitado[MAX];
    int anterior[MAX];
    int i, count, v;

    for (i = 0; i < vertices; i++) {
        dist[i] = INF;
        visitado[i] = 0;
        anterior[i] = -1;
    }
    dist[origem] = 0;

    for (count = 0; count < vertices; count++) {
        int u = -1;
        for (i = 0; i < vertices; i++) {
            if (!visitado[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INF)
            break;

        visitado[u] = 1;

        for (v = 0; v < vertices; v++) {
            if (matriz[u][v] != 0 && !visitado[v]) {
                int novaDist = dist[u] + matriz[u][v];
                if (novaDist < dist[v]) {
                    dist[v] = novaDist;
                    anterior[v] = u;
                }
            }
        }
    }

    printf("\n === CALCULO DE MENOR ROTA (DIJKSTRA) ===\n");
    printf("Origem: Local %d\n\n", origem);
    printf("%-10s %-12s %s\n", "Destino", "Distancia", "Caminho");
    printf("----------------------------------------------\n");

    for (i = 0; i < vertices; i++) {
        if (i == origem) continue;

        printf("Local %-4d ", i);

        if (dist[i] == INF) {
            printf("%-12s %s\n", "INACESSIVEL", "-");
            continue;
        }

        printf("%-12d ", dist[i]);

        int caminho[MAX];
        int tam = 0;
        int atual = i;

        while (atual != -1) {
            caminho[tam++] = atual;
            atual = anterior[atual];
        }

        for (int j = tam - 1; j >= 0; j--) {
            printf("%d", caminho[j]);
            if (j > 0) printf(" -> ");
        }
        printf("\n");
    }
    printf("\n");
}