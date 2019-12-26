// Deck.h

#ifndef DECK_H
#define DECK_H

#include <map>
#include "Card.h"

struct Deck
{
public:
	Deck() = default;
	Deck(const Deck& other) = default;
	~Deck() = default;

private:
	std::map<int, Card> deck;
};

#endif
