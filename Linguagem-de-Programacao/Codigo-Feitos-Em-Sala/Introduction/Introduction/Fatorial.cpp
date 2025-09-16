#include <iostream>
#include "Fatorial.h"
#include "Introducao.h"

using namespace std;

/*L� um numero inteiro, calcula e exibe o fatorial desse n�mero.
* Retorna o valor do fatorial ou - 1 se a opera��o for cancelada.
*/
int Fatorial::fatorial()
{	
	Introducao introducao;
	int numeroPositivo = 0, fatorial = -1; // Cria (instancia) um objeto da classe introducao.

	while (numeroPositivo != -1) {
	
		numeroPositivo = introducao.operacao("Fatorial", "N�mero positivo = ");
		if (numeroPositivo != -1) {
			/*
			* O this � um ponteiro que aponta para um objeto da classe Fatorial
			* e � usado abaixo para invocar o m�todo fatorial(int).
			-- Basicamente quando h� uma vari�vel local (por ex) que tenha o mesmo nome de um m�todo,
			-- deve-se especificar quem � quem por meio do this
			*/
			fatorial = this->fatorial(numeroPositivo);

			cout << "\n\tO fatorial de " << numeroPositivo << "=" << fatorial << endl;
			introducao.promptUniversal();
		}
	}
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
