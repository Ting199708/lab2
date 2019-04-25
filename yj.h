#include <iostream>
#include <string>

using namespace std;

class yj {

	public:
		double getBMI();
		string getCategory(double bmi);
		void get(string path);
                void set(string data);


	private:
		int height;
		int mass;
		string path;
};
