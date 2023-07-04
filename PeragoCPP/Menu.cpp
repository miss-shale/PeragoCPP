#include "Menu.h"
using namespace System;
using namespace Aspose::Words;
//
//
void Menu::configureOptions()
{
	_options.clear();
	_optionHeadings.clear();

	_options[0]        = std::bind(&Menu::quit, this);
	_optionHeadings[0] = "Exit";
	_options[1]        = std::bind(&Menu::denominate, this);
	_optionHeadings[1] = "Denominate";
	_options[2]        = std::bind(&Menu::toPdf, this);
	_optionHeadings[2] = "ToPdf";

}


//
//
void Menu::print()
{
	system("CLS");

	std::cout << std::string(_heading.length(), '*') << std::endl;
	std::cout << _heading << std::endl;
	std::cout << std::string(_heading.length(), '*') << std::endl;

	std::cout << "Available options:" << std::endl;
	
	for (std::pair<int, std::function< void() > > option : _options)
	{
		std::cout << "\t" << option.first << "\t-\t" << _optionHeadings[option.first] << std::endl;
	}

	std::cout << std::string(_heading.length(), '*') << std::endl;
	std::cout << "Please make your selection: ";
}


//
//
int Menu::getInput()
{
	int input = 0;

	std::cin >> input;

	return input;
}


//
//
void Menu::processInput(int option)
{
	int chosenOption = option;

	while (_options.find(chosenOption) == _options.end())
	{
		std::cout << "No such option available.  Please retry: ";

		chosenOption = getInput();
	}

	_options[chosenOption]();
	//Log Chosen Option
	_logMessage += "Chosen Option: " + std::to_string(chosenOption) + "\n";
}
//
// 
std::string Menu::FormatDateForFileLog(std::string DateTime)
{
	std::string _logTimeStamp;
	std::string _Date;
	std::string _Time;
	std::vector <std::string> tokens;

	if (!DateTime.empty()) {
		int start = 0;
		do {
			// Find the index of occurrence
			int idx = DateTime.find(" ", start);
			if (idx == std::string::npos) {
				break;
			}

			// If found add the substring till that
			// occurrence in the vector
			int length = idx - start;
			tokens.push_back(DateTime.substr(start, length));
			start += (length + 1);
		} while (true);
		tokens.push_back(DateTime.substr(start));
	}
	_Date = std::string(tokens[3]) + std::string("_") + std::string(tokens[1]) + std::string("_") + std::string(tokens[5]) ;
	_Date.erase(remove(_Date.begin(), _Date.end(), '\n'), _Date.end());
	_Time = std::string("_") +std::string(tokens[4]);
	_Time.erase(remove(_Time.begin(), _Time.end(), ':'), _Time.end());
	_logTimeStamp = std::string(_Date) + std::string(_Time);
	return _logTimeStamp;
}
//
//
void Menu::Logger() 
{
	std::string filePath = "Log"+  std::string(".log");
	std::ofstream _ofs;
	_ofs.open(filePath.c_str()/**std::ios_base::out | std::ios_base::app*/);
	_ofs << '\t' << _logMessage << '\n';
	_ofs.close();
}
//
//
void Menu::quit()
{
	_quit = 1;
}
//
//
void Menu::toPdf()
{
	// Declaring argument for time()
	//time_t _tt;
	//// Applying time()
	//time(&_tt);
	//auto start = std::chrono::system_clock::now();
	//auto legacyStart = std::chrono::system_clock::to_time_t(start);
	//std::string _timestamp = FormatDateForFileLog(std::string(std::ctime(&legacyStart)));
	//std::string filePathPdf = "log_" + std::string(_timestamp) + std::string(".pdf");
	////Read from log file
	//std::string filePath = "Log" + std::string(".log");
	//std::ifstream _ifs;
	//_ifs.open(filePath.c_str()/**std::ios_base::out | std::ios_base::app*/);
	//std::string _str((std::istreambuf_iterator<char>(_ifs)),
	//std::istreambuf_iterator<char>());
	//_ifs.close();
	// 
	////// String for file name.
	//String filename(filePathPdf.c_str());
	//// Add text to new page
	//auto textFragment = MakeObject<TextFragment>(_str.c_str());

	////// Initialize document object
	//auto doc = MakeObject<Document>();
	//// Add page
	//auto pg = doc->get_Pages();
	//pg->idx_get(1);
	//pg->Add();
	///*
	//pg->get_Paragraphs()->Add(textFragment);
	//*/
	//// create TextBuilder object
	//auto textBuilder = MakeObject<TextBuilder>(pg);
	//// append the text fragment to the PDF page
	//textBuilder->AppendText(textFragment);

	////// Save updated PDF
	//String outputFileName = filename;

	//doc->Save(outputFileName);

	auto doc = MakeObject<Document>(u"Log.log");
	doc->Save(u"Log.pdf");

}
//
//
void Menu::denominate()
{
	//_denominate = 1;
	int						 _amount    = 0;
	int						 _denomSize = 0;
	std::vector<int>         _denominations;
	std::vector<Combination> _calculatedCombinations;
	std::cout << "Please enter an amount in cents: ";
	_amount= getInput();
	//Log entered amount
	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	_logMessage += std::ctime(&legacyStart) + std::string("Amount: " ) + std::to_string(_amount)+std::string("c") + "\n";
	std::cout << "   Amount: " << _amount << "c" << std::endl;
	//Get available denominations here?
	std::cout << "Please enter the number of different denominations available : ";
	_denomSize = getInput();
	// Log entered denomSize
	 start = std::chrono::system_clock::now();
	 legacyStart = std::chrono::system_clock::to_time_t(start);
	_logMessage += std::ctime(&legacyStart) + std::string(" Possible denominations: ") + std::to_string(_denomSize) + "\n";
	std::cout << "Please enter the "<< _denomSize<<" denominations available : "<< std::endl;

	for (int it = 0; it < _denomSize; it++)
	{
		
		_denominations.push_back(getInput());
	}
	//Log entered denominations
	_logMessage += std::string("Denominations: \n [");
	std::cout << "  Denominations: \n [";
	for (int i = 0; i < _denominations.size(); i++)
	{
		start = std::chrono::system_clock::now();
		legacyStart = std::chrono::system_clock::to_time_t(start);
		_logMessage += /*std::ctime(&legacyStart) + */std::to_string(_denominations[i]);
		std::cout << _denominations[i];
		//Do not print comma after the last item on the list
		if (i < _denominations.size() - 1)
		{
			_logMessage += std::string(",");
			std::cout << ",";
		}
	}
	_logMessage += std::string("] \n");
	std::cout << "]"<<std::endl;
	//Calculate Combinations
	_denominator.calculateCombinations(_amount, _denominations);
	//Print Combinations
	std::cout << "  Combinations: "<<std::endl;
	_calculatedCombinations =_denominator.getCombinations();
	// If _calculatedCombinations is empty, then
	if (_calculatedCombinations.size() == 0) 
	{
		start = std::chrono::system_clock::now();
		legacyStart = std::chrono::system_clock::to_time_t(start);
		std::cout << "Empty";
		_logMessage += std::ctime(&legacyStart) + std::string(" Empty");
		return;
	}
	// Log results heading
	
	_logMessage += std::string("Possible Combinations: \n");
	for (int i = 0; i < _calculatedCombinations.size(); i++) 
	{
		if (_calculatedCombinations[i].getCoinList().size() > 0) {
			for (int j = 0; j < _calculatedCombinations[i].getCoinList().size(); j++)
			{
				std::cout << _calculatedCombinations[i].getCoinList()[j] <<"c" ;
				// Log results 
				_logMessage += std::string(" ") + std::to_string(_calculatedCombinations[i].getCoinList()[j]) ;
				//Do not print comma after the last item on the list
				if (j < _calculatedCombinations[i].getCoinList().size() - 1)
				{
					std::cout << ",";
					_logMessage += ",";
				}
			}
			std::cout << std::endl;
			_logMessage += std::string("\n");
			//Wait 5 seconds before going back to main menu
			Sleep(5000);
		}
	}
	 
}
//
//
Menu::Menu()
{
	_heading    = "Perago's Default Menu";
	_quit       = 0;
	_logMessage = "";
	configureOptions();
}


//
//
Menu::Menu(std::string heading)
{
	_heading    = heading;
	_quit       = 0;
	_logMessage = "";
	configureOptions();
}


//
//
Menu::~Menu()
{
	// Empty for now
}


//
//
void Menu::run()
{

	do
	{
		print();
		processInput(getInput());
		Logger();
	} while ( _quit == 0 );
}