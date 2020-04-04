#include <iostream>
using namespace std;
//template for aata type flexibility
template <class T>

//making own stack with arrays.
class GenStack{
public:
  GenStack(); //default constructor
  GenStack(int maxSize); //overload constructor
  ~GenStack(); //destructor

  //core functions
  void push(T data); //insert an item
  T pop(); //remove ... if called when the stack is empty then
   // throw an exception

  //aux / helper functions
  T peek(); //aka top
  bool isEmpty();
  bool isFull();
  int getSize();
  GenStack *allocateMemory(); // method to add memory wgeb stack is full

  int top; //keeps trakc of top of stack
  int mSize;

  T *myArray; //pointer referrs to memory address of first block

};

template <class T>

GenStack<T>::GenStack(){
  myArray = new T[50];
  mSize = 50;
  top = -1;
}

template <class T>

GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class T>

GenStack<T>::~GenStack(){
  delete myArray;
}

template <class T>
void GenStack<T>::push(T data){
  myArray[++top] = data;
}

template <class T>

T GenStack<T>::pop(){
  if(isEmpty()){ //checl if stack is full
    return '\0';
  }else{
  return myArray[top--];
  }
}

template <class T>

T GenStack<T>::peek(){
  return myArray[top];
}

template <class T>

bool GenStack<T>::isFull(){
  return (top == mSize - 1);
}

template <class T>

bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>

int GenStack<T>::getSize(){
  return mSize;
}


template <class T>
//doubling stack memory automatically if its full
GenStack<T>* GenStack<T>::allocateMemory(){
  int size = mSize * 2;
  GenStack<T> *array = new GenStack<T>(size);
  return array;
}
