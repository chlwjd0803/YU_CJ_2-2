#include <stdio.h>
#include <string.h> //strlen을 이용하기위함

void SWAP(char* ls1, char* ls2) {
	char temp = *ls1;
	*ls1 = *ls2;
	*ls2 = temp;
}

void perm(char* list, int i, int n) { //한단어, 인덱스 0, 단어의문자개수 n
	int j;
	if (i == n) {
		for (j = 0; j < n; j++) printf("%c", list[j]);
		printf("   ");
	}
	else {
		for (j = i; j < n; j++) {
			SWAP(&list[i], &list[j]);
			perm(list, i + 1, n);
			SWAP(&list[i], &list[j]); //원상복구
		}
	}
}


int main(void) {
	char str[4][10] = { "GO", "BOY", "GIRL", "GIRLS" }; //총 4개단어, 문자개수10개이하
	
	for (int i = 0; i < 4; i++) {
		printf("제시문자열 : ");
		for (int k = 0; k < strlen(str[i]); k++) printf("%c", str[i][k]);
		printf("\n");
		perm(str[i], 0, strlen(str[i]));
		printf("\n");
	}

}