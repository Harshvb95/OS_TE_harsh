#include <stdio.h>

int find_optimal(int pages[], int frames[], int start, int n) {
    for (int i = 0; i < start; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (frames[i] == pages[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return -1;
}

void optimal(int pages[], int n) {
    int page_faults = 0;
    int frame_size = 3; // Change this based on your requirements
    int frames[frame_size];

    for (int i = 0; i < frame_size; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int page_found = 0;

        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            int index = find_optimal(pages, frames, i + 1, n);
            if (index != -1)
                frames[index] = page;
            else
                frames[page_faults % frame_size] = page;
            page_faults++;
        }
    }

    printf("Page Faults: %d\n", page_faults);
}

int main() {
    int pages[] = {0, 1, 2, 0, 3, 4, 2, 3, 1, 4}; // Example pages
    int n = sizeof(pages) / sizeof(pages[0]);

    optimal(pages, n);

    return 0;
}