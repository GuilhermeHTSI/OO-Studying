#include <iostream>
#include "Fatorial.h"

using namespace std;



// Lê um numero inteiro, calcula e exibe o fatorial desse número. Retorna o valor do fatorial.
int Fatorial::fatorial()
{	
	int numero, fatorial;
	cout << "Número inteiro positivo:";
	cin >> numero;

	/*
	* O this é um ponteiro que aponta para um objeto da classe Fatorial 
	* e é usado abaixo para invocar o método fatorial(int).
	-- Basicamente quando há uma variável local (por ex) que tenha o mesmo nome de um método, 
	-- deve-se especificar quem é quem por meio do this
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
