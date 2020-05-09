//Implementation file for Customer methods
#include <iostream>
#include "Customer.h"
#include <stdlib.h>		//srand, rand


//initialize customer and fill it's attributes
Customer::Customer(int TICKET) {
	ticket_number = TICKET;
	task_time_customer = rand() % 22 + 8;	//average task time of the customer is between 29-8 minutes
}

//Functions for testing
int Customer::GetTaskTimeCustomer() const {
	return task_time_customer;
}

int Customer::GetTicketNumber() const {
	return ticket_number;
}

int Customer::GetTellerNumber() const {
	return teller_number;
}

void Customer::ShowCustomer() const {
	std::cout << "Customer Task Time:" << task_time_customer << std::endl;
	std::cout << "Customer Ticket   :" << ticket_number << std::endl;
	std::cout << "Customer Teller   :" << teller_number << std::endl;
	std::cout << "\n\n";
}
