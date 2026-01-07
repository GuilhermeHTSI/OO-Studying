#pragma once

#include <vector>
#include <memory>
#include "Peca.h"
#include "Cubo.h"
#include "Cilindro.h"
#include "Paralelepipedo.h"

// Define as propriedades da estrutura metálica.
class EstruturaMetalica {
public:
	// Lata de tinta de 0,5 litro.
	inline static const double LATA_TINTA_MEIO_LITRO = 0.5;

	// Lata de tinta de 2 litros
	inline static const double LATA_TINTA_DOIS_LITROS = 2;

	// Lata de tinta de 5 litros.
	inline static const double LATA_TINTA_CINCO_LITROS = 5;

	EstruturaMetalica() = default;

	// Obtém o número total das peças que compõem a estrutura metálica.
	int numeroDePecas();

	// Obtém o número total das peças que compõem a estrutura metálica que são iguais ao tipo de peça especificado. 
	int numeroDePecas(TipoPeca tipoPeca);

	// Adiciona uma peça na estrutura metálica. 
	void adicionarPeca(Cubo cubo);
	void adicionarPeca(Cilindro cilindro);
	void adicionarPeca(Paralelepipedo paralelepipedo);

	/* Obtém a relação de todos os cubos da estrutura metálica.
	   Se a estrutura não tiver nenhum cubo retorna um vector de tamanho zero. 
	*/ 
	vector<Cubo> obterCubos();

	/* Obtém a relação de todos os cilindros da estrutura metálica.
	   Se a estrutura não tiver nenhum cilindro retorna um vector de tamanho zero. 
	*/
	vector<Cilindro> obterCilindros();

	/* Obtém a relação de todos os paralelepípedos da estrutura metálica.
	   Se a estrutura não tiver nenhum paralelepípedo retorna um vector de tamanho zero.
	*/
	vector<Paralelepipedo> obterParalelepipedos();

	/* Calcula o peso total da estrutura metálica.
	   Retorna o valor em gramas (g) correspondente ao peso total da estrutura metálica. 
	*/
	double pesoTotal();

	/* Calcula o peso total de todas as peças da estrutura metálica que possuem o mesmo tipo de peça.
	   Retorna o valor em gramas (g) correspondente ao peso total da estrutura metálica.
	*/
	double pesoTotal(TipoPeca tipoPeca);

	/* Calcula o volume total da estrutura metálica.
	   Retorna o valor em metros cúbicos (m³) correspondente ao volume total da estrutura metálica. 
	*/
	double volumeTotal();

	/* Calcula o volume total de todas as peças da estrutura metálica que possuem o mesmo tipo de peça.
	   Retorna o valor em metros cúbicos (m³) correspondente ao volume da peça.
	*/
	double volumeTotal(TipoPeca tipoPeca);

	/* Calcula a área total da estrutura metálica.
	   Retorna o valor em metros quadrados (m²) correspondente a área total da estrutura metálica.
	*/
	double areaTotal();

	/* Calcula a área total de todas as peças da estrutura metálica que possuem o mesmo tipo de material.
	   Retorna o valor em metros quadrados (m²) correspondente a área total da peça. 
	*/ 
	double areaTotal(TipoMaterial tipoMaterial);

	/* Calcula o número de latas de tinta necessárias para pintar a estrutura metálica.
       	     Retorna um ponteiro inteligente para um vetor de números inteiros com a quantidade de cada lata de tinta.
	    A quantidade das latas de tinta de 0,5 litro, 2 litros e 5 litros são armazenadas no vetor, respectivamente nas posições 0, 1 e 2.
	*/
	unique_ptr<int[]> numeroDeLatasDeTinta();

private:
	int calcularLatas(double consumoReal, unique_ptr <int[]>& tintas);
	// Relação de todos os cubos que compõe a estrutura metálica.
	vector<unique_ptr<Cubo>> cubos;

	// Relação de todos os cilindros que compõe a estrutura metálica.
	vector<unique_ptr<Cilindro>> cilindros;

	// Relação de todos os paralelepípedos que compõe a estrutura metálica.
	vector<unique_ptr<Paralelepipedo>> paralelepipedos;
}; 
