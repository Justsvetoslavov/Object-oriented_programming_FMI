#include <iostream>
#include <fstream>

void writeFile(const char *fileName)
{
   std::ofstream out("result.txt");

   if (!out.is_open())
   {
      std::cout << "Can't open the file\n";
      return;
   }
   int num1, num2, num3, sum, prod;
   std::cout << "Input numbers\n";
   std::cin >> num1 >> num2 >> num3;
   sum = num1 + num2 + num3;
   prod = num1 * num2 * num3;

   if (out.is_open())
   {
      out << sum << "\n"
          << prod;
   }
   out.close();
}

int readFile(const char *fileName)
{
   std::ifstream in("result.txt");
   int sum, prod;

   if (!in.is_open())
   {
      return -1;
   }
   else
   {
      in >> sum >> prod;
      return prod - sum;
   }
   in.close();
}

int main()
{
   writeFile("result.txt");
   std::cout << readFile("result.txt");
   return 0;
}