#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool validate_cc(long cc_num);
int cc_multiply_digits(long cc_num);
int mult_by_two(int a);
int cc_add_digits(int mult_total, long cc_num);
bool cc_confirm_digit(int a);
string cc_type(long cc_num);
int check_cc_num_length(long cc_num);

int main(void)
{
    long cc_num = get_long("Input CC #: ");

    int cc_length = check_cc_num_length(cc_num);

    if (cc_length == 13 || cc_length == 15 || cc_length == 16)
    {
        bool cc_check = validate_cc(cc_num);

        if (cc_check)
        {
            string name = cc_type(cc_num);
            printf("%s\n", name);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }


}

bool validate_cc(long cc_num)
{
    int step1 = cc_multiply_digits(cc_num);
    int step2 = cc_add_digits(step1, cc_num);
    bool step3 = cc_confirm_digit(step2);

    if (!step3)
    {
        return false;
    }

    return true;
}

int cc_multiply_digits(long cc_num)
{
    // inital number variable to store individual CC #'s'

    int num;
    int cc_mult_num;
    int cc_mult_total = 0;

    // loop over CC # pulling every other digit, starting with the number’s second-to-last digit to double and add together

    while (cc_num > 0)
    {
        // grabs every 2nd digit from right to left of CC #
        num = (cc_num % 100) / 10;

        // removes last two digits from right to left of CC #
        cc_num /= 100;

        // multiply pulled numbers by 2
        cc_mult_num = mult_by_two(num);

        // add doubled CC #'s together
        cc_mult_total += cc_mult_num;
    }
    // returns value of each digit doubled and added together for step 1 of Luhn’s algorithm
    return cc_mult_total;
}

int mult_by_two(int a)
{
    // multiplies number by 2
    int num = a * 2;
    // checks if number over 10 and if so breaks it up and adds it together
    if (num >= 10)
    {
        int total;
        int sum = 0;
        while (num > 0)
        {
            total = num % 10;
            sum += total;
            num /= 10;
        }
        return sum;
    }
    // if number is ok submits number
    else
    {
        return num;
    }
}

int cc_add_digits(int mult_total, long cc_num)
{
    int num;
    int cc_add_total = mult_total;

    while (cc_num > 0)
    {
        num = cc_num % 10;
        cc_num /= 100;
        cc_add_total += num;
    }
    return cc_add_total;
}

bool cc_confirm_digit(int a)
{
    if (a % 10 != 0)
    {
        return false;
    }

    return true;
}

string cc_type(long cc_num)
{
    long num = cc_num;
    string card_type;

    while (num > 100)
    {
        num /= 10;
    }

    if (num >= 40 && num <= 49)
    {
        num /= 10;
    }

    switch (num)
    {
        case 34:
        card_type = "AMEX";
        break;
        case 37:
        card_type = "AMEX";
        break;
        case 4:
        card_type = "VISA";
        break;
        case 51:
        card_type = "MASTERCARD";
        break;
        case 52:
        card_type = "MASTERCARD";
        break;
        case 53:
        card_type = "MASTERCARD";
        break;
        case 54:
        card_type = "MASTERCARD";
        break;
        case 55:
        card_type = "MASTERCARD";
        break;
        default:
        card_type = "INVALID";
    }

    return card_type;
}

int check_cc_num_length(long cc_num)
{
    int length = 0;

    while (cc_num > 0)
    {
        cc_num /= 10;
        length++;
    }
    return length;
}
