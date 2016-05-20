#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //nao sei se essa biblioteca eh necessaria mesmo, da um confere aí

int verify (int k, char *n); //recebe a base original e o endereço da primeira posicao do numero
int toInt (char n); //recebe a primeira posicao do numero
int adaptHex (char n); //trabalha junto com toInt() para adatar os valores dos numeros hexadecimais, recebendo o valor q deve converter
int kToTen (int k, int *n); //recebe a base original do numero e a primeira posicao do do vetor gerado com toInt()
void tenToK (int n, int k); //recebe o numero inteiro gerado com kToTen() e a base para a qual converter o numero

int main(){
	int b, k, num[], base_ten;
	char n[128]; //coloquei 128 pq eh o tamanho da maior palavra em binario, mas se quiser mudar o tamanho, pode
	do{
		printf ("Informe o numero seguido da base atual e da base desejada, separados por espaço (Ex.: 150 10 2):  ");
		scanf ("%s %d %d", n, &b, &k);
	} while (verify (k, n) == 1);
	if (b == k)
		printf ("\nResultado: %s", n);
	else if (b != 10){
		int i = 0;
		while (n[i] != '\0'){
			num[i] = toInt (n[i]);
			i++;
		}
		base_ten = kToTen (k, num, strlen (n));
	}
	else {
		//faça aqui um código q pegue o numero char n, que vai estar na base int b == 10, para um int base_ten de mesmo valor
	}
	if (k == 10)
		printf ("\nResultado %d", base_ten);
	else {
		printf ("Resultado: ");
		tenToK (int n, int k);
		//Insira um codigo para exibir o resultado
		//O resultado em hexadecial pode ser exibido usando %x, mas eu não sei se vai funcionar, ou transformando o resultado em char novamente.
	}
	return 0;
}

int kToTen (int k, int *n, int tam){
	int num = 0, i;
	for (i = 0; i < tam; i++, n++)
		num += *n * pow (k, i);
	return num;
}

void tenToK (int n, int k){
	tenToK (n / k);
	if (k == 10){
		switch (n % k){
			case 10: printf ("a"); break;
			case 11: printf ("b"); break;
			case 12: printf ("c"); break;
			case 13: printf ("d"); break;
			case 14: printf ("e"); break;
			case 15: printf ("f"); break;
		}
	}
	else
		printf ("%d", n % k);
}

int verify (int k, char *n){
	char asc;
	switch (k){
		case 2: asc = '1'; break;
		case 5: asc = '4'; break;
		case 8: asc = '7'; break;
		case 10: asc = '9'; break;
		case 16: asc = 'f'; break;
	}
	while (*n != '\0'){
		if (tolower (*n) > asc)
			return 1;
		*n++;
	}
	return 0;
}