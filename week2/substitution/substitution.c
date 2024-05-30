#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int length = 26;

bool isalphastr(string x);
bool unique_chars(string x);

int main(int argc, string argv[])
{
    // The key is the second CLI
    string key = argv[1];

    // Check for errors
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (!isalphastr(key))
    {
        printf("Key must be alphabetical.\n");
        return 1;
    }
    else if (!unique_chars(key))
    {
        printf("Each letter in the key must be unique.\n");
        return 1;
    }

    // Get the message from the user
    string plaintext = get_string("plaintext:  ");

    // Create a string to store the ciphertext
    char ciphertext[length];
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int x = plaintext[i];

            // Preserve capitalization
            if (x > 64 && x < 91)
            {
                x -= 65;
                ciphertext[i] = toupper(key[x]);
            }
            else if (x > 96 && x < 123)
            {
                x -= 97;
                ciphertext[i] = tolower(key[x]);
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
    return 0;
}

bool isalphastr(string x)
{
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (!isalpha(x[i]))
        {
            return false;
        }
    }
    return true;
}

bool unique_chars(string str)
{
    int n = strlen(str);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}
