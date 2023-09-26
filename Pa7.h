/*

	Programmer: Adam El-Mobdy

	Class: CPTS 121

	Assigment: PA7

	Date: 4/26/23

	Description: This is the header for the game of poker

*/
#ifndef PA7_H
#define PA7_h
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int face;
	int suit;
}Card;
typedef struct
{
	Card cards[5];
}Hand;
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card player1hand[], Card player2hand[]);
int Pair(Card playerhand[]);
int pairs_of_2(Card playerhand[]);
int pairs_of_3(Card playerhand[]);
int four_of_a_kind(Card playerhand[]);
int flush(Card playerhand[]);
int fullhouse(Card playerhand[]);
int straight(Card playerhand[]);
int evhand(Card playerhand[]);
void replace(Card playerhand[], int num);
void replace_dealer(Card playerhand[]);


#endif
