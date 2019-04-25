#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "yj.h"

using namespace std;

int main()
{
	yj yj1;

	//double bmi = yj1.getBMI();
	//cout << "bmi=" << bmi;
	//cout << " " << yj1.getCategory(bmi) << endl;
	ofstream outFile("file.out", ios::out);
	if(!outFile) {
		cerr << "Failed" << endl;
		exit(1);
	}

	//set the input file
        yj1.get("/home/tztmw/lab2-reference/file.in");


	return 0;
}
