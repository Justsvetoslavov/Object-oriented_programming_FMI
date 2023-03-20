#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;


const int MAX_NAME_LENGTH = 20;
const int CONDITION_LENGTH = 50;
const int  NUMBER_OF_TASKS = 10;
const int NUM_TASKS = 3;
const int MIN_PASS_GRADE = 60;

class Task {
private:
	char name[MAX_NAME_LENGTH];
	char condition[CONDITION_LENGTH];
	int points;
public:
	Task():name{}, condition{}, points{} {}
	Task(const char* name, const char* condition, int points) {
		setName(name);
		setCondition(condition);
		setPoints(points);
	}
	const char* getName()const {
		return name;
	}
	const char* getCondition()const {
		return condition;
	}
	int getPoints()const {
		return points;
	}

	void setName(const char name[]) {
		int index = 0;
		while (index != '\0') {
			this->name[index] = name[index];
			index++;
		}
		this->name[index] = '\0';
	}
	void setCondition(const char condition[]) {
		int index = 0;
		while (index != '\0') {
			this->condition[index] = condition[index];
			index++;
		}
		this->condition[index] = '\0';
	}
	void setPoints(int points) {
		if (points >= 0) {
			this->points = points;
		}
	}
	void changeName(const char name[]) {
		setName(name);
	}
	void changeCondition(const char condition[]) {
		setCondition(condition);

	}
	void changePoints(int points) {
		setPoints(points);
	}
};
class Exam {
private:
	Task tasks[NUMBER_OF_TASKS];
	int numOfTasks;
	int minPoints;

public:
	Exam(const Task tasks[], int minPoints, int numOfTasks) {
		setTasks(tasks, numOfTasks);
		setMinPoints(minPoints);

	}

	void setTasks(const Task tasks[], int numOfTasks){

		if (numOfTasks >= 0) {
			this ->numOfTasks = numOfTasks;
		}
		
		for (int i = 0; i < numOfTasks; i++) {
			this->tasks[i] = tasks[i];
		}

     }
	void setMinPoints(int minPoints) {
		if (minPoints >= 0) {
			this->minPoints = minPoints;
		}
	}
	void changeMinPoints(int minPoints) {
		setMinPoints(minPoints);
	}
	int getMinPoints()const {
		return minPoints;
	}
	
	int getMaxPoints()const {
		int maxPoints = 0;
		for (int i = 0; i < numOfTasks; i++) {
			maxPoints += tasks[i].getPoints();
		}
		return maxPoints;

	}


	void writeToFile(const char* filename)const {
		std::ofstream file(filename,std:: ios::out |std:: ios::binary);

		if (!file.is_open()) {
			std::cerr << "ERROR OPENING THE "<<filename<< "FILE";
			return;
		}
		file.write((const char*)&minPoints, sizeof(int));
		file.write((const char*)&numOfTasks, sizeof(int));
		
		for (int i = 0; i < numOfTasks; i++) {
			
			const char* name = tasks[i].getName();
			size_t LengthName = strlen(tasks[i].getName());
			const char* condition = tasks[i].getCondition();
			size_t ConditionLength = strlen(tasks[i].getCondition());
			const int points = tasks[i].getPoints();
			file.write((const char*)&LengthName, sizeof(LengthName));
			file.write(name, LengthName);
			file.write((const char*)&ConditionLength, sizeof(ConditionLength));
			file.write(condition, ConditionLength);
			file.write((const char*)&points, sizeof(int));
		}
		file.close();


	}
	void readFromFile(std::ifstream& file) {
	
		int points;
		file.read((char*)&points, sizeof(int));
		int minPoints;
		file.read((char*)&minPoints, sizeof(int));
		setMinPoints(minPoints);
		Task *tasks=new Task[numOfTasks];
		for (int i = 0; i < numOfTasks; i++) {
			size_t LengthName, ConditionLength;

			file.read((char*)&LengthName, sizeof(LengthName));
			char* name = new char[LengthName + 1];
			file.read(name, LengthName);
			name[LengthName] = '\0';

			file.read((char*)&ConditionLength, sizeof(ConditionLength));
			char* condition = new char[ConditionLength + 1];
			file.read(condition, ConditionLength);
			condition[ConditionLength] = '\0';

			int points;
			file.read((char*)&points, sizeof(int));
			tasks[i] = Task(name, condition, points);
			delete[] name;
			delete[] condition;
			setTasks(tasks, i);
			
		}
		delete[] tasks;
		
	}
		
};


int main() {
	
		// Creating tasks
		Task tasks[NUM_TASKS];
		tasks[0] = Task("Task 1", "Complete the assigned reading", 20);
		tasks[1] = Task("Task 2", "Write an essay on a given topic", 30);
		tasks[2] = Task("Task 3", "Solve a set of problems", 40);

		// Creating exam simulation
		Exam exam(tasks, NUM_TASKS, MIN_PASS_GRADE);

		// Setting task properties
		tasks[0].setName("Reading Assignment");
		tasks[1].setCondition("Write an essay on a given topic within 2 hours");
		tasks[2].setPoints(50);

		//Changing task properties
		tasks[0].changeName("Grammar");
		tasks[1].changeCondition("Choose the right preposition ");
		tasks[2].changePoints(10);


		// Writing exam simulation to file
		exam.writeToFile("exam.dat");

		// Read exam simulation from file
		std::ifstream file("exam.dat", std::ios::binary |std:: ios::in);
		if (!file.is_open()) {
			if (!file.is_open()) {
				std::cerr << "ERROR OPENING THE FILE";
				return 0;
			}
			exam.readFromFile(file);
			file.close();

		}
		
		// Change minimum passing grade
		exam.changeMinPoints(70);

		// Get maximum points for exam
		int maxPoints = exam.getMaxPoints();

		cout << "Maximum points for exam: " << maxPoints << endl;

		return 0;
	
}