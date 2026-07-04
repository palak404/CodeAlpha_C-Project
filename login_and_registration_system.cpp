#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//Function to register a new user
void registerUser()
{
    string username, password;
    string user, pass;

    cout<< "\n========== Registration ==========\n";

    cout<< "Enter Username: ";
    cin>>username;

    if(username.length() < 4)
    {
        cout<< "Username must be at least 4 characters long.\n";
        return;
    }
    cout << "Enter Password: ";
    cin >> password;
    
    if(password.length() < 6)
    {
        cout<< "Password must be at least 6 characters long.\n";
        return;
    }

    //Check duplicate username
    ifstream infile("users.txt");

    while(infile >> user >> pass)
    {
        if(user == username)
        {
            cout<< "Username already exists!\n";
            infile.close();
            return;
        }
    }
    infile.close();

    //Save new user
    ofstream outfile("users.txt",ios::app);
    outfile<< username << " " << password <<endl;
    outfile.close();

    cout<< "Registration Successful!\n";

}

// Function to login
void loginUser()
{
    string username,password;
    string user, pass;
    bool found = false;

    cout<< "\n=========== Login ===========\n";

    cout << "Enter Username: ";
    cin>> username;

    cout<< "Enter Password: ";
    cin>> password;

    ifstream infile("users.txt");

    while(infile >> user >> pass)
    {
        if(user == username && pass == password)
        {
            found = true;
            break;
        }
    }
    infile.close();

    if(found)
    {
        cout<< "\nLogin Successful!\n";
        cout<< "Welcome " << username << "!\n";

    }
    else{
        cout<< "\nInvalid Username or Password!\n";

    }

}

int main()
{
    int choice;

    do
    {
       cout<< "\n=======================\n";
       cout<< " LOGIN & REGISTRATION SYSTEM\n";
       cout<< "=======================\n";
       cout<< "1. Register\n";
       cout<< "2. Login\n";
       cout<< "3. Exit\n";
       cout<< "Enter your choice : ";
       cin >> choice;

       switch(choice)
       {
        case 1:
           registerUser();
           break;
        case 2:
           loginUser();
           break;
        case 3:
           cout<< "Thank You!\n";
           break;
        default:
           cout<< "Invalid Choice!\n";       

       }
    }  while (choice != 3);
    return 0;
    
}