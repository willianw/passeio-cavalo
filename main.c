#include <stdio.h>

#define N 8
#define MAX 64

int passeio(int tab[N][N]);

int main(){
	int tab[N][N], i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			tab[i][j] = 0;
	passeio(tab);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			printf("%2d ", tab[i][j]);
		printf("\n");
	}
	return 0;
}

int passeio(int tab[N][N]){
	int mov[8][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} }; 
	//int mov[8][2] = {{ 3,  1, -1, -3, -3, -1,  1,  3},{ 1,  3,  3,  1, -1, -3, -3, -1}};
	int pilhaMov[MAX], t;
	int pilhaj[MAX], J;
	int x, y, i, j, nx, ny;
	
	x = y = t = 0;
	J = 0; pilhaj[J] = 0;
	i = 1;
	while(i < N * N){
		//printf("i = %d\n", i);
		for(j = pilhaj[J]; j < 8; j++){
			pilhaj[J] = j;
			nx = x + mov[j][0];
			ny = y + mov[j][1];
			if ((nx >= 0) && (nx < N) && (nx >= 0) && (ny < N) && !tab[nx][ny]){
				//printf("goto (%d, %d)\n", nx, ny);
				break;
			}

		}
		if (j < 8){
			x = nx;
			y = ny;
			tab[x][y] = i;
			pilhaMov[t++] = j;
			pilhaj[++J] = 0;
			i++;
		} else if (t > 0){
			//printf("zera (%d, %d)\n", x, y);
			pilhaj[J--] = 0;
			pilhaj[J]++;
			tab[x][y] = 0;
			x -= mov[pilhaMov[--t]][0];
			y -= mov[pilhaMov[t]][1];
			i--;
		} else return -1;
		/*
		for(ny = 0; ny < N; ny++){
			for(nx = 0; nx < N; nx++)
				printf("%2d ", tab[nx][ny]);
			printf("\n");
		}
		printf("\n");
		*/
	}		
	return 0;
}

