#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    srand(time(0));
    cout << "========== WELCOME ==========\n";
    cout << "What's your Name : ";
    getline(cin, playerName);
    cout << "\nEnter the starting balance to play the game : $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\nYour current balance is $ " << balance << "\n";

        do
        {
            cout << "Hey, " << playerName << ", enter your ammount to bet $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
            {
                cout << "Betting balance cant be more than current balance!\n"
                     << "\nRe-enter balance";
            }

        } while (bettingAmount > balance);

        do
        {
            cout << "Guess any betting number between 1 & 10 : ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
            {
                cout << "\nNumber should be between 1 & 10\n"
                     << "Re-enter number";
            }

        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
        {
            cout << "\nYou're in luck !! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount * 10;
            balance = balance - bettingAmount * 10;
        }
        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n"
             << playerName << ", You have balance of $ " << balance << "\n";
        if (balance == 0)
        {
            cout << "You have no money to play";
            break;
        }
        cout << "\n--->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\nThanks for playing the game, Your balance is $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "========CASINO NUMBER GUESSING RULES!==========\n";
    cout << "1. Choose number between 1 - 10\n";
    cout << "2. Winner gets 10 times of the money bet\n";
    cout << "3. Wrong bet, and you lose the amount you bet\n";
}
