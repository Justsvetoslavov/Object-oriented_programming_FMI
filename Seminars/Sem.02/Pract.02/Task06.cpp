#include <iostream>
#include <fstream>
#include <string>

void copyFile(const char *readFileName, const char *writeFileName)
{
   std::ifstream in(readFileName);
   std::ofstream out(writeFileName);

   if (!in.is_open() || !out.is_open())
   {
      std::cout << "Error";
      return;
   }

   std::string str;

   while (!in.eof())
   {
      str = "";
      std::getline(in, str);
      out << str << std::endl;
   }
   in.close();
   out.close();
}

int main()
{
   copyFile("Task06.cpp", "codeText.txt");

   return 0;
}