/**
* Programme qui permet de trouver le moment de la collision entre 2 trains.
* \file   Source.cpp
* \author Delisle et Malek
* \date   21 septembre 2021
* Créé le 9 septembre 2021
*/
using namespace std;
#include <string>
#include <cmath> // Permet d'utiliser "INFINITY"
#include <iostream>

int lireValeur(string texte, float min, float max) // Cette fonction repete une demande d'entre temps que l'entre ne se situe pas entre le max et min.
{
	int valeurChoisi = 0;
	do {

		cout << texte; cin >> valeurChoisi; 
	} while (valeurChoisi<min || valeurChoisi>max); // Repete la commande jusqu'a temps que l'entre soit entre les bornes.

	return valeurChoisi;
}

void collision() // Cette fonction determine quand la collision arrive, si elle arrive, et l'affiche dans la console.
{
	int tempsTotal = 0;
	int posInitTrain1 = 0;
	int posInitTrain2 = 0;
	int vitesseTrain1 = 0;
	int vitesseTrain2 = 0;
	int posFinTrain1 = 0;
	int posFinTrain2 = 0; 
	bool collision = false;

	tempsTotal = lireValeur("Entrez le temps total : ", 0, INFINITY);
	posInitTrain1 = lireValeur("Entrez la position initiale du premier train: ", -INFINITY, INFINITY); // Pour utiliser la fonction plus haut pour des entres sans borne, nous imposons des bornes infinies.
	vitesseTrain1 = lireValeur("Entrez la vitesse du premier train : ", -100, 100);
	posInitTrain2 = lireValeur("Entrez la position initiale du second train: ", -INFINITY, INFINITY);
	vitesseTrain2 = lireValeur("Entrez la vitesse du second train : ", -100, 100);


	for (int i = 1; i <= tempsTotal; i++) // On affiche un compte-rendu a chaque seconde.
	{
		cout << "apres " << i << " seconde(s): " << endl;
		posFinTrain1 = posInitTrain1 + (i * vitesseTrain1); // Equation permettant de connaitre l'emplacement des trains en connaissant la vitesse et le temps.
		posFinTrain2 = posInitTrain2 + (i * vitesseTrain2);

		cout << "Train 1 : " << posFinTrain1 << endl; // Donne la position a chaque seconde.
		cout << "Train 2 : " << posFinTrain2 << endl;

		if (posInitTrain1 > posInitTrain2 && posFinTrain1 <= posFinTrain2) // Determine si pendant la seconde les 2 trains se sont croise, donc percute.
		{
			cout << "Les 2 trains entrent en collisions durant la " << i << "e seconde." << endl;
			collision = true;
			break;
		}
		else if (posInitTrain1 < posInitTrain2 && posFinTrain1 >= posFinTrain2)
		{
			cout << "Les 2 trains entrent en collisions durant la " << i << "e seconde." << endl;
			collision = true;
			break;
		}
		else if (i == tempsTotal && !collision) // Si lon est a la derniere seconde et les 2 trains ne sont pas percute, alors on indique qu'ils ne sont pas entre en collision.
		{
			cout << "Les 2 trains ne rentreront pas en collision.";
		}
	}
}

int main() {
	collision(); // Appelle de la fonction.
}
