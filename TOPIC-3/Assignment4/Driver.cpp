#include "DLList.h"

int main() {
    //Create Variables
    string newContents;
    string compare;
    string getcount;
    string getiterator;
    string stopped;
    char letter;
    int counter;
    int player_count;
    
	cout << "\n\nAssignment4 Started..." << endl;;
	//Create file var
	ifstream inputfile;
	//Open file
	inputfile.open("a3input.txt");
	
	// Debugger
	if(inputfile.is_open())
		{cout << " Inputfile was opened successfully!\n" << endl;
	}else{
	    cout << " Inputfile Failed to Open.\n" << endl;
		
	}
	    
	DLList list;
	
	while(inputfile.is_open()) {
		
		// Get int from input file as string, turn it into int
		// File input only reads in CHAR and STRING. So we need to convert it.
		getline(inputfile, getcount);
		stringstream getint(getcount);
		getint >> player_count;
		
		// Building the Linked List
	    for(int i = 0; i<player_count;i++) {
	        getline(inputfile, newContents);
	        cout<<"    Creating Node "<<i<<" with Contents: "<<newContents<<endl;
	        list.insert(newContents);
	        sleep(3);
	        cout<<"    Node "<<i<<" Created." <<endl;
	    }
	    
	    cout << "\nNode creation completed. Count = " << player_count << "\n" << endl;
	    // Clear our Stringstream for later use
	    getint.clear();
	    
	    // The names have all been entered thanks to the dynamic file read-in module.
	    // The next values will all be the amount of times to move through the list.
	    // So, we need to loop this through until the file is done.
	    while(!inputfile.eof()) {
	    	// Get the next line, which is the amount to move through the linked list.
	    	getline(inputfile, getiterator);
	    	stringstream iterator(getiterator);
	    	iterator >> counter;
	    	
	    	// Run the getStop function to read out where it stops.
	    	// It will then run the remove function.
	    	if(list.removeFirst(list.getStop(counter)) == true) {
	    		cout << "  Elimination Successful.\n" << endl;
	    	}else{
	    		cout << "  Elimination Failed.\n" << endl;
	    	}
	        sleep(1);
	    }
	    
	    // Report the winner
	    if(inputfile.eof()) {
	    	cout << "\n\nThe winner is: " << list.getFront() << "!" << endl;
	    }
	    
	    // Clear all of the nodes and free the memory.
	    list.clear();
	    
		// Close File, we're done
		inputfile.close();
	}
	cout << "Program Complete!\n" << endl;
	return 0;
}