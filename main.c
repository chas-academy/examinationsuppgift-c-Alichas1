#include <stdio.h>
#include <ctype.h>

int main() {
    char names[5][11];
    int scores[5][13];
    double avg[5];

    for (int i = 0; i < 5; i++) {
        scanf("%10s", names[i]);
        for (int j = 0; j < 13; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        names[i][0] = toupper(names[i][0]);
        for (int j = 1; names[i][j] != '\0'; j++)
            names[i][j] = tolower(names[i][j]);
    }

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 13; j++)
            sum += scores[i][j];
        avg[i] = (double)sum / 13;
    }

    int best = 0;
    for (int i = 1; i < 5; i++)
        if (avg[i] > avg[best])
            best = i;
    printf("%s\n", names[best]);

    double group = 0;
    for (int i = 0; i < 5; i++)
        group += avg[i];
    group /= 5;

    for (int i = 0; i < 5; i++)
        if (avg[i] < group)
            printf("%s\n", names[i]);

    return 0;
}