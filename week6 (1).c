#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double readRevenue(void) {
    double v;
    int r;
    while ((r = scanf("%lf", &v)) != 1 || v < 0) {
        if (r == EOF) exit(0);
        printf("Enter a valid amount (0 or more): ");
        if (r != 1) while (getchar() != '\n');
    }
    return v;
}

int main(void) {
    srand((unsigned)time(NULL));

    /* 1D: weekly revenue */
    double revenue[7], total = 0;
    for (int i = 0; i < 7; i++) {
        printf("Revenue day %d: ", i + 1);
        revenue[i] = readRevenue();
        total += revenue[i];
    }
    printf("Total: %.2f\nAverage: %.2f\n", total, total / 7);

    /* 2D: one branch (1 = occupied, 0 = vacant) */
    int occupancy[5][10];
    for (int f = 0; f < 5; f++) {
        int occ = 0;
        for (int r = 0; r < 10; r++) {
            occupancy[f][r] = rand() % 2;
            occ += occupancy[f][r];
        }
        printf("Floor %d: Occupied %d, Vacant %d\n", f + 1, occ, 10 - occ);
    }

    /* 3D: 3 branches */
    int chain[3][5][10], count = 0;
    for (int b = 0; b < 3; b++)
        for (int f = 0; f < 5; f++)
            for (int r = 0; r < 10; r++) {
                chain[b][f][r] = rand() % 2;
                count += chain[b][f][r];
            }
    printf("Total occupied rooms (all branches): %d\n", count);
    return 0;
}
