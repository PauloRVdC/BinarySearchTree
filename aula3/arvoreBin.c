#include <stdio.h>
#include <stdlib.h>
#include "arvoreBin.h"
#include "list.h"
#include "fila.h"

no *new_no (int x) {
	no *novo_no = malloc(sizeof(no));
	novo_no->info = x;
	novo_no->Llink = NULL;
	novo_no->Rlink = NULL;
	return novo_no;
}

int insert (no **T, int x) {
	if ((*T) == NULL) {
		no *novo_no = new_no(x);
		*T = novo_no;
		return 1;
	}
	if (x > (*T)->info) {
		return insert(&((*T)->Rlink),x);
	}
	else if (x < (*T)->info) {
		return insert(&((*T)->Llink),x);
	}
	else 
		return 0;
}

void emOrdem_AB(no **T) {
	if((*T) != NULL) {
		emOrdem_AB(&((*T)->Llink));
		printf("\n %d", (*T)->info);
		emOrdem_AB(&((*T)->Rlink));
	}
}

void preOrdem_AB(no **T) {
	if((*T) != NULL) {
		printf("\n %d", (*T)->info);
		preOrdem_AB(&((*T)->Llink));
		preOrdem_AB(&((*T)->Rlink));
	}
}

void posOrdem_AB(no **T) {
	if((*T) != NULL) {
		posOrdem_AB(&((*T)->Llink));
		posOrdem_AB(&((*T)->Rlink));
		printf("\n %d", (*T)->info);
	}
}

void folha(no **T) {
	if((*T) != NULL) {
		folha(&((*T)->Llink));
		folha(&((*T)->Rlink));
		if ((*T)->Llink == NULL && (*T)->Rlink == NULL)
			printf("\n %d", (*T)->info);
	}	
}

int liberar(no **T) {
	if((*T) != NULL) {
		liberar(&((*T)->Llink));
		liberar(&((*T)->Rlink));
		free(*T);
		*T = NULL;
	}
	return 1;
}

int count(no **T) {
	if((*T) != NULL) {
		int ce = count(&((*T)->Llink));
		int cd = count(&((*T)->Rlink));
		return cd + ce + 1;
	}
}

no *menor(no **T) {
	if ((*T)->Llink == NULL)
		return (*T);
	else 
		return menor(&((*T)->Llink));
}

no *maior(no **T) {
	if ((*T)->Rlink == NULL)
		return (*T);
	else 
		return maior(&((*T)->Rlink));
}

int nivel(no **T, int x) {
	if ((*T) == NULL) {
		return 0;
	}
	if (x > (*T)->info) {
		int nd = nivel(&((*T)->Rlink),x);
		return nd + 1;
	}
	else if (x < (*T)->info) {
		int ne = nivel(&((*T)->Llink),x);
		return ne + 1;
	}
	else {
		return 0;
	}
}

int altura (no **T) {
	if ((*T) == NULL) 
    	return -1; 
    else {
    	int he = altura ((&(*T)->Llink));
    	int hd = altura ((&(*T)->Rlink));
    	if (he < hd) 
    		return hd + 1;
    	else 
    		return he + 1;
    }
}

no *pesq_AB (no **T, int x) {
	if ((*T) == NULL) {
		return NULL;
	}
	if ((*T)->info == x) {
		return (*T);
	}
	if (x > (*T)->info) {
		return pesq_AB(&((*T)->Rlink),x);
	}
	else if (x < (*T)->info) {
		return pesq_AB(&((*T)->Llink),x);
	}
}

/*retorno – define sucesso ou não da operação de rem
oção */
int remove_AB(no **T, int x) {
	no *p, *aux;
	if (*T == NULL) { 
		/*o nó não existe na árvore*/
		return (1);
	}
	else {
		if (x < (*T)->info) 
		/* valor menor ->subárvore esquerda*/
		remove_AB(&(*T)->Llink, x);	
		else {
			if (x > (*T)->info) 
			/* valor maior ->subárvore direita*/
			remove_AB(&(*T)->Rlink, x);
			else {
				/* valor encontrado*/
				/* no folha */
				if (((*T)->Llink == NULL) && ((*T)->Rlink == NULL)) {
					p = (*T);
					free(p);
					(*T) = NULL;
					return (1);
				}
				else{
					/* NO tem somente filho da direita */
					if ((*T)->Llink == NULL){ /* NO so tem filho direita */
						p = (*T);
						(*T) = (*T)->Rlink;
						free(p);
						return (1);
					}
					else{
						/* NO tem somente filho da esquerda */
						if ((*T)->Rlink == NULL){ 
						p = (*T);
						(*T) = (*T)->Llink;
						free((p));
						return (1);
						}
						else {
							/* NO com 2 filhos */
							p = maior(&(*T)->Llink);
							(*T)->info = p->info;
							remove_AB(&((*T)->Llink),p->info);
						}
					}
				}	
			}
		}
	}
}


void largura(no **T) {
	if (*T == NULL) return;

	//cria a lista
	list *f = new_queue(count(T));
	//seta a raiz
	enqueue((*T)->info, f);
	//instancia auxiliar
	no *aux;
	int x;

	//percurso
	while (is_empty(f) == 0) {
		aux = pesq_AB(T,peek(f));
		x = dequeue(f);
		printf("\n %d", x);
		if (aux->Llink != NULL) {
			enqueue(aux->Llink->info, f);
		} 
		if (aux->Rlink != NULL) {
			enqueue(aux->Rlink->info, f);
		}
	}
}

/*void largura(no **T) {
	if (T == NULL) return;

	list *f = new_queue(count(T));
	enqueue((*T)->info, f);
	no *aux;

	while (is_empty(f) == 0) {
		aux = pesq_AB(T,peek(f));
		printf("\n %d", aux->info);
		dequeue(f);
		if (aux->Llink != NULL) {
			enqueue(aux->Llink->info, f);
		} 
		if (aux->Rlink != NULL) {
			enqueue(aux->Rlink->info, f);
		}
	}
}*/