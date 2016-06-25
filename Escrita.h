#ifndef ESCRITA_H_
#define ESCRITA_H_

#include "TadPilha.h"
#include "TadTabela.h"

/* Função imprime o tempo em segundos corretamente
 * input: tempo em segundos
 * output: nenhum
 * pre-condicao: um tempo em segundos válido é passado como parâmetro
 * pos-condicao: o tempo é mostrado corretamente, como por exemplo em horas, minutos ou seg
 */
void MostraTempo(float tempoSeg);

/* ---------------------------------------------------------------  COMPACTAÇÃO --------------------------------------------------------------- */

/* Imprime o caracter ASCII e o numero de ocorrencias do arquivo de entrada
 * inputs: o caracter ASCII e o numero de ocorrencias
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: imprime na tela o caracter e o numero de ocorrencia
 */
void cImprimeASCII(unsigned char c, long int i);

/* Imprime o caracter ASCII e o numero de ocorrencias no arquivo de entrada com auxilio de outras
 * funçoes
 * inputs: vetor que representa a quantidade de vezes em que cada caracter da tabela ASCII se
 * repete
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: chama funçao auxiliar que imprime na tela o caracter e o numero de ocorrencia
 * para cada caracter da tabela ASCII
 */
void cImprimeOcorrencias(long int ocorrencias[]);

/* Escreve no arquivo compactado o tamanho e o nome do arquivo a ser compactado
 * inputs: arquivo compactado e nome do arquivo original
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: escreve no arquivo de saida o tamanho seguido pelo próprio nome do arquivo
 */
void cEscreveNomeArq(FILE* arquivo, char nomeArq[]);

/* Escreve o tamanho e a arvore de bits no arquivo compactado
 * inputs: arquivo compactado e a arvore de bits
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: escreve no arquivo compactado o tamanho seguido pela arvore de bits
 */
void cEscreveArvoreBits(FILE* arquivo, Pilha* arv_bits);

/* Escreve o restante do arquivo compactado
 * inputs: arquivo original, arquivo compactado, tabela de Huffman, tamanho do conteúdo em bits e
 * altura da árvore de Huffman
 * output: nenhum
 * pre-condicao: função deve ser chamada na ordem correta, além dos arquivos passados serem o
 * arquivo a ser compactado e o arquivo compactado, respectivamente
 * pos-condicao: escreve no arquivo compactado o conteúdo do arquivo original usando a codificação
 * de Huffman
 */
void cEscreveConteudoCompact(FILE* compactar, FILE* saida, ListaTab* listaTabHuff,
        long long int tamSaidaBits, int alturaArvHuff);

/* Mostra informações de tempo de Compactação
 * input: tempos final para todas as tarefas relevantes do compactador
 * output: nenhum
 * pre-condicao: função deve ser chamada no final do compactador e os tempos devem existir
 * pos-condicao: o tempo de compactação é mostrado corretamente
 */
void cMostraEstatComp(clock_t tempoFinalOcor, clock_t tempoFinalListaHuff,
        clock_t tempoFinalArvoreHuff, clock_t tempoFinalTabHuff, clock_t tempoFinalEscrComp,
        clock_t tempoFinalLib, clock_t tempoFinal);

/* ------------------------------------------------------------  DESCOMPACTAÇÃO ------------------------------------------------------------ */

/* Procura na árvore de Huffman o caracter correspondente através dos bits
 * input: árvore de Huffman, caracter a ser procurado, vetor que armazenará o caracter e
 * e uma flag indicando se o caracter é válido ou não, int que indica a posição na pilha, a
 * pilha de bits, vetor de inteiros que indicará a posição que pilha parou.
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: se o caracter foi achado com sucesso, é armazenado no campo 0 do vetor
 * caracter, e no campo 1, é armazenado o valor 1.  Senão, no campo 1 é armazenado o valor
 * '\0'.  Em qualquer que for o caso, o vetor de inteiros codPos é atualizado com a posição
 * em que se parou na pilha de Bits.
 */
void dProcuraCaracterArvoreHuffman(Arvore* arvoreHuff, char c, unsigned char caracter[], int pos,
        Pilha* pilhaBits, int* codPos);

/* Escreve o arquivo descompactado, utilizando funções auxiliares
 * input: arquivo compactado, arquivo final descompactado, arvore de Huffman
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: o arquivo descompactado foi escrito com êxito, e está idêntico ao original
 */
void dEscreveConteudoDescmp(FILE* compactado, FILE* saida, Arvore* arvoreHuff);

/* Mostra informações de tempo de Descompactação
 * input: tempos final para todas as tarefas relevantes do descompactador
 * output: nenhum
 * pre-condicao: função deve ser chamada no final do descompactador e os tempos devem existir
 * pos-condicao: o tempo de descompactação é mostrado corretamente
 */
void dMostraEstatDescmp(clock_t tempoFinalNomeArq, clock_t tempoFinalRecriaArv,
        clock_t tempoFinalReescreveArq, clock_t tempoFinalLib, clock_t tempoFinal);

#endif /* ESCRITA_H_ */