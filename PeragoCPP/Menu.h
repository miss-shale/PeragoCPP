#pragma once

#include "Entities/Denominator.h"
#include "../packages/Aspose.Words.Cpp.23.6.0/build/native/include/Aspose.Words.Cpp/Document.h";
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include<ctime>
#include <chrono>
#include<fstream>
#include<windows.h>


//
// Represents the menu, along with input
class Menu
{
private:
	std::string                              _heading;
	std::map< int, std::function< void() > > _options;
	std::map< int, std::string >             _optionHeadings;
	int                                      _quit;
	Denominator                              _denominator;
	std::string                              _logMessage;

	void configureOptions();
	void print();
	int  getInput();
	void processInput(int option);
	void quit();
	void denominate();
	void toPdf();
	void Logger();
	std::string FormatDateForFileLog(std::string DateTime);
public:
	//
	// Default constructor
	Menu();

	//
	// Constructor taking menu heading as parameter
	Menu(std::string heading);

	//
	// Destructor
	~Menu();

	//
	//
	void run();
};

