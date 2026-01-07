#include "Paralelepipedo.h"

double Paralelepipedo::area() const {
	double area = 2 * (altura * largura + altura * profundidade + largura * profundidade);
	return area;
}

double Paralelepipedo::volume() const{
	double volume = altura * largura * profundidade;
	return volume;
}

Peca Paralelepipedo::getPeca() const {
    return peca;
}

float Paralelepipedo::getAltura() const {
    return altura;
}

float Paralelepipedo::getLargura() const {
    return largura;
}

float Paralelepipedo::getProfundidade() const {
    return profundidade;
}

Paralelepipedo& Paralelepipedo::setPeca(Peca peca) {
	this->peca = peca;
	return *this;
}

Paralelepipedo& Paralelepipedo::setAltura(float altura) {
	this->altura = altura;
	return *this;
}

Paralelepipedo& Paralelepipedo::setLargura(float largura){
	this->largura = largura;
	return *this;
}

Paralelepipedo& Paralelepipedo::setProfundidade(float profundidade) {
	this->profundidade = profundidade;
	return *this;
}
