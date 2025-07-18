#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

// ----- CONFIGURATION -----

#define TEAM_SIZE 11
#define STARTING 80      // Lowest rating to consider
#define FINISHING 98     // Highest rating + 1
#define GOAL 86          // Target team value

// Fix players to specific ratings (0 = unfixed)
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

// Player prices by rating (index = rating)
unsigned int prices[100] = {};

// ----- FUNCTION DECLARATIONS -----

/**
 * @brief Computes the SBC-style value of a team of 11 players.
 * @param team Pointer to an array of 11 player ratings.
 * @return Adjusted average rating with correction factor.
 */
float teamVal(const unsigned char* team);

/**
 * @brief Calculates the total coin cost of a team.
 * @param team Pointer to an array of 11 player ratings.
 * @return Total cost in coins.
 */
unsigned int getCost(const unsigned char* team);

/**
 * @brief Saves a team configuration to a target buffer.
 * @param target Output array where the team will be saved.
 * @param team Source team to copy.
 */
void saveTeam(unsigned char* target, const unsigned char* team);

/**
 * @brief Finds and prints the cheapest team that meets the goal rating.
 * @param goalVal Minimum required SBC team value.
 */
void findBestTeamConf(float goalVal);

// ----- MAIN FUNCTION -----

int main()
{
    // Set prices for each player rating
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

    findBestTeamConf(GOAL);

    return 0;
}

// ----- FUNCTION DEFINITIONS -----

float teamVal(const unsigned char* team)
{
    float sum = 0, correction = 0;

    // Calculate average rating
    for (int i = 0; i < TEAM_SIZE; i++)
        sum += team[i];

    float avg = sum / TEAM_SIZE;

    // Add correction factor: sum of amounts above average
    for (int i = 0; i < TEAM_SIZE; i++) {
        if (team[i] > avg)
            correction += team[i] - avg;
    }

    return floor((sum + correction) / TEAM_SIZE);
}

unsigned int getCost(const unsigned char* team)
{
    unsigned int total = 0;
    for (int i = 0; i < TEAM_SIZE; i++)
        total += prices[team[i]];
    return total;
}

void saveTeam(unsigned char* target, const unsigned char* team)
{
    for (int i = 0; i < TEAM_SIZE; i++)
        target[i] = team[i];
}

void findBestTeamConf(float goalVal)
{
    unsigned char team[TEAM_SIZE] = {};
    unsigned char bestTeam[TEAM_SIZE] = {};
    unsigned int minCost = UINT_MAX;

    for (int a = STARTING; a < FINISHING; a++) {
        team[0] = FIXED0 ? FIXED0 : a;
        for (int b = a; b < FINISHING; b++) {
            team[1] = FIXED1 ? FIXED1 : b;
            for (int c = b; c < FINISHING; c++) {
                team[2] = FIXED2 ? FIXED2 : c;
                for (int d = c; d < FINISHING; d++) {
                    team[3] = FIXED3 ? FIXED3 : d;
                    for (int e = d; e < FINISHING; e++) {
                        team[4] = FIXED4 ? FIXED4 : e;
                        for (int f = e; f < FINISHING; f++) {
                            team[5] = FIXED5 ? FIXED5 : f;
                            for (int g = f; g < FINISHING; g++) {
                                team[6] = FIXED6 ? FIXED6 : g;
                                for (int h = g; h < FINISHING; h++) {
                                    team[7] = FIXED7 ? FIXED7 : h;
                                    for (int i = h; i < FINISHING; i++) {
                                        team[8] = FIXED8 ? FIXED8 : i;
                                        for (int j = i; j < FINISHING; j++) {
                                            team[9] = FIXED9 ? FIXED9 : j;
                                            for (int k = j; k < FINISHING; k++) {
                                                team[10] = FIXED10 ? FIXED10 : k;

                                                if (teamVal(team) >= goalVal) {
                                                    unsigned int cost = getCost(team);
                                                    if (cost < minCost) {
                                                        minCost = cost;
                                                        saveTeam(bestTeam, team);
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

    // Output the best configuration
    cout << "The cheapest team of value " << goalVal << " consists of the following players:\n";
    for (int i = 0; i < TEAM_SIZE; i++)
        cout << (int)bestTeam[i] << (i < TEAM_SIZE - 1 ? ", " : "\n");

    cout << "Team value: " << teamVal(bestTeam) << ", Total cost: " << getCost(bestTeam) << " coins" << endl;
}