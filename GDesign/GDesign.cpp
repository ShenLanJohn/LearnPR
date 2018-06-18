#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int number;
    
    cout << "Hello, welcome to GDesign!" << endl;
    cout << "1   Animal" << endl;
    cout << "2   Human" << endl;
    cout << "3   Nature" << endl;
    cout << "4   Abstract" << endl;
    cout << "5   Plant" << endl;
       
   while(number !=9999)   
   {
        cout << "Plese input a number (input 9999 to exit program!):";
        cin >> number;
    
        if(number == 9999)
        {
            cout << "Bye....." << endl;
            usleep(3000);
            return 0;
        }
        
        if(cin)
        {
            switch(number)
            {
                case 1 :
                    cout << "Koala!" << endl;
                    break;
                case 2 :
                    cout << "Einstein!" << endl;
                    break;
                case 3 :
                    cout << "Polar Light！" << endl;
                    break;
                case 4 :
                    cout << "Quantum theory!" << endl;
                    break;
                case 5 :
                    cout << "Succulent!" << endl;
                    break;
                default:
                    cout << "Invalid opiion number, pleaes try again!"<<endl;
                    break;
            }
        }
        else
        { 
            cout << "Invalid input! We are closing close GDesgin!"<<endl;
            return 0;
        }
   }
    return 0;
}