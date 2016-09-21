#include <stdio.h>
#define N 8 //map size
FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
int M;
int Map[N + 1][N + 1];
int Ans[N + 1][N + 1];
int R[N + 1], C[N + 1]; //���� ��ռ�Ȯ�� ��, ���� ��ռ�Ȯ�� ��
int Rm[N + 1], Cm[N + 1]; //���� ���� �й��� ����, ���� ���� �й��� ����
void Input() {
	int i, j;
	fscanf(in, "%d", &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			fscanf(in, "%d", &Map[i][j]);
			Map[i][j] -= M; //��� ��Ȯ���� 0���� ���������ִ� ȿ��.
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
			sum = R[i] + C[j] - Map[i][j]; //i�� j���� �߽����� �ϴ� ���ڰ��� �ִ� ������ ��
			if (sum % 2) {
				Ans[i][j] = 1; //���� Ȥ�� ���ʾ��� �ѷ����ϴ� ��ġ�̴�. �ٸ� �������� ����
				Rm[i]++; Cm[j]++;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			//���� �й��⿡ ���� ���� ��Ȯ���� �ʿ��� ���� ����.
			Map[i][j] -= Rm[i] + Cm[j] - Ans[i][j];
		}
	}
	for (i = 1; i <= N; i++) R[i] = C[i] = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) { //R,C�迭 �ٽ� ����
			R[i] += Map[i][j];
			C[j] += Map[i][j];
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			sum = R[i] + C[j] - Map[i][j]; //i�� j���� �߽����� �ϴ� ���ڰ��� �ִ� ������ ��
			if (sum % 4) {
				Ans[i][j] = 2; //���ʾ��� �ѷ����ϴ� ��ġ.
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