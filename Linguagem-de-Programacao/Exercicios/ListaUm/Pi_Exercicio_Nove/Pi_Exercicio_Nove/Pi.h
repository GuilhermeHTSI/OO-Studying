#pragma once

class Pi {
	public:
		// Valor principal de pi a ser cálculado.
		double valorPi;
		// Construtor Pi.
		Pi();

		// Executa o cálculo de Pi através da fórmula de Leibniz.
		double calcularPi();

		double formulaLeibniz(double interacoes, double &pi);

		void exibirPi();
};