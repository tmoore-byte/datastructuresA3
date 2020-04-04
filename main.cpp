#include "FileIO.h"
#include <string>

//main
int main(int argc, char **argv){

  char run = 'y';

  while(run != 'n'){
    if(argc > 1){
      string file = argv[1];
      string delimeter = "";
      FileIO<char> *fileIO = new FileIO<char>();
      delimeter = fileIO->ReadFile(file);
      run = fileIO->getAgainCheck();
      delete fileIO;
//user entry from delimeter.h ....
//if they want to run another file after all is done running
      if(run == 'y'){
        cout << "Enter the next file name: ";
        cin >> file;
        continue;

      }else if (run == 'n'){
        break;
      }else{
        cout<< "Exiting program. Incorrect input. " << endl;
        break;
      }
    }else{
      return 0;
    }
  }
  return 0;
}
