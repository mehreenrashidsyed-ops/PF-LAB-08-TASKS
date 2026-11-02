#include <stdio.h>

int validateWithdrawal(float balance, float amount)
{
    if (amount != (int)amount || (int)amount % 500 != 0)
    {
        return 0;               
    }
    if (amount > balance)
    {
        return -1;             
    }
    if (balance - amount < 1000)
    {
        return -2;              
    }
    return 1;                   
}

float withdraw(float balance, float amount)
{
    return balance - amount;
}

void showMessage(int code)
{
    switch (code)
    {
        case 1:
            printf("Withdrawal successful. ");
            break;
        case 0:
            printf("Error: Amount must be a multiple of 500.\n");
            break;
        case -1:
            printf("Error: Insufficient balance.\n");
            break;
        case -2:
            printf("Error: Minimum balance of Rs. 1000 must be maintained.\n");
            break;
    }
}

int main()
{
    float balance = 10000;
    float amount;
    int code;

    printf("Balance: %.0f\n", balance);

    while (1)
    {
        printf("Enter amount (0 to exit): ");
        if (scanf("%f", &amount) != 1)
        {
            printf("Invalid input.\n");
            break;
        }

        if (amount == 0)
        {
            break;
        }

        if (amount < 0)
        {
            printf("Error: Amount cannot be negative.\n");
            continue;
        }

        code = validateWithdrawal(balance, amount);
        showMessage(code);

        if (code == 1)
        {
            balance = withdraw(balance, amount);
            printf("New balance: %.2f\n", balance);
        }
    }

    return 0;
}