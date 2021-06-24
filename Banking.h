#ifndef BANKING_H
#define BANKING_H

using namespace std;

// Default constructor
// Declare class member functions and variables
// Initialize variables
class BalanceInterest {
public:
    BalanceInterest();
    int t_time = 0;
    double t_openingAmount = 0.0;
    double t_depositAmount = 0.0;
    double t_interestRate = 0.0;
    double getOpeningAmount();
    double getMonthlyDeposit();
    double getAnnualInterset();
    int getTimeLength();
    void setOpeningAmount(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setAnnualInterset (double t_annualInterest);
    void setTimeLength(int t_length);
    void printMonthlyDepositReport();
    void printNoMonthlyDepositReport();

private:
    double m_endInterest = 0.0;
    double m_endBalance = 0.0;
    double m_noDepBalance = 0.0;
    double m_noDepInterest = 0.0;
    double yearEndInterest(int a = 0);
    double yearEndBalance(int b = 0);
    double noDepdBalance(int c = 0);
    double noDepdInterest(int d = 0);
};
#endif

