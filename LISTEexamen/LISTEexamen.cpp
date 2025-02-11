#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*#define SIZE 10

typedef struct STUDENT {
	char nume[15];
	int id;
	char gen;
	struct STUDENT* next;
}STUDENT;

typedef struct UNIVERSITATE {
	char nume[50];
	char adresa[100];
	int nr_studenti;
	STUDENT* student;
}UNIVERSITATE;

typedef struct SET {
	UNIVERSITATE v[SIZE];
	int dim;
}SET;


STUDENT* creare_nod(const char* nume, int id, char gen, STUDENT* next)
{
	STUDENT* aux = NULL;
	if ((aux = (STUDENT*)malloc(sizeof(STUDENT))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	aux->id = id;
	aux->gen = gen;
	aux->next = next;
	return aux;
}

void add_university(SET* s, const char* nume, const char* adresa)
{
	for(int i=0;i<s->dim;i++)
		if (strcmp(s->v[i].nume, nume) == 0)
		{
			printf("Universitatea %s deja exista!\n", nume);
			return;
		}
	strcpy(s->v[s->dim].nume, nume);
	strcpy(s->v[s->dim].adresa, adresa);
	s->v[s->dim].nr_studenti = 0;
	s->v[s->dim].student = NULL;
	s->dim++;
}

void add_student(SET* s, const char* nume_universitate, const char* nume, int id, char gen)
{
	int i;
	int ok = 1;
	for (int i = 0; i < s->dim; i++)
	{
		STUDENT* p = s->v[i].student;
		while (p != NULL)
		{
			if (p->id == id)
			{
				ok = 0;
				printf("Studentul cu id-ul %d este deja inregistrat la universitatea %s\n", id, s->v[i].nume);
				return;
			}
			p = p->next;
		}
	}

	for (i = 0; i < s->dim; i++)
	{
		if (strcmp(s->v[i].nume, nume_universitate) == 0)
		{
			s->v[i].student = creare_nod(nume, id, gen, s->v[i].student);
			return;
		}
	}
	printf("Universitatea %s nu exista!\n", nume_universitate);
}

void remove_student(SET* s, const char* nume_univ, int id)
{
	int ok = 0;
	int cnt = 0;
	for (int i = 0; i < s->dim; i++)
	{
		if (strcmp(s->v[i].nume, nume_univ) == 0)
		{
			ok = 1;
			STUDENT* lista = s->v[i].student;
			STUDENT* p = NULL, * prev = NULL;
			if (lista == NULL)
				return;
			if (lista->next == NULL && lista->id != id)
				return;
			if (lista->id == id)
			{
				p = lista;
				lista = lista->next;
				free(p);
				s->v[i].student = lista;
				return;
			}
			p = lista->next;
			prev = lista;
			while (p)
			{
				if (p->id == id)
				{
					s->v[i].nr_studenti--;
					cnt = 1;
					prev->next = p->next;
					free(p);
					break;
				}
				p = p->next;
				prev = prev->next;
			}
			s->v[i].student = lista;
		}
	}
	if (ok == 0)
		printf("Universitatea %s nu exista!\n", nume_univ);
	if (cnt == 0)
		printf("Studentul cu id-ul %d nu s-a gasit in universitatea %s!\n", id, nume_univ);
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
	{
		printf("%s - %s - ", s.v[i].nume, s.v[i].adresa);
		STUDENT* p = s.v[i].student;
		while (p != NULL)
		{
			printf("%s ", p->nume);
			p = p->next;
		}
		printf("\n");
	}
	printf("\n");
}

void main1()
{
	SET s;
	s.dim = 0;
	add_university(&s, "POLITEHNICA", "TIMISOARA");
	add_university(&s, "UNIBUC", "BUCURESTI");
	add_university(&s, "UBB", "CLUJ");

	add_student(&s, "POLITEHNICA", "Lica", 1, 'B');
	add_student(&s, "POLITEHNICA", "Nico", 2, 'F');
	add_student(&s, "UNIBUC", "Alex", 3, 'B');
	add_student(&s, "UNIBUC", "Marius", 4, 'B');
	add_student(&s, "UBB", "Adina", 5, 'F');
	add_student(&s, "UBB", "Andreea", 6, 'F');
	add_student(&s, "POLITEHNICA", "Livi", 3, 'F');
	add_student(&s, "UBB", "Stefania", 5, 'F');
	add_student(&s, "AUTOMATICA_CRV", "Dani", 7, 'B');

	afisare(s);
	printf("\n");
	remove_student(&s,"UNIBUC",3);
	remove_student(&s, "UBB", 6);
	remove_student(&s,"UBB", 1);
	remove_student(&s, "AUTOMATICA_CRV", 2);
	afisare(s);
}*/

/*typedef struct STUDENT {
	char nume[10];
	int id;
	char gen;
	struct STUDENT* next;
}STUDENT;

typedef struct UNIVERSITATE {
	char nume[50];
	char adresa[100];
	int nr_studenti;
	STUDENT* student;
	struct UNIVERSITATE* next;
}UNIVERSITATE;

UNIVERSITATE* creare_nod(const char* nume, const char* adresa, UNIVERSITATE* next)
{
	UNIVERSITATE* aux = NULL;
	if ((aux = (UNIVERSITATE*)malloc(sizeof(UNIVERSITATE))) == NULL) {
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	strcpy(aux->adresa, adresa);
	aux->nr_studenti = 0;
	aux->student = NULL;
	aux->next = next;
	return aux;
}

STUDENT* creare_nodd(const char* nume, int id, char gen, STUDENT* next)
{
	STUDENT* aux = NULL;
	if ((aux = (STUDENT*)malloc(sizeof(STUDENT))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	aux->id = id;
	aux->gen = gen;
	aux->next = next;
	return aux;
}

UNIVERSITATE* add_university(const char* nume, const char* adresa, UNIVERSITATE* lista)
{
	UNIVERSITATE* p = lista;
	while (p != NULL)
	{
		if (strcmp(p->nume, nume) == 0)
		{
			printf("Universitatea %s deja exista!\n", nume);
			return lista;
		}
		p = p->next;
	}
	return creare_nod(nume, adresa, lista);
}

UNIVERSITATE* add_student(const char *nume, int id, char gen, UNIVERSITATE* lista, const char* nume_univ)
{
	UNIVERSITATE* p = lista;
	int ok = 0;
	while (p != NULL)
	{
		STUDENT* q = p->student;
		while (q != NULL)
		{
			if (q->id == id)
			{
				printf("Studentul cu id ul %d este deja inregistrat la universitatea %s\n", id, p->nume);
				return lista;
			}
			q = q->next;
		}
		p = p->next;
	}
	p = lista;
	while (p != NULL)
	{
		if (strcmp(p->nume, nume_univ) == 0)
		{
			p->student = creare_nodd(nume, id, gen, p->student);
			p->nr_studenti++;
			ok = 1;
		}
		p = p->next;
	}
	if (ok == 0)
		printf("Universitatea %s nu s-a gasit!", nume_univ);
	return lista;
}

UNIVERSITATE* remove_university(UNIVERSITATE* lista, const char* nume_univ)
{
	UNIVERSITATE* p = NULL, * prev = NULL;
	if (lista == NULL)
		return lista;
	if (lista->next == NULL && strcmp(lista->nume, nume_univ) != 0)
		return lista;

	if (strcmp(lista->nume, nume_univ) == 0)
	{
		printf("Universitatea %s are %d studenti\n", nume_univ, lista->nr_studenti);
		p = lista;
		lista = lista->next;
		free(p);
		return lista;
	}

	p = lista->next;
	prev = lista;
	int ok = 0;
	while (p)
	{
		if (strcmp(p->nume, nume_univ) == 0)
		{
			ok = 1;
			printf("Universitatea %s are %d studenti\n", nume_univ, lista->nr_studenti);
			prev->next = p->next;
			free(p);
			break;
		}
		p = p->next;
		prev = prev->next;
	}
	if (ok == 0)
		printf("Universitatea %s nu s-a gasit\n", nume_univ);
	return lista;
}


void afisare(UNIVERSITATE* lista)
{
	UNIVERSITATE* p = lista;
	while (p != NULL)
	{
		printf("%s - %s - %d: ", p->nume, p->adresa, p->nr_studenti);
		STUDENT* q = p->student;
		while (q != NULL)
		{
			printf("%s ", q->nume);
			q = q->next;
		}
		p = p->next;
		printf("\n");
	}
	printf("\n");
}

void main2()
{
	UNIVERSITATE* lista = NULL;
	lista = add_university("POLITEHNICA", "TIMISOARA", lista);
	lista = add_university("UBB", "CLUJ", lista);
	lista = add_university("DREPT", "BUCURESTI", lista);

	lista = add_student("Ion", 1, 'B', lista, "POLITEHNICA");
	lista = add_student("Ana", 2, 'F', lista, "UBB");
	lista = add_student("Maria", 3, 'F', lista, "DREPT");
	lista = add_student("Lica", 3, 'B', lista, "POLITEHNICA");
	lista = add_student("Marius", 2, 'B', lista, "UBB");
	afisare(lista);

	printf("\n");
	lista = remove_university(lista, "POLITEHNICA");
	lista = remove_university(lista, "AVXDBGXAHSBX");
	afisare(lista);
}*/


//prob din lab

//liste simple 
/*typedef struct REZERVARE {
	char nume[20]; //dupa numele pasagerilor
	int id;
	struct REZERVARE* next;
}REZERVARE;


REZERVARE* creare_nod(const char* nume, int id,REZERVARE* next)
{
	REZERVARE* aux = NULL;
	if ((aux = (REZERVARE*)malloc(sizeof(REZERVARE))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	aux->id = id;
	aux->next = next;
	return aux;
}

REZERVARE* inserare_ordonata(REZERVARE* lista, const char* nume,int id)
{
	if (lista == NULL)
		lista = creare_nod(nume,id, lista);
	else
		if (strcmp(lista->nume, nume) > 0)
			lista = creare_nod(nume,id,lista);
		else
		{
			REZERVARE* p = lista;
			while (p->next != NULL && strcmp(p->next->nume, nume) < 0)
				p = p->next;
			if (p->next == NULL)
			{
				p->next = creare_nod(nume,id, p->next);
				p->next->next = NULL;
			}
			else
			{
				REZERVARE* q = p->next;
				p->next = creare_nod(nume,id, p->next);
				p->next->next = q;
			}
		}
	return lista;
}

REZERVARE* stergere(REZERVARE* lista, const char* nume)
{
	if (lista == NULL)
		return lista;
	if (lista->next == NULL && strcmp(lista->nume, nume) != 0)
		return lista;

	REZERVARE* p = NULL, * prev = NULL;;
	if (strcmp(lista->nume, nume) == 0)
	{
		p = lista;
		lista = lista->next;
		free(p);
		return lista;
	}

	p = lista->next;
	prev = lista;
	while (p != NULL)
	{
		if (strcmp(p->nume, nume) == 0)
		{
			prev->next = p->next;
			free(p);
			break;
		}
		p = p->next;
		prev = prev->next;
	}
	return lista;
}

void verificare(REZERVARE* lista, int id)
{
	REZERVARE* p = lista;
	while (p)
	{
		if (p->id == id)
		{
			printf("Rezervarea cu id-ul %d este pe numele %s\n", id, p->nume);
			return;
		}
		p = p->next;
	}
	printf("Nu s-a gasit rezervarea dvs!\n");
}

void afisare(REZERVARE* lista)
{
	REZERVARE* p = lista;
	while (p)
	{
		printf("%s,%d   ", p->nume,p->id);
		p = p->next;
	}
	printf("\n");
}

void main3()
{
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
		{
			printf("0.Ati iesit din meniu!\n");
			break;
		}
		case 1:
		{
			printf("1.Rezervarea unui bilet\n");
			break;
		}
		case 2:
		{
			printf("2.Anularea unei rezervari\n");
			break;
		}
		case 3:
		{
			printf("3.Verificarea datelor unei rezervari pe baza unui ID unic al rezervarii\n");
			break;
		}
		}
	}

	printf("\n\n");
	REZERVARE* lista = NULL;
	char nume[20];
	int id = 0;
	int op = 0;
	while (scanf("%d", &op) == 1 )
	{
		if (op == 0)
		{
			afisare(lista);
			printf("Ati iesit din meniu!\n");
			printf("\n");
			break;
		}
		switch (op)
		{
		case 1:
		{
			printf("Ati selectat operatia de Rezervare!\n");
			printf("Introduceti numele: ");
			scanf("%19s", nume);
			id++;
			lista = inserare_ordonata(lista, nume, id);
			printf("ID-ul dvs este %d\n", id);
			printf("\n");
			break;
		}
		case 2:
		{
			printf("Ati selectat operatia de Anulare!\n");
			printf("Introduceti numele rezervarii: ");
			scanf("%19s", nume);
			lista = stergere(lista, nume);
			printf("\n");
			break;
		}
		case 3:
		{
			int v = 0;
			printf("Ati selectat operatia de Verificare!\n");
			printf("Introduceti id-ul dvs: ");
			scanf("%d", &v);
			verificare(lista, v);
			printf("\n");
			break;
		}
		}
	}
}
}*/

//multiliste 
#define SIZE 100
typedef struct REZERVARE {
	char nume_pasager[20]; //dupa numele pasagerilor
	int id;
	struct REZERVARE* next;
}REZERVARE;

typedef struct ZBOR {
	char nume_zbor[20];
	REZERVARE* rezervari;
}ZBOR;

typedef struct SET {
	ZBOR v[SIZE];
	int dim;
}SET;


REZERVARE* creare_nod(const char* nume, int id, REZERVARE* next)
{
	REZERVARE* aux = NULL;
	if ((aux = (REZERVARE*)malloc(sizeof(REZERVARE))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume_pasager, nume);
	aux->id = id;
	aux->next = next;
	return aux;
}

void adaugare_zboruri(SET* s, const char* nume_zbor)
{
	int ok = 1;
	for (int i = 0; i < s->dim; i++)
		if (strcmp(s->v[i].nume_zbor, nume_zbor) == 0)
			ok = 0;
	if (ok == 0)
	{
		printf("Zborul exista deja!\n");
		return;
	}
	strcpy(s->v[s->dim].nume_zbor,nume_zbor);
	s->v[s->dim].rezervari = NULL;
	s->dim++;
}

void afisare_zboruri(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s ", s.v[i].nume_zbor);
	printf("\n");
}

void inserare_pasageri(SET* s, const char* nume_pasager, int id,const char *nume_zbor)
{
	if (s->dim == 0)
	{
		printf("Nu exista zboruri!\n");
		return;
	}
	for (int i = 0; i < s->dim; i++)
	{
		if (strcmp(s->v[i].nume_zbor, nume_zbor) == 0)
		{
			REZERVARE* lista = s->v[i].rezervari;
			if (lista == NULL)
				lista = creare_nod(nume_pasager, id, lista);
			else
				if (strcmp(lista->nume_pasager, nume_pasager) > 0)
					lista = creare_nod(nume_pasager, id, lista);
				else
				{
					REZERVARE* p = s->v[i].rezervari;
					while (p->next != NULL && strcmp(p->next->nume_pasager, nume_pasager) < 0)
						p = p->next;
					if (p->next == NULL)
					{
						p->next = creare_nod(nume_pasager, id, NULL);
					}
					else
					{
						REZERVARE* q = p->next;
						p->next = creare_nod(nume_pasager, id, q);
					}
				}
			s->v[i].rezervari = lista;
		}
	}

}

void anulare_rezervare(SET* s, const char* nume_pasager, const char* nume_zbor)
{
	for (int i = 0; i < s->dim; i++)
	{
		if (strcmp(s->v[i].nume_zbor, nume_zbor) == 0)
		{
			REZERVARE* lista = s->v[i].rezervari;
			REZERVARE* p = NULL, * prev = NULL;
			if (lista == NULL || (strcmp(lista->nume_pasager, nume_pasager) != 0 && lista->next == NULL))
				return;
			if (strcmp(lista->nume_pasager, nume_pasager) == 0)
			{
				p = lista;
				lista = lista->next;
				free(p);
				s->v[i].rezervari = lista;
				return;
			}
			p = lista->next;
			prev = lista;
			while (p)
			{
				if (strcmp(lista->nume_pasager, nume_pasager) == 0)
				{
					prev->next = p->next;
					free(p);
					s->v[i].rezervari = lista;
					return;
				}
				p = p->next;
				prev = prev->next;
			}
		}
	}
}

void verificare(SET s, int id,const char *zbor)
{
	for (int i = 0; i < s.dim; i++)
	{
		if (strcmp(s.v[i].nume_zbor, zbor) == 0)
		{
			REZERVARE* p = s.v[i].rezervari;
			while (p != NULL)
			{
				if (p->id == id)
				{
					printf("Rezervarea cu id-ul %d este pe numele %s\n", id, p->nume_pasager);
					return;
				}
				p = p->next;
			}
		}
	}
	printf("Nu s-a gasit rezervarea dvs!\n");

}


void afisare_rezervari(SET s)
{
	for (int i = 0; i < s.dim; i++)
	{
		printf("Zborul %s cu pasagerii: ", s.v[i].nume_zbor);
		REZERVARE* p = s.v[i].rezervari;
		while (p != NULL)
		{
			printf("%s-%d  ", p->nume_pasager, p->id);
			p = p->next;
		}
		printf("\n");
	}
	printf("\n");
}

void main3()
{
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
		{
			printf("0.Ati iesit din meniu!\n");
			break;
		}
		case 1:
		{
			printf("1.Rezervarea unui bilet\n");
			break;
		}
		case 2:
		{
			printf("2.Anularea unei rezervari\n");
			break;
		}
		case 3:
		{
			printf("3.Verificarea datelor unei rezervari pe baza unui ID unic al rezervarii\n");
			break;
		}
		}
	}

	printf("\n\n");

	SET s;
	s.dim = 0;

	adaugare_zboruri(&s, "MILANO");
	adaugare_zboruri(&s, "MADRID");
	adaugare_zboruri(&s, "PARIS");

	char nume[20],zbor[20];
	int id = 0;
	int op = 0;
	while (scanf("%d", &op) == 1)
	{
		if (op == 0)
		{
			afisare_rezervari(s);
			printf("Ati iesit din meniu!\n");
			printf("\n");
			break;
		}
		switch (op)
		{
		case 1:
		{
			printf("Ati selectat operatia de Rezervare! Zborurile disponibile sunt :");
			afisare_zboruri(s);
			printf("Introduceti numele dvs si numele zborului dorit: ");
			scanf("%19s %19s", nume,zbor);
			id++;
			inserare_pasageri(&s, nume, id, zbor);
			printf("ID-ul dvs este %d\n", id);
			printf("\n");
			break;
		}
		case 2:
		{
			printf("Ati selectat operatia de Anulare!\n");
			printf("Introduceti numele rezervarii si zborul: ");
			scanf("%19s %19s", nume,zbor);
			anulare_rezervare(&s, nume,zbor);
			printf("\n");
			break;
		}
		case 3:
		{
			int verif = 0;
			printf("Ati selectat operatia de Verificare!\n");
			printf("Introduceti id-ul dvs si zborul: ");
			scanf("%d %19s", &verif,zbor);
			verificare(s, verif, zbor);
			printf("\n");
			break;
		}
		}
	}
}

int main()
{
	//main1();
	//main2();
	main3();
	return 0;
}