# Notes/Play Code From Edx CS50x course

## Week 0 -

## Week 1 -

Started Intro into C language and concepts of programming

Created a hello world app in c

### Problem Sets

1. Mario1 - basic
Let’s recreate that pyramid in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself is also be taller than it is wide.

       #
      ##
     ###
    ####
   #####
  ######
 #######
########

2. Mario2 - advanced
Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.

   #  #
  ##  ##
 ###  ###
####  ####

3. Cash - basic
Implementation Details

Implement, in a file called cash.c in a ~/pset1/cash directory, a program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.

    Use get_float to get the user’s input and printf to output your answer. Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
        We ask that you use get_float so that you can handle dollars and cents, albeit sans dollar sign. In other words, if some customer is owed $9.75 (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill), assume that your program’s input will be 9.75 and not $9.75 or 975. However, if some customer is owed $9 exactly, assume that your program’s input will be 9.00 or just 9 but, again, not $9 or 900. Of course, by nature of floating-point values, your program will likely work with inputs like 9.0 and 9.000 as well; you need not worry about checking whether the user’s input is “formatted” like money should be.
    You need not try to check whether a user’s input is too large to fit in a float. Using get_float alone will ensure that the user’s input is indeed a floating-point (or integral) value but not that it is non-negative.
    If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.
    So that we can automate some tests of your code, be sure that your program’s last line of output is only the minimum number of coins possible: an integer followed by \n.
    Beware the inherent imprecision of floating-point values. Recall floats.c from class, wherein, if x is 2, and y is 10, x / y is not precisely two tenths! And so, before making change, you’ll probably want to convert the user’s inputted dollars to cents (i.e., from a float to an int) to avoid tiny errors that might otherwise add up!

    Take care to round your cents to the nearest penny, as with round, which is declared in math.h. For instance, if dollars is a float with the user’s input (e.g., 0.20), then code like

    int cents = round(dollars * 100);

    will safely convert 0.20 (or even 0.200000002980232238769531250) to 20.

Your program should behave per the examples below.

$ ./cash
Change owed: 0.41
4

$ ./cash
Change owed: -0.41
Change owed: foo
Change owed: 0.41
4

4. Credit - advanced
Luhn’s Algorithm

So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

    Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    Add the sum to the sum of the digits that weren’t multiplied by 2.
    If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

    For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

    4003600000000014

    Okay, let’s multiply each of the underlined digits by 2:

    1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

    That gives us:

    2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

    Now let’s add those products’ digits (i.e., not the products themselves) together:

    2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

    Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

    13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

    Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.
In a file called credit.c in a ~/pset1/credit/ directory, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card). But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input. (Why?)

Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).

$ ./credit
Number: 4003600000000014
VISA

Now, get_long itself will reject hyphens (and more) anyway:

$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA

But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:

$ ./credit
Number: 6176292929
INVALID


## Week 2 -

## Week 3 - Algorithms
