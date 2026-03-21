#include <stdio.h>

int main() {
    int frames[3], pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12, i, j, k, pos;
    int faults = 0, hits = 0;

    // Initialize frames
    for(i = 0; i < 3; i++) {
        frames[i] = -1;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check hit
        for(j = 0; j < 3; j++) {
            if(frames[j] == pages[i]) {
                hits++;
                found = 1;
                break;
            }
        }

        if(found == 0) {
            faults++;

            int farthest = -1;
            pos = -1;

            for(j = 0; j < 3; j++) {
                int next_use = -1;

                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        next_use = k;
                        break;
                    }
                }

                // If page not used again
                if(next_use == -1) {
                    pos = j;
                    break;
                }

                // Choose farthest use
                if(next_use > farthest) {
                    farthest = next_use;
                    pos = j;
                }
            }

            frames[pos] = pages[i];
        }

        // Print frames
        printf("\nPage %d -> ", pages[i]);
        for(j = 0; j < 3; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);
    printf("\nTotal Page Hits = %d", hits);

    printf("\nHit Percentage = %.2f%%", (hits/(float)n)*100);
    printf("\nFault Percentage = %.2f%%\n", (faults/(float)n)*100);

    return 0;
}