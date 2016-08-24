#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXIMUM 10000
struct user
{
char Name[30];
int Score;
};
int randomNumber();
void soldierWin(struct user arr[],int Soldier);
struct user arr[4];
void main()
{
int i,King,Lieutenant,Soldier,Thief,num=1,choice,finish=1,ThiefIs,k,m,n,exist,rbug;
char check[30];
char intChar[10];
srand(time(0));
/*Initial value of score is 0*/
for(i=0;i<4;i++)
arr[i].Score=0;
printf("\n[RULE] := Whoever scores 10000 points first will WIN\n");
for(i=0;i<4;i++)
{
printf("\nEnter the name of User %d\n",i+1);
gets(arr[i].Name);
strcpy(check,arr[i].Name);
/*Functional Testing 1 starts here*/
for(n=0;n<i;n++)
{
exist=strcmp(check,arr[n].Name);
if(exist==0)
break;
}
if(exist==0)
{
printf("\n[Usage] := This name exists\n");
i--;
continue;
}
/*Functional Testing 1 ends here*/
m = strlen(arr[i].Name);
/*Functional Testing 2 starts here*/
if(m==0)  
{
printf("\n[Usage] := You have not entered anything\n");
i--;
continue;
}
/*Functional Testing 2 ends here*/
}
while(1)
{
King=Lieutenant=Soldier=Thief=1000;
King = randomNumber(); //King
arr[King].Score = arr[King].Score + 1000;
if(arr[King].Score >= MAXIMUM)
{
printf("\n[KING := %s]",arr[King].Name);
printf("\tWho is my Lieutenant?\n");
sleep(2);
printf("\n(Since %s has secured 1000 points in this round",arr[King].Name);
printf(" He is the first to score 10000 points)");
printf("\n\n\t\t\t\t\t[WINNER := %s][FINAL SCORE : = %d]\n",arr[King].Name,arr[King].Score);
printf("\n__________________________________________________________");
printf("____________________________________________________________\n");
exit(1);
}

do{
Lieutenant = randomNumber(); //Lieutenant
}
while(Lieutenant==King);

do{                           //Soldier
Soldier= randomNumber();
}while(Soldier==King || Soldier==Lieutenant);
arr[Soldier].Score = arr[Soldier].Score+500;


do{                          //Thief
Thief=randomNumber();
}while(Thief==King || Thief==Lieutenant || Thief==Soldier);

/*Main Concept starts from here*/
printf("\n\nSlips are being SCATTERED......\n");
sleep(2);
printf("\n[KING := %s]",arr[King].Name);
printf("\tWho is my Lieutenant?\n");
sleep(3);
printf("\n[Lieutenant := %s]",arr[Lieutenant].Name);
printf("\tI am your Lieutenant.\n");
sleep(3);
printf("\n[KING := %s]",arr[King].Name);
printf("\tWe have caught two persons. ");
printf("Tell me, Who the thief is.\n");
sleep(2);
for(i=0;i<4;i++)
{
if(arr[i].Name != arr[King].Name && arr[i].Name !=arr[Lieutenant].Name)
{
printf("\n\t\t\t(Enter %d if %s is the thief)",num,arr[i].Name);
if(arr[i].Name==arr[Thief].Name)
ThiefIs=num;
num++;
}
}
printf("\n");
num=1;

printf("\n[Lieutenant := %s]",arr[Lieutenant].Name);
printf("\tI am thinking...\n");
printf("\n[Lieutenant := %s] := The Thief is....",arr[Lieutenant].Name);
do
{
fgets(intChar,10,stdin);
rbug = atoi(intChar);

if(rbug==1 || rbug==2)
{
break;
}
printf("\r[Lieutenant := %s] := The Thief is....",arr[Lieutenant].Name);
}while(rbug != 1 || rbug != 2);

if(rbug==1 || rbug==2)
choice = rbug;
intChar[0]='a';
rbug=-1;
if(choice==ThiefIs)
{
printf("\n");
sleep(2);
if(arr[Soldier].Score >= MAXIMUM)
soldierWin(arr,Soldier);

printf("Congratulations, you are right");
printf("\t\t%s is the thief",arr[Thief].Name);
printf("\n:=%s has scored 800 points",arr[Lieutenant].Name);
arr[Lieutenant].Score=arr[Lieutenant].Score+800;
if(arr[Lieutenant].Score >= MAXIMUM)
{
printf("\n");
sleep(2);
printf("\n\n\t\t\t\t\t[WINNER := %s][FINAL SCORE : = %d]\n",arr[Lieutenant].Name,arr[Lieutenant].Score);
printf("\n__________________________________________________________");
printf("____________________________________________________________\n");
exit(1);
}
arr[Thief].Score=arr[Thief].Score+0;
}
else
{
printf("\n");
sleep(2);
if(arr[Soldier].Score >= MAXIMUM)
soldierWin(arr,Soldier);

printf("Sorry, you are wrong");
printf("\t\t%s is the thief",arr[Thief].Name);
printf("\n:=%s has scored 0 points and 800 points have been given to %s",arr[Lieutenant].Name,arr[Thief].Name);
arr[Lieutenant].Score=arr[Lieutenant].Score+0;
arr[Thief].Score=arr[Thief].Score+800;
if(arr[Thief].Score >= MAXIMUM)
{
printf("\n");
sleep(2);
printf("\n\n\t\t\t\t\t[WINNER := %s][FINAL SCORE : = %d]\n",arr[Thief].Name,arr[Thief].Score);
printf("\n__________________________________________________________");
printf("____________________________________________________________\n");
exit(1);
}
}
printf("\n");
printf("\n[SCORE] :=");
for(i=0;i<4;i++)
printf("\t[%s := %d]\t",arr[i].Name,arr[i].Score);
printf("\n__________________________________________________________");
printf("____________________________________________________________");
printf("\n");
sleep(4);
printf("\n\nNow Concentrate......\n");
sleep(3);
}
}

void soldierWin(struct user arr[],int Soldier)
{
printf("[Soldier := %s]\tI am the Soldier",arr[Soldier].Name);
sleep(2);
printf("\n(Since %s has secured 500 points even before the Lieutenant guessed in this round.",arr[Soldier].Name);
printf("\nAnd it will not be altered whether Lieutenant guessed right or not.");
printf("\nHence he is the first to score 10000 points.)");
printf("\n\n\t\t\t\t\t[WINNER := %s][FINAL SCORE : = %d]\n",arr[Soldier].Name,arr[Soldier].Score);
printf("\n__________________________________________________________");
printf("____________________________________________________________\n");
exit(1);
}


int randomNumber()
{
int x;
x=(rand()%4);
return x;
}


