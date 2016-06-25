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

        printf("\n\t > ERRO: Necessário passar arquivo a ser descompactado como parâmetro na "
                "execução do programa!\n\n");

        return 0;

    }

    FILE* descompactar = fopen(argv[1], "rb");

    clock_t tempoInicialNomeArq = clock();

    char nomeArq[257];

    PegaNomeDoArquivo(argv[1], nomeArq);

    printf("\n> A descompactar arquivo %s ...", nomeArq);

    if (VerificaErrosLeitura(descompactar))
        return 0;

    int tamNomeArq = dRetornaTamanhoNomeArquivo(descompactar);

    FILE* descompactado = dRetornaNomeDescmp(tamNomeArq, descompactar);

    clock_t tempoFinalNomeArq = clock() - tempoInicialNomeArq;

    clock_t tempoInicialRecriaArv = clock();

    printf("\n\n> Lendo cabeçalho do arquivo ...");
    printf("\n\t- Reconstruindo árvore de Huffman ...");
    
    int tamArvBits = dRetornaTamanhoArvoreBits(descompactar);
    Pilha* arvBits = dArvoreBits(descompactar, tamArvBits);

    Arvore* arvoreHuff = arv_criavazia();
    long int ocorrencias[256];

    memset(ocorrencias, '\0', sizeof (ocorrencias));

    arvoreHuff = arv_cria('a', 0, NULL, NULL);

    dCriaArvoreHuff(arvBits, arvoreHuff, -1, 1, ocorrencias);

    clock_t tempoFinalRecriaArv = clock() - tempoInicialRecriaArv;

    clock_t tempoInicialReescreveArq = clock();

    printf("\n\n> Descompactando ...\n");
    
    dEscreveConteudoDescmp(descompactar, descompactado, arvoreHuff);

    clock_t tempoFinalReescreveArq = clock() - tempoInicialReescreveArq;

    clock_t tempoInicialLib = clock();

    destroi_pilha(arvBits);
    arv_libera(arvoreHuff);
    fclose(descompactado);
    fclose(descompactar);

    clock_t tempoFinalLib = clock() - tempoInicialLib;

    clock_t tempoFinal = clock() - tempoInicial;
    
    dMostraEstatDescmp(tempoFinalNomeArq, tempoFinalRecriaArv, tempoFinalReescreveArq,
            tempoFinalLib, tempoFinal);

    return 0;

}
