#include <stdio.h>
#include <stdlib.h>

int main() {
	int numCompartimentos, numCarregamentos;
	float **compartimentos, **carregamentos;

	scanf("%d", &numCompartimentos);
	scanf("%d", &numCarregamentos);

	// Alocacao da matriz que representa os compartimentos
	compartimentos = malloc(sizeof(float*) * numCompartimentos);
	if (!compartimentos) {
		printf("Erro. Não foi possível alocar memória.\n");
	}

	for (int i = 0; i < numCompartimentos; i++) {
		compartimentos[i] = malloc(sizeof(float) * 2);
	
		if (!compartimentos[i]) {
			printf("Erro. Não foi possível alocar memória\n");
			return -1;
		}
	}

	// Alocacao da matriz que representa os carregamentos
	carregamentos = malloc(sizeof(float*) * numCarregamentos);
	if (!carregamentos) {
		printf("Erro. Não foi possível alocar memória.\n");
	}

	for (int i = 0; i < numCarregamentos; i++) {
		carregamentos[i] = malloc(sizeof(float*) * 2);
	
		if (!carregamentos[i]) {
			printf("Erro. Não foi possível alocar memória\n");
			return -1;
		}
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
	printf("max: ");
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < numCompartimentos; j++) {
			printf("%.6f x%d%d", carregamentos[i][2], i+1, j+1);
		
			if ((i == numCarregamentos-1) && (j == numCompartimentos-1)) { 
				printf(";\n\n");
			} else {
				printf(" + ");
			}	
		}
	}

	// Restrições de proporção
	for (int i = 0; i < numCompartimentos; i++) {
		for (int j = 0; j < numCarregamentos; j++) {
			printf("x%d%d", j+1, i+1);

			if (j == numCarregamentos-1) {
				printf(" - %f r = 0;\n\n", compartimentos[i][0]);
			} else {
				printf(" + ");
			}
		}
	}

	// Restrições de peso (por material)
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < numCompartimentos; j++) {
			printf("x%d%d", i+1, j+1);

			if (j == numCompartimentos-1) {
				printf(" <= %f;\n\n", carregamentos[i][0]);
			} else {
				printf(" + ");
			}
		}
	}

	// Restrições de volume 
	for (int i = 0; i < numCompartimentos; i++) {
		for (int j = 0; j < numCarregamentos; j++) {
			printf("%fx%d%d ", carregamentos[j][1]/carregamentos[j][0], j+1, i+1);
	
			if (j == numCarregamentos-1) {
				printf(" <= %f;\n\n", compartimentos[i][1]);
			} else {
				printf(" + ");
			}
		}
	}

	// Restrições de não negatividade
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < numCompartimentos; j++) {
			printf("x%d%d >= 0;\n", i+1, j+1);
		}
	}

	// Restrições para a proporção (numero de 0 a 1)
	printf("r >= 0;\n");
	printf("r <= 1;\n");

	for (int i = 0; i < numCompartimentos; i++) {
    free(compartimentos[i]);
	}
	free(compartimentos);

	for (int i = 0; i < numCarregamentos; i++) {
    free(carregamentos[i]);
	}
	free(carregamentos);

}