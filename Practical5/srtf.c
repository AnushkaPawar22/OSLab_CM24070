#include <stdio.h>

int main() {

    int arrival[3] = {0, 2, 6};
    int burst[3] = {10, 20, 30};
    int completion[3] = {10, 30, 60};
    int waiting[3];
    int total_waiting = 0;
    int context_switch = 2;

    for(int i = 0; i < 3; i++) {
        waiting[i] = completion[i] - arrival[i] - burst[i];
        total_waiting += waiting[i];
    }

    float avg_waiting = total_waiting / 3.0;

    printf("Total Context Switches = %d\n", context_switch);
    printf("Average Waiting Time = %.2f ns\n", avg_waiting);

    return 0;
}