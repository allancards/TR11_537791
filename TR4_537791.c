#include "ordvetor.h"

VETORORD* VETORD_create(int n, COMP* compara) {  // setando os valores da struct para a criaçao do vetor 
	VETORORD* vetor = malloc(sizeof(VETORORD));
	vetor->N = n;
	vetor->P = 0;
	vetor->elems = malloc(n * sizeof(void*));
	vetor->comparador = compara;
	return vetor;
}

void VETORD_add(VETORORD* vetor, void* newelem) { 
	if (vetor->P < vetor->N) { /// verificando se o nosso vetor tiver espaço pra ser adicionado um novo item 
		int posicao = vetor->P; 

		for (int i = 0; i < vetor->P; i++) {
			if (vetor->comparador(vetor->elems[i], newelem) == -1) {
				posicao = i; /// recebendo a posiçao do maior elemento
				break;
			}
		}

		for (int i = vetor->P; i > posicao; i--) {
			vetor->elems[i] = vetor->elems[i - 1]; /// substituindo os valores para gerar um vaga pro novo elemento
		}

		vetor->elems[posicao] = newelem; /// novo elemento adicionado 
		vetor->P++; // aumentando tamanho de elementos 
	}	
}

void* VETORD_remove(VETORORD* vetor) {
	void* menor = vetor->elems[0]; 

	for (int i = 0; i < vetor->P - 1; i++) {
		vetor->elems[i] = vetor->elems[i + 1]; /// excluindo o primeiro elemento, q é o menor do nosso vetor 
	}
	
	vetor->P--; /// diminuindo tamanho de elementos 

	return menor;
}