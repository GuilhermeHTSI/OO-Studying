#include "Cilindro.h"
#include <numbers>


double Cilindro::area() const {
	double area = 2 * M_PI * raio * (raio + altura);
	return area;
}

double Cilindro::volume() const {
	double volume = M_PI * pow(raio, 2) * altura;
	return volume;
}

Peca Cilindro::getPeca() const {
	return peca;
}

float Cilindro::getRaio() const {
	return raio;
}

float Cilindro::getAltura() const {
	return altura;
}

Cilindro& Cilindro::setPeca(Peca peca) {
	this->peca = peca;
	return *this;
}

Cilindro& Cilindro::setRaio(float raio) {
	this->raio = raio;
	return *this;
}

Cilindro& Cilindro::setAltura(float altura) {
	this->altura = altura;
	return *this;
}
