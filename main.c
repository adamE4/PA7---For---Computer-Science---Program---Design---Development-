#include "Pa7.h"
/*

   Programmer: Adam El-Mobdy

   Class: CPTS 121

   Assigment: PA7

   Date: 4/26/23

   Description: This is where the program is going to start, and where the game gets played

*/
int main(void)
{
	
	int game = 0, times = 0, row = 0, col = 0, count = 0, choice = 0, num = 0, pick_card = 0;
	srand((unsigned)time(NULL)); /* seed random-number generator */

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };
	Card playerhand[6] = { 0 };
	Card computerhand[6] = { 0 };

	printf("\nWELOMCE****TO****POKER\n");
	printf("\nPlayers are dealt two private cards and share five community cards to make the best five-card hand possible.\n");
	printf("\n1.PLAY GAME\n");
	printf("\n2.EXIT\n");
	printf("\nENTER: ");
	scanf("%d", &game);
	if (game == 1)
	{
		while (count < 10)
		{
			shuffle(deck);
			deal(deck, face, suit, playerhand, computerhand);
			replace_dealer(computerhand);

			for (int i = 1; i <= 5; i++)
			{
				printf("\nCard #%d, %s of %s\n", i, face[playerhand[i].face], suit[playerhand[i].suit]);
			}
			do
			{
				printf("Would you like to replace any of your cards? [1] Yes [0] No\n");
				scanf("%d", &choice);
			} while (choice != 1 && choice != 0);

			if (choice == 1)
			{
				do
				{
					printf("How many cards would like to replace [MAX 3]");
					scanf("%d", &num);
				} while (num > 3 && num < 1);

				for (int i = 0; i < num; i++)
				{
					printf("\nWhich card would you like to replace\n",i + 1);
					scanf("%d", &pick_card);
					replace(playerhand, pick_card);
					printf("\nYOU UPDATED YOUR HAND\n");
					for (int i = 1; i <= 5; i++)
					{
						printf("CARD #%d) %s of %s\n", i, face[playerhand[i].face], suit[playerhand[i].suit]);
					}
				}
				int dealer = evhand(computerhand);
				int player = evhand(playerhand);
				if (player > dealer)
				{
					
					system("cls");
					printf("\nYour Hand\n");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[playerhand[i].face], suit[playerhand[i].suit]);
					}
					printf("\n");
					printf("ComPuters Hand");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[computerhand[i].face], suit[computerhand[i].suit]);
					}
					printf("YOU WIN");
				}
				else
				{
					system("cls");
					printf("\nYour Hand\n");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[playerhand[i].face], suit[playerhand[i].suit]);
					}
					printf("\n");
					printf("ComPuters Hand");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[computerhand[i].face], suit[computerhand[i].suit]);
					}
					printf("COMPUTER WINS");
				}
			}
			if (choice == 0)
			{
				int dealer = evhand(computerhand);
				int player = evhand(playerhand);

				if (player > dealer)
				{
					system("cls");
					printf("\nYour Hand\n");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[playerhand[i].face], suit[playerhand[i].suit]);
					}
					printf("\n");
					printf("ComPuters Hand");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[computerhand[i].face], suit[computerhand[i].suit]);
					}
					printf("\nYOU WIN\\n");

				}
				else
				{
					system("cls");
					printf("\nYour Hand\n");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[playerhand[i].face], suit[playerhand[i].suit]);
					}
					printf("\n");
					printf("ComPuters Hand");
					for (int i = 1; i <= 5; i++)
					{
						printf("\nCard #%d, %s of %s\n", i, face[computerhand[i].face], suit[computerhand[i].suit]);
					}


					printf("\nCOMPUTER WINS\n");
				}
			}
			count++;
			system("pause");
			system("cls");
		}

		

	}
	else
	{
		system("cls");
		printf("\nHave A Good One!\n");
	}

	

	return 0;
}
