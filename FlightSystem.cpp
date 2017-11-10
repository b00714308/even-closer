/*
* FlightSystem.cpp
* Version information v0.1
* Author: Matthew Webster b00714308
*/
#include <iostream>
#include <string>
#include <vector>
#include "Aircraft.h"
#include "FlightSystem.h"


void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, std::string gridReference, int groundspeed, int altitude, int heading) {
	
	bool isThere = false;
	
	aircraftList_;
	Aircraft aircraft1(flightNumber, airline, aircraftType, gridReference, groundspeed, altitude, heading);		

	for (int i = 0; i < aircraftList_.size(); i++) {
		if (flightNumber == aircraftList_.at(i).GetFlightNumber())
		{
			isThere = true;
		}
	}
	if (isThere == false) 
	{
		aircraftList_.push_back(aircraft1);
		std::cout << "You have successfully added an aircraft!" << std::endl;
	}
	else 
	{
		std::cout << "Flight " << flightNumber << " already in the system";		
	}

	}
std::vector<Aircraft> FlightSystem::ListAllAircraft()
{	
	return aircraftList_;
}
std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft() {
	aircraftList_;

	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetAltitude() >= 30000)
		{
			std::cout << aircraftList_.at(i).GetFlightNumber() << "\t\t" 
				<< aircraftList_.at(i).GetAirline() << "\t\t" 
				<< aircraftList_.at(i).GetAltitude() << "\t\t"
				<< aircraftList_.at(i).GetGroundSpeed() << "\t\t" 
				<< aircraftList_.at(i).GetGridReference() << "\t\t" 
				<< aircraftList_.at(i).GetHeading() << std::endl;
		}
	}

	return aircraftList_;
}
void FlightSystem::RemoveAircraft(std::string flightNumber) {
	
	bool isThere = false;
	
	aircraftList_;

	std::cout << "Please enter flightnumber" << std::endl;
	std::cin >> flightNumber;
	for (int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber)
		{
			isThere = true;
			aircraftList_.erase(aircraftList_.begin() + i);
			std::cout << "Flight " << flightNumber << " has been removed from the system\n" << std::endl;			
		}
		if (isThere == false)
		{
			std::cout << "Flight " << flightNumber << " is not in the system\n" << std::endl;			
		}
	}

}
void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {
	bool exist = false;
	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			exist = true;
			aircraftList_.at(i).SetHeading(heading);
			std::cout << "Heading of flight " << flightNumber << " changed to " << heading << std::endl;
			break;
		}
	}
	if (exist == false)
	{
		std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
	}
}
int FlightSystem::GetHeading(std::string flightNumber) {
	bool exist = false;
	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			exist = true;
			return aircraftList_.at(i).GetHeading();
		}
	}	
}
void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude) {
	bool exist = false;
	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			exist = true;
			aircraftList_.at(i).SetAltitude(altitude);
			std::cout << "Heading of flight " << flightNumber << " changed to " << altitude << std::endl;
			break;

		}
	}
	if (exist == false)
	{
		std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
	}
}
int FlightSystem::GetAltitude(std::string flightNumber) {
	bool exist = false;
	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			exist = true;
			return aircraftList_.at(i).GetAltitude();
		}
	}
}

int FlightSystem::numAircraftInSector() {
	
	return 0;
}