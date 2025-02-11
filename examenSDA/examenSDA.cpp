#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*int fac(int n)
{
	if (n == 1)
		return n;
	else
		if (n == 0)
			return 1;
		else
			return n * fac(n - 1);
}*/

//lab 2
/*long long nElemFib(int n)
{
	if (n == 0)
		return 0;
	else
		if (n == 1)
			return 1;
		else
			return nElemFib(n - 1) + nElemFib(n - 2);
}

long long nElemFib_nerecursiv(int n)
{
	long long elem = 0;
	if (n == 0)
	{
		elem = 0;
		return elem;
	}
	if (n == 1)
	{
		elem = 1;
		return elem;
	}
	int prev1 = 0, prev2 = 1;
	for (int i = 2; i <= n; i++)
	{
		elem = prev1 + prev2;
		prev1 = prev2;
		prev2 = elem;
	}
	return elem;
}

int cmmdc(int a, int b)
{
	while (a != b)
		if (a > b)
			a = a - b;
		else
			b = b - a;
	return a;
}

int cmmdc_recursiv(int a, int b)
{
	if (a == b)
		return a;
	else
		if (a > b)
			return cmmdc_recursiv(a - b, b);
		else
			return cmmdc_recursiv(a, b - a);
}

void lab2()
{
	printf("%lld\n", nElemFib(7));
	printf("%lld\n\n", nElemFib_nerecursiv(7));
	printf("%d\n", cmmdc(14, 49));
	printf("%d\n\n", cmmdc_recursiv(14, 49));
}
*/
//lab3

/*void swap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void bubblesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(&a[j], &a[j - 1]);
}

void shakersort(int a[], int n)
{
	int sus = 1, jos = n - 1, ultim = n - 1;
	do {
		for (int j = jos; j >= sus; j--)
			if(a[j-1]>a[j])
			{
				swap(&a[j - 1], &a[j]);
				ultim = j;
			}

		sus = ultim + 1;
		for(int j=sus;j<=jos;j++)
			if (a[j - 1] > a[j])
			{
				swap(&a[j - 1], &a[j]);
				ultim = j;
			}
		jos = ultim - 1;

	} while (sus <= jos);
}


void afisare(FILE *f,int a[], int n)
{
	for (int i = 0; i < n; i++)
		fprintf(f,"%d ", a[i]);
}

void alg1(FILE* f,int a[],int n)
{
	clock_t t = clock();
	double cpu_time_used;

	bubblesort(a, n);

	t = clock() - t;
	cpu_time_used = ((double)t) / CLOCKS_PER_SEC;
	fprintf(f, "BUBBLESORT, ");
	afisare(f, a, n);
	fprintf(f, ", timp de executie: %lf\n", cpu_time_used);
}

void alg2(FILE* f, int a[], int n)
{
	clock_t t = clock();
	double cpu_time_used;

	shakersort(a, n);

	t = clock() - t;
	cpu_time_used = ((double)t) / CLOCKS_PER_SEC;
	fprintf(f, "SHAKERSORT, ");
	afisare(f, a, n);
	fprintf(f, ", timp de executie: %lf\n", cpu_time_used);
}

void fib1(FILE* f, int n1)
{
	clock_t t = clock();
	double cpu;

	long long rez = nElemFib(n1);
	t = clock() - t;
	cpu = ((double)t) / CLOCKS_PER_SEC;
	fprintf(f, "\nFIBONACCI RECURSIV, %d , timp de executie: %lf\n", n1, cpu);
}

void fib2(FILE* f, int n2)
{
	clock_t t = clock();
	double cpu;

	long long rez = nElemFib_nerecursiv(n2);
	t = clock() - t;
	cpu = ((double)t) / CLOCKS_PER_SEC;
	fprintf(f, "FIBONACCI NERECURSIV, %d , timp de executie: %lf\n", n2, cpu);
}


void lab3() {
	//problema 1
	srand(time(NULL));
	int a[1000];
	int n = 1000;
	for (int i = 0; i < n; i++)
		a[i] = rand();
	int b[1000];
	for (int i = 0; i < n; i++)
		b[i] = a[i];

	FILE* f = NULL;
	if ((f = fopen("lab3.txt", "w")) == NULL)
	{
		printf("error opening!");
		return;
	}

	alg1(f, a, n);
	alg2(f, b, n);

	//problema 2
	fib1(f, 10);
	fib2(f, 1000000);

	if (fclose(f) != 0)
	{
		printf("error closing!");
		return;
	}
}
*/

//problema clasa LAB2

/*#define SIZE 10

typedef struct {
	char nr_inmat[9];
	unsigned int an;
	char model[10];
}MASINA;

typedef struct {
	MASINA v[SIZE];
	int dimensiune;
}MULTIME;

void add_car(MULTIME *s, MASINA car)
{
	for(int i=0;i<s->dimensiune;i++)
		if (strcmp(car.nr_inmat, s->v[i].nr_inmat) == 0)
		{
			printf("Masina %s exista deja lmao!\n",car.nr_inmat);
			return;
		}
	s->v[s->dimensiune].an = car.an;
	strcpy(s->v[s->dimensiune].nr_inmat, car.nr_inmat);
	strcpy(s->v[s->dimensiune].model, car.model);
	s->dimensiune += 1;
}

void remove_car(MULTIME *s, const char* nr_inmat)
{
	if (s->dimensiune == 0)
		return;
	int ok = 0;
	for (int i = 0; i < s->dimensiune; i++)
		for (int j = i; j < s->dimensiune; j++)
			if (strcmp(s->v[i].nr_inmat, nr_inmat) == 0)
			{
				s->dimensiune--;
				s->v[j] = s->v[j + 1];
				ok = 1;
				return;
			}
	if (ok == 0)
		printf("Masina %s nu s-a gasit!\n", nr_inmat);
}

void afisare(MULTIME s)
{
	for (int i = 0; i < s.dimensiune; i++)
		printf("%s - %d - %s\n", s.v[i].nr_inmat, s.v[i].an, s.v[i].model);
}

int count(MULTIME s)
{
	return s.dimensiune;
}

void problemaLaborator2()
{
	MULTIME s;
	s.dimensiune = 0;

	MASINA car1;
	strcpy(car1.nr_inmat, "DJ99DRU");
	car1.an = 2023;
	strcpy(car1.model, "BMW");

	MASINA car2;
	strcpy(car2.nr_inmat, "DJ99DRU");
	car2.an = 2021;
	strcpy(car2.model, "BMW");

	MASINA car3;
	strcpy(car3.nr_inmat, "DJ97DRU");
	car3.an = 2021;
	strcpy(car3.model, "BMW");

	MASINA car4;
	strcpy(car4.nr_inmat, "DJ77DRA");
	car4.an = 2025;
	strcpy(car4.model, "AUDI");

	add_car(&s, car1);
	add_car(&s, car2);
	add_car(&s, car3);
	add_car(&s, car4);

	afisare(s);

	remove_car(&s, "DJ97DRU");
	remove_car(&s, "DJ97DRA");

	afisare(s);
	printf("DIMENSIUNEA: %d\n", count(s));
}
*/
//problema clasa LABORATOR 4

/*int countChar(char* s, char c)
{
	int nr = 0;
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] == c)
			nr++;
	return nr;
}

void CharWithMostAppNormal(char* s)
{
	int max = 0;
	char c;
	int nr = 0;
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		nr = countChar(s, s[i]);
		if (nr > max)
		{
			max = nr;
			c = s[i];
		}
	}
	printf("Caracterul %c apare de cele mai multe ori: %d\n", c, max);
}

void CharWithMostAppFrecventa(char* s)
{
	int max = 0;
	char c;
	int fr[26] = { 0 };
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		fr[s[i] - 'a']++;
	for(int i=0;i<26;i++)
		if (fr[i] > max)
		{
			max = fr[i];
			c = i + 'a';
		}
	printf("Caracterul %c apare de cele mai multe ori: %d\n", c, max);
}


void problemaLaborator4()
{
	clock_t t = clock();
	double cpu;

	srand(time(NULL));
	char s[101];
	int n = 100;

	for(int i=0;i<n;i++)
		s[i] = (rand() % 26) + 'a';
	s[n] = '\0';
	printf("%s\n", s);

	printf("Caracterul %c apare de %d ori\n", 'a', countChar(s, 'a'));
	CharWithMostAppNormal(s);
	CharWithMostAppFrecventa(s);

	t = clock() - t;
	cpu = ((double)t) / CLOCKS_PER_SEC;
	printf("Timpul de executie: %lf\n", cpu);
}
*/

//problema Laborator5 SORTARI

/*typedef struct {
	char isDir; //0-fisier, 1-director
	char nume[256];
	int size;
}FILES;


int compare(FILES a, FILES b)
{
	if (a.isDir != b.isDir)
		return b.isDir - a.isDir;
	if (a.size != b.size)
		return a.size - b.size;
	return strcmp(a.nume, b.nume);
}

/*void swap(FILES* a, FILES* b)
{
	FILES aux = *a;
	*a = *b;
	*b = aux;
}*/

/*void SelectionSort(FILES v[], int n)
{
	int i, j, min; // min retine INDEXUL elementului cu valoare minima
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (compare(v[j],v[min])<0)
				min = j;
		}
		swap(&v[min], &v[i]);
	}
}

void InsertionSort(FILES v[], int n)
{
	int i, j;
	FILES tmp;
	for (i = 1; i < n; i++)
	{
		tmp = v[i];
		for (j = i; (j > 0) && (compare(tmp,v[j-1])<0); j--)
			v[j] = v[j - 1];
		v[j] = tmp;
	}
}

void quicksort(FILES v[], int prim,int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;

	//alegere pivot
	swap(&v[prim], &v[(prim + ultim) / 2]);

	//mutare pivot pe prima pozitie
	FILES pivot = v[prim];

	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && compare(v[stanga],pivot)<0)
			stanga++;
		while (dreapta >= prim && compare(pivot,v[dreapta]) < 0)
			dreapta--;
		if (stanga < dreapta)
			swap(&v[stanga++], &v[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&v[dreapta], &v[prim]);

	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(v, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(v, dreapta + 1, ultim);
}

void quicksort2(FILES v[], int prim, int ultim)
{

	int stanga = prim + 1;
	int dreapta = ultim;
	FILES pivot = v[prim];
	if (ultim - prim + 1 <= 7)
	{
		InsertionSort(v + prim, ultim - prim + 1);
		return;
	}
	while (stanga <= dreapta)
	{
		while (compare(v[stanga], pivot) < 0)
			stanga++;
		while (compare(v[dreapta], pivot) > 0)
			dreapta--;
		if (stanga < dreapta)
			swap(&v[stanga++], &v[dreapta--]);
		else
			stanga++;
	}

	swap(&v[dreapta], &v[prim]);

	if (prim < dreapta - 1)
		quicksort2(v, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort2(v, dreapta + 1, ultim);

}


void afisare(FILES v[],int n)
{
	for (int i = 0; i < n; i++)
		printf("%c - %d - %s\n", v[i].isDir, v[i].size, v[i].nume);
	printf("\n");
}

void problemaLaborator5()
{
	FILES v[] = {
		{'0',"ale.exe",4099},
		{'0',"/nico.txt",3098},
		{'1',"/maria/home",456},
		{'0',"zappytv",4099},
		{'1',"alexEbou",456},
		{'1',"manele.tv",8976}
	};
	int n = 6;
	afisare(v, n);
	//SelectionSort(v, n);
	//quicksort(v, 0, n - 1);
	//InsertionSort(v, n);
	//quicksort2(v, 0, n - 1);
	afisare(v, n);
}

*/
//lab 4-6 sortare

/*typedef struct {
	int an;
	int durata;
	char titlu[150];
	char cat[30];
	char premii[4];
}FILME;

int processLine(char* line,FILME *movie)
{
	char* p=NULL;
	if ((p = strtok(line, ",")) == NULL)
		return 0;
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0:
		{
			movie->an = strtol(p, NULL, 10);
			break;
		}
		case 1:
		{
			movie->durata = strtol(p, NULL, 10);
			break;
		}
		case 2:
		{
			strcpy(movie->titlu, p);
			break;
		}
		case 3:
		{
			strcpy(movie->cat, p);
			break;
		}
		case 4:
		{
			strcpy(movie->premii, p);
			break;
		}
		}
		if ((p = strtok(NULL, ",")) == NULL)
			return 0;
	}
	return 1;
}


void afisareFilme(FILME v[],int n)
{
	for (int i = 0; i < n; i++)
		printf("%d - %d - %s - %s - %s", v[i].an, v[i].durata, v[i].titlu, v[i].cat, v[i].premii);
}

void swap(FILME* a, FILME* b)
{
	FILME aux = *a;
	*a = *b;
	*b = aux;
}

void bubble_sort(FILME v[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
			if (strcmp(v[j].titlu,v[j - 1].titlu)<0) //daca nu sunt in ordinea potrivita
				swap(&v[j], &v[j - 1]);
	}
}

void sortare_dupa_premii(FILME v[], int n)
{
	int prim = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(v[i].premii, "Da\n") == 0)
		{
			if (prim != i)
				swap(&v[prim], &v[i]);
			prim++;
		}
	}
}

void quicksort(FILME v[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;

	//alegere pivot
	swap(&v[prim], &v[(prim + ultim) / 2]);

	//mutare pivot pe prima pozitie
	FILME pivot = v[prim];

	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && v[stanga].an<pivot.an)
			stanga++;
		while (dreapta >= prim && pivot.an<v[dreapta].an)
			dreapta--;
		if (stanga < dreapta)
			swap(&v[stanga++], &v[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&v[dreapta], &v[prim]);

	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(v, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(v, dreapta + 1, ultim);
}

void p1FILME()
{
	FILE* f = NULL;
	if ((f = fopen("Filme.txt", "r")) == NULL)
	{
		printf("error opening!");
		return;
	}


	FILME v[19] = {};
	int cnt = 0;
	char line[300];


	for(int i=0;i<19;i++)
	{
		fgets(line, 300, f);
		//line[strlen(line - 2)] = '\0';
		FILME movie;
		int ok=processLine(line, &movie);
		v[cnt] = movie;
		cnt++;
	}

	//afisareFilme(v, cnt);
	//bubble_sort(v, cnt);
	//sortare_dupa_premii(v, cnt);
	quicksort(v, 0, cnt - 1);
	afisareFilme(v, cnt);

	if (fclose(f) != 0)
	{
		printf("error closing!");
		return;
	}
}*/

/*typedef struct {
	char nume[10];
	double nota;
}STUDENTI;

typedef struct {
	STUDENTI v[11];
	int dim;
}SET;


void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%s - %lf\n", s.v[i].nume, s.v[i].nota);
}

void swap(STUDENTI* a, STUDENTI* b)
{
	STUDENTI aux = *a;
	*a = *b;
	*b = aux;
}

void bubble_sort(SET *s)
{
	int i, j;
	for (i = 0; i < s->dim-1; i++)
	{
		for (j = s->dim - 1; j > i; j--)
			if (strcmp(s->v[j].nume, s->v[j - 1].nume) < 0) //daca nu sunt in ordinea potrivita
				swap(&s->v[j], &s->v[j - 1]);
	}
}

void sortare_promovati(SET* s)
{
	int prim = 0;
	for (int i = 0; i < s->dim; i++)
	{
		if (s->v[i].nota >= 5)
		{
			if (prim != i)
				swap(&s->v[prim], &s->v[i]);
			prim++;
		}
	}
}

void quicksort(SET*s, int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;

	//alegere pivot
	swap(&s->v[prim], &s->v[(prim + ultim) / 2]);

	//mutare pivot pe prima pozitie
	STUDENTI pivot = s->v[prim];

	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && s->v[stanga].nota < pivot.nota)
			stanga++;
		while (dreapta >= prim && pivot.nota < s->v[dreapta].nota)
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

void p2STUDENTI() {
	FILE* f = NULL;
	if ((f = fopen("Studenti.txt", "r")) == NULL)
	{
		printf("error opening!");
		return;
	}

	SET s;
	s.dim = 10;
	for (int i = 0; i < 10; i++)
	{
		fscanf(f,"%s %lf", s.v[i].nume, &s.v[i].nota);
	}

	//bubble_sort(&s);
	//sortare_promovati(&s);
	quicksort(&s, 0, s.dim - 1);
	afisare(s);
	fclose(f);
}
*/

//prob ex suplimentar promovare lab 15 ian

/*typedef struct {
	int an;
	char platforma[10];
	char titlu[30];
	char gen[15];
	char multi[4];
}GAME;

typedef struct {
	GAME v[5];
	int dim;
}SET;

int processLine(char* line, GAME* joc)
{
	char* p = NULL;
	if ((p = strtok(line, ",")) == NULL)
		return 0;
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0:
		{
			joc->an = strtol(p, NULL, 10);
			break;
		}
		case 1:
		{
			strcpy(joc->platforma, p);
			break;
		}
		case 2:
		{
			strcpy(joc->titlu, p);
			break;
		}
		case 3:
		{
			strcpy(joc->gen, p);
			break;
		}
		case 4:
		{
			strcpy(joc->multi, p);
			break;
		}
		}
		if ((p = strtok(NULL, ",")) == NULL)
			return 0;
	}
	return 1;
}

void afisare(SET s)
{
	for (int i = 0; i < s.dim; i++)
		printf("%d - %s - %s - %s - %s\n", s.v[i].an, s.v[i].platforma, s.v[i].titlu, s.v[i].gen, s.v[i].multi);
}

void insertion_sort(SET *s)
{
	int i, j;
	GAME tmp;
	for (i = 1; i < s->dim; i++)
	{
		tmp = s->v[i];
		for (j = i; (j > 0) && (tmp.an > s->v[j - 1].an); j--)
			s->v[j] = s->v[j - 1];
		s->v[j] = tmp;
	}
}

void swap(GAME* a, GAME* b)
{
	GAME aux = *a;
	*a = *b;
	*b = aux;
}

void selection_sort(SET* s)
{
	int i, j, min; // min retine INDEXUL elementului cu valoare minima
	for (i = 0; i < s->dim - 1; i++)
	{
		min = i;
		for (j = i + 1; j < s->dim; j++)
		{
			if (strcmp(s->v[j].multi, s->v[min].multi) < 0)
				min = j;
		}
		swap(&s->v[min], &s->v[i]);
	}
}

int cautare_binara(SET s, int an)
{
	int mij;
	int st = 0, dr = s.dim - 1, ok = 0;
	while ((st <= dr) && ok == 0)
	{
		mij = (st + dr) / 2;
		if (s.v[mij].an == an)
			ok = 1;
		else
			if (s.v[mij].an < an)
				st = mij + 1;
			else
				dr = mij - 1;
	}
	if (ok == 1)
		return mij;
	else
		return -1;
}


void wtfman()
{
	FILE* f = NULL;
	if ((f = fopen("Jocuri.txt", "r")) == NULL)
	{
		printf("error opening!");
		return;
	}

	char line[200];
	SET s;
	s.dim = 0;
	GAME joc;

	if (fgets(line, 200, f) == NULL)
		exit(-1);

	for (int i = 0; i < 4; i++)
	{
		fgets(line, 200, f);
		processLine(line, &joc);
		{
			s.v[s.dim] = joc;
			s.dim++;
		}
	}

	//afisare(s);
	//insertion_sort(&s);
	//selection_sort(&s);

	int rez = cautare_binara(s, 2011);
	if (rez == -1)
		printf("nu exista lmao");
	else
		printf("jocul este: %s", s.v[rez].titlu);
	//afisare(s);

	fclose(f);
}*/

//lab LISTE

/**typedef struct STUDENT {
	char nume[15];
	int id;
	char gen; //F SAU B
	struct STUDENT* next;
}STUDENT;

typedef struct UNIVERSITATE {
	char nume[30];
	char adresa[100];
	int nr_studenti;
	struct UNIVERSITATE* next;
	STUDENT* student;
}UNIVERSITATE;

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

UNIVERSITATE* creare_nod(const char* nume, const char* adresa,UNIVERSITATE* next)
{
	UNIVERSITATE* aux = NULL;
	if ((aux = (UNIVERSITATE*)malloc(sizeof(UNIVERSITATE))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(aux->nume, nume);
	strcpy(aux->adresa, adresa);
	aux->nr_studenti = 0;
	aux->next = next;
	aux->student = NULL;
	return aux;
}

UNIVERSITATE* add_university(UNIVERSITATE* lista, const char *nume, const char *adresa)
{
	UNIVERSITATE* p = lista;
	int ok = 1;
	while (p != NULL)
	{
		if (strcmp(p->nume, nume) == 0)
		{
			ok = 0;
			break;
		}
		p = p->next;
	}
	if (ok == 0)
	{
		printf("Universitatea exista deja\n");
		return lista;
	}
	else
		return creare_nod(nume,adresa, lista);
}

UNIVERSITATE* add_student(const char *nume, int id, char gen, UNIVERSITATE* lista, const char* nume_universitate)
{
	UNIVERSITATE* p = lista;

	int ok = 1;
	while (p != NULL)
	{
		STUDENT* q = p->student;
		while (q != NULL)
		{
			if (q->id == id)
				ok = 0;
			q = q->next;
		}

		if (ok == 0)
		{
			printf("Studentul deja se afla!\n");
			return lista;
		}

		if (strcmp(p->nume, nume_universitate) == 0)
		{
			p->student = creare_nod(nume,id,gen,p->student);
			p->nr_studenti++;
		}
		p = p->next;
	}
	return lista;
}


void afisare(UNIVERSITATE* lista)
{
	UNIVERSITATE* p = lista;
	while (p != NULL)
	{
		printf("%s - %s - %d - ", p->nume,p->adresa,p->nr_studenti);
		STUDENT* q = p->student;
		while (q != NULL)
		{
			printf("%s ", q->nume);
			q = q->next;
		}
		printf("\n");
		p = p->next;
	}
	printf("\n");
}

UNIVERSITATE* remove_university(const char* nume, UNIVERSITATE* lista)
{
	if (lista == NULL)
		return lista;
	if (lista->next == NULL && strcmp(lista->nume, nume) != 0)
		return lista;

	UNIVERSITATE *p = NULL;
	if (strcmp(lista->nume, nume) == 0)
	{
		printf("Am sters univ. %s, cu %d studenti\n", nume, lista->nr_studenti);
		p = lista;
		lista = lista->next;
		free(p);
		return lista;
	}

	p = lista->next;
	UNIVERSITATE* prev = lista;
	while (p != NULL)
	{
		if (strcmp(p->nume, nume) == 0)
		{
			printf("Am sters univ. %s, cu %d studenti\n", nume, p->nr_studenti);
			prev->next = p->next;
			free(p);
			break;
		}
		p = p->next;
		prev = prev->next;
	}
	return lista;
}

void problemaCLASA()
{
	// 2 liste dinamice
	UNIVERSITATE* uni = NULL;
	uni = add_university(uni,"POLITEHNICA", "TIMISOARA");
	uni = add_university(uni,"UNIBUC", "BUCURESTI");
	uni = add_university(uni,"UBB", "CLUJ");
	uni = add_university(uni, "POLITEHNICA", "CLUJ");

	uni = add_student("Ion", 1, 'B', uni, "POLITEHNICA");
	uni = add_student("Maria", 2, 'F', uni, "UNIBUC");
	uni = add_student("Ana", 3, 'F', uni, "UBB");
	uni = add_student("Nico", 4, 'F', uni, "POLITEHNICA");
	uni = add_student("Ale", 2, 'F', uni, "POLITEHNICA");
	uni = add_student("Lica", 3, 'B', uni, "UBB");
	uni = add_student("Livi", 5, 'F', uni, "UNIBUC");
	uni = add_student("Marius", 6, 'B', uni, "UBB");
	uni = add_student("Diana", 7, 'F', uni, "UNIBUC");

	afisare(uni);
	printf("\n");
	uni = remove_university("UNIBUC", uni);
	afisare(uni);
}*/



int main()
{
	//lab2();
	//lab3();
	//problemaLaborator2();
	//problemaLaborator4();
	//problemaLaborator5();
	//p1FILME();
	//p2STUDENTI();
	//wtfman();
	//problemaCLASA();

	return 0;
}