#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/// <summary>
/// HW5.1과 5.2를 한번에 구현하였습니다.
/// top은 이론수업과 관련해 0으로 초기화해주었습니다.(1부터 시작)
/// </summary>

class Stack { //저번과제 4.1 의 스택 클래스를 활용함
protected:
	char* stack; //문자를 넣으므로 char형으로 변경
	double* dStack; //eval에서 사용할 double형 스택
	int top;
	int size;

public:
	Stack(int n) {
		stack = new char[n]; //스택이 많이 길어져도 수식길이를 넘지 않음
		dStack = new double[n]; //eval에서 사용할 것
		stack[0] = '\0'; //아스키 코드로 0임
		top = 0; //0번째를 건너뛰고 1번째부터 추가할 예정, dStack때도 그냥 그대로 사용
		size = n;
	}

	~Stack() { delete[] stack; } //메모리해제

	void push(char item) { stack[++top] = item; }

	void dPush(double item) { dStack[++top] = item; } //eval에서 사용할 더블형 스택 함수

	char pop() { return stack[top--]; }

	double dPop() { return dStack[top--]; } //eval에서 사용할 더블형 스택 함수

};

class Postfix_Eval : public Stack { //후위연산 클래스
private:
	char* expr; //입력받을 수식 : infix
	char* new_expr; //계산 후 수식 : postfix
	int new_size;

public:

	Postfix_Eval(char* infix, int n) : Stack(n) {
		expr = new char[n + 1]; //여유공간 1
		strcpy(expr, infix);
		new_expr = new char[n + 1]; //postfix로 옮길 배열 할당
	}

	~Postfix_Eval() {
		delete[] expr;
		delete[] new_expr;
	}
	void postfixStatus(char token, int output) {
		printf("   %c  | ", token);
		for (int i = 1; i <= top; i++) printf("%c ", stack[i]);
		printf("                  ");
		printf("|%d| ", top);
		for (int i = 0; i < output; i++) printf("%c ", new_expr[i]);
		printf("\n");
	}

	void evalStatus(char token) {
		printf("   %c  | ", token);
		for (int i = 1; i <= top; i++) printf("%.0lf ", dStack[i]);
		printf("                ");
		printf("|%d\n", top);
	}

	bool isOperand(char tk) {
		if ((tk >= 48) && (tk <= 57)) return true; //아스키 코드상에서 숫자들
		else return false;
	}

	int getStrong(char op) {
		switch (op) {
		case '\0':
			return 0;
		case '(': //isp의 (만 구현, icp인경우 바로 푸시하는 형태
			return 1;
		case '+':
			return 2;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 3;
		default:
			cout << "입력오류가 있었습니다." << endl;
			cout << "오류는 바로 :: " << op << endl;
			exit(0); //강제종료
		}
	}

	void make_postfix() {
		int j = 0; //new_expr의 인덱스

		for (int i = 0; i < size; i++) {
			if (isOperand(expr[i])) new_expr[j++] = expr[i]; //숫자면 더하기

			else if (expr[i] == '(') {
				push(expr[i]); //괄호가 시작되면 무조건 푸시
			}

			else if (expr[i] == ')') { //괄호가 닫기면 그 사이 원소들 팝해서 newexpr에 저장
				while (stack[top] != '(') {
					new_expr[j++] = pop();
				}
				top--; // expr[i]가 '('인 자리를 무시하므로 탑을 강제로 내린다.
			}

			else { //이 경우는 + - * / 연산을 푸시 팝 함
				char icp = expr[i]; //스택에 들어오려는 원소
				char isp = stack[top]; //스택에 가장 위에있는 원소

				if (getStrong(icp) <= getStrong(isp)) new_expr[j++] = pop(); //isp가 팝됨, 반대로 icp가 크다면 그냥 푸시만 하는것.
				push(icp); //이후에 icp를 푸시함,
			}
			postfixStatus(expr[i], j);
		}

		while (top > 0) new_expr[j++] = pop(); //스택에 연산자가 남아있다면?



		new_expr[j] = '\0'; //문자의 끝을 알려주어 출력시 깨지지 않게 함
		new_size = j; //j값이 곧 new_size이다.
	}

	double calc(char op, double x, double y) { //계산 중 실수가 나올 상황이 존재하여 double형으로 계산
		switch (op) {
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		}
	}

	double eval() { //계산 중 실수가 나올 상황이 존재하여 double형으로 계산
		double result;

		for (int i = 0; i < new_size; i++) {
			if (isOperand(new_expr[i])) {
				dPush((double)new_expr[i] - 48); //더블스택에 저장
			}
			else { //피연산자 아니면 연산자일것임, make_postfix에서 피연산자와 연산자 구분이 끝남
				double y = dPop(); //스택 순서가 반대이므로
				double x = dPop();
				result = calc(new_expr[i], x, y);
				dPush(result);
			}
			evalStatus(new_expr[i]);
		}

		return dStack[1]; //마지막 하나남은 원소가 연산의 답이다.
	}

	void run() { //main함수와 동일한 역할을 할 예정
		cout << "===infix를 postfix로 변환합니다.===" << endl;
		printf("Token | Stack           | Top | Output\n");
		make_postfix();

		cout << "결과 : ";
		for (int i = 0; i < new_size; i++) {
			cout << new_expr[i];
		}

		cout << endl << "===postfix를 eval로 변환합니다.===" << endl;
		printf("Token | Stack           | Top\n");
		cout << "결과 : " << eval() << endl;
	}
};


int main() {
	char infix[1001]; //임의로 이정도만 정적할당

	cout << "infix 수식을 입력하여주세요 : ";
	cin >> infix;

	int len = strlen(infix);

	Postfix_Eval pfe(infix, len); //생성자를 통하여 infix수식 전달과 postfix수식 공간 할당
	pfe.run();
}
