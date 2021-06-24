#include <iostream>
#include <iomanip>
#include <math.h>
#include "Banking.h"

// Default constructor
BalanceInterest::BalanceInterest() {}

// Accessor gets initial investment, validates input.
double BalanceInterest::getOpeningAmount() {
	std::cout << "Enter Initial Investment Amount: $";
	cin >> t_openingAmount;
	if (!t_openingAmount) {
		throw 'x';
	}
	if (t_openingAmount < 0) {
		throw 0;
	}
	return t_openingAmount;
}

// Accessor gets monthly deposit, validates input.
double BalanceInterest::getMonthlyDeposit() {
	std::cout << "Enter Monthly Deposit: $";
	cin >> t_depositAmount;
	if (!t_depositAmount) {
		throw 'x';
	}
	if (t_depositAmount < 0) {
		throw 0;
	}
	return t_depositAmount;
}

// Accessor gets annual interest, validates input.
double BalanceInterest::getAnnualInterset() {
	std::cout << "Enter Annual Interest: %";
	cin >> t_interestRate;
	if (!t_interestRate) {
		throw 'x';
	}
	if (t_interestRate < 0) {
		throw 0;
	}
	return t_interestRate;
}

// Accessor gets investment time length, validates input.
int BalanceInterest::getTimeLength() {
	std::cout << "Enter Number of Years: ";
	cin >> t_time;
	if (!t_time) {
		throw 'x';
	}
	if (t_time < 0) {
		throw 0;
	}
	return t_time;
}

// Mutator sets initial investment.
void BalanceInterest::setOpeningAmount(double t_initialInvestment) {
	t_openingAmount = t_initialInvestment;
}

// Mutator sets monthly deposit.
void BalanceInterest::setMonthlyDeposit(double t_monthlyDeposit) {
	t_depositAmount = t_monthlyDeposit;
}
// Mutator sets annual interest.
void BalanceInterest::setAnnualInterset(double t_annualInterest) {
	t_interestRate = t_annualInterest / 100;
}

// Mutator sets investment time.
void BalanceInterest::setTimeLength(int t_length) {
	t_time = t_length;
}

// Member function calculates year end interest w/ monthly deposit.
double BalanceInterest::yearEndInterest(int a) {
	m_endInterest = ((yearEndBalance(a) - 1 - (t_depositAmount * (static_cast<__int64>(t_time) * 12))) - ((yearEndBalance(a - 1) - 1 - (t_depositAmount * ((static_cast<__int64>(t_time) - 1) * 12)))));
	return m_endInterest;
}

// Member function calculates year end balance w/ monthly deposit.
double BalanceInterest::yearEndBalance(int b) {
	 m_endBalance = (t_openingAmount * pow(1 + (t_interestRate / 12), 12 * b)) + (t_depositAmount * (((pow(1 + (t_interestRate / 12), 12 * b) - 1)) / (t_interestRate / 12)) * (1 + ((t_interestRate / 12))));
	return m_endBalance;
}

// Member function calculates year end interest w/o monthly deposit.
double BalanceInterest::noDepdBalance(int c) {
	m_noDepBalance = (t_openingAmount * pow(1 + (t_interestRate / 12), 12 * c));
	return m_noDepBalance;
}

// Member function calculates year end balance w/ monthly deposit.
double BalanceInterest::noDepdInterest(int d) {
	m_noDepInterest = ((noDepdBalance(d) - t_openingAmount) - (noDepdBalance(d - 1) - t_openingAmount));
	return m_noDepInterest;
}

// Member function prints year end balance and interest w/ monthly deposit. 
void BalanceInterest::printMonthlyDepositReport() {
	std::cout << std::setw(59) << std::setfill(' ') << std::right;
	std::cout << "Balance and Interest With Additional Monthly Deposits" << std::endl;
	std::cout << std::setfill('=') << std::setw(64) << "=" << std::endl;
	std::cout << std::setw(13) << std::left << std::setfill(' ') << "  Year";
	std::cout << std::setw(32) << std::left << std::setfill(' ') << "Year End Earned Interest";
	std::cout << "Year End Balance" << std::endl;
	std::cout << std::setfill('-') << std::setw(64) << "-" << std::endl;

	for (int y = 1; y <= t_time; y++) {
		cout << "   ";
		std::cout << std::setw(18) << std::left << std::setfill(' ') << std::fixed << std::setprecision(2) << y;
		std::cout << "$" << std::setw(27) << std::left << yearEndInterest(y);
		std::cout << "$" << yearEndBalance(y);
		cout << endl;
	}
	cout << endl << endl;
}

// Member function prints year end balance and interest w/o monthly deposit.
void BalanceInterest::printNoMonthlyDepositReport() {
	std::cout << std::right << std::setw(60) << "Balance and Interest Without Additional Monthly Deposits" << std::endl;
	std::cout << std::setfill('=') << std::setw(64) << "=" << std::endl;
	std::cout << std::setw(13) << std::left << std::setfill(' ') << "  Year";
	std::cout << std::setw(32) << std::left << std::setfill(' ') << "Year End Earned Interest";
	std::cout << "Year End Balance" << std::endl;
	std::cout << std::setfill('-') << std::setw(64) << "-" << std::endl;

	for (int y = 1; y <= t_time; y++) {
		cout << "   ";
		std::cout << std::setw(18) << std::left << std::setfill(' ') << std::fixed << std::setprecision(2) << y;
		std::cout << "$" << std::setw(27) << std::left << noDepdInterest(y);
		std::cout << "$" << noDepdBalance(y);
		cout << endl;
	}
	cout << endl << endl;
}


