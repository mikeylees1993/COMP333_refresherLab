#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
const int SIZE = 25;

int loadArrays(ifstream&,string[],int[],int[],char[]);
void printArrays(ofstream&, string[],int[],int[],char[],int);
int main()
{
    int noProducts;
    ifstream fin("student.dat");
    ofstream fout("student.rpt");
    string studentNames[SIZE];
    int assignTotals[SIZE];
    int testTotals[SIZE];
    char grades[SIZE];
    if(!fin.is_open())
    {
        cout<< "error opening student.dat data file";
        system("pause");
        exit(-1);
    }
    if(!fout.is_open())
    {
        cout<<"Error Opening report file ";
        system("pause");
        exit(-2);
    }
    noProducts = loadArrays(fin,studentNames,assignTotals,testTotals,grades);
    printArrays(fout,studentNames,assignTotals,testTotals,grades,noProducts);
    cout<<"program completed successfully"<<endl;
    system("type student.rpt");
    system("pause");
    return 0;
}
int loadArrays(ifstream& fin,string names[],int assignTotal[],int testTotal[],char grade[])
{
    int length=0;
    for(;length < SIZE;length++)
    {
        getline(fin,names[length]);
        if(fin.eof())
            break;
        fin>>assignTotal[length];
        fin>>testTotal[length];
        fin>>grade[length];
        fin.ignore(80,'\n');
    }
    return length;
}

void printArrays(ofstream & out, string name[],int assignTotal[],int testTotal[],char grade[], int noStudents)
{
     out << left << setw(30) << "Student Name" << setw(20)<<right << "Assignment Total" 
     <<setw(20) << right << "Test Total" << setw(20) << "Grade" <<endl << endl;

     for(int counter=0;counter < noStudents;counter++)
     {
         out<<left<<setw(30)<<name[counter]
         <<right<<setw(20)<<assignTotal[counter]
         <<right<<setw(20)<<testTotal[counter]
         <<right<<setw(20)<<grade[counter]<<endl;
     }
    out<<endl<<endl;
    out<<"Number of students: "<< noStudents<<endl;
}