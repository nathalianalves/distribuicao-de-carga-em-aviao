#include <stdio.h>
#include <stdlib.h>

#define nomeArquivo "programaLinear.lp"

int main() {
	int numCompartimentos, numCarregamentos;
	float **compartimentos, **carregamentos;
//	char nomeArquivo[50] = "programaLinear.lp" ;
	FILE *arqProgramaLinear;

	scanf("%d", &numCompartimentos);
	scanf("%d", &numCarregamentos);

	// Alocacao da matriz que representa os compartimentos
	compartimentos = malloc(sizeof(float*) * numCompartimentos);
	if (!compartimentos) {
		printf("Erro. Não foi possível alocar memória para compartimentos.\n");
	}

	for (int i = 0; i < numCompartimentos; i++) {
		compartimentos[i] = malloc(sizeof(float) * 2);
	
		if (!compartimentos[i]) {
			printf("Erro. Não foi possível alocar memória para compartimentos.\n");
			return -1;
		}
	}

	// Alocacao da matriz que representa os carregamentos
	carregamentos = malloc(sizeof(float*) * numCarregamentos);
	if (!carregamentos) {
		printf("Erro. Não foi possível alocar memória para carregamentos.\n");
	}

	for (int i = 0; i < numCarregamentos; i++) {
		carregamentos[i] = malloc(sizeof(float*) * 2);
	
		if (!carregamentos[i]) {
			printf("Erro. Não foi possível alocar memória para carregamentos.\n");
			return -1;
		}
	}

	// Abre o arquivo no qual o programa será escrito
	arqProgramaLinear = fopen(nomeArquivo, "w");
	if (!arqProgramaLinear) {
		printf("Erro. Não foi possível abrir o arquivo.\n");
		return -1;
	}

	// Leitura dos dados de compartimentos
	for (int i = 0; i < numCompartimentos; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%f", &compartimentos[i][j]);
		}
	}

	// Leitura dos dados de carregamentos
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%f", &carregamentos[i][j]);
		}
	}

	// Função objetivo
	fprintf(arqProgramaLinear, "max: ");
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < numCompartimentos; j++) {
			fprintf(arqProgramaLinear, "%.6f x%d%d", carregamentos[i][2], i+1, j+1);
		
			if ((i == numCarregamentos-1) && (j == numCompartimentos-1)) { 
				fprintf(arqProgramaLinear, ";\n");
			} else {
				fprintf(arqProgramaLinear, " + ");
			}	
		}
	}
	fprintf(arqProgramaLinear, "\n");

	// Restrições de proporção
	for (int i = 0; i < numCompartimentos; i++) {
		for (int j = 0; j < numCarregamentos; j++) {
			fprintf(arqProgramaLinear, "x%d%d", j+1, i+1);

			if (j == numCarregamentos-1) {
				fprintf(arqProgramaLinear, " - %f r = 0;\n", compartimentos[i][0]);
			} else {
				fprintf(arqProgramaLinear, " + ");
			}
		}
	}
	fprintf(arqProgramaLinear, "\n");

	// Restrições de peso (por material)
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < numCompartimentos; j++) {
			fprintf(arqProgramaLinear, "x%d%d", i+1, j+1);

			if (j == numCompartimentos-1) {
				fprintf(arqProgramaLinear, " <= %f;\n", carregamentos[i][0]);
			} else {
				fprintf(arqProgramaLinear, " + ");
			}
		}
	}
	fprintf(arqProgramaLinear, "\n");

	// Restrições de volume 
	for (int i = 0; i < numCompartimentos; i++) {
		for (int j = 0; j < numCarregamentos; j++) {
			fprintf(arqProgramaLinear, "%fx%d%d ", carregamentos[j][1]/carregamentos[j][0], j+1, i+1);
	
			if (j == numCarregamentos-1) {
				fprintf(arqProgramaLinear, " <= %f;\n", compartimentos[i][1]);
			} else {
				fprintf(arqProgramaLinear, " + ");
			}
		}
	}
	fprintf(arqProgramaLinear, "\n");

	// Restrições de não negatividade
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < numCompartimentos; j++) {
			fprintf(arqProgramaLinear, "x%d%d >= 0;\n", i+1, j+1);
		}
	}

	// Restrições para a proporção (numero de 0 a 1)
	fprintf(arqProgramaLinear, "r >= 0;\n");
	fprintf(arqProgramaLinear, "r <= 1;\n");

	// Desaloca matriz de compartimentos
	for (int i = 0; i < numCompartimentos; i++) {
    free(compartimentos[i]);
	}
	free(compartimentos);

	// Desaloca matriz de carregamentos
	for (int i = 0; i < numCarregamentos; i++) {
    free(carregamentos[i]);
	}
	free(carregamentos);

	// Fecha arquivo
	fclose(arqProgramaLinear);
}