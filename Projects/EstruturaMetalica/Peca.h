#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Material.h"

// Tipos de peça
enum class TipoPeca { CILINDRO, CUBO , PARALELEPIPEDO };

//  Define as propriedades de cada peça que compõe a estrutura metálica.
class Peca {
public:
	Peca() = default;
	Peca(string nome, int quantidade, TipoPeca tipoPeca, Material material);

	string getNome() const;
	int getQuantidade() const;
	TipoPeca getTipo() const;
	Material getMaterial() const;

	Peca& setNome(string nome);
	Peca& setQuantidade(int quantidade);
	Peca& setTipo(TipoPeca tipoPeca);
	Peca& setMaterial(Material material);

	/* Calcula o peso da peça. O peso é calculado de acordo com o tipo do material.
	   Retorna o valor em gramas (g) correspondente ao peso da peça. 
	*/
	double peso(double volume);

private: // Define o nome, a quantidade, o tipo e o material da peça.
	string nome;
	int quantidade = 0.0;
	TipoPeca tipo = TipoPeca::CUBO;
	Material material;
}; 
