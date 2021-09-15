/**
* Programme qui permet de  trouver le nombre premier le plus proche suivant le nombre donne par un utilisateur.
* \file   nombrePremier.cpp
* \author Delisle et Malek
* \date   21 septembre 2021
* Créé le 11 septembre 2021
*/

#include <iostream> // permet d'afficher les resultats dans la console.
using namespace std;

void primeNumberFinder(int nb) // Cette fonction permet de trouver le nombre premier tout de suite apres le nombre donne.
{
	bool isPrime = false; // permet de determine si le nombre trouve est un nombre premier ou pas.
	while (!isPrime) // la boucle continue tant que "num" nest pas un nombre premier
	{
		if (nb == 3) // l'algorithm pour trouver si "num" est un nombre premier ne fonctionne pas avec 3, je le verifie donc directement.
		{
			isPrime = true;
		}
		else // Pour tous les autres cas nous utilisons l'algorithm.
		{
			for (int i = 2; i <= nb / 2; i++) // Ceci est l'algorithm trouve sur internet.
			{
				if (nb % i == 0)
				{
					nb++;
					break;
				}
				else if (i == nb / 2)
				{
					isPrime = true;
				}
			}
		}
		if (isPrime == true) // Une fois sorti de la boucle for, si "num" "isPrime", alors nous affichons le resultat dans la console.
		{
			cout << "Le prochain nombre premier est le " << nb << endl;
		}
	}
}

int main()
{
	int number = 0; // Ceci est le nombre que l'utilisateur entrera dans la console.
	do
	{
		cout << "Entrez un nombre: ";
		cin >> number;
		primeNumberFinder(number); // on appelle la fonction a chaque fois qu'un nombre est donne.
	} while (number != -1); // le programme continue tant et aussi longtemps que l'utilisateur donnes des nombres autres que -1. Si le input est -1, alors le programme s'arrete.
}
