#ifndef TAD_LISTA_H_
#define TAD_LISTA_H_

#include "TadArvore.h"

typedef struct tipoitem Item;
typedef struct tipolista Lista;

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

/* Inicializa a lista
 * inputs: nenhum
 * output: a lista
 * pre-condicao: nenhuma
 * pos-condicao: inicializa a lista com a primeira e ultima celula apontando pra NULL
 */
Lista * InicializaLista();

/* Inicializa item
 * inputs: a arvore
 * output: item
 * pre-condicao: nenhuma
 * pos-condicao: espaço do item reservado com malloc
 */
Item * InicializaItem(Arvore* arvore);

/* Insere nova celula
 * inputs: o item a ser adicionado e a lista
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: celula adicionada a lista
 */
void InsereCelula(Item* item, Lista* lista);


/* Libera a lista
 * inputs: lista
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: a lista foi liberada com sucesso
 */
void LiberaLista(Lista* lista);

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */


/* Retorna o tamanho da lista
 * inputs: lista
 * output: o tamanho da lista
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
long int tamanhoLista(Lista* lista);

/* --------------------------------------------------  F. DO ALGORITMO DE HUFFMAN -------------------------------------------------- */

/* Função principal que cria lista de Huffman com todos os caracteres do arquivo de entrada e seu
 * peso correspondente
 * inputs: vetor com ocorrencia dos caracteres
 * output: lista inicial ordenada
 * pre-condicao: nenhuma
 * pos-condicao: função chama funções auxiliares para ser finalizada
 */
Lista* CriaHuffman(long int ocorrencia[]);

/* Função principal que cria arvore binaria de acordo com os pesos dos caracteres
 * inputs: lista com o peso e os caracteres a serem ordenados
 * output: arvore criada
 * pre-condicao: nenhuma
 * pos-condicao: função chama funções auxiliares para ser finalizada
 */
Arvore* CriaArvoreHuffman(Lista* listaHuff);

/* Função auxiliar para a criação da lista de Huffman, ordenando a lista pelo peso
 * inputs: lista
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: lista ordenada de forma crescente de peso
 */
void OrdenaHuffman(Lista* lista);

/* Função auxiliar para a criação da lista de Huffman
 * inputs: lista
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: retira as duas celulas de arvore que foram unidas em uma e coloca no fim da lista
 */
void atualizarHuffman(Lista* listaHuff);

/* Imprime a lista de Huffman
 * inputs: lista
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: lista impressa na tela
 */
void ImprimeLista(Lista* lista);

/* Funçao auxiliar na criação da lista de Huffman
 * inputs: lista de Huffman, peso do caracter e o caracter
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: árvores auxiliares criadas e inseridas na lista de forma ordenada
 */
void InsereArvHuffman(Lista* lista, long int peso, unsigned char caracter);

#endif /* TAD_LISTA_H_ */