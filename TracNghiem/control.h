void gotoxy( short x, short y );
void veKhung(int x, int y, int z, int g, int kiTu);
int LuaChon(int sodongDau, int soDongCuoi, int vtConTro);
int LuaChonDe(int sodongDau, int soDongCuoi, int vtConTro);
int DiChuyen();
//---------------------------------------------

// set vi tri
void gotoxy( short x, short y ) 
{ 
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD position = { x, y }; 
    SetConsoleCursorPosition(hStdout, position);
}
// 39 69 9 15
void veKhung(int x, int y, int z, int g, int kiTu)
{
	for(int i=x;i<y;i++) 
 	{
		gotoxy(i,z);
		printf("%c\n", 254);// tao dong ngang tren
	  	gotoxy(i,g);
  		printf("%c\n", 254); // dong ngang duoi
  	}
   	for(int i=z;i<=g;i++)  // dong ke thang dung
  	{
		 gotoxy(x,i);printf("%c\n", kiTu); // dong thang dung ben trai
		 gotoxy(y,i);printf("%c\n", kiTu); // dong thang dung ben phai
  	}
}
//Menu dau tien
int LuaChon(int sodongDau, int soDongCuoi, int vtConTro)
{
	bool thoat = false;
	int line = sodongDau+1, x;
			gotoxy(vtConTro, line);// set vi tri con tro
			printf("%c", 175); // tao con tro
	while (!thoat) {
 
        if (kbhit()) { //phat hien co phim nhan vao
 
            x = DiChuyen();
 
            gotoxy(vtConTro, line);
            printf(" "); // xoa con tro cu
 
            switch (x) {
 
                case 1:
                case 3:
                    {
                        line++;
                        if (line >= soDongCuoi) 
							line=sodongDau+1;
                        break;
                    }
 
  
  				case 2:
      			case 4:
                    {
                        line--;
                        if (line <= sodongDau) 
							line = sodongDau+soDongCuoi-sodongDau-1;
                        break;
                    }
       			case 5:
                    {
                    	if(line==sodongDau+1)
                    		return 1;
                   		else if(line==sodongDau+2)
                   			return 2;
       					else if(line==sodongDau+3)
       						return 3;
 						else if(line==sodongDau+4)
 							return 4;
 						else if(line==sodongDau+5)
 							return 5;
 						else if(line==sodongDau+6)
 							return 6;
 						else if(line==sodongDau+7)
 							return 7;
 						else if(line==sodongDau+8)
 							return 8;
 						else
							return 0;
                        break;
 
                    }
 
                case 8:
                    thoat = true;
            }
 
            gotoxy(vtConTro, line);
            printf("%c", 175);
 
        }
 
    }
}
int LuaChonDe(int sodongDau, int soDongCuoi, int vtConTro)
{
	bool thoat = false;
	int line = sodongDau+1, ngang = vtConTro, x;

			gotoxy(vtConTro, line);// set vi tri con tro
			printf("%c", 175); // tao con tro 
			veKhung(39, 79, 0, 6, 219);
	while (!thoat) {
 
        if (kbhit()) { //phat hien co phim nhan vao
 
            x = DiChuyen();
 
            gotoxy(ngang, line);
            printf(" "); // xoa con tro cu
 
            switch (x) {
 
                case 1:
                	{
                        line++;
                        if (line >= soDongCuoi && ngang<50) 	
						{
							line=sodongDau+1;
						}
						else if(line >= soDongCuoi-1 && ngang>50)
						{
							line = sodongDau+1;
							ngang == 70;
						}
						break;
                    }
                case 3: 
                	{
	                	ngang = ngang +30;
	                	if(ngang>=81)
	                		ngang=vtConTro;
                		else if(ngang>=50 && line==5)
	                			ngang = 40;
                		break;
	                }
  				case 2:
 					{
                        line--;
                        if (line <= sodongDau ) 
						{
							line = sodongDau+soDongCuoi-sodongDau-1;
							ngang = 40;
						}
                        break;
                    }
      			case 4:
        			{
	                	ngang = ngang - 30;
	                	if(ngang<=39)
	                		ngang=vtConTro+30;
                		if(ngang<=80 && line==5)
	                			ngang = 40;
                		break;
	                }
       			case 5:
                    {
                    	if(line==2 && ngang<50)
                    		return 1;
                    	else if(line==3 && ngang<50)
                    		return 3;
                    	else if(line==4 && ngang<50)
                    		return 5;
                    	else if(line==2 && ngang>50)
                    		return 2;
                    	else if(line==3 && ngang>50)
                    		return 4;
   		               	else if(line==4 && ngang>50)
                    		return 6;
                   		else
                   			return 0;
 						
                        break;
 
                    }
 
                case 8:
                    thoat = true;
            }
 
            gotoxy(ngang, line);
            printf("%c", 175);
 
        }
 
    }
}
int DiChuyen() {
 
    char c = getch();
 
    if ((int) c == -32) c = getch();
 
    switch ((int) c) {
 
        case 80:
            return 1; //  "Xuong";
 
        case 72:
            return 2; //"Len";
 
        case 77:
            return 3; //"Phai";       
 
        case 75:
            return 4; //"Trai";
 
        case 27:
            return 8; //Nut ESC thoat
 
        case 13:
            return 5; //Nut Enter
 
        default:
            return 0; //"Sai";
    } 
}
