#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_amt_owed(void);
int quarter_check(int change);
int dime_check(int count, int change);
int nickel_check(int count, int change);
int penny_check(int count, int change);

int main(void)
{
    float amount = get_amt_owed();
    int change = round(amount * 100);
    int coin_count = quarter_check(change);
    printf("%i\n", coin_count);
}

float get_amt_owed(void)
{
    float amt;
    do
    {
        amt = get_float("Amount Owed: ");
    }
    while (amt <= 0);
    return amt;
}

int quarter_check(int change)
{
    // initalize counter for total # of coins used
    int count = 0;

    // check if change needed is > 25 cents and subtracts needed change by .25 until it needed change is lower than .25 or done

    if (change > 24)
    {
        do
    {
        count++;
        change -= 25;
    }
    while (change > 24);
    }

    /*
      after looping over change for quarters check if change still needed, if so, run dime_check function
      and pass in current count of coins and current change level, otherwise return coin count
    */

    if (change > 0)
    {
        return dime_check(count, change);
    }

    return count;
}

int dime_check(int count, int change)
{
    // check if change needed is > 10 cents and subtracts needed change by .10 until it needed change is lower than .10 or no longer needed

    if (change > 9)
    {
        do
        {
            count++;
            change -= 10;
        }
        while (change > 9);
    }

    /*
      after looping over change for dime check if change still needed, if so, run nickel_check function
      and pass in current count of coins and current change level, otherwise return coin count
    */

    if (change > 0)
    {
        return nickel_check(count, change);
    }

    return count;
}

int nickel_check(int count, int change)
{
    // check if change needed is > 5 cents and subtracts needed change by .55 until it needed change is lower than .5


    if (change > 4)
    {
        do
        {
            count++;
            change -= 5;
        }
        while (change > 4);
    }

    /*
      after looping over change for nickel check if change still needed, if so, run penny_check function
      and pass in current count of coins and current change level, otherwise return coin count
    */

    if (change > 0)
    {
        return penny_check(count, change);
    }

    return count;
}

int penny_check(int count, int change)
{

    // check if change is still needed and loop over it reducing to 0 while adding pennies to the total coin count used

    if (change > 0)
    {
        for (int i = 0; i < change; i++)
        {
            if (change > 0)
            {
                count++;
                change--;
            }
        }
    }

    // return the total count of coins used to make change

    return count;
}
