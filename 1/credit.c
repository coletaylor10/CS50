#include <cs50.h>
#include <stdio.h>

//prototype functions
int calculate_check(long card_number);
int card_length(long card_number);
void card_properties(long card_number, int length, int checksum);



//main
int main(void)
{
    //getting input
    long card_number = get_long("Enter Card Number:");
    //checksum calculation, returns boolean
    bool checksum = calculate_check(card_number);
    //check card properties
    int length = card_length(card_number);
    card_properties(card_number,length,checksum);






}

//luhns algorithmn
int calculate_check(long card_number)
{
    long total = 0;
    for(int i = 0; i < 20; i++)
    {
        if(i % 2 == 0)
        {
            total += card_number % 10;
            card_number /= 10;
        }
        else
        {
            if(card_number % 10 >= 5)
            {
                long digits = card_number % 10;
                total += ((digits*2)%10)+((digits*2)/10);
            }
            else
            {
                total += (card_number % 10)*2;
            }
            card_number /= 10;
        }
    }
    //tenary return operator
    return (total % 10 == 0) ? 0 : 1;
}

//check the card length

int card_length(long card_number)
{

    int length = 0;
    while(card_number > 0)
    {
        card_number /= 10;
        length++;
    }
    return length;
}

//check the card properties to evaluate type
void card_properties(long card_number, int length, int checksum)
{
    int pointer = 0;
    //while pointer is less than 16 and is not any of the card starting numbers
    while(pointer <= 16 &&(!(card_number == 34 || card_number == 37 || card_number == 4 || (card_number >= 51 && card_number <= 55))))
    {
        card_number /= 10;
        pointer++;
    }
    if((card_number == 34 || card_number == 37) && length == 15 && checksum == 0)
        {
            printf("AMEX\n");
        }
    else if((card_number == 4 && (length >= 13 && length <= 16) && checksum == 0))
        {
            printf("VISA\n");
        }
    else if(card_number >= 51 && card_number <= 55 && length == 16 && checksum == 0)
        {
            printf("MASTERCARD\n");
        }
    else
        {
            printf("INVALID\n");
        }

}
