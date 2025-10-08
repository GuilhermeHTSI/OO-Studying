#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <clocale>
#include <cmath>
#include <iomanip> // Requerido por setw e setprecision.
#include "Funcao.h"

int main() {
	return Funcao().funcao();
}

// Apresenta os tópicos deste capítulo.
int Funcao::funcao() {
	setlocale(LC_ALL, "pt-BR");
	cout.imbue(locale("pt-BR"));

	exibirMensagem("\n- Fatorial\n\tfat(5) = ");	cout << FATORIAL_DE_CINCO;
	exibirMensagem("\n\tfat(10) = ");				        cout << fatorial(10) << endl;

	referencias();
	autoKeyword();
	staticCast();
	testarPesquisa();
	enumeracao();
	templateDeFuncao();

	return EXIT_SUCCESS;
} // funcao()

// Exibe a mensagem no console.
inline void Funcao::exibirMensagem(string mensagem) {
	cout << mensagem;
}

// Apresenta referências e parâmetros de referência.
void Funcao::referencias() {
	string path = "/home/aluno";

	cout << "\nDiretório no Linux: " << path;

	replace(path, '/', '\\');

	cout << "\nDiretório no Windows: " << path << endl;

	int x = 10, y = 15;

	/* A referência deve ser iniciada na definição. Referência não é ponteiro, logo
	   int& (referência) é diferente de int* (ponteiro).

		 refX = &x;  // ERRO: não se pode converter um ponteiro para int (int *) em uma referência para int (int &).
	*/
	int& refX = x;

	// Define um referência para uma constante do tipo int.
	const int& refConstX = x;

	/*ERRO: não é permitido alterar uma variável usando uma referência para uma constante.

			refConstX = 50;
	*/
	cout << "\n- Referências\n\tx = " << x << "\n\tx via refX = " << refX << endl;

	refX = 20;
	cout << "\tx = " << x << "\n\tx via refX = " << refX << endl;

	refX = y;
	cout << "\tx = " << x << "\n\tx via refX = " << refX << endl;
} // referencias()

// Substitui o caractere atual pelo caractere novo na string. Retorna a string modificada.
/*
* 
*		auto maximo(auto, auto, auto); // Exemplo: 
* 
*/
string Funcao::replace(string& str, char caracterAtual, char caracterNovo) {
	/* A string C++ permite acessar cada caractere usando o operador colchetes por
		 causa do recurso de sobrecarga de operadores da linguagem.
	*/
	for (size_t indice = 0; indice < str.length(); indice++)
		if (str[indice] == caracterAtual)
			str[indice] = caracterNovo;

	return str;
}

void Funcao::autoKeyword() {
	/*
		auto c = 'c', i = 6;  // Erro: porque a variável c é char e i é int.

		Para corrigir esse erro devemos assegurar que as inicializações na lista de definição
		de variáveis sejam do mesmo tipo de dado ou que elas sem feitas em linhas
		separadas.
	*/
	const auto PI = M_PI; // constante double, logo não se pode modificar o PI.
	auto numero = 10;  // int
	auto caractere = 'A'; // char
	auto number = numero; // int
	auto& refNumero = numero; // referência para int

	auto palavra = "almoço"; // a string da Linguagem C, ou seja, o vetor de caracteres terminado com nulo ('\0').
	auto frase = string("Tô com fome."); // objeto string do C++

	auto tamanhoFrase = frase.length(); // size_t (unsigned int)

	cout << "\n- Palavra reservada auto\n\tPi = " << setw(20) << setprecision(20) << PI <<
		endl;
} // autoKeyword()

// Apresenta o static_cast do C++.
void Funcao::staticCast() {
	/*  Use sempre o static_cast em C++ para realizar a coerção (cast) de tipo de dado, porque ele captura, em tempo de compilação,
		  conversões de tipo que não podem ser realizadas com segurança.

		  A coerção (cast) de tipo de dado abaixo não é permitida pelo compilador C++, porque o static_cast faz a verificação de
		  segurança de tipo.

		  int *ptrInt = static_cast<int *>(0xB8000); // O número hexadecimal B8000 em decimal é 753.664.

		  A linha abaixo é permitida pelo compilador C / C++, mas representa um erro em potencial. Portanto, não faça isso.
		  Sempre que for fazer um cast em C++ use o static_cast.
	 */
	double* ptrDouble = (double*)(100); // Exemplo de como NÃO fazer o cast.

	/* O acesso abaixo representa um erro grave porque você está tentando acessar uma posição de memória desconhecida.

			 *ptrDouble = 9.5;
	*/
} // staticCast()

// Lê e retorna uma string. A mensagem representa o texto a ser exibido antes de ler a string.
string Funcao::lerString(string mensagem) {
	string palavra;

	cout << mensagem;
	getline(cin, palavra);

	return palavra;
}

/* Pesquisa por todas as ocorrências do número no vetor. Retorna a posição onde o número foi localizado ou NAO_ACHOU
	 se o número não foi encontrado.
*/
int Funcao::pesquisar(int vetor[], int tamanhoVetor, int numero) {
	/* As variáveis locais estáticas não são armazendas na pilha como as demais variáveis locais, elas são guardadas na região
		 de memória conhecida como área de dados globais e estáticos.
	*/
	static int posicao = 0; // Essa iniciação é feita somente na primeira chamada da função.

	for (; posicao < tamanhoVetor; posicao++)
		if (vetor[posicao] == numero)
			return posicao++;
	posicao = 0;
	return NAO_ACHOU;
}

/* Pesquisa pela primeira ocorrência da string no vetor. A pesquisa ocorrerá apenas no intervalo definido pelos parâmetros
	 posicaoInicial e posicaoFinal (inclusive). Retorna a posição onde a string foi localizada ou NAO_ACHOU se ela não foi encontrada.
*/
int Funcao::pesquisar(string vetor[], string str, int posicaoInicial, int posicaoFinal) {
	for (int indice = posicaoInicial; indice <= posicaoFinal; indice++)
		if (str == vetor[indice]) // ou (str.compare(vetor[indice]) == 0)    
			return indice;

	return NAO_ACHOU;
}

// Testa os métodos de pesquisa da classe.
void Funcao::testarPesquisa() {
	// Não pode-se realizar a declaração de multiplas variáveis quando se há um vetor dentre as declarações.
	// Um vetor não pode ser declarado com auto.
	int posicao, teste = 1, numeros[] = { 2, 4, 2, 6, 2, 8 };
	string palavra, palavras[] = { "sol", "terra", "lua", "mar" , "uva", "abacaxi", "laranja", "ameixa", "fogo", "praia", "oi" };

	cout << "\n- Testar Pesquisa";
	do {
		posicao = pesquisar(numeros, sizeof numeros / sizeof(int), 2);

		if (posicao != NAO_ACHOU)
			cout << "\n\tPosição: " << posicao;

	} while (posicao != NAO_ACHOU);

	cout << "\n\n- Pesquisar string";
	do {
		switch (teste) {
		case 1: palavra = lerString("\n\tTeste 1: pesquisa na primeira metade do vetor\n\tPalavra: ");
			posicao = pesquisar(palavras, palavra, 0, _countof(palavras) / 2);
			break;

		case 2:  palavra = lerString("\n\tTeste 2: pesquisa na segunda metade do vetor\n\tPalavra: ");
			posicao = pesquisar(palavras, palavra, _countof(palavras) / 2 + 1);
			break;

		default: // Usado a partir do teste 3.
			palavra = lerString("\n\tTeste 3: pesquisa em todo o vetor\n\tPalavra: ");
			posicao = pesquisar(palavras, palavra);
		}
		teste++;

		if (posicao != NAO_ACHOU)
			cout << "\n\tA palavra \"" << palavra << "\" foi localizada na posição " << posicao << ".\n";
		else
			if (palavra != "fim")
				cout << "\tPalavra não localizada.\n";
	} while (palavra != "fim");
} // testarPesquisa() 

// Apresenta a enumeração sem e com escopo.
void Funcao::enumeracao() {
	/* Enumeração é uma lista de constantes com valor inicial default zero na primeira constante.
		A definição abaixo é uma enumeração sem escopo.
	*/
	enum Err { ERRO_LEITURA = 10, ERRO_GRAVACAO };

	// Enumeração com escopo.
	enum class Sudeste { ES, MG, RJ, SP };
	string estados[] = { "Espírito Santo", "Minas Gerais", "Rio de Janeiro", "São Paulo" };

	int erro = ERRO_LEITURA,
		mg = static_cast<int>(Sudeste::MG);

	cout << "\n- Enumeração\n\tErro de leitura = " << ERRO_LEITURA << "\n\tMG = " << mg
		<< "\n\tES = " << static_cast<int>(Sudeste::ES);

	cout << "\n\n- Estados da Região Sudeste\n";
	for (Sudeste uf = Sudeste::ES; uf <= Sudeste::SP; uf = static_cast<Sudeste>(static_cast<int>(uf) + 1))
		cout << "\n\t" << estados[static_cast<int>(uf)];

	cout << endl;
} // enumeracao()

// Apresenta o template de função.
void Funcao::templateDeFuncao() {
	cout << "\n- Template de Função\n\n";

	imprimir("Artista: ", "Michael Jackson");
	imprimir("Nota: ", 35.0);
	imprimir("Idade: ", 18);

	imprimir(25, "frio", 'A');
	imprimir(true, 2.57, "oi");
}

// Implementa um template de função com três parâmetros de tipo formal diferentes.
template<typename T1, typename T2, typename T3> void Funcao::imprimir(T1 valor1, T2 valor2, T3 valor3) {
	cout << "\n\tValor 1 = " << valor1
		<< "\n\tValor 2 = " << valor2
		<< "\n\tValor 3 = " << valor3 << endl;
}

/* O uso do auto para definir o tipo do parâmetro formal é válido a partir do C++20.
	 A sintaxe abaixo é conhecida como template de função abreviado, introduzida no C++20.
*/
void Funcao::imprimir(string mensagem, auto valor) {
	cout << "\t" << mensagem << valor << endl;
}

