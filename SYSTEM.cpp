//implementation for SYSTEM.h
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include "SYSTEM.h"
#include "Teller.h"

using namespace std::this_thread;	//sleep_for, sleep_until
using namespace std::chrono;	//nanoseconds, seconds, system_clock

//returns a customer and increases next ticket 
Customer _SYSTEM_::NEW_CUSTOMER() {
	Customer customer(TICKET);
	this->TICKET++;
	return customer;
}

void _SYSTEM_::MENU() {
	while (1) {
		std::cout << "\n1-Set the number of tellers: " << AMOUNT_OF_TELLERS;
		std::cout << "\n2-Set delay (as seconds): " << DELAY;
		std::cout << "\n3-Possibility of customer appear: %" << POSSIBILITY_OF_CUSTOMER;
		std::cout << "\n4-Start simulation" << std::endl;


		int option;
		std::cin >> option;
		if (option == 1) {
			std::cout << "\n\tPlease enter the number of tellers: ";
			std::cin >> AMOUNT_OF_TELLERS;
		}
		else if (option == 2) {
			MENU_SET_DELAY();
		}
		else if (option == 3) {
			std::cout << "\n\tPlease enter the possibility of new customer: ";
			std::cin >> POSSIBILITY_OF_CUSTOMER;
		}
		else if (option == 4) {
			if (!AMOUNT_OF_TELLERS)
				std::cout << "\n***Please set the number of tellers\n" << std::endl;
			else if (!DELAY)
				std::cout << "\n***Please set delay" << std::endl;
			else
				SIMULATION_START();
		}
		else
			std::cout << "***Please enter a valid option" << std::endl;
	}
}

void _SYSTEM_::MENU_SET_DELAY() {
	while (1) {
		std::cout << "\n\t1-1 sec";
		std::cout << "\n\t2-2 sec";
		std::cout << "\n\t3-no delay" << std::endl;

		int option;
		std::cin >> option;
		if (option == 1) {
			DELAY = 1;
			break;
		}
		else if (option == 2) {
			DELAY = 2;
			break;
		}
		else if (option == 3) {
			DELAY = -1;
			break;
		}
		else
			std::cout << "***Please enter a valid option" << std::endl;
	}
}

//Create Tellers
void _SYSTEM_::CREATE_TELLERS(int AMOUNT_OF_TELLERS) {
	this->AMOUNT_OF_TELLERS = AMOUNT_OF_TELLERS;

	for (int i = 1; i <= AMOUNT_OF_TELLERS; i++) {
		Teller T(i);
		_TELLER_LIST_.push_back(T);
	}
}

//Show current Tellers(for testing)
void _SYSTEM_::SHOW_TELLERS() {
	for (std::vector<Teller>::iterator it = _TELLER_LIST_.begin(); it != _TELLER_LIST_.end(); it++) {
		std::cout << " T" << it->GetTellerNumber();
	}
}

//Display for the bank's clock
void _SYSTEM_::SHOW_CLOCK() {
	std::cout << "\t\t\t";

	if (SYSTEM_CLOCK_H == 24)
		SYSTEM_CLOCK_H = 0;

	if (SYSTEM_CLOCK_M == 60) {
		SYSTEM_CLOCK_M = 0;
		SYSTEM_CLOCK_H++;
	}

	if (SYSTEM_CLOCK_H < 10)
		std::cout << "0" << SYSTEM_CLOCK_H << ":";
	else
		std::cout << SYSTEM_CLOCK_H << ":";

	if (SYSTEM_CLOCK_M < 10)
		std::cout << "0" << SYSTEM_CLOCK_M << std::endl;
	else
		std::cout << SYSTEM_CLOCK_M << std::endl;
}

//Display of the tellers and their lines
void _SYSTEM_::SHOW_STATUS() {
	SHOW_CLOCK();

	for (std::vector<Teller>::iterator it = _TELLER_LIST_.begin(); it != _TELLER_LIST_.end(); it++) {
		it->ShowLine();
		std::cout << std::endl;
	}
	std::cout << "\n\n";
}

//Elapse 1 minute for all tellers and clock
void _SYSTEM_::TIME_ELAPSE() {
	for (std::vector<Teller>::iterator it = _TELLER_LIST_.begin(); it != _TELLER_LIST_.end(); it++) {
		it->TIME_ELAPSE_TELLER();
	}

	SYSTEM_CLOCK_M++;
}

void _SYSTEM_::SIMULATION_START() {
	CREATE_TELLERS(AMOUNT_OF_TELLERS);
	SHOW_STATUS();
	while (1) {
		sleep_for(seconds(DELAY));

		//1-Check tellers's total task time
		int min_task_time = 100;
		Teller* T = NULL;
		for (std::vector<Teller>::iterator it = _TELLER_LIST_.begin(); it != _TELLER_LIST_.end(); it++) {
			if (it->GetTasktTimeTotal() < min_task_time) {
				min_task_time = it->GetTasktTimeTotal();
				T = &(*it);
			}
		}

		//2-Direct the new customer to the
		//teller with the minimum task time
		int roll = rand() % 100 + 1;
		if (roll < POSSIBILITY_OF_CUSTOMER)
			T->NewCustomer(NEW_CUSTOMER());

		//3-Elapse the time
		TIME_ELAPSE();

		SHOW_STATUS();
	}
}
