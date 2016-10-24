#include "tokenizedText.h"


TokenizedText::TokenizedText(vector<unsigned int> p_tokens)
{
	tokens = p_tokens;
}


ngram_vec TokenizedText::getTokenCount(unsigned int N)
{
	vector< map<vector<unsigned int> , unsigned int> > resultat(0);
	vector<unsigned int> clef(0);
	for( unsigned int i = 0; i < N; i++)
	{
		map<vector<unsigned int> , unsigned int> temp;
		resultat.push_back(temp);
		for( unsigned int j = 0; j < tokens.size(); j++)
		{
			clef.clear();
			for( unsigned int k = 0; k < i + 1; k++)
			{
				clef.push_back(tokens[j+k]);
			}
			resultat[i][clef]++;
		}
	}
	return resultat;
}

void TokenizedText::show()
{
	cout << tokens[0];
	for( unsigned int i = 1; i < tokens.size(); i++)
		cout << " " << tokens[i];
	cout << endl;
}

