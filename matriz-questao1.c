#include<stdio.h>
#include<stdlib.h>

int linha = 0, coluna = 0;
int tamanho = 4; //tamanho min de um vetor para uma matriz 2x2.

void zerar(int vetor[tamanho]) {
	int k;
	for(k=0;k<tamanho;k++) {
		vetor[k] = 0;
	}
}

void inserir(int valor, int vetor[tamanho], int i, int j, int n) {
	int k = i*n + j; // i,j e n significam: posicao da linha, da coluna e número de colunas, respectivamente.
	vetor[k] = valor;
}

int buscar(int valor, int vetor[tamanho]) {
	int k;
	for(k=0;k<tamanho;k++) {
		if(vetor[k]==valor) {
			return k;
		}
	}
	return -1;
}

void remover(int valor, int vetor[tamanho]) {
	int k = buscar(valor,vetor);
	if(k!=-1) {
		vetor[k] = 0;
	}
	else {
		printf("\nO valor %d nao esta armazenado na matriz!!\n",valor);
		system("pause");
	}
}

void imprimir(int vetor[tamanho]) {
	int i,j;
	for(i=0;i<linha;i++) {
		for(j=0;j<coluna;j++) {
			int k = i*coluna + j;
			printf("%d ", vetor[k]);
		}
		printf("\n");
	}
}

// Calculando matriz transposta (questão 3)

void transposta(int vetor[tamanho]) {
	int i,j;
	for(i=0;i<linha;i++) {
		for(j=0;j<coluna;j++) {
			int k = j*coluna + i;
			printf("%d ", vetor[k]);
		}
		printf("\n");
	}
}

void preencher(int vetor[tamanho]) {
	printf("\nPREENCHENDO MATRIZ %d X %d\n\n",linha,coluna);
	int i,j;
	for(i=0;i<linha;i++) {
		for(j=0;j<coluna;j++) {
			int k = i*coluna + j;
			printf("linha: %d - coluna: %d:    ",i,j);
			scanf("%d",&vetor[k]);
		}
		printf("\n");
	}
}

void menu(int opcao, int matriz[tamanho]) {
	switch(opcao) {
		case 1: {
			system("cls"); //limpa a tela.
			int valor;
			int i,j;
			printf("Informe o valor a ser inserido na matriz:     ");
			scanf("%d",&valor);
			printf("\nInforme a linha e a coluna da matriz, respectivamente:     \n");
			scanf("%d %d",&i,&j);
			
			if(i>linha || j>coluna) {
				printf("\n\nPosicao invalida!!\n");
				system("pause");
				break;
			}
			else {
				inserir(valor,matriz,i,j,coluna);
				printf("\n%d foi inserido com sucesso na matriz!!\n\n",valor);
				system("pause");
				break;
			}
		}
		case 2: {
			system("cls");
			int valor;
			printf("Informe o valor a ser removido da matriz:     ");
			scanf("%d",&valor);
			
			remover(valor,matriz);
			break;
		}
		case 3: {
			system("cls");
			imprimir(matriz);
			system("pause\n\n");
			break;
		}
		case 4: {
			system("cls");
			int valor;
			printf("Informe o valor a ser buscado na matriz:     ");
			scanf("%d",&valor);
			
			int resultado = buscar(valor,matriz);
			if(resultado!=-1) {
				/*printf("\n%d esta armazenado na posicao %d !\n\n",valor,resultado);
				system("pause");*/
				
				int i,j;
				for(i=0;i<linha;i++) {
					for(j=0;j<coluna;j++) {
						int aux = i*coluna + j;
						if(aux==resultado) {
							printf("\n%d esta armazenado na linha %d e coluna %d da matriz!\n\n",valor,i,j);
							system("pause");
						}
					}
				}
			}
			else {
				printf("\n%d nao esta armazenado na matriz!!\n\n",valor);
				system("pause");
			}
			break;
		}
		case 5: {
			system("cls");
			transposta(matriz);
			system("pause\n\n");
			break;
		}
		case 0: break;
		default: {
			printf("\nOPCAO INVALIDA!!\n\n");
			system("pause");
		}
	}
}

main() {
	printf("Informe o numero de linhas e de colunas da matriz, respectivamente:     ");
	scanf("%d %d",&linha,&coluna);
	
	if(linha<2 || coluna <2) {
		printf("\nValor invalido!!\n");
	}
	else {
		tamanho = linha*coluna;
		int matriz[tamanho];
		zerar(matriz);
		preencher(matriz);
	
		int opcao = 1;
		while(opcao) {	
			system("cls");
			printf("=============== DIGITE O NUMERO QUE CORRESPONDE A OPCAO DESEJADA ===============\n\n");
			printf("1. Inserir valor na matriz\n\n");
			printf("2. Remover valor da matriz\n\n");
			printf("3. Imprimir matriz\n\n");
			printf("4. Buscar valor na Matriz\n\n");
			printf("5. Exibir matriz transposta\n\n");
			printf("\n0. Sair\n\n");

			scanf("%d",&opcao);
			menu(opcao,matriz);
		}
	}
}
