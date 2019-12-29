// Card.h

#ifndef CARD_H
#define CARD_H

enum class Suit
{
	Club,
	Diamond,
	Heart,
	Spade
};

class Card
{

public:
	Card() = default;
	Card(Suit, short, int);
	Card(const Card& other) = default;
	~Card() = default;

	inline const short getID()
	{
		return id;
	}

	inline const short getRank()
	{
		return rank;
	}

	inline const Suit getSuit()
	{
		return suit;
	}

	inline const char* getRankStr()
	{
		return rank_to_str[rank];
	}

	inline const char* getSuitStr()
	{
		return suit_to_str[int(suit)];
	}

public:
	const char* suit_to_str[4] = { "Cl", "Di", "Ht", "Sp" };
	const char* rank_to_str[15] = { "__", "A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K " };

private:
	Suit suit;
	short rank;
	unsigned int id;
};

#endif
