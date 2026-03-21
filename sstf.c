#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = 8;
    int visited[8] = {0};
    int head = 53;
    int total = 0;

    int i, j, index;
    
    printf("Sequence: %d", head);

    for(i = 0; i < n; i++) {
        int min = 9999;

        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);

                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total += min;
        head = req[index];

        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}