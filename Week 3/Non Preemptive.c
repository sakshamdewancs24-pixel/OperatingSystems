#include<stdio.h>

int main() {
    int n,i,j,bt[10],pr[10],wt[10],tat[10],temp;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Burst Time and Priority: ");
        scanf("%d%d",&bt[i],&pr[i]);
    }

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(pr[i]>pr[j]){
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
            }

    wt[0]=0;
    for(i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];

    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        printf("P%d WT=%d TAT=%d\n",i+1,wt[i],tat[i]);
    }

    return 0;
}
