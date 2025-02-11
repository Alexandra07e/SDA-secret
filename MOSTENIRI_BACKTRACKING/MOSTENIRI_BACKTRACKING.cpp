#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*char M[] = {'a','b','c'};
int n = 10;
int fr[3] = { 0 };
//0 e pt a, 1 pt b, 2 pt c
char v[11];

int valid(int k)
{
	if (k+1 > n)
		return 0;
	if (fr[0] > 3 || fr[1] > 4 || fr[2] > 3)
		return 0;
	return 1;
}

int solutie(int k)
{
	if (k + 1 != n)
		return 0;
	if (fr[0] != 3 || fr[1] != 4 || fr[2] != 3)
		return 0;
	return 1;
}

void afisare(int k)
{
	for (int i = 0; i <= k; i++)
		printf("%c", v[i]);
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i < 3; i++)
	{
		v[k] = M[i];
		fr[M[i] - 'a']++;
		if (valid(k))
		{
			if (solutie(k))
				afisare(k);
			else
				back(k + 1);
		}
		fr[M[i] - 'a']--;
	}
}

void p1()
{
	back(0);
	//primele 5 cuvinte generate: aaabbbbccc, aaabbbcbcc,
	//aaabbbccbc,aaabbbcccb,aaabbcbbcc. Functia valid are complexitatea
	//O(1), unde se efectueaza niste comparari in timp constant,apoi
	//functia solutie are complexitatea O(1). Nr de Operatii din aceste functii
	//nu depinde de n, deci avem complexitate constanta. Functia
	//afisare are complexitatea O(n), afisam solutiile, iar functia back are
	//complexitatea O(3^n), deoarece la fiecare nivel al recursivitatii corespunzator
	//lui k, functia executa bucla for de 3 ori
	// la k=0, fct este apelata 1 data, k=1=>3 ori, k=2=>3^2 si tot 
	//asa pana la 3^n-1, iar aceasta suma de progresie geometrica tinde
	//la 3^n, complexitate exponentiala.   => COMPLEXITATE GENERALA O(3^n)
}*/

/*char culori[7][10] = {"alb","galben", "rosu","verde","albastru","negru"};
int n = 3;
int steag[3];

int valid(int k)
{
	if (k + 1 > n)
		return 0;
	for (int i = 0; i < k; i++)
		if (steag[i] == steag[k])
			return 0;
	return 1;
}

int solutie(int k)
{
	if (k + 1 != n)
		return 0;
	if (steag[1] != 1 && steag[1] != 3)
		return 0;
	return 1;
}

void afisare(int k)
{
	for (int i = 0; i <= k; i++)
		printf("%s  ",culori[steag[i]]);
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i < 6; i++)
	{
		steag[k] = i;
		if (valid(k))
		{
			if (solutie(k))
				afisare(k);
			else
				back(k + 1);
		}
	}
}


//Algoritmul este eficient, deoarece: 
// functia valid are complexitate O(k) sau O(n-1)<=>O(n), in care avem o comparatie constanta, O(1) 
//si bucla for, care va executa, in cel mai rau caz, k iteratii,(n-1). Functia solutie
//are complexitatea O(1), intrucat avem 3 verificari. Nr operatiilor nu depinde
//de n, deci avem complexitate constanta. Functia de afisare are complexitatea liniara
//O(n), afisam solutiile, iar functia back are complexitatea O(6^n), intrucat avem 6 culori,
//iar la fiecare nivel al recursivitatii, corespunzator lui k, functia executa bucla
//for de 6 ori
//la primul nivel, k=0, functia recursiva este apelata 1 data, k=1=>6 ori, k=2=>6^2 si tot asa
//pana la k=n-1=>6^n-1 ori,iar aceasta suma de progresie
// geometrica tinde la 6^n,complexitate exponentiala
// COMPLEXITATE GENERALA O(n*6^n)

void p2()
{
	back(0);
}*/

/*int sol[3] = {0,1};
int n = 6;
int v[7];
int fr[3] = { 0 };

int valid(int k)
{
	if (k + 1 > n)
		return 0;
	if (fr[0] > 2 || fr[1] > 4)
		return 0;
	return 1;
}

int solutie(int k)
{
	if (k + 1 != n)
		return 0;
	if (fr[0] != 2 && fr[1] != 4)
		return 0;
	if (v[0] == 1 && v[1] == 1)
		return 0;
	if (v[k] == 0)
		return 0;
	return 1;
}

void afisare(int k)
{
	for (int i = 0; i <= k; i++)
		printf("%d",v[i]);
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i < 2; i++)
	{
		v[k] = i;
		fr[i]++;
		if (valid(k))
		{
			if (solutie(k))
				afisare(k);
			else
				back(k + 1);
		}
		fr[i]--;
	}
}

void p3()
{
	//Fie un sistem care genereaza nr binare . toate nr binare de 6 cifre
	//care au 2 cifre de 0 si 4 cifre de 1. nr NU trebuie sa inceapa cu 11 si
	//nu trebuie sa se termine cu 0
	back(0);

	//Algoritmul este eficient deoarece: Functia valid are complex. O(1), in care
	//se intampla 3 comparari. Functia solutie are complex. O(1). Nr operatiilor
	//din aceste functii nu depind de n=>complexitate constanta. Functia afisare
	//are complex. liniara O(n), afisam solutiile. Functia back are complexitate exponentiala
	//O(2^n), fiind asimptota catre care tinde suma progresiei geometrice
	//a nr apelurilor functiei recursive pe fiecare nivel(corespunzator variabilei k).
	//=>COMPLEXITATE generala O(2^n)
}*/

/*int n = 10;
int v[11];

int valid(int k)
{
	if (k + 1 > n)
		return 0;
	for (int i = 1; i <= k; i++)
		if (v[i] % 2 == 0 && v[i - 1] % 2 == 0)
			return 0;
	return 1;
}

int solutie(int k)
{
	if (k + 1 != n)
		return 0;
	if (v[9] != 0)
		return 0;
	if (v[0] != 0 || v[1] != 7 || v[2] != 9 || v[3] != 9)
		return 0;
	return 1;
}

void afisare(int k)
{
	for (int i = 0; i <= k; i++)
		printf("%d", v[i]);
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i <= 9; i++)
	{
		v[k] = i;
		if (valid(k))
		{
			if (solutie(k))
				afisare(k);
			else
				back(k + 1);
		}
	}
}

void p4()
{
	//nr de telf: 10 cifre, incep cu 0799, ultima cifra 0,
	//nu au cifre pare una langa alta
	back(0);
}*/

/*int moves[][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int n = 5;
int map[5][5] = {
	{1,1,0,0,0},
	{0,1,1,0,0},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,1,1}
};

int max = 0;

int valid(int x,int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	if (map[x][y] == 0)
		return 0;
	return 1;
}

void back(int x,int y,int suma)
{
	if (suma > max)
		max = suma;
	int pozitie_curenta = map[x][y];
	map[x][y] = -1; //am trecut de pozitia resp
	for (int i = 0; i < n; i++)
	{
		int next_x = x + moves[i][0];
		int next_y = y + moves[i][1];

		if (valid(next_x, next_y) == 1 && map[next_x][next_y] != -1)
			back(next_x, next_y, suma + 1);
	}
	map[x][y] = pozitie_curenta;
}*/


/*int moves[][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int map[5][5] = {
	{1,1,0,0,0},
	{0,1,1,0,0},
	{0,0,1,0,1},
	{1,0,1,0,1},
	{1,1,1,1,1}
};

int n = 5;
int max = 0;

int valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	if (map[x][y] ==0 )
		return 0;
	return 1;
}

void back(int x, int y, int k)
{
	if (k > max)
		max = k;

	int elem = map[x][y];
	map[x][y] = -1;
	for (int i = 0; i < n; i++)
	{
		int next_x = x + moves[i][0];
		int next_y = y + moves[i][1];

		if (valid(next_x, next_y) && map[next_x][next_y] !=-1)
			back(next_x, next_y, k + 1);
	}
	map[x][y] = elem;
}



void p5()
{
	//lg max de celule 1 interconectate (pe orizontala sau pe verticala intr-o matrice nxn
	// 1 1 0 0 0
	// 0 1 1 0 0
	// 0 0 1 0 1
	// 1 0 0 0 1
	// 0 1 0 1 1   =>R: 5

	back(0, 0, 1);
	printf("%d", max);
}*/



/*#define N 3
int moves[][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int map[3][3] = {
	{9,8,7},
	{6,5,4},
	{1,2,3}
};

int vizitat[N][N];

int valid(int x, int y,int next_x,int next_y)
{
	if (next_x >= 0 && next_x <= N - 1 && next_y >= 0 && next_y <= N - 1 && map[next_x][next_y] < map[x][y])
		return 1;
	return 0;
}

int solutie(int x, int y)
{
	if (x == 0 || y == 0 || x == N - 1 || y == N - 1)
		return 1;
	return 0;
}

void afisare()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", vizitat[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

int k = 2; 
void back(int x, int y)
{
	if (solutie(x, y))
		afisare();

	int elem = map[x][y];
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + moves[i][0];
		int next_y = y + moves[i][1];

		if (valid(x, y, next_x, next_y))
		{
			vizitat[next_x][next_y] = k++;
			back(next_x, next_y);
			vizitat[next_x][next_y] = 0;
			k--;
		}

	}
}

void p6()
{
	//problema cu bila
	vizitat[0][1] = 1;
	back(0, 1);
}*/


//nr telef
/*#define N 10

int v[N];

int valid(int k)
{
	if (k + 1 > N)
		return 0;
	for (int i = 1; i <= k; i++)
		if (v[i - 1] % 2 == 0 && v[i] % 2 == 0)
			return 0;
	return 1;
}

int solutie(int k)
{
	if (k + 1 != N)
		return 0;
	if (v[0] != 0 || v[1] != 7 || v[2] != 9 || v[3] != 9)
		return 0;
	if (v[N - 1] != 0)
		return 0;
	return 1;
}

void afisare()
{
	for (int i = 0; i < N; i++)
		printf("%d", v[i]);
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i < 10; i++)
	{
		v[k] = i;
		if (valid(k))
		{
			if (solutie(k))
				afisare();
			else
				back(k + 1);
		}
	}
}

void p7()
{
	back(0);
}*/
/*#define n 10

char M[] = { 'a','b','c' };
char v[n];

int fr[3] = { 0 };

int valid(int k)
{
	if (k + 1 > n)
		return 0;
}

int solutie(int k)
{
	if (k + 1 != n)
		return 0;
	if (fr[0] != 3 || fr[1] != 4 || fr[2] != 3)
		return 0;
	return 1;
}

void afisare()
{
	for (int i = 0; i < n; i++)
		printf("%c", v[i]);
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i < 3; i++)
	{
		v[k] = M[i];
		fr[M[i] - 'a']++;
		if (valid(k))
		{
			if (solutie(k))
				afisare();
			else
				back(k + 1);
		}
		fr[M[i] - 'a']--;
	}
}

void p8()
{
	back(0);
}*/

/*#define n 3

char culori[6][11] = { "alb","galben","rosu","verde","albastru","negru" };
int v[n];

int valid(int k)
{
	if (k + 1 > n)
		return 0;
	for (int i = 0; i < k; i++)
		if (v[i] == v[k])
			return 0;
	return 1;
}

int solutie(int k)
{
	if (k + 1 != n)
		return 0;
	if (v[1] != 1 && v[1] != 3)
		return 0;
	return 1;
}

void afisare()
{
	for (int i = 0; i < n; i++)
		printf("%s ", culori[v[i]]);
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i < 6; i++)
	{
		v[k] = i;
		if (valid(k))
		{
			if (solutie(k))
				afisare();
			else
				back(k + 1);
		}
	}
}

void p9()
{
	back(0);
}*/

int main()
{
	//p1();
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