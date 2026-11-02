#include<stdio.h>
float CalculateBill(int units)
{ 
      float bill;
    if(units<=100)
    {
        
        bill=units*10;
    }
    else if(units>=101 && units<=200)
    {
        
        bill=100*10+(units-100)*15;
    }
    else{
        
        bill=100*10+100*15+(units-200)*20;
    }
    return bill+150;
}
    void PrintBill(int units,float bill)
    {
        printf("Units consumed:%d",units);
        printf("\nTotal Bill:%f",bill);
    }
  

int main()
{
    int units;
    for(int i=1;i<=3;i++)
    { 
        printf("\nEnter Units:");
        scanf("%d",&units);
        

        float bill=CalculateBill(units);
        PrintBill(units,bill);
    }
}