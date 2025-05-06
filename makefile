# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic

# Diretório do código-fonte (passado como argumento)
DIR = $(folder)

# Encontra o primeiro arquivo .cpp dentro da pasta especificada
SRC = $(wildcard $(DIR)/*.cpp)

# Nome do executável (mesmo nome do arquivo sem extensão)
EXEC = $(DIR)/$(basename $(notdir $(SRC)))

# Regra padrão: mostrar erro se não passar a pasta
all:
	@echo "Uso: make run folder=<nome_da_pasta>"

# Regra para compilar o código dentro da pasta especificada
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar e executar
run: $(EXEC)
	./$(EXEC)

# Limpar arquivos gerados
clean:
	rm -f */*.o */*
