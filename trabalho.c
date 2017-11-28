#include<stdio.h>
#include <string.h>

#define TAM 1000

//Declaração de variáveis globais
int codigo[TAM];
char produto[TAM][100];
int quantidade[TAM];
int preco[TAM];
float valorTotal[TAM];

// Corpo das funções
int leitura(char *nomeDoArquivo);
void printarVetores();
void selectionSort(int vetor[], int tamanho);
void gravarMenoresPrecos(char *nomeDoArquivo, int qtd);

int main(){    
    selectionSort(preco, leitura("produtos.csv")); // Função passada como parâmetro pois ela retorna o tamanho do vetor.
    printarVetores(); // Função que imprime os dados, nessa altura já ordenados
    gravarMenoresPrecos("maioresprecos.csv",100); // Função que grava os menores preços em um arquivo
    return 0;
}

int leitura(char *nomeDoArquivo){
    /*
    Nessa função eu declaro um ponteiro de arquivo, que vou utilizar para abrir o arquivo 
    com o nome que passei de parâmetro na função.
    Depois faço um teste para verificar se o arquivo existe.
    Após isso eu faço um laço que percorre o arquivo aberto até o final do arquivo (EOF/End of file)
    Tal laço percorre o arquivo armazenando seus dados em um vetor. Creio que exista algum problema no 
    arquivo .csv pois ele não está separado por ponto e vírgula (;) e sim por espaço.
    Aproveitei para fazer o cálculo do valor total (preço * qtd) e armazenei ele em um vetor
    Por fim eu retorno a quantidade de itens e fecho o arquivo para ediçaõ
    */
    FILE *arquivo;
    int x = 0;
    arquivo = fopen(nomeDoArquivo,"r"); // "r" significa que eu somente abrirei o arquivo para leitura (read)

    if(arquivo == NULL) return x;

    while(!feof(arquivo)){
        fscanf(arquivo,"%d  %s %d  %d\n",&codigo[x],produto[x],&quantidade[x],&preco[x]);
        valorTotal[x] = quantidade[x] * preco[x];
        x++;
    }
    return x;
    fclose(arquivo);
}

void selectionSort(int vetor[], int tamanho){
    /*
    Essa função implementa o algoritmo selection sort.
    A operação do algoritmo será discutida em sala. 
    A única peculiaridade é que como estamos trabalhando com uma planilha de múltiplos valores 
    o algoritmo irá ordenar somente o vetor que está armazenado o preço dos produtos. 
    Sendo assim eu também devo ordenar o resto dos produtos para que os preços não sejam linkados a 
    produtos diferentes.
    */

    int i,j,minimo;
    int auxCodigo, auxQuantidade, auxPreco;
    float valorTotalAux;
    char auxProduto[100];

    for(i=0;i<tamanho-1;i++){
        minimo = i;
        for(j=(i+1);j<tamanho;j++){
            if(vetor[j] < vetor[minimo]){
                minimo = j;
            }
            if(vetor[i]!=vetor[minimo]){ // Aqui eu faço o processo de ordenação, como estou ordenando vetor de 
                                         // tamanho eu preciso ordenar também os outros vetores
                                         // para corresponderem com os valores ordenados
                //Ordenando o valor
                auxPreco = vetor[i];
                vetor[i] = vetor[minimo];
                vetor[minimo] = auxPreco;
                //Ordenando o código do produto
                auxCodigo = codigo[i];
                codigo[i] = codigo[minimo];
                codigo[minimo] = auxCodigo;
                //Ordenando a quantidade do produto
                auxQuantidade = quantidade[i];
                quantidade[i] = quantidade[minimo];
                quantidade[minimo] = auxQuantidade;
                //Ordenando o nome do produto
                strcpy(auxProduto,produto[i]);
                strcpy(produto[i], produto[minimo]);
                strcpy(produto[minimo],auxProduto);  
                //Ordenando o valor total    
                valorTotalAux = valorTotal[i];
                valorTotal[i] = valorTotal[minimo];
                valorTotal[minimo] = valorTotalAux;          
            }
        }
    }

}

void printarVetores(){
    /*
    Essa função somente realiza a escrita na tela de todos os elementos da planilha, para demonstrar que a operação foi
    realizada corretamente.
    */
    int x=0;
    while(x < 1000){
        printf("Código: %d Produto: %s Quantidade: %d Preço:%d Valor Total: %.2f\n",codigo[x],produto[x],quantidade[x],preco[x], valorTotal[x]);
        x++;
    }

}

void gravarMenoresPrecos(char *nomeDoArquivo, int qtd){
    /*
    Essa função realiza a gravação dos produtos com menores preços de 0 até a quantidade passada por parâmetro na função.
    O procedimento é semelhante ao de leitura de arquivos.
    Eu crio um ponteiro de arquivo, que servirá pra dar o nome para o arquivo que armazenará os dados requeridos.
    Após isso com a função fopen e o parâmetro w+ eu crio o arquivo com o nome passado por parâmetro;
    Depois faço um laço que parte de x igual a 0 até a quantidade de produtos que desejo armazenar no arquivo.
    Utilizo a função fprintf para gravar os dados dos vetores no arquivo.
    Finalmente eu fecho o arquivo com a função fclose; 
    */
    FILE *arquivo;
    int x = 0;
    arquivo = fopen(nomeDoArquivo,"w+");

    while(x != qtd){
        fprintf(arquivo,"%d  %s  %d  %d %.2f\n",codigo[x],produto[x],quantidade[x],preco[x],valorTotal[x]);
        x++;
    }      
    fclose(arquivo);
}