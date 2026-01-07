#pragma once

#include "Peca.h"

class Paralelepipedo {
public:
	Paralelepipedo() = default;

	/* Calcula a área da peça. A área é calculada de acordo com o tipo da peça.
	   Retorna o valor em metros quadrados (m²) correspondente a área da peça.
	*/
	double area() const;

	/* Calcula o volume da peça. O volume é calculado de acordo com o tipo da peça.
	   Retorna o valor em metros cúbicos (m³) correspondente ao volume da peça.
	*/
	double volume() const;

	Peca getPeca() const;
	float getAltura() const;
	float getLargura() const;
	float getProfundidade() const;

	Paralelepipedo& setPeca(Peca peca);
	Paralelepipedo& setAltura(float altura);
	Paralelepipedo& setLargura(float largura);
	Paralelepipedo& setProfundidade(float profundidade);

private:
	Peca peca;
	float altura = 0.0, largura = 0.0, profundidade = 0.0;
};
