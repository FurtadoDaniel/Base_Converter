#include <stdio.h>
#include <stdlib.h>
#include <string.h> //nao sei se essa biblioteca eh necessaria mesmo, da um confere aí

int verify (int k, char *n); //recebe a base original e o endereço da primeira posicao do numero
int toInt (char n); //recebe a primeira posicao do numero
int adaptHex (char n); //trabalha junto com toInt() para adatar os valores dos numeros hexadecimais, recebendo o valor q deve converter
int kToTen (int k, int *n); //recebe a base original do numero e a primeira posicao do do vetor gerado com toInt()
int tenToK (int n, int k); //recebe o numero inteiro gerado com kToTen() e a base para a qual converter o numero

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
		base_ten = kToTen (k, num);
	}
	else {
		//faça aqui um código q pegue o numero char n, que vai estar na base int b == 10, para um int base_ten de mesmo valor
	}
	if (k == 10)
		printf ("\nResultado %d", base_ten);
	else {
		int result[]; //ou char result[];
		tenToK (base_ten, result);
		//Insira um codigo para exibir o resultado
		//O resultado em hexadecial pode ser exibido usando %x, mas eu não sei se vai funcionar, ou transformando o resultado em char novamente.
	}
}