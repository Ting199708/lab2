#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "yj.h"

using namespace std;

double yj::getBMI() {
	double bmi;

	bmi = mass / pow(height / 100.0 , 2);

	return bmi;
}

string yj::getCategory(double bmi) {
	if (bmi < 15)
        {
                return "Very severely underweight";
        }
        else if (bmi >= 15 && bmi < 16)
        {
                return "Serverly underweight";
        }
        else if (bmi >= 16 && bmi < 18.5)
        {
                return "Underweight";
        }
        else if (bmi >= 18.5 && bmi < 25)
        {
                return "Normal";
        }
        else if (bmi >= 25 && bmi < 30)
        {
                return "Overweight";
        }
        else if (bmi >= 30 && bmi < 35)
        {
                return "Obese Class I(Moderately obese)";
        }
        else if (bmi >= 35 && bmi < 40)
        {
                return "Obese Class II(Severely obese)";
        }
        else
        {
                return "Obese Class III(Very severely obese)";
        }
}

void yj::set(string data) {
	
	ofstream outFile("file.out", ios::app);
	if(!outFile) {
		cerr << "Failed" << endl;
		exit(1);
	}
	int pos = data.find_first_of(" ", 0);
        height = stoi(data.substr(0,pos));
        mass = stoi(data.substr(pos, data.length()));

	double bmi = getBMI();
	string category = getCategory(bmi);
	
	outFile << fixed << setprecision(2) << height << "\t" << mass << "\t" << bmi << "\t" << category << endl;

}


void yj::get(string path) {
	string headline;

	ifstream inFile(path, ios::in);
	if(!inFile) {
		cerr << "Failed opening" << endl;
		exit(1);
	}
	getline(inFile, headline);
	while(headline != "0 0") {
		set(headline);
		getline(inFile, headline);
	}

}
