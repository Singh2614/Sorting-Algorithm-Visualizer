#include <iostream>
#include <SDL.h>
#include <string>
#include "visualizer.cpp"
#include "sorting_algorithms.cpp"
#include "array_utils.cpp"
using namespace std;

bool controls() {
    cout << "\nAvailable Controls:\n"
         << "0 - Randomize\n1 - Selection Sort\n2 - Insertion Sort\n3 - Bubble Sort\n"
         << "4 - Merge Sort\n5 - Quick Sort\n6 - Heap Sort\nq - Quit\n\n"
         << "PRESS ENTER TO START...";
    string s;
    getline(cin, s);
    return s != "-1";
}

void intro() {
    cout << "================ SORTING VISUALIZER ================\n"
         << "Press ENTER to show controls...";
    string s;
    getline(cin, s);
}

int main() {
    intro();
    while (1) {
        if (!controls()) break;

        if (!init()) {
            cout << "SDL init failed.\n";
            break;
        }

        randomizeAndSaveArray();
        loadArr();

        SDL_Event e;
        bool quit = false;

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) quit = true;
                else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                        case SDLK_q:
                            quit = true; 
                            break;

                        case SDLK_0:
                            randomizeAndSaveArray(); 
                            complete = false; 
                            loadArr(); break;

                        case SDLK_1: 
                            loadArr(); 
                            complete = false; 
                            cout << "\nStarting Selection Sort...\n";
                            selectionSort(); 

                            complete = true;
                            cout << "\nSelection Sort completed...\n";  
                            break;

                        case SDLK_2: 
                            loadArr(); 
                            complete = false; 
                            cout << "\nStarting Insertion Sort...\n";

                            insertionSort(); 

                            complete = true;
                            cout<< "\nInsertion Sort completed...\n";
                            break;

                        case SDLK_3:
                            loadArr(); 
                            complete = false;
                            cout << "\nStarting Bubble Sort...\n";

                            bubbleSort(); 
                            
                            complete = true; 
                            cout << "\nBubble Sort completed...\n";
                            break;

                        case SDLK_4: 
                            loadArr(); 
                            complete = false; 
                            cout << "\nStarting Merge Sort...\n";

                            mergeSort(arr, 0, arrSize - 1); 

                            complete = true; 
                            cout << "\nMerge Sort completed...\n";
                            break;

                        case SDLK_5: 
                            loadArr(); 
                            complete = false; 
                            cout << "\nStarting Quick Sort...\n";

                            quickSort(arr, 0, arrSize - 1); 

                            complete = true; 
                            cout << "\nQuick Sort completed...\n";
                            break;

                        case SDLK_6: 
                            loadArr(); 
                            complete = false; 
                            cout << "\nStarting Heap Sort...\n";

                            inplaceHeapSort(arr, arrSize); 

                            complete = true; 
                            cout << "\nHeap Sort completed...\n";
                            break;
                    }
                }
            }
            visualize();
        }

        close();
    }

    cout << "\nEXITING PROGRAM.\n";
    return 0;
}
