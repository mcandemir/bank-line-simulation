//Implementation file for Teller methods
#include <iostream>
#include "Teller.h"
#include "Customer.h"

Teller::Teller(int teller_number) {
	this->teller_number = teller_number;
}

Teller::Teller() {
	return;
}

int Teller::GetTasktTimeTotal() const {
	return task_time_total;
}

int Teller::GetTicket() const {
	return current_ticket;
}

int Teller::GetTellerNumber() const {
	return teller_number;
}

//if line is empty, get the task time immidiately
//add customer to the line and update current ticket and total task time of the teller
void Teller::NewCustomer(Customer customer) {
	if (customer_line.empty())
		task_time_current = customer.GetTaskTimeCustomer();
	customer_line.push_back(customer);
	current_ticket = customer.GetTicketNumber();
	task_time_total += customer.GetTaskTimeCustomer();
}

//pop the front customer and get the task time of new customer on the front
void Teller::NextCustomer() {
	if (!customer_line.empty())
		customer_line.pop_front();
	if (!customer_line.empty())
		task_time_current = customer_line.front().GetTaskTimeCustomer();
}

//reduce the task times as the time elapses
//if current cost time(current customer) is 0, go next customer
void Teller::TIME_ELAPSE_TELLER() {
	if (task_time_current) {
		task_time_current--;
		task_time_total--;
	}
	if (task_time_current == 0)
		NextCustomer();

}

//show the teller's customerline
void Teller::ShowLine() {
	std::cout << "T" << teller_number << ": ";
	for (std::list<Customer>::iterator it = customer_line.begin(); it != customer_line.end(); it++)
		std::cout << "(" << it->GetTicketNumber() << ") ";


	/*for (std::list<Customer>::iterator it = customer_line.begin(); it != customer_line.end(); it++) {
		it->ShowCustomer();
	}*/
}
