#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Game constants
#define STARTING_BALANCE 100
#define BET_COST 20
#define JACKPOT_PAYOUT 200
#define TWO_MATCH_PAYOUT 50

int main(void)
{
    char play;
    const char *symbols[] = {"🍒","🍋","🔔","💎","𝟕","🍀"};
    const int symbol_count = sizeof(symbols) / sizeof(symbols[0]);
    char choice;
    int bet = BET_COST;       // cost per spin
    int balance = STARTING_BALANCE;  // Starting balance
    int highscore = balance;      // highest balance for session
    
    
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

        // Deduct bet first
        balance -= bet;

        // Check for wins based on actual symbol matches
        if (symbols[i1] == symbols[i2] && symbols[i2] == symbols[i3]) {
            printf("🎉 JACKPOT! You won! +%dT 🎉\n", JACKPOT_PAYOUT);
            balance += JACKPOT_PAYOUT;
        }
        else if (symbols[i1] == symbols[i2] || symbols[i2] == symbols[i3] || symbols[i1] == symbols[i3]) {
            printf("😊 You got two matching! You win +%dT! 😊\n", TWO_MATCH_PAYOUT);
            balance += TWO_MATCH_PAYOUT;
        }
        else {
            printf("😞 No match this time. Try again! 😞\n");
        }        
        // Update highscore if current balance is higher
        if (balance > highscore) 
        {
            highscore = balance;
        }

        printf("New Balance: %dT\n", balance);
        printf("Your Current Highscore is: %dT\n", highscore);

        if (balance <= 0) 
        {
            printf("You run out of tokens. Game over! 💀\n");
            printf("Your Session Highscore was: %dT\n", highscore);
            break;
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &choice);

        // Input validation
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            printf("Invalid input. Please enter 'y' or 'n': ");
            scanf(" %c", &choice);
        }

    } while (choice == 'y' || choice == 'Y');
    printf("\nThanks for playing!👋\n");
    return 0;
}