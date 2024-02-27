#include <iostream>
#include <string>
using namespace std;

int somme(int a, int b) {
    return a + b;
}

int division(int a, int b) {
    if (b == 0) {
        cout << "Erreur: division par zero" << endl;
        return 0;
    }
    return a / b;
}

int soustraction(int a, int b) {
    return a - b;
}

int multiplication(int a, int b) {
    return a * b;
}

int main() {
    int num1, num2;
    string operation;

    while (true) {
        cout << "Saisissez deux nombres: ";
        cin >> num1 >> num2;
        cout << "Saisissez l'operation (somme, division, soustraction, multiplication) ou 'quitter' pour sortir : ";
        cin >> operation;

        if (operation == "quitter") {
            break;
        }

        int resultat;

        if (operation == "somme") {
            resultat = somme(num1, num2);
        } else if (operation == "division") {
            resultat = division(num1, num2);
        } else if (operation == "soustraction") {
            resultat = soustraction(num1, num2);
        } else if (operation == "multiplication") {
            resultat = multiplication(num1, num2);
        } else {
            cout << "Operation non valide!" << endl;
            continue;
        }
        cout << "Le resultat est : " << resultat;
    }
}


