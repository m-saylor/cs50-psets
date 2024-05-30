#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Get a message from the user
    string msg = get_string("Message: ");
    int length = strlen(msg);

    // Convert message to ASCII values
    for (int i = 0; i < length; i++)
    {
        int decimal = msg[i];

        // Convert ASCII decimal to binary
        int j = 0;
        int rbinary[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

        while (j < BITS_IN_BYTE)
        {
            if (decimal % 2 != 0)
            {
                rbinary[j] = 1;
            }
            decimal /= 2;
            j++;
        }

        // Reverse the binary digit order
        while (j >= 0)
        {
            binary[i] = rbinary[j];
            print_bulb(binary[i]);
            j--;
        }

        // Print a newline
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
