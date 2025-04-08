#include <stdio.h>
#include <stdlib.h>

int main() {
	int numCompartimentos, numCarregamentos, **compartimentos, **carregamentos;

	scanf("%d", &numCompartimentos);
	scanf("%d", &numCarregamentos);

	// Alocacao da matriz que representa os compartimentos
	compartimentos = malloc(sizeof(int) * numCompartimentos);
	if (!compartimentos) {
		printf("Erro. Não foi possível alocar memória.\n");
	}

	for (int i = 0; i < numCompartimentos; i++) {
		compartimentos[i] = malloc(sizeof(int) * 2);
	
		if (!compartimentos[i]) {
			printf("Erro. Não foi possível alocar memória\n");
			return -1;
		}
	}

	// Alocacao da matriz que representa os carregamentos
	carregamentos = malloc(sizeof(int) * numCarregamentos);
	if (!carregamentos) {
		printf("Erro. Não foi possível alocar memória.\n");
	}

	for (int i = 0; i < numCarregamentos; i++) {
		carregamentos[i] = malloc(sizeof(int) * 2);
	
		if (!carregamentos[i]) {
			printf("Erro. Não foi possível alocar memória\n");
			return -1;
		}
	}

	// Leitura dos dados de compartimentos
	for (int i = 0; i < numCompartimentos; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &compartimentos[i][j]);
		}
	}

	// Leitura dos dados de carregamentos
	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &carregamentos[i][j]);
		}
	}

	/*printf("Número de compartimentos: %d\n", numCompartimentos);
	printf("Número de carregamentos: %d\n", numCarregamentos);

	for (int i = 0; i < numCompartimentos; i++) {
		for (int j = 0; j < 2; j++) {
			printf("compartimentos[%d][%d] = %d\n", i, j, compartimentos[i][j]);
		}	
	}

	for (int i = 0; i < numCarregamentos; i++) {
		for (int j = 0; j < 3; j++) {
			printf("carregamentos[%d][%d] = %d\n", i, j, carregamentos[i][j]);
		}	
	}*/
}