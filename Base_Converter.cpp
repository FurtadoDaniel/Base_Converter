#include <stdio.h>
#include <stdlib.h>
#include <String.h>

int AjustaHexa(char letra){
	int num;
	switch(letra){
			case 'A': num= 10; break;
			case 'B': num = 11; break;
			case 'C': num = 12; break;
			case 'D': num = 13; break;
			case 'E': num = 14; break;
			case 'F': num = 15; break;
			default:  num = (int)(letra);  //convertendo para Inteiro
		}
	return (num);
}

int *ToInt (char *vet, int len){
	int *num=(int*)calloc(len, sizeof(int));// aloca um espaço de memoria para o array, explicação sobre a necessidade dele existir no final do prog.
	for(int i = 0; i < len; i++){
		*(num+i) = AjustaHexa (*(vet+i));
	}
	return (num);
}

int verify(char num[10], int a){/*Em testes não estva funcionando, Ai do metodo antigo funcionou??*/
	for(int i = 0; i < strlen(num)-1; i++){
		if(AjustaHexa(num[i]) > a){
			printf("O numero %s nao pertence a base %d", num, a);
			return 1;
		}
	}
	return 0;
}


int main(){
	int a, b;//a base incial, b base final
	int Base_Dez;//armazena o numero em na base dez
	char num[10];//armazena o numero em vetor na base inicial
	int *x;//será apgada em versões futuras
	do{
		printf("Informe a base do numero:");
		scanf("%d%*c",&a);
		printf("Informe o numero:");
		gets(num); 
		printf("\nInforme a base que deseja:");
		scanf("%d%*c",&b);
	} while(verify(num,a)==1);
	x=ToInt(num,strlen(num));//converte as strings em inteiros
	for(int i = 0; i < strlen(num); i++){
		printf("%d", *(x+i));
	}
	free (x);//libera o espaço alocado na na função ajustaHexa
	getchar();
	return 0;
	
}

// Qnd uma função termina sua execução todos os espações alocados por ela são liberados, então o compilador reclama vc passar um espaço de memoria que deveria ser desalocado, por isso o usa da função calloc