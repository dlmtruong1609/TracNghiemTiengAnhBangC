void wait( int seconds );
void DiemNguoc(int k, char* x);
int DongHo(int k);
void CaiDatMau(char* textColorBG);
void BangMau();
void DoiMau(char chon);
DWORD WINAPI ThreadProc(LPVOID param);
void HieuUngTuyetRoi(int x);
DWORD WINAPI ThreadProcSnow(LPVOID param);
typedef struct tagTIME
{
	int h, m, s, k;
	int x, x1; //thr cua hieu ung tuyer roi
} *TIME;
//------------------------------------------
// Cho dong ho chay
void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}
void DiemNguoc(int k, char* x)
{
	int n;
	for (n = k; n > 0; n--)
	  {
	    printf ("%s: %d\n",x, n);
	    wait (1);
	    system("cls");
	  }
}

int DongHo(int k)
{
	int n, p=0, s;
	p = k/60;
	if(k%60==0)
		s=0;
	else
		s=k%60;
	for (n = k; n > 0; n--)
	  {
	  	gotoxy(50,18);
	  	printf("Thoi gian: %dp %ds", p, s);
	    wait (1);
		if(s==0)
		{
			s=60;
			p--;
		}
		s--;
	    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	  }
 	return 0;
}

//
void CaiDatMau(char* textColorBG) // set mau cho nen va chu
{
	system(textColorBG);
}
//
void BangMau()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 128);
	printf("0 - black\n");
	SetConsoleTextAttribute(hConsole, 1);
	printf("1 - blue\n");
	SetConsoleTextAttribute(hConsole, 2);
	printf("2 - Green\n");
	SetConsoleTextAttribute(hConsole, 3);
	printf("3 - Aqua\n");
	SetConsoleTextAttribute(hConsole, 4);
	printf("4 - Red\n");
	SetConsoleTextAttribute(hConsole, 5);
	printf("5 - Purple\n");
	SetConsoleTextAttribute(hConsole, 6);
	printf("6 - Yello\n");
	SetConsoleTextAttribute(hConsole, 7);
	printf("7 - White\n");
	SetConsoleTextAttribute(hConsole, 8);
	printf("8 - Gray\n");
	SetConsoleTextAttribute(hConsole, 9);
	printf("9 - Light blue\n");
	SetConsoleTextAttribute(hConsole, 'B');
	printf("A - LightGreen\n");
	SetConsoleTextAttribute(hConsole, 'C');
	printf("B - LightAqua\n");
	SetConsoleTextAttribute(hConsole, 76);
	printf("C - LightRed\n");
	SetConsoleTextAttribute(hConsole, 'E');
	printf("D - LightPurple\n");
	SetConsoleTextAttribute(hConsole, 'F');
	printf("E - LightYellow\n");
	SetConsoleTextAttribute(hConsole, 'G');
	printf("F - BrightWhite\n");
}
void DoiMau()
{
	int i=0;
	do{
		Sleep(500);
		system("color 01");
			Sleep(500);
		system("color 02");
			Sleep(500);
		system("color 03");
			Sleep(500);
		system("color 04");
			Sleep(500);
		system("color 09");
		i++;
	}while(i<10);
}
DWORD WINAPI ThreadProc(LPVOID param)
{
	DoiMau();
	return 0;

}
DWORD WINAPI ThreadProc1(LPVOID param)
{
	TIME pParam = (TIME)param;
	DongHo(pParam->k);
	return 0;  
}

void HieuUngTuyetRoi(int x)
{
	int  y=0;
	while(1){
		gotoxy(x, y);
		printf("               ");
		gotoxy(x, y+1);
		printf("               ");
		gotoxy(x, y+2);
		printf("               ");
		gotoxy(x, y+3);
		printf("               ");
		gotoxy(x, y+4);
		printf("               ");
		gotoxy(x, y+5);
		printf("               ");
		gotoxy(x, y+6);
		printf("               ");
		gotoxy(x, y+7);
		printf("               ");
		gotoxy(x, y+8);
		printf("               ");
		
		gotoxy(x, y+9);
		printf("               ");
		gotoxy(x, y+10);
		printf("               ");
		gotoxy(x, y+11);
		printf("               ");
		gotoxy(x, y+12);
		printf("               ");
		gotoxy(x, y+13);
		printf("               ");
		gotoxy(x, y+14);
		printf("               ");
		gotoxy(x, y+15);
		printf("               ");
		gotoxy(x, y+16);
		printf("               ");
		gotoxy(x, y+17);
		printf("               ");
		
		gotoxy(x, y+18);
		printf("               ");
		gotoxy(x, y+19);
		printf("               ");
		gotoxy(x, y+20);
		printf("               ");
		gotoxy(x, y+21);
		printf("               ");
		gotoxy(x, y+22);
		printf("               ");
		gotoxy(x, y+23);
		printf("               ");
		gotoxy(x, y+24);
		printf("               ");
		gotoxy(x, y+25);
		printf("               ");
		gotoxy(x, y+26);
		printf("               ");
		gotoxy(x, y+27);
		printf("               ");
		if(y%2!=0)
		{
			gotoxy(x, y);
			printf(" *	*  *");
			gotoxy(x, y+1);
			printf(" *	  * *");
		}
		gotoxy(x, y);
		printf("*	*  *");
		gotoxy(x, y+1);
		printf(" * *  *");
		gotoxy(x, y+2);
		printf(" * *      *");
		gotoxy(x, y+3);
		printf(" *      *  *");
		gotoxy(x, y+4);
		printf("  * *     *");
		gotoxy(x, y+5);
		printf("*	   * *");
		gotoxy(x, y+6);
		printf(" *	*  *");
		gotoxy(x, y+7);
		printf("  *    *      *");
		gotoxy(x, y+8);
		printf(" *	*    *");
		
		gotoxy(x, y+9);
		printf("*   	*  *");
		gotoxy(x, y+10);
		printf(" * * *");
		gotoxy(x, y+11);
		printf(" *   *      *");
		gotoxy(x, y+12);
		printf(" *    *  *");
		gotoxy(x, y+13);
		printf("  *  *    *");
		gotoxy(x, y+14);
		printf("*  * *");
		gotoxy(x, y+15);
		printf("  *	  *   *");
		gotoxy(x, y+16);
		printf("    *   *    *");
		gotoxy(x, y+17);
		printf(" *	  *  *");
		
		gotoxy(x, y+18);
		printf("*	*  *");
		gotoxy(x, y+19);
		printf(" * *  *");
		gotoxy(x, y+20);
		printf(" * *      *");
		gotoxy(x, y+21);
		printf(" *      *  *");
		gotoxy(x, y+22);
		printf("  * *     *");
		gotoxy(x, y+23);
		printf("*	   * *");
		gotoxy(x, y+24);
		printf(" *	*  *");
		gotoxy(x, y+25);
		printf("  *    *      *");
		gotoxy(x, y+26);
		printf(" *	*    *");
		gotoxy(x, y+27);
		printf("*	   * *");
		y++;
			Sleep(500);
		if(y==3)
		{
			y=0;
		}
	}
}

DWORD WINAPI ThreadProcSnow(LPVOID param)
{
	TIME pParam = (TIME)param;	
	HieuUngTuyetRoi(pParam->x);
	return 0;
}
