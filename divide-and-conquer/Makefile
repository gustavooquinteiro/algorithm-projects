# Makefile do Trabalho de Estrutura de Dados e Algoritmos I - MATA40
# Simulação de Agência Bancária Otimizada utilizando conceito de árvore binária AVL
# Maiores detalhes do desenvolvimento, vide https://github.com/gustavooquinteiro/SearchBinaryTree

# Nome do projeto e do executável encontrado no diretório corrente após compilação
PROJ_NAME = SortTest

# Arquivos .c encontrados em src/
C_SOURCE = $(wildcard ./src/*.c)

# Arquivos .h encontrados em lib/
H_SOURCE = $(wildcard ./lib/*.h)

# Arquivos objetos .o encontrados em obj/ após compilação
OBJ = $(subst .c,.o,$(subst src,bin,$(C_SOURCE)))

# Compilador utilizado
CC = g++

# Flags utilizadas na compilação
CC_FLAGS = -c \
           -g \

           
OPT_FLAGS = -O3 \
	    -Ofast \
		
	
# Comando de construção de diretório
MKDIR = mkdir -p
						
# Comando de limpeza de alvos 
RM = rm -rf

GREEN=\033[0;32m
NC=\033[0m

# Regras de compilação
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ $(CC) $^ $(OPT_FLAGS) -o $@
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo " Binário construido: $@"

./bin/%.o: ./src/%.c ./lib/%.h
	@ $(CC) $< $(CC_FLAGS) -o $@
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo " Compilado $< em $@"

# Regra de criação de diretório para os objetos
objFolder:
	@ $(MKDIR) bin
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo ' Criado diretório para objetos' 

# Regra de limpeza de objetos e executável
clean:
	@ $(RM) bin $(PROJ_NAME) *~ test/$(PROJ_NAME) test/randomteste.*
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo ' Workspace limpo'
.PHONY: all clean
