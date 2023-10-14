CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC_DIR = ./
OBJ_DIR = ./obj
INP_DIR = input

all: $(OBJ_DIR)/pert

$(OBJ_DIR)/pert: $(SRC_DIR)/pert.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

rodar_programa: $(OBJ_DIR)/pert
	./$^ < $(INP_DIR)/teste.txt

rodar_programa_saida_arquivo: $(OBJ_DIR)/pert
	./$^ < $(INP_DIR)/teste.txt > output/out.txt

clean:
	rm -f $(OBJ_DIR)/pert

.PHONY: all clean
