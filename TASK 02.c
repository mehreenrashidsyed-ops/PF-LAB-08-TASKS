#include<stdio.h>
int IsPrime(int n)
{
    if(n<2)
    {
        return 0;
    }
    else {
    for(int i=2;i*i<=n;i++)
    {
     if(n%i==0)
     {
        return 0;
     }
    }
    return 1;
}

}
void PrintPrimes(int start,int end)
{ 
    printf("Primes:");
    for(int n=start;n<=end;n++)
    {
        if(IsPrime(n))
        {
            printf(" %d",n);
        }
    }
    printf("\n");
}
void CountPrimes(int start,int end)
{
    int count=0;
  
    for(int n=start;n<=end;n++)
    {
        if(IsPrime(n))
        {
            count++;
        }
    }
    printf("Total Primes Found:%d",count);
}
int main()
{
    int start,end;
    printf("Enter Range:");
    scanf("%d %d",&start,&end);
    if(start>end)
    {
        printf("Invalid Range\n");
    
    }
    else{
    PrintPrimes(start,end);
    CountPrimes(start,end);
    }
    return 0;
}