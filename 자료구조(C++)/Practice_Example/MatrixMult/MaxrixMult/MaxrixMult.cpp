#include "term.h" //해당 헤더에  구현

int main(){
	term d[MAX_TERMS];
	term a[MAX_TERMS] =
	{ {6,6,8},
	 {0,0,15},
	 {0,3,22},
	 {0,5,-15},
	 {1,1,11},
	 {1,2,3},
	 {2,3,-6},
	 {4,0,91},
	 {5,2,28} };
	term b[MAX_TERMS] =
	{ {6,2,5},
	 {0,0,1},
	 {1,1,1},
	 {2,0,3},
	 {3,1,1},
	 {4,0,2} };

	printf("\n***** Sparse Matrix Multiplication *****\n");
	printMatrix(a, SPARSE, "A"); // SPARSE: 희소 행렬 형태로 출력
	printMatrix(b, SPARSE, "B");
	mMult(a, b, d);
	printMatrix(d, SPARSE, "D=AxB");
	printMatrix(d, MATRIX, "D=AxB"); // MATRIX: 일반 행렬 형태로 출력
}
