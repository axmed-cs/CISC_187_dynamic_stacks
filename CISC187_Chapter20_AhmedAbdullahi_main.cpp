/******************************************************************************

Ahmed Abdullahi

Chapter 20 programming assignment - Recursion with Dynamic Queue

November 2023

*******************************************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include "DYNQueue.h"
using namespace std;


// main
int main()
{
    //holds user input
    string inputString;   
    string wordDq;  
    int i = 0;  //used for input validation
    int n = 0;  //used for input validation
    
    //DYNQueue object initialization
    DYNQueue queue;
                      
    // while loop
    char option = 0;
  while (option != 6)
  {
    //Display menu
    cout <<  endl << endl << "********************************" << endl;
    cout << " Point Loma Seafoods - Display Menu " << endl;
    cout << "********************************" << endl;
    cout << "1.  Add a Name (enqueue)" << endl;
    cout << "2.  Make an Order (dequeue)" << endl;
    cout << "3.  Count Names" << endl;
    cout << "4.  Draw Raffle Winner" << endl;
    cout << "5.  Display Line" << endl;
    cout << "6.  Exit" << endl << endl;
    
    //input option
    cout << "Please choose an option from the numbers above or enter 6 to exit: ";
    cin >> option;
    cout << endl;
    
    // switch case from user option
    switch(option)
    {
    case '1': 
        // case 1 will add a word to the queue at the end (enqueue)

        cout << "Enter name (20 letters or less):" << endl << endl;
        
        //get user input for customers name
        cin.ignore();
        getline(cin, inputString);
        
        
        //validate user input to make sure it only has letters (no numbers/spaces)
         i = 0;
        while(inputString[i]){
            if (!isalpha(inputString[i])){
                cout << "Error, Please enter a valid name with no numbers and spaces: " << endl;
                n++;
            }
            i++; 
            if(n>0){
                getline(cin, inputString);
                i=0;
            }
            n = 0;
            //validate user input if length is greater than 20 or if its blank
            while ((inputString.length() > 20) || inputString == ""){  
                cout << "Error, Please enter a valid name less than 20 letters and not blank: " << endl;
                getline(cin, inputString);   
            }
        }
        
        // enqueue the user input
        queue.enqueue(inputString);
        
        break;
    
    case '2':   
        // case 2 will remove a node off the front of queue (dequeue)
        //wordDq holds the word which was removed (pass by reference)
        queue.dequeue(wordDq);
        if (!(wordDq == "")){
            cout << wordDq << ", you may now order!" << endl;
        }
        
        break;
    
    case '3':    
        //case 3 will count all nodes in the queue  
        cout << "There are currently " << queue.numNode() << " customer(s) in queue." << endl;
        
        break;
    
    case '4':    
        //case 4 will choose the raffle winner
        queue.drawRaffle();
        
        break;
        
    case '5':    
        //case 5 will display all nodes in the queue
        queue.display();
        
        break;
           
    case '6':
        // case 3 will close program
        cout << "Bye, we hope you had a good time." << endl;
        exit(0);
       
        break;
       
    default:  
    
        // validation for menu option
        cout << "That is not a valid menu option." << endl;
        
        break;
    
    }//end switch
 
    
  }//end the while loop
 
    return 0;
}//end main
