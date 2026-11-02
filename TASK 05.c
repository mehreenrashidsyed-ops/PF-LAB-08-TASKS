#include <stdio.h>

long factorial(int n)
{
    long result = 1;

    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int reverseNumber(int n)
{
    int reversed = 0;

    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n = n / 10;
    }

    return reversed;
}

int isPalindrome(int n)
{
    if (n == reverseNumber(n))
    {
        return 1;
    }
    return 0;
}

int sumOfDigits(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

void printFibonacci(int terms)
{
    int a = 0, b = 1, next;

    printf("Fibonacci series:");
    for (int i = 0; i < terms; i++)
    {
        printf(" %d", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main()
{
    int choice, n;

    do
    {
        printf("\n1. Factorial\n");
        printf("2. Reverse Number\n");
        printf("3. Check Palindrome\n");
        printf("4. Sum of Digits\n");
        printf("5. Fibonacci Series\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            break;
        }

        if (choice == 6)
        {
            printf("Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5)
        {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        if (choice == 5)
        {
            printf("Enter number of terms: ");
        }
        else
        {
            printf("Enter number: ");
        }
        scanf("%d", &n);

        if (n < 0)
        {
            printf("Please enter a non-negative number.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                if (n > 20)
                {
                    printf("Number too large (max 20 to avoid overflow).\n");
                }
                else
                {
                    printf("Factorial of %d is %ld\n", n, factorial(n));
                }
                break;

            case 2:
                printf("Reverse of %d is %d\n", n, reverseNumber(n));
                break;

            case 3:
                if (isPalindrome(n))
                {
                    printf("%d is a palindrome.\n", n);
                }
                else
                {
                    printf("%d is not a palindrome.\n", n);
                }
                break;

            case 4:
                printf("Sum of digits of %d is %d\n", n, sumOfDigits(n));
                break;

            case 5:
                printFibonacci(n);
                break;
        }
    } while (choice != 6);

    return 0;
}
