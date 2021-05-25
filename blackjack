#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void printcard(int* arr, int num1)
{
	int j;
	for (j = 0; j < num1; j++)
	{
		if (arr[j] == 1)
			printf(" A |");
		else if (arr[j] == 11)
			printf(" J |");
		else if (arr[j] == 12)
			printf(" Q |");
		else if (arr[j] == 13)
			printf(" K |");
		else
			printf(" %d |", arr[j]);
	}
}
int main()
{
	int player, dealer, card, playercount, dealercount, money, game=0, betting, stop, i, playerAcount, dealerAcount, check, random;
	srand(time(NULL));
	while (1) {
		money = 200;
		stop = 1;
		printf("\nWelcome to black jack!\n");
		while (game != 1) {
			printf("(게임시작 = 1 , 게임 설명 = 2) 선택 : ");
			scanf("%d", &game);
			if (game == 2) {
				printf("딜러와 플레이어 중 카드의 합이 21 또는 21에 가장 가까운 숫자를 가지는 쪽이 이기는 게임입니다.\n");
				printf("Ace는 1 또는 11로 계산합니다.\n");
				printf("King, Queen, Jack은 각각 10으로 계산합니다.\n");
				printf("그 외의 카드는 카드에 표시된 숫자로 계산합니다.\n");
				printf("카드 합이 21을 초과하면 베팅 금액을 잃게 됩니다.\n플레이어와 딜러의 각각의 카드 합이 같을 경우 서로 비기게 됩니다.\n");
				printf("추가 카드를 원할경우 Hit 원하지 않을경우 Stay를 하시면 됩니다.\n\n\n");
			}
		}

		while (game == 1) {
			int samecount[13] = { 0, }, playercard[12] = { 0, }, dealercard[12] = { 0, }, betting = 0;
			player = 0, dealer = 0;
			playerAcount = 0, dealerAcount = 0;
			dealercount = 0, playercount = 0;
			printf("\n가진 코인 : %d  ", money);
			check = 0;
			while (check == 0)
			{
				printf("얼마를 배팅하시겠습니까?  배팅 : ");
				scanf("%d", &betting);
				if (money - betting < 0)
					printf("배팅액이 너무 많습니다. 다시 배팅하세요.\n");
				else
					check = 1;
			}

			money -= betting;
			for (i = 0; i < 2; i++) {
				card = rand() % 13 + 1;
				samecount[card - 1]++;
				dealercard[dealercount] = card;
				dealercount++;
				if (card >= 10)
					dealer += 10;
				else
					dealer += card;
				if (card == 1)
					dealerAcount++;
			}


			for (i = 0; i < 2; i++) {
				card = rand() % 13 + 1;
				samecount[card - 1]++;
				playercard[playercount] = card;
				playercount++;
				if (card >= 10)
					player += 10;
				else
					player += card;
				if (card == 1)
					playerAcount++;
			}
			if (dealerAcount > 0)
			{
				if (dealer + 10 == 21)
					dealer += 10;
				else if (17 <= dealer + 10 || dealer + 10 < 21)
				{
					random = rand() % 3 + 1;
					if (random != 1)
					{
						dealer += 10;
					}
				}
			}
			printf("\n딜러카드 |");    printcard(dealercard, 1);
			printf("\n플레이어카드 |");    printcard(playercard, playercount);
			printf("\n플레이어 카드합 : %d", player);
			if (playerAcount > 0)
			{
				if (player + 10 <= 21)
					printf(" or %d", player + 10);
			}
			printf("\nHit or Stay(Hit = 1, stay = 2) 선택 : ");	scanf("%d", &stop);
			while (stop == 1)//플레이어 카드분배
			{
				check = 0;
				while (check == 0)
				{
					card = rand() % 13 + 1;
					if (samecount[card - 1] != 4)
						check = 1;
				}
				playercard[playercount] = card;
				playercount++;
				samecount[card - 1] += 1;
				if (card == 1)
					playerAcount++;
				if (card >= 10)
					player += 10;
				else
					player += card;
				printf("\n\n딜러카드 |");    printcard(dealercard, 1);
				printf("\n플레이어카드 |");    printcard(playercard, playercount);
				printf("\n플레이어 카드합 : %d", player);
				if (playerAcount > 0)
				{
					if (player + 10 <= 21)
						printf(" or %d", player + 10);
				}
				if (player > 21)
					stop = 2;
				else
				{
					printf("  Hit or Stay(Hit = 1, stay = 2) 선택 : ");	scanf("%d", &stop);
				}
			}
			if (playerAcount > 0)
			{
				if (player + 10 <= 21)
					player += 10;
			}
			while (dealer < 17)//딜러 카드분배
			{
				check = 0;
				while (check == 0)
				{
					card = rand() % 13 + 1;
					if (samecount[card - 1] != 4)
						check = 1;
				}
				if (card >= 10)
					dealer += 10;
				else
					dealer += card;
				dealercard[dealercount] = card;
				dealercount++;
				samecount[card - 1] += 1;
				if (dealerAcount > 0)
				{
					if (dealer + 10 == 21)
						dealer += 10;
					else if (17 <= dealer + 10 || dealer + 10 < 21)
					{
						random = rand() % 3 + 1;
						if (random != 1)
						{
							dealer += 10;
						}
					}
				}
			}
			if (player <= 21)
			{
				printf("\n딜러카드 |");    printcard(dealercard, dealercount);
				printf("\n플레이어카드 |");    printcard(playercard, playercount);
				printf("\n플레이어 카드합 : %d", player); printf("  딜러 카드합 : %d\n", dealer);
			}

			if (player > 21)
			{
				printf("\nYou Bust!!\n");
			}
			else if (dealer > 21)
			{
				printf("\nDealer Bust!!\n");
				money += 2 * betting;
			}
			else if (dealer > player)
			{
				printf("\nYou Lose!!\n");
			}
			else if (dealer == player)
			{
				printf("\nYou Draw!\n");
				money += betting;
			}
			else if (dealer < player)
			{
				printf("\nYou Win!!!!!\n");
				money += 2 * betting;
			}
			printf("계속 하시겠습니까?(예 = 1 , 아니요 = 2) 선택 : "); scanf("%d", &game);
			if (money == 0)
			{
				printf("남은코인이 없습니다ㅠㅠㅠㅠ 자동 퇴장됩니다...");
				_sleep(2000);
				game = 2;
			}
		}
		return 0;
	}
}
