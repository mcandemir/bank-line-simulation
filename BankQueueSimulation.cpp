//Displaying of simulation will be 
//created and operated in main

#include <iostream>
#include <list>
#include <vector>
#include <time.h>
#include "Teller.h"
#include "Customer.h"
#include "SYSTEM.h"

int main() {
	srand(time(NULL));

	_SYSTEM_ system;


	while (1) {
		system.MENU();
	}

	return 0;
}
