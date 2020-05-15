#include "evaluator.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::queue;
using std::setw;
using std::fixed;
using std::setprecision;

int main(int argc, char* argv[]){
	string tests[] = {
		"2 14 + 1 5 + *", // 96
		"2 5 ^ 5 +", // 37
		"4 + 5", // Error
		"2 3 ^ 3 * 21 3 / +", // 31
		"15 2 /", // 7.5
		"100 90 - 5 3 - /", // 5
		"10 5 - 2 * 4 3 ^ 2 3 / / +", //106
		"10 5+", // error
		"some", // error
		"2 2 + 4 + 5 * 30 - 5 * 25 /", // 2
		"4 5 10 3 - * +" // 39
	};

	string correctResults[] ={
			"96",
			"37",
			"E",
			"31",
			"7.5",
			"5",
			"106",
			"E",
			"E",
			"2",
			"39"
	};

	string extraCredit[] = {
		"2.5 2 *",
		"2.7172 3.0 ^ 3.1415954 /",
		"1.2 5 * 0.75 0.75 + /"
	};

	string extraCreditResults[] = {
			"5",
			"6.385789014221246",
			"4"
	};


	bool error;
	double grade = 0;
	const size_t TOTAL_TESTS = sizeof(tests)/sizeof(string);
	cout << "Normal Tests: " << endl;
	cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
	for (size_t i = 0; i < TOTAL_TESTS; i++) {

		double result = Evaluate(tests[i], error);
		if (error && correctResults[i] == "E"){
			grade++;
			cerr << " * * * * There was an error  * * * * \t" << tests[i]
				 << "\t" << fixed << setprecision(2) << (grade / TOTAL_TESTS * 100)  << endl;
		}else if (!error && stod(correctResults[i]) == result){
			grade++;
			cout << setw(37) << tests[i] << " = " << setw(5) << result
				 << "\t" << fixed << setprecision(2) << (grade / TOTAL_TESTS * 100) << endl;
		}else{
			cout << "Test " << (i + 1) << " Failed" << endl;
		}
	}
	cout << "Unit Tests Grade: " << fixed << setprecision(2) << (grade / TOTAL_TESTS * 100) << endl;


	double xGrade = 0;
	const size_t XTOTAL_TESTS = sizeof(extraCredit)/sizeof(string);
	cout << "Extra Credit Tests: " << endl;
	cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
	for (size_t i = 0; i < XTOTAL_TESTS; i++) {

		double result = Evaluate(extraCredit[i], error);
		if (error && extraCreditResults[i] == "E"){
			xGrade++;
			cerr << " * * * * There was an error  * * * * \t" << extraCredit[i]
				 << "\t" << fixed << setprecision(2) << (xGrade / XTOTAL_TESTS * 100)  << endl;
		}else if (!error && abs(stod(extraCreditResults[i]) - result) < 0.000001){
			xGrade++;
			cout << setw(37) << extraCredit[i] << " = " << setw(5) << result
				 << "\t" << fixed << setprecision(2) << (xGrade / XTOTAL_TESTS * 100) << endl;
		}else{
			cout << "Test " << (i + 1) << " Failed" << endl;
		}
	}
	cout << "Extra Credit Unit Tests Grade: " << fixed << setprecision(2) << (xGrade / XTOTAL_TESTS * 100 * 0.3) << endl;

	cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl << endl << endl;
	cout << "Unit Tests Final Grade: " << endl;
	cout << "Normal Test:  " << setw(6) << fixed << setprecision(2) << (grade / TOTAL_TESTS * 100) << endl;
	cout << "Extra Credit: " << setw(6) << fixed << setprecision(2) << (xGrade / XTOTAL_TESTS * 100 * 0.3) << endl;
	cout << endl;
	cout << "Total:        " << setw(6) << fixed << setprecision(2) << ((grade / TOTAL_TESTS * 100 * 0.3) + (xGrade / XTOTAL_TESTS * 100)) << endl;



	return 0;
}
