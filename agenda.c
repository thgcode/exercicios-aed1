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
    cpf = nome + (sizeof(char) * 100);
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
    char *inicio = pBuffer;
    inicio += sizeof(int);
    char *p;
    for (p = inicio; *p != '\0'; p += sizeof(char) * 200)
        {
        printf("Nome: %s\n", p);
        printf("CPF: %s\n", p + (sizeof(char) * 100 ));;
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
