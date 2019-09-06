#include <stdio.h>
#include <stdlib.h>

void le_vetor(int *vetor, int tamanho)
    {
    int i;
    for (i = 0; i < tamanho; i++)
        {
        printf("Digite o %do elemento do vetor:", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int main()
    {
    int i, tamanho;
    int *vetor;
    printf("Digite o tamanho do vetor:");
    scanf("%d", &tamanho);
    vetor = malloc(tamanho * sizeof(int));
    le_vetor(vetor, tamanho);
    printf("Os valores colocados no vetor foram:\n");
    for (i = 0; i < tamanho; i++)
        {
        printf("%d\n", vetor[i]);
    }
    free(vetor);
    return 0;
}
