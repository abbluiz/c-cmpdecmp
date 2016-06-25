#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TadTabela.h"
#include "TadArvore.h"
#include "TadPilha.h"

/* --------------------------------------  ESTRUTURA DA LISTA DA TABELA DE HUFFMAN --------------------------------------- */

struct tipoitemtab {
    unsigned char caractere;
    Pilha* binario;

};

typedef struct celulalistatab CelulaTab;

struct celulalistatab {
    ItemTab * item;
    CelulaTab * ant;
    CelulaTab * prox;

};

struct tipolistatab {
    CelulaTab * Primeiro, * Ultimo;

};

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

ListaTab * InicializaListaTab() {

    ListaTab * lista = (ListaTab*) malloc(sizeof (ListaTab));

    lista->Primeiro = NULL;
    lista->Ultimo = NULL;

    return lista;

}

ItemTab * InicializaItemTab(unsigned char caractere, int tamArvHuff) {

    ItemTab * novo_item = (ItemTab*) malloc(sizeof (ItemTab));

    novo_item->caractere = caractere;
    novo_item->binario = cria_pilha(tamArvHuff + 2);

    return novo_item;

}

void InsereCelulaTab(ItemTab * item, ListaTab * lista) {

    CelulaTab * nova_celula = (CelulaTab*) malloc(sizeof (CelulaTab));

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

void ImprimeListaTab(ListaTab* lista) {

    CelulaTab* aux = lista->Primeiro;

    printf("--------------");
    printf("\nTABELA HUFFMAN:\n\n");

    while (aux != NULL) {

        if (aux->item->caractere >= 33 && aux->item->caractere <= 126)
            printf("%c: ", aux->item->caractere);
        else
            printf("(int)char %d: ", (int) aux->item->caractere);

        imprime_pilha(aux->item->binario);

        printf("\n");

        aux = aux->prox;

    }

}

void liberaTabelaHuff(ListaTab * listaTab) {

    CelulaTab* aux = listaTab->Primeiro;

    if (aux == NULL) {

        free(listaTab);
        return;

    }

    while (aux != listaTab->Ultimo) {

        aux = aux->prox;

        destroi_pilha(aux->ant->item->binario);
        free(aux->ant->item);
        free(aux->ant);

    }

    destroi_pilha(aux->item->binario);
    free(aux->item);
    free(aux);

    free(listaTab);

}

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */

long int tamanhoListaTab(ListaTab* lista) {

    long int count = 0;
    CelulaTab* aux = lista->Primeiro;

    while (aux != NULL) {

        count++;

        aux = aux->prox;

    }

    return count;

}

/* ------------------------------------------------------  F. DA TABELA DE HUFFMAN ------------------------------------------------------ */

ListaTab * criaTabelaHuff(ListaTab* listaTab, Arvore * arvoreHuff) {

    CelulaTab* aux = listaTab->Primeiro;

    while (aux != NULL) {

        getCodChar(arvoreHuff, aux->item->caractere, aux->item->binario, -1);

        aux = aux->prox;

    }

    return listaTab;

}

Pilha* procuraCharTab(unsigned char caractere, ListaTab * listaHuff) {

    CelulaTab* aux = listaHuff->Primeiro;

    while (aux != NULL) {

        if (aux->item->caractere == caractere)
            return aux->item->binario;

        aux = aux->prox;

    }

    return NULL;

}

int getCodChar(Arvore* arvore, unsigned char c, Pilha* pilha, int dir) {

    if (dir == 1)
        push('1', pilha);
    else if (dir == 0)
        push('0', pilha);

    if (arv_vazia(arvore)) {

        pop(pilha);
        return 0;

    }

    if (returnChar(arvore) == c && returnisChar(arvore) == 1) {

        return 1;

    }

    if (getCodChar(returnEsq(arvore), c, pilha, 1) || getCodChar(returnDir(arvore), c, pilha, 0)) {

        return 1;

    } else {

        pop(pilha);
        return 0;

    }

}

void cPreencheListaHuff(long int ocorrencias[], ListaTab* listaTabelaHuff, int tamArvHuff) {

    int aux;

    for (aux = 0; aux < 256; aux++) {

        if (ocorrencias[aux]) {

            ItemTab* nova_ocorrencia = InicializaItemTab((unsigned char) aux, tamArvHuff);

            InsereCelulaTab(nova_ocorrencia, listaTabelaHuff);

        }

    }

}