#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Escrita.h"
#include "TadBitmap.h"
#include "TadPilha.h"
#include "TadTabela.h"

void MostraTempo(float tempoSeg) {

    float segundos = tempoSeg;

    int horas = 0, minutos = 0;

    if (segundos >= 60.0) {

        minutos = (int) (segundos / 60.0);

        segundos = segundos - ((float) minutos * 60.0);

    }

    if (minutos >= 60) {

        horas = minutos / 60;

        minutos = minutos - (horas * 60);

    }

    if (horas >= 1) {

        printf("%d horas, %d minutos e %.2f segundos", horas, minutos, segundos);

    } else if (minutos >= 1) {

        printf("%d minutos e %.2f segundos", minutos, segundos);

    } else {

        printf("%.2f segundos", segundos);

    }

}

/* ---------------------------------------------------------------  COMPACTAÇÃO --------------------------------------------------------------- */

void cImprimeASCII(unsigned char c, long int i) {

    if (c == 0)
        printf("(NUL) - %ld\n", i);
    else if (c == 1)
        printf("(SOH) - %ld\n", i);
    else if (c == 2)
        printf("(STX) - %ld\n", i);
    else if (c == 3)
        printf("(ETX) - %ld\n", i);
    else if (c == 4)
        printf("(EOT) - %ld\n", i);
    else if (c == 5)
        printf("(ENQ) - %ld\n", i);
    else if (c == 6)
        printf("(ACK) - %ld\n", i);
    else if (c == 7)
        printf("(BEL) - %ld\n", i);
    else if (c == 8)
        printf("(BS) - %ld\n", i);
    else if (c == 9)
        printf("(HT) - %ld\n", i);
    else if (c == 10)
        printf("(LF) - %ld\n", i);
    else if (c == 11)
        printf("(VT) - %ld\n", i);
    else if (c == 12)
        printf("(FF) - %ld\n", i);
    else if (c == 13)
        printf("(CR) - %ld\n", i);
    else if (c == 14)
        printf("(SO) - %ld\n", i);
    else if (c == 15)
        printf("(SI) - %ld\n", i);
    else if (c == 16)
        printf("(DLE) - %ld\n", i);
    else if (c == 17)
        printf("(DC1) - %ld\n", i);
    else if (c == 18)
        printf("(DC2) - %ld\n", i);
    else if (c == 19)
        printf("(DC3) - %ld\n", i);
    else if (c == 20)
        printf("(DC4) - %ld\n", i);
    else if (c == 21)
        printf("(NAK) - %ld\n", i);
    else if (c == 22)
        printf("(SYN) - %ld\n", i);
    else if (c == 23)
        printf("(ETB) - %ld\n", i);
    else if (c == 24)
        printf("(CAN) - %ld\n", i);
    else if (c == 25)
        printf("(EM) - %ld\n", i);
    else if (c == 26)
        printf("(SUB) - %ld\n", i);
    else if (c == 27)
        printf("(ESC) - %ld\n", i);
    else if (c == 28)
        printf("(FS) - %ld\n", i);
    else if (c == 29)
        printf("(GS) - %ld\n", i);
    else if (c == 30)
        printf("(RS) - %ld\n", i);
    else if (c == 31)
        printf("(US) - %ld\n", i);
    else if (c == 32)
        printf("SPACE - %ld\n", i);
    else if (c >= 33 && c <= 126)
        printf("%c - %ld\n", c, i);
    else if (c == 127)
        printf("DELETE - %ld\n", i);
    else if (c == 127)
        printf("DELETE - %ld\n", i);
    else if (c == 128)
        printf("&euro; - %ld\n", i);
    else if (c == 129)
        printf("NOTHING - %ld\n", i);
    else if (c == 130)
        printf("&sbquo; - %ld\n", i);
    else if (c == 131)
        printf("&fnof; - %ld\n", i);
    else if (c == 132)
        printf("&bdquo; - %ld\n", i);
    else if (c == 133)
        printf("&hellip; - %ld\n", i);
    else if (c == 134)
        printf("DAGGER - %ld\n", i);
    else if (c == 135)
        printf("D. DAGGER - %ld\n", i);
    else if (c == 136)
        printf("&circ; - %ld\n", i);
    else if (c == 137)
        printf("&permil; - %ld\n", i);
    else if (c == 138)
        printf("&Scaron; - %ld\n", i);
    else if (c == 139)
        printf("&lsaquo; - %ld\n", i);
    else if (c == 140)
        printf("&OElig; - %ld\n", i);
    else if (c == 141)
        printf("NOTHING - %ld\n", i);
    else if (c == 142)
        printf("Z W. CARON - %ld\n", i);
    else if (c == 143)
        printf("NOTHING - %ld\n", i);
    else if (c == 144)
        printf("NOTHING - %ld\n", i);
    else if (c == 145)
        printf("&lsquo; - %ld\n", i);
    else if (c == 146)
        printf("&rsquo; - %ld\n", i);
    else if (c == 147)
        printf("&ldquo; - %ld\n", i);
    else if (c == 148)
        printf("&rdquo; - %ld\n", i);
    else if (c == 149)
        printf("BULLET - %ld\n", i);
    else if (c == 150)
        printf("&ndash; - %ld\n", i);
    else if (c == 151)
        printf("&mdash; - %ld\n", i);
    else if (c == 152)
        printf("&tilde; - %ld\n", i);
    else if (c == 153)
        printf("TRADEMARK - %ld\n", i);
    else if (c == 154)
        printf("&scaron; - %ld\n", i);
    else if (c == 155)
        printf("&rsaquo; - %ld\n", i);
    else if (c == 156)
        printf("&oelig; - %ld\n", i);
    else if (c == 157)
        printf("NOTHING - %ld\n", i);
    else if (c == 158)
        printf("Z W. CARON sm - %ld\n", i);
    else if (c == 159)
        printf("&Yuml; - %ld\n", i);
    else if (c == 160)
        printf("&nbsp; - %ld\n", i);
    else if (c == 161)
        printf("&iexcl; - %ld\n", i);
    else if (c == 162)
        printf("CENT - %ld\n", i);
    else if (c == 163)
        printf("POUND - %ld\n", i);
    else if (c == 164)
        printf("CURRENCY - %ld\n", i);
    else if (c == 165)
        printf("YEN - %ld\n", i);
    else if (c == 166)
        printf("PIPE - %ld\n", i);
    else if (c == 167)
        printf("SECTION - %ld\n", i);
    else if (c == 168)
        printf("UMLAUT - %ld\n", i);
    else if (c == 169)
        printf("SECTION - %ld\n", i);
    else if (c == 170)
        printf("&ordf; - %ld\n", i);
    else if (c == 171)
        printf("&laquo; - %ld\n", i);
    else if (c == 172)
        printf("NOT - %ld\n", i);
    else if (c == 173)
        printf("&shy; - %ld\n", i);
    else if (c == 174)
        printf("&reg; - %ld\n", i);
    else if (c == 175)
        printf("OVERLINE - %ld\n", i);
    else if (c == 176)
        printf("DEGREE - %ld\n", i);
    else if (c == 177)
        printf("&plusmn; - %ld\n", i);
    else if (c == 178)
        printf("SQUARED - %ld\n", i);
    else if (c == 179)
        printf("CUBED - %ld\n", i);
    else if (c == 180)
        printf("&acute; - %ld\n", i);
    else if (c == 181)
        printf("MICRO - %ld\n", i);
    else if (c == 182)
        printf("PARAGRAPH - %ld\n", i);
    else if (c == 183)
        printf("&middot; - %ld\n", i);
    else if (c == 184)
        printf("&cedil; - %ld\n", i);
    else if (c == 185)
        printf("&sup1; - %ld\n", i);
    else if (c == 186)
        printf("&ordm; - %ld\n", i);
    else if (c == 187)
        printf("&raquo; - %ld\n", i);
    else if (c == 188)
        printf("&frac14; - %ld\n", i);
    else if (c == 189)
        printf("&frac12; - %ld\n", i);
    else if (c == 190)
        printf("&frac34; - %ld\n", i);
    else if (c == 191)
        printf("&iquest; - %ld\n", i);
    else if (c == 192)
        printf("&Agrave; - %ld\n", i);
    else if (c == 193)
        printf("&Aacute; - %ld\n", i);
    else if (c == 194)
        printf("&Acirc; - %ld\n", i);
    else if (c == 195)
        printf("&Atilde; - %ld\n", i);
    else if (c == 196)
        printf("&Auml; - %ld\n", i);
    else if (c == 197)
        printf("&Aring; - %ld\n", i);
    else if (c == 198)
        printf("&AElig; - %ld\n", i);
    else if (c == 199)
        printf("&Ccedil; - %ld\n", i);
    else if (c == 200)
        printf("&Egrave; - %ld\n", i);
    else if (c == 201)
        printf("&Eacute; - %ld\n", i);
    else if (c == 202)
        printf("&Ecirc; - %ld\n", i);
    else if (c == 203)
        printf("&Euml; - %ld\n", i);
    else if (c == 204)
        printf("&Igrave; - %ld\n", i);
    else if (c == 205)
        printf("&Iacute; - %ld\n", i);
    else if (c == 206)
        printf("&Icirc; - %ld\n", i);
    else if (c == 207)
        printf("&Iuml; - %ld\n", i);
    else if (c == 208)
        printf("ETH - %ld\n", i);
    else if (c == 209)
        printf("&Ntilde; - %ld\n", i);
    else if (c == 210)
        printf("&Ograve; - %ld\n", i);
    else if (c == 211)
        printf("&Oacute; - %ld\n", i);
    else if (c == 212)
        printf("&Ocirc; - %ld\n", i);
    else if (c == 213)
        printf("&Otilde; - %ld\n", i);
    else if (c == 214)
        printf("&Ouml; - %ld\n", i);
    else if (c == 215)
        printf("TIMES - %ld\n", i);
    else if (c == 216)
        printf("&Oslash; - %ld\n", i);
    else if (c == 217)
        printf("&Ugrave; - %ld\n", i);
    else if (c == 218)
        printf("&Uacute; - %ld\n", i);
    else if (c == 219)
        printf("&Ucirc; - %ld\n", i);
    else if (c == 220)
        printf("&Uuml; - %ld\n", i);
    else if (c == 221)
        printf("&Yacute; - %ld\n", i);
    else if (c == 222)
        printf("THORN - %ld\n", i);
    else if (c == 223)
        printf("&szlig; - %ld\n", i);
    else if (c == 224)
        printf("&agrave; - %ld\n", i);
    else if (c == 225)
        printf("&aacute; - %ld\n", i);
    else if (c == 226)
        printf("&acirc; - %ld\n", i);
    else if (c == 227)
        printf("&atilde; - %ld\n", i);
    else if (c == 228)
        printf("&auml; - %ld\n", i);
    else if (c == 229)
        printf("&aring; - %ld\n", i);
    else if (c == 230)
        printf("&aelig; - %ld\n", i);
    else if (c == 231)
        printf("&ccedil; - %ld\n", i);
    else if (c == 232)
        printf("&egrave; - %ld\n", i);
    else if (c == 233)
        printf("&eacute; - %ld\n", i);
    else if (c == 234)
        printf("&ecirc; - %ld\n", i);
    else if (c == 235)
        printf("&euml; - %ld\n", i);
    else if (c == 236)
        printf("&igrave; - %ld\n", i);
    else if (c == 237)
        printf("&iacute; - %ld\n", i);
    else if (c == 238)
        printf("&icirc; - %ld\n", i);
    else if (c == 239)
        printf("&iuml; - %ld\n", i);
    else if (c == 240)
        printf("ETH sm - %ld\n", i);
    else if (c == 241)
        printf("&ntilde; - %ld\n", i);
    else if (c == 242)
        printf("&ograve; - %ld\n", i);
    else if (c == 243)
        printf("&oacute; - %ld\n", i);
    else if (c == 244)
        printf("&ocirc; - %ld\n", i);
    else if (c == 245)
        printf("&otilde; - %ld\n", i);
    else if (c == 246)
        printf("&ouml; - %ld\n", i);
    else if (c == 247)
        printf("DIVISION - %ld\n", i);
    else if (c == 248)
        printf("&oslash; - %ld\n", i);
    else if (c == 249)
        printf("&ugrave; - %ld\n", i);
    else if (c == 250)
        printf("&uacute; - %ld\n", i);
    else if (c == 251)
        printf("&ucirc; - %ld\n", i);
    else if (c == 252)
        printf("&uuml; - %ld\n", i);
    else if (c == 253)
        printf("&yacute - %ld\n", i);
    else if (c == 254)
        printf("THORN sm - %ld\n", i);
    else if (c == 255)
        printf("&yuml; - %ld\n", i);

}

void cImprimeOcorrencias(long int ocorrencias[]) {

    printf("\n\n--------------\n");
    printf("OCORRÊNCIAS: \n\n");

    int aux, cont = 0;

    for (aux = 0; aux < 256; aux++) {

        unsigned char caract = cont;

        cImprimeASCII(caract, ocorrencias[aux]);

        cont++;

    }

}

void cEscreveNomeArq(FILE* arquivo, char nomeArq[]) {

    int tamanhoNomeArq = strlen(nomeArq);

    fprintf(arquivo, "%d", tamanhoNomeArq);
    fprintf(arquivo, "%s", nomeArq);

}

void cEscreveArvoreBits(FILE* arquivo, Pilha* arv_bits) {

    fprintf(arquivo, "%d", tamanho_pilha(arv_bits));

    bitmap bit = bitmapInit(tamanho_pilha(arv_bits) + 1);

    bitmap * bitm = &bit;

    ColocaPilhaBitMap(bitm, arv_bits);

    EscreveBitmap(arquivo, bitm, bitmapGetLength(bit));

    bitmapLibera(bitm);

}

void cEscreveConteudoCompact(FILE* compactar, FILE* saida, ListaTab* listaTabHuff,
        long long int tamSaidaBits, int alturaArvHuff) {

    fprintf(saida, "%lld", tamSaidaBits);

    long long int tamRestante = tamSaidaBits;

    unsigned char caractere;

    Pilha* pilhaBits = cria_pilha(1024 * 1024 * 8);
    Pilha* pilhaResto = cria_pilha(alturaArvHuff + 2);

    while (fscanf(compactar, "%c", &caractere) != EOF) {

        Pilha* pilhaCharBit = procuraCharTab(caractere, listaTabHuff);

        if ((rtnMaxTamPilha(pilhaBits) - rtnTopoPilha(pilhaBits) - 1) >= (rtnTopoPilha(pilhaCharBit) - 1)) {

            int aux;

            for (aux = 0; aux < rtnTopoPilha(pilhaCharBit); aux++) {

                push(rtnCaracterPilha(pilhaCharBit, aux), pilhaBits);

            }

        } else {

            int aux1, aux2;

            for (aux1 = 0, aux2 = rtnTopoPilha(pilhaBits); aux2 != rtnMaxTamPilha(pilhaBits); aux1++,
                    aux2++) {

                push(rtnCaracterPilha(pilhaCharBit, aux1), pilhaBits);

            }

            for (aux1 = aux1; aux1 < rtnTopoPilha(pilhaCharBit); aux1++) {

                push(rtnCaracterPilha(pilhaCharBit, aux1), pilhaResto);

            }

        }

        if (tamRestante > (1024 * 1024 * 8)) {

            if (rtnTopoPilha(pilhaBits) == rtnMaxTamPilha(pilhaBits)) {

                bitmap bit = bitmapInit(1024 * 1024 * 8);

                bitmap* bitm = &bit;

                ColocaPilhaBitMap(bitm, pilhaBits);
                EscreveBitmap(saida, bitm, bitmapGetLength(bit));

                bitmapLibera(bitm);

                tamRestante = tamRestante - (1024 * 1024 * 8);

                alteraTopo(pilhaBits, 0);

            }

        } else {

            if ((rtnTopoPilha(pilhaBits)) == tamRestante) {

                bitmap bit = bitmapInit(tamRestante);

                bitmap* bitm = &bit;

                ColocaPilhaBitMap(bitm, pilhaBits);
                EscreveBitmap(saida, bitm, bitmapGetLength(bit));

                bitmapLibera(bitm);

            }

        }

        if (rtnTopoPilha(pilhaResto) != 0) {

            alteraTopo(pilhaBits, 0);

            int aux3;

            for (aux3 = 0; aux3 < rtnTopoPilha(pilhaResto); aux3++) {

                push(rtnCaracterPilha(pilhaResto, aux3), pilhaBits);

            }

            alteraTopo(pilhaResto, 0);
            alteraTopo(pilhaBits, aux3);

        }

    }

    pilhaBits = destroi_pilha(pilhaBits);
    pilhaResto = destroi_pilha(pilhaResto);

}

void cMostraEstatComp(clock_t tempoFinalOcor, clock_t tempoFinalListaHuff,
        clock_t tempoFinalArvoreHuff, clock_t tempoFinalTabHuff, clock_t tempoFinalEscrComp,
        clock_t tempoFinalLib, clock_t tempoFinal) {

    float tempSegOcor = (float) tempoFinalOcor / CLOCKS_PER_SEC;
    float tempSegListaHuff = (float) tempoFinalListaHuff / CLOCKS_PER_SEC;
    float tempSegArvoreHuff = (float) tempoFinalArvoreHuff / CLOCKS_PER_SEC;
    float tempSegTabHuff = (float) tempoFinalTabHuff / CLOCKS_PER_SEC;
    float tempSegEscrComp = (float) tempoFinalEscrComp / CLOCKS_PER_SEC;
    float tempSegLib = (float) tempoFinalLib / CLOCKS_PER_SEC;
    float tempSegFinal = (float) tempoFinal / CLOCKS_PER_SEC;

    printf("\n--------------\n");
    printf("RESULTADOS DA COMPACTAÇÃO:\n\n");

    printf("Tempo gasto para contar as ocorrências: ");
    MostraTempo(tempSegOcor);
    printf("\n");

    printf("Tempo gasto para montar a lista de Huffman inicial ordenada: ");
    MostraTempo(tempSegListaHuff);
    printf("\n");

    printf("Tempo gasto para montar a árvore de Huffman: ");
    MostraTempo(tempSegArvoreHuff);
    printf("\n");

    printf("Tempo gasto para montar a tabela de Huffman: ");
    MostraTempo(tempSegTabHuff);
    printf("\n");

    printf("Tempo gasto para gerar e escrever os bits no arquivo compactado: ");
    MostraTempo(tempSegEscrComp);
    printf("\n");

    printf("Tempo gasto para liberação das estruturas: ");
    MostraTempo(tempSegLib);
    printf("\n");

    printf("Tempo Total: ");
    MostraTempo(tempSegFinal);
    printf("\n\n");

}

/* ------------------------------------------------------------  DESCOMPACTAÇÃO ------------------------------------------------------------ */

void dProcuraCaracterArvoreHuffman(Arvore* arvoreHuff, char c, unsigned char caracter[], int pos,
        Pilha* pilhaBits, int* codPos) {

    if (returnPeso(arvoreHuff) != -1) {

        if (returnisChar(arvoreHuff)) {

            caracter[0] = returnChar(arvoreHuff);
            caracter[1] = '1';
            codPos[0] = pos;
            return;

        }

        pos++;

        if (pos >= rtnTopoPilha((pilhaBits))) {

            codPos[0] = pos;
            caracter[1] = '\0';

            return;
        }

        c = rtnCaracterPilha(pilhaBits, pos);

        if (c == '0') {

            char c = rtnCaracterPilha(pilhaBits, pos);
            codPos[0] = pos;
            dProcuraCaracterArvoreHuffman(returnDir(arvoreHuff), c, caracter, pos, pilhaBits, codPos);

        } else if (c == '1') {

            char c = rtnCaracterPilha(pilhaBits, pos);
            codPos[0] = pos;
            dProcuraCaracterArvoreHuffman(returnEsq(arvoreHuff), c, caracter, pos, pilhaBits, codPos);

        }

    }

}

void dEscreveConteudoDescmp(FILE* compactado, FILE* saida, Arvore* arvoreHuff) {

    long long int tamArq;

    fscanf(compactado, "%lld", &tamArq);

    long long int tamArqTotal = tamArq;

    unsigned char caractere;
    int pos, ultpos;

    Pilha* pilhaBits = cria_pilha(1024 * 1024 * 8);
    unsigned char codBin[3];
    int codPos[0];

    while (fscanf(compactado, "%c", &caractere) != EOF) {

        tamArq = tamArq - 8;

        transformaCharBit(caractere, pilhaBits);

        if (tamArq <= 0)
            break;

        while (rtnTopoPilha(pilhaBits) + 8 <= rtnMaxTamPilha(pilhaBits) && fscanf(compactado, "%c", &caractere) != EOF) {

            if (tamArq <= 0)
                break;

            tamArq = tamArq - 8;

            transformaCharBit(caractere, pilhaBits);

        }

        pos = -1;
        memset(codBin, '\0', sizeof (codBin));

        while (pos < rtnTopoPilha(pilhaBits) && pos <= (tamArqTotal + tamArq)) {

            if (tamArq <= 0 && pos - tamArq >= rtnTopoPilha(pilhaBits)) {

                pilhaBits = destroi_pilha(pilhaBits);
                return;

            }

            if (pos < rtnTopoPilha((pilhaBits))) {

                dProcuraCaracterArvoreHuffman(arvoreHuff, 'a', codBin, pos, pilhaBits, codPos);

            }

            if (codBin[1]) {

                pos = codPos[0];
                ultpos = pos + 1;

                codBin[2] = '\0';

                unsigned char cImp = codBin[0];

                fprintf(saida, "%c", cImp);

            } else {

                if (tamArq > 0) {

                    int oldTopo = rtnTopoPilha(pilhaBits);
                    alteraTopo(pilhaBits, 0);
                    while (ultpos < oldTopo) {

                        push(rtnCaracterPilha(pilhaBits, ultpos), pilhaBits);
                        ultpos++;

                    }
                } else {

                    pilhaBits = destroi_pilha(pilhaBits);

                    return;

                }

            }

        }
    }

    pilhaBits = destroi_pilha(pilhaBits);


}

void dMostraEstatDescmp(clock_t tempoFinalNomeArq, clock_t tempoFinalRecriaArv,
        clock_t tempoFinalReescreveArq, clock_t tempoFinalLib, clock_t tempoFinal) {

    float tempSegNomeArq = (float) tempoFinalNomeArq / CLOCKS_PER_SEC;
    float tempSegRecriaArv = (float) tempoFinalRecriaArv / CLOCKS_PER_SEC;
    float tempSegReescreveArq = (float) tempoFinalReescreveArq / CLOCKS_PER_SEC;
    float tempSegLib = (float) tempoFinalLib / CLOCKS_PER_SEC;
    float tempSegFinal = (float) tempoFinal / CLOCKS_PER_SEC;

    printf("\n--------------\n");
    printf("RESULTADOS DA DESCOMPACTAÇÃO:\n\n");

    printf("Tempo gasto para tratamento dos nomes dos arquivos: ");
    MostraTempo(tempSegNomeArq);
    printf("\n");

    printf("Tempo gasto para recriação da árvore de Huffman a partir do cabeçalho do arq.: ");
    MostraTempo(tempSegRecriaArv);
    printf("\n");

    printf("Tempo gasto para reescrever os bits do arquivo original: ");
    MostraTempo(tempSegReescreveArq);
    printf("\n");

    printf("Tempo gasto para liberação das estruturas: ");
    MostraTempo(tempSegLib);
    printf("\n");

    printf("Tempo Total: ");
    MostraTempo(tempSegFinal);
    printf("\n\n");

}
