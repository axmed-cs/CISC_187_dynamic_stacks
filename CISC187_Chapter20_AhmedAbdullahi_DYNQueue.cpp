/******************************************************************************

Ahmed Abdullahi

Chapter 20 programming assignment - Recursion with Dynamic Queue

November 2023

This is the implementation file for the DYNQueue Class

*******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include "DYNQueue.h"
using namespace std;


/************************************
DYNQueue constructor
************************************/
DYNQueue::DYNQueue(){
    front = nullptr;
    rear = nullptr;
    numTimes = 0;
    
}


/************************************
DYNQueue destructor
************************************/
DYNQueue::~DYNQueue(){
    string value; //for parameter
    
    //removes every node in the queue
    while(!isEmpty()){
        dequeue(value);
    }
}



/************************************
DYNQueue enqueue (add at end of list)
************************************/
void DYNQueue::enqueue(string input){
    QueueNode *newNode = nullptr; //new node pointer
    
    //store input in the new node
    newNode = new QueueNode;
    newNode->word = input;
    newNode->next = nullptr;
    
    //random number generator (1-500) and puts it in newNode->raffle;
    srand((unsigned) time(NULL));
    int number = rand() % 500 + 1;
    newNode->raffle = number;
    
     //validate input
   if ((input.length() > 20) || input == ""){ 
           exit(EXIT_FAILURE);
        }
    
    //if queue is empty make newNode the front and rear node
    //other wise add newNode at the end (rear)
    if (isEmpty()){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    numTimes++; //used to find if queue is empty or full
    
    //confirmation message   
    cout << "Welcome to Point Loma Seafoods - '" << newNode->word;
    cout << "', your raffle number is: " << newNode->raffle << endl;
}


/**********************************************************
DYNQueue dequeue (from front of queue with reference parameter)
**********************************************************/
void DYNQueue::dequeue(string &input){
    QueueNode *temp = nullptr; // temporary pointer
    
    // check if list is empty
    if (isEmpty()){
        cout << "The queue is empty." << endl;
        input = "";
    }
    
    // else dequeue value of the queue
    else{
        input = front->word; //saves the dequeued value in the parameter
        temp = front;
        front = front->next;
        delete temp;
        
        numTimes--;
    }
}


/*******************************************
DYNQueue isEmpty (checks if queue is empty)
*******************************************/
bool DYNQueue::isEmpty() const{
    bool status; // bool variable that holds true or false
    
    //returns true if queue is Empty and false otherwise
    if(numTimes > 0){
        status = false;
    }
    else{
        status = true;
    }
    
    return status;
}


/**********************************************
DYNQueue countNode (counts all nodes in queue)
**********************************************/
int DYNQueue::countNode(QueueNode *nodePtr) const{
    //use recursion to go through the queue
    // and return number of nodes
    if(nodePtr != nullptr){
        return 1 + countNode(nodePtr->next);
    }
    else{
        return 0;
    }
}


/**********************************************
DYNQueue showNode (display all nodes in queue)
**********************************************/
void DYNQueue::showNode(QueueNode *nodePtr){
    //check if queue is empty
    if(isEmpty()){
        cout << "The queue is empty." << endl;
    }
    
    //traverses through list while printing the words in the nodes
    if(nodePtr != nullptr){
        cout << "   (" << counter << ") - " << nodePtr->word << " - " << nodePtr->raffle << endl;
        counter++;
        showNode(nodePtr->next);
    }
    counter = 0;
}


/***************************************************************
DYNQueue drawRaffle (calls private member funciton raffleWinner)
***************************************************************/
void DYNQueue::drawRaffle(){
    
    if(isEmpty()){
        cout << "The queue is empty." << endl;
    }
    
    //holds parameter value
    //random number from 0 to queue size
    if(!isEmpty()){
    srand((unsigned) time(NULL));
    int position = rand() % numTimes;

    //sends front node and a random position in queue as the winner
    return raffleWinner(front, position);
    }
}

/****************************************************
DYNQueue raffleWinner (randomly chooses raffle winner)
****************************************************/
void DYNQueue::raffleWinner(QueueNode *nodePtr, int input){
    //check if queue is empty
    int num = input;
    
    if(isEmpty()){
        cout << "The queue is empty." << endl;
    }
   
    //if queue is not empty then find the winner position
    if(!isEmpty()){
        //if position is found display winning message
        if (counter == num){
            cout << "The winning raffle is " << nodePtr->raffle;
            cout << ". Congrats you won the raffle '" << nodePtr->word << "'!" << endl;
            cout << endl << "Which of the following would you like?" << endl;
            cout << "1. FREE T-shirt" << endl;
            cout << "2. FREE Side Dish" << endl;
            
            int n = 0; // counter for input validation (while loops)
            int inputNumber = 0;
            cin >> inputNumber;
        
             //Validate user input so it has no characters and is either 1 or 2
             while (n == 0){
                 //check if user input has no characters (valid integer)
                while (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Error..." << endl;
                    cout << "Please enter 1 or 2..." << endl;
                    cin >> inputNumber;
                    cin.ignore();
                }
                
                //check if user input is 1 or 2
                if (inputNumber == 1){
                    n++;
                }
                else if(inputNumber == 2){
                    n++;
                }
                //else get display error and get user input
                else{
                    cout << "Error..." << endl;
                    cout << "Please enter 1 or 2..." << endl;
                    cin >> inputNumber;
                    cin.ignore();
                }
             }
             
             //display confirmation message
            if (inputNumber == 1){
                cout << "'" <<nodePtr->word << "', enjoy your FREE T-Shirt!" << endl;
            }
            else if(inputNumber == 2){
                cout << nodePtr->word << ", enjoy your FREE Side Dish!" << endl;
            }
        
        }
        //else traverse through list using recursion and try next node
        else{
            counter++;
            raffleWinner(nodePtr->next, num);
        }
    }
    counter = 0;
}
