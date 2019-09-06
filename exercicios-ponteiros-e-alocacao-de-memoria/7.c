#include <stdio.h>
#include <stdlib.h>

int conta_valores_no_intervalo(int *vetor, int tamanho, int min, int max)
    {
    int i, conta;;
    for (i = 0, conta = 0; i < tamanho; i++)
        {
        if (vetor[i] > min && vetor[i] < max)
            {
            conta ++;
        }
    }
    return conta;
}

int* valores_entre(int *v, int n, int min, int max, int *qtd)
    {
    int *valores, i, c;
    *qtd = conta_valores_no_intervalo(v, n, min, max);
    if (*qtd > 0)
        {
        valores = malloc(sizeof(int) * *qtd);
        for (i = 0, c = 0; i < n; i++)
            {
            if (v[i] > min && v[i] < max)
                {
                valores[c] = v[i];
                c++;
            }
        }
        return valores;
    }
    else
        {
        return NULL;
    }
}

int main()
    {
    int *vetor, *vetor_copiado, i, min, max, tamanho, quantos_copiou;
    printf("Digite o tamanho do vetor:");
    scanf("%d", &tamanho);
    vetor = malloc(sizeof(int) * tamanho);
    for (i = 0; i < tamanho; i++)
        {
        printf("Digite o %do valor do vetor:", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("Digite o valor minimo para copiar:");
    scanf("%d", &min);
    printf("Digite o valor maximo para copiar:");
    scanf("%d", &max);
    vetor_copiado = valores_entre(vetor, tamanho, min, max, &quantos_copiou);
    if (vetor_copiado != NULL)
        {
        printf("Valores no intervalo de %d a %d:\n", min, max);
        for (i = 0; i < quantos_copiou; i++)
            {
            printf("%d\n", vetor_copiado[i]);
        }
        free(vetor_copiado);
    }
    else
        {
        printf("Nao tem nenhum valor no intervalo.\n");
    }
    free(vetor);
    return 0;
}
