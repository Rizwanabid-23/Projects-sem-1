#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;
int px;
int py;
int sx;
int sy;
int gx;
int gy;
int b1x;
int b1y;
int b2x;
int b2y;
int b3x;
int b3y;
int score=0;
char name[8][92]={
	"===========================================================================================",
	"     -----              ---      ------   ----        -----   ----    |\\     ||  ----   ---",
	"    /        ||    ||  ||  \\     |        ||   \\     /       /     \\  | \\    ||   ||   /   ",
	"    |        ||    ||  ||   |    |____    ||   |     |       |     |  || \\   ||   ||  |    ",
	"     -----   ||    ||  ||---     |        ||  /       -----  |     |  ||  \\  ||   ||  |    ",
	"          |  \\\\    //  ||        |        || \\            |  |     |  ||   \\ ||   ||  |    ",
	"     ----/     ----    ||        |------  ||  \\      ----/    \\---/   ||    \\||  ----  \\___",
	"==========================================================================================="
	};
char map[18][90]={
	"+_______________________________________________________________________________________+",
	"|%%%%START%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%SPACE%ARENA%%%%%%%%%%%|",
	"|             .....       %%%%%%%%%CAUTION%%%%%%%%           ....                      %|",
	"|%%%%%%%%%%%%%%%%%%%%%... %%%%%%%%%%%%%%%%%%%%%%%%       ..           .....       .... %|",
	"|%            % .. %K%...          v                                              .... %|",
	"|%     %%%%%%%% .. %E%... ....^.     ...^...  %%%%         .....            ....       %|",
	"|%       ......... %E%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                     ....            %|",
	"|%     %%%%%%%%%%  %P%|vvvvv|%%|vvvvv|%%|vvv|%%%%%    A          A         A           %|",
	"|%     %        %      ..... %% ..... %%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   %%|",
	"|%   %%%        %%%%G%    .. %%              %%|vvvvvvvvvvvvvvvvvvv|%%%%%%%|vvvv|%%   %%|",
	"|%^   .......      %O%    .. %%              %%                                  %%   %%|",
	"|%%%%  %%%%%%%%%   %I%    .. %%     ..%%         <|>....            %%%B%%%|>    %%   %%|",
	"|%  ...... %%..    %N%    .. %%     ..%%            ....            %% E %%|>    %%   %%|",
	"|%   ....  %%..    %G%              ..%%     %%        <|> ... <|>..%% W %%|>    %%   %%|",
	"|%        ________ %%% ..... %% ..... %%     %% .....               %% A %%|>    %%   %%|",
	"|%              $| %%%|^^^^^|%%|^^^^^|%%|^^^|%%|^^^^^^^^^^^^^^^^^^^|%% R %%|>......   %%|",
	"|%%%%%%%%%THE%END%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%E%%%%%%%%%%%%%%%%|",
	"+---------------------------------------------------------------------------------------+"
	};
bool gameRunning=true;

void showMap();
void showName();
void gotoxy( short x, short y );
void movemanLeft();
void movemanRight();
void movemanUp();
void movemanDown();
void moveGhost();
void shooter1();
void shooter2();
void shooter3();

int main(){

showName();
cout<<endl;
cout<<"This is a lite version of super Sonic game."<<endl;
cout<<endl;
cout<<"You have to avoid obstacles,ghost,spaceshooters to reach the sign ($)."<<endl;
cout<<endl;
cout<<"GOODLUCK!!"<<endl;
cout<<endl;
cout<<"Press any key to continue..."<<endl;
getch();
system("cls");
showMap();

px=3;py=2;
gotoxy(px,py);
map[px][py]='O';
cout<<"O";

gx=13;gy=4;
gotoxy(gx,gy);
map[gx][gy]='G';
cout<<"G";

b1x=54;b1y=6;
gotoxy(b1x,b1y);
map[b1x][b1y]=',';
cout<<",";

b2x=65;b2y=6;
gotoxy(b2x,b2y);
map[b2x][b2y]=',';
cout<<",";

b3x=75;b3y=6;
gotoxy(b3x,b3y);
map[b3x][b3y]=',';
cout<<",";

while(gameRunning){
	gotoxy(60,21);
	cout<<"Score :";
	cout<<score<<endl;
	
    if(GetAsyncKeyState( VK_LEFT )){ 
       movemanLeft();	
	}
	if(GetAsyncKeyState(VK_RIGHT)){
		movemanRight();
	}
	if(GetAsyncKeyState(VK_UP)){
		movemanUp();
	}
	if(GetAsyncKeyState(VK_DOWN)){
		movemanDown();
	}
	if(GetAsyncKeyState( VK_ESCAPE) ){
		gameRunning=false;
      }	
    moveGhost();
    shooter1();
    shooter2();
    shooter3();
}
}

void showName(){
	for(int i=0;i<8;i++){
		for(int j=0;j<92;j++){
			cout<<name[i][j];
		}
		cout<<endl;
	}
	
	
}

void showMap(){
 	for(int i=0;i<18;i++)
	 {
  		for(int j=0;j<90;j++)
		{
	    cout<<map[i][j];
		}
  	 cout<<endl;	
	 }
}

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}

void movemanLeft(){
	if(map[py][px-1]=='^' || map[py][px-1]=='v' || map[py][px-1]=='|' || map[py][px-1]=='G' || map[py][px-1]==',' || map[py][px-1]=='A' || map[py][px-1]=='>' || map[py][px-1]=='<'){
		system("cls");
		gotoxy(40,4);
		cout<<"Game Over!"<<endl;
		cout<<endl;
		cout<<"The score was: ";
		cout<<score<<endl;
		gameRunning=false;
		getch();
		}
	if(map[py][px-1] ==' ' || map[py][px-1] =='.' ){
		if(map[py][px-1]=='.'){
			score++;
		}	
	gotoxy(px,py);
	map[px][py]=' ';
	cout<<" ";
	px=px-1;
	gotoxy(px,py);
	cout<<"O";
	map[px][py]='O';
	}
}

void movemanRight(){
	if(map[py][px+1]=='^' || map[py][px+1]=='v' || map[py][px+1]=='|' || map[py][px+1]=='G' || map[py][px+1]==',' || map[py][px+1]=='A' || map[py][px+1]=='>' || map[py][px+1]=='<'){
		system("cls");
		gotoxy(40,4);
		cout<<"Game Over!"<<endl;
		cout<<endl;
		cout<<"The score was: ";
		cout<<score<<endl;
		gameRunning=false;
		getch();
		}
	if(map[py][px+1] ==' ' || map[py][px+1] =='.' ){
  		if(map[py][px+1]=='.'){
			score++;
		}		
	gotoxy(px,py);
	map[px][py]=' ';
	cout<<" ";
	px=px+1;
	gotoxy(px,py);
	cout<<"O";
	map[px][py]='O';
	}
	if(map[py][px+1]=='$'){
		system("cls");
		cout<<"Congratulations!!"<<endl;
		cout<<endl;
		cout<<"You won!!!"<<endl;
		cout<<endl;
		cout<<"Your score was: "<<score<<endl;
	}
}

void movemanDown(){
	if(map[py+1][px]=='^' || map[py+1][px]=='v' || map[py+1][px]=='|' || map[py+1][px]=='G' || map[py+1][px]==',' || map[py+1][px]=='A' || map[py+1][px]=='>' || map[py+1][px]=='<'){
		system("cls");
		gotoxy(40,4);
		cout<<"Game Over!"<<endl;
		cout<<endl;
		cout<<"The score was: ";
		cout<<score<<endl;
		gameRunning=false;
		getch();
		}
  	if(map[py+1][px] ==' ' || map[py+1][px] =='.' ){
		if(map[py+1][px]=='.'){
			score++;
		}  		
  gotoxy(px,py);
  cout<<" ";
  map[px][py]=' ';
  cout<<" ";
  py=py+1;
  gotoxy(px,py);
  map[px][py]='O';
  cout<<"O";
	}  
}

void movemanUp(){
	if(map[py-1][px]=='^' || map[py-1][px]=='v' || map[py-1][px]=='|' || map[py-1][px]=='G' || map[py-1][px]==',' || map[py-1][px]=='A' || map[py-1][px]=='>' || map[py-1][px]=='<'){
		system("cls");
		gotoxy(40,4);
		cout<<"Game Over!"<<endl;
		cout<<endl;
		cout<<"The score was: ";
		cout<<score<<endl;
		gameRunning=false;
		getch();
		}
  if(map[py-1][px] ==' ' || map[py-1][px] =='.' ){
		if(map[py-1][px]=='.'){
			score++;
		}  
	gotoxy(px,py);	
	map[px][py]=' ';
	cout<<" ";
	py=py-1;
	gotoxy(px,py);
	map[px][py]='O';
	cout<<"O";	
	}		
}

void moveGhost(){
  gotoxy(gx,gy);
  cout<<" ";
  map[gx][gy]=' ';
  if(px>gx){
  	if(map[gy][gx+1]!='%' && map[gy][gx+1]!='>' && map[gy][gx+1]!='<' && map[gy][gx+1]!='|'){
	  
  	gotoxy(gx,gy);
	map[gx][gy]='.';
	cout<<".";
	gx++;
  		}
	}
  if(py>gy){
  	if(map[gy+1][gx]!='%' && map[gy+1][gx]!='<' && map[gy+1][gx]!='>' && map[gy+1][gx]!='|'){
  	gotoxy(gx,gy);
	map[gx][gy]='.';
	cout<<".";
	gy++;
  		}
	}
  
  if(px<gx){
  	if(map[gy][gx-1]!='%' && map[gy][gx-1]!='<' && map[gy][gx-1]!='>' && map[gy][gx-1]!='|'){
  	gotoxy(gx,gy);
	map[gx][gy]='.';
	cout<<".";
	gx--;
  		}
	}
	
  if(py<gy){
   	if(map[gy-1][gx]!='%' && map[gy-1][gx]!='<' && map[gy-1][gx]!='>' && map[gy-1][gx]!='|'){
  	gotoxy(gx,gy);
	map[gx][gy]='.';
	cout<<".";
	gy--;
  		}
	}	
	gotoxy(gx,gy);
	map[gx][gy]='G';
	cout<<"G"<<endl;
	if(px==gx && py==gy){
		system("cls");
		gotoxy(40,4);
		cout<<"Game Over!"<<endl;
		cout<<endl;
		cout<<"The score was: ";
		cout<<score<<endl;
		gameRunning=false;
		getch();
	}
}

void shooter1(){
	Sleep(90);
	gotoxy(b1x,b1y);
	map[b1x][b1y]=' ';
	cout<<" ";
	b1y--;
	gotoxy(b1x,b1y);
	map[b1x][b1y]=',';
	cout<<",";
	if(b1y==2){
		gotoxy(54,2);
		map[54][2]=' ';
		cout<<" "; 
		b1y=6; 
	}
	if(px==b1x && py==b1y){
		gameRunning=false;
	}		
}

void shooter2(){
	Sleep(90);
	gotoxy(b2x,b2y);
	map[b2x][b2y]=' ';
	cout<<" ";
	b2y--;
	gotoxy(b2x,b2y);
	map[b2x][b2y]=',';
	cout<<",";
	if(b2y==2){
		gotoxy(65,2);
		map[65][2]=' ';
		cout<<" "; 
		b2y=6; 
	}
	if(px==b2x && py==b2y){
		gameRunning=false;
	}			
}

void shooter3(){
	Sleep(90);
	gotoxy(b3x,b3y);
	map[b3x][b3y]=' ';
	cout<<" ";
	b3y--;
	gotoxy(b3x,b3y);
	map[b3x][b3y]=',';
	cout<<",";
	if(b3y==2){
		gotoxy(75,2);
		map[75][2]=' ';
		cout<<" "; 
		b3y=6; 
	}
	if(px==b3x && py==b3y){
		gameRunning=false;
	}			
}
