#include <iostream>
#include <clocale>
#include "EstruturaMetalica.h"

using namespace std;

int EstruturaMetalica::numeroDePecas() {
	int numeroPecas = 0;
	int quantidade = 0;
	for (const auto& cubo : cubos) {
		quantidade = cubo->getPeca().getQuantidade();
		if (quantidade >= 1) numeroPecas += quantidade;
	}
	for (const auto& paralelepipedo : paralelepipedos) {
		quantidade = paralelepipedo->getPeca().getQuantidade();
		if (quantidade >= 1) numeroPecas += quantidade;
	}
	for (const auto& cilindro : cilindros) {
		quantidade = cilindro->getPeca().getQuantidade();
		if (quantidade >= 1) numeroPecas += quantidade;
	}
	return numeroPecas;
}

int EstruturaMetalica::numeroDePecas(TipoPeca tipoPeca) {
	int numeroPecas = 0;
	int quantidade = 0;
	for (const auto& cubo : cubos) {
		if (cubo->getPeca().getTipo() == tipoPeca) {
			quantidade = cubo->getPeca().getQuantidade();
			if (quantidade >= 1) numeroPecas += quantidade;
		}
	}
	for (const auto& paralelepipedo : paralelepipedos) {
		if (paralelepipedo->getPeca().getTipo() == tipoPeca) {
			quantidade = paralelepipedo->getPeca().getQuantidade();
			if (quantidade >= 1) numeroPecas += quantidade;
		}
	}
	for (const auto& cilindro : cilindros){
		if (cilindro->getPeca().getTipo() == tipoPeca) {
			quantidade = cilindro->getPeca().getQuantidade();
			if (quantidade >= 1) numeroPecas += quantidade;
		}
	}
	return numeroPecas;
}

void EstruturaMetalica::adicionarPeca(Cubo cubo) {
	cubos.push_back(make_unique<Cubo>(cubo));
}

void EstruturaMetalica::adicionarPeca(Cilindro cilindro) {
	cilindros.push_back(make_unique<Cilindro>(cilindro));
}

void EstruturaMetalica::adicionarPeca(Paralelepipedo paralelepipedo) {
	paralelepipedos.push_back(make_unique<Paralelepipedo>(paralelepipedo));
}

vector<Cubo> EstruturaMetalica::obterCubos() {
	if (cubos.size() == 0) return {};
	vector<Cubo> vetorCubos;
	for (const auto& cuboAux : cubos)
		vetorCubos.push_back(*cuboAux);
    return vetorCubos;
}

vector<Cilindro> EstruturaMetalica::obterCilindros() {
	if (cilindros.size() == 0) return {};
	vector <Cilindro> vetorCilindros;
	for (const auto& cilindroAux : cilindros)
		vetorCilindros.push_back(*cilindroAux);
	return vetorCilindros;
}

vector<Paralelepipedo> EstruturaMetalica::obterParalelepipedos() {
	if (paralelepipedos.size() == 0) return {};
	vector <Paralelepipedo> vetorParalelepipedos;
	for (const auto& paralelepipedoAux : paralelepipedos)
		vetorParalelepipedos.push_back(*paralelepipedoAux);
	return vetorParalelepipedos;
}

double checarMaterial(TipoMaterial tipoMaterial, Material material) {
	if (tipoMaterial == TipoMaterial::ALUMINIO)
		return material.PESO_ALUMINIO;
	else if (tipoMaterial == TipoMaterial::FERRO)
		return material.PESO_FERRO;
	return -1.0;
}

double calcularPesoMaterial(Peca peca, double volume) {
	TipoMaterial tipoMaterial = peca.getMaterial().getTipo();
	double pesoMaterial = checarMaterial(tipoMaterial, peca.getMaterial());
	double pesoDaLeva = pesoMaterial * volume;
	return pesoDaLeva;
}

double EstruturaMetalica::pesoTotal() {
	double pesoTotal = 0.0;
	int quantidade = 0;
	for (const auto& cubo : cubos) {
		quantidade = cubo->getPeca().getQuantidade();
		if (quantidade > 1)
			pesoTotal += calcularPesoMaterial(cubo->getPeca(), cubo->volume()) * quantidade;
		else pesoTotal += calcularPesoMaterial(cubo->getPeca(), cubo->volume());
	}
	for (const auto& paralelepipedo : paralelepipedos) {
		quantidade = paralelepipedo->getPeca().getQuantidade();
		if (quantidade > 1)
			pesoTotal += calcularPesoMaterial(paralelepipedo->getPeca(), paralelepipedo->volume()) * quantidade;
		else pesoTotal += calcularPesoMaterial(paralelepipedo->getPeca(), paralelepipedo->volume());
	}
	for (const auto& cilindro : cilindros) {
		quantidade = cilindro->getPeca().getQuantidade();
		if (quantidade > 1)
			pesoTotal += calcularPesoMaterial(cilindro->getPeca(), cilindro->volume()) * quantidade;
		else pesoTotal += calcularPesoMaterial(cilindro->getPeca(), cilindro->volume());
	}
	return pesoTotal;
}

double EstruturaMetalica::pesoTotal(TipoPeca tipoPeca) {
	double pesoTotal = 0.0;
	int quantidade = 0;
	for (const auto& cubo : cubos) {
		if (cubo->getPeca().getTipo() == tipoPeca) {
			quantidade = cubo->getPeca().getQuantidade();
			if (quantidade > 1)
				pesoTotal += calcularPesoMaterial(cubo->getPeca(), cubo->volume()) * quantidade;
			else pesoTotal += calcularPesoMaterial(cubo->getPeca(), cubo->volume());
		}
	}

	for (const auto& paralelepipedo : paralelepipedos) {
		if (paralelepipedo->getPeca().getTipo() == tipoPeca) {
			quantidade = paralelepipedo->getPeca().getQuantidade();
			if (quantidade > 1)
				pesoTotal += calcularPesoMaterial(paralelepipedo->getPeca(), paralelepipedo->volume()) * quantidade;
			else pesoTotal += calcularPesoMaterial(paralelepipedo->getPeca(), paralelepipedo->volume());
		}
	}

	for (const auto& cilindro : cilindros) {
		if (cilindro->getPeca().getTipo() == tipoPeca) {
			quantidade = cilindro->getPeca().getQuantidade();
			if (quantidade > 1)
				pesoTotal += calcularPesoMaterial(cilindro->getPeca(), cilindro->volume()) * quantidade;
			else pesoTotal += calcularPesoMaterial(cilindro->getPeca(), cilindro->volume());
		}
	}
	return pesoTotal;
}

double EstruturaMetalica::volumeTotal() {
	double volumeTotal = 0.0;
	int quantidade = 0;
	for (const auto& cubo : cubos) {
		quantidade = cubo->getPeca().getQuantidade();
		if (quantidade > 1)
			volumeTotal += cubo->volume() * quantidade;
		else volumeTotal += cubo->volume();
	}
	for (const auto& paralelepipedo : paralelepipedos) {
		quantidade = paralelepipedo->getPeca().getQuantidade();
		if (quantidade > 1)
			volumeTotal += paralelepipedo->volume() * quantidade;
		else volumeTotal += paralelepipedo->volume();
	}
	for (const auto& cilindro : cilindros) {
		quantidade = cilindro->getPeca().getQuantidade();
		if (quantidade > 1)
			volumeTotal += cilindro->volume() * quantidade;
		else volumeTotal += cilindro->volume();
	}

	return volumeTotal;
}

double EstruturaMetalica::volumeTotal(TipoPeca tipoPeca) {
	double volumeTotal = 0.0;
	int quantidade = 0;
	for (const auto& cubo : cubos) {
		if (cubo->getPeca().getTipo() == tipoPeca) {
			quantidade = cubo->getPeca().getQuantidade();
			if(quantidade > 1)
				volumeTotal += cubo->volume() * quantidade;
			else volumeTotal += cubo->volume();
		}
	}
	for (const auto& paralelepipedo : paralelepipedos) {
		if (paralelepipedo->getPeca().getTipo() == tipoPeca) {
			quantidade = paralelepipedo->getPeca().getQuantidade();
			if (quantidade > 1)
				volumeTotal += paralelepipedo->volume() * quantidade;
			else volumeTotal += paralelepipedo->volume();
		}
	}
	for (const auto& cilindro : cilindros) {
		if (cilindro->getPeca().getTipo() == tipoPeca) {
			quantidade = cilindro->getPeca().getQuantidade();
			if (quantidade > 1)
				volumeTotal += cilindro->volume() * quantidade;
			else volumeTotal += cilindro->volume();
		}
	}
	
	return volumeTotal;
}

double EstruturaMetalica::areaTotal() {
	double areaTotal = 0.0;
	int quantidade = 0;

	for (const auto& cubo : cubos) {
		quantidade = cubo->getPeca().getQuantidade();
		if (quantidade > 1)
			areaTotal += cubo->area() * quantidade;
		else areaTotal += cubo->area();
	}
	
	for (const auto& paralelepipedo : paralelepipedos) {
		quantidade = paralelepipedo->getPeca().getQuantidade();
		if (quantidade > 1)
			areaTotal += paralelepipedo->area() * quantidade;
		else areaTotal += paralelepipedo->area();
	}
	
	for (const auto& cilindro : cilindros) {
		quantidade = cilindro->getPeca().getQuantidade();
		if (quantidade > 1)
			areaTotal += cilindro->area() * quantidade;
		else areaTotal += cilindro->area();
	}

    return areaTotal;
}

double EstruturaMetalica::areaTotal(TipoMaterial tipoMaterial) {
	double areaTotal = 0.0;
	int quantidade = 0;
	for (const auto& cubo : cubos) {
		if (cubo->getPeca().getMaterial().getTipo() == tipoMaterial) {
			quantidade = cubo->getPeca().getQuantidade();
			if (quantidade > 1)
				areaTotal += cubo->area() * quantidade;
			else areaTotal += cubo->area();
		}
	}
	for (const auto& paralelepipedo : paralelepipedos) {
		if (paralelepipedo->getPeca().getMaterial().getTipo() == tipoMaterial) {
			quantidade = paralelepipedo->getPeca().getQuantidade();
			if (quantidade > 1)
				areaTotal += paralelepipedo->area() * quantidade;
			else areaTotal += paralelepipedo->area();
		}
	}
	for (const auto& cilindro : cilindros) {
		if (cilindro->getPeca().getMaterial().getTipo() == tipoMaterial) {
			quantidade = cilindro->getPeca().getQuantidade();
			if (quantidade > 1)
				areaTotal += cilindro->area() * quantidade;
			else areaTotal += cilindro->area();
		}
	}
	
	return areaTotal;
}

double checarConsumoMaterial(Material material) {
	if (material.getTipo() == TipoMaterial::ALUMINIO)
		return material.CONSUMO_ALUMINIO;
	else if (material.getTipo() == TipoMaterial::FERRO)
		return material.CONSUMO_FERRO;
	return -1.0;
}

int EstruturaMetalica::calcularLatas(double consumoReal, unique_ptr <int[]> &tintas) {
	double consumoAux = consumoReal;
	
	while (consumoAux >= LATA_TINTA_CINCO_LITROS) {
		tintas[2]++;
		//cout << "Consumo: " << consumoAux << endl;
		consumoAux -= 5.0;
	}
	while (consumoAux >= LATA_TINTA_DOIS_LITROS) {
		tintas[1]++;
		//cout << "Consumo: " << consumoAux << endl;
		consumoAux -= 2.0;
	}
	while (consumoAux > 0.0) {
		tintas[0]++;
		//cout << "Consumo: " << consumoAux << endl;
		consumoAux -= 0.5;
	}
	return EXIT_SUCCESS;
}

unique_ptr<int[]> EstruturaMetalica::numeroDeLatasDeTinta() {
	auto ptrTintas = make_unique<int[]>(3);
	ptrTintas[0] = ptrTintas[1] = ptrTintas[2] = 0;
	double consumo = 0.0;
	double volume = 0.0;
	double consumoReal = 0.0;
	for (const auto& cubo : cubos) {
		consumo = checarConsumoMaterial(cubo->getPeca().getMaterial());
		volume = volumeTotal(cubo->getPeca().getTipo());
		consumoReal = volume * consumo;
		calcularLatas(consumoReal, ptrTintas);
	}
	for (const auto& paralelepipedo : paralelepipedos) {
		consumo = checarConsumoMaterial(paralelepipedo->getPeca().getMaterial());
		volume = volumeTotal(paralelepipedo->getPeca().getTipo());
		consumoReal = volume * consumo;
		calcularLatas(consumoReal, ptrTintas);
	}
	for (const auto& cilindro : cilindros) {
		consumo = checarConsumoMaterial(cilindro->getPeca().getMaterial());
		volume = volumeTotal(cilindro->getPeca().getTipo());
		consumoReal = volume * consumo;
		calcularLatas(consumoReal, ptrTintas);
	}

    return ptrTintas;
}


int main() {
	setlocale(LC_ALL, "pt-BR");
	EstruturaMetalica estrutura;
	Material material;
	TipoMaterial tipoMaterial_1, tipoMaterial_2;
	Peca peca, peca2;
	TipoPeca tipoPeca_1, tipoPeca_2, tipoPeca_3;
	Cubo cubo;
	Cilindro cilindro;
	Paralelepipedo paralelepipedo;
	tipoMaterial_1 = TipoMaterial::ALUMINIO; tipoMaterial_2 = TipoMaterial::FERRO;
	tipoPeca_1 = TipoPeca::CUBO; tipoPeca_2 = TipoPeca::PARALELEPIPEDO; tipoPeca_3 = TipoPeca::CILINDRO;
	
	material.setNome("Material_Ferro").setTipo(tipoMaterial_2);
	cout << "\nMaterial:\n" << "Nome: " << material.getNome() << endl;

	peca.setMaterial(material).setQuantidade(2).setTipo(tipoPeca_1).setNome("Viga");
	cout << "\nPeça 1:\n"
		<< "\nNome: " << peca.getNome()
		<< "\nQuantidade: " << peca.getQuantidade() << endl;
	peca2.setTipo(tipoPeca_3).setMaterial(material).setQuantidade(1).setNome("Pilar");
	cout << "\nPeça 2:\n"
		<< "\nNome: " << peca2.getNome()
		<< "\nQuantidade: " << peca2.getQuantidade() << endl;
	
	cubo.setPeca(peca).setAresta(5.0f);
	cout << "\nCubo:\n" 
		<< "\nAresta: " << cubo.getAresta() << "m" 
		<< "\nÁrea: " << cubo.area() << "m²"
		<< "\nVolume: " << cubo.volume() << "m³" << endl;

	
	cilindro.setRaio(3.0f).setAltura(4.0f).setPeca(peca2);
	cout << "\nCilindro:\n"
		<< "\nAltura: " << cilindro.getAltura() << "m"
		<< "\nRaio: " << cilindro.getRaio() << "m"
		<< "\nÁrea: " << cilindro.area() << "m²"
		<< "\nVolume: " << cilindro.volume() << "m³" << endl;
	estrutura.adicionarPeca(cubo);
	estrutura.adicionarPeca(cilindro);

	double pesoReal = estrutura.pesoTotal() / 1000.0f;

	// m³, m²
	cout << "\nEstrutura Metálica\n"
		<< "\nÁrea Total: " << estrutura.areaTotal() << "m²"
		<< "\nPeso Total: " << pesoReal << "Kg"
		<< "\nVolume Total: " << estrutura.volumeTotal() << "m³"
		<< "\nNúmero de Peças: " << estrutura.numeroDePecas() << endl;
	auto latas = estrutura.numeroDeLatasDeTinta();

	cout << "\n\nLatas de Tinta:\nLatas de 5L: " << latas[2] << endl 
	<< "Latas de 2L: " << latas[1] << endl << "Latas de 0.5L: " << latas[0];


	return EXIT_SUCCESS;
}