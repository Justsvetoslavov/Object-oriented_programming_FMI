#include <iostream>
#include <fstream>

enum hair{
    brown=0, black,blonde,red,white
};


class Student{
private:
    char name[17];
    char familyName[17];
    int facultyNum;
    double average;
    hair color;
public:

    const char* getName()const {
        return name;
    }
    void setName(char*name){
        copyString(this->name,name);
    }
    const char* getFamilyName()const {
        return familyName;
    }
    void setFamilyName(char* familyName){
        copyString(this-> familyName,familyName);
    }

    void setFacultyNum(int facNum){
        this->facultyNum=facNum;
    }
    int getFacultyNum()const{
        return facultyNum;
    }

    void setAverage(double  average){
        this-> average=average;
    }
    double getAverage() const{
        return average;
    }
    void setHair(hair n){
        this->color=n;
    }
    hair getHair(){
        return color;
    }

    char* copyString(char *arr, const char* from){

        for(int i=0;from[i]!='\0';i++){
            arr[i]=from[i];
        }
        return arr;
    }

};

void seperateTheLine(char*line,Student st){
    int counterOfTwoDots = 0;

    for (int i = 0, j = 0; line[i] != '\0'; i++) {
        char temp = line[i];
        if (temp == ',') {
            counterOfTwoDots++;
            j = 0;
            continue;
        }
        //finish
    }
}


void readStudent(Student st){
    char buff[17];
    std::cin>>buff;
    st.setName(buff);
    char buff2[17];
    std::cin>>buff2;
    st.setFamilyName(buff2);
    int facNum;
    std::cin>>facNum;
    st.setFacultyNum(facNum);
    double average;
    std::cin>>average;
    st.setAverage(average);
    int n;
    std::cin>>n;
    st.setHair((hair)n);


}
void writeStudent(std::ofstream &ofs,Student st){
    ofs<<st.getName()<<',';
    ofs<<st.getFamilyName()<<',';
    ofs<<st.getFacultyNum()<<',';
    ofs<<st.getAverage()<<',';
    ofs<<st.getHair()<<std::endl;
}

void writeInFile(Student*arr,int length){
    std::ofstream ofs("student.txt",std::ios::out);

    for(int i=0;i<length;i++){
        writeStudent(ofs,arr[i]);
    }
    ofs.close();
}


void readFromFile(Student*arr,int &n){
    std::ifstream ifs("student.txt",std::ios::in);

    while(!ifs.eof()){
        char buff[1024];
        ifs.getline(buff,1024);
    }
}

int main(){
    int n=3;
    Student *arr= new Student[n];

    for(int i=0;i<n;i++){
        readStudent(arr[i]);
    }
    delete[]arr;
    return 0;
}