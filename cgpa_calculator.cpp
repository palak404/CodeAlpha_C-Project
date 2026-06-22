#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;
    int n, choice;
    float gpa[20], total = 0, cgpa = 0;
    bool calculated = false;

    cout<<
"---------------------------------------\n";
    cout<< "STUDENT RESULT MANAGEMENT SYSTEM\n";
    cout<<
"---------------------------------------\n";

    cout<< "Enter Student Name : ";
    getline(cin, name);

    cout << "Enter Number of Subjects : ";
    cin >> n;

    do{
        cout<<"\n------------MENU------------\n";

        cout << "1. Enter GPA\n";
        cout << "2. Calculate CGPA\n";
        cout << "3. View Result\n";
        cout << "4. Exit\n";
        cout << "Enter Choice : ";
        cin  >> choice;

    switch(choice)
    {
        case 1:
            total = 0;
            for(int i=0;i<n;i++)
            {
                cout << "Enter GPA of Subject" << i+1 << "(0-10) :";
                cin >> gpa[i];

                while(gpa[i] < 0 || gpa[i] >10)
                {
                    cout << "Invalid GPA! Enter Again : ";
                    cin >> gpa[i];
                }
                total += gpa[i];
            }
            calculated = false;
            break;
        case 2:
             cgpa = total / n;
             calculated = true;
             cout<<"\nCGPA Calculated Successfully.\n";
             break;
        case 3:
           if(!calculated)
           {
            cout << "\nPlease Calculated CGPA Frist.\n";
           }   
           else{
                 cout<< "\n-----------RESULT-----------\n";
                 cout<< "Student Name : " << name << endl;
                 cout<< "CGPA         : " << cgpa << endl;

                       if(cgpa >= 9)
                       cout<< "Performance : Outstanding";
                       else if(cgpa >= 8)
                       cout<< "Performance : Excellent";
                       else if(cgpa >= 7)
                       cout<< "Performance : Very Good";
                       else if(cgpa >= 6)
                       cout<< "Performance : Good";
                       else
                       cout<< "Performance : Needs Improvement";
                       cout << endl;

                       } 
                       break;

        case 4:
             cout << "\nThank You for Using the System!";
            break;
                    
        default:
             cout << "\nInvalid Choice!";

         }
        
        } 
     while(choice != 4);
    return 0;
        
}