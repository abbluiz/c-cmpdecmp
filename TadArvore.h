#ifndef TAD_ARVORE_H_
#define TAD_ARVORE_H_

#include "TadPilha.h"

typedef struct arv Arvore;

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

/* Cria árvore vazia 
 * input: nenhum
 * output: árvore que aponta para NULL
 * pre-condicao: nenhum
 * pos-condicao: retorna árvore vazia (que aponta para NULL)
 */
Arvore* arv_criavazia();

/* Cria árvore com as informações passadas 
 * input: caractere, peso e ramo da esquerda e da direita
 * output: árvore inicializada com as informações passadas
 * pre-condicao: nenhum
 * pos-condicao: a árvore é inicializada com as informações passadas e retornada
 */
Arvore* arv_cria (unsigned char caractere, long int peso, Arvore* r_esq, Arvore* r_dir);

/* Imprime a árvore com notação preferida
 * input: árvore a ser impressa
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: árvore é impressa com a notação padrão
 */
void arv_imprime(Arvore* arvore);

/* Muda campo isChar da árvore com o novo inteiro passado como parâmetro 
 * input: árvore a ser modificada e novo valor de isChar
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: valor de isChar é atualizado na árvore em questão
 */
void mudaisChar(Arvore* arvore, int isChar);

/* Função para liberar memória alocada pela árvore passada como parâmetro
 * input: árvore a ser liberada
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: memória alocada pela árvore é liberada
 */
void arv_libera(Arvore* arvore);

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */

/* Verifica se uma árvore é vazia ou não
 * input: árvore a ser verificada
 * output: inteiro 1 para árvore vazia ou 0 para não vazia
 * pre-condicao: nenhum
 * pos-condicao: inteiro é retornado indicando se a árvore está ou não vazia
 */
int arv_vazia(Arvore* arvore);

/* Verifica se árvore tem ou não filhos 
 * input: árvore a ser verificada
 * output: inteiro 1 para árvore sem filhos ou 0 para com filhos
 * pre-condicao: nenhum
 * pos-condicao: inteiro é retornado indicando existência ou não de filhos
 */
int arvoreSemFilho(Arvore* arvore);

/* Função que calcula e retorna a altura de uma árvore 
 * input: árvore a ser verificada
 * output: inteiro que representa a altura da árvore
 * pre-condicao: nenhum
 * pos-condicao: inteiro é retornado indicando a altura da árvore
 */
int arv_altura(Arvore* arvore);

/* ---------------------------------------------------------  FUNÇÕES DE RETORNO --------------------------------------------------------- */

/* Função que retorna o ramo da esquerda da árvore binária
 * input: árvore principal
 * output: árvore que representa o ramo da esquerda da árvore principal
 * pre-condicao: nenhum
 * pos-condicao: árvore da esquerda é retornado caso exista (NULL caso não exista)
 */
Arvore* returnEsq(Arvore* arvore);

/* Função que retorna o ramo da direita da árvore binária
 * input: árvore principal
 * output: árvore que representa o ramo da direita da árvore principal
 * pre-condicao: nenhum
 * pos-condicao: árvore da direita é retornado caso exista (NULL caso não exista)
 */
Arvore* returnDir(Arvore* arvore);

/* Função que retorna o caractere armazenado na árvore binária
 * input: árvore a ser verificada
 * output: caractere que está armazenado na árvore em questão
 * pre-condicao: nenhum
 * pos-condicao: caractere da árvore é retornado caso a mesma exista
 */
unsigned char returnChar(Arvore* arvore);

/* Função que retorna o peso do caractere armazenado na árvore binária
 * input: árvore a ser verificada
 * output: inteiro indicicando o peso que está armazenado na árvore em questão
 * pre-condicao: nenhum
 * pos-condicao: peso armazenado na árvore é retornado caso a mesma exista
 */
int returnPeso(Arvore* arvore);

/* Função que retorna o campo isChar armazenado na árvore binária
 * input: árvore a ser verificada
 * output: inteiro indicicando se aquele nó é caractere ou não
 * pre-condicao: nenhum
 * pos-condicao: inteiro isChar armazenado na árvore é retornado caso a mesma exista
 */
int returnisChar(Arvore* arvore);

/* ----------------------------------------------  COMPACTADOR E DESCOMPACTADOR ---------------------------------------------- */

/* Função que retorna a quantidade de nós que a árvore possui
 * input: árvore a ser verificada
 * output: inteiro informando a quantidade de nós
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
int recCriaArvoreBit(Arvore* arvore);

/* Função que faz o equivalente à árvore em bits, e a joga em uma pilha
 * input: a árvore a ser transformada, e o inteiro indicando a quantidade de caracteres
 * dela
 * output: a pilha contendo o equivalente a arvore em bits
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
Pilha* cCriaArvoreBit(Arvore* arvoreHuff, int tamListaHuff);

/* Função auxiliar para a transformação da árvore em bits.  A função, através do deslocamento
 * esquerda ou direita, vai preenchendo a pilha com 1 e 0, e também se for uma folha ou nó
 * input: a pilha a ser preenchida, a árvore a ser transformada
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: a pilha foi preenchida com sucesso
 */
void cPreenchePilhaArvBits(Pilha* arvBits, Arvore* arvoreHuff);

/* Função que através do binário da árvore, a recria.  Caso seja lido 1, ele cria um nó, caso
 * seja  lido um 0, ele cria uma folha com os próximos 8 bits como caractere.
 * input: a pilha a de bits, a árvore a ser recriada, um int indicando a posição na pilha,
 * um "flag" indicando a hora de parada, e um vetor com todos os caracteres do arquivo e a
 * quantidade de vez que se repete
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: a árvore foi reconstruída com sucesso
 */
int dCriaArvoreHuff(Pilha* arvBits, Arvore* arvore, int pos, int flag, long int ocorrencias[]);

#endif /* TAD_ARVORE_H_ */