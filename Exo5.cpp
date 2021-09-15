/**
* Programme qui enregistre dans un tableau de struct une liste provenant d'un fichier texte et indique l'element de la liste qui est le plus cher.
* \file   Exo5.cpp
* \author Delisle et Malek
* \date   21 septembre 2021
* Créé le 10 septembre 2021
*/

#include <fstream> // permet d'utiliser getline().
#include <vector> // permet de creer notre vecteur "inventaire".
#include <string> // permet la creation de string comme le "input".
#include <iostream> // permet d'afficher le resultat dans la console.
using namespace std;

struct Produits // Creation de la structure.
{
	string nom, type;
	int quantite{};
	double prix{};
};

void articleLePlusCher(const Produits inventaire[], int nArticles)
{
	double prixMax = 0.0; // Prend le prix de l'aliment le plus cher. 
	string articlePlusCher; // Prend le nom de l'aliment le plus cher. 
	for (int i = 0; i < nArticles; i++) {
		if (inventaire[i].prix > prixMax) // Si le prix de l'aliment dans le tableau est plus eleve que prixMax, alors prixMax prend la valeur de cet aliment.
		{
			articlePlusCher = inventaire[i].nom; 
			prixMax = inventaire[i].prix;
		}
	}
	cout << articlePlusCher << "\t" << prixMax;
}

int main()
{
	ifstream file("inventaire.txt"); // Permet de relier le document a la source et de l'identifier plus facilement.

	Produits inventaire[10]; // Nous savons que le maximum d'article est de 10, donc le tableau doit atteindre le maximum.
	string input = "" // input est une ligne dans inventaire.txt.
	int produitN = 0; // Ceci permet de changer de section du tableau a chaque iteration.

	while(getline(file, input, '\t')) // La boucle arretera lorsque le curseur arrive a la fin du document.
	{
		inventaire[produitN].nom = input;

		getline(file, input, '\t'); // Lis la ligne du dernier tab jusqu'au prochain de tab.
		inventaire[produitN].type = input;

		getline(file, input, '\t');
		inventaire[produitN].quantite = stoi(input); // Enregistre le input dans le tableau sous la forme d'un int.

		getline(file, input, '\n'); // Lis la ligne du dernier tab jusqu'a la fin de ligne.
		inventaire[produitN].prix = stof(input); // Enregistre le input dans le tableau sous la forme d'un double.
		
		produitN++;
	}

	for (int i = 0; i < produitN; i++)
	{
		cout << inventaire[i].nom << "\t" << inventaire[i].type << "\t" << inventaire[i].prix << "\t" << inventaire[i].quantite << endl; // Affiche le tableau "inventaire".
	}
	articleLePlusCher(inventaire, produitN); // Grace a cette fonction on trouve l'article le plus cher.
