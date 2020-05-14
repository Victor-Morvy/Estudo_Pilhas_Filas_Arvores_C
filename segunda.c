#include <windows.h>
#include <stdio.h>
#include "no.c"
#include "arvores.c"
#include "arvoresbinarias.c"
#include "filas.c"
#include "pilhas.c"

no * alimentaPilha(){
	
	FILE* arquivo;
	int n;
	no *pilha = NULL;
	
	arquivo = fopen("dados.txt", "r");
	
	while(!feof(arquivo)){
		fscanf(arquivo, "%d\n", &n);
		
		///alimenta a pilha
		push(&pilha, n);	
	}
	
	fclose(arquivo);
	return pilha;
}

no * alimentaFila(){
	FILE* arquivo;
	int n;
	no *fila = NULL;
	
	arquivo = fopen("dados.txt", "r");
	
	while(!feof(arquivo)){
		fscanf(arquivo, "%d\n", &n);
		
		///alimenta a pilha
		qinsert(&fila, n);	
	}
	
	fclose(arquivo);
	return fila;
}

nodetree * alimentaArvoreBinaria(){
	FILE * arquivo;
	int n;
	nodetree * arvore = NULL;
	
	arquivo = fopen("dados.txt", "r");
	
	while(!feof(arquivo)){
		fscanf(arquivo, "%d\n", &n);
		
		///alimenta a pilha
		insert_binary_tree(arvore, n);	
	}
	
	fclose(arquivo);
	return arvore;
}

int main(){
	
	int pilhaAlimenta, pilhaPercorre, filaAlimenta, filaPercorre, arvoreAlimenta;
	int arvoreOrdem, arvorePreOrdem, arvorePosOrdem;
	int loop = 1;
	
	//manipulando tabela
	FILE *tabela;
	
	int tentativas = 0;
	
	no * pilha;
	no * fila;
	nodetree * arvore;
	
	LARGE_INTEGER tempoInicial, tempoFinal;
	int tempo;
	
	//inserindo primeiros dados na tabela
	tabela = fopen("dados.xml", "w");
	fprintf(tabela, "%s", "<?xml version=\"1.0\"?> \n <tabela> \n");
	fclose(tabela);
	
	while(loop <= 10){
	
		////////////PILHA//////////////
		printf("--PILHA--\n");
		//Alimenta
		QueryPerformanceCounter(&tempoInicial);
		
		pilha = alimentaPilha();
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("Tempo gasto para alimentar pilha: %i\n", tempo);
		pilhaAlimenta = tempo;
		
		//Leitura
		QueryPerformanceCounter(&tempoInicial);
		
		percorrer_pilha(&pilha);
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("\nTempo gasto para percorrer pilha: %i\n", tempo);
		pilhaPercorre = tempo;
	
		////////////FILA//////////////
		printf("\n--FILA--\n");
		//Alimenta
		QueryPerformanceCounter(&tempoInicial);
		
		fila = alimentaFila();
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("\nTempo gasto para alimentar a fila: %i\n", tempo);
		filaAlimenta = tempo;
		
		//Leitura
		QueryPerformanceCounter(&tempoInicial);
		
		percorrer_fila(&fila);
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("\nTempo gasto para percorrer a fila: %i\n", tempo);
		filaPercorre = tempo;
		
		////////////Arvore//////////////
		printf("\n--Arvore Binaria--\n");
		//Alimenta
		QueryPerformanceCounter(&tempoInicial);
		
		arvore = alimentaArvoreBinaria();
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("Tempo gasto para alimentar a Arvore Binaria: %i\n", tempo);
		arvoreAlimenta = tempo;
	
		//percorreOrdem
		QueryPerformanceCounter(&tempoInicial);
		
		percorrer_ordem(&arvore);
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("Tempo gasto para percorrer ordem arvore binaria: %i\n", tempo);
		arvoreOrdem = tempo;
		
		//preOrdem
		QueryPerformanceCounter(&tempoInicial);
		
		percorrer_preordem(&arvore);
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("Tempo gasto para percorrer pre ordem arvore binaria: %i\n", tempo);
		arvorePreOrdem = tempo;
		
		//posOrdem
		QueryPerformanceCounter(&tempoInicial);
		
		percorrer_posordem(&arvore);
		
		QueryPerformanceCounter(&tempoFinal);
		
		tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf("Tempo gasto para percorrer pos ordem arvore binaria: %i\n", tempo);
		arvorePosOrdem = tempo;
		
		//DADOS PARA PESQUISA///////////////////
		
		
		
		printf("--PILHA--\n");
		printf("Tempo para alimentar pilha: %i\n", pilhaAlimenta);
		printf("Tempo para percorrer pilha: %i\n", pilhaPercorre);
		
		printf("\n--FILA--\n");
		printf("Tempo para alimentar fila: %i\n", filaAlimenta);
		printf("Tempo para percorrer fila: %i\n", filaPercorre);
		
		printf("\n--ARVORE BINARIA--\n");
		printf("Tempo para alimentar arvore: %i\n", arvoreAlimenta);
		printf("Tempo para percorrer ordem: %i\n", arvoreOrdem);
		printf("Tempo para percorrer pre ordem: %i\n", arvorePreOrdem);
		printf("Tempo para percorrer pos ordem: %i\n", arvorePosOrdem);
	
	/////MANIPULANDO DADOS XML////
	
	
	tabela = fopen("dados.xml", "a");
	fprintf(tabela, "\n    <teste id='%d'>\n", loop);
	
	fprintf(tabela, "        <pilha_alimenta>%d</pilha_alimenta>\n        <fila_alimenta>%d</fila_alimenta>\n        <arvore_alimenta>%d</arvore_alimenta>\n        <pilha_percorre>%d</pilha_percorre>\n        <fila_percorre>%d</fila_percorre>\n        <arvore_ordem>%d</arvore_ordem>\n        <arvore_preordem>%d</arvore_preordem>\n        <arvore_posordem>%d</arvore_posordem>", pilhaAlimenta, filaAlimenta, arvoreAlimenta, pilhaPercorre, filaPercorre, arvoreOrdem, arvorePreOrdem, arvorePosOrdem);
		
	
	fprintf(tabela, "%s", "\n</teste>", loop);
	fclose(tabela);
	
		
		loop++;
	}
	
	tabela = fopen("dados.xml", "a");
	fprintf(tabela, "%s", "\n    </tabela>");
	fclose(tabela);
	
	system("cls");
	printf("O arquivo dados.xml foi alimentado.");
	
	return 0;
}












