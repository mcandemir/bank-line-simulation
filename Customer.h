//Customer class definitions
#pragma once


//Customers's attributes
class Customer {
private:
	int task_time_customer;
	int ticket_number;
	int teller_number;
public:
	Customer(int TICKET);	//ticket will given by the SYSTEM, where the NEW_CUSTOMER method created
	int GetTaskTimeCustomer() const;
	int GetTicketNumber() const;
	int GetTellerNumber() const;

	void ShowCustomer() const;
};
