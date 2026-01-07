#pragma once

#include "Peca.h"

class Cilindro {
public:
	Cilindro() = default;

	/* Calcula a área da peça. A área é calculada de acordo com o tipo da peça.
	   Retorna o valor em metros quadrados (m²) correspondente a área da peça.
	*/
	double area() const;

	/* Calcula o volume da peça. O volume é calculado de acordo com o tipo da peça.
	   Retorna o valor em metros cúbicos (m³) correspondente ao volume da peça.
	*/
	double volume() const;

	Peca getPeca() const;
	float getRaio() const;
	float getAltura() const;

	Cilindro& setPeca(Peca peca);
	Cilindro& setRaio(float raio);
	Cilindro& setAltura(float altura);

private:
	Peca peca;
	float raio = 0.0, altura = 0.0;
};
