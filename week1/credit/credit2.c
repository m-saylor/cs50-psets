#include <cs50.h>
#include <stdio.h>

bool check_sum(long n, int digits);
int get_digits(long n);
int card_name(int n, int digits);

int main(void)
{
    // Prompt for card number input
    long n = get_long("Number: ");

    int digits = get_digits(n);

    // Use check sum algorithm to determine if invalid
    if (!check_sum(n, digits))
    {
        printf("INVALID\n");
    }

    else
    {
        switch(card_name(n, digits))
        {
            case 0:
                printf("INVALID\n");
                break;
            case 1:
                printf("AMEX\n");
                break;
            case 2:
                printf("MASTERCARD\n");
                break;
            case 3:
                printf("VISA\n");
                break;
        }
    }
}

// Calculate the digits in the card number
int get_digits(long n)
{
    int digits = 0;
    do
    {
        n /= 10;
        digits++;
    }
    while (n != 0);

    return digits;
}

bool check_sum(long n, int digits)
{
    int x;
    int xsum = 0;
    int y;
    int ysum = 0;

    do
    {
        // Get the last digit and remove it and sum
        x = n % 10;
        n = n - x;
        n = n / 10;
        xsum += x;

        // Get the second last digit, remove, double
        y = n % 10;
        n = n - y;
        n = n / 10;
        y *= 2;

        // Add the sum of digits of y to the ysum
        if (y > 9)
        {
            ysum += ((y - (y % 10)) / 10) + (y % 10);
        }
        else
        {
            ysum += y;
        }
    }
    while (x > 0);

    if ((xsum + ysum) % 10 == 0)
    {
        return true;
    }
    return false;
}

int card_name(n, digits)
{
    // Use card length and starting digits to determine card name
    int start;
    int mstart;
    int vstart;

    if (digits == 15)
    {
        start = n / 10000000000000;

        if (start == 34 || start == 37)
        {
            return 1;
        }
    }
    else if (digits == 16)
    {
        mstart = n / 100000000000000;
        vstart = n / 1000000000000000;

        if (mstart > 50 && mstart < 56)
        {
            return 2;
        }
        else if (vstart == 4)
        {
            return 3;
        }
    }
    else if (digits == 13)
    {
        start = n / 1000000000000;

            if (start == 4)
            {
                return 3;
            }
    }
    return 0;
}
