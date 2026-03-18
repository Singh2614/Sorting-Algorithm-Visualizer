#include <ctime>
#include <cstdlib>
#include <cstring>

extern const int arrSize;
extern const int SCREEN_HEIGHT;
extern int arr[arrSize];
extern int Barr[arrSize];

void randomizeAndSaveArray() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < arrSize; i++)
        Barr[i] = rand() % SCREEN_HEIGHT;
}

void loadArr() {
    memcpy(arr, Barr, sizeof(int) * arrSize);
}
