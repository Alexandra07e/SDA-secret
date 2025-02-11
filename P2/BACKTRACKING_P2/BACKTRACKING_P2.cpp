#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NR DE TELEFON

/*int v[10];
int n = 10;

int valid(int k) {
	if (k +1> n)
		return 0;
	for (int i = 1; i <=k; i++)
		if (v[i - 1] % 2 == 0 && v[i] % 2 == 0)
			return 0;
	return 1;
}

int solutie(int k) {
	if (k + 1 != n)
		return 0;
	if (v[0] != 0 || v[1] != 7 || v[2] != 9 || v[3] != 9 || v[9] != 0)
		return 0;
	return 1;
}

void afisare() {
	for (int i = 0; i < n; i++)
		printf("%d", v[i]);
	printf("\n");
}

void back(int k) {
	if (k == n)
		return;
	for (int i = 0; i <= 9; i++) {
		v[k] = i;
		if (valid(k)) {
			if (solutie(k))
				afisare();
			else
				back(k + 1);
		}
	}
}

void p1() {
	back(0);
}*/


//NR BINARE

/*int v[6];
int n = 6;
int fr[2] = { 0 };

int valid(int k) {
	if (k + 1 > n)
		return 0;
	return 1;
}

int solutie(int k) {
	if (k + 1 != n)
		return 0;
	if (fr[0] != 2 || fr[1] != 4)
		return 0;
	if (v[0] == 1 && v[1] == 1 || v[5]==0)
		return 0;

}

void afisare() {
	for (int i = 0; i < n; i++)
		printf("%d", v[i]);
	printf("\n");
}

void back(int k) {
	if (k == n)
		return;
	for (int i = 0; i <= 1; i++) {
		v[k] = i;
		fr[i]++;
		if (valid(k)) {
			if (solutie(k)) {
				afisare();
			}
			else
				back(k + 1);
		}
		fr[i]--;
	}
}

void p2() {
	back(0);
}*/

//PROBLEMA P1 ROBOTEL

/*int map[4][5] = {
	{3,0,0,0,1},
	{0,5,0,2,0},
	{0,0,0,0,0},
	{2,0,0,1,0}
};

int moves[][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

int n = 4, m = 5;

int drum[100][3];
int size_drum = 0;
int max = 0;
int best_drum[100][3];
int best_size = 0;


int valid(int x, int y, int energie) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	if (energie == 0)
		return 0;
	if (map[x][y] == -1)
		return 0;
	return 1;
}

int solutie(int x, int y, int x_final, int y_final) {
	if (x == x_final && y == y_final)
		return 1;
	return 0;
}

void back(int x, int y, int x_final, int y_final, int energie) {
	energie += map[x][y];
	drum[size_drum][0] = x;
	drum[size_drum][1] = y;
	drum[size_drum][2] = energie;
	size_drum++;

	if (solutie(x, y, x_final, y_final)) {
		if (energie > max) {
			max = energie;
			best_size = size_drum;
			for (int i = 0; i < size_drum; i++) {
				best_drum[i][0] = drum[i][0];
				best_drum[i][1] = drum[i][1];
				best_drum[i][2] = drum[i][2];
			}
		}
	}

	int acum = map[x][y];
	map[x][y] = -1;

	for (int i = 0; i < 4; i++) {
		int next_x = x + moves[i][0];
		int next_y = y + moves[i][1];
		if (valid(next_x, next_y, energie))
			back(next_x, next_y, x_final, y_final, energie-1);
	}

	map[x][y] = acum;
	size_drum--;
}

void p3() {
	back(0, 0, 3, 4, 0);
	for (int i = 0; i < best_size; i++)
		printf("(%d , %d) - energie %d\n", best_drum[i][0], best_drum[i][1], best_drum[i][2]);
	printf("\n");
}*/

//PROBLEMA CULORI SUPRAFATA

/*int map[4][4] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};

int n = 4;
int moves[][2] = {
	{-1,1},
	{-1,-1},
	{1,-1},
	{1,1}
};

int culori[4] = { 1,2,3,4 };

int valid(int x, int y,int next_x,int next_y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	if (map[x][y] == map[next_x][next_y])
		return 0;
	if (map[x][y] != 0)
		return 0;
	return 1;
}

int solutie(int x, int y);

void back(int x, int y) {
	for (int i = 0; i < 4; i++) {

	}
}*/


int map[3][3] = {
	{9,8,7},
	{6,8,5},
	{5,7,3}
};

int a = 0, b = 0;

int moves[][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0},
	{1,1},
	{1,-1},
	{-1,1},
	{-1,-1}
};

int n = 3;

int valid(int x, int y,int next_x,int next_y) {
	if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
		return 0;
	if (map[x][y] >= map[next_x][next_y])
		return 0;
	return 1;
}

void afisare() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

int solutie(int x, int y) {
	if (x==0 || y==0 || x==n-1 || y==n-1)
		return 1;
	return 0;
}

void back(int x, int y) {

}

int main() {
	//p1();
	//p2();
	//p3();
	return 0;
}