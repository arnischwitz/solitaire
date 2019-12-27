// Deck.cpp

Deck::Deck()
{
	numCards = 0;
	while (numCards < 52)
	{
		++numCards;
		newCard = Card(Club, numCards, numCards);
		deck.insert(numCards, );
	}
}