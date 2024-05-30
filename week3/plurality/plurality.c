#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void swap(candidate *x, candidate *y);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // increment votes and return true if the user-inputted name is a candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }

    // if the vote does not match a candidate name
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Determine winner
    for (int i = 1; i < candidate_count; i++)
    {
        // Implement partial selection sort to find highest votes
        if (candidates[i].votes > candidates[0].votes)
        {
            swap(&candidates[i], &candidates[0]);
        }
    }

    // The highest vote should be in the first position
    int winning_vote = candidates[0].votes;

    // Print winner
    printf("%s\n", candidates[0].name);

    // Determine and print ties
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes == winning_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

void swap(candidate *x, candidate *y)
{
    candidate temp = *x;
    *x = *y;
    *y = temp;
}
