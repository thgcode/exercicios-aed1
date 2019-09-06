#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2)
    {
    int i, c;
    int *vetor_uniao;
    int tamanho_uniao = n1 + n2;
    if (tamanho_uniao > 0)
        {
        vetor_uniao = malloc(sizeof(int) * tamanho_uniao);
        for (i = 0, c = 0; i < n1; i++)
            {
            vetor_uniao[c] = v1[i];
            c ++;
        }
        for (i = 0; i < n2; i++)
            {
            vetor_uniao[c] = v2[i];
            c ++;
        }
        return vetor_uniao;
    }
    else
        {
        return NULL;
    }
}

int main()
    {
    int *vetor1, *vetor2, *vetor_uniao, tamanho1, tamanho2, tamanho_uniao, i;
    printf("Digite o tamanho do primeiro vetor:");
    scanf("%d", &tamanho1);
    vetor1 = malloc(sizeof(int) * tamanho1);
    for (i = 0; i < tamanho1; i++)
        {
        printf("Digite o %do item do primeiro vetor:", i + 1);
        scanf("%d", &vetor1[i]);
    }
    printf("Digite o tamanho do segundo vetor:");
    scanf("%d", &tamanho2);
    vetor2 = malloc(sizeof(int) * tamanho2);
    for (i = 0; i < tamanho2; i++)
        {
        printf("Digite o %do item do segundo vetor:", i + 1);
        scanf("%d", &vetor2[i]);
    }
    vetor_uniao = uniao(vetor1, tamanho1, vetor2, tamanho2);
    if (vetor_uniao != NULL)
        {
        tamanho_uniao = tamanho1 + tamanho2;
        printf("O vetor uniao ficou:\n");
        for (i = 0; i < tamanho_uniao; i++)
            {
            printf("%d\n", vetor_uniao[i]);
        }
        free(vetor_uniao);
    }
    free(vetor1);
    free(vetor2);
    return 0;
}
