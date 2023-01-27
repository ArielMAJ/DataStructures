#include <stdio.h>
#include <stdlib.h>


typedef struct Coins
{
    int one;
    int three;
    int four;
} Coins;

int ONE = 1;
int THREE = 3;
int FOUR = 4;

int get_int();
int exchange_coins(int money_input);
Coins greedy_coins_exchange(int money_input);
void check_for_better_coin_combinations(Coins *coins);
int amount_of_coins(Coins coins);

int main(void)
{
    int money_input = get_int();
    printf("%d\n", exchange_coins(money_input));

    return 0;
}

int exchange_coins(int money_input)
{
    Coins coins = greedy_coins_exchange(money_input);

    check_for_better_coin_combinations(&coins);

    return amount_of_coins(coins);
}

Coins greedy_coins_exchange(int money_input)
{
    Coins coins = {0};
    coins.four = money_input / FOUR;
    money_input %= FOUR;
    coins.three = money_input / THREE;
    money_input %= THREE;
    coins.one = money_input;
    return coins;
}

void check_for_better_coin_combinations(Coins *coins)
{
    if (coins->one > 0 && coins->three > 0)
    {
        coins->one--;
        coins->three--;
        coins->four++;
    }

    if (coins->one > 1 && coins->four > 0)
    {
        coins->four--;
        coins->one--;
        coins->one--;
        coins->three++;
        coins->three++;
    }
}

int amount_of_coins(Coins coins)
{
    return coins.one + coins.three + coins.four;
}

int get_int()
{
    int value;
    scanf("%d", &value);

    return value;
}
