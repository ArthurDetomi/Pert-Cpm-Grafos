# Documentação

## Depêndencias
Necessário ter instalado um compilador de linguagem C++ e o make.
- Distribuições Debian🐧
```shell
sudo apt install build-essential cmake
```
## Parte 1 - Compilação:

Para compilar o programa, navegue até o diretório atual onde se encontram os arquivos correspondentes do programa, usando o terminal. Agora, basta executar o seguinte comando:

```bash
make
``````
Isso irá compilar o programa.

## Parte 2 - Execução

Após compilar o programa, você pode executá-lo de duas maneiras diferentes:

### Opção 1:
Rode o seguinte comando, e a saída será impressa diretamente no terminal:

```bash
make rodar_programa
```
### Opção 2:

Você também pode executar o programa e salvar a saída em um arquivo no diretório "/output". Para fazer isso, execute o seguinte comando:

```bash
make rodar_programa_saida_arquivo
```


## Inserir Novos Testes

**O arquivo teste.txt está localizado na pasta "input/"**

Após inserir o grafo que deseja testar no arquivo "teste.txt", lembre-se de que o programa aceita apenas entradas no formato de números, como 1, 2 e 3. Separe os vértices por espaços, conforme exemplificado abaixo:
Cada cada linha do arquivo deve possuir três colunas: a primeira referente a um vértice que representa um evento que marca o início de uma atividade, a segunda referente a um vértice que representa um evento que marca o fim da atividade e a terceira referente à duração da atividade.

```txt
1 2 10
1 3 7
2 4 5
4 5 3
3 6 0
5 6 2
6 7 1
7 8 14
```

## Alguns testes e suas saídas esperadas
### Teste 1:
**Input :**
```txt
1 2 7
1 3 5
2 4 9
3 5 6
4 5 0
4 6 11
5 7 4
6 8 3
7 8 8
8 9 6
8 10 4
10 9 0
9 11 7
```
**Output:**
```txt
  Tempos mais cedo e mais tarde:
 vr  cedo  tarde
  1   0    0
  2   7    7
  3   5   12
  4  16   16
  5  16   18
  6  27   27
  7  20   22
  8  30   30
  9  36   36
 10  34   36
 11  43   43

Caminho Crítico:
1 -> 2 -> 4 -> 6 -> 8 -> 9 -> 11
```
### Teste 2:
**Input :**
```txt
1 2 10
1 3 7
2 4 5
4 5 3
3 6 0
5 6 2
6 7 1
7 8 14
```
**Output:**
```txt
  Tempos mais cedo e mais tarde:
 vr  cedo  tarde
  1   0    0
  2  10   10
  3   7   20
  4  15   15
  5  18   18
  6  20   20
  7  21   21
  8  35   35

Caminho Crítico:
1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8
```
### Teste 3:
**Input :**
```txt
1 2 7
1 3 5
1 4 7
2 5 3
3 6 5
4 6 8
4 7 4
6 7 7
5 8 7
7 8 4
```
**Output:**
```txt
  Tempos mais cedo e mais tarde:
 vr  cedo  tarde
  1   0    0
  2   7   16
  3   5   10
  4   7    7
  5  10   19
  6  15   15
  7  22   22
  8  26   26

Caminho Crítico:
1 -> 4 -> 6 -> 7 -> 8
```
