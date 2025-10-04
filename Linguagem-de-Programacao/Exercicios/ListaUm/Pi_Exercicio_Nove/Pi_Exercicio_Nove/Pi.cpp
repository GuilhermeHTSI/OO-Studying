#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
#include <clocale>
#include <iomanip>
#include "Pi.h"

using namespace std;

int main() {
	return Pi().calcularPi();
}

Pi::Pi(){
	this->valorPi = 0.0;
}

double Pi::calcularPi() {
	setlocale(LC_ALL, "pt-BR");
	
	Pi novoPi;
	double interacoes = 0.0;
	cout << "Digite a quantidade de interações:";
	cin >> interacoes;
	printf("\n\nIniciando o cálculo de pi...\n");
	novoPi.formulaLeibniz(interacoes, novoPi.valorPi);
	novoPi.exibirPi();
	return novoPi.valorPi;
}

double Pi::formulaLeibniz(double interacoes, double &pi) {
	size_t loopSize = 0;
	for (loopSize; loopSize <= interacoes; loopSize++) {
		pi += ((pow(-1.0, loopSize)) / (2.0 * loopSize + 1.0));
	}
	pi *= 4.0;
	return pi;
}

void Pi::exibirPi() {
	cout << endl << "-Valor cálculado de PI: " << setw(9) << setprecision(9) << this->valorPi << endl;
}
