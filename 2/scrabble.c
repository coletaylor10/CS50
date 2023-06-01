#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//prototype functions
int compute_score(string word);
void compute_winner(int player1, int player2);


//setting point values
int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

//main
int main(void)
{
    //computing scores and gaining player input
    int player1 = compute_score(get_string("Player 1: "));
    int player2 = compute_score(get_string("Player 2: "));

    compute_winner(player1, player2);
}

//caluclate scores based on point matrix
int compute_score(string word)
{
    int total = 0;
    //loops through string
    for(int i = 0, len = strlen(word); i < len ; i++)
    {
        //makes sure the character is valid A-Z
        if(toupper(word[i]) - 65 >= 0 && toupper(word[i]) - 65 <= 25){
            total += points[toupper(word[i]) - 65];
        }
    }
    return total;
}


//if else block to decide winner
void compute_winner(int player1, int player2)
{
    if(player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if(player1 < player2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
