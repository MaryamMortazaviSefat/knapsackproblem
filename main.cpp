#include <iostream>
#include "object.h"
#include "knapsack.h"
using namespace std;

void menu();
int main()
{
    cout<<"In the name of gad\nby Maryam Mortazavi Sefat\n\n";

    menu();
    return 0;
}

/*
example:
5 13
2 20
5 30
7 35
3 12
1 3

example2:
3 5
2 10
4 35
1 25
*/

void menu()
{
    Knapsack knapsack;
    int option=0;

    cout<<"please enter the count of object & max weight\n";
    cout<<"then enter the weight & value of each objects\n";
    cout<<"example:\n5 13\n2 20\n5 30\n7 35\n3 12\n1 3\n\n";

    cin >>knapsack;
    cout<<"\n"<<knapsack; //for test

    while(true)
    {
        cout<<"\nplease enter your desired option:\n";
        cout<<"1.dynamic programming\n";
        cout<<"2.backtrack\n";
        cin>>option;

        if(option==1)
        {
            cout <<"\ndynamic programming end result: ";
            cout<< knapsack.compute_max_value_dynamic_programming()<<"\n";
            cout<<"the number of dynamic programming steps : "<<knapsack.get_dynamic_steps()<<"\n";
        }

        if(option==2)
        {
            cout<<"\n\nbacktrack:   "<<"\n";
            knapsack.compute_max_value_backtrack();
            cout<<knapsack.get_backtrack_proccess()<<"\n";
        }

    }
}
