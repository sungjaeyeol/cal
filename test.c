﻿#include <stdio.h>
#include <windows.h>
#include <math.h>

#define PI 3.1415926535897

//전역변수
double first = 0, second = 0;
char chr = 0;
int start = 0;
int anum = 0;
double bnum = 0;

//함수
double add();
double sub();
double mul();
double _div();
double _pow();
double _sin();
double _cos();
double _tan();
double factor();

int main() {

	int i = 0;
again :
	system("cls");
	printf("┌──────────── 계산기────────────┐\n");
	printf("│                               │\n");
	printf("│       사칙연산, 제곱 (1)      │\n");
	printf("│          삼각함수 (2)         │\n");
	printf("│          팩토리얼 (3)         │\n");
	printf("│            종료  (4)          │\n");
	printf("│                               │\n");
	printf("└───────────────────────────────┘\n");
	scanf_s("%d", &start);

	while (start == 1) { // 사칙연산

		if (i == 0) { system("cls"); printf("숫자를 입력하세요 : ");  scanf_s("%lf", &first); i++; }

		getchar();
		printf("┌────┬────┬────┬────┬────┐\n");
		printf("│  + │  - │  * │  / │  ^ │\n");
		printf("├────┴────┴────┴────┴────┤\n");
		printf("│        exit (z)        │\n");
		printf("└────────────────────────┘\n");
		printf("연산을 고르세요 : "); chr = getchar();
		printf("숫자를 입력하세요 : "); scanf_s("%lf", &second);

		switch (chr) {
		case '+':
			add(first, second);
			system("cls");
			printf("= %g\n", first);
			break;
		case '-':
			sub(first, second);
			system("cls");
			printf("=%g\n", first);
			break;
		case '*':
			mul(first, second);
			system("cls");
			printf("=%g\n", first);
			break;
		case '/':
			_div(first, second);
			system("cls");
			printf("=%g\n", first);
			break;
		case '^':
			_pow(first, second);
			system("cls");
			printf("=%g\n", first);
			break;
		case 'z' :
			goto again;
			break;
		default:
			printf("다시입력하세요\n");
			break;
		}
	}
	system("cls");

	while (start == 2) { //삼각함수

		int check = 0;
		printf("계산 할 숫자를 입력하세요 : "); scanf_s("%d", &anum);

		if (anum >= 0 && anum <= 360) {
			printf("┌────────┬────────┬────────┐\n");
			printf("│ sin (1)│ cos (2)│ tan (3)│\n");
			printf("├────────┴────────┴────────┤\n");
			printf("│         exit (4)         │\n");
			printf("└──────────────────────────┘\n");
			printf("수식을 선택하세요 : "); scanf_s("%d", &check);

			switch (check) {
			case 1:
				_sin(anum);
				system("cls");
				printf("sin(%d) = %g\n", anum, bnum);
				break;
			case 2:
				_cos(anum);
				system("cls");
				printf("cos(%d) = %g\n", anum, bnum);
				break;
			case 3:
				_tan(anum);
				system("cls");
				if (anum == 90) {
					printf("∞\n");
				}
				else if (anum == 270) {
					printf("∞\n");
				}
				else {
					printf("tan(%d) = %g\n", anum, bnum);
				}
				break;
			case 4:
				goto again;
				break;
			}
		}
		else {
			system("cls");
			printf("0~360 사이에 숫자를 입력해주세요.\n");
		}
	}
	while (start == 3) {
		printf("계산 할 숫자를 입력하세요(0 입력 시 초기화면으로) : "); scanf_s("%d", &anum);
		if (anum == 0) {
			goto again;
		}
		factor(anum);
		system("cls");
		printf("%d! = %g\n", anum, bnum);
	}
	while (start == 4) {
		printf("프로그램을 종료합니다.\n");
		Sleep(1000);   //1초 딜레이
		system("cls");
		exit(1);
	}
}


double add(double n1, double n2) {
	first = n1 + n2;
	return first;
}

double sub(double n1, double n2) {
	first = n1 - n2;
	return first;
}

double mul(double n1, double n2) {
	first = n1 * n2;
	return first;
}

double _div(double n1, double n2) {
	first = n1 / n2;
	return first;
}

double _pow(double n1, double n2) {
	first = pow(n1, n2);
	return first;
}

double _sin(int n) {
	bnum = sin(n * PI / 180);
	return bnum;
}

double _cos(int n) {
	bnum = cos(n * PI / 180);
	return bnum;
}

double _tan(int n) {
	bnum = tan(n * PI / 180);
	return bnum;
}

double factor(int n) {
	bnum = 1;
	for (int i = 1; i <= n; i++) {
		bnum *= i;
	}
	return bnum;
}



//#include <stdio.h>

//int main() {

//	printf("┌────┬────┬────┬────┐\n");

//	printf("│  + │  - │  * │  / │\n");

//	printf("│  1 │  2 │  3 │  4 │\n");

//	printf("├────┼────┼────┼────┤\n");

//	printf("│ sin│ cos│ tan││ x││\n");

//	printf("│  5 │  6 │  7 │  8 │\n");

//	printf("└────┴────┴────┴────┘\n");

//}