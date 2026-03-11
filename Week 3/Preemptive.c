#include<stdio.h>

int main() {
    int n,i,time=0,done=0,bt[10],rt[10],pr[10],wt[10],tat[10],min,p;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Burst Time and Priority: ");
        scanf("%d%d",&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(done<n){
        min=9999;
        for(i=0;i<n;i++)
            if(rt[i]>0 && pr[i]<min){min=pr[i]; p=i;}

        rt[p]--; time++;

        if(rt[p]==0){
            done++;
            tat[p]=time;
            wt[p]=tat[p]-bt[p];
        }
    }

    for(i=0;i<n;i++)
        printf("P%d WT=%d TAT=%d\n",i+1,wt[i],tat[i]);

    return 0;
}
