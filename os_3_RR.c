#include <stdio.h>

int main()
{
    int i, n, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    
    printf("Enter total no of processes: ");
    scanf("%d", &n);
    
    printf("Enter TQ: ");
    scanf("%d", &quant);
    
    y = n;
    
    for (i = 0; i < n; i++)
    {
        printf("\nEnter AT, BT for process[%d]:\n", i+1);
        printf("Enter AT: ");
        scanf("%d", &at[i]);
        
        printf("Enter BT: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    
    printf("Process No \t TAT \t WT\n");
    
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        
        if (temp[i] == 0 && count == 1)
        {
            y--;
            
            printf("Process No[%d] \t %d \t %d\n", i+1, sum - at[i], sum - at[i] - bt[i]);
            
            tat = tat + sum - at[i];
            wt = wt + sum - at[i] - bt[i];
            count = 0;
        }
        
        if (i == n-1)
            i = 0;
                
        else if (at[i+1] <= sum)
            i++;
                
        else i = 0;
    }
    
    avg_tat = tat * 1.0 / n;
    avg_wt = wt * 1.0 / n;
    
    printf("\nAvg TAT = %f", avg_tat);
    printf("\nAvg WT = %f", avg_wt);
}