#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void forLoop() {
    for (int i = 100; i >= 50; i--);
        printf("%d\n", i);
}

void atm() {
    double balance, amount;
    printf("Enter balance: ");
    scanf("%lf", &balance);
    while (balance > 0) {
        printf("Withdraw amount: ");
        scanf("%lf", &amount);
        balance -= amount;
        printf("Balance: %.2f\n", balance);
    }
}

void guessGame() {
    int secret = rand() % 20 + 1, guess = 0, attempts = 0;
    while (guess != secret) {
        printf("Guess (1-20): ");
        scanf("%d", &guess);
        attempts++;
        if (guess > secret) printf("Too high!\n");
        else if (guess < secret) printf("Too low!\n");
        else printf("Congratulations!\n");
    }
    printf("Attempts: %d\n", attempts);
}

void password() {
    char pw[50];
    do {
        printf("Enter password: ");
        scanf("%49s", pw);
    } while (strcmp(pw, "1234") != 0);
    printf("Access Granted\n");
}

int main() {
    int c;
    srand(time(NULL));
    printf("1.For 2.ATM 3.Guess 4.Password: ");
    scanf("%d", &c);
    if (c == 1) forLoop();
    else if (c == 2) atm();
    else if (c == 3) guessGame();
    else if (c == 4) password();
    return 0;
}
