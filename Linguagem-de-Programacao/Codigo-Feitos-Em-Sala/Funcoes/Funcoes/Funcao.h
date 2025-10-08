#pragma once

#include <string>

using namespace std;

/*	A palavra reservada constexpr (constant expression) foi introduzida no C++11 e aperfeiçoada no C++14.

	Ao contrário de const, constexpr também pode ser aplicado a funções e constructores de classe.
	Ela indica que o valor, ou valor de retorno, é constante e, quando possível, é calculado em tempo de compilação.

	Um valor integral (número inteiro) constexpr pode ser usado onde um inteiro constante é necessário,
	como em definições de vetor e matriz. Quando um valor é calculado em tempo de compilação e não tempo de execução,
	isso ajuda o programa a ser executado mais rápido e usa menos memória.

	A principal diferença entre variáveis const e constexpr é que a inicialização de uma variável const pode ser adiada
	até o tempo de execução, e uma variável constexpr deve ser inicializada em tempo de compilação.

	Uma variável pode ser declarada com constexpr quando tem um tipo literal (que pode ser determinado em
	tempo de compilação) e é inicializada. Se a inicialização for realizada por um construtor, esse deve ser declarado como
	constexpr.

	Uma função constexpr é aquela cujo valor de retorno é computável em tempo de compilação quando o código chamador
	o requerer. O código que chama a função requer o valor de retorno em tempo de compilação para inicializar uma variável
	constexpr. Quando seus argumentos são valores constexpr, uma função constexpr produz uma constante em tempo de
	compilação. Quando ela é chamada com argumentos não constexpr, ou quando seu valor não é exigido em tempo de
	compilação, ela produz um valor em tempo de execução como uma função regular. Este comportamento duplo evita que
	você tenha que escrever versões constexpr e não constexpr da mesma função.
*/
constexpr int fatorial(int numero)
{
	return (numero == 0) ? 1 : numero * fatorial(numero - 1);
}

constexpr int CINCO = 5;

// O fatorial de cinco é calculado em tempo de compilação.
constexpr int FATORIAL_DE_CINCO = fatorial(CINCO);

class Funcao {
public:
	// Construtor default.
	Funcao() = default;

	// Apresenta os tópicos deste capítulo.
	int funcao();

	// Exibe a mensagem no console.
	inline void exibirMensagem(string mensagem);

	// Apresenta referências e parâmetros de referência.
	void referencias();

	/* O padrão C++11 definiu um significado original e revisado para a palavra reservada auto.
		 Antes ela declarava uma variável na classe de armazenamento automática, ou seja, uma variável que tem um tempo de
		 vida local, como as variáveis locais definidas 	em uma função. Com o C++11 a palavra reservada auto pode ser usada
		 para declarar uma variável em que seu tipo de dado é deduzido com base na expressão de inicialização de declaração.

		O uso da palavra reservada auto é recomendado para a maioria das situações porque ela fornece estes benefícios:

		1. Robustez: Se o tipo da expressão for alterado (incluindo o tipo de retorno de função) ele simplesmente funcionará.
		2. Desempenho: Você tem a garantia de que não haverá nenhuma conversão.
		3. Usabilidade: Você não precisa se preocupar com dificuldades de ortografia e erros de digitação nos nomes dos tipo de dados.
		4. Eficiência: Sua codificação pode ser mais eficiente.

		Apresenta a palavra reservada auto.
*/
	void autoKeyword();

	// Apresenta o static_cast do C++.
	void staticCast();

	// Testa os métodos de pesquisa da classe.
	void testarPesquisa();

	// Apresenta a enumeração sem e com escopo.
	void enumeracao();

	// Apresenta o template de função.
	void templateDeFuncao();

	// Implementa um template de função com três parâmetros de tipo formal diferentes.
	template <typename T1, typename T2, typename T3> void imprimir(T1 valor1, T2 valor2, T3 valor3);

	/* O uso do auto para definir o tipo do parâmetro formal é válido a partir do C++20.
		 A sintaxe abaixo é conhecida como template de função abreviado, introduzida no C++20.
	*/
	void imprimir(string mensagem, auto valor);

private:
	const int NAO_ACHOU = -1;

	// Substitui o caractere atual pelo caractere novo na string. Retorna a string modificada.
	string replace(string& str, char caracterAtual, char caracterNovo);

	// Lê e retorna uma string. A mensagem representa o texto a ser exibido antes de ler a string.
	string lerString(string mensagem);

	/* Pesquisa por todas as ocorrências do número no vetor. Retorna a posição onde o número foi localizado ou NAO_ACHOU
		 se o número não foi encontrado.
	*/
	int pesquisar(int vetor[], int tamanhoVetor, int numero);

	/* Pesquisa pela primeira ocorrência da string no vetor. A pesquisa ocorrerá apenas no intervalo definido pelos parâmetros
		 posicaoInicial e posicaoFinal (inclusive). Retorna a posição onde a string foi localizada ou NAO_ACHOU se ela não foi
		 encontrada.
	*/
	int pesquisar(string vetor[], string str, int posicaoInicial = 0, int posicaoFinal = 10);
	//int pesquisar(string vetor[], string str, int posicaoInicial = 0, int posicaoFinal = (sizeof vetor / sizeof(int));
}; // class Funcao

