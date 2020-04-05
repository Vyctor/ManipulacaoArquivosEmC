# Exemplo de manipulação de Arquivos em C

## Descrição do Trabalho Prático

### Implementar um programa em C que faça:

1. leitura de um arquivo de texto com as informações de entrada do problema.
2. O arquivo será dado pelo professor;
   
3. processamento dos dados lidos(as instruções de processamento estão nas definições dos grupos);
   
4. gravação de um arquivo de texto com os resultados encontrados;


5. cada etapa do programa tem que ser uma função;


### O arquivo de entrada tem quatro colunas
```c
codigo - int
nomeProduto - string
quandide - int
preco - float
```


### O arquivo de saída terá cinco colunas
```
codigo - int
nomeProduto - string
quantidade - int
preço - float
precoTotal - float (quantidade*preço);
```


### Definições:

  1. colocar os preços em ordem cresente.
  2. utilizar o algoritmo de ordenação Selection sort.
  3. explicar na apresentação o funcionamento do algoritmo de ordenação.   
  4. gravar no arquivo de saída os 100 produtos mais baratos.