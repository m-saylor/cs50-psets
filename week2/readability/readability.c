#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool isendpunct(char c);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get the text from the user
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the average letters per 100 words
    float L = (float) letters / words * 100;

    // Calculat the average sentences per 100 words
    float S = (float) sentences / words * 100;

    // Calculate grade level using the Coleman-Liau index
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int g = round(grade);
        printf("Grade %i\n", g);
    }
}

// Check if a character is an ending punctuation
bool isendpunct(char c)
{
    if (c == '!' || c == '?' || c == '.')
    {
        return true;
    }
    return false;
}

// Count the letters in the text
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Count the words in the text
int count_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

// Count the sentences in the text
int count_sentences(string text)
{
    int sentences = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isendpunct(text[i]))
        {
            if (isspace(text[i + 1]))
            {
                sentences++;
            }
        }
    }
    return sentences;
}
