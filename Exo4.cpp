/**
* Programme qui organise en ordre croissant 10 nombres entres par un utilisateur.
* \file   Exo4.cpp
* \author Delisle et Malek
* \date   21 septembre 2021
* Créé le 8 septembre 2021
*/

#include <iostream>
#include <vector> // va nous permette de creer le vecteur "nombres".
using namespace std;

int main()
{
	vector<int> nombres; // les nombres entres dans la console par l'usager seront instaure dans ce vecteur.
	int input = 0; // le input est les 10 chiffres entres dans la console par l'utilisateur. 
	int transit = 0; // Le "transit" nous permettera de faire les manipulations necessaires pour changer l'emplacement des nombres dans le vecteur.
	cout << "Entrez 10 nombres entiers: ";
	for (int i = 0; i < 10; i++) // Cette boucle permet de prendre en entre les 10 nombres, soit en les espacant ou en appuyant sur entre.
	{
		cin >> input;
		nombres.push_back(input);
	}
	for (int min = 0; min < 10; min++) 
	{
		for (int i = min; i < 10; i++) // Cette double boucle "for" permet de comparer par exemple la premiere valeur du vecteur avec tous les autres valeurs qui suivent, et ainsi de suite.
		{
			if (nombres[i] < nombres[min]) // permet de comparer les valeurs aux positions qui non pas encore ete modifie, pour y placer la plus petite valeur possible. (Nous ne comparons pas avec les valeurs se trouvant a des positions plus basse que la position "min")
			{
				transit = nombres[min]; // pusique nous voulons echanger l'emplacement des valeurs, nous utilisons le transit comme variable tampon pour ne pas perdre la valeur que nous voulons transferer.
				nombres[min] = nombres[i];
				nombres[i] = transit;
			}
		}
	}
	cout << "Voici le tableau trie: ";
	for (int i = 0; i < 10; i++) // Cette boucle permet d'afficher les nombres entres maintenant en ordre croissant.
	{
		cout << nombres[i] << " ";
	}
}
