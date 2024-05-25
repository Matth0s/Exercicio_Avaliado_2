# Segundo Exercício Avaliado

## Autor:
  - Nome: Matheus Moreira do Nascimento
  - DRE: 119042060

## Introdução:

O programa calcula propriedades e realiza calculos em um Grafo lido de um
arquivo `.txt` ou `.csv`

## Requisitos Para Compilação:

Necessario compilador gcc, ferramenta make

**Comando para atualizar lista de pacotes:**
```sh
sudo apt-get update
```
**Comando para instalar gcc e make:**
```sh
sudo apt-get -y install build-essential
```
## Como Compilar e Executar:

**Comando para compilação:**
```sh
make
```

**Comando para execução:**
```sh
./main <arquivo contendo grafo>
```
## Formato do Arquivo:

O arquivo precisa conter os Vertices do Grafo e o Grau da Aresta que os liga
com a seguinte formatação:
- O Grau da Aresta precisa ser um valor comportado por um `double`
- O Grau da Aresta precisa ser maior que 0
- As casas decimais do Grau da Aresta são marcadas com `.`
- Cada linha deve conter exatamente 3 parametros, referentes a
**Vertice**, **Vertice** e **Grau_Aresta**
- Se a extensão do arquivo for `.txt`, o separador dos Vertices e Grau podem ser
**espaços** ou **tabs**
```txt
A       B 1.3
A C  7
Joao Maria 5.5
v3     v1  1657.4687
```
- Se a extensão do arquivo for `.csv`, o separador dos Vertices e Grau é a
**virgula**
```txt
A,B,1.3
A,C,7
Joao,Maria,5.5
v3,v1,1657.4687
```
## Como Utilizar:

O programa le um Grafo a partir de um arquivo passado pelo usuario como parametro
do executavel `main`

Ao iniciar o programa, um menu será exibido, apresentando as opções de interação
disponíveis, cada uma identificada por um código correspondente. Após a execução
de cada comando, é necessário pressionar a tecla `Enter` para prosseguir com a
interação.
