#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa
    {
    char *nome;
    char *telefone;
};

struct pessoa *agenda;
int numero_de_pessoas;

char *le_e_aloca_string()
    {
    char s[101];
    char *string_certa;
    char c;
    int i, j;
    i = 0;
    do
        {
        c = getchar();
        s[i] = c;
        i ++;
    }
    while (c != '\n' && i < 101);
    s[i] = '\0';
    string_certa = malloc(i * sizeof(char));
    for (j = 0; j < i; j++)
        {
        string_certa[j] = s[j];
    }
    i --; /* sobrescreve o último caractere da string (provavelmente o \n) com \0 */
    string_certa[i] = '\0';
    return string_certa;
}

int preenche_pessoa(int numero_da_pessoa)
    {
    printf("Digite o nome da pessoa:");
    agenda[numero_da_pessoa].nome = le_e_aloca_string();
    printf("Digite o telefone da pessoa:");
    agenda[numero_da_pessoa].telefone = le_e_aloca_string();
    if (agenda[numero_da_pessoa].nome == NULL ||
            agenda[numero_da_pessoa].telefone == NULL || agenda[numero_da_pessoa].nome[0] == '\0' ||
            agenda[numero_da_pessoa].telefone[0] == '\0')
        {
        printf("O nome e o telefone da pessoa devem estar preenchidos.\n");
        return 0;
    }
    else
        {
        return 1;
    }
}

void libera_tudo()
    {
    int i;
    for (i = 0; i < numero_de_pessoas; i++)
        {
        free(agenda[i].nome);
        free(agenda[i].telefone);
    }
    free(agenda);
    agenda = NULL;
}

void atualiza_agenda(int tamanho)
    {
    if (numero_de_pessoas > 0)
        {
        agenda = realloc(agenda, tamanho * sizeof(struct pessoa));
    }
    else if (tamanho == 0)
        {
        libera_tudo();
    }
    else
        {
        agenda = malloc(tamanho * sizeof(struct pessoa));
    }
}

void insere_na_agenda()
    {
    atualiza_agenda(numero_de_pessoas + 1);
    if (preenche_pessoa(numero_de_pessoas))
        {
        numero_de_pessoas ++;
        printf("Pessoa %d adicionada.\n", numero_de_pessoas);
    }
    else
        {
        atualiza_agenda(numero_de_pessoas);
    }
}

int procura_pessoa(char *nome)
    {
    int i;
    for (i = 0; i < numero_de_pessoas; i++)
        {
        if (strcmp(agenda[i].nome, nome) == 0)
            {
            return i;
        }
    }
    return -1;
}

void remove_da_agenda()
    {
    char s[101];
    char c;
    int i, p;
    printf("Qual o nome da pessoa para remover?\n");
    i = 0;
    do
        {
        c = getchar();
        s[i] = c;
        i ++;
    }
    while (c != '\n' && i < 101);
    i --;
    s[i] = '\0';
    p = procura_pessoa(s);
    if (p != -1)
        {
        free(agenda[p].nome);
        free(agenda[p].telefone);
        for (i = p; i < numero_de_pessoas - 1; i++)
            {
            agenda[i] = agenda[i + 1];
        }
        numero_de_pessoas --;
        atualiza_agenda(numero_de_pessoas);
        printf("Pessoa %d removida.\n", p + 1);
    }
    else
        {
        printf("Pessoa %s nao encontrada.\n", s);
    }
}

void imprime_a_agenda()
    {
    int i;
    for (i = 0; i < numero_de_pessoas; i++)
        {
        printf("Pessoa %d:\nNome: %s\nTelefone: %s\n", i + 1,
            agenda[i].nome, agenda[i].telefone);
    }
}

int main()
    {
    int opcao;
    agenda = NULL;
    numero_de_pessoas = 0;
    do
        {
        printf("Menu da agenda\n");
        printf("1. Adicionar uma pessoa\n");
        printf("2. Remover uma pessoa\n");
        printf("3. Imprimir todas as pessoas\n");
        printf("4. Sair:");
        scanf("%d", &opcao);
        while (getchar() != '\n'); /* Ignora tudo que a pessoa digitar que não seja o número */
        switch (opcao)
            {
            case 1:
                insere_na_agenda();
                break;
            case 2:
                remove_da_agenda();
                break;
            case 3:
                imprime_a_agenda();
            break;
        }
    }
    while (opcao != 4);
    return 0;
}
