#pragma once

#include "Peca.h"

class Cubo {
public:
	Cubo() = default;

	/* Calcula a área da peça. A área é calculada de acordo com o tipo da peça.
	   Retorna o valor em metros quadrados (m²) correspondente a área da peça. 
	*/
	double area() const;

	/* Calcula o volume da peça. O volume é calculado de acordo com o tipo da peça.
	   Retorna o valor em metros cúbicos (m³) correspondente ao volume da peça. 
	*/
	double volume() const;

	Peca getPeca() const;
	float getAresta() const;

	Cubo& setPeca(Peca peca);
	Cubo& setAresta(float aresta);

private:
	Peca peca;
	float aresta = 0.0;
};
