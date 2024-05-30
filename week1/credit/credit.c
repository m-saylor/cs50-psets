#include <cs50.h>
#include <stdio.h>

bool check_sum(long n, int digits);
int get_digits(long n);

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
        int start;
        int mstart;
        int vstart;

        // Check for card length and starting digits
        // Check if American Express
        if (digits == 15)
        {
            start = n / 10000000000000;

            if (start == 34 || start == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Check if Mastercard or Visa
        else if (digits == 16)
        {
            mstart = n / 100000000000000;
            vstart = n / 1000000000000000;

            if (mstart > 50 && mstart < 56)
            {
                printf("MASTERCARD\n");
            }

            else if (vstart == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Check if Visa
        else if (digits == 13)
        {
            start = n / 1000000000000;

            if (start == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
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
    int digit1;
    int digit2;
    int x;
    int xsum = 0;
    int y;
    int ysum = 0;

    // Calculate the necessary iterations of check sum
    int limit = digits / 2;

    if (!(digits % 2 == 0))
    {
        limit += 1;
    }

    for (int i = 0; i < limit; i++)
    {
        // Get the last digit and remove it and sum
        x = n % 10;
        n = n - x;
        n = n / 10;
        xsum += x;

        // Get the second last digit and remove it
        y = n % 10;
        n = n - y;
        n = n / 10;

        // Double every other digit
        y *= 2;

        // Add the doubles to one of the sums
        if (y > 9)
        {
            // Sum the first and second digits
            digit2 = y % 10;
            digit1 = (y - digit2) / 10;
            ysum += digit1 + digit2;
        }
        else
        {
            ysum += y;
        }
    }

    if ((xsum + ysum) % 10 == 0)
    {
        return true;
    }

    return false;
}
