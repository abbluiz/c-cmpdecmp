#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TadPilha.h"
#include "TadArvore.h"

/* --------------------------------------------------------  ESTRUTURA DA ÁRVORE -------------------------------------------------------- */

struct arv {
    unsigned char caractere;
    long int peso;
    int isChar;
    Arvore* esq;
    Arvore* dir;

};

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

Arvore* arv_criavazia() {

    return NULL;

}

Arvore* arv_cria(unsigned char caractere, long int peso, Arvore* r_esq, Arvore* r_dir) {

    Arvore* nova_arvore = (Arvore*) malloc(sizeof (Arvore));

    nova_arvore->caractere = caractere;
    nova_arvore->peso = peso;
    nova_arvore->isChar = 0;

    nova_arvore->dir = r_dir;
    nova_arvore->esq = r_esq;

    return nova_arvore;

}

void arv_imprime(Arvore* arvore) {

    printf("<");

    if (!arv_vazia(arvore)) {

        if (arvore->caractere >= 33 && arvore->caractere <= 126)
            printf("%c(%ld)", arvore->caractere, arvore->peso);
        else if (arvore->isChar == 0) {

            printf("no(%ld)", arvore->peso);

        } else {

            printf("c. %d(%ld)", (int) arvore->caractere, arvore->peso);

        }


        arv_imprime(arvore->esq);
        arv_imprime(arvore->dir);

    }

    printf(">");

}

void mudaisChar(Arvore* arvore, int isChar) {

    arvore->isChar = isChar;

}

void arv_libera(Arvore* arvore) {

    if (!arv_vazia(arvore)) {

        arv_libera(arvore->esq);
        arv_libera(arvore->dir);

        free(arvore);

    }

}

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */

int arv_vazia(Arvore* arvore) {

    return arvore == NULL;

}

int arvoreSemFilho(Arvore* arvore) {

    if (arvore->dir == NULL && arvore->esq == NULL)
        return 1;
    else
        return 0;

}

static int max2(int a, int b) {

    return (a > b) ? a : b;

}

int arv_altura(Arvore* arvore) {

    if (arv_vazia(arvore))
        return -1;
    else
        return 1 + max2(arv_altura(arvore->esq),
            arv_altura(arvore->dir));

}

/* ---------------------------------------------------------  FUNÇÕES DE RETORNO --------------------------------------------------------- */

Arvore* returnEsq(Arvore* arvore) {

    return arvore->esq;

}

Arvore* returnDir(Arvore* arvore) {

    return arvore->dir;

}

unsigned char returnChar(Arvore* arvore) {

    return arvore->caractere;

}

int returnPeso(Arvore* arvore) {

    return arvore->peso;

}

int returnisChar(Arvore* arvore) {

    return arvore->isChar;

}

/* ----------------------------------------------  COMPACTADOR E DESCOMPACTADOR ---------------------------------------------- */

int recCriaArvoreBit(Arvore* arvore) {

    int count = 0;

    if (!arv_vazia(arvore))
        count = 1 + recCriaArvoreBit(returnEsq(arvore)) + recCriaArvoreBit(returnDir(arvore));

    return count;

}

Pilha* cCriaArvoreBit(Arvore* arvoreHuff, int tamListaHuff) {

    long int tamArvoreBit = ((long int) tamListaHuff * 8) + (long int) recCriaArvoreBit(arvoreHuff);

    Pilha* arvBits = cria_pilha(tamArvoreBit + 2);

    cPreenchePilhaArvBits(arvBits, arvoreHuff);

    return arvBits;

}

void cPreenchePilhaArvBits(Pilha* arvBits, Arvore* arvoreHuff) {

    if (!arv_vazia(arvoreHuff)) {

        if (returnisChar(arvoreHuff) == 0)
            push('1', arvBits);
        else if (returnisChar(arvoreHuff) == 1) {

            push('0', arvBits);
            transformaCharBit(returnChar(arvoreHuff), arvBits);

        }

        cPreenchePilhaArvBits(arvBits, returnEsq(arvoreHuff));
        cPreenchePilhaArvBits(arvBits, returnDir(arvoreHuff));

    }

}

int dCriaArvoreHuff(Pilha* arvBits, Arvore* arvore, int pos, int flag, long int ocorrencias[]) {

    pos++;
    char arv = rtnCaracterPilha(arvBits, pos);
    int aux;

    if (arv == '1') {

        arvore->peso = 0;

        arvore->esq = arv_cria('a', -1, NULL, NULL);
        arvore->dir = arv_cria('a', -1, NULL, NULL);

        mudaisChar(arvore, 0);

        pos = dCriaArvoreHuff(arvBits, arvore->esq, pos, 0, ocorrencias);

        pos = dCriaArvoreHuff(arvBits, arvore->dir, pos, 0, ocorrencias);
        return pos;

    } else {

        pos++;
        char BintoChar[9];
        memset(BintoChar, '\0', sizeof (BintoChar));

        for (aux = 0, pos = pos; aux < 8; aux++, pos++) {

            BintoChar[aux] = rtnCaracterPilha(arvBits, pos);

        }

        pos--;

        unsigned char c = '\0';
        c = strtol(BintoChar, 0, 2);

        int caracter = c;

        ocorrencias[caracter] = 1;

        arvore->caractere = c;
        arvore->peso = 0;

        mudaisChar(arvore, 1);

        return pos;

    }


    return pos;

}