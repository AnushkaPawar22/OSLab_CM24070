#include <stdio.h>

#define P 5   // Number of processes
#define R 4   // Number of resources

int main() {

    int i, j, k;
    
    int allocation[P][R] = {
        {0, 0, 1, 4},   // Google Drive
        {0, 6, 3, 2},   // Firefox
        {0, 0, 1, 2},   // Word
        {1, 0, 0, 0},   // Excel
        {1, 3, 5, 4}    // PowerPoint
    };

    int max[P][R] = {
        {0, 6, 5, 6},
        {0, 6, 5, 2},
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6}
    };

    int available[R] = {1, 6, 2, 0};

    int need[P][R];
    int finish[P] = {0};
    int safeSeq[P];
    int work[R];

    // Calculate Need = Max - Allocation
    for(i = 0; i < P; i++) {
        for(j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Copy available to work
    for(i = 0; i < R; i++)
        work[i] = available[i];

    int count = 0;

    while(count < P) {
        int found = 0;
        for(i = 0; i < P; i++) {
            if(finish[i] == 0) {

                int possible = 1;

                for(j = 0; j < R; j++) {
                    if(need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(k = 0; k < R; k++)
                        work[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("System is NOT in safe state.\n");
            return 0;
        }
    }

    printf("System is in SAFE state.\nSafe sequence is: ");

    for(i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);

    return 0;
}