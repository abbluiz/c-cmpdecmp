#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "TadArvore.h"
#include "TadLista.h"
#include "TadTabela.h"
#include "TadPilha.h"
#include "Escrita.h"
#include "Leitura.h"
#include "TadBitmap.h"

int main(int argc, char* argv[]) {

    clock_t tempoInicial = clock();

    if (argc < 2) {

        printf("\n\t> ERRO: Necessário passar arquivo a ser compactado como parâmetro na execução"
                " do programa!\n\n");

        return 0;

    }

    FILE* compactar = fopen(argv[1], "rb");

    char nomeArq[257];

    PegaNomeDoArquivo(argv[1], nomeArq);

    printf("\n> A compactar arquivo %s ...", nomeArq);

    if (VerificaErrosLeitura(compactar))
        return 0;

    printf("\n\n> Registrando ocorrências de caracteres ...");
    
    printf("\n");
    
    clock_t tempoInicialOcor = clock();

    long int ocorrencias[256];

    cLeituraOcorrencias(compactar, ocorrencias);

    cImprimeOcorrencias(ocorrencias);

    clock_t tempoFinalOcor = clock() - tempoInicialOcor;

    clock_t tempoInicialListaHuff = clock();

    printf("\n--------------");

    Lista* listaHuff = CriaHuffman(ocorrencias);

    clock_t tempoFinalListaHuff = clock() - tempoInicialListaHuff;

    clock_t tempoInicialArvoreHuff = clock();

    Arvore* arvoreHuff = CriaArvoreHuffman(listaHuff);

    printf("--------------\n");
    printf("ÁRVORE DE HUFFMAN:\n\n");
    arv_imprime(arvoreHuff);
    printf("\n\n");

    int alturaArvoreHuff = arv_altura(arvoreHuff);

    clock_t tempoFinalArvoreHuff = clock() - tempoInicialArvoreHuff;

    clock_t tempoInicialTabHuff = clock();

    ListaTab* listaTabelaHuff = InicializaListaTab();

    cPreencheListaHuff(ocorrencias, listaTabelaHuff, alturaArvoreHuff);

    listaTabelaHuff = criaTabelaHuff(listaTabelaHuff, arvoreHuff);

    ImprimeListaTab(listaTabelaHuff);

    clock_t tempoFinalTabHuff = clock() - tempoInicialTabHuff;
    
    printf("\n> Compactando ...");
    
    printf("\n");

    clock_t tempoInicialEscrComp = clock();

    rewind(compactar);
    
    char nomeComp[262] = "\0";
    
    strcpy(nomeComp, nomeArq);
    strcat(nomeComp, ".cmp");
    
    FILE* compactado = fopen(nomeComp, "wb");

    cEscreveNomeArq(compactado, nomeArq);

    Pilha* pilhaArvBits = cCriaArvoreBit(arvoreHuff, tamanhoListaTab(listaTabelaHuff));
    cEscreveArvoreBits(compactado, pilhaArvBits);

    long long int tamCompactar = cCalculaQntdBitsArquivo(ocorrencias, listaTabelaHuff);
    cEscreveConteudoCompact(compactar, compactado, listaTabelaHuff, tamCompactar,
            alturaArvoreHuff);

    clock_t tempoFinalEscrComp = clock() - tempoInicialEscrComp;

    clock_t tempoInicialLib = clock();

    arv_libera(arvoreHuff);
    liberaTabelaHuff(listaTabelaHuff);

    pilhaArvBits = destroi_pilha(pilhaArvBits);
    fclose(compactar);
    fclose(compactado);

    clock_t tempoFinalLib = clock() - tempoInicialLib;

    clock_t tempoFinal = clock() - tempoInicial;
    
    cMostraEstatComp(tempoFinalOcor, tempoFinalListaHuff, tempoFinalArvoreHuff, tempoFinalTabHuff,
            tempoFinalEscrComp, tempoFinalLib, tempoFinal);

    return 0;

}