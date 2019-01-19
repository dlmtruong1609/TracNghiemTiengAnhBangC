#include <windows.h>
#include <iostream>
using namespace std;
 
int wsclen(const wchar_t* str) {
    const wchar_t* s;
    for (s = str; *s; ++s);
    return(s - str); //address
}
 
int main(){
    HANDLE hinp = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
 
    wchar_t buf[512];
    DWORD rd, dw;
 
    wchar_t* tmp = "B?n tên chi ? ";
    WriteConsoleW( hout, tmp, wsclen(tmp), &dw, 0 );
    ReadConsoleW( hinp, buf, 512, &rd, 0 );
   
    tmp = "Chào, h?n g?p l?i, ";
    WriteConsoleW( hout, tmp, wsclen(tmp), &dw, 0 );
    WriteConsoleW( hout, buf, rd, &rd, 0 );
   
    cout << "\nDone, bye...";
    system("pause>nil"); cout << endl;
    return 0;
}