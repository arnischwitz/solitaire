// Deck.cpp

#include "Deck.h"
#include <algorithm>
#include <random>
#include "time.h"

Deck::Deck(DeckType type)
{
	short nSuit = 0;
	short nRank = 1;
	int key = 1;

	switch (type)
	{
	case DeckType::Standard52:
		while (nSuit < 4)
		{
			while (nRank <= 13)
			{
				deck.insert({ key, Card(Suit(nSuit), nRank, key) });
				++key;
				++nRank;
			}
			nRank = 1;
			++nSuit;
		}
		break;

	case DeckType::Double52:
		deck.insert({ key, Card(Suit(nSuit), nRank, key) });
		break;
	}
}

void Deck::shuffle()
{
	int indexArray[52] = {};
	int index;
	for (index = 0; index < 52; ++index)
	{
		indexArray[index] = index+1;
	}

	int j, temp;
	index = 51;
	srand(static_cast<unsigned int>(time(NULL)));
	for ( ; index > 0; --index)
	{
		//get swap index
		j = rand() % index;
		//swap p[i] with p[j]
		temp = indexArray[index];
		indexArray[index] = indexArray[j];
		indexArray[j] = temp;
	}

	Deck tmpDeck = Deck(DeckType::Standard52);

	std::map<int, Card>::iterator deckIter = deck.begin();
	std::map<int, Card>::iterator deckIterEnd = deck.end();

	index = 0;
	while (deckIter != deckIterEnd)
	{
		tmpDeck.deck.erase(indexArray[index]);
		tmpDeck.deck.insert({ indexArray[index], deckIter->second });
		++index;
		++deckIter;
	}

	deck = tmpDeck.deck;
}
