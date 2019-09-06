#include <stdio.h>
#include <stdlib.h>

int *cria_vetor(int tamanho)
    {
        return malloc(tamanho * sizeof(int));
}

void le_vetor(int *vetor, int tamanho)
    {
    int i;
    for (i = 0; i < tamanho; i++)
        {
        printf("Digite o %do elemento do vetor:", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void imprime_vetor(int *vetor, int tamanho)
    {
    int i;
    for (i = 0; i < tamanho; i++)
        {
        printf("%d\n", vetor[i]);
    }
}

void libera_vetor(int *vetor)
    {
    free(vetor);
}

int main()
    {
    int n;
    int *vetor;
    printf("Digite o valor de n:");
    scanf("%d", &n);
    vetor = cria_vetor(n);
    le_vetor(vetor, n);
    printf("Os valores colocados no vetor foram:\n");
    imprime_vetor(vetor, n);
    libera_vetor(vetor);
    return 0;
}
