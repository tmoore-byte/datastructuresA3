#include "GenStack.h"
#include <iostream>

using namespace std;

template <class T>
class Delimeter{
  public:
    Delimeter();//constructor
    ~Delimeter();//destructor

    char Checker(GenStack<T>* stack, string line, int* delimPosition, int delimCount);

  private:
    bool m_error; //TRUE IF DELIM ERROR
    char m_curr;
    int m_ePosition;
    char m_topElement;
    char m_expectedChar;
    char m_run; //check if user wants to run again
};


template <class T>
Delimeter<T>::Delimeter(){ //defautlt
  m_error = false;
  m_curr = '\0';
  m_ePosition = 0;
  m_topElement = '\0';
  m_expectedChar = '\0';
  m_run = '\0';
}



template <class T>
Delimeter<T>::~Delimeter(){}


template <class T>
//adding delimeters to stack created
char Delimeter<T>::Checker(GenStack<T>* stack, string line, int* delimPosition, int delimCount){
  for(int i = 0; i < delimCount; ++i){
    m_curr = line[i];

    if(m_curr == '(' || m_curr == '{' || m_curr == '['){
      stack->push(m_curr);
    }

//checking current elements
    if(m_curr == ')' || m_curr == '}' || m_curr == ']'){
      m_topElement = stack->pop();
      if(m_topElement == '('){
        m_expectedChar = ')';
        if(m_expectedChar != m_curr){
          m_ePosition = delimPosition[i];
          cout << "At Line " << m_ePosition << " expected " << m_expectedChar << " adn found " << m_curr << endl;
          m_error = true;

          break;

        }else{
          continue;
        }

      }else if(m_topElement == '{'){
        m_expectedChar = '}';

        if(m_expectedChar != m_curr){
          m_ePosition = delimPosition[i];

          cout << "At Line " << m_ePosition << " expected " << m_expectedChar << " adn found " << m_curr << endl;
          m_error = true;

          break;

        }else{
          continue;
        }

      }else if(m_topElement == '['){
        m_expectedChar = ']';

        if(m_expectedChar != m_curr){
          m_ePosition = delimPosition[i];
          cout << "At Line " << m_ePosition << " expected " << m_expectedChar << " adn found " << m_curr << endl;
          m_error = true;

          break;

        }else{
          continue;

        }
      }
    }
  }

  if(!(stack->isEmpty())){
    m_topElement = stack->pop();

    if(m_topElement == '('){
      cout << "Delimeter needed: )" << endl;

    }else if(m_topElement == '{'){
      cout << "Delimeter needed: }" << endl;

    }else if(m_topElement == '['){
      cout << "Delimeter needed: ]" << endl;

    }
    m_error = true;
  }


  if(m_error != true){
    cout << "All Delimeters are correct!" << endl;
    cout << "Scan another file? (y or n):";
    cin >> m_run;
  }
  return m_run; //enrty from above
}
