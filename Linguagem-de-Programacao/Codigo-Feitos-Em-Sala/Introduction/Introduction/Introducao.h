#pragma once

#include <string> // Requerido pela classe string.

using namespace std;

class Introducao {
	public:
		// Define constantes est�ticas.
		static const short
			FATORIAL = 1,
			DECIMAL_PARA_BINARIO = 2,
			SAIR = 3;

		// Prot�tipos de fun��es-membro (m�todo).
		short menu();
		
		// Exibe a mensagem "Pressione qualquer tecla para continuar...".
		int introducao();

		// Exibe a mensagem "Pressione qualquer tecla para continuar...";
		void promptUniversal();

		// Limpa a tela do console.
		void limpaTela();

		// L� um n�mero decimal, calcula e exibe o resultado.
		void decimalBinario();

		/* Converte um n�mero decimal (base 10) para bin�rio (base 2).
		*   Retorna o n�mero bin�rio como uma string em que os d�gitos 0 e/ou 1 s�o agrupados de 4 em 4 bits.
		*/
		string decimalBinario(int numeroDecimal);

		/* Exibe uma tela para a opera��o selecionada pelo usu�rio.
		*   L� o n�mero a ser usado na opera��o. Finaliza a leitura quando -1 for lido.
		*   Retorna o n�mero lido.
		*/
		int operacao(string nomeOperacao, string prompt);

};