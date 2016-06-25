#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TadLista.h"
#include "TadArvore.h"
#include "TadBitmap.h"

/* ----------------------------------------------------------  ESTRUTURA DA LISTA ---------------------------------------------------------- */

struct tipoitem {
    Arvore* arvore;

};

typedef struct celulalista Celula;

struct celulalista {
    Item * item;
    Celula * ant;
    Celula * prox;

};

struct tipolista {
    Celula * Primeiro, * Ultimo;

};

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

Lista * InicializaLista() {

    Lista * lista = (Lista*) malloc(sizeof (Lista));

    lista->Primeiro = NULL;
    lista->Ultimo = NULL;

    return lista;

}

Item * InicializaItem(Arvore* arvore) {

    Item * novo_item = (Item*) malloc(sizeof (Item));

    novo_item->arvore = arvore;

    return novo_item;

}

void InsereCelula(Item* item, Lista* lista) {

    Celula * nova_celula = (Celula*) malloc(sizeof (Celula));

    if (lista->Primeiro == NULL) {

        lista->Primeiro = lista->Ultimo = nova_celula;
        lista->Primeiro->prox = NULL;
        lista->Primeiro->ant = NULL;
        lista->Ultimo->prox = NULL;
        lista->Ultimo->ant = NULL;

    } else {

        lista->Ultimo->prox = nova_celula;
        lista->Ultimo->prox->ant = lista->Ultimo;
        lista->Ultimo = lista->Ultimo->prox;
        lista->Ultimo->prox = NULL;

    }

    lista->Ultimo->item = item;

}

void LiberaLista(Lista* lista) {

    Celula* aux = lista->Primeiro;

    if (aux == NULL) {

        free(lista);
        return;

    }

    while (aux != lista->Ultimo) {

        aux = aux->prox;

        free(aux->ant->item->arvore);
        free(aux->ant->item);
        free(aux->ant);

    }

    free(aux->item->arvore);
    free(aux->item);
    free(aux);

    free(lista);

}

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */

long int tamanhoLista(Lista* lista) {

    long int count = 0;
    Celula* aux = lista->Primeiro;

    while (aux != NULL) {

        count++;

        aux = aux->prox;

    }

    return count;

}

static void LiberaCelulaMenosArvore(Celula* celula) {

    free(celula->item);
    free(celula);

}

/* --------------------------------------------------  F. DO ALGORITMO DE HUFFMAN -------------------------------------------------- */

Lista* CriaHuffman(long int ocorrencia[]) {

    int aux;

    Lista * nova_lista = InicializaLista();

    for (aux = 0; aux < 256; aux++) {

        if (ocorrencia[aux]) {

            unsigned char auxC = (unsigned char) aux;
            InsereArvHuffman(nova_lista, ocorrencia[aux], auxC);

        }

    }

    ImprimeLista(nova_lista);
    
    return nova_lista;

}

Arvore* CriaArvoreHuffman(Lista* listaHuff) {

    while (tamanhoLista(listaHuff) > 1) {

        long int somaPeso = returnPeso(listaHuff->Primeiro->item->arvore)
                + returnPeso(listaHuff->Primeiro->prox->item->arvore);

        Arvore* arvore = arv_cria(-1, somaPeso, listaHuff->Primeiro->item->arvore,
                listaHuff->Primeiro->prox->item->arvore);

        mudaisChar(arvore, 0);

        Item* item = InicializaItem(arvore);

        InsereCelula(item, listaHuff);

        OrdenaHuffman(listaHuff);

        atualizarHuffman(listaHuff);

    }

    Arvore* arvore = listaHuff->Primeiro->item->arvore;
    
    LiberaCelulaMenosArvore(listaHuff->Primeiro);
    free(listaHuff);
    
    mudaisChar(arvore, 0);
    
    return arvore;
    
}

void OrdenaHuffman(Lista* lista) {

    Celula* aux = lista->Primeiro;

    while (aux != NULL && lista->Primeiro != lista->Ultimo) {

        if (returnPeso(aux->item->arvore) >= returnPeso(lista->Ultimo->item->arvore)) {

            if (lista->Primeiro == aux) {

                Celula* bck = lista->Ultimo->ant;
                lista->Ultimo->prox = lista->Primeiro;

                lista->Ultimo->ant->prox = NULL;

                lista->Primeiro->ant = lista->Ultimo;

                Celula* aux2 = lista->Ultimo;

                lista->Primeiro = aux2;
                lista->Primeiro->ant = NULL;
                lista->Ultimo = bck;
                lista->Ultimo->prox = NULL;

                break;

            } else if (aux == lista->Ultimo) {

                break;

            } else {

                Celula* auxC = lista->Ultimo;
                Celula* bck = lista->Ultimo->ant;
                auxC->ant = aux->ant;
                auxC->prox = aux;

                aux->ant->prox = auxC;
                aux->ant = auxC;

                lista->Ultimo = bck;
                lista->Ultimo->prox = NULL;

                break;

            }

        }

        aux = aux->prox;

    }

}

void atualizarHuffman(Lista* listaHuff) {

    if (tamanhoLista(listaHuff) >= 3) {

        Celula* aux = listaHuff->Primeiro->prox->prox;
        listaHuff->Primeiro->prox->prox->ant = NULL;

        LiberaCelulaMenosArvore(listaHuff->Primeiro->prox);
        LiberaCelulaMenosArvore(listaHuff->Primeiro);

        listaHuff->Primeiro = aux;

    }

}

void ImprimeLista(Lista* lista) {

    Celula* aux = lista->Primeiro;

    printf("\nLISTA INICIAL DE HUFFMAN:\n\n");

    while (aux != NULL) {

        unsigned char c = returnChar(aux->item->arvore);
        long int i = returnPeso(aux->item->arvore);

        if (c >= 33 && c <= 126)
            printf("char: %c | Peso: %ld\n", c, i);
        else
            printf("(int)char: %d | Peso: %ld\n", (int) c, i);

        aux = aux->prox;

    }

    printf("Tamanho da lista: %ld\n\n", tamanhoLista(lista));

}

void InsereArvHuffman(Lista* lista, long int peso, unsigned char caracter) {

    Arvore* arvore = arv_cria(caracter, peso, NULL, NULL);

    if (arvoreSemFilho(arvore))
        mudaisChar(arvore, 1);

    Item* item = InicializaItem(arvore);

    InsereCelula(item, lista);

    OrdenaHuffman(lista);

}
