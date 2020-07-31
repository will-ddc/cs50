#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_submitted_key(string s);
string convert_text(string s, int key);

int main(int argc, string argv[])
{

    // check to make sure only 1 argument is submitted when starting program, that argument will be used as the key in the cipher
    if (argc > 2 || argc <= 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check to make sure submitted key is a # that can be used in cipher
    if (!check_submitted_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert key to an integer to use in cipher
    int key = atoi(argv[1]);

    // prompt user for message to code in cipher using provided key
    string plain_text = get_string("plaintext: ");

    // use key to convert plaintext into ciphertext
    string cipher_text = convert_text(plain_text, key);

    // print the ciphertext out
    printf("ciphertext: %s\n", cipher_text);
    return 0;
}

bool check_submitted_key(string s)
{
    // loop over submitted key to make sure it is a number
    for (int i = 0, j = strlen(s); i < j; i++)
    {
       if (!isdigit(s[i]))
       {
           return false;
       }
    }
    return true;
}

string convert_text(string s, int key)
{
    // loop over string to get individual letters
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        // if letter is between A - Z shift the letter by key
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = (s[i] - 65 + key) % 26 + 65;
        }
        // if letter between a - z shift the letter by key
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = (s[i] - 97 + key) % 26 + 97;
        }
        else
        {
            s[i] = s[i];
        }
    }
    // return the text after applying the key to it
    return s;
}
