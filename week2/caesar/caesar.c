#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isnumber(string x);

int main(int argc, string argv[])
{
    // Check for errors
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!isnumber(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // The key is the second CLI
    int key = atoi(argv[1]);

    // Get the message from the user
    string plaintext = get_string("plaintext:  ");

    // Create a string to store the ciphertext
    int length = strlen(plaintext);
    char ciphertext[length];
    printf("ciphertext: ");

    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int x = plaintext[i];

            // Preserve capitalization
            if (x > 64 && x < 91)
            {
                x -= 65;
                x = (x + key) % 26;
                x += 65;
                ciphertext[i] = (char) x;
            }
            else
            {
                x -= 97;
                x = (x + key) % 26;
                x += 97;
                ciphertext[i] = (char) x;
            }
        }
        else
        {
            char x = plaintext[i];
            ciphertext[i] = x;
        }

        // Print the ciphertext
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}

bool isnumber(string x)
{
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (!isdigit(x[i]))
        {
            return false;
        }
    }
    return true;
}
