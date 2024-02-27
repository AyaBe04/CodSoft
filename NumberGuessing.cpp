#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	int Num = 0;
	int n=1;
	int GuessNum=rand()%100+1;//rand par defaut 0-99 avec le 1 1-100
	cout<<"Choisie un Numero entre 1 et 100";
do{
	cin>> Num;
	if(Num==GuessNum){
		cout<<"Bravo! Vous avez gagné";
		n=0;
	}
	else if(Num>GuessNum){
		cout<<"le numero que vous avez choisie est plus grand, choisissez un autre";
	}
	else if(Num<GuessNum){
		cout<<"le numero que vous avez choisie est plus petit, choisissez un autre";
	}
		
}while(n==1);
}
