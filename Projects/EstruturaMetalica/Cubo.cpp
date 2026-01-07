#include "Cubo.h"

double Cubo::area() const{
	double area = 6.0 * pow(aresta, 2);
	return area;
}

double Cubo::volume() const {
	return pow(aresta, 3);
}

float Cubo::getAresta() const {
	return aresta;
}

Peca Cubo::getPeca() const {
	return peca;
}

Cubo& Cubo::setPeca(Peca peca) {
	this->peca = peca;
	return *this;
}

Cubo& Cubo::setAresta(float aresta) {
	this->aresta = aresta;
	return *this;
}