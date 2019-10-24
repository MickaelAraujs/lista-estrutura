#include<stdio.h>

	#include<stdio.h>
#include<stdlib.h>

/* Essas variáveis precisam ser globais pq estão sendo usadas nos subprogramas */

int linhaA = 2, colunaA = 3;
int linhaB = 3, colunaB = 2;
int tamanhoA = 6; //tamanho min de um vetor para uma matriz 2x2.
int tamanhoB = 6;

void preencherA(float matrizA[tamanhoA]){
	printf("\nPREENCHENDO MATRIZA %d X %d\n\n",linhaA,colunaA);
	int l,c;
	for(l=0;l<linhaA;l++){
		for(c=0;c<colunaA;c++){
			int k = l*colunaA + c;
			printf("linha: %d - coluna: %d:",l,c);
			scanf("%f",&matrizA[k]);
		}
		printf("\n");
	}
}
void preencherB(float matrizB[tamanhoB]){
	printf("\nPREENCHENDO MATRIZB %d X %d\n\n",linhaB,colunaB);
	int l,c;
	for(l=0;l<linhaB;l++){
		for(c=0;c<colunaB;c++){
			int k = l*colunaB + c;
			printf("linha: %d - coluna: %d:",l,c);
			scanf("%f",&matrizB[k]);
		}
		printf("\n");
	}
}

void multiplicaMat(float matrizA[tamanhoA], float matrizB[tamanhoB]){
	int lA = 0; //linha de A
	int lB = 0; //linha de B
	float soma = 0; //variavel pra somar
	int cA; //coluna de A
	int cB = 0; //coluna de B
	int posA = 0; //posição de A
	int posB = 0; //posição de B
	//esses posA e posB são para a conta não ir diretamente dentro da conta, são para pegar logo a posição de A e de B
	for(cA=0; cA<tamanhoA/2; cA++){ //esse for é para pegar o primeiro termo
		posA = lA*colunaA + cA; //pegando a posição de A
		posB = lB*colunaB + cB; //pegando a posição de B
		soma = soma + (matrizA[posA])*(matrizB[posB]); // fazendo a soma dos valores
		lB = lB + 1; // incrementando a linha de B
	}
	printf("%.2f ", soma);
	lA = 0;
	lB = 0; 
	cB = 1;
	soma = 0;
	for(cA=0; cA<tamanhoA/2; cA++){
		posA = lA*colunaA + cA;
		posB = lB*colunaB + cB;
		soma = soma + (matrizA[posA])*(matrizB[posB]);
		lB = lB + 1;
	}
	printf("%.2f \n", soma);
	lA = 1;
	lB = 0; 
	cB = 0;
	soma = 0;
	for(cA=0; cA<=tamanhoA/2; cA++){
		posA = lA*colunaA + cA;
		posB = lB*colunaB + cB;
		soma = soma + (matrizA[posA])*(matrizB[posB]);
		lB = lB + 1;
	}
	printf("%.2f ", soma);
	lA = 1;
	lB = 0; 
	cB = 1;
	soma = 0;
	for(cA=0; cA<=tamanhoA/2; cA++){
		posA = lA*colunaA + cA;
		posB = lB*colunaB + cB;
		soma = soma + (matrizA[posA])*(matrizB[posB]);
		lB = lB + 1;
	}
	printf("%.2f \n", soma);
}

main(){
	tamanhoA = linhaA*colunaA;
	tamanhoB = linhaB*colunaB;
	float matrizA[tamanhoA];
	float matrizB[tamanhoB];
	preencherA(matrizA);
	preencherB(matrizB);
		
	multiplicaMat(matrizA, matrizB);
}
