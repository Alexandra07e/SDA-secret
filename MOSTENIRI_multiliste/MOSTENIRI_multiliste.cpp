#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

typedef struct {
	char nume[25];
	int puncte;
	int buget;
	char oras[25];
}ECHIPA;

typedef struct {
	ECHIPA v[N];
	int dim;
}SET;

//In structura ECHIPA am implementat elementele unei echipe,apoi in structura SET am implementat tabloul de structuri si dimensiunea, fiind un TDA multime
//pentru a facilita lucrul cu fuunctiile si pt lizibilitate!


void add_echipa(SET* s, const char* nume, int puncte, int buget)
{
	if (s->dim > N)
		return;
	for (int i = 0; i < s->dim; i++)
		if (strcmp(s->v[i].nume, nume) == 0)
		{
			printf("ECHIPA EXISTA DEJA!\n");
			return;
		}
	strcpy(s->v[s->dim].nume, nume);
	s->v[s->dim].puncte = puncte;
	s->v[s->dim].buget = buget;
	s->dim++;
}

void swap(ECHIPA* a, ECHIPA* b)
{
	ECHIPA aux = *a;
	*a = *b;
	*b = aux;
}

void sortare_wow(SET* s)
{
	int i = 0, j = s->dim - 2;
	int l = 0, k = s->dim - 2;
	while (i < j || l<k)
	{
		if (i < j)
		{
			if (s->v[i].puncte <= 45 && s->v[j].puncte > 45)
				swap(&s->v[i], &s->v[j]);
			if (s->v[i].puncte > 45)
				i++;
			if (s->v[j].puncte <= 45)
				j--;

		}

		if (l < k)
		{
			if (s->v[l].puncte < 20 && s->v[k].puncte >= 20)
				swap(&s->v[l], &s->v[k]);
			if (s->v[l].puncte >= 20)
				l++;
			if (s->v[k].puncte < 20)
				k--;
		} 
	}
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s (%d-%d)   ", s.v[i].nume, s.v[i].puncte, s.v[i].buget);
	printf("\n");
}

void mergesort(ECHIPA A[], ECHIPA temp[], int left, int right) 
{
	if (left == right) return; // secventa de un element
	int mid = (left + right) / 2;

	mergesort(A, temp, left, mid);
	mergesort(A, temp, mid + 1, right);

	for (int i = left; i <= right; i++) 
		temp[i] = A[i]; // se copiaza secventa in temp

	int i1 = left; 
	int i2 = mid + 1; 
	
	// interclasare inapoi in A
	for (int index = left; index <= right; index++) {
		if (i1 == mid + 1) A[index] = temp[i2++];  // s-a epuizat secventa din stanga
		else if (i2 > right) A[index] = temp[i1++]; // s-a epuizat secventa din dreapta
		else if (temp[i1].buget > temp[i2].buget) A[index] = temp[i1++];
		else A[index] = temp[i2++];
	}
}

void sorteaza_dupa_buget(SET* s)
{
	ECHIPA eligibili[N];
	int temp_dim = 0;

	for(int i=0;i<s->dim;i++)
		if (s->v[i].buget > 100000)
		{
			eligibili[temp_dim] = s->v[i];
			temp_dim++;
		}

	ECHIPA temp_sort[N];
	mergesort(eligibili, temp_sort, 0, temp_dim - 1);

	int index = 0;
	for(int i=0;i<s->dim;i++)
		if (s->v[i].buget > 100000)
		{
			s->v[i] = eligibili[index];
			index++;
		}
}


void p1()
{
	/*SET s;
	s.dim = 5;

	strcpy(s.v[0].nume, "REAL");
	s.v[0].puncte = 19;
	s.v[0].buget = 90908;
	strcpy(s.v[0].oras, "Madrid");

	strcpy(s.v[1].nume, "ATALANTA");
	s.v[1].puncte = 87;
	s.v[1].buget = 176324;
	strcpy(s.v[1].oras, "Atlanta");

	strcpy(s.v[2].nume, "INTER");
	s.v[2].puncte = 16;
	s.v[2].buget = 154098;
	strcpy(s.v[2].oras, "Milano");

	strcpy(s.v[3].nume, "ASROMA");
	s.v[3].puncte = 44;
	s.v[3].buget = 9090098;
	strcpy(s.v[3].oras, "Roma");

	strcpy(s.v[4].nume, "LIVERPOOL");
	s.v[4].puncte = 98;
	s.v[4].buget = 909080;
	strcpy(s.v[4].oras, "Liverpool");

	afisare(s);
	sortare_wow(&s);
	afisare(s);
	sorteaza_dupa_buget(&s);
	afisare(s);*/

	SET s;
	s.dim = 0;

	add_echipa(&s, "INTER", 19, 876543);
	add_echipa(&s, "REAL", 78, 9999999);
	add_echipa(&s, "BARCELONA", 0, 0);
	add_echipa(&s, "ROMA", 43, 90);
	add_echipa(&s, "PSG", 67, 768743);

	afisare(s);
	sortare_wow(&s);
	afisare(s);
}


//prob cu agenda lmao

/*typedef struct {
	char nume[25];
	char telefon[12];
	int an;
	int venit;
}AGENDA;

typedef struct {
	AGENDA v[N];
	int dim;
}SET;

void swap(AGENDA* a, AGENDA* b)
{
	AGENDA aux = *a;
	*a = *b;
	*b = aux;
}

void sorteaza_venit(SET* s)
{
	int i = 0, j = s->dim - 1;
	while (i < j && j != s->dim - 3)
	{
		if (s->v[i].venit < 1000)
		{
			swap(&s->v[i], &s->v[j]);
			j--;
			i++;
		}
		if (s->v[i].venit > 1000)
			i++;
	}
}


void mergesort(AGENDA A[], AGENDA temp[], int left, int right) {
	if (left == right) return; // secventa de un element
	int mid = (left + right) / 2;
	mergesort(A, temp, left, mid);
	mergesort(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++) temp[i] = A[i]; // se copiaza secventa in temp
	int i1 = left; int i2 = mid + 1; // interclasare inapoi in A
	for (int index = left; index <= right; index++) {
		if (i1 == mid + 1) A[index] = temp[i2++];  // s-a epuizat secventa din stanga
		else if (i2 > right) A[index] = temp[i1++]; // s-a epuizat secventa din dreapta
		else if (strcmp(temp[i1].nume ,temp[i2].nume)<0) A[index] = temp[i1++];
		else A[index] = temp[i2++];
	}
}

void sorteaza_dupa_nume(SET* s)
{
	AGENDA eligibili[N];
	int temp_dim = 0;

	for(int i=0;i<s->dim;i++)
		if (s->v[i].an >= 30 && s->v[i].an <= 40)
		{
			eligibili[temp_dim] = s->v[i];
			temp_dim++;
		}

	AGENDA temp_sort[N];

	mergesort(eligibili, temp_sort, 0, temp_dim - 1);

	int index = 0;
	for(int i=0;i<s->dim;i++)
		if (s->v[i].an >= 30 && s->v[i].an <= 40)
		{
			s->v[i] = eligibili[index];
			index++;
		}
}


void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s (%d-%d)   ", s.v[i].nume, s.v[i].an, s.v[i].venit);
	printf("\n");
}

void p2()
{
	SET s;
	s.dim = 5;

	strcpy(s.v[0].nume, "Nicoleta");
	strcpy(s.v[0].telefon, "0745321876");
	s.v[0].an = 32;
	s.v[0].venit = 987;

	strcpy(s.v[1].nume, "Alexandra");
	strcpy(s.v[1].telefon, "0745321876");
	s.v[1].an = 17;
	s.v[1].venit = 9870;

	strcpy(s.v[2].nume, "Lica");
	strcpy(s.v[2].telefon, "0745321876");
	s.v[2].an = 33;
	s.v[2].venit = 987;

	strcpy(s.v[3].nume, "Costi");
	strcpy(s.v[3].telefon, "0745321876");
	s.v[3].an = 38;
	s.v[3].venit = 987;

	strcpy(s.v[4].nume, "Octavian");
	strcpy(s.v[4].telefon, "0745321876");
	s.v[4].an = 33;
	s.v[4].venit = 98;

	afisare(s);
	sorteaza_venit(&s);
	afisare(s);
	sorteaza_dupa_nume(&s);
	afisare(s);
}*/


//AICI INCEP MULTILISTELEEEEEEE

/*#define N 3

typedef struct PALETI{
	int cod;
	struct PALETI* next;
}PALETI;

typedef struct {
	char nume_dep[20];
	PALETI* paleti;
}DEPOZITE;

typedef struct {
	DEPOZITE v[N];
	int dim;
}SET;

PALETI* creare_nod(int cod, PALETI* next)
{
	PALETI* aux = NULL;
	if ((aux = (PALETI*)malloc(sizeof(PALETI))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	aux->cod = cod;
	aux->next = next;
	return aux;
}

void add_depozit(SET* s, const char* nume)
{
	strcpy(s->v[s->dim].nume_dep, nume);
	s->v[s->dim].paleti = NULL;
	s->dim++;
}

void add_palet(SET* s, int cod, const char* nume_dep)
{
	for (int i = 0; i < s->dim; i++)
	{
		if (strcmp(s->v[i].nume_dep, nume_dep) == 0)
		{
			PALETI* lista = s->v[i].paleti;
			if (lista == NULL || lista->cod>cod)
				lista = creare_nod(cod, lista);
			else
			{
				PALETI* p = lista;
				while (p->next != NULL && p->next->cod < cod)
					p = p->next;

				if (p->next == NULL)
					p->next = creare_nod(cod, NULL);
				else
				{
					PALETI* q = p->next;
					p->next = creare_nod(cod, q);
				}
			}
			s->v[i].paleti = lista;
		}

	}
}

//INSERAREA ARE COMPLEXITATEA O(n+p) 

void eliminare(SET* s, int cod)
{
	for (int i = 0; i < s->dim; i++)
	{
		PALETI* lista = s->v[i].paleti;
		PALETI* p = NULL;
		PALETI *prev = NULL;
		if (lista->cod == cod)
		{
			p = lista;
			lista = lista->next;
			free(p);
		}
		else
		{
			p = lista->next;
			prev = lista;
			while (p)
			{
				if (p->cod == cod)
				{
					prev->next = p->next;
					free(p);
					break;
				}
				p = p->next;
				prev = prev->next;
			}
		}
		s->v[i].paleti = lista;
	}
}

//STERGERE COMPLEX O(n+p)

void eliberare(SET* s)
{
	for (int i = 0; i < s->dim; i++)
	{
		PALETI* lista = s->v[i].paleti;
		PALETI* p = NULL;
		while (lista != NULL)
		{
			p = lista->next;
			free(lista);
			lista = p;
		}
	}
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
	{
		printf("%s - ", s.v[i].nume_dep);
		PALETI* p = s.v[i].paleti;
		while (p!=NULL)
		{
			printf("%d ", p->cod);
			p = p->next;
		}
		printf("\n");
	}
}

//ELIBERARE si AFISARE complx O(n+p)

void p3()
{
	SET s;
	s.dim = 0;

	add_depozit(&s, "A");
	add_depozit(&s, "B");
	add_depozit(&s, "C");

	add_palet(&s, 12, "A");
	add_palet(&s, 13, "A");
	add_palet(&s, 14, "A");

	add_palet(&s, 11, "B");
	add_palet(&s, 15, "B");
	add_palet(&s, 12, "B");

	add_palet(&s, 16, "C");
	add_palet(&s, 12,"C");
	add_palet(&s, 15, "C");

	afisare(s);
	printf("Stergem paletul 12\n");
	eliminare(&s, 12);
	afisare(s);
	eliberare(&s);
}*/


/*typedef struct PRODUSE {
	int cod;
	struct PRODUSE* next;
}PRODUSE;

typedef struct MAGAZINE {
	char nume[20];
	struct MAGAZINE* next;
	PRODUSE* produse;
}MAGAZINE;

PRODUSE* creare_nod(int cod, PRODUSE* next)
{
	PRODUSE* aux = NULL;
	if ((aux = (PRODUSE*)malloc(sizeof(PRODUSE))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	aux->cod = cod;
	aux->next = next;
	return aux;
}

MAGAZINE* creare_nod(const char* nume, MAGAZINE* next)
{
	MAGAZINE* aux = NULL;
	if ((aux = (MAGAZINE*)malloc(sizeof(MAGAZINE))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	aux->produse = NULL;
	aux->next = next;
	return aux;
}

MAGAZINE* add_magazin(const char* nume, MAGAZINE* lista)
{
	return creare_nod(nume, lista);
}

MAGAZINE* add_produs(int cod,const char *nume, MAGAZINE* lista)
{
	MAGAZINE* p = lista;
	while (p != NULL)
	{
		if (strcmp(p->nume, nume) == 0)
		{
			PRODUSE* prod = p->produse;
			if (prod == NULL || (prod->cod>cod))
				prod = creare_nod(cod, prod);
			else
			{
				PRODUSE* q = prod;
				while (q->next != NULL && q->next->cod < cod)
					q = q->next;
				if (q->next == NULL)
					q->next = creare_nod(cod, NULL);
				else
				{
					PRODUSE* pr = q->next;
					q->next = creare_nod(cod, pr);
				}
			}
			p->produse = prod;
		}
		p = p->next;
	}
	return lista;
}

MAGAZINE* sterge(MAGAZINE* lista, int cod)
{
	MAGAZINE* list = lista;
	while (list!=NULL)
	{
		PRODUSE* prod = list->produse;
		PRODUSE* p = NULL, * prev = NULL;
		if (prod->cod == cod)
		{
			p = prod;
			prod = prod->next;
			free(p);
		}
		else
		{
			p = prod->next;
			prev = prod;
			while (p)
			{
				if (p->cod == cod)
				{
					prev->next = p->next;
					free(p);
					break;
				}
				prev = prev->next;
				p = p->next;
			}
		}
		list->produse = prod;
		list = list->next;
	}
	return lista;
}

void afisare(MAGAZINE* lista)
{
	MAGAZINE* p = lista;
	while (p)
	{
		printf("%s: ", p->nume);
		PRODUSE* q = p->produse;
		while (q)
		{
			printf("%d ", q->cod);
			q = q->next;
		}
		printf("\n");
		p = p->next;
	}
}

void p4()
{
	MAGAZINE* lista = NULL;
	lista = add_magazin("A", lista);
	lista = add_magazin("B", lista);
	lista = add_magazin("C", lista);

	lista = add_produs(1, "A", lista);
	lista = add_produs(3, "A", lista);
	lista = add_produs(2, "A", lista);

	lista = add_produs(5, "B", lista);
	lista = add_produs(4, "B", lista);
	lista = add_produs(1, "B", lista);

	lista = add_produs(5, "C", lista);
	lista = add_produs(3, "C", lista);
	lista = add_produs(1, "C", lista);

	afisare(lista);
	sterge(lista, 1);
	afisare(lista);
}*/

/*#define N 4

typedef struct GPS{
	int cod;
	struct GPS* next;
}GPS;

typedef struct {
	char nume[20];
	GPS* gps;
}FIRMA;

typedef struct {
	FIRMA v[N];
	int dim;
}SET;

GPS* creare_nod(int cod, GPS* next)
{
	GPS* aux = NULL;
	if ((aux = (GPS*)malloc(sizeof(GPS))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	aux->cod = cod;
	aux->next = next;
	return aux;
}

void add_firma(SET* s, const char* nume)
{
	for (int i = 0; i < s->dim; i++)
	{
		if (strcmp(s->v[i].nume, nume) == 0)
		{
			printf("FIRMA EXISTA DEJA!\n");
			return;
		}
	}

	strcpy(s->v[s->dim].nume, nume);
	s->v[s->dim].gps = NULL;
	s->dim++;
}

void add_gps(SET* s, int cod,const char *nume)
{
	for (int i = 0; i < s->dim; i++)
	{
		if (strcmp(s->v[i].nume, nume) == 0)
		{
			GPS* lista = s->v[i].gps;
			if (lista == NULL || (lista->cod > cod))
				lista = creare_nod(cod, lista);
			else
			{
				GPS* p = lista;
				while (p->next != NULL && p->next->cod < cod)
					p = p->next;
				if (p->next == NULL)
					p->next = creare_nod(cod, p->next);
				else
				{
					GPS* q = p->next;
					p->next = creare_nod(cod, q);
				}
			}
			s->v[i].gps = lista;
		}
	}
}

void stergere_gps(SET* s, int cod)
{
	for (int i = 0; i < s->dim; i++)
	{
		GPS* lista = s->v[i].gps;
		GPS* p = NULL, * prev = NULL;
		if (lista->cod == cod)
		{
			p = lista;
			lista = lista->next;
			free(p);
		}
		else
		{
			p = lista->next;
			prev = lista;
			while (p)
			{
				if (p->cod == cod)
				{
					prev->next = p->next;
					free(p);
					break;
				}
				prev = prev->next;
				p = p->next;
			}
		}
		s->v[i].gps = lista;
	}
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
	{
		printf("%s: ", s.v[i].nume);
		GPS* p = s.v[i].gps;
		while (p)
		{
			printf("%d ", p->cod);
			p = p->next;
		}
		printf("\n");
	}
}

void eliberare(SET* s)
{
	for (int i = 0; i < s->dim; i++)
	{
		GPS* lista = NULL;
		while (s->v[i].gps != NULL)
		{
			lista = s->v[i].gps->next;
			free(s->v[i].gps);
			s->v[i].gps = lista;
		}
	}
}

void p5()
{
	SET s;
	s.dim = 0;

	add_firma(&s, "A");
	add_firma(&s, "B");
	add_firma(&s, "C");

	add_gps(&s, 5, "A");
	add_gps(&s, 2, "A");
	add_gps(&s, 1, "A");
	add_gps(&s, 4, "A");
	add_gps(&s, 3, "A");

	add_gps(&s, 4, "B");
	add_gps(&s, 3, "B");
	add_gps(&s, 5, "B");
	add_gps(&s, 51, "B");
	add_gps(&s, 1, "B");

	add_gps(&s, 6, "C");
	add_gps(&s, 5, "C");
	add_gps(&s, 9, "C");
	add_gps(&s, 52, "C");
	add_gps(&s, 8, "C");

	afisare(s);
	stergere_gps(&s, 1);
	afisare(s);
	eliberare(&s);
}*/

/*#define N 5

typedef struct STUDENT{
	char nume[10];
	struct STUDENT* next;
}STUDENT;

typedef struct {
	int id;
	char parola[10];
	STUDENT* studenti;
}CONF;

typedef struct {
	CONF v[N];
	int dim;
}SET;

STUDENT* creare_nod(const char* nume, STUDENT* next)
{
	STUDENT* aux = NULL;
	if ((aux = (STUDENT*)malloc(sizeof(STUDENT))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	aux->next = next;
	return aux;
}

void add_conf(SET* s,int id,const char *parola)
{
	if (s->dim >= N)
		return;
	for (int i = 0; i < s->dim; i++)
	{
		if (s->v[i].id == id)
		{
			printf("CONFERINTA EXISTA DEJA!\n");
			return;
		}
	}
	s->v[s->dim].id = id;
	strcpy(s->v[s->dim].parola, parola);
	s->v[s->dim].studenti = NULL;
	s->dim++;
}

void add_student(SET* s, const char* nume, int id)
{
	for (int i = 0; i < s->dim; i++)
	{
		if (s->v[i].id == id)
		{
			STUDENT* lista = s->v[i].studenti;
			if (lista == NULL || (strcmp(lista->nume, nume) > 0))
				lista = creare_nod(nume, lista);
			else
			{
				STUDENT* p = lista;
				while (p->next != NULL && strcmp(p->next->nume, nume) < 0)
					p = p->next;
				if (p->next == NULL)
					p->next = creare_nod(nume, p->next);
				else
				{
					STUDENT* q = p->next;
					p->next = creare_nod(nume, q);
				}
			}
			s->v[i].studenti = lista;
		}
	}
}

void stergere_studenti(SET* s, char ch)
{
	for (int i = 0; i < s->dim; i++)
	{
		STUDENT* lista = s->v[i].studenti;
		STUDENT* prev = NULL;

		while (lista)
		{
			if (lista->nume[0] == ch)
			{
				STUDENT* aux = lista;
				lista = lista->next;
				if (prev == NULL)
					s->v[i].studenti = lista;
				else
					prev->next = lista;
				free(aux);
			}
			else
			{
				prev = lista;
				lista = lista->next;
			}
		}
	}
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
	{
		printf("CONFERINTA %d: ", s.v[i].id);
		STUDENT* p = s.v[i].studenti;
		while (p)
		{
			printf("%s ", p->nume);
			p = p->next;
		}
		printf("\n");
	}
}

void eliberare(SET* s)
{
	for (int i = 0; i < s->dim; i++)
	{
		STUDENT* lista = s->v[i].studenti;
		STUDENT* p = NULL;
		while (lista)
		{
			p = lista->next;
			free(lista);
			lista = p;
		}
	}
}


void p6()
{
	SET s;
	s.dim = 0;

	add_conf(&s, 1234, "ABCDF");
	add_conf(&s, 2345, "ABCDF");
	add_conf(&s, 3456, "ABCDF");

	add_student(&s, "Nicoleta", 1234);
	add_student(&s, "Alexandra", 1234);
	add_student(&s, "Octavian", 1234);
	add_student(&s, "Andra", 1234);
	add_student(&s, "Bogdan", 1234);

	add_student(&s, "Maria", 2345);
	add_student(&s, "Anda", 2345);
	add_student(&s, "Nicoleta", 2345);
	add_student(&s, "Lica", 2345);

	add_student(&s, "Ana", 3456);
	add_student(&s, "Nicoleta", 3456);
	add_student(&s, "Anca", 3456);

	afisare(s);
	stergere_studenti(&s, 'N');
	afisare(s);
}*/

/*#define SIZE 10

typedef struct {
	int id_con;
	char nume_con[35];
	char ocupatie_con[35];
}CONEXIUNI;

typedef struct PERSOANA{
	int id;
	char nume[35];
	char ocupatie[35];
	CONEXIUNI v[SIZE];
	int nr_conexiuni;
	struct PERSOANA* next;
}PERSOANA;

PERSOANA* creare_nod(int id, const char* nume, const char* ocupatie, PERSOANA* next)
{
	PERSOANA* aux = NULL;
	if ((aux = (PERSOANA*)malloc(sizeof(PERSOANA))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	strcpy(aux->ocupatie, ocupatie);
	aux->id = id;
	aux->nr_conexiuni = 0;
	aux->next = next;
	return aux;
}

PERSOANA* add_persoana(PERSOANA* lista, int id, const char* nume, const char* ocupatie)
{
	return creare_nod(id, nume, ocupatie, lista);
}

PERSOANA* add_conexiune(PERSOANA* lista, int id, const char* nume, const char* ocupatie,const char *nume_persoana)
{
	PERSOANA* p = lista;
	while (p != NULL)
	{
		if (strcmp(p->nume, nume_persoana) == 0)
		{
			if (p->nr_conexiuni >= SIZE)
			{
				printf("PREA MULTE CONEXIUNI!");
				return lista;
			}

			p->v[p->nr_conexiuni].id_con = id;
			strcpy(p->v[p->nr_conexiuni].nume_con, nume);
			strcpy(p->v[p->nr_conexiuni].ocupatie_con, ocupatie);
			p->nr_conexiuni++;
		}
		p = p->next;
	}
	return lista;
}

void afisare(PERSOANA* lista)
{
	PERSOANA* p = lista;
	while (p)
	{
		printf("%s-%d-%s ; CONEXIUNI: %d ,  ", p->nume, p->id, p->ocupatie,p->nr_conexiuni);
		for (int i = 0; i < p->nr_conexiuni; i++)
			printf("%s ", p->v[i].nume_con);
		printf("\n");
		p = p->next;
	}
}

void eliberare(PERSOANA* lista)
{
	PERSOANA* p = NULL;
	while (lista)
	{
		p = lista->next;
		free(lista);
		lista = p;
	}
}


void p7()
{
	PERSOANA* lista = NULL;

	lista = add_persoana(lista, 1, "Ale", "wtf");
	lista = add_persoana(lista, 2, "Nico", "queen");
	lista = add_persoana(lista, 3, "Lica", "varcelona");

	lista = add_conexiune(lista, 4, "Livi", "bro", "Lica");
	lista = add_conexiune(lista, 1, "Ale", "wtf", "Lica");
	lista = add_conexiune(lista, 1, "Ale", "wtf", "Nico");
	lista = add_conexiune(lista, 3, "Lica", "varcelona", "Nico");
	lista = add_conexiune(lista, 5, "Alex", "BMW", "Ale");
	lista = add_conexiune(lista, 6, "TOT ALEX", "TOT BMW", "Ale");

	afisare(lista);
	eliberare(lista);
}*/
/*#define SIZE 10

typedef struct STUDENT{
	char nume[20];
	struct STUDENT* next;
}STUDENT;

typedef struct CONF {
	int id;
	char parola[10];
	STUDENT* studenti;
}CONF;

typedef struct {
	CONF v[4];
	int dim;
}SET;

STUDENT* creare_nod(const char* nume, STUDENT* next)
{
	STUDENT* aux = NULL;
	if ((aux = (STUDENT*)malloc(sizeof(STUDENT))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	aux->next = next;
	return aux;
}

void add_conferinta(SET* s, int id, const char* parola)
{
	if (s->dim > SIZE)
		return;
	for(int i=0;i<s->dim;i++)
		if (s->v[i].id == id)
		{
			printf("CONFERINTA DEJA EXISTA!!");
			return;
		}

	s->v[s->dim].id = id;
	strcpy(s->v[s->dim].parola, parola);
	s->v[s->dim].studenti = NULL;
	s->dim++;
}

void add_studenti(SET* s, int id, const char* nume)
{
	for (int i = 0; i < s->dim; i++)
	{
		if (s->v[i].id == id)
		{
			STUDENT* lista = s->v[i].studenti;
			if (lista == NULL || strcmp(lista->nume, nume) > 0)
				lista = creare_nod(nume, lista);
			else
			{
				STUDENT* p = lista;
				while (p->next != NULL && strcmp(p->next->nume, nume) < 0)
					p = p->next;
				if (p->next == NULL)
					p->next = creare_nod(nume, NULL);
				else
				{
					STUDENT* q = p->next;
					p->next = creare_nod(nume, q);
				}
			}
			s->v[i].studenti = lista;
		}
	}
}

void stergere_studenti(SET* s, char ch)
{
	for (int i = 0; i < s->dim; i++)
	{
		STUDENT* lista = s->v[i].studenti;
		STUDENT* prev = NULL;

		while (lista)
		{
			if (lista->nume[0] == ch)
			{
				STUDENT* aux = lista;
				lista = lista->next;

				if (prev == NULL)
					s->v[i].studenti = lista;
				else
					prev->next = lista;
				free(aux);
			}
			else
			{
				prev = lista;
				lista = lista->next;
			}
		}
	}
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
	{
		printf("CONF %d: ", s.v[i].id);
		STUDENT* p = s.v[i].studenti;
		while (p)
		{
			printf("%s ", p->nume);
			p = p->next;
		}
		printf("\n");
	}
}

void eliberare(SET* s)
{
	for (int i = 0; i < s->dim; i++)
	{
		STUDENT* aux = NULL;
		while (s->v[i].studenti)
		{
			aux = s->v[i].studenti->next;
			free(s->v[i].studenti);
			s->v[i].studenti = aux;
		}
	}
}

void p8()
{
	SET s;
	s.dim = 0;

	add_conferinta(&s, 12, "abc");
	add_conferinta(&s, 23, "abc");
	add_conferinta(&s, 34, "abc");

	add_studenti(&s, 12, "Nico");
	add_studenti(&s, 12, "Livi");
	add_studenti(&s, 12, "Lica");
	add_studenti(&s, 12, "Anca");
	add_studenti(&s, 12, "Maria");

	add_studenti(&s, 23, "Ale");
	add_studenti(&s, 23, "Nicolas");
	add_studenti(&s, 23, "Lonia");
	add_studenti(&s, 23, "Lavi");
	add_studenti(&s, 23, "Nico");

	add_studenti(&s, 34, "Ana");
	add_studenti(&s, 34, "Levi");
	add_studenti(&s, 34, "Lorena");
	add_studenti(&s, 34, "Luiziana");
	add_studenti(&s, 34, "Nico");

	afisare(s);
	char ch;
	scanf("%c", &ch);
	stergere_studenti(&s, ch);
	afisare(s);
}*/

/*typedef struct STUDENT {
	char nume[20];
	struct STUDENT* next;
}STUDENT;

typedef struct CONF {
	int id;
	STUDENT* studenti;
	struct CONF* next;
}CONF;

STUDENT* creare_nod(const char* nume, STUDENT* next)
{
	STUDENT* aux = NULL;
	if ((aux = (STUDENT*)malloc(sizeof(STUDENT))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	aux->next = next;
	return aux;
}

CONF* creare_nod(int id, CONF* next)
{
	CONF* aux = NULL;
	if ((aux = (CONF*)malloc(sizeof(CONF))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	aux->id = id;
	aux->next = next;
	aux->studenti = NULL;
	return aux;
}

CONF* add_conferinta(CONF* lista, int id)
{
	return creare_nod(id, lista);
}

CONF* add_studenti(CONF* lista, int id, const char *nume)
{
	CONF* p = lista;
	while (p)
	{
		if (p->id == id)
		{
			STUDENT* q = p->studenti;
			if (q == NULL || strcmp(q->nume, nume) > 0)
				q = creare_nod(nume, q);
			else
			{
				STUDENT* a = q;
				while (a->next != NULL && strcmp(a->next->nume, nume) < 0)
					a = a->next;
				if (a->next == NULL)
					a->next = creare_nod(nume, NULL);
				else
				{
					STUDENT* b = a->next;
					a->next = creare_nod(nume, b);
				}
			}
			p->studenti = q;
		}
		p = p->next;
	}
	return lista;
}

CONF* stergere(CONF* lista, char ch)
{
	CONF* p = lista;
	while (p)
	{
		STUDENT* list = p->studenti;
		STUDENT* prev = NULL;

		while (list)
		{
			if (list->nume[0] == ch)
			{
				STUDENT* aux = list;
				list = list->next;

				if (prev == NULL)
					p->studenti = list;
				else
					prev->next = list;
				free(aux);
			}
			else
			{
				prev = list;
				list = list->next;
			}
		}
		p = p->next;
	}
	return lista;
}

void afisare(CONF* lista)
{
	CONF* p = lista;
	while (p)
	{
		printf("CONF %d: ", p->id);
		STUDENT* q = p->studenti;
		while (q)
		{
			printf("%s ", q->nume);
			q = q->next;
		}
		printf("\n");
		p = p->next;
	}
	printf("\n");
}

void eliberare_stud(CONF* lista)
{
	CONF* aux = lista;
	while (aux)
	{
		while (aux->studenti)
		{
			STUDENT* p = aux->studenti->next;
			free(aux->studenti);
			aux->studenti = p;
		}
		aux = aux->next;
	}
}

void eliberare(CONF* lista)
{
	while (lista)
	{
		eliberare_stud(lista);
		CONF* p = lista->next;
		free(lista);
		lista = p;
	}
}

void p9()
{
	CONF* lista = NULL;
	lista=add_conferinta(lista, 12);
	lista=add_conferinta(lista,23);
	lista=add_conferinta(lista, 34);

	lista=add_studenti(lista, 12, "Nico");
	lista=add_studenti(lista, 12, "Livi");
	lista=add_studenti(lista, 12, "Lica");
	lista=add_studenti(lista, 12, "Anca");
	lista=add_studenti(lista, 12, "Maria");

	lista=add_studenti(lista, 23, "Ale");
	lista=add_studenti(lista, 23, "Nicolas");
	lista=add_studenti(lista, 23, "Lonia");
	lista=add_studenti(lista, 23, "Lavi");
	lista=add_studenti(lista, 23, "Nico");

	lista=add_studenti(lista, 34, "Ana");
	lista=add_studenti(lista, 34, "Levi");
	lista=add_studenti(lista, 34, "Lorena");
	lista=add_studenti(lista, 34, "Luiziana");
	lista=add_studenti(lista, 34, "Nico");

	afisare(lista);
	stergere(lista, 'L');
	afisare(lista);
	eliberare(lista);
}*/


int main()
{
	p1();
	//p2();
	//p3();
	//p4();
	//p5();
	//p6();
	//p7();
	//p8();
	//p9();
	return 0;
}