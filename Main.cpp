/*
* Main.cpp
* Version information v0.1
* Author: Matthew Webster b00714308
*/

#include <iostream>
#include <string>
#include <vector>
#include "regex"
#include "FlightSystem.h"

using namespace std;

int main() {

	FlightSystem aircraft1;	
	int answer;
	
		
	do {
		std::cout << "\n--------------------------------------------------\n" << endl;
		std::cout << "Please Choose what you would like to do" << endl;
		std::cout << "1: Add an aircraft to the system" << endl;
		std::cout << "2. List all aircraft on the system" << endl;
		std::cout << "3. List all cruising aircraft in the system" << endl;
		std::cout << "4. Change heading of an aircraft in the system" << endl;
		std::cout << "5. Change altitude of an aircraft in the system" << endl;	
		std::cout << "6. Remove an aircraft from the system" << endl;
		std::cout << "7. Close the application" << endl;
		
		std::string flightNumber_;
		std::string airline_;
		std::string aircraftType_;
		std::string gridReference_;
		int groundspeed_;
		int altitude_;
		int heading_;
		
		bool menu = true;
		
		if (menu)
		{
						
			std::cin >> answer;
			switch (answer) {
			case 1:
			{
				std::cout << "Add an aircraft to the system\n" << endl;
				std::cout << "Please Enter Flight Number" << endl;
				std::cin >> flightNumber_;
				std::cout << "Please enter Airline" << endl;
				std::cin >> airline_;
				std::cout << "Please enter Aircraft Type" << endl;
				std::cin >> aircraftType_;
				std::cout << "Please enter Grid Reference" << endl;
				std::cin >> gridReference_;
				std::cout << "Please enter Groundspeed" << endl;
				std::cin >> groundspeed_;
				std::cout << "Please enter Altitude" << endl;
				std::cin >> altitude_;
				std::cout << "Please enter Heading" << endl;
				std::cin >> heading_;

				//add object to vector

				aircraft1.AddAircraft(flightNumber_, airline_, aircraftType_ ,gridReference_, groundspeed_, altitude_, heading_);
			}
			break;

			case 2:
			{
				std::cout << "Flight Number:\tAirline:\tAircraft Type:\tGrid Reference:\tGround Speed:\tAltitude:\tHeading:" << endl;
				std::vector<Aircraft>temporary;
				temporary = aircraft1.ListAllAircraft();
				for (int i = 0; i < temporary.size(); i++) {
					std::cout << temporary[i].GetFlightNumber()
						<< "\t\t" << temporary[i].GetAirline()
						<< "\t\t" << temporary[i].GetAircraftType()
						<< "\t\t" << temporary[i].GetGridReference()
						<< "\t\t" << temporary[i].GetGroundSpeed()
						<< "\t\t" << temporary[i].GetAltitude()
						<< "\t\t" << temporary[i].GetHeading();
				}

			}
			break;
			{
			case 3: std:cout << "Cruising aircraft in the system\n" << endl;
				std::cout << "Flight Number:\tAirline:\tAircraft Type:\tGrid Reference:\tGround Speed:\tAltitude:\tHeading:" << endl;
				std::vector<Aircraft>temporary;
				temporary = aircraft1.ListAllCruisingAircraft();
			}
			break;
			{
			case 4: std::cout << "Enter a flight number to change the heading of an aircraft in the system\n" << endl;
				aircraft1.ChangeHeading(flightNumber_);
				std::cin >> flightNumber_;
				std::cout << "Enter the new heading for this aircraft" << endl;
				aircraft1.GetHeading(flightNumber_);								
				std::cin >> heading_;				
				
				
			}
			break;
			{
			case 5: std::cout << "Enter a flight number to change the altitude of an aircraft in the system\n" << endl;
				aircraft1.GetHeading(flightNumber_);
				aircraft1.ChangeHeading(flightNumber_, altitude_);
				std::cout << "Enter the new altitude for this aircraft" << endl;
				std::cin >> altitude_;
			}
			break;
			{
			case 6: std::cout << "Remove an aircraft from the system\n" << endl;
				aircraft1.RemoveAircraft(flightNumber_);				
			}
			break;
			{
			case 7: std::cout << "Closing application" << endl;

			}
			}
		}
	} while (answer != 7);
	return 0;
}