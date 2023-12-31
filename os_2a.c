#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubblesort(int arr[], int n)
{
    for (int i=0; i < n-1; i++)
    {
        for (int j=0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("\nSorted array by bubble sort in child process is: ");
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

void selectionsort(int arr[], int n)
{
    int min_idx;
    
    for (int i=0; i<n-1; i++)
    {
        min_idx = i;
        
        for (int j = i+1; j<n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        
        if (min_idx != i)
            {
                int temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
    }
    
    printf("\nSorted array by selection sort in parent process is: ");
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    pid_t pid;
    
    int n;
    
    printf("\nEnter total no. of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("\nEnter the array: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    pid = fork();
    
    if (pid == 0)
    {
        printf("\n*** CHILD PROCESS ***\n");
        printf("\nIt is child process with pid = %d and ppid = %d \n", getpid(), getppid());
        bubblesort(arr, n);
        printf("\n*** CHILD PROCESS TERMINATED ***\n");
    }
    
    else
    {
        wait(NULL);
        printf("\n\n\n\n*** PARENT PROCESS ***\n");
        printf("\nIt is parent process with pid = %d and ppid = %d \n", getpid(), getppid());
        selectionsort(arr, n);
        printf("\n*** PARENT PROCESS TERMINATED ***\n");
    }
    
}