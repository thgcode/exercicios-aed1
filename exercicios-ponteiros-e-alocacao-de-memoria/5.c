#include <stdio.h>
#include <stdlib.h>

struct pessoa
    {
    char nome[100];
    char nascimento[20];
    char cpf[20];
};

void le_string(char *string, int tamanho)
    {
    char c;
    int i;
    i = 0;
    while ((c = getchar()) != '\n' && i < tamanho)
        {
        string[i] = c;
        i ++;
    }
    string[i] = '\0';
}

int preenche_pessoa(struct pessoa *p)
    {
    printf("Digite o nome da pessoa:");
    le_string(p->nome, 100);
    printf("Digite a data de nascimento da pessoa:");
    le_string(p->nascimento, 20);
    printf("Digite o CPF da pessoa:");
    le_string(p->cpf, 20);
    if (p->nome[0] != '\0' && p->cpf[0] != '\0' && p->nascimento[0] != '\0')
        {
        return 1;
    }
    else
        {
        return 0;
    }
}

void imprime_pessoa(struct pessoa *p)
    {
    printf("Nome da pessoa: %s\n", p->nome);
    printf("Data de nascimento: %s\n", p->nascimento);
    printf("CPF: %s\n", p->cpf);
}

int main()
    {
    struct pessoa *p = malloc(sizeof(struct pessoa));
    if (preenche_pessoa(p))
        {
        imprime_pessoa(p);
    }
    free(p);
    return 0;
}
