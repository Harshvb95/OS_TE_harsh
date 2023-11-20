#include <stdio.h>

void lru(int pages[], int n) {
    int page_faults = 0;
    int frame_size = 3; // Change this based on your requirements
    int frames[frame_size];
    int counter[frame_size];

    for (int i = 0; i < frame_size; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int page_found = 0;

        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                page_found = 1;
                counter[j] = 0;
            } else {
                counter[j]++;
            }
        }

        if (!page_found) 
        {
            int index = 0;
            for (int j = 1; j < frame_size; j++) 
            {
                if (counter[j] > counter[index]) 
                {
                    index = j;
                }
            }
            frames[index] = page;
            counter[index] = 0;
            page_faults++;
        }
    }

    printf("Page Faults: %d\n", page_faults);
}

int main() {
    int pages[] = {0, 1, 2, 0, 3, 4, 2, 3, 1, 4}; // Example pages
    int n = sizeof(pages) / sizeof(pages[0]);

    lru(pages, n);

    return 0;
}