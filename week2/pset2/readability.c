#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
string convert_lowercase(string s);
int count_words(string s);
int count_sentences(string s);
float get_average_letters(int letter_count, int word_count);
float get_average_sentences(int sentence_count, int word_count);
int get_cli(float avg_letters, float avg_sentences);

int main(void)
{

    // prompt user for text input to analyze reading level
    string input = get_string("Input Text: ");

    // convert input string to all lowercase
    string input_lowercase = convert_lowercase(input);


    // get count of all letters in the text and print # out
    int letter_count = count_letters(input_lowercase);

    // get count of all words in the text and print # out
    int word_count = count_words(input_lowercase);

    // get count of all sentences in the text and print # out
    int sentence_count = count_sentences(input_lowercase);

    // get average # of letters per 100 words
    float avg_letters = get_average_letters(letter_count, word_count);

    // get average # of sentences per 100 words
    float avg_sentences = get_average_sentences(sentence_count, word_count);

    // calculate the Coleman–Liau index
    int cli = get_cli(avg_letters, avg_sentences);

    // print out Grade level based on CLI Index
    if (cli < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (cli > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", cli);
        return 0;
    }
}

int count_letters(string s)
{
    // initalized variable to hold count of all letters in the string
    int total_letter_count = 0;

    // loop over convereted string and count all letters between a-z
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            total_letter_count++;
        }
    }
    // return total count of all letters
    return total_letter_count;
}

string convert_lowercase(string s)
{

    // create new string that containes passed in string
    string converted = s;

    // loop over the string and lowercase any letter that is uppercase
    for (int i = 0, j = strlen(converted); i < j; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            converted[i] += 32;
        }
    }
    //return new string in all lowercase
    return converted;
}

int count_words(string s)
{
    // initalized variable to hold count of all words in the string
    int total_word_count = 1;

    // a WORD is any sequence of characters separated by a SPACE (so a hyphenated word like "sister-in-law" should be considered one WORD

    // loop over string and count all words
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        if (s[i] == 32)
        {
            total_word_count++;
        }
    }
    // return total count of all words
    return total_word_count;
}

int count_sentences(string s)
{
    // initalized variable to hold count of all words in the string
    int total_sentence_count = 0;

    // For this problem, we’ll ask you to ignore that subtlety: you should consider any sequence of characters that ends with a . or a ! or a ? to be a sentence

    // loop over string and count all sentences
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            total_sentence_count++;
        }
    }
    // return total count of all sentences
    return total_sentence_count;
}

float get_average_letters(int letter_count, int word_count)
{
    // convert letter and word count numbers to floats
    float ltr_cnt = (float) letter_count;
    float wrd_cnt = (float) word_count;

    // divide letter and word counts and multiply by 100 to get average and return that value
    return (ltr_cnt / wrd_cnt) * 100;
}

float get_average_sentences(int sentence_count, int word_count)
{
    // convert sentence and word count numbers to floats
    float sent_cnt = (float) sentence_count;
    float wrd_cnt = (float) word_count;

    // divide sentence and word counts and multiply by 100 to get averag and return that value
    return (sent_cnt / wrd_cnt) * 100;
}

int get_cli(float avg_letters, float avg_sentences)
{
    // calculate the CLI, formula = 0.0588 * L (average # of letters per 100 words) - 0.296 * S (average # of sentences per 100 words) - 15.8
    float index = (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8;

    // round CLI up to nearest number
    index = round(index);

    // convert to integer and return
    return (int) index;

}
