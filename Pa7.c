#include "Pa7.h"
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This is the function that creates the deck

*/
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This is the function that deals the cards from the deck

*/
/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card player1hand[], Card player2hand[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int i = 1;
	int j = 1;

	/* deal each of the 52 cards */
	for (card = 1; card <= 10; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					if (card < 6)
					{
						player1hand[i].face = column;
						player1hand[i].suit = row;
						i++;

					}
					else
					{
						player2hand[j].face = column;
						player2hand[j].suit = row;
						j++;
					}
				}
				
				
			}
		}

	}
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function checks the hand of player or computer for a pair of cards

*/
int Pair(Card playerhand[])
{
	int has_pair = 0;
	int count = 0;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (playerhand[i].face == playerhand[j].face)
			{
				has_pair = 1;
			}
		}
	}
	return has_pair;
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function checks the hand of player or computer for a 2 pairs of cards

*/
int pairs_of_2(Card playerhand[])
{
	int pair = 0;
	int has_pair = 0;
	int count = 0;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (playerhand[i].face == playerhand[j].face)
			{
				has_pair++;
			}
		}
	}
	if (has_pair == 2)
	{
		pair = 2;
	}
	return pair;
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function checks the hand of player or computer for 3 of a kind 

*/
int pairs_of_3(Card playerhand[])
{
	int threes = 0;
	if (playerhand[0].face == playerhand[1].face && playerhand[2].face == playerhand[1].face)
	{
		threes = 3;
	}
	if (playerhand[2].face == playerhand[1].face && playerhand[2].face == playerhand[3].face) 
	{
		threes = 3;
	}
	if (playerhand[2].face == playerhand[3].face && playerhand[4].face == playerhand[3].face)
	{
		threes = 3;
	}
	return threes;
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function checks the hand of player or computer for four of a kind

*/
int four_of_a_kind(Card playerhand[])
{
	int four = 0;

	if (playerhand[0].face == playerhand[1].face && playerhand[1].face == playerhand[2].face && playerhand[2].face == playerhand[3].face)
	{
		four = 4;
	}
	if (playerhand[1].face == playerhand[2].face && playerhand[2].face == playerhand[3].face && playerhand[3].face == playerhand[4].face)
	{
		four = 4;
	}
	return four;
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function checks the hand of player or computer for a flush

*/
int flush(Card playerhand[])
{
	int flush = 0, count = 0;
	Card Suit = { 0 };
	Suit.suit = playerhand[0].suit;

	for (int i = 0; i < 6; i++)
	{
		if (Suit.suit == playerhand[i].suit)
		{
			count++;
		}
	}
	if (count == 5)
	{
		flush = 6;
	}
	return flush;
}

/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function checks the hand of player or computer for a fullhouse

*/
int fullhouse(Card playerhand[])
{
	int house = 0, total = 0, add1 = 0, add2 = 0;
	add1 = pairs_of_3(playerhand);
	add2 = pairs_of_2(playerhand);

	total = add1 + add2;
	if (total == 4)
	{
		house = 5;
	}
	return house;
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function checks the hand of player or computer for a straight

*/
int straight(Card playerhand[])
{
	int straight = 0;
	int count = 0;
	Card Suit = { 0 };
	Suit.face = playerhand[0].face;

	for (int i = 0; i < 6; i++)
	{
		if (Suit.face == (playerhand[i].face - 1))
		{
			count++;
			Suit.face++;
		}
	}
	if (count == 5)
	{
		straight = 7;
	}
	return straight;
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function evaulates the hand of the player and the computer
*/
int evhand(Card playerhand[])
{
	int all[7] = { 0 };
	int num = 0;

	all[0] = Pair(playerhand);
	all[1] = pairs_of_2(playerhand);
	all[2] = pairs_of_3(playerhand);
	all[3] = four_of_a_kind(playerhand);
	all[4] = flush(playerhand);
	all[5] = fullhouse(playerhand);
	all[6] = straight(playerhand);

	for (int i = 0; i < 8; i++)
	{
		if (all[0] < all[i])
		{
			all[0] = all[i];
		}
	}
	num = all[0];
	return num;
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function replaces card within the player

*/
void replace(Card playerhand[], int num)
{


	int x = rand() % 8 + 2;
	int y = rand() % 3 + 1;

	do
	{
		x = rand() % 8 + 2;
		y = rand() % 4 + 1;




	} while (x == playerhand[num].face && y == playerhand[num].suit);
	playerhand[num].face = x;
	playerhand[num].suit = y;

	
}
/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This function replaces the cards in the compuuters hand
*/
void replace_dealer(Card playerhand[])
{
	int min = playerhand[0].face;
	int num = 0;

	for (int i = 0; i < 6; i++)
	{
		if (min > playerhand[i].suit)
		{
			min = playerhand[i].face;
			num = 1;
		}
	}
	replace(playerhand, num);
}

