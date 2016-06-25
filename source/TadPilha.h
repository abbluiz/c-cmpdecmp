#ifndef TAD_PILHA_H_
#define TAD_PILHA_H_

typedef struct pilha Pilha;

/* -------------------------------------------------------  FUNÇÕES ELEMENTARES ------------------------------------------------------- */

/* Cria uma pilha com tamanho máximo passado como parâmetro 
 * input: tamanho máximo da pilha
 * output: pilha inicializada
 * pre-condicao: inteiro passado é positivo maior que zero
 * pos-condicao: pilha de retorno foi inicializada corretamente
 */
Pilha* cria_pilha(int tamArvHuff);

/* Adiciona caractere (item) no topo da pilha 
 * input: caractere a ser adicionado e pilha a ser modificada
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: item é adicionado ao topo da pilha e este é atualizado caso não atinja tamanho max
 */
void push(char bit, Pilha* pilha);

/* Retira caractere do topo da pilha 
 * input: pilha a ser atualizada
 * output: caractere "retirado" 
 * pre-condicao: nenhum
 * pos-condicao: caractere do topo é retornado e o mesmo é atualizado caso haja caracteres na pilha
 */
char pop(Pilha* pilha);

/* Imprime sequência de caracteres da pilha 
 * input: pilha a ser impressa
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: toda a sequência de caractere da pilha é impressa corretamente
 */
void imprime_pilha(Pilha* pilha);

/* Memória alocada pela pilha em questão é desalocada
 * input: pilha a ser "destruída"
 * output: pilha vazia
 * pre-condicao: nenhum
 * pos-condicao: a memória alocada pela pilha em questão foi desalocada
 */
Pilha* destroi_pilha(Pilha* pilha);

/* -------------------------------------------------  F. AUXILIARES E DE VERIFICAÇÃO ------------------------------------------------- */

/* Verifica se uma pilha é vazia ou não
 * input: pilha a ser verificada
 * output: inteiro 1 para pilha vazia ou 0 para não vazia
 * pre-condicao: nenhum
 * pos-condicao: inteiro é retornado indicando se a pilha está ou não vazia
 */
int vazia_pilha(Pilha* pilha);

/* Retorna tamanho (topo) da pilha
 * input: pilha a ser verificada
 * output: inteiro representando o tamanho da pilha (topo)
 * pre-condicao: nenhum
 * pos-condicao: topo da pilha é retornado
 */
int tamanho_pilha(Pilha* pilha);

/* Transforma um unsigned char em uma sequência de caracteres 1 ou 0 representando seus bits e 
 * joga em uma pilha
 * input: unsigned char a ser transformado e pilha 
 * output: nenhum
 * pre-condicao: pilha passada como parâmetro não é vazia
 * pos-condicao: a sequência de bits do caractere é passado para a pilha
 */
void transformaCharBit(unsigned char caractere, Pilha* pilha);

/* Altera o topo de uma pilha com o inteiro passado como parâmetro 
 * input: pilha a ser modificada e valor novo de topo
 * output: nenhum
 * pre-condicao: inteiro de topo é um valor maior que zero e menor que o tamanho máximo da pilha
 * pos-condicao: valor de topo da pilha é modificado com o novo valor
 */
void alteraTopo(Pilha* pilha, int topo);

/* ---------------------------------------------------------  FUNÇÕES DE RETORNO --------------------------------------------------------- */

/* Função que retorna o caractere de posicão n da pilha
 * input: pilha e posição n
 * output: caractere da posição n
 * pre-condicao: posição n deve existir na pilha
 * pos-condicao: caractere de posição n é retornado
 */
char rtnCaracterPilha(Pilha* pilha, int n);

/* Função que retorna o valor do topo de uma pilha 
 * input: pilha a ser verificada
 * output: inteiro que representa o topo da pilha em questão
 * pre-condicao: pilha deve existir
 * pos-condicao: topo deve ser retornado
 */
int rtnTopoPilha(Pilha* pilha);

/* Função que retorna o tamanho máximo de uma pilha
 * input: pilha a ser verificada
 * output: inteiro que representa o tamanho máximo da pilha em questão
 * pre-condicao: pilha deve existir
 * pos-condicao: tamanho máximo deve ser retornado
 */
int rtnMaxTamPilha(Pilha* pilha);

#endif /* TAD_PILHA_H_ */