#include <stdio.h>	//printf() e scanf()
#include <stdlib.h>	//atoi()
#include <string.h> //strlen()
#include <math.h>	//pow()

int Verify (int k, char *n); //Verifica se o numero esta dentro da base
int BtoInt (char *b, int base); //recebe um vetor de caracteres, a base dele e o converte para um numero na base 10.
int Conve(char n); //converte o caractere recebido no respectivo inteiro
int Reconve(int num);//converte o inteiro recebido no respectivo caractere
void TentoK (int n, int k, char resultado[128]); //recebe o numero inteiro na base 10, a base para a qual converter o numero e o endereço de memoria onde deve montar o numero convertido

int main(){
	int b, k, num, base_ten;
	char n[128], result[128]; 
	
	//le os dados de entrada indefinidas vezes, ate que o numero esteja na base inicial fornecida
	do{
		printf ("Informe o numero seguido da base atual e da base desejada, separados por espaco (Ex.: 150 10 2):  ");
		scanf ("%s %d %d", n, &b, &k);
	} while (Verify (b, n) == 1);
	
	if (b == k)	//caso a conversao nao faca sentindo
		printf ("\nResultado: %s", n);
	else {
		if (b != 10) //caso o numero fornecido nao esteja na base 10, ele eh convertido para a mesma e tranformado em um inteiro
			base_ten = BtoInt(n, b);
		else {
			base_ten = atoi(n); //caso esteja na base 10, o numero eh convertido para inteiro diretamente
		}
		
		if (k == 10)//caso a base desejada seja a 10, o resultado ja esta pronto
			printf ("\nResultado %d", base_ten);
		else {//caso a base desejada nao seja a 10, ele eh convertido
			TentoK (base_ten, k, result);
			printf ("\nResultado %s", result);
		}
	}
	
	return 0;
}

int BtoInt (char *num, int base) {
	int resp = 0, i;
	// percorre o vetor fazendo o somatorio da segunte formula: numero * base elevado a posicao
	for (i=0; i < strlen(num); i++) 
		resp += (Conve(*(num+i)) * pow(base,(strlen(num)-i-1)));
	return resp;
}

int Conve(char letra){
	int num;
	switch(letra){
			case 'A': num= 10; break;
			case 'B': num = 11; break;
			case 'C': num = 12; break;
			case 'D': num = 13; break;
			case 'E': num = 14; break;
			case 'F': num = 15; break;
			default:  num = letra - '0';  //convertendo para Integer
		}
	return (num);
}

int Reconve(int num){
	char letra;
	switch(num){
			case 10: letra='A' ; break;
			case 11: letra ='B' ; break;
			case 12: letra ='C' ; break;
			case 13: letra ='D' ; break;
			case 14: letra ='E' ; break;
			case 15: letra ='F' ; break;
			default:  letra = num+'0';  	//convertendo para char
		}
	return (letra);
}

int Verify(int a, char *num){
	for(int i = 0; i < strlen(num); i++){
		if(Conve(num[i]) >= a){//utiliza a funcao Conve para converter os caracteres de base acima de 10
			printf("O numero %s nao pertence a base %d\n", num, a);
			return 1;
		}
	}
	return 0;
}

void TentoK(int n, int k, char *resultado){
	int invertida[128];
	int i=0, j;
	while (n != 0){     //metodo das multiplas divisoes
		invertida[i] = (n % k);
		n = (n / k);
		i++;
	}
	resultado[i] = '\0';    //marca o limite do vetor final
	for (j=0; i>0; j++, i--){    //inverte o vetor que vem ao contrario pelo metodo acima
		resultado[j] = Reconve(invertida[i-1]);
	}
}