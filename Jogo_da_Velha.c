#include<stdio.h>
#include<stdlib.h>

const int TRUE = 1;
const int FALSE = 0;
const int ORDEM = 3;

void iniciar_jogo(char matriz[]) {
	int i,j;
	for(i=0;i<ORDEM;i++) {
		for(j=0;j<ORDEM;j++) {
			int k = i*ORDEM + j;
			matriz[k] = '\0';
		}
	}
}

int verificar_pos(int i, int j, char matriz[]) {
	int k = i*ORDEM + j;
	if(matriz[k]=='\0') {
		return TRUE;
	}
	return FALSE;
}

void inserir(char c, int i, int j, char matriz[]) {
	if(verificar_pos(i,j,matriz)==TRUE) {
		int k = i*ORDEM + j;
		matriz[k] = c;
	}
	else {
		printf("\nEssa posisao ja foi jogada!!\n\n");
	}
}

void imprimir(char matriz[]) {
	int i,j;
	for(i=0;i<ORDEM;i++) {
		for(j=0;j<ORDEM;j++) {
			int k = i*ORDEM + j;
			printf("  %c  ",matriz[k]);
		}
		printf("\n-----|----|----\n");
	}
}

char verificar_vencedor(char matriz[]) {
	int countX = 0, countO = 0;
	int i,j;
	//verificando linhas
	for(i=0;i<ORDEM;i++) {
		for(j=0;j<ORDEM;j++) {
			int k = i*ORDEM + j;
			if(matriz[k]=='X') {
				countX++;
			}
			else if(matriz[k]=='O') {
				countO++;
			}
		}
		if(countX==3) {
			return 'X';
		}
		else if(countO==3) {
			return 'O';
		}
		countX = 0;
		countO = 0;
	}
	//verificando colunas.
	for(i=0;i<ORDEM;i++) {
		for(j=0;j<ORDEM;j++) {
			int k = j*ORDEM + i;
			if(matriz[k]=='X') {
				countX++;
			}
			else if(matriz[k]=='O') {
				countO++;
			}
		}
		if(countX==3) {
			return 'X';
		}
		else if(countO==3) {
			return 'O';
		}
		countX = 0;
		countO = 0;
	}
	//percorrendo diagonal principal.
	for(i=0;i<ORDEM;i++) {
		int k = i*ORDEM + i;
		if(matriz[k]=='X') {
			countX++;
		}
		else if(matriz[k]=='O') {
			countO++;
		}
	}
	if(countX==3) {
		return 'X';
	}
	else if(countO==3) {
		return 'O';
	}
	countX = 0;
	countO = 0;
	
	//percorrendo diagonal secundária.
	for(i=0;i<ORDEM;i++) {
		int k = i*ORDEM + (ORDEM-1-i);
		if(matriz[k]=='X') {
			countX++;
		}
		else if(matriz[k]=='O') {
			countO++;
		}
	}
	if(countX==3) {
		return 'X';
	}
	else if(countO==3) {
		return 'O';
	}
		
	return '\0';
}

int empate(char matriz[]) {
	int i,j;
	for(i=0;i<ORDEM;i++) {
		for(j=0;j<ORDEM;j++) {
			int k = i*ORDEM + j;
			if(matriz[k]=='\0') {
				return FALSE;
			}
		}
	}
	return TRUE;
}

main() {
	char matriz[ORDEM*ORDEM];
	iniciar_jogo(matriz);
	imprimir(matriz);
	char vencedor = '\0';
	do {
		int linha,coluna;
		char c;
		
		printf("\nEscolha a linha e a coluna a ser jogada, respectivamente:\n\n");
		scanf("%d %d",&linha,&coluna);
		printf("\nDigite X ou O para inserir:\n\n");
		fflush(stdin);
		scanf("%c",&c);
		
		if(c!='X'&&c!='O') {
			system("cls");
			printf("\n\nCaractere invalido!!!\n");
		}
		else {
			system("cls");
			inserir(c,linha-1,coluna-1,matriz);
			fflush(stdin);
			vencedor = verificar_vencedor(matriz); //percorrer matriz pra saber se alguem ganhou
			fflush(stdin);
			if(vencedor!='\0') {
				printf("%c venceu !!\n\n",vencedor);
			}
			if(empate(matriz)==TRUE) {
				printf("Empate!!\n\n");
			}
		}
		imprimir(matriz);
	} while(vencedor=='\0'&&empate(matriz)==FALSE);
}
