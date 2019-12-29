// Deck.h

#ifndef DECK_H
#define DECK_H

#include <map>
#include "Card.h"

enum class DeckType
{
	Standard52,
	Double52,
};

struct Deck
{
public:
	Deck(DeckType type);
	Deck(const Deck& other) = default;
	~Deck() = default;

	void shuffle();

public:
	std::map<int, Card> deck;
};

#endif
