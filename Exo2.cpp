/*
Programme qui permet de deviner la valeur d`un nombre entier choisi aléatoirement entre 0 et 1000
\file: Exo2.cpp
\authors: Desisles et Malek
\date: 21 septembre 2021
\created: 13 september 2021
*/

#include <iostream>
using namespace std;
#include <string> // On inclu string pour la variable "texte" d'entre de la fonction lireValeur()

int lireValeur(string texte, float min, float max)// Fonction pour lire une valeur, demander, verifier que la valeur est valide et redemander tant qu'elle ne l'est pas (utilise float pour que INFINITY fonctionne).
{   
    int valeurChoisi;
    do {
        
        cout << texte; cin >> valeurChoisi;
    } while (valeurChoisi<min || valeurChoisi>max);
    
    return valeurChoisi;
}

void devinette() // Fonction permettant d'indique si le nombre entre par l'usager est plus petit, plus grand ou egal au nombre genere.
{
    
    int valeurADevine = rand() % 1001;// Genere un nombre aleatoire entre 0 et 1000
    int nombreDeTentatives = 0; // Cette valeur augmentera a chaque essaie de l'usager pour trouver le nombre aleatoire.
    bool correct = false;
    
    while (correct == false) // Cette boucle s'arretera seulement si le nombre entre est egal au nombre aleatoire genere.
    {
        int valeur = lireValeur("Entree un nombre: ", 0, 1000); // 'valeur' est le nombre entre par l'usager, il est maintenant verifie avec les conditions ici-bas.
        if (valeur == valeurADevine)
        {
            cout << "Bravo! Vous avez reussi en " << nombreDeTentatives << " tentatives!" << endl;
            correct = true;
        }
        else if (valeur < valeurADevine)
        {
            cout << "Trop bas!" << endl;
            nombreDeTentatives++;
        }
        else if (valeur > valeurADevine)
        {
            cout << "Trop haut!" << endl;
            nombreDeTentatives++;
        }

    }
}

int main()
{
    devinette(); // Appelle de la fonction.
}
