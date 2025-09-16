#include <iostream>
#include <cstdlib> // Requerido pelo system.
#include <clocale>
#include <conio.h> // Requerido por _getch ou _getche.
#include "Introducao.h"
#include <conio.h> // Requerido por _getch ou _getche.
#include "Fatorial.h"

using namespace std;

int main() {
	// Cria (instaciar) um objeto da classe Introducao e usa esse objeto para invocar o m�todo Introducao();
	return Introducao().introducao();
}

// Exibe, l� e retorna a op��o do menu escolhida pelo usu�rio.
short Introducao::menu() {
	short opcao;
	const string
		OPCOES = "\t- Opera��es\n\n\t1. Fatorial\n\t2. Decimal para Bin�rio\n\t3. Sair\n\n\tEscolha: ",
		OPCAO_INEXISTENTE = "\n\t\tErro: op��o inexistente!\n\n";

	limpaTela();

	// L� e valida uma op��o do menu at� que o usu�rio forne�a um dos valores v�lidos (1, 2 ou 3).
	do {
		cout << OPCOES;
		cin >> opcao; // cin � o objeto padr�o de entrada de dados do C++.

		// Verifica se a op��o do menu � inv�lida.
		if (opcao < FATORIAL || opcao > SAIR)
			cout << OPCAO_INEXISTENTE;

	} while (opcao < FATORIAL || opcao > SAIR);
	return opcao;
}

int Introducao::introducao() {
	char opcao;

	setlocale(LC_ALL, "pt-BR");

	// Define a regi�o (locale) do objeto cout para informar que o separador de milhar deve ser usado ao exibir os n�meros.
	cout.imbue(locale("pt-BR"));

	Fatorial fatorial; // Cria (instancia) um objeto da classe Fatorial.
	
	// Finaliza o programa quando o usu�rio escolher a op��o Introducao::SAIR.
	do { // Exibe o menu e l� a op��o do usu�rio.
		opcao = menu();

		/* Executa o comando do menu de acordo com a op��o do usu�rio.
		* Como as constantes da classe introducao s�o est�ticas deve-se usar a sintaxe est�tica com seguinte nota��o:
		* 
		*		<NomeDaClasse>::<NomeDaConstante>
		*
		* como nos tr�s exemplos abaixo.
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

// L� um n�mero decimal, calcula e exibe o resultado.
void Introducao::decimalBinario() {
	int numeroDecimal = 0;

	while (numeroDecimal != -1)
	{
		numeroDecimal = operacao("Decimal para Bin�rio", "N�mero decimal = ");

		// Verifica se o usu�rio pediu para sair.
		if (numeroDecimal == -1) break;

		cout << "\n\tN�mero bin�rio: " << decimalBinario(numeroDecimal) << "\n\n\t";

		promptUniversal();
	}
}

/* Converte um n�mero decimal (base 10) para bin�rio (base 2).
*   Retorna o n�mero bin�rio como uma string em que os d�gitos 0 e/ou 1 s�o agrupados de 4 em 4 bits.
*/
string Introducao::decimalBinario(int numeroDecimal) {
	const char ESPACO = ' ';
	/* Calcula o tamanho do n�mero bin�rio de acordo com o n�mero de bits do tipo de dado int acrescido do n�mero de
	 espa�os (2) entre os grupos bin�rios compostos de 4 bits.
*/
	const unsigned
		INT_SIZE = sizeof(numeroDecimal) * 8,
		TAMANHO_NUMERO_BINARIO = INT_SIZE + (INT_SIZE / 4 - 1) * 2;

	// Representa os d�gitos bin�rios (0 ou 1) do n�mero decimal a ser convertido para a base 2.
	char bits[TAMANHO_NUMERO_BINARIO];

	// Cria uma string para armazenar um n�mero bin�rio composto de INT_SIZE bits e agrupados de 4 em 4 bits.
	string numeroBinario = string(TAMANHO_NUMERO_BINARIO, ESPACO);

	unsigned int um = 1;

	// Percorre os bits do n�mero decimal (base 10) para obter o valor de cada bit.
	for (int indice = TAMANHO_NUMERO_BINARIO - 1; indice >= 0; indice--)
	{   /*
			Testa cada bit do operando numero decimal (base 10).
			 Os bits s�o armazenados no vetor a partir da posi��o final at� a posi��o inicial para serem formatados
			 corretamente, ou seja, do bit 31 ao bit 0, considerando 32 bits e numera��o da direita para esquerda.
		*/
		bits[indice] = (numeroDecimal & um) ? '1' : '0';

		// Desloca o bit 1 no operando um para obter o valor do pr�ximo d�gito bin�rio (0 ou 1).
		um = um << 1;

		// Substitui o d�gito bin�rio na string numeroBinario mantendo os bits agrupados de 4 em 4 e separados por 2 espa�os.
		numeroBinario.replace(indice, 1, 1, bits[indice]);

		// Quando � formado um grupo de 4 bits o �ndice deve pular o n�mero de espa�os (2) entre os grupos.
		if (indice % 6 == 0)
			indice -= 2;
	}
	return numeroBinario;
}

/* Exibe uma tela para a opera��o selecionada pelo usu�rio.
*   L� o n�mero a ser usado na opera��o. Finaliza a leitura quando -1 for lido.
*   Retorna o n�mero lido.
*/
int Introducao::operacao(string nomeOperacao, string prompt) {
	int numero;
	const string
		MENSAGEM = "\t- Opera��es | " + nomeOperacao + "\n\n\tDigite -1 para retorna ao menu!\n\n\t" + prompt;

	limpaTela();

	cout << MENSAGEM;
	cin >> numero;
	return numero;
}