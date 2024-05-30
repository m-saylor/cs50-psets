#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the user's name and say hello
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}
