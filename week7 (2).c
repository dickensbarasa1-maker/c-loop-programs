#include <stdio.h>
#include <string.h>

struct Student {
    char  name[50];
    char  regNo[20];
    float marks;
};

void borrowedBooks(void) {
    char title[100];
    FILE *fp = fopen("borrowed_books.txt", "a");   /* append keeps old records */
    if (fp == NULL) {
        printf("Error: cannot open borrowed_books.txt\n");
        return;
    }
    printf("Enter book title: ");
    if (scanf(" %99[^\n]", title) != 1) {          /* leading space skips old newline */
        printf("No title entered.\n");
        fclose(fp);
        return;
    }
    fprintf(fp, "%s\n", title);
    fclose(fp);
    printf("Title stored successfully.\n");
}

void readResults(void) {
    struct Student s;
    FILE *fp = fopen("results.dat", "rb");
    if (fp == NULL) {
        printf("Error: results.dat not found.\n");
        return;
    }
    while (fread(&s, sizeof s, 1, fp) == 1)
        printf("%s - %.2f\n", s.name, s.marks);
    fclose(fp);
}

void salesTotal(void) {
    double amt, total = 0;
    FILE *fp = fopen("sales.txt", "r");
    if (fp == NULL) {
        printf("Error: sales.txt not found.\n");
        return;
    }
    while (fscanf(fp, "%lf", &amt) == 1)
        total += amt;
    fclose(fp);
    printf("Total sales: KSh %.2f\n", total);
}

int main(void) {
    int c;
    printf("1.Books 2.Results 3.Sales: ");
    if (scanf("%d", &c) != 1) {
        printf("Invalid choice.\n");
        return 1;
    }
    if (c == 1) borrowedBooks();
    else if (c == 2) readResults();
    else if (c == 3) salesTotal();
    else printf("Invalid choice.\n");
    return 0;
}
