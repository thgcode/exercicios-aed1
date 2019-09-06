#include <stdio.h>
#include <stdlib.h>

struct conjunto
    {
    int *elementos;
    int tamanho;
};

struct conjunto *cria_conjunto()
    {
    struct conjunto *c = malloc(sizeof(struct conjunto));
    if (c != NULL)
        {
        c->tamanho = 0;
        c->elementos = malloc(sizeof(int));
        return c;
    }
    return NULL;
}

void libera(struct conjunto *c)
    {
    free(c->elementos);
    free(c);
}

int pertence(struct conjunto *c, int elemento)
    {
    int i;
    for (i = 0; i < c->tamanho; i++)
        {
        if (c->elementos[i] == elemento)
            {
            return 1;
        }
    }
    return 0;
}

void adiciona(struct conjunto *c, int elemento)
    {
    int tamanho;
    tamanho = c->tamanho + 1;
    if (!pertence(c, elemento))
        {
        if (tamanho > c->tamanho)
            {
            c->elementos = realloc(c->elementos, tamanho * sizeof(int));
        }
        c->tamanho = tamanho;
        c->elementos[tamanho - 1] = elemento;
    }
}

void apaga(struct conjunto *c, int elemento)
    {
    int i, j, removeu;;
    for (i = 0, removeu = 0; i < c->tamanho; i++)
        {
        if (c->elementos[i] == elemento)
            {
            for (j = i + 1; j < c->tamanho; j++, i++)
                {
                c->elementos[i] = c->elementos[j];
            }
            removeu = 1;
            break;
        }
    }
    if (removeu)
        {
        c->elementos = realloc(c->elementos, --(c->tamanho));
    }
}

struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2)
    {
    int i;
    struct conjunto *c;
    c = cria_conjunto();
    if (c == NULL)
        {
        return NULL;
    }
    for (i = 0; i < c1->tamanho; i++)
        {
        if (pertence(c2, c1->elementos[i]))
            {
            adiciona(c, c1->elementos[i]);
        }
    }
    return c;
}

struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2)
    {
    struct conjunto *c;
    int i;
    c = cria_conjunto();
    if (c == NULL)
        {
        return NULL;
    }
    for (i = 0; i < c1->tamanho; i++)
        {
        adiciona(c, c1->elementos[i]);
    }
    for (i = 0; i < c2->tamanho; i++)
        {
        adiciona(c, c2->elementos[i]);
    }
    return c;
}

struct conjunto *diferenca(struct conjunto *c1, struct conjunto *c2)
    {
    struct conjunto *c;
    int i;
    c = cria_conjunto();
    if (c == NULL)
        {
        return NULL;
    }
    for (i = 0; i < c1->tamanho; i++)
        {
        if (!pertence(c2, c1->elementos[i]))
            {
            adiciona(c, c1->elementos[i]);
        }
    }
    return c;
}

int vazio(struct conjunto *c)
    {
    return c->tamanho == 0;
}

int tamanho(struct conjunto *c)
    {
    return c->tamanho;
}

int igual(struct conjunto *c1, struct conjunto *c2)
    {
    int i;
    struct conjunto *d;
    if (c1->tamanho != c2->tamanho)
        {
        return 0;
    }
    d = diferenca(c1, c2);
    i = d->tamanho;
    free(d->elementos);
    free(d);
    return i == 0;
}

void imprime(struct conjunto *c)
    {
    int i;
    printf("{");
    for (i = 0; i < c->tamanho; i++)
        {
        printf("%d,", (int)c->elementos[i]);
    }
    printf("}\n");
}

int main()
    {
    struct conjunto *c, *c2, *d, *i, *u;
    c = cria_conjunto();
    adiciona(c, 1);
    adiciona(c, 2);
    adiciona(c, 3);
    imprime(c);
    c2 = cria_conjunto();
    adiciona(c2, 4);
    adiciona(c2, 5);
    adiciona(c2, 6);
    u = uniao(c, c2);
    imprime(u);
    i = intersecao(c, c2);
    printf("%d\n", vazio(i));
    imprime(i);
    libera(i);
    i = intersecao(c, c);
    imprime(i);
    d = diferenca(u, c);
    imprime(d);
    printf("%d %d\n", igual(c, c), igual(c, c2));
    printf("%d %d\n", tamanho(u), vazio(u));
    libera(d);
    libera(i);
    libera(u);
    libera(c2);
    libera(c);
    return 0;
}
