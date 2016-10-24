#include <iostream>
#include <stdio.h>
#include <string>

#include "elementArbre.h"
#include "arbre.h"
#include "tokenizedText.h"
#include <map>

using namespace std;


vector<unsigned int> DenombreToken(vector<unsigned int>);

int main(int argc, char ** argv)
{
	//liste des séparateur à prendre en compte.
	unsigned int list_sep[12] = {44, 32, 10, 9, 91, 93, 46, 63, 33, 58, 59, 95};
	vector<unsigned int> sep(0);
	sep.assign(list_sep, list_sep + 12);

	Arbre arbre(argv[1]); //creation de l'arbre.

	//arbre.show();       //Pour afficher les mots construis dans l'arbre.
		
	//Calcule des token
	vector<unsigned int> token_list;
	token_list = arbre.tokenization(argv[2], sep);
	TokenizedText tokens(token_list);
	
	//Affichage de la tokenization
	//tokens.show();

	//dénombrement des tokens
	ngram_vec vec;
	vec = tokens.getTokenCount(2);

	typedef map<vector<unsigned int>, unsigned int>::const_iterator MapIterator;
	for (MapIterator iter = vec[1].begin(); iter != vec[1].end(); iter++)
	{
		cout << "Key : " << iter->first[0] << ' ' << iter->first[1] << " - Values: " << iter->second << endl;
	}

	return 0;
}





vector<unsigned int> DenombreToken(vector<unsigned int> token_list)
{

	unsigned int max = 0;
	for( unsigned int i = 0; i < token_list.size(); i++)
	{
		if( token_list[i] >= max )
			max = token_list[i];
	}

	vector<unsigned int> res(max);

	for( unsigned int i = 0; i < token_list.size(); i++ )
		res[token_list[i]]++;


	return res;
}












