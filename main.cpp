//This program will be used to take input from user and execute
//the respective min heap operations

#include"util.h"
#include"heap.h"

using namespace std;

int main(){
	
	string line;
	HEAP H;
	HEAP* heap = &H;
	heap -> capacity = -1;
	cout << "Please enter a command: ";
	
	//file variables
	ifstream file;			
	int read = 0;
	int count = 0;
	int j = 1;
	int min = 0;
	char buffer[256];
	int numlines;
	
	file.open("HEAPinput.txt");
	getline(file, line);
	count = atoi(line.c_str());
	ELEMENT *A = new ELEMENT[count +1];
	
	//parser variables
	int i, v, f;
	char c;
	
	while(1){	
	c = nextCommand(&i, &v, &f);
	switch(c){		
		case 's':
		case 'S':
			 cout << "COMMAND: " << c << "\nThe program is going to be terminated.\n";
			 exit(0);

		case 'C':
			cout << "COMMAND: " << c << " " << i << '\n';
			heap = Initialize(i);
			break;

		case 'R':
			cout << "COMMAND: " << c << '\n';
			if(heap -> capacity == -1){
				cout << "Sorry! It cannot be done. Please initialize the heap first.\n";
				break;
			}
			if(heap -> capacity < count){
				cout << "Sorry! It cannot be done. Please increase the capacity of the heap first.\n";
				break;
			}
			if(!file.is_open()){
				cout << "There was a problem opening file HEAPinput.txt for reading. \n";
				break;
			}
			//while(getline(file, line)){
			while(!file.eof()){			
				file.getline(buffer, 256, '\n');
				if(strlen(buffer))
					numlines++;
				//getline(file, line);
				read = atoi(buffer);
				//read = atoi(line.c_str());
				A[j].key = read;
				j++;
			}
			
			if(numlines < count){
				cout << "Sorry! It cannot be done. The number of elements in file is less than as speicified in the beginning of the file.\n";
				break;
			}
			BuildHeap(heap, A, count);
			break;
	
		case 'W':
			cout << "COMMAND: " << c << '\n';
			if(heap -> capacity == -1){
				cout << "Sorry! It cannot be done. Please initialize the heap first.\n";
				break;
			}
			printHeap(heap);
			break;

		case 'I':
			cout << "COMMAND: " << c << " " << i << " " << v;
			if(heap -> capacity == -1){
				cout << "\nSorry! It cannot be done. Please initialize the heap first.\n";
				break;
			}
			if(i != 1 && i != 2){
				cout << "This is not a valid flag value. This operation cannot be completed.\n";
				break;
			}
			Insert(heap, i, v);
			break;
		
		case 'D':
			cout << "COMMAND: " << c << " " << i << '\n';
			if(heap -> capacity == -1){
				cout << "Sorry! It cannot be done. Please initialize the heap first and put the elements into it.\n";
				break;
			}
			if(heap -> size == 0){
				cout << "You cannot delete anymore elements because the heap is empty.\n";
				break;
			}
			
			min = DeleteMin(heap, i);
			cout <<  min << endl;
			break;

		case 'k':
		case 'K':
			cout << "COMMAND: " << c << " " << i << " " << v << " " << f << '\n';
			if(heap -> capacity == -1){
				cout << "Sorry! It cannot be done. Please initialize the heap first and put the elements into it.\n";
				break;
			}
			DecreaseKey(heap, i, v, f);
			break;

		default: 
			break;
	
	}

	}
return 0;
}

