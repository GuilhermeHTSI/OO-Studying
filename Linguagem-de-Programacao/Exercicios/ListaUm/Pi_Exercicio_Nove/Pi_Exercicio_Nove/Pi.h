#pragma once

class Pi {
	public:
		// Valor principal de pi a ser c�lculado.
		double valorPi;
		// Construtor Pi.
		Pi();

		// Executa o c�lculo de Pi atrav�s da f�rmula de Leibniz.
		double calcularPi();

		double formulaLeibniz(double interacoes, double &pi);

		void exibirPi();
};