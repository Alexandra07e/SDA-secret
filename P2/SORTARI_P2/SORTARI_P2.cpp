
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//PROBLEMA P1 

/*#define SIZE 100

typedef unsigned int boolean;

typedef struct {
	char enunt[201];
	int dificultate;
	boolean actualizare; //0-fals,1-adevarat
}INTREBARE;

typedef struct {
	INTREBARE v[SIZE];
	int dim;
}SET;

//Structura INTREBARE are componentele cerute in cerinta, unde pt campul actualizare am folost un typedef pt a implementa tipul boolean,
//iar structura SET este un TDA multime, pt a facilita codul si pt lizibilitate, unde tinem vectorul de intrebari si dimensiunea acestuia!

void adaugare(SET* s, const char* enunt, int dificultate, boolean actualizare)
{
	if (s->dim >= 100)
	{
		printf("nu mai e loc!\n");
		return;
	}
	for(int i=0;i<s->dim;i++)
		if (strcmp(s->v[i].enunt, enunt) == 0)
		{
			printf("intrebarea exista deja!\n");
			return;
		}
	strcpy(s->v[s->dim].enunt, enunt);
	s->v[s->dim].dificultate = dificultate;
	s->v[s->dim].actualizare = actualizare;
	s->dim++;
}

//Functia de adaugare in multime, complexitate liniara O(n) deoarece verific pt duplicate

void swap(INTREBARE* a, INTREBARE* b)
{
	INTREBARE aux = *a;
	*a = *b;
	*b = aux;
}

//Functia swap, complexitate constanta O(1)

void quicksort(SET *s, int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&s->v[prim], &s->v[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	INTREBARE pivot = s->v[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && s->v[stanga].dificultate < pivot.dificultate)
			stanga++;
		while (dreapta >= prim && pivot.dificultate < s->v[dreapta].dificultate)
			dreapta--;
		if (stanga < dreapta)
			swap(&s->v[stanga++], &s->v[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&s->v[dreapta], &s->v[prim]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(s, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(s, dreapta + 1, ultim);
}

//Am ales quicksort, deoarece are complexitatea, in medie, O(n*logn), fiind o sortare avansata eficienta,in situ, fara a folosi memorie auxiliara, chiar daca
//timpul de executie poate fi mai ridicat datorita setului mic de date de intrare comparativ cu alti algoritmi de sortare

void ordonare_dificultate(SET* s) {
	for (int i = 1; i < s->dim - 1; i++)
	{
		swap(&s->v[i], &s->v[i + 1]);
		i++;
	}
}

//Functie auxiliara pt a respecta cerinta < > < >, de complexitate liniara O(n), unde swap-uiesc elementele (complexitate O(1))

void ordonare_actualizare(SET* s) {
	int i = 0;
	int j = s->dim - 1;
	while (i < j)
	{
		if (s->v[i].actualizare==0 && s->v[j].actualizare==1)
			swap(&s->v[i], &s->v[j]);
		if (s->v[i].actualizare==1) 
			i++;
		if(s->v[j].actualizare==0)
			j--;
	}
}

//Complexitate O(n), eficient deoarece, prin folosirea celor doi indici de pozitie, sortez vectorul printr-o singura parcurgere, swap-uind doar elementele ce nu 
// respecta conditia, iar restul raman pe pozitiile lor neschimbate . Sortarea se realizeaza in situ, fara folosirea unui spatiu suplimentar de memorie

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s - %d - %d\n", s.v[i].enunt, s.v[i].dificultate, s.v[i].actualizare);
	printf("\n");
}

//Functia de afisare, complexitate O(n)

void p1(){
	SET s;
	s.dim = 0;

	adaugare(&s, "Cine te-a intrebat?", 3, 0);
	adaugare(&s, "Ce faci?", 1, 1);
	adaugare(&s, "Cine mortii mei esti?", 5, 1);
	adaugare(&s, "Cum adica?", 2, 0);
	adaugare(&s, "De ce am venit aici?", 7, 0);
	adaugare(&s, "De ce am ales aceasta facultate?", 9, 1);

	afisare(s);
	printf("\n");

	//meniul
	printf("1. Ordonare dupa dificultate\n");
	printf("2. Ordonare dupa actualizare\n");
	printf("3. Iesire\n");
	printf("--------------------------------------------\n");

	int op = 0;
	int ok = 1;
	while (ok) {
		printf("Introduceti optiunea: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
		{
			quicksort(&s, 0, s.dim - 1);
			ordonare_dificultate(&s);
			afisare(s);
			printf("\n");
			break;
		}
		case 2:
		{
			ordonare_actualizare(&s);
			afisare(s);
			printf("\n");
			break;
		}
		case 3:
		{
			afisare(s);
			printf("\n");
			ok = 0;
			break;
		}
		}
	}
}*/


//PROBLEMA CU NR INTREGI

/*#define SIZE 100

typedef struct {
	int v[SIZE];
	int dim;
}SET;

void adaugare(SET* s,int x) {
	if (s->dim >= SIZE) {
		printf("no more space man :(\n");
		return;
	}

	s->v[s->dim] = x;
	s->dim++;
}

void swap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void quicksort(SET* s, int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&s->v[prim], &s->v[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	int pivot = s->v[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && s->v[stanga] < pivot)
			stanga++;
		while (dreapta >= prim && pivot < s->v[dreapta])
			dreapta--;
		if (stanga < dreapta)
			swap(&s->v[stanga++], &s->v[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&s->v[dreapta], &s->v[prim]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(s, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(s, dreapta + 1, ultim);
}

void afisare(SET s) {
	for (int i = 0; i < s.dim; i++)
		printf("%d ", s.v[i]);
	printf("\n");
}

void p2() {
	SET s;
	s.dim = 0;

	adaugare(&s, 1);
	adaugare(&s, 6);
	adaugare(&s, -2);
	adaugare(&s, 0);
	adaugare(&s, -9);
	adaugare(&s, 3);
	adaugare(&s, -6);
	adaugare(&s, 4);

	afisare(s);
	quicksort(&s, 0, s.dim - 1);
	afisare(s);
}*/


//PROBLEMA AGENDA

/*#define SIZE 100

typedef struct {
	char nume[25];
	char telefon[11];
	int an;
	int venit;
}AGENDA;

typedef struct {
	AGENDA v[SIZE];
	int dim;
}SET;

void adaugare(SET* s,const char *nume,const char *telefon,int an,int venit) {
	if (s->dim >= SIZE) {
		printf("no more space man:(\n");
		return;
	}

	for(int i=0;i<s->dim;i++)
		if (strcmp(s->v[i].telefon, telefon) == 0) {
			printf("Acest nr de telefon exista deja!\n");
			return;
		}

	strcpy(s->v[s->dim].nume, nume);
	strcpy(s->v[s->dim].telefon, telefon);
	s->v[s->dim].an = an;
	s->v[s->dim].venit = venit;
	s->dim++;
}

void swap(AGENDA* a, AGENDA* b) {
	AGENDA aux = *a;
	*a = *b;
	*b = aux;
}

void ordonare_venit(SET* s) {
	int i = 0, j = s->dim - 1;
	while (i < j && j != s->dim - 3) {
		if (s->v[i].venit < 1000) {
			swap(&s->v[i], &s->v[j]);
			j--;
		}
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
			else if (strcmp(temp[i1].nume,temp[i2].nume)<0) A[index] = temp[i1++];
			else A[index] = temp[i2++];
		}
}

void ordonare_varsta(SET* s) {

	AGENDA eligibili[SIZE];
	int temp_dim = 0;

	for(int i=0;i<s->dim;i++)
		if (s->v[i].an > 30 && s->v[i].an < 40){
			eligibili[temp_dim] = s->v[i];
			temp_dim++;
		}

	AGENDA temp_sort[SIZE];
	mergesort(eligibili, temp_sort, 0, temp_dim - 1);
	int index=0;

	for(int i=0;i<s->dim;i++)
		if (s->v[i].an > 30 && s->v[i].an < 40) {
			s->v[i] = eligibili[index];
			index++;
		}
}

void afisare(SET s) {
	for (int i = 0; i < s.dim; i++) {
		printf("%s - %s - ani: %d - venit: %d\n", s.v[i].nume, s.v[i].telefon, s.v[i].an, s.v[i].venit);
	}
	printf("\n");
}

void p3() {
	SET s;
	s.dim = 0;

	adaugare(&s, "Maria", "0760987543", 23, 998);
	adaugare(&s, "Nicoleta", "0760987542", 35, 10009);
	adaugare(&s, "Alexandra", "0760987547", 32, 9988);
	adaugare(&s, "Bogdan", "0760987540", 22, 990);
	adaugare(&s, "Alin", "0760987541", 37, 9988);
	adaugare(&s, "Lica", "0760987544", 20, 998);
	adaugare(&s, "Cristina", "0760987545", 34, 998);
	adaugare(&s, "Zaharia", "0760987548", 38, 10087);
	adaugare(&s, "Octavian", "0760987549", 36, 99);

	afisare(s);
	ordonare_venit(&s);
	afisare(s);
	ordonare_varsta(&s);
	afisare(s);
}*/

//PROBLEMA STUDENT

/*#define SIZE 100

typedef struct {
	char nume[35];
	int varsta;
	int premii;
}STUDENT;

typedef struct {
	STUDENT v[SIZE];
	int dim;
}SET;

void adaugare(SET* s, const char *nume,int varsta,int premii) {
	if (s->dim >= SIZE) {
		printf("no more space man:(\n");
		return;
	}
	strcpy(s->v[s->dim].nume, nume);
	s->v[s->dim].varsta = varsta;
	s->v[s->dim].premii = premii;
	s->dim++;
}

void swap(STUDENT* a, STUDENT* b) {
	STUDENT aux = *a;
	*a = *b;
	*b = aux;
}

int ordonare_premii(SET* s) {
	int i = 0;
	int j = s->dim - 1;
	while (i < j) {
		if (s->v[i].premii == 0 && s->v[j].premii == 1)
			swap(&s->v[i], &s->v[j]);
		if (s->v[i].premii == 1)
			i++;
		if (s->v[j].premii == 0)
			j--;
	}
	return i;
}

void quicksort(SET* s, int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&s->v[prim], &s->v[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	STUDENT pivot = s->v[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && strcmp(s->v[stanga].nume,pivot.nume)>0)
			stanga++;
		while (dreapta >= prim && strcmp(pivot.nume ,s->v[dreapta].nume)>0)
			dreapta--;
		if (stanga < dreapta)
			swap(&s->v[stanga++], &s->v[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&s->v[dreapta], &s->v[prim]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(s, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(s, dreapta + 1, ultim);
}

void afisare(SET s) {
	for (int i = 0; i < s.dim; i++) {
		printf("%s - varsta: %d - premii: %d\n", s.v[i].nume, s.v[i].varsta, s.v[i].premii);
	}
	printf("\n");
}

void p4() {
	SET s;
	s.dim = 0;

	adaugare(&s, "Alexandra", 20, 0);
	adaugare(&s, "Icoleta", 20, 0);
	adaugare(&s, "Lica", 20, 1);
	adaugare(&s, "Livi", 20, 1);
	adaugare(&s, "Bogdan", 20, 1);
	adaugare(&s, "Maria", 20, 0);
	adaugare(&s, "Zaharia", 20, 1);

	afisare(s);
	int poz=ordonare_premii(&s);
	afisare(s);
	quicksort(&s, 0, poz);
	afisare(s);
}*/


//PROBLEMA ECHIPE

/*#define SIZE 100

typedef struct {
	char nume[25];
	int puncte;
	int buget;
	char oras[25];
}ECHIPA;

typedef struct {
	ECHIPA v[SIZE];
	int dim;
}SET;

void adaugare(SET* s, const char* nume, int puncte, int buget, const char* oras) {
	if (s->dim >= SIZE) {
		printf("no more space man:(\n");
		return;
	}

	strcpy(s->v[s->dim].nume, nume);
	s->v[s->dim].puncte = puncte;
	s->v[s->dim].buget = buget;
	strcpy(s->v[s->dim].oras, oras);
	s->dim++;
}

void swap(ECHIPA* a, ECHIPA* b) {
	ECHIPA aux = *a;
	*a = *b;
	*b = aux;
}

void ordonare_puncte(SET* s) {
	int i = 0, j = s->dim - 1;
	int k = 0, m = s->dim - 1;

	while (i < j || k < m) {
		if (s->v[i].puncte < 45 && s->v[j].puncte>45)
			swap(&s->v[i], &s->v[j]);
		if (s->v[k].puncte < 20 && s->v[m].puncte>20)
			swap(&s->v[k], &s->v[m]);

		if (s->v[i].puncte > 45)
			i++;
		if (s->v[j].puncte < 45)
			j--;
		if (s->v[k].puncte > 20)
			k++;
		if (s->v[m].puncte < 20)
			m--;
	}
}

void mergesort(ECHIPA A[], ECHIPA temp[], int left, int right) {
	if (left == right) return; // secventa de un element
	int mid = (left + right) / 2;
	mergesort(A, temp, left, mid);
	mergesort(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++) temp[i] = A[i]; // se copiaza secventa in temp
	int i1 = left; int i2 = mid + 1; // interclasare inapoi in A
	for (int index = left; index <= right; index++) {
		if (i1 == mid + 1) A[index] = temp[i2++];  // s-a epuizat secventa din stanga
		else if (i2 > right) A[index] = temp[i1++]; // s-a epuizat secventa din dreapta
		else if (temp[i1].puncte>temp[i2].puncte) A[index] = temp[i1++];
		else A[index] = temp[i2++];
	}
}

void ordonare_buget(SET* s) {
	ECHIPA eligibili[SIZE];
	int temp_dim = 0;

	for(int i=0;i<s->dim;i++)
		if (s->v[i].buget > 100000) {
			eligibili[temp_dim] = s->v[i];
			temp_dim++;
		}

	ECHIPA temp_sort[SIZE];
	mergesort(eligibili, temp_sort, 0, temp_dim - 1);

	int index = 0;
	for(int i=0;i<s->dim;i++)
		if (s->v[i].buget > 100000) {
			s->v[i] = eligibili[index];
			index++;
		}
}


void afisare(SET s) {
	for (int i = 0; i < s.dim; i++)
		printf("%s - puncte: %d - buget: %d\n", s.v[i].nume, s.v[i].puncte, s.v[i].buget);
	printf("\n");
}

void p5() {
	SET s;
	s.dim = 0;

	adaugare(&s, "Atletico", 0, 0,"Madrid");
	adaugare(&s, "Real", 80, 9999990,"Madrid");
	adaugare(&s, "Barcelona", 10, 10,"Barcelona");
	adaugare(&s, "Milan", 60, 9543217, "Milano");
	adaugare(&s, "UCV", 79,7654, "Craiova");
	adaugare(&s, "Bayern", 34, 987654, "Munchen");
	adaugare(&s, "AS Roma", 19, 6543, "Roma");
	adaugare(&s, "PSG", 65, 981234, "Paris");

	afisare(s);
	ordonare_puncte(&s);
	afisare(s);
	ordonare_buget(&s);
	afisare(s);
}*/

int main()
{
	//p1();
	//p2();
	//p3();
	//p4();
	//p5();
	return 0;
}

