#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_used_names(string used_names[], string name);
void swap_pairs(int a, int b);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
  // Loop over candidates
  for (int i = 0; i < candidate_count; i++)
  {
      // if submitted name is valid add index of candidate to ranks[rank]
      if (strcmp(candidates[i], name) == 0)
      {
          ranks[rank] = i;
          return true;
      }
  }
  return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // initalize string array to hold used candidate names
    string used_names[candidate_count];

    // Loop over ranks array
  for (int i = 0; i < candidate_count; i++)
  {
    // loop over candidates to match candidate[j] to ranks[i]
    for (int j = 0; j < candidate_count; j++)
    {
      if (candidates[rank[i]] == candidates[j])
      {
        preferences[ranks[i]][j] = 0;
      }
      if (candidates[ranks[i]] != candidates[j] && !check_used_names(used_names, candidates[j]))
      {
          preferences[ranks[i]][j]++;
      }
    }
    // add ranks[i] candidate to list of used names
    used_names[i] = candidates[ranks[i]];
  }
  return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // loop over preferences
    for (int i = 0, j = candidate_count - 1; i < j; i++)
    {
      // loop inner preferences to compare candidates
      for (int k = i + 1; k < candidate_count; k++)
      {
        if (preferences[i][j] > preferences[j][i])
        {
          pairs[i].winner = i;
          pairs[i].loser = j;
          pair_count++;
        }
        else
        {
          pairs[i].winner = j;
          pairs[i].loser = i;
          pair_count++;
        }
      }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // loop over pairs
    for (int i = 0, j = pair_count - 1; i < j; i++)
    {
      // initailize variables to hold win margin of pairs[i]
      int win1 = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
      // loop over pairs to sort in decreasing order of strength of victory
      for (int k = i + 1; k < pair_count; k++)
      {
        // initailize variables to hold win margin of pairs[j]
        int win2 = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

        // if win2 margin is bigger than win1 swap spots
        if (win2 > win1)
        {
          swap_pairs(i, j);
        }

      }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // loop over pairs[i] and set all edge cases in locked[i][j]
    for (int i = 0; i < pair_count; i++)
    {
      locked[pairs[i].winner][pairs[i].loser] = true;
    }

    // loop over pairs again and check if any edge cases made a cycle
    for (int j = 0; j < pair_count; j++)
    {
      if (locked[pairs[j].winner][pairs[j].loser] && locked[pairs[j].loser][pairs[j].winner])
      {
        locked[pairs[j].winner][pairs[j].loser] = false;
      }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

bool check_used_names(string used_names[], string name)
{
    // loop over used names
    for (int i = 0; i < candidate_count; i++)
    {
        if (used_names[i] == name)
            return true;
    }
    return false;
}

void swap_pairs(int a, int b)
{
  // initalize pair to hold the first pair
  pair temp = pairs[a];
  // set new pair in place
  pairs[a] = pairs[b];
  pairs[b] = temp;
  return;
}

bool is_edge_case(pair pair[])
{
  // loop over locked to check if submitted pair will create cycle
  for (int i = 0; i < candidate_count; i++)
  {
    for (int j = 0; j < candidate_count; j++)
    {
      if ()
    }
  }
}
