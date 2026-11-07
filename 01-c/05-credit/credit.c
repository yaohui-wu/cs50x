#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool checksum(long card_number);
bool valid_card(long card_number, string network);
int len(long card_number);
string card_network(long card_number);

int main(void)
{
    // Get card number from user.
    long card_number = get_long("Number: ");
    // Validate card network and length
    string network = card_network(card_number);

    // Validate whether a card number is
    // American Express, MasterCard, Visa, or invalid.
    if (valid_card(card_number, network))
    {
        printf("%s\n", network);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool valid_card(long card_number, string network)
{
    return network[0] != 'I' && checksum(card_number);
}

int len(long card_number)
{
    int length = 0; // Card number length

    // Count the number of digits.
    while (card_number > 0)
    {
        card_number /= 10;
        length += 1;
    }

    return length;
}

bool checksum(long card_number)
{
    int sum = 0;

    // Luhn's Algorithm
    while (card_number > 0)
    {
        // Add first rightmost digit to sum.
        int digit = card_number % 10;
        sum += digit;
        card_number /= 10;

        // Double second rightmost digit.
        int doubled = card_number % 10 * 2;
        // Sum the individual digits.
        sum += doubled / 10 + doubled % 10;
        card_number /= 10;
    }

    // Valid card number if true.
    return sum % 10 == 0;
}

string card_network(long card_number)
{
    int length = len(card_number);

    // Get the first two digits from left of card number.
    while (card_number >= 100)
    {
        card_number /= 10;
    }

    int prefix = card_number;

    // American Express: 15-digit numbers with prefix 34 or 37
    // MasterCard: 16-digit numbers with prefix 51, 52, 53, 54, or 55
    // Visa: 13-digit or 16-digit numbers with prefix 4
    bool is_amex = (prefix == 34 || prefix == 37) && length == 15;
    bool is_mastercard = prefix >= 51 && prefix <= 55 && length == 16;
    bool is_visa = (prefix / 10 == 4) && (length == 13 || length == 16);

    if (is_amex)
    {
        return "AMEX";
    }
    else if (is_mastercard)
    {
        return "MASTERCARD";
    }
    else if (is_visa)
    {
        return "VISA";
    }

    return "INVALID";
}
