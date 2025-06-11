#include <iostream>
using namespace std;

//****** variables ******//
int deposit = 0, Withdraw = 0, password = 9988, choice = 0;
double balance = 1000;
//****** End of variables ******//

// show is a function to display the menu of ATM
void show()
{
    cout << "******** Menu ********" << endl;
    cout << "1:Balance" << endl;
    cout << "2:Withdraw" << endl;
    cout << "3:Deposit" << endl;
    cout << "4:Exit" << endl;
    cout << "**********************" << endl;
}

void process()
{
    cout << "Enter your Password: ";
    cin >> password;
    system("cls");

    do
    {
        if (password == 9988)
        {
            cout << "Enter your Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "your Balance is " << balance << endl;
                break;

            case 2: // The balance will decrease
                cout << "Note : your Balance is " << balance << endl;
                cout << "Enter your amount: ";
                cin >> Withdraw;

                if (Withdraw > balance)
                {
                    cout << "Sorry you can't Withdraw this Amount " << endl;
                }
                else
                {
                    balance -= Withdraw;
                    cout << "now : your balance is " << balance << endl;
                }
                break;

            case 3: // the balance will increase
                cout << "your Current Balance is " << balance << endl;
                cout << "Enter your deposit money: ";
                cin >> deposit;
                balance += deposit;
                cout << "your New Balance is " << balance << endl;
                break;

            case 4:
                cout << "Thank you" << endl;

                break;

            } // End of switch

        } // End of if

        else
        {
            char option = 'o';
            cout << "Password is Incorrect, Do you want to try Again ? Enter [Y] for Yes or [N] for No\n";
            cin >> option;

            if (option == 'Y' || option == 'y')
            {
                cout << "Enter your Password: ";
                cin >> password;
                system("cls");
            }
            else
            {
                choice = 4;
            }
        }

    } while (choice < 4);

} // End of process

int main()
{
    show();
    process();
    return 0;
}