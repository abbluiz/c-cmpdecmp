#ifndef LEITURA_H_
#define LEITURA_H_

#include "TadTabela.h"

/*Verifica erro de leitura
* input: arquivo a ser verificado
* output: 1 caso tenha ocorrido erro, 0 caso não
* pre-condicao: nenhuma
* pos-condicao: nenhuma
*/    
int VerificaErrosLeitura(FILE* arquivo);

/* Atualiza vetor nomeArq com o nome completo do arquivo
 * inputs: string com o caminho do arquivo e vetor de char vazia para o nome do arquivo
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: nome do arquivo é atualizado no vetor nomeArq
 */
void PegaNomeDoArquivo(char caminho[], char nomeArq[]);

/* ---------------------------------------------------------------  COMPACTAÇÃO --------------------------------------------------------------- */

/*Verifica o número de ocorrencias que um caracter aparece
* inputs: arquivo a ser verificado, vetor que registra numero de ocorrências
* output: nenhum
* pre-condicao: nenhuma
* pos-condicao: o número de vezes que um caracter se repetiu ficou registrado no vetor ocorrências
*/    
void cLeituraOcorrencias(FILE* arquivo, long int ocorrencias[]);

/* Calcula  a quantidade de bits do arquivo utilizando os bits de Huffman
* inputs: o vetor de ocorrencias, a lista que contém o mapa de caracteres
* output: quantidade de bits do arquivo
* pre-condicao: nenhuma
* pos-condicao: nenhuma
*/    
long int cCalculaQntdBitsArquivo(long int ocorrencias[], ListaTab* listaHuff);

/* ------------------------------------------------------------  DESCOMPACTAÇÃO ------------------------------------------------------------ */

/* Lê o primeiro inteiro do arquivo compactado e o retorna
 * input: arquivo compactado
 * output: inteiro que representa o tamanho do nome do arquivo original
 * pre-condicao: a ordem de chamada da função importa, o arquivo lido deve ser o compactado
 * pos-condicao: inteiro que representa o tamanho do arquivo é retornado
 */
int dRetornaTamanhoNomeArquivo(FILE* compactado);

/* Cria nome do arquivo descompactado e retorna o próprio arquivo já aberto
 * inputs: tamanho do nome do arquivo original e arquivo compactado
 * output: arquivo descompactado aberto
 * pre-condicao: função deve ser chamada na ordem correta e arquivo deve ser o compactado
 * pos-condicao: arquivo descompactado é inicializado com o nome correto e retornado na função
*/
FILE* dRetornaNomeDescmp(int tamNomeArq, FILE* descompactar) ;

/* Atualiza string com o nome do arquivo original através da leitura do cabeçalho do arq. compactado
 * inputs: arquivo compactado, vetor de caracteres nomeArq e inteiro com o tamanho do nome
 * output: nenhum
 * pre-condicao: a ordem de chamada da função importa, arquivo a ser lido é o compactado
 * pos-condicao: nome do arquivo é recriado corretamente na string nomeArq
 */
void dRecriaNomeArquivo(FILE* compactado, char nomeArq[], int tam);

/* Lê o tamanho da árvore de Huffman em bits e o retorna pelo cabeçalho do arquivo compactado
 * inputs: arquivo compactado
 * output: inteiro que representa o tamanho da árvore em bits
 * pre-condicao: função deve ser chamada na ordem correta e arquivo deve ser o compactado
 * pos-condicao: inteiro que representa o tamanho da árvore em bits será retornado
 */
int dRetornaTamanhoArvoreBits(FILE* compactado);

/* Lê e armazena a árvore de Huffman em bits do arquivo compactado para uma pilha
 * inputs: arquivo compactado e inteiro representando o tamanho da árvore em bits
 * output: pilha contendo uma cadeia de caracteres representando a sequência de bits da árvore
 * pre-condicao: função deve ser chamada na ordem correta e arquivo deve ser o compactado
 * pos-condicao: pilha com a cadeia de caracteres de bits é criada corretamente
 */
Pilha* dArvoreBits(FILE* compactado, int tamArvBits);

#endif /* LEITURA_H_ */