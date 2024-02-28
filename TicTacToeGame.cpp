#include <iostream>
#include <string>
using namespace std;


	char espace[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int colverti;
	int colhori;
	char symbole='X';
	bool link=false;
	string player1="";
	string player2="";
	bool manipulation();
	
	
void Game(){
	cout<<"    |    |   \n";
	cout<<" "<<espace[0][0]<<"  |"<<espace[0][1]<<"   |"<<espace[0][2]<<"  \n";
	cout<<"____|____|____\n";
	cout<<"    |    |   \n";
	cout<<" "<<espace[1][0]<<"  |"<<espace[1][1]<<"   |"<<espace[1][2]<<"  \n";
	cout<<"____|____|____\n";
	cout<<"    |    |   \n";
	cout<<" "<<espace[2][0]<<"  |"<<espace[2][1]<<"   |"<<espace[2][2]<<"  \n";
	cout<<"    |    |   \n";	
}
void Cases(){
	int Case;
	 if (manipulation()) {
        cout << "Il n'y a plus d'espace disponible. Le jeu est terminé." << endl;
        return;
    }
	if(symbole=='X'){
		cout<<player1<<"Saisissez la case";
		cin>>Case;
	}
	if(symbole=='O'){
		cout<<player2<<"Saisissez la case";
		cin>>Case;
	}
	if(Case==1){
		colverti=0;
		colhori=0;
	}
	else if(Case==2){
		colverti=0;
		colhori=1;
	}
	else if(Case==3){
		colverti=0;
		colhori=2;
	}
	else if(Case==4){
		colverti=1;
		colhori=0;
	}
	else if(Case==5){
		colverti=1;
		colhori=1;
	}
	else if(Case==6){
		colverti=1;
		colhori=2;
	}
	if(Case==7){
		colverti=2;
		colhori=0;
	}
	else if(Case==8){
		colverti=2;
		colhori=1;
	}
	else if(Case==9){
		colverti=2;
		colhori=2;
	}
	else if(Case<1 || Case>9){
		cout<<"Saisissez une case valide";
		return;
	}
	if( symbole=='X' && espace[colverti][colhori]!='X' && espace[colverti][colhori]!='O'){
		espace[colverti][colhori]='X';
		symbole='O';
	}
	else if( symbole=='O' && espace[colverti][colhori]!='X' && espace[colverti][colhori]!='O'){
		espace[colverti][colhori]='O';
		symbole='X';
	}
	else{
		cout<<"Il reste plus d'espace";
		Cases();
	}

}

bool manipulation() {
    for (int i = 0; i < 3; i++) {
        if (espace[i][0] == espace[i][1] && espace[i][0] == espace[i][2] && (espace[i][0] == 'X' || espace[i][0] == 'O')) {
            return true; 
        }
        if (espace[0][i] == espace[1][i] && espace[0][i] == espace[2][i] && (espace[0][i] == 'X' || espace[0][i] == 'O')) {
            return true; 
        }
    }
    if ((espace[0][0] == espace[1][1] && espace[0][0] == espace[2][2] ||
         espace[0][2] == espace[1][1] && espace[0][2] == espace[2][0]) &&
        (espace[1][1] == 'X' || espace[1][1] == 'O')) {
        return true; 
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (espace[i][j] != 'X' && espace[i][j] != 'O') {
                return false; 
            }
        }
    }
    link = true;
    return true; 
}

int main(){
	cout<<"Saisissez le nom du premier joueur: ";
	getline(cin,player1);
	cout<<"Saisissez le nom du deuxieme joueur: ";
	getline(cin,player2);
	cout<<player1<<" Va jouer en premier X \n";
	cout<<player2<<" va jouer en deuxieme O \n";
	while(!manipulation()){
		Game();
		Cases();	
	}
	if (link == true) {
    cout << "C'est une egalite";
    return 0;
	}
	if (symbole == 'X') {
    	cout << player2 << " a gagne";
	} else if (symbole == 'O') {
    	cout << player1 << " a gagne";
	}
	
}

