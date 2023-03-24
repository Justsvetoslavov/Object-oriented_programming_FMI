# Потоци и Файлове. Двоични файлове.

## Режими за работа с файлове

| Режим:| Ефект:                                                                      | 
|--------|------------------------------------------------------------------------------|
|ios::in |Отваря файл за четене  (по подразбиране на ifstream)                           |
|ios::out    |Отваря файл за четене (по подразбиране на ofstream)                        |
|ios::binary | Отваря файл в двоичен режим                                               |
|ios::trunc  | Ако файлът съществува,  съдържанието му се изтрива след отваряне на поток |
|ios::app    | Отваря файлът за вмъкване. Поставя put указателят в края. Не се допуска вмъкване преди края на потока      |
|ios::ate    | Отваря файлът за вмъкване. Поставя put указателят в края. Допуска вмъкване на прозиволни места                |
|ios::nocreate | Отваря за вмъкване, само ако файлът с указаното име съществува.|
ios::noreplace | Отваря за вмъкване само ако файлът с указаното име не съществува.|
### Пример:
 ```c++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream f("test.txt", ios::out | ios::app); //ios::out is by default

	if (!f.is_open()) {
		cout << "Error while opening file!" << endl;
		return 1;
	}
	f << 33; //appends at the end of the file

	f.close();
	return 0;
}
 ```
## Флагове на състоянията на потока 
| Флаг:| Значение:                                                                      | 
|--------|------------------------------------------------------------------------------|
|bad()   | Има загуба на информация. Някоя операция за четене и писане не е изпълнена. |
|fail() |Последната входно/изходна операция е невалидна.|
|good() | Всички операции са изпълнени успешно.|
|clear()| Изчиства състоянието на потока (Вече good() ще върне истина).|
| eof() | Достигнат е края на файла. |

## Позициониране във файл

 - tellg() - Връща позицития на текущия символ в **потока за четене**
 - tellp() - Връща позицития на текущия символ в **потока за писане**
 - seekg(offset, direction) - Премества get-указателят на позицията на **потока за четене**.
 - seekg(streampos idx) - Премества get-указателят на позицията idx на **потока за четене**.
 - seekp(offset, direction) - Премества put-указателят на позицията на **потока за писане**.
 - seekp(streampos idx) - Премества put-указателят на позицията idx на **потока за писане**.

-**offset** : целочислена стойност. Отместването от direction.
 
 -**direction** : Може да заема следите стойностти:

1. ios::beg - началото на файла.
2. ios::cur - текущата позиция във файла.
3. ios::end - края на файла.

## Двоични файлове.

Изпоилзваме функциите:

1. .read(char* memoryBlock, size_t size);
2. .write(const char* memoryBlock, size_t size);

Обърнете внимание, че функцията приема **char***. Ако искаме да запазим променлива от друг вид, ще трябва експлицитно да преобразуваме указателя към тип char* (без значение, че указателят не сочи към елементи от тип char)

### Примери за запазване на променливи във файл.

- запазване на променлива в двоичен файл:
```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream f("file.dat", std::ios::binary);

	int a = 155555;

	f.write((const char*)&a, sizeof(int));

	return 0;
}
```

- запазване на масив от примитивен тип в двоичен файл:
```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream ofs("myfile.dat", std::ios::out | std::ios::binary);
	
	int arr[5] = { 1,2,3,4,5 };

	ofs.write((const char*)arr, 5 * sizeof(int));

	ofs.close();

	return 0;
}

- пример за прочитане на данна от двоичен файл
 
```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream f("file.dat", std::ios::binary);

	if(!f.is_open()) {
		std::cout << "Could not open file\n";
		return 1;
	}

	int a;
	f.read((char*)&a, sizeof(int));

	std::cout << a << std::endl;

	return 0;
}
```

- пример за прочитане на масив(данни) от двоичен файл
```c++
#include <iostream>
#include <fstream>

size_t GetFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

int main()
{
	std::ifstream f("myfile.dat", std::ios::in | std::ios::binary);
	
	if(!f.is_open()) {
		std::cout << "Could not open file\n";
		return 1;
	}
	
	size_t fileSize = GetFileSize(f);
	size_t arrSize = fileSize / sizeof(int);
	int* arr = new int[arrSize];

	f.read((char*)arr, fileSize);

	for (size_t i = 0; i < arrSize; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	ifs.close();

	return 0;
}
```

### Съдържанието на двоичния файл:
 ![enter image description here](https://i.ibb.co/G3R72qG/sudurjanie.png "Binary file example")
 
Байтовете се записват в **обратна посока**. Най-старшият байт е последен. Следователно запаментеното число е **00025fa3**, което е точно шестнайсетичния запис на числото **155555**.
 
### Примери за запазване на структури във файл.
 
- писане/четене на структура, която не използва динамична памет, в/от двоичен файл.

```c++
#include <iostream>
#include <fstream>

using namespace std;

struct Test
{
	bool b;
	int x;
};

int main()
{
	{
		Test t = { true, 45 };
		ofstream file("testObj.bat", ios::binary);

		if (!file.is_open()) {
			return 1;
		}

		file.write((char*)&t, sizeof(t));
	}

	{
		Test t;
		ifstream file("testObj.bat", ios::binary);

		if (!file.is_open()) {
			return -1;
		}

		file.read((char*)&t, sizeof(t));
		std::cout << t.b << " " << t.x << std::endl;
	}
}
```

```c++
#include <iostream>
#include <fstream>

struct Test
{
 	char ch;
 	int a;
};

int main()
{
    std::ofstream f("output.dat", std::ios::binary);
    
    Test arr[3] = { {'a', 400}, {'b', 500}, {'c', 600} };
    
    f.write((const char*)&arr, sizeof(arr));
    
    f.close();
	return 0;
}
```
След изпълнението на програмата, файлът (**output.dat**) изглежда така:
![Image of the binary file after running the code](https://i.ibb.co/0JthLd6/3-A978-D14-7-C7-A-4-ABD-8-B0-C-DA27-F6-E9-CD0-A.png "Binary file")

- писане/четене на структура, която използва динамична памет, в/от двоичен файл.
```c++
struct Test
{
	char* name;
	double nmuber;
};

Test CreateObject(const char* name, int number)
{
	Test obj;

	size_t nameLen = strlen(name);
	obj.name = new char[nameLen + 1];
	strcpy(obj.name, name);

	obj.number = number;

	return obj;
}

void SaveTestToFile(std::ofstream& f, const Test& obj)
{
	size_t nameLen = strlen(obj.name);

	f.write((const char*)&nameLen, sizeof(size_t));  //first we write the size of the name!
	f.write(obj.name, nameLen);

	f.write((const char*)&obj.number, sizeof(double));
}

Test ReadTestFromFile(std::ifstream& f)
{
	Test obj;
	size_t nameLen;

	f.read((char*)&nameLen, sizeof(nameLen)); //first we read the size of the name!

	obj.name = new char[nameLen + 1];
	f.read(obj.name, nameLen);
	obj.name[nameLen] = '\0';

	f.read((char*)&obj.number, sizeof(double));

	return obj;
}

void Free(Test& obj)
{
	delete[] obj.name;
	obj.number = NULL;
}

void Print(const Test& obj)
{
	std::cout << obj.name << " " << obj.number << "\n";
}

int main()
{
	{
		Test obj1 = CreateObject("Ivana", 11.1);
		Test obj2 = CreateObject("Petur", 22.2);

		std::ofstream fWrite("uni.dat", std::ios::binary);

		if (!f3.is_open()) {
			std::cout << "Error" << std::endl;
			return 1;
		}

		SaveTestToFile(fWrite, obj1);
		SaveTestToFile(fWrite, obj2);

		Free(obj1);
		Free(obj2);
	}

	{
		std::ifstream fRead("uni.dat", std::ios::binary);

		if (!f2.is_open()) {
			std::cout << "Error" << std::endl;
			return 1;
		}
		
		Test obj3 = ReadTestFromFile(fRead);
		Test obj4 = ReadTestFromFile(fRead);

		Print(obj3);
		Print(obj4);

		Free(obj3);
		Free(obj4);
	}
}
```

## Задачи

**Задача 1:** Да се напишат програми, които запазват/четат масиви от обекти, които не използват динамична памет.

**Задача 2:** Да се напише функция, която намира големината на файл.

**Задача 3:** Да се напише функция, която заменя всяко срещане на символ във файл с друг символ. <br />
              Съдържанието на файла не трябва да се зарежда в паметта.

**Задача 4**: 

Да се реализира програма за изглед и модификация на двоични файлове (hex viewer). При стартиране на програмата трябва да се въведе път до двоичен файл и да зареди съдържанието на файла в паметта. След като файлът се е заредил в паметта, трябва да поддържате следните операции:
 
 - Преглед на файла (view)  отпечатва байтовете на файла (в шестнайсетична бройна система). След това да се отпечатат интерпретацията на байтовете като символи. Ако байтът отговаря на малка/голяма латинска буква, то да се отпечата символа. В противен случай да се отпечатва точка.  
 -  Промяна на байт по индекс (change ). 
 -  Премахване на последния байт (remove) 
 -  Добавяне на байт в края (add ). 
 -  Запазване на промените в същия файл (save) 
 -  Запазване на промените в друг файл (save as )

Нека имаме двоичен файл, myData.dat, който се е получил след изпълнението на следния c++ код: 
 ```c++
int x = 25409;
ofstream file(“myData.dat”, std::ios::binary);
file.write( (const char*)&x, sizeof(x));
```

Да се реализира прост интерфейс, с който да се извикват написаните фунцкии през конзолата.

**Важно** Не се ползволява използването на stl, както и std::hex.

**Пример** (входът от потребителя започва с '>'):

 ```
Enter a file path:
> myData.dat
File loaded successfully! Size: 4 bytes 
> view
41 63 00 00
A  c  .  . 
>change 1 65 
Operation successfully executed!
> view 
41 65 00 00 
A  e  .  . 
> remove 
> view
 41 65 00 
 A  e   . 
 >save 
 File successfully saved
```

**Забележка:** Не се изисква поддържането на конзолен интерфейс. Можете само да реализирате функциите и да ги изпробвате в main функцията. 
