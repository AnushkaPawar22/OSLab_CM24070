#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define N 5

HANDLE chopstick[N];

DWORD WINAPI philosopher(LPVOID num) {
    int id = *(int*)num;

    while(1) {
        printf("Philosopher %d is Thinking\n", id);
        Sleep(1000);

        WaitForSingleObject(chopstick[id], INFINITE);
        WaitForSingleObject(chopstick[(id + 1) % N], INFINITE);

        printf("Philosopher %d is Eating\n", id);
        Sleep(2000);

        ReleaseMutex(chopstick[id]);
        ReleaseMutex(chopstick[(id + 1) % N]);

        printf("Philosopher %d Finished Eating\n", id);
    }
}

int main() {
    HANDLE thread[N];
    int phil[N];

    for(int i = 0; i < N; i++)
        chopstick[i] = CreateMutex(NULL, FALSE, NULL);

    for(int i = 0; i < N; i++) {
        phil[i] = i;
        thread[i] = CreateThread(NULL, 0, philosopher, &phil[i], 0, NULL);
    }

    WaitForMultipleObjects(N, thread, TRUE, INFINITE);

    return 0;
}