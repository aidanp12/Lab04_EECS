#include <stdio.h>

void score_calculator(int score)
{
	int td2, td1, td, sft, fg;
	for (td2 = 0; td2 * 8 <= score; td2++)
	{
		int remainingScore_td2 = score - (td2 * 8);
		for (td1 = 0; td1  <= remainingScore_td2; td1++)
		
		{
			int remainingScore_td1 = remainingScore_td2 - (td1 * 7);
			for (td = 0; td * 6 <= remainingScore_td1; td++)
			{
				int remainingScore_td = remainingScore_td1 - (td * 6);
				for ( fg = 0; fg * 3 <= remainingScore_td; fg++)
				{
					int remainingScore_fg = remainingScore_td - (fg * 3);
					for (sft = 0; sft * 2 <= remainingScore_fg; sft++)
					{
						int remainingScoreFinal = remainingScore_fg - (sft * 2);
						if (remainingScoreFinal == 0)
						{
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, sft);
						}										
					}
				}
			}
		}
	}
}



int main()
{
	int score;
	printf("Enter 0 or 1 to STOP\n");
	while(1)
	{
		printf("Enter the NFL score: ");
		scanf("%d", &score);
		if (score == 0 || score == 1)
		{
			printf("Exiting program...\n");
			break;
		}
		else if (score < 0)
		{
			printf("Score must be greater than zero!\n");
		}
		else
		{
			score_calculator(score);
			printf("\n");
		}
	}
	return 0;
}

