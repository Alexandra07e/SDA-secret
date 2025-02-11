#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PROBLEMA DEPOZITE

/*#define SIZE 100

typedef struct PALET{
	int cod;
	struct PALET* next;
}PALET;

//lista secundara dinamica

typedef struct DEPOZIT {
	char nume[20];
	PALET* paleti;
}DEPOZIT;

//lista principala tablou

typedef struct {
	DEPOZIT v[SIZE];
	int dim;
}SET;

//TDA multime

PALET* creare_nod(int cod, PALET* next) {
	PALET* aux = NULL;
	if ((aux = (PALET*)malloc(sizeof(PALET))) == NULL) {
		perror(NULL);
		exit(-1);
	}
	aux->cod = cod;
	aux->next = next;
	return aux;
}

//O(1)

void adaugare_depozit(SET* s, const char* nume) {
	if (s->dim >= SIZE) {
		printf("no more space bro :(\n");
		return;
	}
	for (int i = 0; i < s->dim; i++)
		if (strcmp(s->v[i].nume, nume) == 0) {
			printf("it's already there bro..\n");
			return;
		}
	strcpy(s->v[s->dim].nume, nume);
	s->v[s->dim].paleti = NULL;
	s->dim++;
}

//O(n)


void adaugare_palet(SET *s, const char *nume,int cod) {
	for(int i=0;i<s->dim;i++)
		if (strcmp(s->v[i].nume, nume) == 0) {
			PALET* lista = s->v[i].paleti;
			if (lista == NULL || lista->cod > cod)
				lista = creare_nod(cod, lista);
			else {
				PALET* p = lista;
				while (p->next != NULL && p->next->cod < cod)
					p = p->next;
				if (p->next == NULL)
					p->next = creare_nod(cod, NULL);
				else {
					PALET* q = p->next;
					p->next = creare_nod(cod, q);
				}
			}
			s->v[i].paleti = lista;
		}
}

//O(n+p)

void eliminare(SET* s, int cod) {
	for (int i = 0; i < s->dim; i++) {
		PALET* lista = s->v[i].paleti;
		PALET* prev = NULL;

		while (lista) {
			if (lista->cod == cod) {
				PALET* aux = lista;
				lista = lista->next;
				if (prev == NULL)
					s->v[i].paleti = lista;
				else
					prev->next = lista;
				free(aux);
			}
			else {
				prev = lista;
				lista = lista->next;
			}
		}
	}
}

//O(n+p)

void afisare(SET s) {
	for (int i = 0; i < s.dim; i++) {
		printf("%s - ", s.v[i].nume);
		PALET* lista = s.v[i].paleti;
		while (lista) {
			printf("%d  ", lista->cod);
			lista = lista->next;
		}
		printf("\n");
	}
	printf("\n");
}

//O(n+p)

void eliberare(SET* s) {
	for (int i = 0; i < s->dim; i++) {
		PALET* lista = s->v[i].paleti;
		while (lista) {
			PALET* p = lista->next;
			free(lista);
			lista = p;
		}
	}
}

//O(n+p)

void p1() {
	SET s;
	s.dim = 0;

	adaugare_depozit(&s, "A");
	adaugare_depozit(&s, "B");
	adaugare_depozit(&s, "C");

	adaugare_palet(&s, "A", 345);
	adaugare_palet(&s, "A", 123);
	adaugare_palet(&s, "A", 789);
	adaugare_palet(&s, "A", 234);
	adaugare_palet(&s, "A", 456);

	adaugare_palet(&s, "B", 789);
	adaugare_palet(&s, "B", 123);
	adaugare_palet(&s, "B", 345);
	adaugare_palet(&s, "B", 456);
	adaugare_palet(&s, "B", 234);

	adaugare_palet(&s, "C", 456);
	adaugare_palet(&s, "C", 123);
	adaugare_palet(&s, "C", 789);
	adaugare_palet(&s, "C", 234);
	adaugare_palet(&s, "C", 456);

	afisare(s);
	eliminare(&s, 456);
	afisare(s);
	eliberare(&s);
}*/

/*#define SIZE 100

typedef struct PRODUS {
	int cod;
	struct PRODUS* next;
}PRODUS;

typedef struct MAGAZIN {
	char nume[100];
	PRODUS* produse;
}MAGAZIN;

typedef struct {
	MAGAZIN v[SIZE];
	int dim;
}SET;

PRODUS* creare_nod(int cod, PRODUS* next) {
	PRODUS* aux = NULL;
	if ((aux = (PRODUS*)malloc(sizeof(PRODUS))) == NULL) {
		perror(NULL);
		exit(-1);
	}
	aux->cod = cod;
	aux->next = next;
	return aux;
}

void add_magazin(SET* s, const char* nume) {
	if (s->dim >= SIZE) {
		printf("no more space man:(\n");
		return;
	}

	for(int i=0;i<s->dim;i++)
		if (strcmp(s->v[i].nume, nume) == 0) {
			printf("it's already there bro...\n");
			return;
		}

	strcpy(s->v[s->dim].nume, nume);
	s->v[s->dim].produse = NULL;
	s->dim++;
}

void add_produse(SET* s, const char* nume, int cod) {
	for (int i = 0; i < s->dim; i++) {
		if (strcmp(s->v[i].nume, nume) == 0) {
			PRODUS* lista = s->v[i].produse;
			if (lista == NULL || lista->cod > cod)
				lista = creare_nod(cod, lista);
			else {
				PRODUS* p = lista;
				while (p->next != NULL && p->next->cod < cod)
					p = p->next;
				if (p->next == NULL)
					p->next = creare_nod(cod, NULL);
				else {
					PRODUS* q = p->next;
					p->next = creare_nod(cod, q);
				}
			}
			s->v[i].produse = lista;
		}
	}
}

void eliminare(SET* s, int cod) {
	for (int i = 0; i < s->dim; i++) {
		PRODUS* lista = s->v[i].produse;
		PRODUS* prev = NULL;

		while (lista) {
			if (lista->cod == cod) {
				PRODUS* aux = lista;
				lista = lista->next;

				if (prev == NULL)
					s->v[i].produse = lista;
				else
					prev->next = lista;
				free(aux);
			}
			else {
				prev = lista;
				lista = lista->next;
			}
		}
	}
}

void afisare(SET s) {
	for (int i = 0; i < s.dim; i++) {
		printf("%s - ", s.v[i].nume);
		PRODUS* lista = s.v[i].produse;
		while (lista) {
			printf("%d ", lista->cod);
			lista = lista->next;
		}
		printf("\n");
	}
	printf("\n");
}

void eliberare(SET* s) {
	for (int i = 0; i < s->dim; i++) {
		PRODUS* lista = s->v[i].produse;
		while (lista) {
			PRODUS* p = lista->next;
			free(lista);
			lista = p;
		}
	}
}

void p2() {
	SET s;
	s.dim = 0;

	add_magazin(&s, "A");
	add_magazin(&s, "B");
	add_magazin(&s, "C");

	add_produse(&s, "A", 345);
	add_produse(&s, "A", 123);
	add_produse(&s, "A", 789);
	add_produse(&s, "A", 234);
	add_produse(&s, "A", 456);

	add_produse(&s, "B", 789);
	add_produse(&s, "B", 123);
	add_produse(&s, "B", 345);
	add_produse(&s, "B", 456);
	add_produse(&s, "B", 234);

	add_produse(&s, "C", 456);
	add_produse(&s, "C", 123);
	add_produse(&s, "C", 789);
	add_produse(&s, "C", 234);
	add_produse(&s, "C", 456);

	afisare(s);
	eliminare(&s, 123);
	afisare(s);
	eliberare(&s);
}*/

//	lista nr impar de elem, sa stergem elem din mijloc printr-o singura parcurgere

/*typedef struct LIST {
	int elem;
	struct LIST* next;
}LIST;

LIST* creare_nod(int elem, LIST* next) {
	LIST* aux = NULL;
	if ((aux = (LIST*)malloc(sizeof(LIST))) == NULL) {
		perror(NULL);
		exit(-1);
	}
	aux->elem = elem;
	aux->next = next;
	return aux;
}

LIST* inserare(int elem, LIST* lista) {
	return creare_nod(elem, lista);
}

void afisare(LIST* lista) {
	LIST* p = lista;
	while (p) {
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}

void stergere(LIST* lista) {
	LIST* p = lista;  //se muta cu o pozitie
	LIST* q = lista->next;
	LIST* prev = NULL;
	//se muta cu 2 pozitii
	while (p) {
		prev = p;
		p = p->next;
		q = q->next->next;
		if (q == NULL) {
			LIST* aux = p->next;
			prev->next = aux;
			lista = prev;
			break;
		}
	}
}

void p3() {
	LIST* lista = NULL;
	lista = inserare(11, lista);
	lista = inserare(10, lista);
	lista = inserare(9, lista);
	lista = inserare(8, lista);
	lista = inserare(7, lista);
	lista = inserare(6, lista);
	lista = inserare(5, lista);
	lista = inserare(4, lista);
	lista = inserare(3, lista);
	lista = inserare(2, lista);
	lista = inserare(1, lista);
	afisare(lista);
	stergere(lista);
	afisare(lista);
}*/

//PROBLEMA P1 liste circulare

/*typedef struct LIST {
	int elem;
	struct LIST* next;
}LIST;

LIST* creare_nod(int elem, LIST* next) {
	LIST* aux = NULL;
	if ((aux = (LIST*)malloc(sizeof(LIST))) == NULL) {
		perror(NULL);
		exit(-1);
	}
	aux->elem = elem;
	aux->next = next;
	return aux;
}

LIST* inserare(int elem, LIST* lista) {
	return creare_nod(elem, lista);
}

void afisare(LIST* lista) {
	LIST* p = lista;
	LIST* q = lista;
	while (p) {
		printf("%d ", p->elem);
		p = p->next;
		if (p == q) {
			printf("\n");
			return;
		}
	}
	printf("\n");
}

void isCyclic(LIST* lista) {
	LIST* prim = lista;
	LIST* p = lista;
	while (p->next != NULL) {
		p = p->next;
		if (p->next == prim) {
			printf("lista e ciclica bro\n");
			return;
		}
	}
	if (p->next == NULL)
		printf("lista e liniara bro\n");
}

void p4() {
	LIST* lista = NULL;
	lista = inserare(11, lista);
	lista = inserare(10, lista);
	lista = inserare(9, lista);
	lista = inserare(8, lista);
	lista = inserare(7, lista);
	lista = inserare(6, lista);
	lista = inserare(5, lista);
	lista = inserare(4, lista);
	lista = inserare(3, lista);
	lista = inserare(2, lista);
	lista = inserare(1, lista);

	LIST* nod = creare_nod(12, lista);
	LIST* p = lista;
	while (p->next)
		p = p->next;
	p->next = nod;
	afisare(lista);
	isCyclic(lista);
}*/

int main() {
	//p1();
	//p2();
	//p3();
	//p4();
	return 0;
}