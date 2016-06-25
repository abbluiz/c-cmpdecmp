/** Define um TAD representando um mapa de bits.
 * @file bitmap.h
 * @author Joao Paulo Andrade Almeida (jpalmeida@inf.ufes.br)
 */

#ifndef BITMAP_H_
#define BITMAP_H_
#include "TadPilha.h"

/**
 * Estrutura para representar um mapa de bits.
 */
typedef struct {
	unsigned int max_size;		///< tamanho maximo em bits
	unsigned int length; 		///< tamanho atual em bits
	unsigned char* contents; 	///< conteudo do mapa de bits
} bitmap;

typedef struct bitmap Bitmap;

unsigned char* bitmapGetContents(bitmap bm);
unsigned int bitmapGetMaxSize(bitmap bm);
unsigned int bitmapGetLength(bitmap bm);
bitmap bitmapInit(unsigned int max_size);
unsigned char bitmapGetBit(bitmap bm, unsigned int index);
void bitmapSetBit(bitmap* bm, unsigned int index, unsigned char bit);
void bitmapAppendLeastSignificantBit(bitmap* bm, unsigned char bit);

/* Colaca a pilha no struct do Bitmap
 * input: bitmap onde será inserido, a pilha que será inserida
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: conteúdo da pilha passada para o bitmap com sucesso
 */
void ColocaPilhaBitMap(bitmap * bitm, Pilha* pilha);

/* Escreve o conteúdo do bitmap no arquivo de saída a ser compactado
 * input: arquivo de saída onde será impresso, o bitmap que será escrito
 * inteiro indicando o tamanho do bitmap
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: conteúdo compactado foi escrito com sucesso no arquivo
 * de saída
 */
void EscreveBitmap(FILE* compacta, bitmap * bitm, int topo);

/* Libera espaço alocado por determinado bitmap
 * input: bitmap a ser liberado
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: memória alocada é liberada
 */
void bitmapLibera(bitmap* bitm);

#endif /*BITMAP_H_*/