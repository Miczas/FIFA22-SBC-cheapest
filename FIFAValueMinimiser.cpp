#include <iostream>

using namespace std;
float teamVal(unsigned char* players);
void findBestTeamConf(float goalVal);
unsigned int getCost(unsigned char* p);
void saveTeam(unsigned char* target, unsigned char* team);

#define FIXED0 0
#define FIXED1 0
#define FIXED2 0
#define FIXED3 0
#define FIXED4 0
#define FIXED5 0
#define FIXED6 0
#define FIXED7 0
#define FIXED8 0
#define FIXED9 0
#define FIXED10 0

#define STARTING 80
#define FINISHING 98
#define GOAL 86

unsigned int prices[100] = {};

int main(void)
{
	prices[81] = 750;
	prices[82] = 1000;
	prices[83] = 1200;
	prices[84] = 2200;
	prices[85] = 3600;
	prices[86] = 4500;
	prices[87] = 6000;
	prices[88] = 7400;
	prices[89] = 11000;
	prices[90] = 11250;
	prices[91] = 11500;
	prices[92] = 12000;
	prices[93] = 12000;
	prices[94] = 13000;
	prices[95] = 15000;
	prices[96] = 17000;
	prices[97] = 31000;
	prices[98] = 94000;
	prices[99] = 1000000;
	//unsigned char players[11] = { 86, 87, 87, 87, 88, 88, 88, 88, 88, 88, 89 };
	//cout << "val of the team is " << teamVal(players) << endl;
	//cout << "cost is " << getCost(players) << endl;
	//for (int i = GOAL; i < 88; i++)
	//{
	//	findBestTeamConf(i);
	//}
	findBestTeamConf(GOAL);
	

	
	system("pause");
}

void findBestTeamConf(float goalVal)
{
	unsigned char players[11] = {};
	unsigned int totalCost = UINT32_MAX;
	unsigned char bestTeam[11] = {};

	for (int a = STARTING; a < FINISHING; a++)
	{
		players[0] = FIXED0 == 0 ? a : FIXED0;
		for (int b = a; b < FINISHING; b++)
		{
			
			players[1] = FIXED1 == 0 ? b : FIXED1;
			for (int c = b; c < FINISHING; c++)
			{
				
				players[2] = FIXED2 == 0 ? c : FIXED2;
				for (int d = c; d < FINISHING; d++)
				{
					players[3] = FIXED3 == 0 ? d : FIXED3;
					for (int e = d; e < FINISHING; e++)
					{
						players[4] = FIXED4 == 0 ? e : FIXED4;
						for (int f = e; f < FINISHING; f++)
						{							
							players[5] = FIXED5 == 0 ? f : FIXED5;
							for (int g = f; g < FINISHING; g++)
							{
								players[6] = FIXED6 == 0 ? g : FIXED6;
								for (int h = g; h < FINISHING; h++)
								{
									players[7] = FIXED7 == 0 ? h : FIXED7;
									
									for (int i = h; i < FINISHING; i++)
									{
										players[8] = FIXED8 == 0 ? i : FIXED8;
										for (int j = i; j < FINISHING; j++)
										{
											players[9] = FIXED9 == 0 ? j : FIXED9;
											for (int k = j; k < FINISHING; k++)
											{
												players[10] = FIXED10 == 0 ? k : FIXED10;
												if (teamVal(players) >= goalVal)												
												{
													if (getCost(players) < totalCost)
													{
														totalCost = getCost(players);
														saveTeam(bestTeam, players);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "The cheapest team of value " << goalVal << " consists of following players: " << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << (int)bestTeam[i] << ", ";
	}
	cout << "val of the team is " << teamVal(bestTeam) ;
	cout << ". Cost is " << getCost(bestTeam) << endl << endl;
}

unsigned int getCost(unsigned char* p)
{
	return prices[p[0]] + prices[p[1]] + prices[p[2]] + prices[p[3]] + prices[p[4]] + prices[p[5]] + prices[p[6]] + prices[p[7]] + prices[p[8]] + prices[p[9]] + prices[p[10]];
}

void saveTeam(unsigned char* target, unsigned char* team)
{
	for (int i = 0; i < 11; i++)
		target[i] = team[i];
}

float teamVal(unsigned char* p)
{
	float cf = 0;
	unsigned short int sum = 0;
	float avg;
	for (int i = 0; i < 11; i++)
	{
		sum += p[i];
	}
	avg = sum / (float)11;
	for (int i = 0; i < 11; i++)
	{
		if (p[i]>avg)
		cf += p[i]-avg;
	}
	//cout << "avg is" << avg << endl;
	//cout << "cf is " << cf << endl;
	return floor((sum + cf) / 11);

}