#include <iostream>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
    int size=30;
    char player = '@' , target = '!' , energy = 'E' , obstacle = 'X' , Timeup = 'T';
    clock_t ft , lt;
//################################################################	
void adress(int x , int y){
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);}
//################################################################
void print(int a, int d, int w, int s, int q, int z, int e, int x){
    for (int i=size/5 ; i<=2*size/5 ; i++) {
	adress(2*i,i); cout << obstacle;
	adress(2*(size-i),i); cout << obstacle;
	adress(2*i,(size-i)); cout << obstacle;
	adress(2*(size-i),(size-i)); cout << obstacle;}
//--------------------------------------------------
        adress(2*a,w); cout << target;
        adress(2*z,q); cout << energy;
        adress(2*x,e); cout << Timeup;
        adress(2*d,s); cout << player;
//--------------------------------------------------
    for (int i=0 ; i<=size ; i++){
        adress(2*size+1,i); cout << "|";}
//--------------------------------------------------
	    cout << endl;
		for (int i=0 ; i<2*size+1 ; i++) cout << "_"; cout << "|";}
//################################################################
int main()
{   system("color 3B");
    int s=0 , d=0 , w=0 , a=0 , q=0 , z=0 , e=0 , x=0;
	int point=-1;
	int charge=size;
	int Time=2*size/5;
	char wsad;
	unsigned seed;
	int intft, Timedown, intlt;
//--------------------------------------------------
	cout<<"Hi. Do you want to play? This is not easy!! you can move with w,s,a,d.\n"
	<<"You should get ! marks to get points but you shold be careful! Becaouse,\n"
	<<"you should get E marks to get energy to keep moving and also you shold get\n"
	<<"T marks to get more time, you don't have enought time for rest, so hurry up!\n"
	<<"Let's play a game now... Enter every thing to bigin:";
	getch(); system("cls");
//--------------------------------------------------
	Rand:    srand(time(NULL));
	adress(2*a,w); cout << ' ';
    adress(2*z,q); cout << ' ';
    adress(2*x,e); cout << ' ';
		if (w==s && a==d) {point++;
		adress(2*a,w); cout << ' ';
			w = 1 + rand() % size ;
		    a = 1 + rand() % size ;}
		if (q==s && z==d) {charge+=size;
		adress(2*z,q); cout << ' ';
			q = 1 + rand() % size ;
		    z = 1 + rand() % size ;}
		if (e==s && x==d) {Time+=size/5;
		adress(2*x,e); cout << ' ';
			e = 1 + rand() % size ;
		    x = 1 + rand() % size ;}
//--------------------------------------------------
	for (int i=size/5 ; i<=2*size/5 ; i++) {
        if (w==q && a==z || w==i && a==i || w==(size-i) && a==i ||
		w==i && a==(size-i) || w==(size-i) && a==(size-i) ||
		q==i && z==i || q==(size-i) && z==i || q==i && z==(size-i) ||
		q==(size-i) && z==(size-i) || e==i && x==i || e==(size-i) && x==i ||
		e==i && x==(size-i) || e==(size-i) && x==(size-i)) goto Rand;}
//--------------------------------------------------
	print(a, d, w, s, q, z, e, x);
		cout << endl << "Point = " << point;
		cout << endl << "Charge = " << charge;
		cout << endl << "Time = " << Time;
	do  {  	ft=clock(); intft = (int)ft / ((int)CLOCKS_PER_SEC);
	    charge--;
	    wsad = getch();
        adress(2*d,s); cout << ' ';
			 if (wsad == 'a'){
			     if (d!=0) d--;
			     else d=size;}
		else if (wsad == 'w'){
		         if (s!=0) s--;
			     else s=size;}
		else if (wsad == 'd'){
		         if (d!=size) d++;
		         else d=0;}
		else if (wsad == 's'){
		         if (s!=size) s++;
		         else s=0;}
//--------------------------------------------------
        for (int i=size/5 ; i<=2*size/5 ; i++) {
        if (s==i && d==i || s==(size-i) && d==i ||
		 s==i && d==(size-i) || s==(size-i) && d==(size-i)) goto End;}
//--------------------------------------------------
        lt = clock(); intlt = (int)lt / ((int)CLOCKS_PER_SEC);
        Timedown = intlt - intft;
        Time -= Timedown;
//--------------------------------------------------
		if (w==s && a==d || q==s && z==d || e==s && x==d) goto Rand;
		else print(a, d, w, s, q, z, e, x);
				cout << endl << "Point = " << point;
		        cout << endl << "Charge = " << charge;
		        cout << endl << "Time = " << Time;
	} while(charge>0 && Time>0);
//--------------------------------------------------
End :    system("cls");
	cout << "Game Over.\nPoint = " << point; 
		 if (charge == 0) cout << endl << "Charge Finished.";
	else if (Time <= 0) cout << endl << "Time Out.";
	else for (int i=size/5 ; i<=2*size/5 ; i++) {
	if (s==i && d==i || s==(size-i) && d==i ||
    	s==i && d==(size-i) || s==(size-i) && d==(size-i))
    	cout << endl << "Touch Obstacle.";}
	cin.get();
	cout << "Enter 'E' to exit or enter every thing to play again.";
    if ( getch() == 'e' || getch() == 'E' ) return 0;
	system("cls"); Time=2*size/5; charge=size; point=-1; q=w=e=a=s=d=z=x=0; goto Rand;}
