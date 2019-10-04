#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer;

int *pega_var_menu()
    {
    int *numero_de_pessoas = pBuffer;
    return pBuffer + sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char);
}

void preenche_string(char *pBuffer)
    {
    int *i = pega_var_menu();
    *i = 0;
    while ((*pBuffer = getchar()))
        {
        (*i)++;
        if (*pBuffer == '\n' || *i >= 100)
            {
            *pBuffer = '\0';
            break;
        }
        else
            {
            pBuffer ++;
        }
    }
}

void realoca_agenda()
    {
    char *parada;
    int *numero_de_pessoas;
    if (pBuffer == NULL)
        {
        pBuffer = malloc(sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char) * 100 + sizeof(char) *
200);
        numero_de_pessoas = pBuffer;
        *numero_de_pessoas = 0;
        parada = pBuffer + sizeof(int);
        *parada = '\0';
    }
    else
        {
        int *numero_de_pessoas = pBuffer;
        pBuffer = realloc(pBuffer, sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char) + sizeof(int) + sizeof(char) * 100 + sizeof(char) * 200);
        numero_de_pessoas = pBuffer;
        parada = pBuffer + sizeof(int) + (sizeof(char) * 200 * *numero_de_pessoas);
        *parada = '\0';
    }
}

    char *pega_nome(void *pessoa)
    {
    return pessoa;
}

char *pega_cpf(void *pessoa)
    {
    return pessoa + sizeof(char) * 100;
}

void *primeira_pessoa()
    {
    return pBuffer + sizeof(int);
}

void *pessoa_anterior(void *pessoa)
    {
    return pessoa - sizeof(char) * 200;
}

void *proxima_pessoa(void *pessoa)
    {
    return pessoa + sizeof(char) * 200;
}

void cria_pessoa()
    {
    int *numero_de_pessoas = pBuffer;
    char *nome, *cpf;
    (*numero_de_pessoas) ++;
    realoca_agenda();
    numero_de_pessoas = pBuffer;
    nome = pBuffer + sizeof(int) + ((*numero_de_pessoas - 1) * sizeof(char) * 200);
    printf("Digite o nome da pessoa:");
    preenche_string(nome);
    cpf = pega_cpf(nome);
    printf("Digite o CPF da pessoa:");
    preenche_string(cpf);
    if (*nome == '\0' || *cpf == '\0')
        {
        (*numero_de_pessoas) --;
        realoca_agenda();
    }
}

void imprime_pessoa(void *pessoa)
    {
    printf("Nome: %s\n", pega_nome(pessoa));
    printf("CPF: %s\n", pega_cpf(pessoa));
}

void imprime_agenda()
    {
    void *p;
    for (p = primeira_pessoa(); (*pega_nome(p)) != '\0'; p = proxima_pessoa(p))
        {
        imprime_pessoa(p);
    }
}

    char *pega_area_pra_digitar()
    {
    int *numero_de_pessoas = pBuffer;
    return pBuffer + sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char) + sizeof(int);
}

    void *pega_area_de_troca()
    {
    int *numero_de_pessoas = pBuffer;
    return pBuffer + sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char) + sizeof(int) + sizeof(char) * 100;
}
void *procura_pessoa()
    {
    char *nome = pega_area_pra_digitar();
    void *p;
    printf("Qual o nome da pessoa?");
    preenche_string(nome);
    for (p = primeira_pessoa(); *(pega_nome(p)) != '\0'; p = proxima_pessoa(p))
        {
        if (!strcmp(pega_nome(p), nome))
            {
            return p;
        }
    }
    return NULL;
}

void procura_pessoa_e_imprime()
    {
    void *p = procura_pessoa();
    if (p != NULL)
        {
        imprime_pessoa(p);
    }
    else
        {
        printf("Pessoa nao encontrada.\n");
    }
}

void apaga_pessoa()
    {
    void *p = procura_pessoa();
    void *proxima;
    int *numero_de_pessoas;
    if (p != NULL)
        {
        for (proxima = proxima_pessoa(p); (*pega_nome(proxima)) != '\0'; p = proxima, proxima = proxima_pessoa(proxima))
            {
            strcpy(pega_nome(p), pega_nome(proxima));
            strcpy(pega_cpf(p), pega_cpf(proxima));
        }
        numero_de_pessoas = pBuffer;
        (*numero_de_pessoas)--;
        realoca_agenda();
        printf("Pessoa apagada.\n");
    }
    else
        {
        printf("Pessoa nao encontrada.\n");
    }
}

void troca_pessoa(void *primeira, void *segunda)
    {
        if (primeira != segunda)
        {
        strcpy(pega_area_pra_digitar(), pega_nome(primeira));
        strcpy(pega_nome(primeira), pega_nome(segunda));
        strcpy(pega_nome(segunda), pega_area_pra_digitar());
        strcpy(pega_area_pra_digitar(), pega_cpf(primeira));
        strcpy(pega_cpf(primeira), pega_cpf(segunda));
        strcpy(pega_area_pra_digitar(), pega_cpf(segunda));
        *pega_area_pra_digitar() = '\0';
    }
}

void ordena_por_selecao()
    {
    void *i, *j, *menor;
    for (i = primeira_pessoa(); (*pega_nome(i) != '\0'); i = proxima_pessoa(i))
        {
        menor = i;
        for (j = proxima_pessoa(i); (*pega_nome(j) != '\0'); j = proxima_pessoa(j))
            {
            if (strcmp(pega_nome(i), pega_nome(j)) > 0)
                {
                menor = j;
            }
        }
        troca_pessoa(i, menor);
    }
}

void ordena_por_insercao()
    {
    void *i, *j, *tmp;
    for (j = proxima_pessoa(primeira_pessoa()); (*pega_nome(j) != '\0'); j = proxima_pessoa(j))
        {
        i = pessoa_anterior(j);
        tmp = pega_area_de_troca();
        strcpy(tmp, pega_nome(j));
        strcpy(tmp + sizeof(char) * 100, pega_cpf(j));
        while (i >= primeira_pessoa() && strcmp(pega_nome(i), pega_nome(tmp)) > 0)
            {
            strcpy(pega_nome(proxima_pessoa(i)), pega_nome(i));
            strcpy(pega_cpf(proxima_pessoa(i)), pega_cpf(i));
            i = pessoa_anterior(i);
        }
        strcpy(proxima_pessoa(i), tmp); /* Copia o nome */
        strcpy(proxima_pessoa(i) + sizeof(char) * 100, tmp + sizeof(char) * 100); /* Copia o CPF */
    }
}

void ordena_por_bolha()
    {
    void *i, *j;
    for (i = primeira_pessoa(); (*pega_nome(i) != '\0'); i = proxima_pessoa(i))
        {
        for (j = proxima_pessoa(i); (*pega_nome(j) != '\0'); j = proxima_pessoa(j))
            {
            if (strcmp(pega_nome(i), pega_nome(j)) > 0)
                {
                troca_pessoa(i, j);
            }
        }
    }
}

void ordena_por_quicksort(void *inicio, void *fim)
    {
    void *pivo, *i, *j;
    i = inicio;
    j = fim;
    pivo = pega_area_de_troca();
    strcpy(pega_area_de_troca(), pega_nome(inicio));
    do
        {
        while (strcmp(pega_nome(i), pivo) < 0)
            {
            i = proxima_pessoa(i);
        }
        while(strcmp(pega_nome(j), pivo) > 0)
            {
            j = pessoa_anterior(j);
        }
        if (i <= j)
            {
            troca_pessoa(i, j);
            i = proxima_pessoa(i);
            j = pessoa_anterior(j);
        }
    }
    while (i <= j);
    if (inicio < j)
        {
        ordena_por_quicksort(inicio, j);
    }
    if (i < fim)
        {
        ordena_por_quicksort(i, fim);
    }
}

int main()
    {
    int *opcao, *numero_de_pessoas;
    realoca_agenda(); /* Cria agenda vazia */
    numero_de_pessoas = pBuffer;
    opcao = pega_var_menu();
    while (*opcao != 9 || *numero_de_pessoas != -1)
        {
        printf("Menu da agenda:\n");
        printf("1. Adicionar uma pessoa\n");
        printf("2. Imprimir a lista de pessoas\n");
    printf("3. Procurar uma pessoa\n");
    printf("4. Apagar uma pessoa\n");
    printf("5. Ordenar por selecao\n");
        printf("6. Ordenar por insercao\n");
        printf("7. Ordenar por bolha\n");
        printf("8. Ordenar por quicksort\n");
        printf("9. Sair:\n");
        scanf("%d", opcao);
        while (getchar() != '\n');
        switch (*opcao)
            {
            case 1:
                cria_pessoa();
                opcao = pega_var_menu();
                numero_de_pessoas = pBuffer;
                break;
            case 2:
                imprime_agenda();
                break;
            case 3:
                procura_pessoa_e_imprime();
                break;
            case 4:
                apaga_pessoa();
                opcao = pega_var_menu();
                numero_de_pessoas = pBuffer;
                break;
            case 5:
                ordena_por_selecao();
                break;
            case 6:
                ordena_por_insercao();
                break;
            case 7:
                ordena_por_bolha();
                break;
            case 8:
                ordena_por_quicksort(primeira_pessoa(), primeira_pessoa() + (sizeof(char) * 200 * (*numero_de_pessoas - 1)));
                break;
            case 9:
                *numero_de_pessoas = -1;
                break;
        }
    }
    free(pBuffer);
    return 0;
}
