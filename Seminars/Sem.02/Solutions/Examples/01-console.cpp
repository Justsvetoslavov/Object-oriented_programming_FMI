#include <iostream>

void NewLineError()
{
	int a;
	std::cin >> a;

	char arr[10];
	//std::cin >> arr;
	//std::cin.ignore();
	std::cin.getline(arr, 10);

	std::cout << a << " " << arr;
}

void InfiniteLoop()
{
	char c;
	std::cin.putback('a');
	while (std::cin >> c) {
		std::cout << c;
		std::cin.putback(c);
	}
}

void GetAndPutbackExamples()
{
	{
		//Example 1 - get function
		char ch1, ch2;
		std::cin.get(ch1);
		std::cin.get(ch2);
		std::cout << ch1 << " " << ch2 << std::endl;
	}

	{
		//Example 2 - putback
		char c;
		std::cin.putback('a');
		std::cin.get(c);
		std::cout << c;
	}

	{
		// Above stream buffer is not cleared
		std::cin.clear(); // clear stream buffer for last example
		char ch1, ch2;
		ch1 = std::cin.peek(); 
		std::cin.get(ch2);
		std::cin.putback('d');
		std::cin.get(ch2);
	}
}

void ReadExample()
{
	char c;
	std::cin.putback('a').putback('b');
	char info[3] = { '\0' };
	std::cin.read(info, 2);
	std::cout << info;
}