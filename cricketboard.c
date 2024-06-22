#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct batsman {
    char name[25];
    int ones, twos, threes, fours, sixes, balls;
    int runs;
    float str;
} pl1[100];

struct bowler {
    char name[25];
    int runsgv, wkttkn, overs;
    float econ;
} pl2[100];

int main() {
    int plno, choice;
    int i, n, m;
    struct batsman pl3 = { .runs = 0, .str = 0 };
    struct bowler pl4 = { .runsgv = 0, .wkttkn = 0, .overs = 0 };

    printf("Enter the Batsman detail:\n");
    printf("Enter the number of batsman:\n");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter name of batsman%d:\n", i + 1);
        scanf("%s", pl1[i].name);
        printf("Enter the number of ones scored by player%d:\n", i + 1);
        scanf("%d", &pl1[i].ones);
        printf("Enter the number of twos scored by player%d:\n", i + 1);
        scanf("%d", &pl1[i].twos);
        printf("Enter the number of threes scored by player%d:\n", i + 1);
        scanf("%d", &pl1[i].threes);
        printf("Enter the number of fours scored by player%d:\n", i + 1);
        scanf("%d", &pl1[i].fours);
        printf("Enter the number of sixes scored by player%d:\n", i + 1);
        scanf("%d", &pl1[i].sixes);
        printf("Enter the balls played by the player%d:\n", i + 1);
        scanf("%d", &pl1[i].balls);
    }

    printf("\nEnter the bowlers details:\n");
    printf("Enter the number of bowlers:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter name of bowler%d:\n", i + 1);
        scanf("%s", pl2[i].name);
        printf("Enter the runs given by the bowler%d:\n", i + 1);
        scanf("%d", &pl2[i].runsgv);
        printf("Enter the overs bowled by the bowler%d:\n", i + 1);
        scanf("%d", &pl2[i].overs);
        printf("Enter the wickets taken by the bowler%d:\n", i + 1);
        scanf("%d", &pl2[i].wkttkn);
    }

    printf("Thank you, all details are recorded\n");

    do {
        printf("Enter the choice:\n 1) Batsman detail\n 2) Bowlers detail\n 3) Match summary\n 4) Record\n 5) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the batsman number to see his details\n");
                scanf("%d", &plno);
                plno--;
                printf("                       Player Detail\n");
                printf("===========================================================================\n");
                printf(" Batsman        runs           balls        fours       sixes         sr   \n");
                printf("===========================================================================\n");
                pl1[plno].runs = (1 * pl1[plno].ones) + (2 * pl1[plno].twos) + (3 * pl1[plno].threes) + (4 * pl1[plno].fours) + (6 * pl1[plno].sixes);
                pl1[plno].str = (pl1[plno].runs * 100.0) / pl1[plno].balls;
                printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n\n", pl1[plno].name, pl1[plno].runs, pl1[plno].balls, pl1[plno].fours, pl1[plno].sixes, pl1[plno].str);
                break;

            case 2:
                printf("Enter the bowlers number to see his details\n");
                scanf("%d", &plno);
                plno--;
                printf("                         Player Detail\n");
                printf("=================================================================\n");
                printf(" Bowler        overs           runs        wicket       economy\n");
                printf("=================================================================\n");
                pl2[plno].econ = (float) pl2[plno].runsgv / pl2[plno].overs;
                printf(" %-15s %-14d %-13d %-11d %-11.2f\n\n", pl2[plno].name, pl2[plno].overs, pl2[plno].runsgv, pl2[plno].wkttkn, pl2[plno].econ);
                break;

            case 3:
                printf("                     Match summary\n");
                printf("==========================================================================\n");
                printf(" Batsman        runs           balls        fours       sixes         sr   \n");
                printf("==========================================================================\n");
                int total_runs = 0;
                for (i = 0; i < m; i++) {
                    pl1[i].runs = (1 * pl1[i].ones) + (2 * pl1[i].twos) + (3 * pl1[i].threes) + (4 * pl1[i].fours) + (6 * pl1[i].sixes);
                    total_runs += pl1[i].runs;
                    pl1[i].str = (pl1[i].runs * 100.0) / pl1[i].balls;
                    printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n", pl1[i].name, pl1[i].runs, pl1[i].balls, pl1[i].fours, pl1[i].sixes, pl1[i].str);
                }
                printf("TOTAL RUNS: %d\n\n", total_runs);
                printf("=================================================================\n");
                printf(" Bowler        overs           runs        wicket       economy\n");
                printf("=================================================================\n");
                for (i = 0; i < n; i++) {
                    pl2[i].econ = (float) pl2[i].runsgv / pl2[i].overs;
                    printf(" %-15s %-14d %-13d %-11d %-11.2f\n", pl2[i].name, pl2[i].overs, pl2[i].runsgv, pl2[i].wkttkn, pl2[i].econ);
                }
                break;

            case 4:
                pl3.runs = 0;
                pl4.wkttkn = 0;
                int max_run = 0, max_six = 0, max_four = 0, max_wickets = 0;
                for (i = 0; i < m; i++) {
                    pl1[i].runs = (1 * pl1[i].ones) + (2 * pl1[i].twos) + (3 * pl1[i].threes) + (4 * pl1[i].fours) + (6 * pl1[i].sixes);
                    if (max_run < pl1[i].runs) max_run = pl1[i].runs;
                    if (max_six < pl1[i].sixes) max_six = pl1[i].sixes;
                    if (max_four < pl1[i].fours) max_four = pl1[i].fours;
                }
                for (i = 0; i < n; i++) {
                    if (max_wickets < pl2[i].wkttkn) max_wickets = pl2[i].wkttkn;
                }
                printf("Highest runs scored by a batsman: %d\n", max_run);
                printf("Maximum fours scored by a batsman: %d\n", max_four);
                printf("Maximum sixes scored by a batsman: %d\n", max_six);
                printf("Maximum wickets taken by a bowler: %d\n", max_wickets);
                break;

            case 5:
                exit(0);

            default:
                printf("Enter the correct choice\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
