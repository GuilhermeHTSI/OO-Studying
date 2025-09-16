#include <iostream>
#include <cstdlib> // Requerido pelo system.
#include <clocale>
#include <conio.h> // Requerido por _getch ou _getche.
#include "Introducao.h"
#include <conio.h> // Requerido por _getch ou _getche.
#include "Fatorial.h"

using namespace std;

int main() {
	// Cria (instaciar) um objeto da classe Introducao e usa esse objeto para invocar o método Introducao();
	return Introducao().introducao();
}

// Exibe, lê e retorna a opção do menu escolhida pelo usuário.
short Introducao::menu() {
	short opcao;
	const string
		OPCOES = "\t- Operações\n\n\t1. Fatorial\n\t2. Decimal para Binário\n\t3. Sair\n\n\tEscolha: ",
		OPCAO_INEXISTENTE = "\n\t\tErro: opção inexistente!\n\n";

	limpaTela();

	// Lê e valida uma opção do menu até que o usuário forneça um dos valores válidos (1, 2 ou 3).
	do {
		cout << OPCOES;
		cin >> opcao; // cin é o objeto padrão de entrada de dados do C++.

		// Verifica se a opção do menu é inválida.
		if (opcao < FATORIAL || opcao > SAIR)
			cout << OPCAO_INEXISTENTE;

	} while (opcao < FATORIAL || opcao > SAIR);
	return opcao;
}

int Introducao::introducao() {
	char opcao;

	setlocale(LC_ALL, "pt-BR");

	// Define a região (locale) do objeto cout para informar que o separador de milhar deve ser usado ao exibir os números.
	cout.imbue(locale("pt-BR"));

	Fatorial fatorial; // Cria (instancia) um objeto da classe Fatorial.
	
	// Finaliza o programa quando o usuário escolher a opção Introducao::SAIR.
	do { // Exibe o menu e lê a opção do usuário.
		opcao = menu();

		/* Executa o comando do menu de acordo com a opção do usuário.
		* Como as constantes da classe introducao são estáticas deve-se usar a sintaxe estática com seguinte notação:
		* 
		*		<NomeDaClasse>::<NomeDaConstante>
		*
		* como nos três exemplos abaixo.
		*/
		switch (opcao) {
		case Introducao::FATORIAL: fatorial.fatorial(); break;
		case Introducao::DECIMAL_PARA_BINARIO: decimalBinario();  break;
		}
	} while (opcao != Introducao::SAIR);

	return EXIT_SUCCESS;
}// introducao

// Exibe a mensagem "Pressione qualquer tecla para continuar...";
void Introducao::promptUniversal() {
	cout << "\tPressione qualquer tecla para continuar...";
	cout << _getch();
}

// Limpa a tela do console.
void Introducao::limpaTela() {
	system("cls");
}

// Lê um número decimal, calcula e exibe o resultado.
void Introducao::decimalBinario() {
	int numeroDecimal = 0;

	while (numeroDecimal != -1)
	{
		numeroDecimal = operacao("Decimal para Binário", "Número decimal = ");

		// Verifica se o usuário pediu para sair.
		if (numeroDecimal == -1) break;

		cout << "\n\tNúmero binário: " << decimalBinario(numeroDecimal) << "\n\n\t";

		promptUniversal();
	}
}

/* Converte um número decimal (base 10) para binário (base 2).
*   Retorna o número binário como uma string em que os dígitos 0 e/ou 1 são agrupados de 4 em 4 bits.
*/
string Introducao::decimalBinario(int numeroDecimal) {
	const char ESPACO = ' ';
	/* Calcula o tamanho do número binário de acordo com o número de bits do tipo de dado int acrescido do número de
	 espaços (2) entre os grupos binários compostos de 4 bits.
*/
	const unsigned
		INT_SIZE = sizeof(numeroDecimal) * 8,
		TAMANHO_NUMERO_BINARIO = INT_SIZE + (INT_SIZE / 4 - 1) * 2;

	// Representa os dígitos binários (0 ou 1) do número decimal a ser convertido para a base 2.
	char bits[TAMANHO_NUMERO_BINARIO];

	// Cria uma string para armazenar um número binário composto de INT_SIZE bits e agrupados de 4 em 4 bits.
	string numeroBinario = string(TAMANHO_NUMERO_BINARIO, ESPACO);

	unsigned int um = 1;

	// Percorre os bits do número decimal (base 10) para obter o valor de cada bit.
	for (int indice = TAMANHO_NUMERO_BINARIO - 1; indice >= 0; indice--)
	{   /*
			Testa cada bit do operando numero decimal (base 10).
			 Os bits são armazenados no vetor a partir da posição final até a posição inicial para serem formatados
			 corretamente, ou seja, do bit 31 ao bit 0, considerando 32 bits e numeração da direita para esquerda.
		*/
		bits[indice] = (numeroDecimal & um) ? '1' : '0';

		// Desloca o bit 1 no operando um para obter o valor do próximo dígito binário (0 ou 1).
		um = um << 1;

		// Substitui o dígito binário na string numeroBinario mantendo os bits agrupados de 4 em 4 e separados por 2 espaços.
		numeroBinario.replace(indice, 1, 1, bits[indice]);

		// Quando é formado um grupo de 4 bits o índice deve pular o número de espaços (2) entre os grupos.
		if (indice % 6 == 0)
			indice -= 2;
	}
	return numeroBinario;
}

/* Exibe uma tela para a operação selecionada pelo usuário.
*   Lê o número a ser usado na operação. Finaliza a leitura quando -1 for lido.
*   Retorna o número lido.
*/
int Introducao::operacao(string nomeOperacao, string prompt) {
	int numero;
	const string
		MENSAGEM = "\t- Operações | " + nomeOperacao + "\n\n\tDigite -1 para retorna ao menu!\n\n\t" + prompt;

	limpaTela();

	cout << MENSAGEM;
	cin >> numero;
	return numero;
}