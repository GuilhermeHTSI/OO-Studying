#include <iostream> // Requerido pelo cout.
#include<clocale> // Requerido pela função setlocale.
#include "OlaMundo.h" // Requerido pela constante EXIT_SUCCESS.

int OlaMundo::olaMundo()
{
	setlocale(LC_ALL, "pt-BR");
	cout << "\n\tBem-vindo a programação C++.\n\tTchau!";
	return EXIT_SUCCESS;
}


// Iniciar o prograama C++.
int main() {
	// Define um objeto da classe OlaMundo.
	OlaMundo olaMundo;

	// Executa a função-membro (método) pública usando o objeto da classe OlaMundo.
	return olaMundo.olaMundo();
}