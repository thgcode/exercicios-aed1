#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int linhas, int colunas)
    {
    int **matriz_das_linhas = malloc(sizeof(int *) * linhas);
    int i;
    for (i = 0; i < linhas; i++)
        {
        matriz_das_linhas[i] = malloc(sizeof(int) * colunas);
    }
    return matriz_das_linhas;
}

void libera_matriz(int **matriz, int linhas)
    {
    int i;
    for (i = 0; i < linhas; i++)
        {
        free(matriz[i]);
    }
}

int main()
    {
    int linhas, colunas, i, j;
    int **matriz;
    printf("Digite o valor das linhas:");
    scanf("%d", &linhas);
    printf("Digite o valor das colunas:");
    scanf("%d", &colunas);
    matriz = cria_matriz(linhas, colunas);
    for (i = 0; i < linhas; i++)
        {
        for (j = 0; j < colunas; j++)
            {
            printf("Digite o valor da linha %d coluna %d da matriz:", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Os valores colocados na matriz foram:\n");
    for (i = 0; i < linhas; i++)
        {
        for (j = 0; j < colunas; j++)
            {
            printf("Linha %d coluna %d: %d\n", i + 1, j + 1, matriz[i][j]);
        }
    }
    libera_matriz(matriz, linhas);
    return 0;
}
