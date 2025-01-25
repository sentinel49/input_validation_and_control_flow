/*
 * Project Name: Input Validation and Control Flow
 * Created by: sentinel49
 * GitHub: https://github.com/sentinel49
 *
 * Description:
 * This C++ program demonstrates input validation, control flow, and modular functions by calculating membership rewards based on user input.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void showMenu();
void showRewards(double, double);

int main()
{
    int choice;
    double monthlyPurchases;

    const int basic = 1,
              standard = 2,
              premium = 3,
              quit = 4;

    const double basicHigh = 0.15,
                 basicLow = 0.10,
                 standardHigh = 0.20,
                 standardLow = 0.15,
                 premiumHigh = 0.30,
                 premiumLow = 0.20;

    cout << fixed << showpoint << setprecision(2);

    do
    {
        showMenu();
        cin >> choice;

        // Input validation for choice
        while (cin.fail() || choice < basic || choice > quit)
        {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Please enter a valid membership type (1-4): ";
            cin >> choice;
        }

        if (choice != quit)
        {
            cout << "Enter your monthly purchase total: $";
            cin >> monthlyPurchases;

            // Input validation for monthlyPurchases
            while (cin.fail() || monthlyPurchases < 0)
            {
                cin.clear(); // Clear the error flag on cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Please enter a valid, non-negative amount: $";
                cin >> monthlyPurchases;
            }

            switch (choice)
            {
            case basic:
                if (monthlyPurchases >= 101)
                    showRewards(basicHigh, monthlyPurchases);
                else
                    showRewards(basicLow, monthlyPurchases);
                break;
            case standard:
                if (monthlyPurchases >= 101)
                    showRewards(standardHigh, monthlyPurchases);
                else
                    showRewards(standardLow, monthlyPurchases);
                break;
            case premium:
                if (monthlyPurchases >= 101)
                    showRewards(premiumHigh, monthlyPurchases);
                else
                    showRewards(premiumLow, monthlyPurchases);
                break;
            }
        }
    } while (choice != quit);
    return 0;
}

void showMenu()
{
    cout << "\n\t\t Wholesale Membership Rewards Calculator\n\n"
         << "NOTE: Basic and Standard members who spend more than $100 per month earn\n"
         << "an additional 5% in rewards and Premium members who spend more than $100\n"
         << "earn an additional 10% in rewards!\n\n"

         << "1. Basic Membership (10%)\n"
         << "2. Standard Membership (15%)\n"
         << "3. Premium Membership (20%)\n"
         << "4. Quit\n\n"
         << "Enter your choice: ";
}

void showRewards(double memberRate, double monthlyPurchases)
{
    cout << "The rewards balance is $"
         << (memberRate * monthlyPurchases) << endl;
        
}
