// Paul Kenaga
// June 1, 2021
// Project Two

#include <iostream>
#include <limits>
#include <iomanip>
#include "Banking.h"
#include<conio.h>
#include <exception>

int main() {
	BalanceInterest newReport;  // Create new instance of class
	bool exit = false;	// Boolean variable allows user to exit program
	double startAmount; // User Input for new report
	double deposit;
	double interest;
	int years;
	int userInput = 0;
	
	// While loop prompts user for input, generates and prints report, then allows user to 
	// make another report or exit.
	while (!exit) {
		try {
			// Display border 
			std::cout << std::setfill('*') << std::setw(64) << "*" << std::endl;
			std::cout << "|" << std::right << std::setfill(' ') << std::setw(36) << "Data Input";
			std::cout << std::left << std::setfill(' ') << std::setw(26) << " " << "|" << std::endl;
			std::cout << std::setfill('*') << std::setw(64) << "*" << std::endl;

			// Call accessors to create new report 
			startAmount = newReport.getOpeningAmount();
			deposit = newReport.getMonthlyDeposit();
			interest = newReport.getAnnualInterset();
			years = newReport.getTimeLength();
		}
		// Accesors validate user input through try/throw/catch and displays appropriate error message 
		catch (char x) {
			system("cls");
			std::cout << "ERROR: Non-numerical value entered." << endl;
			std::cout << "Please enter only positive numerical values." << endl;
			cin.clear(); // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		catch (int y) {
			system("cls");
			std::cout << "ERROR: Negative value entered." << endl;
			std::cout << "Please enter only positive numerical values." << endl;
			cin.clear(); // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		// Once user input is validated call mutators to set class member variables
		newReport.setOpeningAmount(startAmount);
		newReport.setMonthlyDeposit(deposit);
		newReport.setAnnualInterset(interest);
		newReport.setTimeLength(years);

		// Clear screen before displaying report
		system("cls");

		// Call class functions to output reports w/ and w/o monthly deposit
		newReport.printMonthlyDepositReport();
		newReport.printNoMonthlyDepositReport();
		
		// While loop will ask user if they want to enter information for another report.
		// User can enter 1 to restart first while looop and make a new report.
		// User can eneter 2 to exit program; exit boolean becomes true.
		// Input is validated by try/throw/catch to make sure 1 or 2 is entered, otherwise user asked again. 
		while (userInput != 1 && userInput != 2) {
			try {
				std::cout << "Enter '1' to calculate another report or '2' to EXIT: ";
				cin >> userInput;

				if (userInput == 1) {
					userInput = 0;
					system("cls");
					break;
				}

				else if (userInput == 2) {
					exit = true;
					system("cls");
					break;
				}

				else {
					throw 1;
				}
			}
			catch (int z) {
				system("cls");
				std::cout << "ERROR: Please enter '1' or '2' only." << endl;
				cin.clear(); // Clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}

	// Program outputs goodbye message to confirm exit.
	std::cout << "Thank you for your time, goodbye." << endl << endl << endl;
}

