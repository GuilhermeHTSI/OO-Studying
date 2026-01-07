#include "Peca.h"

Peca::Peca(string nome, int quantidade, TipoPeca tipoPeca, Material material) {
	this->nome = nome;
	this->quantidade = quantidade;
	tipo = tipoPeca;
	this->material = material;
}

string Peca::getNome() const {
	return nome;
}

int Peca::getQuantidade() const {
	return quantidade;
}

TipoPeca Peca::getTipo() const {
	return tipo;
}

Material Peca::getMaterial() const {
	return material;
}

Peca& Peca::setNome(string nome) {
	this->nome = nome;
	return *this;
}

Peca& Peca::setQuantidade(int quantidade) {
	this->quantidade = quantidade;
	return *this;
}

Peca& Peca::setTipo(TipoPeca tipoPeca) {
	tipo = tipoPeca;
	return *this;
}

Peca& Peca::setMaterial(Material material) {
	this->material = material;
	return *this;
}

double Peca::peso(double volume) {
	if (material.getTipo() == TipoMaterial::FERRO)
		return (volume * material.PESO_FERRO);
	return (volume * material.PESO_ALUMINIO);
}
