#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TadPilha.h"

/* ----------------------------------------------------------  ESTRUTURA DA PILHA ---------------------------------------------------------- */

struct pilha {
    char* binario;
    int maxtam;
    int topo;

};

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

Pilha* cria_pilha(int tamArvHuff) {

    Pilha* nova_pilha = (Pilha*) malloc(sizeof (Pilha)+1);
    char* seq_bits = (char*) malloc(sizeof (char) * tamArvHuff);

    nova_pilha->topo = 0;
    nova_pilha->binario = seq_bits;
    nova_pilha->maxtam = tamArvHuff;

    return nova_pilha;

}

void push(char bit, Pilha* pilha) {

    if (pilha == NULL) {

        printf("Pilha não inicializada.\n");
        return;

    }

    if (tamanho_pilha(pilha) == (pilha->maxtam)) {

        printf("Pilha cheia!");
        return;

    }

    pilha->binario[pilha->topo] = bit;

    pilha->topo++;

}

char pop(Pilha* pilha) {

    char binario_retirado = '\0';

    if (pilha == NULL) {

        printf("Pilha não inicializada.\n");
        return binario_retirado;

    }

    if (vazia_pilha(pilha)) {

        printf("Pilha vazia.\n");
        return binario_retirado;

    }

    binario_retirado = pilha->binario[pilha->topo];

    pilha->topo--;

    return binario_retirado;

}

void imprime_pilha(Pilha* pilha) {

    int aux = 0;

    for (aux = 0; aux < pilha->topo; aux++) {

        printf("%c", pilha->binario[aux]);

    }

}

Pilha* destroi_pilha(Pilha* pilha) {

    free(pilha->binario);

    pilha->topo = 0;
    free(pilha);

    Pilha* pilha_null = NULL;

    return pilha_null;

}

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */

int vazia_pilha(Pilha* pilha) {


    if (pilha->topo == 0)
        return 1;
    else
        return 0;

}

int tamanho_pilha(Pilha* pilha) {

    return pilha->topo;

}

void transformaCharBit(unsigned char caractere, Pilha* pilha) {

    int i;
    for (i = 0; i < 8; i++) {

        int bit = !!(((char) caractere << i) & 0x80);

        bit = bit + 48;

        char bitC = (char) bit;

        push(bitC, pilha);

    }
    
}

void alteraTopo(Pilha* pilha, int topo) {

    pilha->topo = topo;

}

/* ---------------------------------------------------------  FUNÇÕES DE RETORNO --------------------------------------------------------- */

char rtnCaracterPilha(Pilha* pilha, int n) {

    return pilha->binario[n];

}

int rtnTopoPilha(Pilha* pilha) {

    return pilha->topo;

}

int rtnMaxTamPilha(Pilha* pilha) {

    return pilha->maxtam;

}