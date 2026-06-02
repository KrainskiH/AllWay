#ifndef GRAFO_H
#define GRAFO_H

#define MAX 20
#define INF 99999

typedef struct {
    int numVertices;
    int matriz[MAX][MAX];
} Grafo;

void inicializarGrafo(Grafo *g, int vertices);
void adicionarAresta(Grafo *g, int origem, int destino, int peso);
void exibirMatriz(Grafo *g);
void bfs(int matriz[MAX][MAX], int vertices, int origem);
void dijkstra(int matriz[MAX][MAX], int vertices, int origem);

#endif