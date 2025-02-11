#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//P1

//sortari


/*#define N 5

typedef struct {
	char nume[25];
	char telefon[12];
	int an;
	int venit;
}AGENDA;

typedef struct {
	AGENDA v[N];
	int dim;
}SET;

//am ales tda multime, unde eficient tin minte tabloul de agende
//precum si dimensiunea acestuia

void swap(AGENDA* a, AGENDA* b)
{
	AGENDA aux = *a;
	*a = *b;
	*b = aux;
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s (%d %d)   ", s.v[i].nume, s.v[i].an, s.v[i].venit);
	printf("\n");
}


void sortare_dupa_venit(SET *s)
{
	int ultim = s->dim-2;
	for(int i=0;i<s->dim;i++)
		if (s->v[i].venit < 1000)
		{
			swap(&s->v[ultim], &s->v[i]);
			ultim++;
			if (ultim == s->dim)
				return;
		}
}

void sortare(SET *s)
{
	int i = 0, j = s->dim - 1;
	int cnt = 0;
	while (i < j && cnt != 2)
	{
		if (s->v[i].venit < 1000)
		{
			swap(&s->v[i], &s->v[j]);
			cnt++;
			j--;
			i++;
		}
		if (s->v[i].venit > 1000)
			i++;
	}
}

//Complexitatea acestui alg este O(n), am ales sa swap-uiesc de 2 ori, 
//folosind contorul ultim, pe care l-am setat eficient pe penultima pozitie,
//urmand sa dau return exact cand am mutat primele 2 persoane cu venitul <1000.
//totul se retine in multimea S, data ca pointer pt a suporta schimbarile facute


void sortare_alfabetica(SET* s)
{
	int i, j;
	for (i = 0; i < s->dim - 1; i++)
	{
		if(s->v[i].an>30 && s->v[i].an<40)
			for (j = i+1; j <s->dim; j++)
				if (s->v[j].an > 30 && s->v[j].an < 40)
					if (strcmp(s->v[i].nume ,s->v[j].nume)>0)
						swap(&s->v[i], &s->v[j]);
	}
}

//Am ales algoritmul BubbleSort, avand complexitatea in medie O(n^2), deoarece
//ne permite mult mai usor sa sortam DOAR persoanele cu varsta intre
//30 si 40 de ani,restul pastrandu-si pozitia, intrucat secventa
//de sortat nu este liniara, caz in care puteam folosi cu usurinta
//algoritmul Quicksort, cu complexitatea mai mica O(nlogn). Prin
//folosirea instructiunii de decizie, for-ul dupa j este utilizat
//DOAR daca persoana indeplineste conditia din comparatii. Functia swap
//are complexitatea constanta O(1).

void p2()
{
	SET s;
	s.dim = 5;

	strcpy(s.v[0].nume, "Nico");
	strcpy(s.v[0].telefon, "0760934949");
	s.v[0].an = 5;
	s.v[0].venit = 1925;

	strcpy(s.v[1].nume, "Maria");
	strcpy(s.v[1].telefon, "0760887386");
	s.v[1].an = 38;
	s.v[1].venit = 567;

	strcpy(s.v[2].nume, "Bogdan");
	strcpy(s.v[2].telefon, "0760564323");
	s.v[2].an = 31;
	s.v[2].venit = 925;

	strcpy(s.v[3].nume, "Actavian");
	strcpy(s.v[3].telefon, "0745328762");
	s.v[3].an = 22;
	s.v[3].venit = 1987;

	strcpy(s.v[4].nume, "Costi");
	strcpy(s.v[4].telefon, "0755436987");
	s.v[4].an = 34;
	s.v[4].venit = 34;

	afisare(s);
	sortare(&s);
	afisare(s);
	//insertion_sort2(&s);
	sortare_alfabetica(&s);
	afisare(s);
}*/

/*#define N 6

typedef struct {
	char nume[35];
	int salariu;
	int bonus; // 1-da, 0-nu
}ANGAJAT;

typedef struct {
	ANGAJAT v[N];
	int dim;
}SET;

//structura ANGAJAT implementeaza cerintele, iar structura
//SET este un TDA multime, care stocheaza vectorul de angajati si
//dimensiunea lui, pt a eficientiza functiile implementate ulterior


void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s (%d %d)   ", s.v[i].nume, s.v[i].salariu, s.v[i].bonus);
	printf("\n");
}

void swap(ANGAJAT* a, ANGAJAT* b)
{
	ANGAJAT aux = *a;
	*a = *b;
	*b = aux;
}

int sortare_bonus(SET* s)
{
	int i = 0, j = s->dim - 1;
	while (i < j)
	{
		if (s->v[i].bonus == 0 && s->v[j].bonus == 1)
			swap(&s->v[i], &s->v[j]);
		if (s->v[i].bonus == 1)
			i++;
		if (s->v[j].bonus == 0)
			j--;
	}
	return i;
}

//Algoritmul este eficient deoarece are complexitatea liniara 
//O(n), nu foloseste spatiu suplimentar de memorie, sortarea 
//facandu-se in situ! Fiecare element este verificat cel mult o
//data, functia swap are complexitatea constanta O(1), iar operatiile
//efectuate implica doar compararea valorilor s->v[i].bonus si
//s->v[j].bonus, ceea ce dau algoritmului ales eficienta maxima.
//la final,returnam indicele i,adica pozitia de la care se afla
//persoanele care nu au primit bonus


void quicksort(SET* s,int prim,int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;

	swap(&s->v[prim], &s->v[(prim + ultim) / 2]);
		
	ANGAJAT pivot = s->v[prim];
	while (stanga <= dreapta)
	{
		while (stanga <= ultim && s->v[stanga].salariu > pivot.salariu)
			stanga++;
		while (dreapta >= prim && pivot.salariu > s->v[dreapta].salariu)
			dreapta--;
		if (stanga < dreapta)
			swap(&s->v[stanga++], &s->v[dreapta--]);
		else
			stanga++;
	}

	swap(&s->v[dreapta], &s->v[prim]);
	if (prim < dreapta - 1)
		quicksort(s, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(s, dreapta + 1, ultim);
}

//Am ales algoritmul Quicksort, deoarece are o complexitate
//medie de O(nlogn), fiind O(n^2) worst case, facandu-l sa fie
//mai eficient decat restul, chiar daca timpul de executie poate
//fi mai ridicat comparativ cu alti algoritmi de sortare din cauza
//nr mic de date de intrare. Algoritmul este mai eficient deoarece
//porneste sortarea de la pozitia la care se afla primul angajat
//fara bonus, prin variabila retinuta anterior, la prima functie
//de sortare!

void p3()
{
	SET s;
	s.dim = 6;

	strcpy(s.v[0].nume, "Nicoleta");
	s.v[0].salariu = 2500;
	s.v[0].bonus = 1;

	strcpy(s.v[1].nume, "Alexandra");
	s.v[1].salariu = 2800;
	s.v[1].bonus = 0;

	strcpy(s.v[2].nume, "Lica");
	s.v[2].salariu = 1900;
	s.v[2].bonus = 1;

	strcpy(s.v[3].nume, "Livi");
	s.v[3].salariu = 1700;
	s.v[3].bonus = 0;

	strcpy(s.v[4].nume, "Mihnea");
	s.v[4].salariu = 3000;
	s.v[4].bonus = 0;

	strcpy(s.v[5].nume, "Bogdan");
	s.v[5].salariu = 1000;
	s.v[5].bonus = 1;

	afisare(s);
	int prim=sortare_bonus(&s);
	afisare(s);
	quicksort(&s, prim, s.dim - 1);
	afisare(s);
}*/

/*#define N 6

void swap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void sortare(int v[],int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (v[i] > 0 && v[j] <= 0)
			swap(&v[i], &v[j]);
		if (v[i] <= 0)
			i++;
		if (v[j] > 0)
			j--;
	}
}

void quicksort(int v[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;

	swap(&v[prim], &v[(prim + ultim) / 2]);

	int pivot = v[prim];
	while (stanga <= dreapta)
	{
		while (stanga <= ultim && v[stanga] < pivot)
			stanga++;
		while (dreapta >= prim && pivot < v[dreapta])
			dreapta--;
		if (stanga < dreapta)
			swap(&v[stanga++], &v[dreapta--]);
		else
			stanga++;
	}

	swap(&v[dreapta], &v[prim]);

	if (prim < dreapta - 1)
		quicksort(v, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(v, dreapta + 1, ultim);
}

//am folosit quicksort deoarece are complexitatea worst case O(n^2),iar best case O(nlogn)
	//ceea ce il face cel mai eficient algoritm in cazul in care nu avem un set
	//de date de intrare prestabilit

void afisare(int v[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void p1()
{
	int v[] = { 2,1,-1,0,-3,-5 };
	int n = 6;
	afisare(v, n);
	sortare(v, n);
	quicksort(v,0,n-1);
	afisare(v, n);
}*/

/*#define N 6

typedef struct {
	char nume[35];
	int varsta;
	int premii; //1 da, 0 nu 
}STUDENT;

typedef struct {
	STUDENT v[N];
	int dim;
}SET;

//Am folosit structura STUDENT, unde implementez campurile din
//cerinta, iar structura SET este un TDA multime, care retine vectorul
//de studenti si dimensiunea lui,astfel fiind mai eficient si mai lizibil
//de implementat functiile uletrioare

void swap(STUDENT* a, STUDENT* b)
{
	STUDENT aux = *a;
	*a = *b;
	*b = aux;
}

int sortare_premii(SET* s)
{
	int i = 0, j = s->dim - 1;
	while (i < j)
	{
		if (s->v[i].premii == 0 && s->v[j].premii == 1)
			swap(&s->v[i], &s->v[j]);
		if (s->v[i].premii == 1)
			i++;
		if (s->v[j].premii == 0)
			j--;
	}
	return j;
}

//Algoritmul este eficient, deoarece are complexitatea O(n) liniara, iar fiecare
//element al tabloului este accesat cel mult o data. Nu foloseste spatiu
//de memorie suplimentar, fiindca sortarea este realizata in situ,
//iar functia swap are complexitatea constanta O(1), singurele operatii
//efectuate fiind cele de comparare in care sunt implicate variabilele
//s->v[i].premii si s->v[j].premii. La final, returnam pozitia in
//tablou a ultimului student premiat, ce ne va ajuta in functia de 
//sortare implementata ulterior

void quicksort(SET *s, int prim, int ultim)
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

//Am ales algoritmul Quicksort,deoarece are,in medie, o complexitate
//de O(nlogn), worst case fiind O(n^2), chiar daca timpul de executie
//poate fi mai ridicat comparativ cu alti algoritmi de sortare din cauza
//dimensiunii mici a setului de date de intrare. Pentru o eficienta
//si mai mare, am returnat in fct anterioara pozitia la care se afla
//ultimul student premiat in tablou, iar sortarea Quicksort se termina
//cand acel indice este atins

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s - %d  ", s.v[i].nume, s.v[i].premii);
	printf("\n");
}

void p4()
{
	SET s;
	s.dim = 5;

	strcpy(s.v[0].nume, "Alexandra");
	s.v[0].varsta = 21;
	s.v[0].premii = 1;

	strcpy(s.v[1].nume, "Nicoleta");
	s.v[1].varsta = 20;
	s.v[1].premii = 1;

	strcpy(s.v[2].nume, "Lica");
	s.v[2].varsta = 19;
	s.v[2].premii = 0;

	strcpy(s.v[3].nume, "Livi");
	s.v[3].varsta = 21;
	s.v[3].premii = 1;

	strcpy(s.v[4].nume, "Octavian");
	s.v[4].varsta = 21;
	s.v[4].premii = 0;

	afisare(s);
	int ultim=sortare_premii(&s);
	afisare(s);
	printf("%d\n", ultim);
	quicksort(&s, 0, ultim);
	afisare(s);
}*/

/*#define N 6
typedef struct {
	char nume[25];
	int puncte;
	int buget;
}ECHIPA;

typedef struct {
	ECHIPA v[N];
	int dim;
}SET;

void add_echipa(SET* s, const char* nume, int puncte, int buget)
{
	if (s->dim > N)
		return;
	for(int i=0;i<s->dim;i++)
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
void sortare_punctaj(SET* s)
{
	int i = 0, j = s->dim - 1;
	int l = 0, k = s->dim - 1;
	while (i < j || l < k)
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
			if (s->v[k].puncte <20)
				k--;
		}
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
		else if (temp[i1].buget > temp[i2].buget) A[index] = temp[i1++];
		else A[index] = temp[i2++];
	}
}

void sortare_buget(SET* s)
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

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s (%d-%d)  ", s.v[i].nume, s.v[i].puncte, s.v[i].buget);
	printf("\n");
}

void p5()
{
	SET s;
	s.dim = 0;

	add_echipa(&s, "INTER", 19, 876543);
	add_echipa(&s, "REAL", 78, 9999999);
	add_echipa(&s, "BARCELONA", 0, 0);
	add_echipa(&s, "ROMA", 43, 90);
	add_echipa(&s, "PSG", 67, 768743);

	afisare(s);
	printf("%d\n", s.dim);
	sortare_punctaj(&s);
	afisare(s);
	sortare_buget(&s);
	afisare(s);
}*/


int main()
{
	//p2();
	//p3();
	//p1();
	//p4();
	//p5();
	return 0;
}