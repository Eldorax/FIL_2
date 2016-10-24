#ifndef __TOKENIZEDTEXT
#define __TOKENIZEDTEXT

#include <vector>
#include <iostream>
#include <map>

using namespace std;


typedef vector< map<vector<unsigned int> , unsigned int> > ngram_vec;

class TokenizedText
{
	private:
		vector<unsigned int> tokens;  //Texte tokénizé.
	public:
		TokenizedText(vector<unsigned int>);
		ngram_vec getTokenCount(unsigned int);  //retoune un tableau de n-gram (matrice de décomptage).
		void show();
		
};


#endif


