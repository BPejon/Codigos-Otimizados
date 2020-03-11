#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **aloca_matriz(int linha, int coluna){
	int **matriz = malloc(sizeof(int*) * linha);

	for(int i = 0; i<linha; ++i){
		matriz[i] = malloc(sizeof(int*)*coluna);
	}

	return matriz;

}

/*Gera matriz rand criando uma matriz auxiliar
//Acho que gasta mais poder computacional, pois necessita alocar dinamicamente uma matriz auxiliar, sendo que isso poderia ser pulado apenas utilizando a matriz já criada 
//Deixei esse código para comparar com o outro
int **gera_matriz_rand(int linha, int coluna){
	int **matriz[linha][coluna];
	srand(time(NULL));

		for(int i =0; i<linha ;++i){
			for(int j=0; j<coluna; ++j)
				matriz[i][j] = rand() % 100;
		}

	return matriz;

}
*/

void gera_matriz_rand(int **matriz, int linha, int coluna){
	srand(time(NULL));

		for(int i =0; i<linha ;++i){
			for(int j=0; j<coluna; ++j)
				matriz[i][j] = rand() % 100;
		}


}

// Faz a multiplicação de matrizes com o método usual 3 fors e vai
// (int matrizfinal, int matriz 1, int matriz 2)
void multiplica_matrizes(int **matrizmult, int **matriz1, int **matriz2, int linha, int coluna){

	//verificar se linha e coluna são identicas
	if(coluna != linha){
		printf("Linha e Coluna diferentes!! Vá consertar\n");
		return;
	}

	//Aloca um inteiro auxiliar. Aloquei dinamicamente apenas para teste
	int *aux = malloc(sizeof(int*));	//Armazena o numero intermediario entre as operações de multiplicação de matrizes
									//isto é, ao multiplicar um elemento com outro, armazena o valor nessa variavel,
									//quando todas as multiplicações fores feitas, ela será inseria na matriz
									//ACHO que gasta menos'poder computacionar do que um for() que zeraria a matriz 
	aux = 0; //posso fazer isso?

	for(int i=0; i<linha ; ++i){
		for(int j=0; j<coluna; ++j){	//deveria ser coluna da matriz 1
			for(int k=0; k< coluna; ++k){//deveria ser coluna da matriz 2
				aux += matriz1[i][k] * matriz2[k][j];
			}
			matrizmult[i][j] = *aux;
			aux = 0;		//zerar o auxiliar para recomeçar a multiplicação
		
		}
	}

	free(aux);

}

void desaloca_matriz(int **matriz, int linha){
	//desaloca linhas
	for(int i =0; i<linha; ++i)
		free(matriz[i]);
	//desaloca matriz
	free(matriz);
}


void print_matriz(int **matriz, int linha, int coluna ){
	for(int i =0; i<linha; ++i){
		for(int j=0 ; j<coluna; ++j)
			printf("%d", matriz[i][j]);
	}

}

int main (){
	//mesma linha e coluna para ambas as matrizes
	int linha, coluna;
	scanf("%d %d", &linha, &coluna);

	//cria matriz 1 e coloca numeros aleaorios
	int **matriz1 = aloca_matriz(linha, coluna);
	gera_matriz_rand(matriz1,linha, coluna);

	//cria matriz 2 e coloca numeros aleatorios
	int **matriz2 = aloca_matriz(linha, coluna);
	gera_matriz_rand(matriz2, linha, coluna);					

	//Multiplicação de matrizes
	int **matrizmultiplicada = aloca_matriz( linha, coluna);
	multiplica_matrizes(matrizmultiplicada,matriz1, matriz2, linha, coluna);


	desaloca_matriz(matriz1,linha);
	desaloca_matriz(matriz2, linha);
	desaloca_matriz(matrizmultiplicada, linha);


	return 0;
}