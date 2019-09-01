#include <stdio.h>
#include <stdlib.h>

void *pBuffer;

void preenche_string(char *pBuffer)
    {
    while ((*pBuffer = getchar()))
        {
        if (*pBuffer == '\n')
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
        pBuffer = malloc(sizeof(int) + sizeof(char));
        numero_de_pessoas = pBuffer;
        *numero_de_pessoas = 0;
        parada = pBuffer + sizeof(int);
        *parada = '\0';
    }
    else
        {
        int *numero_de_pessoas = pBuffer;
        pBuffer = realloc(pBuffer, sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char));
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

void imprime_agenda()
    {
    void *p;
    for (p = primeira_pessoa(); (*pega_nome(p)) != '\0'; p = proxima_pessoa(p))
        {
        printf("Nome: %s\n", pega_nome(p));
        printf("CPF: %s\n", pega_cpf(p));
    }
}

int main()
    {
    realoca_agenda(); /* Cria agenda vazia */
    cria_pessoa();
    imprime_agenda();
    cria_pessoa();
    imprime_agenda();
    free(pBuffer);
    return 0;
}
