#ifndef TAD_TABELA_H_
#define TAD_TABELA_H_

#include "TadPilha.h"
#include "TadArvore.h"

typedef struct tipoitemtab ItemTab;
typedef struct tipolistatab ListaTab;

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

/* Inicializa a lista
 * inputs: nenhum
 * output: a lista
 * pre-condicao: nenhuma
 * pos-condicao: inicializa a lista com a primeira e ultima celula apontando pra NULL
 */
ListaTab * InicializaListaTab();

/* Inicializa item
 * inputs: caractere e tamanho da árvore de Huffman para inicialização da pilha
 * output: item
 * pre-condicao: nenhuma
 * pos-condicao: espaço do item reservado com malloc
 */
ItemTab * InicializaItemTab(unsigned char caractere, int tamArvHuff);

/* Insere nova celula
 * inputs: o item a ser adicionado e a lista
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: celula adicionada a lista
 */
void InsereCelulaTab(ItemTab * item, ListaTab * lista);

/* Imprime a tabela de Huffman
 * input: lista que representa a tabela de Huffman
 * output: nenhum
 * pre-condicao: tabela de Huffman existe e foi criada corretamente
 * pos-condicao: tabela é impressa
 */
void ImprimeListaTab(ListaTab* lista);

/* Libera a lista
 * inputs: lista
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: a lista foi liberada com sucesso
 */
void liberaTabelaHuff(ListaTab* listaTab);

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */

/* Retorna o tamanho da lista
 * inputs: lista
 * output: o tamanho da lista
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
long int tamanhoListaTab(ListaTab* lista);

/* ------------------------------------------------------  F. DA TABELA DE HUFFMAN ------------------------------------------------------ */

/* Preenche a pilha de cada célula com a sequência de bits Huffman
 * input: tabela Huffman e árvore Huffman
 * output: tabela Huffman atualizada
 * pre-condicao: tabela Huffman já tem as células com os caracteres que aparecem no arquivo
 * pos-condicao: tabela Huffman é atualizada com as sequências de bits Huffman
 */
ListaTab* criaTabelaHuff(ListaTab* listaTab, Arvore* arvoreHuff);

/* Função que procura um caractere na tabela e retorna sua sequência de bits
 * input: caractere a ser procurado e tabela de Huffman
 * output: pilha que representa a sequência de bits Huffman do caractere 
 * pre-condicao: lista existe
 * pos-condicao: pilha com a sequência de bits Huffman é retornada caso caractere é encontrado
 */
Pilha* procuraCharTab(unsigned char caractere, ListaTab* listaHuff);

/* Função recursiva que atualiza pilha de sequência de bits huffman pela árvore de Huffman
 * input: árvore de Huffman, caractere, pilha e direção da árvore
 * output: inteiro para retorno da função recursiva
 * pre-condicao: nenhum
 * pos-condicao: pilha é atualizada com a sequência de bits correta caso os itens existam e sejam
 * válidos
 */
int getCodChar(Arvore* arvore, unsigned char c, Pilha* pilha, int dir);

/* Função principal que preenche a tabela de Huffman
 * input: vetor de ocorrências dos caracteres, tabela de Huffman vazia e tamanho da árvore de Huffman
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: tabela Huffman será preenchida com os caracteres 
 */
void cPreencheListaHuff(long int ocorrencias[], ListaTab* listaTabelaHuff, int tamArvHuff);

#endif /* TAD_TABELA_H_ */