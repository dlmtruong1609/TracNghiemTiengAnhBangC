#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
#include "control.h"
#include "hieuung.h"
#define MAX 100
#define consoleWidth 855
#define consoleHeight 30
//=============================CAU TRUC====================================
enum TrangThai{UP, DOWN};
struct DETHI
{
	char tieuDe[100];
	char cauHoi[100];
	char dapAnA[100];
	char dapAnB[100];
	char dapAnC[100];
	char dapAnD[100];
};
struct THONGTIN	
{
	char hoTen[300];
	char tuoi[300];
	char mssv[300];
	char acc[300];
	char pass[300];
	char diem[300];
};
struct DAPANDETHI
{
	int dapAn;
};
DETHI de1[MAX];
char chu[10] = "color 09";
tagTIME t;
char tK[20];
//================================NGUYEN MAU HAM===============================
void menuMain();
int DocFileDeThiTextVaoMang(char* filename, DETHI taiKhoan[], int &n);
int GhiMangVaoFileText(char* filename, DETHI taiKhoan[], int n);
int DocFileDapAnVaoMang(char* filename, DAPANDETHI taiKhoan[], int &n);
void showMainMenu(THONGTIN showMeNu[], int n);
void showTestMenu();
void xuatDanhSachVaThucThi(DETHI taiKhoan[], DAPANDETHI de[], int n, char* dapande, char* bode, char* account);
void KetQuaThi(int socau,int n, int x, int taiKhoan[], DAPANDETHI b[]);
void xuat(THONGTIN arr[],int n);
//Dang nhap dang ky
int DangNhap(THONGTIN a[],int &n);
int DangKy(THONGTIN a,THONGTIN arr[] ,int n);
int GhiThongTinDangKy(char* filename,THONGTIN taiKhoan);
int DocFileDangKy(char* filename, THONGTIN taiKhoan[], int &n);
void doiMatKhau(char *taiKhoan,THONGTIN arr[] , int &n);
int GhiThongTinDangKy_Again(char* filename,THONGTIN taiKhoan[],int &n);
//Them
int GhiThongTinDeThi(char* filename,DETHI taiKhoan);
int themCauHoi(DETHI arr[], DETHI taiKhoan, int n);
//About
void About();
void Title();
void Title1();
void ThongTinTK();
void HuongDan();
//XEP HANG
int GhiThongTinXepHang(char* filename,char *account,float diem);
int GhiThongTinXepHang_Char(char* filename,char *account,char *diem);
int DocFileXepHang(char* filename, THONGTIN taiKhoan[], int &n);
void Swap(char *a, char* b);
void xepThuHang(char* filename,THONGTIN taiKhoan[], int &n);
int GhiFileTrang(char* filename);
void xoaPhanTuTrung(THONGTIN arr[],int &n,int viTri);
void lichSuThi(THONGTIN arr[] , int &n);
//===============================MAIN CHINH=====================================
int main(int argc, char *argv[])
{
	int chon,n, dangNhap;
	THONGTIN taiKhoan[100],dangKi, showMeNu[100],doiMK[100];
	DETHI de;
	DAPANDETHI dapande1[MAX];
	HANDLE hConsole =GetStdHandle( STD_OUTPUT_HANDLE),thr;
	DWORD param;
	t.k = 3600;
	SetConsoleTitle("Chuong trinh trac nghiem tieng anh lop 12"); //Dat ten tieu de chuong trinh
	CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);
			 LoadScreen();
 			do{
			thr = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);// tao them 1 luong
			menuMain();
			chon = LuaChon(16, 21, 44);
			switch(chon){
				case 1:
			        //	CloseHandle(thr);
		    	    CaiDatMau(chu);
			    	system("cls");
			    	TerminateThread(thr, param);
			    	dangNhap = DangNhap(taiKhoan, n);
		       	if(dangNhap!=-1){//Dang nhap
				// Menu Chon 
		    	do{
				CaiDatMau(chu);
				showMainMenu(showMeNu, n);
				chon = LuaChon(13, 19, 49);
				switch(chon){
					case 1:
					//Menu chon de
				    	showTestMenu();
						fflush(stdin);
						chon = LuaChonDe(1, 6, 40);
						switch(chon)
						{
						case 1:
							system("cls");
							DiemNguoc(3, "Bat dau thi sau");
							printf("Bo de 1\n");
					    	xuatDanhSachVaThucThi(de1, dapande1, n, "dethivadapan/dapande1.txt", "dethivadapan/bode1.txt", taiKhoan[dangNhap].acc);
							break;
						case 2:
					    	system("cls");
					    	DiemNguoc(3, "Bat dau thi sau");
							printf("Bo de 2\n");
							xuatDanhSachVaThucThi(de1, dapande1, n,"dethivadapan/dapande2.txt",  "dethivadapan/bode2.txt", taiKhoan[dangNhap].acc);
							break;
						case 3:
							system("cls");
							DiemNguoc(3, "Bat dau thi sau");
					    	printf("Bo de 3\n");
							xuatDanhSachVaThucThi(de1, dapande1, n,"dethivadapan/dapande3.txt",  "dethivadapan/bode3.txt", taiKhoan[dangNhap].acc);
							break;
						case 4:
							system("cls");
							DiemNguoc(3, "Bat dau thi sau");
							printf("Bo de 4\n");
							xuatDanhSachVaThucThi(de1, dapande1, n,"dethivadapan/dapande4.txt",  "dethivadapan/bode4.txt", taiKhoan[dangNhap].acc);
							break;
				        case 5:
							system("cls");
							DiemNguoc(3, "Bat dau thi sau");
							printf("Bo de 5\n");
					    	xuatDanhSachVaThucThi(de1, dapande1, n,"dethivadapan/dapande5.txt",  "dethivadapan/bode5.txt", taiKhoan[dangNhap].acc);
							break;
						case 6:
					    	system("cls");
							DiemNguoc(3, "Bat dau thi sau");
							printf("Bo de 6\n");
							xuatDanhSachVaThucThi(de1, dapande1, n,"dethivadapan/dapande6.txt",  "dethivadapan/bode6.txt", taiKhoan[dangNhap].acc);
							break;
				        case 0:
					    	system("cls");
							break;
						default:
						//MessageBox(NULL, "Ban nhap sai! Vui long nhap lai!", "Error", MB_OK);//HIen thi hop thoai thong bao loi
							system("cls");
							break;
				    	}
								break;
					case 2:
						system("cls");
					    gotoxy(2, 1);
						printf("1. Thay doi mau nen + text\n");
						gotoxy(2, 2);
						printf("2. Thay doi thoi gian\n");
						gotoxy(2, 3);	
						printf("3. Quay lai\n");
						char esc;
						if(kbhit()){//phat hien co phim nhan
						esc = getch();
						}
						if(esc==27)
							break;
						chon = LuaChon(0, 4, 0);
						switch(chon){					
								case 1:
									system("cls");
									BangMau();
									SetConsoleTextAttribute(hConsole, 1);
									printf("\nChon so tuong ung nhu mau o bang tren voi cu phap sau: color 02 \n");
							    	printf("0 la mau nen (Den)\n");
									printf("2 la mau chu (Xanh)\n ");
							    	printf("Hoac chi doi mau chu: color 1\n");
									printf("Nhap cu phap: ");
									fflush(stdin);
									gets(chu);
									CaiDatMau(chu);
									system("cls");
											break;
								case 2:
									system("cls");
									printf("Nhap gio: ");
									scanf("%d", &t.h);
									printf("Nhap phut: ");
									scanf("%d", &t.m);
									printf("Nhap giay: ");
									scanf("%d", &t.s);
									t.k = t.h*60*60+t.m*60+t.s;
									printf("Thay doi thanh cong\n");
							    	system("pause");
								    system("cls");
											break;
								case 3:
									system("cls");
											break; 
							    	}
										break;
					case 3:
						system("cls");
						printf("\n>>>Danh Sach Thu Hang Account<<<");
						xepThuHang("XepHang.txt", taiKhoan, n);
						gotoxy(0, 28);
						system("pause");
						system("cls");
							break;
					case 4:
						system("cls");
						doiMatKhau(taiKhoan[dangNhap].acc,doiMK,n);
						system("pause");
						system("cls");
							break;
					case 5:
							break;
					default:
			    	//MessageBox(NULL, "Ban nhap sai! Vui long nhap lai!", "Error", MB_OK);//HIen thi hop thoai thong bao loi
						system("cls");
							break;
							}
						}while(chon!=5);
					}
					break;
				case 2:
				//CloseHandle(thr);
					system("cls");
					TerminateThread(thr, param); 
					if(DangKy(dangKi,taiKhoan,n)==1){
						printf("\nDang ky thanh cong\n");
						system("pause");
						break;
					} if(DangKy(dangKi,taiKhoan,n)==-1){
						SetConsoleTextAttribute(hConsole, 2);
						printf("\nTat ca thong tin khong duoc nhap khoang trang");
						system("pause");
						break;
					}
					else
						SetConsoleTextAttribute(hConsole, 2);
						printf("\n>>> Ten tai khoan da ton tai hoac ban da nhap khoan trang vui long dang ky lai <<<\n\n");
						system("pause");
					break;
				case 3:
					TerminateThread(thr, param);
					About();
					break;
				case 4:
					SetConsoleTextAttribute(hConsole, 9);
					int mess = MessageBox(NULL, "Ban muon thoat chuong trinh sao? Toi buon lam do :((", "THOAT", MB_ICONQUESTION | MB_YESNO);//HIen thi hop thoai
					if(mess==6)
					{
						gotoxy(0, 28);
						printf("Hen gap lai!");
						chon=0;
						break;
					}
					else
						break;
			}
		}while(chon!=0);
	return 0;
}
//===============================VIET HAM========================================
// Menu va giao dien-----------------------------------------
void Title()
{
			gotoxy(20, 1);
			printf(" _____  _   _ _   _ _____ _   _ _____   ___________ _____ _   _  _   _ ");
			gotoxy(20, 2);
			printf("/  __ \\| | | | | | |  _  | \\ | |  __ \\ |_   _| ___ \\_   _| \\ | || | | |");
			gotoxy(20, 3);
			printf("| /  \\/| |_| | | | | | | |  \\| | |  \\/   | | | |_/ / | | |  \\| || |_| |");
			gotoxy(20, 4);
			printf("| |    |  _  | | | | | | | . ` | | __    | | |    /  | | | . ` ||  _  |");
			gotoxy(20, 5);
			printf("| \\__/\\| | | | |_| \\ \\_/ / |\\  | |_\\ \\   | | | |\\ \\ _| |_| |\\  || | | |");
			gotoxy(20, 6);
			printf("\\____/\\_|  |_/\\___/ \\___/\\_| \\_/\\____/   \\_/ \\_| \\_|\\___/\\_| \\_/ \\_||_/");
			gotoxy(20, 9);
			printf(" ___________  ___  _____   _   _ _____  _   _ _____ ________  ___");
			gotoxy(20, 10);
			printf("|_   _| ___ \\/ _ \\/  __ \\ | \\ | |  __ \\| | | |_   _|  ___|  \\/  |");
			gotoxy(20, 11);
			printf("  | | | |_/ / /_\\ \\ /  \\/ |  \\| | |  \\/| |_| | | | | |__ | .  . |");
			gotoxy(20, 12);
			printf("  | | |    /|  _  | |     | . ` | | __ |  _  | | | |  __|| |\\/| |");
			gotoxy(20, 13);
			printf("  | | | |\\ \\| | | | \\__/\\ | |\\  | |_\\ \\| | | |_| |_| |___| |  | |");
			gotoxy(20, 14);
			printf("  \\_/ \\_| \\_\\_| |_/\\____/ \\_| \\_/\\____/\\_| |_/\\___/\\____/\\_|  |_/");
}
void menuMain()
{
	
			CaiDatMau(chu);
			system("cls");
			Title();
			veKhung(15, 95, 0, 24, 254);
			gotoxy(46, 17);//Set vi tri	
			printf("1 .Dang nhap");
			gotoxy(46, 18);
			printf("2 .Dang ky");
			gotoxy(46, 19);
			printf("3. About\n");
			gotoxy(46, 20);
			printf("4. Thoat");
			gotoxy(46, 21);
}
void Title1()
{
	//Chuong
	gotoxy(33, 0);
	printf(" _____  _   _ _   _ _____ _   _ _____ ");
	gotoxy(33, 1);
	printf("/  __ \\| | | | | | |  _  | \\ | |  __ \\");
	gotoxy(33, 2);
	printf("| /  \\/| |_| | | | | | | |  \\| | |  \\/");
	gotoxy(33, 3);
	printf("| |    |  _  | | | | | | | . ` | | __");
	gotoxy(33, 4);
	printf("| \\__/\\| | | | |_| \\ \\_/ / |\\  | |_\\ \\");
	gotoxy(33, 5);
	printf("\\____/\\_| |_/\\___/ \\___/\\_| \\_/\\____/");
	//Trinh
	gotoxy(54, 6);
	printf("______ _____ _____ _   _  _   _ ");
	gotoxy(54, 7);
	printf("|_   _| ___ \\_   _| \\ | || | | |");
	gotoxy(54, 8);
	printf("  | | | |_/ / | | |  \\| || |_| |");
	gotoxy(54, 9);
	printf("  | | |    /  | | | . ` ||  _  |");
	gotoxy(54, 10);
	printf("  | | | |\\ \\ _| |_| |\\  || | | |");
	gotoxy(54, 11);
	printf("  \\_/ \\_| \\_|\\___/\\_| \\_/\\_| |_/");
	//Luyen
	gotoxy(82, 13);
	printf(" _     _   ___   _______ _   _ ");
	gotoxy(82, 14);
	printf("| |   | | | \\ \\ / /  ___| \\ | |");
	gotoxy(82, 15);
	printf("| |   | | | |\\ V /| |__ |  \\| |");
	gotoxy(82, 16);
	printf("| |   | | | | \\ / |  __|| . ` |");
	gotoxy(82, 17);
	printf("| |___| |_| | | | | |___| |\\  |");
	gotoxy(82, 18);
	printf("\\_____/\\___/  \\_/ \\____/\\_| \\_/");
	//Thi
	gotoxy(33, 22);
	printf(" _____ _   _ _____ ");
	gotoxy(33, 23);
	printf("|_   _| | | |_   _|");
	gotoxy(33, 24);
	printf("  | | | |_| | | |  ");
	gotoxy(33, 25);
	printf("  | | |  _  | | |  ");
	gotoxy(33, 26);
	printf("  | | | | | |_| |_");
	gotoxy(33, 27);
	printf("  \\_/ \\_| |_/\\___/");
	//Anh
	gotoxy(56, 22);
	printf("  ___   _   _  _   _ ");
	gotoxy(56, 23);
	printf(" / _ \\ | \\ | || | | |");
	gotoxy(56, 24);
	printf("/ /_\\ \\|  \\| || |_| |");
	gotoxy(56, 25);
	printf("|  _  || . ` ||  _  |");
	gotoxy(56, 26);
	printf("| | | || |\\  || | | |");
	gotoxy(56, 27);
	printf("\\_| |_/\\_| \\_/\\_| |_/");
	//Van 12
	gotoxy(81, 22);
	printf(" _   _  ___   _   _   __   _____ ");
	gotoxy(81, 23);
	printf("| | | |/ _ \\ | \\ | | /  | / __  \\");
	gotoxy(81, 24);
	printf("| | | / /_\\ \\|  \\| | `| | `' / /'");
	gotoxy(81, 25);
	printf("| | | |  _  || . ` |  | |   / /  ");
	gotoxy(81, 26);
	printf("\\ \\_/ / | | || |\\  | _| |_./ /___");
	gotoxy(81, 27);
	printf(" \\___/\\_| |_/\\_| \\_/ \\___/\\_____/");
}
void showMainMenu(THONGTIN showMeNu[], int n)
{
		ThongTinTK();
		Title1();
		veKhung(48, 77, 13, 20, 219);
		gotoxy(1,0);
		printf("\n>>>Nhung nguoi vua moi thi<<<");
		lichSuThi(showMeNu, n);
		Sleep(1000);
		gotoxy(51, 14);
		printf("1. Bat dau thi\n");
		Sleep(500);
		gotoxy(51, 15);
		printf("2. Cai dat\n");
		Sleep(500);
		gotoxy(51, 16);
		printf("3. Bang Xep Hang\n");
		Sleep(500);
		gotoxy(51, 17);
		printf("4. Doi mat khau\n");
		gotoxy(51, 18);
		printf("5. Quay lai");
		Sleep(500);
}
void showTestMenu()
{
	system("cls");
	gotoxy(42, 1);
	printf("****** Bo de thi trac nghiem ******\n");
	gotoxy(42, 2);
	printf("1. De 1\t\t\t2.De 2\n");
	gotoxy(42, 3);
	printf("3. De 3\t\t\t4.De 4\n");
	gotoxy(42, 4);
	printf("5. De 5\t\t\t6.De 6\n");
	gotoxy(42, 5);
	printf("0. Quay lai\n");
	HuongDan();
}
//Xu ly thi trac nghiem-----------------------------------------
void xuatDanhSachVaThucThi(DETHI taiKhoan[], DAPANDETHI de[], int n, char* dapande, char* bode, char* account)
{	
	int  chon5[40]; 
	int tongdiem=0, dem = 0;
	HANDLE thr;
	 DWORD param;
	 t.x=98;
		DocFileDeThiTextVaoMang(bode, taiKhoan, n);
		DocFileDapAnVaoMang(dapande, de, n);
		thr= CreateThread(NULL, 0, ThreadProc1, &t, 0, NULL);
		
    	for(int i = 0; i<n; i++)
        {
			do
			{
				veKhung(60, 90, 20, 25, 219);
				HuongDan();
				CaiDatMau(chu);
				gotoxy(2, 1);
				printf("%s\n", taiKhoan[i].tieuDe);
				gotoxy(2, 3);
				printf("%s\n", taiKhoan[i].cauHoi);
				gotoxy(2, 4);
				printf("%s\n", taiKhoan[i].dapAnA);
				gotoxy(2, 5);
				printf("%s\n", taiKhoan[i].dapAnB);
				gotoxy(2, 6);
				printf("%s\n", taiKhoan[i].dapAnC);
				gotoxy(2, 7);
				printf("%s\n",taiKhoan[i].dapAnD);
				gotoxy(2, 8);
				printf("Dung\n");
				if(WaitForSingleObject(thr, 1)==0)//Hang cho het thg gian thi dung
				{
					gotoxy(2, 10);
					printf("Het thoi gian\n");
					goto THOAT;
				}
				chon5[i] = LuaChon(3, 9, 0);
				if(chon5[i]==de[i].dapAn) // tim xem ki tu "chon" co ton tai trong chuoi de[i].dapan hay ko?
					tongdiem++;
					dem++;
				if(chon5[i]==5)
					goto THOAT;
				gotoxy(2, 9);
				system("pause");
				system("cls");
			}while(chon5[i]!=5 && chon5[i]!=1 && chon5[i]!=2 && chon5[i]!=3 && chon5[i]!=4);
        }
        THOAT:;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        KetQuaThi(tongdiem, n, dem, chon5, de);
        GhiThongTinXepHang("XepHang.txt", account, tongdiem*(10/30.0));
       	TerminateThread(thr, param); // tat thread 
		system("pause");
		system("cls");
}


int DocFileDeThiTextVaoMang(char* filename, DETHI taiKhoan[], int &n)
{
	FILE* f = fopen(filename, "r");
	if(!f)
		return 0;
	int i= 0;
	while(!feof(f))
	{
		fgets(taiKhoan[i].tieuDe, 1000, f);
		fgets(taiKhoan[i].cauHoi, 1000, f);
		fgets(taiKhoan[i].dapAnA, 1000, f);
		fgets(taiKhoan[i].dapAnB, 1000, f);
		fgets(taiKhoan[i].dapAnC, 1000, f);
		fgets(taiKhoan[i].dapAnD, 1000, f);
		i++;
	}
	n=i;
}
int DocFileDapAnVaoMang(char* filename, DAPANDETHI taiKhoan[], int &n)
{
	FILE* f = fopen(filename, "r");
	if(!f)
		return 0;
	int i= 0;
	while(!feof(f))
	{
		fscanf(f, "%d", &taiKhoan[i].dapAn);
		i++;
	}
	n=i;
}

//Dang nhap va dang ki-----------------------------------------
int DangNhap(THONGTIN taiKhoan[],int &n)
{	
	char acc[20], pass[20];
	char ch;
	int dem=0,mark=0;
	veKhung(39, 69, 9, 15, 219);
	DocFileDangKy("Dangky.txt",taiKhoan,n);
		gotoxy(50, 10);//Set vi tri	
		printf("Dang Nhap\n");
		gotoxy(40, 11);//Set vi tri	
		printf("Tai khoan\n");
		gotoxy(40, 12);//Set vi tri	
		scanf("%s", &acc);
		gotoxy(40, 13);
		printf("Nhap mat khau\n");
		gotoxy(40, 14);
		while((ch=getch())!='\r') //Chi dung lai khi xuong dong (\r = 'ENTER' khac voi \n, \n la sang dong moi)
		{
			if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
					printf("*");
					pass[dem++]=ch;
			}
		 	else if (ch == -32) //bo qua phím mui tên + space
	            _getch();
 	 		else if(ch=='\b')// backspace de xoa ki tu, \b la dung de lui ve vi tri trai 1 o
	 		{
		 		printf("\b \b");//\b nghia la lui con tro ve ben tra 1 ki tu
		 		dem--;
		 	}
		}
		strcpy(tK, acc);
		pass[dem]='\0'; // ket thuc chuoi
		for(int i = 0 ; i<n;i++){
			if(strcmp(acc,taiKhoan[i].acc)==0 && strcmp(pass,taiKhoan[i].pass)==0)
			{
				printf("\nDang nhap thanh cong\n");
				system("pause");
				system("cls");
				mark=1;
				return i;
			}
		}
		if(mark==0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("\nSai tai khoan hoac mat khau\n");
			system("pause");
			return -1;
		}
}
int DocFileDangKy(char* filename, THONGTIN taiKhoan[], int &n)
{
	FILE* f = fopen(filename, "r");
	if(!f)
		return 0;
	int i= 0;
	while(!feof(f))
	{	
		fscanf(f, "%s", &taiKhoan[i].hoTen);
		fscanf(f, "%s", &taiKhoan[i].mssv);
		fscanf(f, "%s", &taiKhoan[i].tuoi);
		fscanf(f, "%s", &taiKhoan[i].acc);
		fscanf(f, "%s", &taiKhoan[i].pass);
		i++;
	}
	n=i;
}
int GhiThongTinDangKy(char* filename,THONGTIN taiKhoan)
{
	FILE* f = fopen(filename, "a");
	if(!f) return 0;
		fprintf(f, "%s", "");
		fprintf(f, "%s\n", taiKhoan.hoTen);
		fprintf(f, "%s\n", taiKhoan.mssv);	
		fprintf(f, "%s\n", taiKhoan.tuoi);
		fprintf(f, "%s\n", taiKhoan.acc);
		fprintf(f, "%s\n", taiKhoan.pass);	
	fclose(f);
	return 1;
}
int DangKy(THONGTIN taiKhoan,THONGTIN arr[],int n)
{	
	DocFileDangKy("Dangky.txt",arr,n);
	printf("\n------Tao Tai Khoan------\n");
	printf("\n*Luu y*>> Khong nhap khoan trang (space) \n");
	printf("\nTen : ");
	fflush(stdin);
	gets(taiKhoan.hoTen);
	printf("Mssv : ");
	fflush(stdin);
	gets(taiKhoan.mssv);
	printf("Tuoi : ");
	fflush(stdin);
	gets(taiKhoan.tuoi);
	printf("Tai Khoan : ");
	fflush(stdin);
	gets(taiKhoan.acc);
	if(strstr(taiKhoan.hoTen," ") || strstr(taiKhoan.mssv," ") || strstr(taiKhoan.tuoi," ") || strstr(taiKhoan.acc," ")) 
			return -1;
	for(int i=0 ; i<n ;i++){
		if(strcmp(arr[i].acc,taiKhoan.acc)==0) {
			return 0;
		}
	}
	printf("Mat Khau : ");
	fflush(stdin);
	gets(taiKhoan.pass);
	GhiThongTinDangKy("Dangky.txt",taiKhoan);
	return 1;
}
//
int GhiThongTinDangKy_Again(char* filename,THONGTIN taiKhoan[],int &n)
{
	FILE* f = fopen(filename, "w");
	if(!f) return 0;
	for(int i = 0 ; i < n ; i ++){
		fprintf(f, "%s", "");
		fprintf(f, "%s\n", taiKhoan[i].hoTen);
		fprintf(f, "%s\n", taiKhoan[i].mssv);	
		fprintf(f, "%s\n", taiKhoan[i].tuoi);
		fprintf(f, "%s\n", taiKhoan[i].acc);
		fprintf(f, "%s\n", taiKhoan[i].pass);	
	}
	fclose(f);
	return 1;
}
void doiMatKhau(char *taiKhoan,THONGTIN arr[] , int &n){
	char matKhau[30];
	DocFileDangKy("Dangky.txt",arr,n);
	GhiFileTrang("Dangky.txt");
	printf("Nhap mat khau moi :");	
	fflush(stdin);
	gets(matKhau);
	if(strstr(matKhau, " ") || strlen(matKhau)==0)
	{
		SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 4);
		printf("Khong duoc de trong pass\n");
	}
	else
	{
		for(int i = 0 ; i < n ; i++){
			if(strcmp(arr[i].acc,taiKhoan)==0){
				strcpy(arr[i].pass,matKhau);
			}
		}
		SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 7);
		printf("\n\n\t\t\t\t\t\tDoi Mat Khau Thanh Cong\n\n\n\n\n");
	}
	GhiThongTinDangKy_Again("Dangky.txt",arr,n);
}
//Ket qua thi-----------------------------------------

void KetQuaThi(int socau, int n, int x, int taiKhoan[], DAPANDETHI b[])
{
	float diem = socau*(10/30.0);
	printf("Tong so cau ban lam CHINH XAC la: %d/30\n", socau);
	printf("Diem: %.2f	\n", diem);
	printf("Dap an\n");
	for(int i=0; i<n; i++)
	{
		if(b[i].dapAn==1)
			printf("%d. A\t", i+1);
		if(b[i].dapAn==2)
			printf("%d. B\t", i+1);
		if(b[i].dapAn==3)
			printf("%d. C\t", i+1);
		if(b[i].dapAn==4)
			printf("%d. D\t", i+1);
	}
	printf("\nDap an cua ban\n");
	for(int i=0; i<x; i++)
	{
		if(taiKhoan[i]==1)
			printf("%d. A\t", i+1);
		if(taiKhoan[i]==2)
			printf("%d. B\t", i+1);
		if(taiKhoan[i]==3)
			printf("%d. C\t", i+1);//con file dapan3456 chua sua
		if(taiKhoan[i]==4)
			printf("%d. D\t", i+1);
	}
	printf("\n");
}
// BANG XEP HANG-----------------------------------------
int DocFileXepHang(char* filename, THONGTIN taiKhoan[], int &n)
{
	FILE* f = fopen(filename, "r");
	if(!f)
		return 0;
	int i= 0;
	while(!feof(f))
	{	
		fscanf(f, "%s", &taiKhoan[i].acc);
		fscanf(f, "%s", &taiKhoan[i].diem);
		i++;
	}
	n=i;
}
void Swap(THONGTIN a, THONGTIN b)
{
	THONGTIN temp = a;
	a=b;
	b=temp;
}
void xepThuHang(char* filename,THONGTIN taiKhoan[], int &n)
{
	int k;
	THONGTIN temp;
	THONGTIN b[100];
	GhiFileTrang("XepHangTrue.txt");
	DocFileXepHang("XepHang.txt",taiKhoan,n); // 3 4 5

	for(int i = 0; i < n ; i ++){
		for(int j = i+1 ; j<n;j++){	
			if(strcmp(taiKhoan[i].diem,taiKhoan[j].diem)<0){
				temp = taiKhoan[i];
				taiKhoan[i] = taiKhoan[j];
				taiKhoan[j] = temp;
			}  
		}
	}
	gotoxy(1, 1);
	printf("%-5s%-13s%-10s","Top","Account","Diem");
	for(int i = 0; i <n ; i ++){
		GhiThongTinXepHang_Char("XepHangTrue.txt",taiKhoan[i].acc,taiKhoan[i].diem);
	}
	DocFileXepHang("XepHangTrue.txt",b,n);
	for(int i = 0; i < n ; i ++){
		for(int j = i+1 ; j<n;j++){	
			if(strcmp(b[i].acc,b[j].acc)==0){
				xoaPhanTuTrung(b,n,j);
				j--;
			}  
		}
	}
	veKhung(0, 33, 0, 20, 219);
	for(int i = 0; i <n ; i++){
		gotoxy(2, i+2);
		printf("%-5d%-13s%-10s",i+1,b[i].acc,b[i].diem);
		if(n>10)
			n=10;
	}
	THONGTIN tt[MAX];
	char temp1[300];
			DocFileXepHang("XepHangTrue.txt", tt, n);
		strcpy(temp1, "0");
		int flag1 = 0;
		for(int i=0; i<n;i++)
		{
			if(strcmp(tK, tt[i].acc)==0)
			{
				flag1 = 1;
				gotoxy(5, 16);
				printf("Hang cua ban: %d", i+1);
				break;
				
			}
		}
		if(flag1==0)
		{
			strcpy(temp1, "Chua xep hang");
			gotoxy(5, 16);
			printf("Hang cua ban: %s", temp);
		}
}
void lichSuThi(THONGTIN arr[] , int &n){
	DocFileXepHang("XepHang.txt",arr,n);
	veKhung(0, 31, 0, 23, 219);
	gotoxy(2, 2);
	printf("%-10s%-10s%-4s","NewText","Account", "Diem");
	int k =2, l=0;
	while(n>23)
	{
		l++;
		// Gioi han chi 20 phan tu
		if(n<(23+l))
			break;
	}
	for(int i = n-2; i > l  ; i--){
		gotoxy(2, k+1);
		printf("%-10d%-10s%-4s",n-i-1,arr[i].acc,arr[i].diem);
		k++;
	}		
}
void xoaPhanTuTrung(THONGTIN arr[] , int &n, int viTri){
	for(int i = viTri ; i<n ; i++){
		arr[i] = arr[i+1];
	}
	n--;
}
int GhiFileTrang(char* filename)
{	
	FILE* f = fopen(filename, "w");
	if(!f) return 0;
		fprintf(f, "%s", "");
	fclose(f);
	return 1;
}
int GhiThongTinXepHang(char* filename,char *account,float diem)
{	
	FILE* f = fopen(filename, "a");
	if(!f) return 0;
		fprintf(f, "%s", "");
		fprintf(f, "%s\n", account);
		fprintf(f, "%.2f\n", diem);
	fclose(f);
	return 1;
}
int GhiThongTinXepHang_Char(char* filename,char *account,char *diem)
{	
	FILE* f = fopen(filename, "a");
	if(!f) return 0;
		fprintf(f, "%s", "");
		fprintf(f, "%s\n", account);
		fprintf(f, "%s\n", diem);
	fclose(f);
	return 1;
}
//Thong Tin-----------------------------------------
void About()
{
	TrangThai tt;
	int y=0, x = 42, t;
	tt=DOWN;
	char c;
	system("cls");
	while(1)
	{
		if(kbhit())//phat hien co phim nhan
		{
			c = getch();
		}
		if(c==27)
			break;
		system("cls");
		gotoxy(x, y);
		printf("GIOI THIEU\n");
		gotoxy(x, y+2);
		printf("Nhom 5");
		gotoxy(x, y+4);
		printf("Dang Le Minh Truong - 17019711(LEADER)");
		gotoxy(x, y+6);
		printf("Le Thanh Tung");
		gotoxy(x, y+8);
		printf("Nhan Vi Nam - 17025741");
		gotoxy(x, y+10);
		printf("Project: Chuong Trinh Trac Nghiem Tieng Anh");
		gotoxy(x, y+12);
		printf("Ngay hoan thanh: 8/11/2018");
		gotoxy(x, y+14);
		printf("Version: 1.0");
		gotoxy(0,0);
		printf("ESC");
		//XU ly cham bien
		if(y>=15)
			tt=UP;
		else if(y==0) 
			tt=DOWN;
		//Di chuyen
		if(tt==DOWN)
			y++;
		else if(tt==UP)
			y--;
		Sleep(300);
	}
}                          
void ThongTinTK()
{
	THONGTIN a[MAX], tt[MAX];
	char temp[300];
	int n, k;
	veKhung(89, 117, 0, 9, 219);
	DocFileDangKy("DangKy.txt", a, n);
	for(int i = 0;i<n;i++)
	{
		if(strcmp(tK, a[i].acc)==0)
		{
			gotoxy(95, 1);
			printf("THONG TIN TAI KHOAN");
			gotoxy(93, 2);
			printf("Ten TK: %s", a[i].acc);
			gotoxy(93, 3);
			printf("Ten: %s", a[i].hoTen);
			gotoxy(93, 4);
			printf("MSSV: %s", a[i].mssv);
			gotoxy(93, 5);
			printf("Tuoi: %s", a[i].tuoi);
		}
	}
		DocFileXepHang("XepHang.txt", tt, n);
		strcpy(temp, "0");
		int flag = 0;
		for(int i=0; i<n;i++)
		{
			if(strcmp(tK, tt[i].acc)==0)
			{
				flag = 1;
				if(strcmp(tt[i].diem,temp)>0)
					strcpy(temp,tt[i].diem);
			}
		}
		if(flag==0)
		{
			strcpy(temp, "Chua thi");
		}
		gotoxy(93, 6);
		printf("Diem cao nhat: %s", temp);
}
void HuongDan()
{
	veKhung(0, 54, 20, 27, 219);
	gotoxy(2, 22);
	printf("1. Thoi gian thi: 60p (Co the cai dat o muc Cai Dat)");
	gotoxy(2, 23);
	printf("2. Da chon dap an roi thi se khong duoc chon lai");
	gotoxy(2, 24);
	printf("3. Vui long suy nghi ki truoc khi chon dap an");
	gotoxy(2, 25);
	printf("4. Thay doi mau nen + mau chu o muc Cai Dat");
}
