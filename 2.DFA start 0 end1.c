#include <stdio.h>

int main() {
    int state = 0; 
    char input;

    printf("Enter a string of 0's and 1's: ");
    while((input = getchar()) != '\n') { 
        switch(state) {
            case 0:
                if(input == '0') state = 1;
                else state = 3;
                break;
            case 1:
                if(input == '0') state = 1;
                else if(input == '1') state = 2;
                else state = 3;
                break;
            case 2:
                if(input == '0' || input == '1') state = 2;
                else state = 3;
                break;
            case 3:
                break;
        }
    }

    if(state == 2) printf("The input string is accepted.\n"); // If the final state is 2, then the input string is accepted
    else printf("The input string is not accepted.\n");

    return 0;
}

