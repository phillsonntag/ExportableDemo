// ExportableDemoConsumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

typedef int(__cdecl* p_externalProcedure)();

int main()
{
	HINSTANCE hGetProcIDDLL = LoadLibraryA("ExportableDemo.dll");
	
	if (!hGetProcIDDLL) {
		std::cout << "Unable to load the dynamic linked library" << std::endl;
		return EXIT_FAILURE;
	}

	const LPCSTR procedure_name = "ExternalProcedure";

	try
	{
		p_externalProcedure externalProcedure = (p_externalProcedure)GetProcAddress(hGetProcIDDLL, procedure_name);
		if (!externalProcedure) {
			std::cout << "Unable locate a procedure called \"" << procedure_name << "\"" << std::endl;
		}
		externalProcedure();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
