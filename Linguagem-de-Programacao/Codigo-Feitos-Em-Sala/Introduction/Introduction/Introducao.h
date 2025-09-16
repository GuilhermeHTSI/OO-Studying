#pragma once

#include <string> // Requerido pela classe string.

using namespace std;

class Introducao {
	public:
		// Define constantes estáticas.
		static const short
			FATORIAL = 1,
			DECIMAL_PARA_BINARIO = 2,
			SAIR = 3;

		// Protótipos de funções-membro (método).
		short menu();
		
		// Exibe a mensagem "Pressione qualquer tecla para continuar...".
		int introducao();

		// Exibe a mensagem "Pressione qualquer tecla para continuar...";
		void promptUniversal();

		// Limpa a tela do console.
		void limpaTela();

		// Lê um número decimal, calcula e exibe o resultado.
		void decimalBinario();

		/* Converte um número decimal (base 10) para binário (base 2).
		*   Retorna o número binário como uma string em que os dígitos 0 e/ou 1 são agrupados de 4 em 4 bits.
		*/
		string decimalBinario(int numeroDecimal);

		/* Exibe uma tela para a operação selecionada pelo usuário.
		*   Lê o número a ser usado na operação. Finaliza a leitura quando -1 for lido.
		*   Retorna o número lido.
		*/
		int operacao(string nomeOperacao, string prompt);

};