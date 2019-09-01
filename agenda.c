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
        pBuffer = malloc(sizeof(int) + sizeof(char) + sizeof(int));
        numero_de_pessoas = pBuffer;
        *numero_de_pessoas = 0;
        parada = pBuffer + sizeof(int);
        *parada = '\0';
    }
    else
        {
        int *numero_de_pessoas = pBuffer;
        pBuffer = realloc(pBuffer, sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char) + sizeof(int));
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

int *pega_var_menu()
    {
    int *numero_de_pessoas = pBuffer;
    return pBuffer + sizeof(int) + ((sizeof(char) * 200) * *numero_de_pessoas) + sizeof(char);
}

int main()
    {
    int *opcao;
    realoca_agenda(); /* Cria agenda vazia */
    opcao = pega_var_menu();
    while (*opcao != 3)
        {
        printf("Menu da agenda:\n");
        printf("1. Adicionar uma pessoa\n");
        printf("2. Imprimir a lista de pessoas\n");
        printf("3. Sair:\n");
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
        }
    }
    free(pBuffer);
    return 0;
}
