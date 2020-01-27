#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Bank
{
private:
    const string username;
    const int bankid;
    static int users;
    int balance;
    string password;
    Bank *next;
public:
    static void NoOfUsers()
    {
        cout<<"Total users : "<<users<<endl;
    }
    Bank(string name, int id, string pp, int x=0):username(name), bankid(id), password(pp), balance(x)
    {
        if(balance < 0)
        {
            balance = -balance;
        }
        users++;
        cout<<"Account created successfully!"<<endl;
        cout<<"Bankid: "<<bankid<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"password: "<<password<<endl;
        cout<<"Initial balance: "<<balance<<endl;
        cout<<endl<<endl<<"NOTE: Bankid and password is used for authenticaton! So keep it safe!"<<endl;
    }
    void withdraw()
    {
        int amount;
        cout<<"Enter amount to withdraw: ";
        cin>>amount;
        if(balance - amount >= 0)
        {
            balance -= amount;
            cout<<"Amount withdrawn successfully!"<<endl;
        }
        else
        {
            cout<<"Insufficient amount to withdraw!"<<endl;
        }
    }
    void deposit()
    {
        int amount;
        cout<<"Enter amount to deposit: ";
        cin>>amount;
        if(amount > 0)
        {
            balance += amount;
        }
        else
        {
            amount = -amount;
            balance += amount;
        }
        cout<<"Amount deposited successfully!"<<endl;
    }

    void changepp()
    {
        cout<<"Please enter your current password: ";
        string pp;
        cin>>pp;
        if(pp == password)
        {
            cout<<"Please enter new password: ";
            cin>>password;
            cout<<"Password changed successfully!"<<endl;
        }
        else cout<<"Wrong password!" <<endl;
    }

    void getDetails() const
    {
        cout<<"Username :"<<username<<"\n";
        cout<<"Bank id: "<<bankid<<"\n";
        cout<<"Balance: "<<balance<<endl;
    }
    void CreateNewUser(string name, string pp, int x);
    int Checkidandpp();

}*START, *CHECK, *RAND;
int Bank::users = 0;
void Bank::CreateNewUser(string name, string pp, int x)
{

    Bank *ptr;
    srand(time(NULL));
    int c;
    c = rand();
    ptr = new Bank(name,c, pp, x);
    if(START == NULL)
    {
        ptr->next = NULL;
        START = ptr;
        CHECK = ptr;
    }
    else
    {
       CHECK->next = ptr;
       ptr->next = NULL;
       CHECK = ptr;
    }

}
int Bank::Checkidandpp()
{
    cout<<"Enter your bankid: ";
    int id;
    cin>>id;
    cout<<"Enter password: ";
    string pp;
    cin>>pp;
    RAND = START;
    while(RAND != NULL)
    {
        if(RAND->bankid == id)
        {
            if(RAND->password == pp)
                return 1;
            cout<<"Wrong password!";
            return 0;
        }
        RAND = RAND->next;
    }
    cout<<"Bankid not found!\n";
    return 0;
}
int main()
{
    int select, bankid, deposit;
    string username, pp;
    while(1){
    cout<<"1. Create new user"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Close"<<endl;
    cin>>select;
    switch(select)
    {
    case 1:
        system("cls");

        cin.ignore();
        cout<<"Enter username: ";
        getline(cin, username);
        cout<<"Enter password: ";
        getline(cin, pp);
        cout<<"Enter amount to deposit: ";
        cin>>deposit;
        system("cls");
        START->CreateNewUser(username, pp, deposit);
        system("pause");
        break;
    case 2:
        system("cls");
        select = START->Checkidandpp();
        if(select == 1)
      {
         while(1)
        {
         cout<<"1. Deposit"<<endl;
         cout<<"2. Withdraw"<<endl;
         cout<<"3. Change password"<<endl;
         cout<<"4. Display account information"<<endl;
         cout<<"5. LogOut"<<endl;
         int choice;
         cin>>choice;
         switch(choice)
         {
            case 1:  RAND->deposit(); break;
            case 2: RAND->withdraw(); break;
            case 3: RAND->changepp(); break;
            case 4: RAND->getDetails();break;
            case 5: cout<<"Thanks for using this application!"<<endl;
                    break;
            default:
                cout<<"Wrong option!"<<endl;
                continue;
         }
         system("pause");
         system("cls");
         if(choice == 5)
            break;
        }
      }
      break;
      case 3:
        cout<<"Thanks for using this application!"<<endl;
        //Bank::NoOfUsers();
        return 0;
    default:
        cout<<"Wrong option selected!";
        continue;

     }
    }
    return 0;
}
