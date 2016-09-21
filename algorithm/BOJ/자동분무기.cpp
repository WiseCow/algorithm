#include <stdio.h>
#define N 8 //map size
FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
int M;
int Map[N + 1][N + 1];
int Ans[N + 1][N + 1];
int R[N + 1], C[N + 1]; //행의 평균수확량 합, 열의 평균수확량 합
int Rm[N + 1], Cm[N + 1]; //행의 비료액 분무기 갯수, 열의 비료액 분무기 갯수
void Input() {
	int i, j;
	fscanf(in, "%d", &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			fscanf(in, "%d", &Map[i][j]);
			Map[i][j] -= M; //평균 수확량을 0으로 고정시켜주는 효과.
		}
	}
}
void Process() {
	int i, j, sum;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			R[i] += Map[i][j];
			C[j] += Map[i][j];
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			sum = R[i] + C[j] - Map[i][j]; //i행 j열을 중심으로 하는 십자가에 있는 수들의 합
			if (sum % 2) {
				Ans[i][j] = 1; //비료액 혹은 제초액을 뿌려야하는 위치이다. 다만 비료액으로 가정
				Rm[i]++; Cm[j]++;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			//비료액 분무기에 의해 얻은 수확량을 맵에서 빼어 갱신.
			Map[i][j] -= Rm[i] + Cm[j] - Ans[i][j];
		}
	}
	for (i = 1; i <= N; i++) R[i] = C[i] = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) { //R,C배열 다시 갱신
			R[i] += Map[i][j];
			C[j] += Map[i][j];
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			sum = R[i] + C[j] - Map[i][j]; //i행 j열을 중심으로 하는 십자가에 있는 수들의 합
			if (sum % 4) {
				Ans[i][j] = 2; //제초액을 뿌려야하는 위치.
			}
		}
	}
}
void Output() {
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (Ans[i][j] == 0) {
				fprintf(out, ". ");
			}
			if (Ans[i][j] == 1) {
				fprintf(out, "+ ");
			}
			if (Ans[i][j] == 2) {
				fprintf(out, "- ");
			}
		}
		fprintf(out, "\n");
	}
}
int main() {
	Input();
	Process();
	Output();
	return 0;
}