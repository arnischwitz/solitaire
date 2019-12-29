#include <stdio.h>
#include <map>
#include <iterator>
#include "Deck.h"

#include <iostream>

int main()
{
	printf("\nWELCOME TO SOLITAIRE\n");

	Deck sDeck = Deck(DeckType::Standard52);
	
	int validator = 1;
	std::map<int, Card>::iterator iter = sDeck.deck.begin();
	std::map<int, Card>::iterator iterEnd = sDeck.deck.end();

	while (iter != iterEnd)
	{
		if (validator == iter->first)
		{
			++validator;
			++iter;
		}
		else
		{
			return 1;
		}
	}

	bool gameActive = true;

	while (gameActive == true)
	{
		sDeck.shuffle();

		iter = sDeck.deck.begin();
		iterEnd = sDeck.deck.end();

		while (iter != iterEnd)
		{
			printf("%s\t%s\n", iter->second.getRankStr(), iter->second.getSuitStr());
			++iter;
		}

		char x;
		std::cin >> x;

		gameActive = false;
	}

	return 0;
}