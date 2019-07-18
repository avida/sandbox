#include <fstream>
#include <iostream>


int main()
{
   std::ifstream infile("fileio.cpp");
   std::string address;
   std::ofstream outfile ("out.txt");

   while (std::getline(infile, address ) )
   {
	outfile << address;	
	std::cout << address<<std::endl;
   }
 return 0;
}