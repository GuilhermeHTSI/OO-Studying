#include <iostream>
#include "Fatorial.h"

using namespace std;



// L� um numero inteiro, calcula e exibe o fatorial desse n�mero. Retorna o valor do fatorial.
int Fatorial::fatorial()
{	
	int numero, fatorial;
	cout << "N�mero inteiro positivo:";
	cin >> numero;

	/*
	* O this � um ponteiro que aponta para um objeto da classe Fatorial 
	* e � usado abaixo para invocar o m�todo fatorial(int).
	-- Basicamente quando h� uma vari�vel local (por ex) que tenha o mesmo nome de um m�todo, 
	-- deve-se especificar quem � quem por meio do this
	*/ 
	fatorial = this->fatorial(numero);
	
	cout << "\nO fatorial de " << numero << "=" << fatorial << endl;
	return fatorial;
}

// Calcula o fatorial de um numero inteiro.
int Fatorial::fatorial(int numero)
{
	
	int fatorial = 1;
	for (int number = 1; number <= numero; number++)
		fatorial = fatorial * number;
	return fatorial;
}
