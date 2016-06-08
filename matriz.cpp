#include <stdio.h> 
#include <string.h>
const int mod = 10000;
struct Matrix {
	float v[100][100];
	int row, col; // row x col
	Matrix(int n, int m, int a = 0) {
		memset(v, 0, sizeof(v));
		row = n, col = m;
		for(int i = 0; i < row && i < col; i++)
			v[i][i] = a;
	}
	Matrix operator*(const Matrix& x) const {
		Matrix ret(row, x.col);
		for(int i = 0; i < row; i++) {
			for(int k = 0; k < col; k++) {
				if (v[i][k])
				for(int j = 0; j < x.col; j++) {
					ret.v[i][j] += v[i][k] * x.v[k][j];
				}
			}
		}
		return ret;
	}
	Matrix operator^(const int& n) const {
		Matrix ret(row, col, 1), x = *this;
		int y = n;
		while(y) {
			if(y&1)	ret = ret * x;
			y = y>>1, x = x * x;
		}
		return ret;
	}
};
int main() {
	int N, L, S, T;
	float x, y;
	while (scanf("%d %d", &N, &L) == 2) {
		Matrix m(N, N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%f", &x);
				m.v[i][j]=x;
			}
		}
		Matrix ret = m ^ L;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				printf("%f ", ret.v[i][j]);
			}
			printf("\n");
		}
		
	}
	return 0;
}