#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char play;
    const char *symbols[] = {"🍒","🍋","🔔","💎","𝟕","🍀"};
    const int symbol_count = sizeof(symbols) / sizeof(symbols[0]);
    char choice;
    int bet = 20;       // cost per spin
    int balance = 100;  // Starting balance
    int highscore = balance;      // highsore for session
    
    
    srand(time(NULL));
    printf("🎰Welcome to the Slot Machine!🎰\n");
    printf("You have a starting balance of %dT.\n", balance);
    printf("Each spin costs %dT.\n", bet);

    printf("Do you want to play? (y/n): ");
    scanf(" %c", &play);

    if (play == 'y' || play == 'Y') {
        printf("Good luck!\n");
    } else {
        printf("Maybe next time! 👋\n");
        return 0;
    }

    do
    {
        int i1 = rand() % symbol_count;
        int i2 = rand() % symbol_count;
        int i3 = rand() % symbol_count;
        printf ("\nSpinning...\n\n");
        printf("| %s | %s | %s |\n\n", symbols[i1], symbols[i2], symbols[i3]);

        int chance = rand() % 100 + 1; // Random number between 1 and 100

        if ( chance <= 5 && symbols[i1] == symbols[i2] && symbols[i2] == symbols[i3]) {
            printf("🎉 JACKPOT! You won! +200T 🎉\n");
            balance += 200;
            balance -= bet;
            highscore += 200;
        }
        else if (chance <= 15 && (symbols[i1] == symbols[i2] || symbols[i2] == symbols[i3] || symbols[i1] == symbols[i3])) {
            printf("😊 You got a two matching! You win +50T ! 😊\n");
            balance += 50;
            balance -= bet;
            highscore += 50;
        }
        else {
            printf("😞 No match this time. Try again! 😞\n");
            balance -= bet;
        }        
        printf("New Balance: %dT\n", balance);
        printf("Your Current Highscore is: %dT\n", highscore);

        if (balance <= 0) 
        {
            printf("You run out of tokens. Game over! 💀\n");
            printf("Your Session Highscore was: %dT\n", highscore);
            break;
        }

        if (balance > highscore) 
        {
            highscore = balance;
        }
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    printf("\nThanks for playing!👋\n");
    return 0;
}