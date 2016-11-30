#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main() {
	string line;
	ifstream myfile;
	double avg_rmp = 0.0, avg_analysis = 0.0, avg_difference = 0.0; 
	double d_anal;
	int n = 0, cat_1 = 0, cat_2 = 0, cat_3 = 0, cat_4 = 0, cat_5 = 0;
	myfile.open("senti_results.txt");
	if(myfile) {
		while(getline(myfile, line)) {
			string rmp, analysis, difference;
			int index = 0;
			
			while(!isdigit(line.at(index)) && line.at(index) != '-') {
				++index;
			}
			
			while(index < line.size() && line.at(index) != ' ' &&
					line.at(index) != '\t') {
				rmp += line.at(index);
				++index;
			}
			avg_rmp += atof(rmp.c_str());

			while(!isdigit(line.at(index)) && line.at(index) != '-') {
				++index;
			}

			while(index < line.size() && line.at(index) != ' ' &&
					line.at(index) != '\t') {
				analysis += line.at(index);
				++index;
			}
			d_anal = atof(analysis.c_str());
			avg_analysis += d_anal;
			if(d_anal > -10.0 && d_anal < 0.0) {
				++cat_1;
			}
			else if(d_anal >= 0.0 && d_anal < 3.0) {
				++cat_2;
			}
			else if(d_anal >= 3.0 && d_anal < 6.0) {
				++cat_3;
			}
			else if(d_anal >= 6.0 && d_anal < 8.0) {
				++cat_4;
			}
			else if(d_anal >= 8.0) {
				++cat_5;
			}

			while(!isdigit(line.at(index)) && line.at(index) != '=') {
				++index;
			}

			while(index < line.size() && line.at(index) != ' ' &&
					line.at(index) != '\t') {
				difference += line.at(index);
				++index;
			}
			avg_difference += atof(difference.c_str());
			++n;
		}
	}
	cout << "Sample Size: " << n << endl;
	cout << "-10.0 - 0.0: " << cat_1 << endl;
	cout << "0.0 - 3.0: " << cat_2 << endl;
	cout << "3.0 - 6.0: " << cat_3 << endl;
	cout << "6.0 - 8.0: " << cat_4 << endl;
	cout << "8.0 - infinity: " << cat_5 << endl;
	cout << "Average RMP: " << avg_rmp / n << endl;
	cout << "Average Analysis: " << avg_analysis / n << endl;
	cout << "Average Difference: " << avg_difference / n << endl;

	return 0;
}
