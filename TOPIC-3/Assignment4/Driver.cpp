#include "Assignment4.h"

int main() {
    //Create Variables
    string line;
    string compare;
    char letter;
    int number;
    int player_count = 5;
    
	cout << "Assignment4 Started..." << endl;;
	//Create file var
	ifstream inputfile;
	//Open file
	inputfile.open("a3input.txt");
	
	// Debugger
	if(inputfile.is_open())
		{cout << "Inputfile was opened successfully." << endl;
	}else{
	    cout << "Inputfile Failed to Open" << endl;}
	    
	DLList list;
	
	while(inputfile.is_open()) {
	    for(int i = 0; i<player_count;i++) {
	        getline(inputfile, line);
	        list.insert(line);
	        cout << "Line Inserted: i=" << i << ".L:" << line << endl;
	        sleep(1);
	    }
		// Close File
		inputfile.close();
	}
	cout << "Program Complete!" << endl;
	return 0;
}