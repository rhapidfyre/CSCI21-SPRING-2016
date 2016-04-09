/*
 
    Michael Harris
    Assignment 4
    April 7th 2016
 
    References Used:
  
 */
 
// Includes
#include <cstdlib> // For NULL
#include <iostream> // I just add this by default.
#include <fstream> // for File Input.
#include <string> // for newContents
#include <sstream> // for converting numbers in file to int from string
#include <unistd.h> // Not sure why I added this.
using namespace std;

// Header Guards
#ifndef DLNODE
#define DLNODE
// DLNode Class Declarations
class DLNode {
    public:
        DLNode();
        DLNode(string newContents);
        virtual ~DLNode();
        void setContents(string newContents);
        void setNext(DLNode* newNext);
        void setPrevious(DLNode* newPrevious);
        string getContents() const;
        DLNode* getNext() const;
        DLNode* getPrevious() const;
    private:
        string contents;
        DLNode* previous_node;
        DLNode* next_node;
};

#endif