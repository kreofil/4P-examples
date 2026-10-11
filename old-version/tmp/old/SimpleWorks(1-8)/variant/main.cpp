//------------------------------------------------------------------------------
// main.cpp - Формирование описания задания на лабораторную работу № 1 
// по Технологии программирования 
// Номер варианта задания задается параметром, указанным в командной строке
//------------------------------------------------------------------------------

#include <stdlib.h>
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	if(argc !=2)
	{
		cout << "Incorrect comman line. Necessary to do: "
			    "variant variant_number (from 1 to 648)" << endl;
		exit(1);
	}

	int num = atoi(argv[1]);
	if((num < 1)||(num > 648))
	{
		cout << "Incorrect variant number equal " << argv[1] << "." 
			 << endl
			 << "Necessary to do: variant variant_number (from 1 to 648)" 
			 << endl;
		exit(1);
	}

	cout << "Variant number = " << num << endl;
	
	int num_of_struct = (--num) % 3 + 1;
	num /= 3;
//	int num_of_module = (--num) % 3 + 1;
	int num_of_module = (num) % 3 + 1;
	num /= 3;
	int num_of_container = (num) % 6 + 1;
	num /= 6;
	int num_of_task = (num) % 12 + 1;


	cout << "Number of task = " << num_of_task << endl;
	cout << "Number of container = " << num_of_container << endl;
	cout << "Number of module organization = " << num_of_module << endl;
	cout << "Number of structure = " << num_of_struct << endl;
//	cout << "Last num = " << num << endl;

	return 0;
}
