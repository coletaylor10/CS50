#include <cs50.h>
#include <stdio.h>


//prototype functions
int getinput(void);
void printspaces(int num);
void printblocks(int num);


//main
int main(void)
{
    //configurable parameters
    int input = getinput();
    int blocks = 0;
    int spaces = input - 1;

    //create pyramid
    for(int i = 0; i < input; i++)
    {
        printspaces(spaces);
        printblocks(blocks);
        printf("  ");
        printblocks(blocks);
        printf("\n");
        spaces -=1;
        blocks +=1;
    }


}


//spaces to center pyramid
void printspaces(int num){
    for(int j = 0; j < num; j++){
        printf(" ");
    }
}

//prints hashtags
void printblocks(int num){
    for(int j = 0; j < num+1; j++){
        printf("#");
    }
}


//cleans input and loops if input is incorrect
int getinput(void){
    int input;
    do{
    input = get_int("Height: ");

    }while(input < 1 || input > 8);


    return input;


}
