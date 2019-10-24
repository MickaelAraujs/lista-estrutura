#include<stdio.h>
#include<stdlib.h>

const int TRUE = 1;
const int FALSE = 0;

int entrada(int tamanho, int tamanhoVet, int matriz[tamanhoVet], int linha){
	int k;
	int cont = 0;
	for(k=0; k<tamanho; k++){
		int posVet = linha*tamanho + k;
		if(k != linha){
			if(matriz[posVet] == 1){
				cont = cont + 1;
			}
		}
	}
	return cont;
}

int saida(int tamanho, int tamanhoVet, int matriz[tamanhoVet], int coluna){
	int k;
	int cont = 0;
	for(k=0; k<tamanho; k++){
		int posVet = k*tamanho + coluna;
		if(k != coluna){
			if(matriz[posVet] == 1){
				cont = cont + 1;
			}
		}
	}
	return cont;
}

void saidaUn(int tamanho, int tamanhoVet, int matriz[tamanhoVet], int coluna){
	int k;
	int cont = 0;
	for(k=0; k<tamanho; k++){
		int posVet = k*tamanho + coluna;
		if(k != coluna){
			if(matriz[posVet] == 1){
				printf("\nA cidade %d possui saida direta para a cidade %d", k, coluna);
			}
			else{
				printf("\nA cidade %d nao possui saida direta para a cidade %d", k, coluna);
			}
		}
	}
}

int entSaiVet(int tamanho, int tamanhoVet, int matriz[tamanhoVet], int tam, int vet[tam]){
	int k, x;
	int cont = 0;
	for(k=0; k<tam; k++){
		x = k + 1;
		int posVet = vet[k]*tamanho + vet[x];
		if(matriz[posVet] == 0){
			return FALSE;
		}
		cont++;
	}
	return TRUE;
}

main(){
	int tamanho;
	printf("Informe a ordem da matriz:");
	scanf("%d", &tamanho);
	int tamanhoVet = tamanho * tamanho;
	int matriz[tamanhoVet];
	int l, c;
	printf("\nInforme 0 ou 1 \n");
	for(l=0; l<tamanho; l++){
		for(c=0; c<tamanho; c++){
			int posVet = l*tamanho + c;
			printf("linha: %d - coluna: %d:",l,c);
			scanf("%d",&matriz[posVet]);
		}
	}
	printf("\nExistem cidades isoladas? \n");
	int cont = 0;
	for(l=0; l<tamanho; l++){
		int entra = entrada(tamanho, tamanhoVet, matriz, l);
		int sai = saida(tamanho, tamanhoVet, matriz, l);
		if(entra != 0 || sai != 0){
			printf("A cidade %d nao eh isolada\n", l);
		}
		else{
			printf("A cidade %d eh isolada\n", l);
		}
	}
	printf("\nCidades que nao ha saida mas ha entrada\n");
	int k;
	for(k=0; k<tamanho; k++){
		int entra = entrada(tamanho, tamanhoVet, matriz, k);
		int sai = saida(tamanho, tamanhoVet, matriz, k);
		if(entra == FALSE && sai != FALSE){
			printf("A cidade %d possui entrada mas nao possui saida\n", k);
		}
	}
	printf("\nCidades que nao ha entrada mas ha saida\n");
	for(k=0; k<tamanho; k++){
		int entra = entrada(tamanho, tamanhoVet, matriz, k);
		int sai = saida(tamanho, tamanhoVet, matriz, k);
		if(sai == FALSE && entra != FALSE){
			printf("A cidade %d possui saida mas nao possui entrada\n",k);
		}
	}
	printf("\nQual a cidade com o maior numero de estradas\n");
	int maiorNumEst = 0;
	int cidadeMaisEst = 0;
	for(k=0; k<tamanho; k++){
		int entra = entrada(tamanho, tamanhoVet, matriz, k);
		int sai = saida(tamanho, tamanhoVet, matriz, k);
		int totEst = entra + sai;
		if(totEst > maiorNumEst){
			cidadeMaisEst = k;
			maiorNumEst = totEst;
		}
	}
	printf("A cidade com mais estradas eh a cidade %d\n", cidadeMaisEst);
	int cidadeSaida;
	printf("\nInforme a cidade que deseja consultar as cidades que possuem saidas para ela:");
	scanf("%d", &cidadeSaida);
	if(cidadeSaida < tamanho){
		saidaUn(tamanho,tamanhoVet,matriz,cidadeSaida);
	}
	else{
		printf("Essa cidade nao existe\n");
	}
	int tam;
	printf("\nInforme o tamanho da sequencia:");
	scanf("%d", &tam);
	int vet[tam];
	printf("\nInforme uma cidade por vez\n");
	for(k=0; k<tam; k++){
		printf("Informe o numero da cidade:");
		scanf("%d", &vet[k]);
	}
	int seq = entSaiVet(tamanho, tamanhoVet, matriz, tam, vet);
	if(seq == FALSE){
		printf("Nao eh possivel fazer esse caminho entre as cidades");
	}
	else{
		printf("Eh possivel fazer esse caminho entre as cidades");
	}
}
