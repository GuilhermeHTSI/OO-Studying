#include "Material.h"

Material::Material(string nome, TipoMaterial tipoMaterial) {
	this->nome = nome;
	tipo = tipoMaterial;
}

string Material::getNome() const {
	return nome;
}

TipoMaterial Material::getTipo() const {
	return tipo;
}

Material& Material::setNome(string nome) {
	this->nome = nome;
	return *this;
}

Material& Material::setTipo(TipoMaterial tipoMaterial) {
	tipo = tipoMaterial;
	return *this;
}