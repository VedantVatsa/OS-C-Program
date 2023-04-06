//page replacement algortihms (FIFO, Optimal, LRU) as a menu driven program 
#include <stdio.h>
#include <stdlib.h>
int FIFO(int frames, int pages[], int n) 
{
    int pf = 0;
    int a[frames];
    int front=0, rear=-1;
    for (int i=0; i<n; i++) 
    {
        int page=pages[i];
        int found=0;
        for (int j=0; j<=rear; j++) 
        {
            if (a[j]==page) 
            {
                found=1;
                break;
            }
        }
        if (!found) 
        {
            if (rear == frames - 1) 
            {
                front++;
            }
            rear = (rear + 1)%frames;
            a[rear] = page;
            pf++;
        }
    }
    return pf;
}

int optimal(int frames, int pages[], int n) {
    int pf=0;
    int a[frames];
    int front = 0, rear = -1;
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j <= rear; j++) {
            if (a[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (rear == frames - 1) {
                int farthest_page = -1;
                int farthest_index = -1;
                for (int j=0; j<=rear; j++) {
                    int k;
                    for (k = i+1; k < n; k++) {
                        if (pages[k]==a[j]) {
                            if (k > farthest_index) {
                                farthest_page = j;
                                farthest_index = k;
                            }
                            break;
                        }
                    }
                    if (k == n) {
                        farthest_page = j;
                        break;
                    }
                }
                a[farthest_page] = page;
            } else {
                rear++;
                a[rear] = page;
            }
            pf++;
        }
    }
    return pf;
}

int lru(int frames, int pages[], int n) {
    int pf=0;
    int a[frames];
    int front = 0, rear = -1;
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j <= rear; j++) {
            if (a[j] == page) {
                found = 1;
                for (int k = j; k < rear; k++) {
                    a[k] = a[k+1];
                }
                a[rear] = page;
                break;
            }
        }
        if (!found) {
            if (rear == frames - 1) {
                front++;
            }
            rear = (rear + 1) % frames;
            for (int j = rear; j > front; j--) {
                a[j] = a[j-1];
            }
            a[front] = page;
            pf++;
        }
    }
    return pf;
}
int main() {
    int pages[] = {0,1,2,3,0,1,4,0,1,2,3,4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;
    while (1) 
    {
        printf("Choose a page replacement algorithm:\n");
        printf("1. FIFO\n");
        printf("2. Optimal\n");
        printf("3. LRU\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice==1) 
        {
            printf("\nPage Faults: %d\n",FIFO(frames, pages, n));
        } 
        else if (choice==2) 
        {
            printf("\nPage Faults: %d\n",optimal(frames, pages, n));
        } 
        else if (choice == 3) 
        {
            printf("\nPage Faults: %d\n",lru(frames, pages, n));
        } 
        else if (choice == 4) 
        {
            exit(0);
        } 
        else 
        {
            printf("\nInvalid choice, try again.\n");
        }
    }
    return 0;
}

