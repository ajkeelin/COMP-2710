/*
*Austin Keelin
*ajk0033
*hw2.cpp
*Compiled using g++ compiler
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double loan_amount, interest_rate, monthly_payments,
			interest, principal, total_interest, rate;
         
   cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
         
	cout << "Loan Amount: ";
	cin >> loan_amount;
	cout << "Interest Rate (% per year): ";
	cin >> interest_rate;
	cout << "Monthly Payments: ";
	cin >> monthly_payments;
   
   if (monthly_payments <= ((interest_rate / 12) * loan_amount) / 100) {
      cout << "\nRegular payments must be larger than monthly interest\n";
      return 0;
   }   

	cout << "*********************************************************************";
	cout << "\n\tAmortization Table";
	cout << "\n*********************************************************************";

	double balance = loan_amount;
	int month = 0;
	cout << "\nMonth\tBalance\t\tPayment\tRate\tInterest\tPrincipal";
	cout << "\n" << month << "\t$" << balance << "\tN/A\tN/A\tN/A\t\tN/A";

	while (balance > 0) {
		++month;
		rate = interest_rate / 12;
		interest = (balance * rate) / 100;
		principal = monthly_payments - interest;
		balance = balance - principal;
      total_interest += interest;
      
      if (balance <= 0) {
         principal = balance + principal;
         monthly_payments = principal + interest;
         balance = 0;
      }   

		cout << "\n" << month; 
      cout << "\t$" << balance; 
      cout << "\t\t$" << monthly_payments;
		cout << "\t" << rate;
      cout << "\t$" << interest; 
      cout << "\t\t$" << principal;
   }   
      
   cout << "\n*********************************************************************";
   cout << "\n\nIt takes " << month << " months to pay off the loan.";
   cout << "\nTotal interest paid is: $" << total_interest << "\n";
	

	return 0;
}

