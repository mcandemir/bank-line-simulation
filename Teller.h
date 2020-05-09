//Teller class definitions

#pragma once
#include <list>
#include "Customer.h"

//Tellers's attributes
class Teller {
private:
	std::list <Customer> customer_line;
	int task_time_total;
	int task_time_current;
	int current_ticket;
	int teller_number;
public:
	Teller(int teller_number);
	Teller();
	int GetTicket() const;
	int GetTasktTimeTotal() const;
	int GetTellerNumber() const;
	void NewCustomer(Customer customer);
	void NextCustomer();
	void TIME_ELAPSE_TELLER();
	void ShowLine();
};
