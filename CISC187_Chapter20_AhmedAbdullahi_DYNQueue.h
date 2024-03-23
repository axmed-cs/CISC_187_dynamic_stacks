/******************************************************************************

Ahmed Abdullahi

Chapter 20 programming assignment - Recursion with Dynamic Queue

November 2023

This is the specification file for the DYNQueue Class

*******************************************************************************/
#ifndef DYNQUEUE_H
#define DYNQUEUE_H


class DYNQueue{
    private: 
        // structure for the queue nodes
        struct QueueNode{
            std::string word;
            int raffle;
            struct QueueNode *next;
        };
        
        struct QueueNode *front; // Queue front pointer
        struct QueueNode *rear;  // Queue rear pointer
        int numTimes;            //to check if queue is full or empty
        int counter = 0;         //counter for displaying the nodes
        
        //private member functions (recursion)
        int countNode(QueueNode *) const;
        void showNode(QueueNode *);
        void raffleWinner(QueueNode *, int);
        
        public: 
        // contructor
        DYNQueue();
        
        // destructor
        ~DYNQueue();
        
        //Queue operations
        void enqueue(std::string);
        void dequeue(std::string &);
        bool isEmpty() const;
        int numNode() const
            { return countNode(front); }
        void display()
            { return showNode(front); }
        void drawRaffle();
        
            
};
#endif