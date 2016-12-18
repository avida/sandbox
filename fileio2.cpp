#include <fstream>
#include <iostream>

using namespace std;
class FileWriter{
 public:
   FileWriter(): prefix("out.txt"), bytes_written(0), suffix(1)
   {
      
   }
   FileWriter& operator<< (const string &str)
   {
      if(true)
      outfile << str;
      return *this;
   }
protected:
   ofstream outfile;
   string prefix;
   size_t bytes_written;
   int suffix;
   
};

int main()
{
   std::ifstream infile("fileio.cpp");
   std::string address;
   std::ofstream outfile;
   outfile.close ();
std::string oname = "out.txt";
   outfile.open (oname.c_str());
outfile << "hello\n";
outfile << "ho"<<std::endl;
   outfile.close ();
   outfile.open ("out1.txt");

   while (std::getline(infile, address ) )
   {
	outfile << address;	
	std::cout << address<<std::endl;
   }
 return 0;
}