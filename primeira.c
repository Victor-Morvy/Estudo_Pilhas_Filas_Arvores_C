#include <stdio.h>


void msg(char txt[50]){
	printf(txt);
	getch();
}

void cadastrarDados(int n){
	FILE* arquivo;
	arquivo = fopen("dados.txt", "a");
	
	fprintf(arquivo, "%d\n", n);
	printf("Cadastrado com sucesso!\n");
	
	fclose(arquivo);
	
}

//////BUGADO//////////
void lerDados(){
	
	FILE* arquivo;
	int n;
	
	arquivo = fopen("dados.txt", "r");
	
	while(!feof(arquivo)){
		fscanf(arquivo, "%d\n", &n);
		printf("%d\n", n);
	}
	
	fclose(arquivo);
	
}

void limparDados(){
	
	FILE * arquivo;
	
	arquivo = fopen("dados.txt", "w");
	fclose(arquivo);
	msg("\nOs dados foram limpos!\n");
	
	
	
}


int main(){

	int opc;
	
	while(opc != 4){
		
		system("cls");
		
		fflush(stdin);
		
		printf("1- Cadastrar um numero\n");
		printf("2- Listar numeros cadastrados\n");
		printf("3- Limpar numeros cadastrados\n");
		printf("4- Sair\n");
		
		scanf("%d", &opc);
		fflush(stdin);
		
		switch(opc){
			int n;
			case 1: 
				printf("Informe um numero inteiro: ");
				scanf("%d", &n);
				
				cadastrarDados(n);
				break;
			case 2:
				printf("Numeros listados: \n");
				lerDados();
				break;
			case 3:
				limparDados();
				break;
			case 4:
			default: msg("Opcao invalida");
			break;
		}
		
		
		system("pause");
	}
	
	return 0;
	
}


/*


	}while(!feof(arquivo));

	fclose(arquivo);
	
	printf("\n\n");
	system("pause");
	


arquivo = fopen("carros.txt", "r");
	
	do{
		fscanf(arquivo, "%s %f\n", placa, &kilometragem);
		printf("A kilometragem da placa %s e %f\n", placa, kilometragem);

	}while(!feof(arquivo));

	fclose(arquivo);
*/
