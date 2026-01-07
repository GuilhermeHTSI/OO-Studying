#pragma once

#include <string>

using namespace std;

// Tipos de material
enum class TipoMaterial { ALUMINIO, FERRO };

//  Define as propriedades do material.
class Material {
public:
	// Peso específico do alumínio de 2,7 g/m³
	inline static const double PESO_ALUMINIO = 2.7;

	// Peso específico do ferro de 7,8 g/m³
	inline static const double PESO_FERRO = 7.8;

	// Consumo de tinta do alumínio de 0,5 l/m²
	inline static const double CONSUMO_ALUMINIO = 0.5;

	// Consumo de tinta do ferro de 0,7 l/m²
	inline static const double CONSUMO_FERRO = 0.7;

	Material() = default;
	Material(string nome, TipoMaterial tipoMaterial);

	string getNome() const;
	TipoMaterial getTipo() const;

	Material& setNome(string nome);
	Material& setTipo(TipoMaterial tipoMaterial);

private: // Nome e tipo do material.
	string nome;
	TipoMaterial tipo = TipoMaterial::ALUMINIO; // Default, caso não seja setado.
};