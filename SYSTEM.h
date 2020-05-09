//System class definition

#pragma once
#include <vector>
#include "Customer.h"
#include "Teller.h"


class _SYSTEM_ {
private:
	int TICKET = 300;	//first ticket
	int AMOUNT_OF_TELLERS = 4;
	std::vector<Teller> _TELLER_LIST_;
	int SYSTEM_CLOCK_H = 0, SYSTEM_CLOCK_M = 0;
	int DELAY = 1; //speed of the time
	int POSSIBILITY_OF_CUSTOMER = 20;
public:
	Customer NEW_CUSTOMER();	//when a new customer created, a ticket will be given too
	void MENU();
	void CREATE_TELLERS(int AMOUNT_OF_TELLERS);
	void SHOW_TELLERS();
	void SHOW_STATUS();	//shows all the tellers and their customer list
	void SHOW_CLOCK();
	void TIME_ELAPSE();
	void SIMULATION_START();
	void MENU_SET_DELAY();
};
