// Card.h

#ifndef CARD_H
#define CARD_H

enum Suit
{
	Club,
	Diamond,
	Heart,
	Spade
};

const char* suit_to_str[] = { "Cl", "Di", "Ht", "Sp" };

const char* rank_to_str[] = { "[]", "A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K " };

class Card
{

public:
	Card(Suit, short, short);
	Card(const Card& other) = default;
	~Card() = default;

	inline const short getRank()
	{
		return rank;
	}

	inline const Suit getSuit()
	{
		return suit;
	}

private:
	Suit suit;
	short rank;
	short id;
};

#endif
