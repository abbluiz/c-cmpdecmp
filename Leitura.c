#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Leitura.h"
#include "TadTabela.h"
#include "TadPilha.h"

int VerificaErrosLeitura(FILE* arquivo) {

    if (!arquivo) {

        printf("\n\n\t> Erro ao abrir arquivo de entrada!\n\n");
        return 1;

    }

    return 0;

}

void PegaNomeDoArquivo(char caminho[], char nomeArq[]) {

    int tamCam = strlen(caminho), aux, aux2, aux3, temBarra = 0;

    for (aux = tamCam; aux >= 0; aux--) {

        if (caminho[aux] == '/') {

            temBarra = 1;
            break;

        }

    }

    if (temBarra == 0) {

        for (aux = 0; aux < tamCam + 1; aux++)
            nomeArq[aux] = caminho[aux];

        return;

    } else if (temBarra == 1) {

        for (aux2 = aux + 1, aux3 = 0; aux2 < tamCam + 1; aux2++, aux3++)
            nomeArq[aux3] = caminho[aux2];

        return;

    }

}

/* ---------------------------------------------------------------  COMPACTAÇÃO --------------------------------------------------------------- */

void cLeituraOcorrencias(FILE* arquivo, long int ocorrencias[]) {

    unsigned char caractere;

    memset(ocorrencias, 0, 256 * sizeof (long int));

    while (fscanf(arquivo, "%c", &caractere) != EOF) {

        int ascii;

        ascii = (int) caractere;

        ocorrencias[ascii]++;

    }

}

long int cCalculaQntdBitsArquivo(long int ocorrencias[], ListaTab* listaHuff) {

    long int count = 0, aux;

    for (aux = 0; aux < 256; aux++) {

        long long int calc = 0;

        if (ocorrencias[aux]) {

            Pilha* auxP = procuraCharTab((unsigned char) aux, listaHuff);

            calc = ocorrencias[aux] * (long long int) tamanho_pilha(auxP);

            count = count + calc;

        }

    }

    return count;

}

/* ------------------------------------------------------------  DESCOMPACTAÇÃO ------------------------------------------------------------ */

int dRetornaTamanhoNomeArquivo(FILE* compactado) {

    int tamanho;

    fscanf(compactado, "%d", &tamanho);

    return tamanho;

}

FILE* dRetornaNomeDescmp(int tamNomeArq, FILE* descompactar) {

    if (tamNomeArq) {
        char nomeArq[tamNomeArq + 1];

        dRecriaNomeArquivo(descompactar, nomeArq, tamNomeArq);

        char nomeDescmp[tamNomeArq + 7];

        nomeDescmp[0] = '\0';

        strcat(nomeDescmp, "[dscmp]");
        strcat(nomeDescmp, nomeArq);

        FILE* descompactado = fopen(nomeDescmp, "wb");

        return descompactado;

    } else {

        FILE* descompactado = fopen("descmp", "wb");
        return descompactado;
    }


}

void dRecriaNomeArquivo(FILE* compactado, char nomeArq[], int tam) {

    if (tam == 0)
        return;
    else {

        int aux;

        for (aux = 0; aux < tam; aux++) {

            fscanf(compactado, "%c", &nomeArq[aux]);

        }

        nomeArq[tam] = '\0';

    }

}

int dRetornaTamanhoArvoreBits(FILE* compactado) {

    int tamArvBits;

    fscanf(compactado, "%d", &tamArvBits);

    return tamArvBits;

}

Pilha* dArvoreBits(FILE* compactado, int tamArvBits) {

    int tamb, aux;

    if (tamArvBits % 8 == 0)
        tamb = tamArvBits / 8;
    else
        tamb = tamArvBits / 8 + 1;

    Pilha* pilha = cria_pilha((tamb * 8) + 1);

    for (aux = 0; aux < tamb; aux++) {

        unsigned char caractere;

        fscanf(compactado, "%c", &caractere);

        transformaCharBit(caractere, pilha);

    }

    int aux1 = (tamb * 8) - tamArvBits;

    for (aux = 0; aux < aux1; aux++) {

        pop(pilha);

    }

    return pilha;

}