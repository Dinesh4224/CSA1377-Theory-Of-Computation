#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STATE0 0
#define STATE1 1
#define STATE2 2

bool isAcceptingState(int state) {
    return state == STATE2;
}

bool simulateNFA(char* input) {
    int currentState[100];
    int nextState[100];
    int currentStateIndex = 0;
    int nextStateIndex = 0;

    currentState[currentStateIndex++] = STATE0;

    for (int i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        nextStateIndex = 0;

        for (int j = 0; j < currentStateIndex; j++) {
            int state = currentState[j];

            switch (state) {
                case STATE0:
                    if (currentChar == 'b') {
                        nextState[nextStateIndex++] = STATE1;
                    }
                    break;
                case STATE1:
                    if (currentChar == 'a') {
                        nextState[nextStateIndex++] = STATE2;
                    }
                    break;
            }
        }

        if (nextStateIndex == 0) {
            return false;  
        }

        currentStateIndex = nextStateIndex;
        memcpy(currentState, nextState, currentStateIndex * sizeof(int));
    }

    for (int i = 0; i < currentStateIndex; i++) {
        if (isAcceptingState(currentState[i])) {
            return true;  
        }
    }

    return false;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    bool result = simulateNFA(input);

    if (result) {
        printf("String accepted.\n");
    } else {
        printf("String rejected.\n");
    }

    return 0;
}

