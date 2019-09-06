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
        pBuffer = malloc(sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char) * 100);
        numero_de_pessoas = pBuffer;
        *numero_de_pessoas = 0;
        parada = pBuffer + sizeof(int);
        *parada = '\0';
    }
    else
        {
        int *numero_de_pessoas = pBuffer;
        pBuffer = realloc(pBuffer, sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char) + sizeof(int) + sizeof(char) * 100);
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

void imprime_pessoa(void *p)
    {
    printf("Nome: %s\n", pega_nome(p));
    printf("CPF: %s\n", pega_cpf(p));
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

int main()
    {
    int *opcao;
    realoca_agenda(); /* Cria agenda vazia */
    opcao = pega_var_menu();
    while (*opcao != 4)
        {
        printf("Menu da agenda:\n");
        printf("1. Adicionar uma pessoa\n");
        printf("2. Imprimir a lista de pessoas\n");
    printf("3. Procurar uma pessoa\n");
        printf("4. Sair:\n");
        scanf("%d", opcao);
        while (getchar() != '\n');
        switch (*opcao)
            {
            case 1:
                cria_pessoa();
                opcao = pega_var_menu();
                break;
            case 2:
                imprime_agenda();
                break;
            case 3:
                procura_pessoa_e_imprime();
                break;
        }
    }
    free(pBuffer);
    return 0;
}
