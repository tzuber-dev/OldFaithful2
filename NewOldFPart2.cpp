#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	string inputuser;
	cout << "Enter path: ";
	cin >> inputuser;

	ifstream inputactualcontent(inputuser);
	ofstream outputactualcontent("faithful_updated.csv");
	if (!inputactualcontent.is_open() || !outputactualcontent.is_open()) {
		cerr << "!! CAN'T OPEN !!";
		return 1;
	}

	string headerfile;
	getline(inputactualcontent, headerfile);
	outputactualcontent << headerfile << ",Short Wait Time\n";

	double sumeruptioninterval = 0.0;
	double sumwaitinginterval = 0.0;

	double eruptioninterval = 0.0;
	int trackercounting = 0;
	double waitinginterval = 0.0;
	char charactersymbol = ',';
	
	

	// ^^ variable declaration for the while loop to work 
	while ((inputactualcontent >> eruptioninterval) && (inputactualcontent >> charactersymbol) && (inputactualcontent >> waitinginterval)) {
		char shortWait = (waitinginterval <= 60.0 ? 'T' : 'F');
		outputactualcontent
			<< eruptioninterval << ","
			<< waitinginterval << ","
			<< shortWait << '\n';

		sumeruptioninterval += eruptioninterval;
		sumwaitinginterval += waitinginterval;
		++trackercounting;


	}

	if (trackercounting > 0) {
		double averageruptioncalc = sumeruptioninterval / trackercounting;
		double averagewaitingcalc = sumwaitinginterval / trackercounting;
		cout << "Average eruption (in length): " << averageruptioncalc <<" " << "min. \n";
		cout << " ";
		cout << "Average eruption (in wait): " << averagewaitingcalc << " " << "min. \n";
		
	}
	else {
		cout << "Records not found.";
	}
	cout << "Writing a new CSV file called faithful_updated.csv.\n";
	
	return 0;

	// ^^displays the data if records not found then displays the "Records not found" text.

}
