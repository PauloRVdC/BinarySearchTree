#include <stdio.h>
#include <stdlib.h>
#include "arvoreBin.h"

int main () {
	no *T = NULL, *p = NULL;
	int menu = 0,valor = 0;
	printf("Arvore T:\n1-Realizar insercao na arvore T\n2-Pesquisar valor na arvore T\n"
			"3-Percurso preOrdem\n4-Percurso emOrdem\n5-Percuros posOrdem\n6-Folhas arvore\n"
			"7-Liberar arvore\n8-Contador de nos\n9-Menor no\n10-Maior no\n11-Nivel no\n"
			"12-Altura da arvore\n13-Popular arvore\n14-Remover no\n15-Teste Altura\n"
			"16-Percurso largura\n\n"
		   "0-Sair da interface de acesso\n\n");
	do {
		//scan
		printf("\nMenu: ");
		scanf("%d",&menu);
		//insert
		if (menu == 1) {
			printf("Valor a ser inserido: ");
			scanf("%d",&valor);
			if (insert(&T,valor) == 1)
				printf("Valor Inserido com sucesso!\n");
			else 
				printf("Insercao falhou!\n");
		}
		//search
		else if (menu == 2) {
			printf("No a ser pesquisado: ");
			scanf("%d",&valor);
			p = pesq_AB(&T,valor);
			if (p != NULL) 
				printf("Valor: %d\n\n", p->info);
			else 
				printf("No nao se encontra na arvore\n\n");
		}
		//percursos
		else if (menu == 3) 
			preOrdem_AB(&T);
		else if (menu == 4)
			emOrdem_AB(&T);
		else if (menu == 5)
			posOrdem_AB(&T);
		//folhas arvore
		else if (menu == 6)
			folha(&T);
		//liberar
		else if (menu == 7) {
			if (liberar(&T) == 1)
				printf("Arvore liberada!\n");
			else
				printf("Liberacao falhou!\n");
		}
		//contador de nos
		else if (menu == 8) {
			printf("Existem %d nos na arvore.\n", count(&T)); 
		}
		//menor no
		else if (menu == 9) {
			no *aux;
			aux = menor(&T);
			printf("Valor menor no: %d\n", aux->info);
		}
		//maior no
		else if (menu == 10) {
			no *aux;
			aux = maior(&T);
			printf("Valor maior no: %d\n", aux->info);
		}
		//nivel no
		else if (menu == 11) {
			printf("No a conhecer o nivel: ");
			scanf("%d",&valor);
			p = pesq_AB(&T,valor);
			if (p != NULL) {
				printf("Nivel do no = %d\n", nivel(&T,valor));
			}
			else 
				printf("No nao se encontra na arvore\n\n");
			 
		}
		//altura arvore
		else if (menu == 12) {
			printf("Altura da arvore = %d\n", altura(&T));
		}
		//popular
		else if (menu == 13) {
			if ((insert(&T,50) == 1) && (insert(&T,40) == 1) && (insert(&T,60) == 1))
				printf("50-40-60 Inseridos com sucesso!\n");
			else 
				printf("Insercao falhou!\n");
		}
		//remover no
		else if (menu == 14) {
			printf("No a ser o removido: ");
			scanf("%d",&valor);
			if (remove_AB(&T,valor) == 1)
				printf("Valor removido com sucesso!\n");
			else 
				printf("Remocao falhou!\n");
		}
		//insere teste altura
		else if (menu == 15) {
			if ((insert(&T,5000) == 1) && (insert(&T,4000) == 1) && (insert(&T,6000) == 1) &&
				(insert(&T,3500) == 1) && (insert(&T,4500) == 1) && (insert(&T,5500) == 1) &&
				(insert(&T,6500) == 1) && (insert(&T,3250) == 1) && (insert(&T,3750) == 1) &&
				(insert(&T,4250) == 1) && (insert(&T,4750) == 1) && (insert(&T,5250) == 1) &&
				(insert(&T,5750) == 1) && (insert(&T,6250) == 1) && (insert(&T,6750) == 1))
				printf("Teste altura inseridos com sucesso!\n");
			else 
				printf("Insercao falhou!\n");
		}
		//percurso largura
		else if (menu == 16) {
			largura(&T);
		}
		//tramento de entrada
		else if (menu > 16 || menu < 0)
			printf("Acao invalida\n");
	} while (menu != 0);
	if (liberar(&T) == 1)
		printf("Arvore liberada!\n");
	else
		printf("Liberacao falhou!\n");
	return 0;
}
