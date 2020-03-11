#include <stdlib.h>
#include <stdio.h>
#include<time.h>



int **aloca_matriz(int linha, int coluna){
	int **matriz = malloc(sizeof(int*)*linha);

	for (int i = 0; i < linha; ++i)
	{
		matriz[i] = malloc(sizeof(int)*coluna);
	}

	return matriz;
}

void desaloca_matriz(int linha, int **matriz){
	for (int i = 0; i < linha; ++i)
	{
		free(matriz[i]);
	}

	free(matriz);
}

void preenche_matriz(int linha, int coluna, int **matriz){
	for (int i = 0; i < linha; ++i){
		for (int j = 0; j < coluna; ++j){
			matriz[i][j] = rand()%10;
		}
	}
}

void printa_matriz(int linha, int coluna, int **matriz){
	for (int i = 0; i < linha; ++i){
		for (int j = 0; j < coluna; ++j){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int **multiplica_matriz(int **matriz1,int linha1, int coluna1, int **matriz2, int linha2, int coluna2 ){

	if(coluna1 != linha2) { 
		printf("Deu merda.\n");
		return NULL;
	}

	int **matriz_aux = aloca_matriz(linha1, coluna2);

	for (int i = 0; i < linha1; ++i){
		for (int k = 0; k < linha2; ++k){
			for (int j = 0; j < coluna1; ++j){
				matriz_aux[i][j] += matriz1[i][k] * matriz2[k][j];  
			}
		}
	}

	return matriz_aux;

}



int main (){
	int n1,m1, n2, m2;

	int **matriz1, **matriz2, **matriz3;

	scanf("%d %d", &n1, &m1);

	matriz1 = aloca_matriz(n1,m1);

	preenche_matriz(n1, m1, matriz1);

	scanf("%d %d", &n2, &m2);

	matriz2 = aloca_matriz(n2,m2);

	preenche_matriz(n2,m2, matriz2);

	matriz3 = multiplica_matriz(matriz1, n1,m1,matriz2,n2,m2 );

	// printa_matriz( n1,m2,matriz3);

	return 0;
}