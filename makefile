# Makefile do segundo trabalho de Estrutura de Dados I
# Gustavo Luiz & LABB

# Arquivo a ser compactado
ENTRADACOMP = Bible

# Arquivo a ser descompactado
ENTRADADESCMP = Bible.cmp

# Compilador utilizado
CC = gcc

# Opções de compilação
CFLAGS = -Wall

# Ligação com as bibliotecas
LDFLAGS = -lm

FONTESCOMP = Compacta.c TadArvore.c TadLista.c TadTabela.c TadPilha.c TadBitmap.c Escrita.c Leitura.c
FONTESDESCMP = Descompacta.c TadArvore.c TadLista.c TadTabela.c TadPilha.c TadBitmap.c Escrita.c Leitura.c

OBJETOSCOMP = $(FONTESCOMP:.c=.o)
OBJETOSDESCMP = $(FONTESDESCMP:.c=.o)

# Nome do arquivo executável
EXECUTAVELCOMP = ted1_2comp
EXECUTAVELDESCMP = ted1_2descmp

all-comp: $(EXECUTAVELCOMP)

$(EXECUTAVELCOMP): $(OBJETOSCOMP)
	$(CC) -o $@ $^ $(LDFLAGS)

all-descmp: $(EXECUTAVELDESCMP)

$(EXECUTAVELDESCMP): $(OBJETOSDESCMP)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o

rmproper: clean
	rm -rf $(EXECUTAVELCOMP)
	rm -rf $(EXECUTAVELDESCMP)

run-comp: $(EXECUTAVELCOMP)
	./$(EXECUTAVELCOMP) $(ENTRADACOMP)

run-descmp: $(EXECUTAVELDESCMP)
	./$(EXECUTAVELDESCMP) $(ENTRADADESCMP)

run-comp-val: $(EXECUTAVELCOMP)
	valgrind --track-origins=yes ./$(EXECUTAVELCOMP) $(ENTRADACOMP)

run-descmp-val: $(EXECUTAVELDESCMP)
	valgrind --track-origins=yes ./$(EXECUTAVELDESCMP) $(ENTRADADESCMP)
