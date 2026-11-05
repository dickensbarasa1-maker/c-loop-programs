#include <stdio.h>
#include <stdlib.h>

/* read a non-negative number safely */
double readNum(void) {
    double v;
    int r;
    while ((r = scanf("%lf", &v)) != 1 || v < 0) {
        if (r == EOF) exit(0);
        printf("Enter a valid number (0 or more): ");
        if (r != 1) while (getchar() != '\n');
    }
    return v;
}

double calculateElectricBill(int units) {
    if (units <= 100) return units * 10.0;
    if (units <= 200) return 1000 + (units - 100) * 15.0;
    return 2500 + (units - 200) * 20.0;
}

double calculateFare(double km) {
    return km * 50;
}

double convertToCelsius(double f) {
    return (f - 32) * 5 / 9;
}

int main(void) {
    printf("Units: ");
    int units = (int)readNum();
    printf("Bill: KSh %.2f\n", calculateElectricBill(units));

    printf("Distance (km): ");
    double km = readNum();
    printf("Fare: KSh %.2f\n", calculateFare(km));

    printf("Fahrenheit: ");            /* can be negative, so read directly */
    double f;
    while (scanf("%lf", &f) != 1) {
        if (feof(stdin)) return 0;
        printf("Enter a valid number: ");
        while (getchar() != '\n');
    }
    printf("Celsius: %.2f\n", convertToCelsius(f));
    return 0;
}
