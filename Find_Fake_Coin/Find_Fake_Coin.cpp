#include <iostream>
#include<string>
#include <map>
#include<vector>
using namespace std;

void find_fake_coins(vector<int>coins)
{
    int size = coins.size();
    int remaining_coins = size % 3; // elements in the end of the array that don't fit into any group 

    int new_coins_numbers = size - remaining_coins;

    int coin_group1 = 0;

    int coin_group2 = 0;

    int coin_group3 = 0;

    // filling the groups
    for (int i = 0; i < new_coins_numbers; i++)
    {

        if (i % 3 == 0)
        {
            coin_group1 += coins[i];
        }
        else if (i % 3 == 1)
        {
            coin_group2 += coins[i];
        }
        else
        {
            coin_group3 += coins[i];
        }

    }
    // check if all groups are equal, meaning the odd coin is in remaining coins
    if (coin_group1 == coin_group2)
    {
        if (coin_group1 == coin_group3)
        {   
            // determine if the remaining coins are 1 or more and determine if they are heavier or lighter
            if (remaining_coins == 1)
            {
                if (coins[0] > coins[size - 1])
                {
                    cout << "The fake lighter ";
                    return;
                }
                else
                {
                    cout << "The fake heavier ";
                    return;
                }
            }
            else
            {
                if (coins[0] == coins[size - 1])
                {
                    if (coins[0] > coins[size - 2])
                    {
                        cout << "The fake coin is lighter ";
                        return;
                    }
                    else
                    {
                        cout << "The fake coin is heavier ";
                        return;
                    }
                }
                else
                {
                    if (coins[0] > coins[size - 1])
                    {
                        cout << "The fake coin is lighter ";
                        return;
                    }
                    else
                    {
                        cout << "The fake coin is heavier ";
                        return;
                    }

                }
            }

        }
        // check the 3 groups against each other . if group1 = group2 then we can just measure either one against group3 to determine if the coin is heavier or lighter
        else
        {
            if (coin_group2 < coin_group3)
            {
                cout << "The fake coin is heavier ";
                return;
            }

            else
            {
                cout << "The fake coin is lighter";
                return;
            }
        }

    }
    else if (coin_group1 > coin_group2)
    {
        if (coin_group2 == coin_group3)
        {
            cout << "The fake coin is heavier ";
            return;
        }
        else
        {
            cout << "The fake coin is lighter";
            return;
        }

    }
    else
    {
        if (coin_group1 == coin_group3)
        {
            cout << "The fake coin is heavier ";
            return;
        }
        else
        {
            cout << "The fake coin is lighter";
            return;
        }
    }


}

int main()
{
    vector<int> coins = { 1,1,1,1,1,1,0,1,1,1,1 };
    /*vector<int> coins = { 1,1,1,1,1,1,2,1,1,1,1 };*/
    find_fake_coins(coins);
    return 0;

}