#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define MAX 20

int a[1000];

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, n, ele, pid;
    char *str1[MAX];
    char str[5];

    printf("Enter size of Elements: ");
    scanf("%d", &n);

    printf("Enter %d Elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    pid = fork();
    if (pid < 0) {
        printf("Error while creating new process...!!!");
    } else if (pid > 0) {
        bubble_sort(a, n);
        printf("\nAfter sorting:\t");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        for (i = 0; i <= MAX; i++) {
            str1[i] = NULL;
        }
        for (i = 0; i < n; i++) {
            sprintf(str, "%d", a[i]);
            str1[i] = strdup(str);
        }
        execve("./Reverse", str1, NULL);
        printf("EXECVE not called...!!!");
    }
}

// #include<stdio.h> 
// #include<sys/types.h> 
// #include<unistd.h> 
// #include<stdlib.h> 
// #define MAX 20

// int a[MAX];
// int main(int argc,char*argv[]) 
// {
//     int i;
//     for(i=0;i<argc;i++)
//     {
//         a[i]=atoi(argv[i]);
//     }
//     printf("Reversed Array:");

//     for(int i=argc-1;i>=0;i--)
//     {
//         printf("%d ",a[i]);
//     } 
//     printf("\nEXECVE() called"); 
//     return 0;
// }
