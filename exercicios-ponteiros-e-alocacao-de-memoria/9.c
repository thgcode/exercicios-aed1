#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void le_aposta(int *aposta, int tamanho)
    {
    int i;
    for (i = 0; i < tamanho; i++)
        {
        do
            {
            printf("Digite o numero %d da aposta (entre 0 e 100):", i + 1);
            scanf("%d", &aposta[i]);
        }
        while (aposta[i] < 0 || aposta[i] > 100);
    }
}

void sorteia_valores(int *sorteio, int tamanho)
    {
    int i;
    for (i = 0; i < tamanho; i++)
        {
        sorteio[i] = rand() % 100;
    }
}

int *compara_valores(int *aposta, int *sorteio, int *quantos_acertou, int tamanho_aposta, int tamanho_sorteio)
    {
    int i, j, k;
    int *acertou = malloc(sizeof(int) * tamanho_sorteio);
    k = 0;
    for (i = 0; i < tamanho_sorteio; i++)
        {
        for (j = 0; j < tamanho_aposta; j++)
            {
            if (sorteio[i] == aposta[j])
                {
                acertou[k] = sorteio[i];
                k ++;
            }
        }
    }
    *quantos_acertou = k;
    return acertou;
}

int main()
    {
    int *aposta, *sorteio, *acertou, quantos_aposta, quantos_acertou, i;
    printf("Quantos numeros voce quer apostar?");
    scanf("%d", &quantos_aposta);
    if (quantos_aposta > 0)
        {
        srand(time(NULL));
        aposta = malloc(sizeof(int) * quantos_aposta);
        le_aposta(aposta, quantos_aposta);
        sorteio = malloc(sizeof(int) * 20);
        sorteia_valores(sorteio, 20);
        acertou = compara_valores(aposta, sorteio, &quantos_acertou,
quantos_aposta, 20);
        if (quantos_acertou > 0)
            {
            printf("Voce acertou os seguintes numeros:\n");
            for (i = 0; i < quantos_acertou; i++)
                {
                printf("%d\n", acertou[i]);
            }
            free(acertou);
        }
        else
            {
            printf("Voce nao acertou nenhum numero.\n");
        }
        free(aposta);
        free(sorteio);
    }
    return 0;
}
