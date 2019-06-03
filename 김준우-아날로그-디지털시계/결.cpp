#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>


//숫자 모양 표현 함수[
void base();//시계 틀1
void base2();//시계 틀2
void forcon(int x, int colon1[][3]);
void gotoxy(int x, int y);// 숫자모양 자리지정하는 함수

//숫자 모양 표현 함수 ]
int main() {
	int sec1 = 0, sec10 = 0, min1 = 0, min10 = 0, hour1 = 0, hour10 = 0;
	time_t ct;
	struct tm tm;
	ct = time(NULL);
	tm = *localtime(&ct);

	int arr[][5][3] = {
	{
	{ 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 }, },
	{
	{ 1, 1, 1 }, { 1, 0, 1 }, { 1, 0, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, },
	{
	{ 1, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 }, { 1, 1, 1 }, },
	{
	{ 1, 1, 1 }, { 0, 0, 1 }, { 0, 1, 0 }, { 1, 0, 0 }, { 1, 1, 1 }, },
	{
	{ 1, 1, 1 }, { 0, 0, 1 }, { 1, 1, 1 }, { 0, 0, 1 }, { 1, 1, 1 }, },
	{
	{ 1, 0, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, },
	{
	{ 1, 1, 1 }, { 1, 0, 0 }, { 1, 1, 1 }, { 0, 0, 1 }, { 1, 1, 1 }, },
	{
	{ 1, 0, 0 }, { 1, 0, 0 }, { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, },
	{
	{ 1, 1, 1 }, { 1, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, },
	{
	{ 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, },
	{
	{ 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, }
	};
	hour10 = tm.tm_hour / 10;
	hour1 = tm.tm_hour % 10;
	min10 = tm.tm_min / 10;
	min1 = tm.tm_min % 10;
	sec10 = tm.tm_sec / 10;
	sec1 = tm.tm_sec % 10;

	if (tm.tm_hour > 12) {
		tm.tm_hour -= 12;
	}

	while (1) {
		system("mode con cols=180 lines=70");
		base();
		base2();
		forcon(80, arr[0]);
		forcon(57.5, arr[0]);

		
		if ((sec1 + (clock() / 1000)) % 10 == 0) {
			sec10++;
		}
		if (sec10 == 6) {      //초의 10의자리
			sec10 = 0; min1++;
		}
		if (min1 == 10) {       //분의 1의자리
			min1 = 0; min10++;
		}
		if (min10 == 6) {            //분의 10의자리
			min10 = 0; hour1++;
		}
		if (hour1 == 10) {          //시의 1의자리
			hour1 = 0; hour10++;
		}
		if (hour10 == 2 && hour1 == 4) {    //시의 10의자리
			break;
		}
		//초의 1의자리 출력
		forcon(97, arr[((sec1 + (clock() / 1000)) % 10) +1]);
		//초의 10의자리 출력
		forcon(87, arr[sec10+1]);
		//분의 1의자리 출력
		forcon(73, arr[min1+1]);
		//분의 10의자리 출력
		forcon(64, arr[min10+1]);
		//시의 1의자리 출력
		forcon(51, arr[hour1+1]);
		//시의 10의자리 출력
		forcon(42, arr[hour10+1]);
		
		Sleep(980); //인자값을 받는동안 시스템 정지 (1초=1000밀리세컨드) 1초동안 정지
		system("cls"); //콘솔창 초기화
	}
}


void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void base() {
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆시계◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	for (int i = 1; i <= 70; i++) {
		printf("◆◆                                                                                                                                                                        ◆◆\n");
	}
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
}

void base2() {
	gotoxy(16, 10);printf("			                     *********************\n");
	gotoxy(16, 11);printf("                                      *                                 *\n");
	gotoxy(16, 12);printf("                                 *                                           *\n");
	gotoxy(16, 13);printf("                             *                                                   *\n");
	gotoxy(16, 14);printf("                         *                                                           *\n");
	gotoxy(16, 15);printf("                      *                                                                 *\n");
	gotoxy(16, 16);printf("                    *                                                                     *\n");
	gotoxy(16, 17);printf("                  *                                                                         *\n");
	gotoxy(16, 18);printf("                *                                                                             *\n");
	gotoxy(16, 19);printf("              *                                                                                 *\n");
	gotoxy(16, 20);printf("            *                                                                                     *\n");
	gotoxy(16, 21);printf("           *                                                                                       *\n");
	gotoxy(16, 22);printf("         *                                                                                           *\n");
	gotoxy(16, 23);printf("        *                                                                                             *\n");
	gotoxy(16, 24);printf("       *                                                                                               *\n");
	gotoxy(16, 25);printf("      *                                                                                                 *\n");
	gotoxy(16, 26);printf("     *                                                                                                   *\n");
	gotoxy(16, 27);printf("    *                                                                                                     *\n");
	gotoxy(16, 28);printf("    *                                                                                                     *\n");
	gotoxy(16, 29);printf("   *                                                                                                       *\n");
	gotoxy(16, 30);printf("  *                                                                                                         *\n");
	gotoxy(16, 31);printf("  *                                                                                                         *\n");
	gotoxy(16, 32);printf(" *                                                                                                           *\n");
	gotoxy(16, 33);printf(" *                                                                                                           *\n");
	gotoxy(16, 34);printf(" *                                                                                                           *\n");
	gotoxy(16, 35);printf(" *                                                                                                           *\n");
	gotoxy(16, 36);printf(" *                                                                                                           *\n");
	gotoxy(16, 37);printf("**                                                                                                           **\n");
	gotoxy(16, 38);printf(" *                                                                                                           *\n");
	gotoxy(16, 39);printf(" *                                                                                                           *\n");
	gotoxy(16, 40);printf(" *                                                                                                           *\n");
	gotoxy(16, 41);printf(" *                                                                                                           *\n");
	gotoxy(16, 42);printf(" *                                                                                                           *\n");
	gotoxy(16, 43);printf("  *                                                                                                         *\n");
	gotoxy(16, 44);printf("  *                                                                                                         *\n");
	gotoxy(16, 45);printf("  *                                                                                                         *\n");
	gotoxy(16, 46);printf("   *                                                                                                       *\n");
	gotoxy(16, 47);printf("    *                                                                                                     *\n");
	gotoxy(16, 48);printf("     *                                                                                                   *\n");
	gotoxy(16, 49);printf("      *                                                                                                 *\n");
	gotoxy(16, 50);printf("       *                                                                                               *\n");
	gotoxy(16, 51);printf("        *                                                                                             *\n");
	gotoxy(16, 52);printf("         *                                                                                           *\n");
	gotoxy(16, 53);printf("           *                                                                                       *\n");
	gotoxy(16, 54);printf("            *                                                                                     *\n");
	gotoxy(16, 55);printf("              *                                                                                 *\n");
	gotoxy(16, 56);printf("                *                                                                             *\n");
	gotoxy(16, 57);printf("                  *                                                                         *\n");
	gotoxy(16, 58);printf("                    *                                                                     *\n");
	gotoxy(16, 59);printf("                      *                                                                 *\n");
	gotoxy(16, 60);printf("                         *                                                           *\n");
	gotoxy(16, 61);printf("                             *                                                   *\n");
	gotoxy(16, 62);printf("                                 *                                           *\n");
	gotoxy(16, 63);printf("                                      *                                 *\n");
	gotoxy(16, 64);printf("                                             *********************");
}

void forcon(int x, int colon1[][3]) { //디지털 출력함수
	int y = 3;
	int a = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (colon1[i][j] == 1) {
				gotoxy(x + a, y); printf("■");
				a += 2;
			}
			else if (colon1[i][j] == 0) {
				gotoxy(x + a, y); printf("  ");
				a += 2;
			}
		}
		y++;
		a = 0;
		printf("\n");
	}
}
void formin(double a, int b) {//아날로그 대각선 출력 함수
	double c;
	int d, e, x = 0, y = 0, r = 0, f;

	if (a > 70 && b < 37) {// 제 1사분면
		c = sqrt((a - 70) * (a - 70) + (37 - b) * (37 - b));

		d = ((int)a - 70);
		e = (37 - b);
		while (e) {
			r = d % e;
			d = e;
			e = r;
		}
		f = d;
		d = ((int)a - 70) / f;
		e = (37 - b) / f;
		for (int j = 1; j <= c; j++) {
			if (37 - y > 10) {
				gotoxy(70 + x, 37 - y); printf("@");
				x += d; y += e;
			}
		}
	}
	else if (a > 70 && b > 37) {// 제 4사분면
		c = sqrt((a - 70) * (a - 70) + (b - 37) * (b - 37));

		d = ((int)a - 70);
		e = (b - 37);
		while (e) {
			r = d % e;
			d = e;
			e = r;
		}
		f = d;
		d = ((int)a - 70) / f;
		e = (b - 37) / f;
		for (int j = 1; j <= c; j++) {
			if (37 + y < 65) {
				gotoxy(70 + x, 37 + y); printf("@");
				x += d; y += e;
			}
		}
	}
	else if (a < 70 && b>37) {// 제 3사분면
		c = sqrt((70 - a) * (70 - a) + (b - 37) * (b - 37));

		d = (70 - (int)a);
		e = (b - 37);
		while (e) {
			r = d % e;
			d = e;
			e = r;
		}
		f = d;
		d = (70 - (int)a) / f;
		e = (b - 37) / f;
		for (int j = 1; j <= c; j++) {
			if (37 + y < 65) {
				gotoxy(70 - x, 37 + y); printf("@");
				x += d; y += e;
			}
		}
	}
	else if (a < 70 && b < 37) {// 제 2사분면
		c = sqrt((70 - a) * (70 - a) + (37 - b) * (37 - b));

		d = (70 - (int)a);
		e = (37 - b);
		while (e) {
			r = d % e;
			d = e;
			e = r;
		}
		f = d;
		d = (70 - (int)a) / f;
		e = (37 - b) / f;
		for (int j = 1; j <= c; j++) {
			if (37 - y < 65) {
				gotoxy(70 - x, 37 - y); printf("@");
				x += d; y += e;
			}
		}
	}
	if (a == 70 && b == 13) {//12시방향
		for (int i = 1; i <= 20; i++) {
			gotoxy(70, 37 - i); printf("@\n");
		}
	}
	if (a == 29 && b == 37) {//9시방향
		for (int i = 1; i <= 40; i++) {
			gotoxy(29 + i, 37); printf("@");
		}
	}
	if (a == 59 && b == 37) {//3시방향
		for (int i = 1; i <= 44; i++) {
			gotoxy(70 + i, 37); printf("@");
		}
	}
	if (a == 70 && b == 52) {//6시방향
		for (int i = 1; i <= 24; i++) {
			gotoxy(70, 37 + i); printf("@");
		}
	}
}
