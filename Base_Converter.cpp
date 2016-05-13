#include <stdio.h>
#include <stdlib.h>
#include <String.h>

/*void ajusteHexa(char num[10], int aux[10]){
	for(int i = 0; i < strlen(num)-1; i++){
		switch(num[i]){
			case 'A': aux[i] = 10; break;
			case 'B': aux[i] = 11; break;
			case 'C': aux[i] = 12; break;
			case 'D': aux[i] = 13; break;
			case 'E': aux[i] = 14; break;
			case 'F': aux[i] = 15; break;
			default: aux[i] = atoi(num[i]); break; //convertendo para Inteiro e invertendo
		}
	}
	return;
}
*/
int verify(char num[10], int a){
	for(int i = 0; i < strlen(num)-1; i++){
		if(num[i] > a + 0x30){
			printf("O numero %s nao pertence a base %d", num, a);
			return 1;
		}
	}
	return 0;
}

int main(){
	int a, b;//a base incial, b base final
	int i = 0; //contador
	char num[10];//numero
	int aux[10];//auxiliar para a inversão
	do{
		printf("Informe a base do numero:");
		scanf("%d*C",&a);
		printf("Informe o numero:");
		gets(num); //o programa, por algum motivo, nao esta executando o terceiro scanf
		printf("\nInforme a base que deseja:");
		scanf("%d*C",&b);
	} while(verify(num,a) == 1);
	/* Para passarmos esse vetor de por parametros precisariamos alocar um espaçõ de memoria e passarmos um vetor
	para facilitar nossa vida faça a função aki 
	ps:o numero esta invertido para facilitar qnd for elevar para converter para decimal */
	
	
}