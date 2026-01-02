#include <iostream>
#include <ctime>

int main(){
    srand(time(NULL));  
    char choice;
    int bet;
    int yourCoins;
    int i = 1;
    char playAgain;

    std::cout << "Enter your no. of coins: ";
    std::cin >> yourCoins;

    do {
        int random1 = (rand() % 6) + 1;
        int random2 = (rand() % 6) + 1;
        int sum = random1 + random2;

        std::cout << "Enter your bet amount: ";
        std::cin >> bet;

        if (yourCoins < bet){
            std::cout << "You cannot make a bet.Insufficient coins.";
            return 0;
        }
        else if ((!(bet % 500 == 0)) || (bet == 0)){
            std::cout << "Not a valid bet.";
            return 0;
        }

        std::cout << "A: 0-6\nB: 7\nC: 8-12\n";
        std::cout << "Enter your choice (A,B,C): ";
        std::cin >> choice;

        int coinsNow;
        std::cout << "dice1 : " << random1 << " dice2 : " << random2 << '\n';
        if (choice != 'A' && choice != 'B' && choice != 'C'){
            std::cout << "Invalid choice";
        }
        else if ((sum >=0 && sum <= 6) && choice == 'A'){
            coinsNow = yourCoins - bet + (bet * 2);
            std::cout << "You won " << bet * 2 << "!!\n";
            std::cout << "Coins : " << coinsNow << '\n';
        } 
        else if (sum == 7 && choice == 'B'){
            coinsNow = yourCoins - bet + (bet * 3);
            std::cout << "You won " << bet * 3 << "!!\n";
            std::cout << "Coins : " << coinsNow << '\n';
        }
        else if ((sum >=8 && sum <= 12) && choice == 'C'){
            coinsNow = yourCoins - bet + (bet * 2);
            std::cout << "You won " << bet * 2 << "!!\n";
            std::cout << "Coins : " << coinsNow << '\n';
        }
        else {
            std::cout << "Agh.You lost!\n";
            coinsNow = yourCoins - bet;
            std::cout << "Coins : " << coinsNow << '\n';
        }

        yourCoins = coinsNow;
        i++;
        std::cout << "Want to play again? (Y/N): ";
        std::cin >> playAgain;
        std::cout << '\n';

    }while((i <= 7) && (yourCoins > 0) && (playAgain == 'Y'));

    return 0;
}