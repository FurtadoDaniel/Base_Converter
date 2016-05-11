#include <stdio.h>
#include <String.h>

int main (){
	int a, b;//a base incial, b base final
	int i=0; //contador
	char num[10];//numero
	int aux[10];//auxiliar para a inversão
	printf("Informe a base do numero:");
	scanf("%d*C",&a);
	printf("Informe o numero:");
	gets(num);
	printf("Informe a base que deseja:");
	scanf("%d*C",&b);
	while(i<strlen(num)){
		switch (num[strlen(num)-i-1]){
			case 'A':aux[i]=10;break;
			case 'B':aux[i]=11;break;
			case 'C':aux[i]=12;break;
			case 'D':aux[i]=13;break;
			case 'E':aux[i]=14;break;
			case 'F':aux[i]=15;break;
			default:aux[i]=atoi(num[strlen(num)-i-1]);//convertendo para Inteiro e invertendobreak;
		}
		i++;
	}
	aux[i]='\0'
	/* Para passarmos esse vetor de por parametros precisariamos alocar um espaçõ de memoria e passarmos um vetor
	para facilitar nossa vida faça a função aki 
	ps:o numero esta invertido para facilitar qnd for elevar para converter para decimal */
	
	
}