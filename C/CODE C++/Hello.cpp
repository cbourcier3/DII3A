#include <iostream>
#include <string>
using namespace std;

int main()
{

    // Demande nom et nombre

    /*cout << "Quel est votre nom ?" << endl;
    string nomUtilisateur("Sans nom"); //On crée une case mémoire pour contenir une chaine de caractères
    getline(cin, nomUtilisateur); //On remplit cette case avec toutela ligne que l'utilisateur a écrit

    cout << "Combien vaut pi ?" << endl;
    double piUtilisateur(-1.); //On crée une case mémoire pour stockerun nombre réel
    cin >> piUtilisateur; //Et on remplit cette case avec ce qu'écritl'utilisateur
     
    cout << "Vous vous appelez " << nomUtilisateur << " et vous pensez que pivaut " << piUtilisateur << "." << endl;

    return 0;*/

    cout << "---------------------------------" << endl;
    cout << "--------CALCULATRICE C++---------" << endl;
    cout << "---------------------------------" << endl;

    int a,b,resultat;
    char signeOperation;
    cout << "Saisissez le signe de l'opération que vous voulez effectuer (x,+,-,%,/) :";
    cin >> signeOperation;
    cout << "Saisissez le premier nombre à inclure dans votre opération: ";
    cin >> a;
    cout << "Saisissez le deuxieme nombre à inclure dans votre opération: ";
    cin >> b;
    switch (signeOperation){
        case 'x':
            resultat = a * b;
            break;
        case '/':
            resultat = a / b;
            break;
        case '+':
            resultat = a + b;
            break;
        case '-':
            resultat = a - b;
            break;
        case '%':
            resultat = a % b;
            break;
    }
    cout << "Le résultat de l'opération est :" << resultat;


    return 0;
    

}