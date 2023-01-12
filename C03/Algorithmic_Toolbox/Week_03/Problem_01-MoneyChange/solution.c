#include <stdio.h>

typedef struct CoinsChange
{
    int pennies;
    int nickels;
    int dimes;
} CoinsChange;

int get_money_change_from_stdin();
CoinsChange exchange_to_coins(int money_to_return_in_coins);
void printCoinsChange(CoinsChange change);

int main()
{
    int money_to_return_in_coins = get_money_change_from_stdin();
    CoinsChange result = exchange_to_coins(money_to_return_in_coins);
    printf("Money: %6d cents\n", money_to_return_in_coins);
    printCoinsChange(result);

    return 0;
}

int get_money_change_from_stdin()
{
    int stdin_input;
    scanf("%d", &stdin_input);

    return stdin_input;
}

CoinsChange exchange_to_coins(int money_to_return_in_coins)
{
    CoinsChange result;
    result.dimes = money_to_return_in_coins / 10;
    money_to_return_in_coins %= 10;
    result.nickels = money_to_return_in_coins / 5;
    money_to_return_in_coins %= 5;
    result.pennies = money_to_return_in_coins;

    return result;
}

void printCoinsChange(CoinsChange change)
{
    printf("Coins: %6d coins\n", change.dimes + change.nickels + change.pennies);
}
