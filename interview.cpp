#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int get_open( ifstream& ); //fuction prototypes
void avg_calc( ifstream& );

int main ()
{
    ifstream infile;
    get_open( infile );
    avg_calc( infile );
}

int get_open( ifstream& file )
{
    const int MAXCHARS = 255; //max # of filename characters
    char name[MAXCHARS];

    cout << "Please enter the name of the file you wish to open: ";
    cin >> name; //user enters file name

    file.open(name); //opens file; input pathway

    if ( file.fail() ) //check for succesful open
    {
	    cout << "\n The file was not openend successfully "
             << "\n Please check that the file currently exits." << endl;
	    exit(1);
    }
    else
	    return 0;
}

void avg_calc( ifstream& file )
{
    //read data file
    char ch;
    double v; //lower case v for data values
    vector<double> V; //capital V for vector containing data values v (lower case)

    while( (ch = file.get()) != EOF ) //check for end of file
    {
        file.putback(ch); //an alternative is to have this line in each if..else statement body
        if ( ch >= '0' && ch <= '9' )
        {
	        while( file >> v )
            {
	            V.push_back(v); //input data by appended vector V
                break;
	        }
        }
        else
            file.ignore(); //skips over character if it's not a double
    }
    file.close(); //closes input file pathway
    
    //now compute the average of the doubles entered

    double s = 0.0; //variable for data entered into vector below
    int i;
       
    for ( i = 0; i < V.size(); ++i )
    {
        s +=  V[i]; //calculates data sum (alternative to using s = s + V[i])
        cout << "\nThis is V[" << i << "]:= " << V[i] << endl;
    }
    
    cout << "\nHere is the sum: " << s << endl;
    cout << "\nAnd the number of doubles is: " << i << endl;
    
    double avg;
    avg = s/i;
    cout << "\nThe average of the numbers in the file is: " << avg << endl;
}
