#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	FILE * arquivo;
	
	srand(time(NULL));
	
	arquivo = fopen("dados.txt", "w");
	
	int i = 0;
	
	while(i <= 500){
		
		fprintf(arquivo, "%d\n", rand() % 100000);
		i++;
	}
	
	printf("Foram gerado os dados no arquivo dados.txt");
	
	fclose(arquivo);
	
	return 0;
}


