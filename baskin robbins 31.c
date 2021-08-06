#include<stdio.h>

main()
{
	int num,computer,player,i;
	int game=0;
	printf("배스킨라빈스 31게임에 오신것을 환영합니다!");
	while(game!=1)
	{
		printf("\n게임시작 = 1 게임설명 = 2 선택 : "); scanf("%d",&game); 
		if(game==2)
		{
			printf("\n배스킨라빈스 31 게임은 몇 명의 사람들이 1부터 시작하여 숫자를 1~3개씩 부르는 게임입니다. \n이 때 31을 부르는 사람이 지게 됩니다.");
		}
	}
	while(game==1)
	{
		num=0;
		int baskin = 31;
		for(i=0;i<2;i++)
		{
			num++;
			printf("\n컴퓨터 : %d! ",num);
		}
		baskin-=2; 
		while(1)
		{
			printf("\n\n몇개의 숫자를 부르시겠습니까? (1~3) "); scanf("%d",&player);
			baskin-=player;
			for(i=0;i<player;i++)
			{
				num++;
				if(baskin<=0)
				{
					printf("\n플레이어 : %d! ",num);
					break;
				}
				printf("\n플레이어 : %d! ",num);
			}
			if(baskin<=0)
			{
				printf("\n\n당신은 패배하였습니다!");
				break;
			}
			baskin-=4-player;
			for(i=0;i<4-player;i++)
			{
				num++;
				printf("\n컴퓨터 : %d! ",num);
			}
			if(baskin<=0)
			{
				printf("\n당신은 승리하였습니다!");
				break;
			}
		}
		printf("\n계속하기겠습니까?(예 = 1 아니요 = 2)"); scanf("%d",&game);
	}
	
}
