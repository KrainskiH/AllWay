#include <stdio.h>
#include "grafo.h"

/*Inicializa a matriz com zero*/
void inicializarGrafo(Grafo *g, int vertices)
{
     int i;
     int j;
g->numVertices = vertices;
  for(i = 0; i < vertices; i++)
 {
 for(j = 0; j < vertices; j++)
{
g->matriz[i][j] = 0;
}
 }
}
/* Adiciona uma rota entre dois locais*/
void adicionarAresta(Grafo *g, int origem, int destino, int peso)
{
g->matriz[origem][destino] = peso;
}

/* Exibe a matriz de adjacência*/
void exibirMatriz(Grafo *g)
{
     int i;
 printf("\n MATRIZ DE ADJACENCIA\n\n");

printf("     ");
for (int i = 0; i < g->numVertices; i++) {
    printf("%4d", i);
}
printf("\n");

for (int i = 0; i < g->numVertices; i++) {
    printf("%4d", i);

    for (int j = 0; j < g->numVertices; j++) {
        printf("%4d", g->matriz[i][j]);
    }

    printf("\n");
}
}

int main()
{
 Grafo g;
 int quantidadeLocais;
 int opcao = 0;

 printf("SISTEMA DE PLANEJAMENTO DE ROTAS\n\n");
 printf("Informe a quantidade de locais: ");
 scanf("%d", &quantidadeLocais);

  while(quantidadeLocais <= 0 || quantidadeLocais > MAX)
{
 printf("Quantidade invalida.\n");
 printf("Digite um valor entre 1 e %d: ", MAX);
 scanf("%d", &quantidadeLocais);
}

 inicializarGrafo(&g, quantidadeLocais);
/* Menu principal*/
  do
 {
 printf("\n MENU \n");
printf("1 - Cadastrar rota\n");
printf("2 - Exibir rede\n");
printf("3 - Simular entrega (BFS)\n");
printf("4 - Calcular menor rota (Dijkstra)\n");
printf("5 - Sair\n");
printf("Opcao: ");
 scanf("%d", &opcao);

  switch(opcao)
  {
 case 1:
  {
  int origem;
  int destino;
  int distancia;

 printf("\nLocais disponiveis: 0 ate %d\n",g.numVertices - 1);

 printf("Origem: ");
 scanf("%d", &origem);

 printf("Destino: ");
 scanf("%d", &destino);

 printf("Distancia(km): ");
 scanf("%d", &distancia);

if(origem >= 0 &&
 origem < g.numVertices &&
 destino >= 0 &&
 destino < g.numVertices)
 {
adicionarAresta(
&g,
origem,
destino,
distancia
);
 printf("\nRota cadastrada com sucesso!\n");
 }
 else
{
 printf("\nVertices invalidos!\n");
}
break;
 }

  case 2:
{
exibirMatriz(&g);
break;
}

  case 3:
{
    int origem;

    printf("\nLocais disponiveis: 0 ate %d\n", g.numVertices - 1);
    printf("Digite o local de origem para iniciar a entrega: ");
    scanf("%d", &origem);

    if (origem >= 0 && origem < g.numVertices)
    {
        bfs(g.matriz, g.numVertices, origem);
    }
    else
    {
        printf("\nLocal de origem invalido!\n");
    }

    break;
}
   case 4:
{
    int origem;
    printf("\nLocais disponiveis: 0 ate %d\n", g.numVertices - 1);
    printf("Digite o local de origem: ");
    scanf("%d", &origem);

    if (origem >= 0 && origem < g.numVertices)
        dijkstra(g.matriz, g.numVertices, origem);
    else
        printf("\nLocal de origem invalido!\n");

    break;
}

case 5:
{
    printf("\nEncerrando sistema...\n");
    break;
}
default:
{
printf("\nOpcao invalida!\n");
}
  }
 } while(opcao != 5);

  return 0;
}
