#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp_choice(void);
int player_choice(void);
int round_result(int c, int p);
void result_phrase(int c, int p);

int comp_choice(void)
{
	int min, max, choice;

	min = 1;
	max = 5;
	choice = rand() % (max + 1 - min) + min;

	return (choice);
}

int player_choice(void)
{
	int choice;
	char input[10];
	printf("Make your choice:\n1. Rock\n2. Paper\n3. Scissors\n4. Lizard\n5. Spock.\n\n");
	scanf("%s", input);

	if (strcmp(input, "1") == 0 || strcmp(input, "rock") == 0 || strcmp(input, "Rock") == 0)
		choice = 1;
	else if (strcmp(input, "2") == 0 || strcmp(input, "paper") == 0 || strcmp(input, "Paper") == 0)
		choice = 2;
	else if (strcmp(input, "3") == 0 || strcmp(input, "scissors") == 0 || strcmp(input, "Scissors") == 0)
		choice = 3;
	else if (strcmp(input, "4") == 0 || strcmp(input, "lizard") == 0 || strcmp(input, "Lizard") == 0)
		choice = 4;
	else if (strcmp(input, "5") == 0 || strcmp(input, "spock") == 0 || strcmp(input, "Spock") == 0)
		choice = 5;
	return (choice);
}

int round_result(int c, int p)
{
	char *choices[5] = {"Rock", "Paper", "Scisscors", "Lizard", "Spock"};

	printf("You chose: %s\nI chose: %s\n\n", choices[p - 1], choices[c - 1]);

	if (c == p)
	{
		printf("It's a draw. Go again.\n");
		return (1);
	}
	else if ((c == 1 && p == 4) || (c == 1 && p == 3) || (c == 2 && p == 1) ||
		 (c == 2 && p == 5) || (c == 3 && p == 2) || (c == 3 && p == 4) ||
		 (c == 4 && p == 5) || (c == 4 && p == 2) || (c == 5 && p == 3) ||
		 (c == 5 && p == 1))
	{
		result_phrase(c, p);
		printf("You Lose!\n");
		return(0);
	}
	else
	{
		result_phrase(c, p);
		printf("You Win!\n");
		return (0);
	}
}

void result_phrase(int c, int p)
{
	if ((c == 1 && p == 4) || (c == 4 && p == 1))
		printf("Rock Crushes Lizard!\n");
	else if ((c == 1 && p == 3) || (c == 3 && p == 1))
		printf("Rock Crushes Scissors\n");
	else if ((c == 2 && p == 1) || (c == 1 && p == 2))
		printf("Paper Covers Rock!\n");
	else if ((c == 2 && p == 5) || (c == 5 && p == 2))
		printf("Paper Disproves Spock!\n");
	else if ((c == 3 && p == 2) || (c == 2 && p == 3))
		printf("Scissors Cuts Paper!\n");
	else if ((c == 3 && p == 4) || (c == 4 && p == 3))
		printf("Scissors Decapitates Lizard\n");
	else if ((c == 4 && p == 5) || (c == 5 && p == 4))
		printf("Lizard Poisons Spock\n");
	else if ((c == 4 && p == 2) || (c == 2 && p == 4))
		printf("Lizard Eats Paper!\n");
	else if ((c == 5 && p == 3) || (c == 3 && p == 5))
		printf("Spock Smashes Scissors!\n");
	else if ((c == 5 && p == 1) || (c == 1 && p == 5))
		printf("Spock vaporizes Rock!\n");
}

int run_game(void)
{
	int player, comp, draw;
	char done[10];

	comp = comp_choice();
	player = player_choice();
	draw = round_result(comp, player);
	if (draw == 1)
		return(run_game());
	printf("\n\nAnother Game?(Enter yes or no)\n");
	scanf("%s", done);
	if (strcmp(done, "yes") == 0 || strcmp(done, "Yes") == 0)
	{
		return(run_game());
	}
	else if (strcmp(done, "no") == 0 || strcmp(done, "No") == 0)
	{
		return(0);
	}
		printf("You suck at directions. See Ya!\n");
		return (0);
	return (0);
}
int main(void)
{
	run_game();
	return (0);
}
