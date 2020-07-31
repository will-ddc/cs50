#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_submitted_key(string s);
string get_ciphertext(string text, string key);
int get_index(string alphabet, char a);

int main(int argc, string argv[])
{
    // check to make sure only 1 argument is submitted when starting program, that argument will be used as the key in the cipher
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // check to make sure submitted key is exactly 26 characters long, only letters of the alphabet, and each letter once
    if (!check_submitted_key(argv[1]))
    {
        printf("Key must be exactly 26 characters, use only letters, use each letter once\n");
        return 1;
    }

    // get plaintext from user
    string plaintext = get_string("plaintext: ");

    // convert to ciphertext
    string ciphertext = get_ciphertext(plaintext, argv[1]);

    printf("ciphertext: %s\n", ciphertext);

}

bool check_submitted_key(string s)
{
    // get length of key
    int key_length = strlen(s);

    // check key length to make sure it is 26, if not return error
    if (key_length != 26)
    {
        return false;
    }

    // loop over key to makes sure it is all letters w/ no duplicates
    for (int i = 0, j = key_length; i < j; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (!isalpha(s[i]) || s[i] == s[k])
            {
                return false;
            }
        }
    }
    return true;
}

string get_ciphertext(string text, string key)
{
    // create string with alphabet in order
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // outer loop takes each letter of the plain text
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        // inner loop goes through the alphabet until it matches the letter of the outer loop plaintext letter
        for (int k = 0, l = strlen(alphabet); k < l; k++)
        {
            if (alphabet[k] == text[i] || toupper(alphabet[k]) == text[i])
            {
                // get the index of the alphabet letter corresponding to the matched letter
                int index = get_index(alphabet, alphabet[k]);

                // then we check if the text case and what the key case is to make sure the converted text case matches its submission
                if (isupper(text[i]) && islower(key[index]))
                {
                    text[i] = toupper(key[index]);
                }
                else if (islower(text[i]) && isupper(key[index]))
                {
                    text[i] = tolower(key[index]);
                }
                else
                {
                    text[i] = key[index];
                }
                // set k equal to the end of the loop to grab next letter from outer loop
                k = l;
            }
        }
    }
    // return the converted text
    return text;
}

int get_index(string alphabet, char a)
{
    int idx;

    // use strchr to find the remaing letters once it matches the argument letter
    string results = strchr(alphabet, a);

    // get the index of the letter by subtracting the strchr results from the entire submitted string
    idx = results - alphabet;

    // return the index
    return idx;
}
