#include <iostream>
#include "Fatorial.h"
#include "Introducao.h"

using namespace std;

/*Lê um numero inteiro, calcula e exibe o fatorial desse número.
* Retorna o valor do fatorial ou - 1 se a operação for cancelada.
*/
int Fatorial::fatorial()
{	
	Introducao introducao;
	int numeroPositivo = 0, fatorial = -1; // Cria (instancia) um objeto da classe introducao.

	while (numeroPositivo != -1) {
	
		numeroPositivo = introducao.operacao("Fatorial", "Número positivo = ");
		if (numeroPositivo != -1) {
			/*
			* O this é um ponteiro que aponta para um objeto da classe Fatorial
			* e é usado abaixo para invocar o método fatorial(int).
			-- Basicamente quando há uma variável local (por ex) que tenha o mesmo nome de um método,
			-- deve-se especificar quem é quem por meio do this
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
