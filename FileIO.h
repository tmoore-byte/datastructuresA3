// opening file, source code file to be analyzed as command line argument

#include "Delimeter.h"
#include <fstream>

template <class T>
class FileIO{
  public:
    FileIO();//default constructor
    ~FileIO();//destructor
// functions for opening file, checking if full and adding memory if full
    string ReadFile(string file);
    char getAgainCheck();
    int* allocateMemory(int* curr, int size);

  private:
    int m_delimCount;
    char m_againCheck;
};



template <class T>
FileIO<T>::FileIO(){ //default

  m_delimCount = 0;
  m_againCheck = '\0';

}


template <class T>
FileIO<T>::~FileIO(){}



template <class T>
string FileIO<T>::ReadFile(string file){

  ifstream infs;
  string line = "";
  int lineCount = 0;
  string delimStr = "";
  int delimError = 0;

//Attempt to open file
  infs.open(file);
  if(!infs.is_open()){
    cout << "error opening file." << endl;

  }


  GenStack<T> *stack = new GenStack<T>();
  int stackSize = stack->getSize();
  int *delimPosition = new int[stackSize];

//while we are not at the end of the file and opening does not fail...
  while(!infs.eof()){

    if(!infs.fail()){

      while(getline(infs, line)){
        lineCount += 1;

        for(int i = 0; i < line.size(); ++i){

          if(m_delimCount == stackSize - 1){
            delimPosition = allocateMemory(delimPosition, m_delimCount);
            stack = stack->allocateMemory();
            stackSize = stack->getSize();

          }

          //TRACKING THE DELIMETERS
          if(line.at(i) == '('){
            delimStr.push_back('(');
            m_delimCount += 1;
            delimPosition[delimError] = lineCount;
            delimError += 1;

          }else if(line.at(i) == ')'){
              delimStr.push_back(')');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;

          }else if(line.at(i) == '{'){
              delimStr.push_back('{');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;

          }else if(line.at(i) == '}'){
              delimStr.push_back('}');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;

          }else if(line.at(i) == '['){
              delimStr.push_back('[');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;

          }else if(line.at(i) == ']'){
              delimStr.push_back(']');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;
          }
        }
      }
    }

    infs.close();//remember to close file!!

    Delimeter<T> *delimeter = new Delimeter<T>();
    m_againCheck = delimeter->Checker(stack, delimStr, delimPosition, m_delimCount);
    return delimStr;
    break;
  }
}
//more memory.. double size of stack
template <class T>
int* FileIO<T>::allocateMemory(int* curr, int size){
  int newSize = size * 2;
  int* array = new int[newSize];

  for(int i = 0; i < size; ++i){
    array[i] = curr[i];
  }
  return array;
  //returning new array based stack
}

template <class T>
char FileIO<T>::getAgainCheck(){
  return m_againCheck;
}
