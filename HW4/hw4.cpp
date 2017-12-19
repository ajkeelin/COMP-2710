/*
*Austin Keelin
*ajk0033
*hw4.cpp
*Compiled using g++ compiler
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;

const int MAX_SIZE = 1000;

//Prototypes
int readfile(int inputArray[], ifstream& instream);
// Input: (1) Array storing data retrieved from the file (i.e., instream) 
//        (2) input file stream object 
// Output: Size of array. Note: you need to use this parameter to control the array size. 

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
// Input: (1) Array storing data retrieved from the file
//        (2) Array size retrieved from the file
//        (3) Array storing data retrieved from the file
//        (4) Array size retrieved from the file
//        (5) Array used to save output data
// Output: Sorted list of numbers from both input files

void writefile(int outputArray[], int outputArray_size, ofstream& outStream);
// Input: (1) Array of combined data from two input files
//        (2) Size of the output array
// Output: Creates output file containing the sorted output array

void test_readfile(void);
// This is a test driver for readfile()

void test_sort(void);
// This is a test driver for sort()

//Main Function
int main() {
   ifstream inStreamFirst;
   ofstream outStream;
   
   int iArray1[MAX_SIZE];
   int iArray1_size;
   std::string file1 = "";
   int iArray2[MAX_SIZE];
   int iArray2_size;
   std::string file2 = "";
   int outputArray[MAX_SIZE];
   int outputSize;
   std::string outfile = "";
   
   cout << "*** Unit Test Cases ***\n";
   
   test_readfile();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   test_sort();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   cout << "*** Welcome to Austin's sorting program ***\n";
   cout << "Enter the first input file name: ";
   cin >> file1;
   
   inStreamFirst.open((char*)file1.c_str());
   if (inStreamFirst.fail()) {
      cout << "Input file opening failed.";
      exit(1);
   }   
   iArray1_size = readfile(iArray1, inStreamFirst);
   inStreamFirst.close();
   inStreamFirst.clear();
   
   cout << "The list of " << iArray1_size + 1 << " numbers in file " << file1 << " is:\n";
   for (int i = 0; i <= iArray1_size; i++) {
      cout << iArray1[i];
      cout << "\n";
   }
   
   cout << "\nEnter the second input file name: ";
   cin >> file2;
   
   inStreamFirst.open((char*)file2.c_str());
   if (inStreamFirst.fail()) {
      cout << "Inout file opening failed>";
      exit(1);
   }   
   iArray2_size = readfile(iArray2, inStreamFirst);
   inStreamFirst.close();  
   inStreamFirst.clear(); 
   
   cout << "The list of " << iArray2_size + 1 << " numbers in file " << file2 << " is:\n";
   for (int i = 0; i <= iArray2_size; i++) {
      cout << iArray2[i];
      cout << "\n";
   }  
   
   cout << "\n";
   outputSize = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);
   cout << "The sorted list of " << outputSize << " numbers is: ";
   for (int i = 0; i < outputSize; i++) {
      cout << outputArray[i] << " ";
   } 
   
   cout << "\nEnter the output file name: ";
   cin >> outfile;
   outStream.open((char*)outfile.c_str());
   if (outStream.fail()) {
      cout << "Output file opening failed.";
      exit(1);
   }
      
   writefile(outputArray, outputSize, outStream);
   cout << "*** Please check the new file - " << outfile << " ***\n";
   cout << "*** Goodbye ***";

   return 0;
}   

//Function Implementations
int readfile(int inputArray[], ifstream& inStream) {
   int index = 0;   
   
   inStream >> inputArray[index];
   while (! inStream.eof()) {
      index++;
      inStream >> inputArray[index];
   }
   
   return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
   int outputArray_size = inputArray1_size + inputArray2_size;
   int index1, index2, index3;
   index1 = index2 = index3 = 0;

   while(index1 < inputArray1_size && index2 < inputArray2_size)
   {
      if(inputArray1[index1] < inputArray2[index2]){
         outputArray[index3] = inputArray1[index1];
         index1++;
         index3++;
      }
      else {
         outputArray[index3] = inputArray2[index2];
         index2++;
         index3++;
      }
  }

  //If all numbers from inputArray1 have been added
  if(index1 == inputArray1_size)
  {
    while(index2 < inputArray2_size)
    {
      outputArray[index3] = inputArray2[index2];
      index2++;
      index3++;
    }
  }
  else
  {
    while(index1 < inputArray1_size)
    {
      outputArray[index3] = inputArray1[index1];
      index1++;
      index3++;
    }
  }

  assert(index3 == outputArray_size);
  return outputArray_size;
}      

void writefile(int outputArray[], int outputArray_size, ofstream& outstream)
{
  for(int x = 0; x < outputArray_size; x++)
  {
    outstream << outputArray[x] << endl;
  }
}      

//Test Drivers
void test_readfile(void) {
   ifstream inStreamFirst;
   int array[MAX_SIZE];
   int array_size;
   std::string file1 = "input1.txt";
   std::string file2 = "input2.txt";
   std::string file3 = "input3.txt";
   std::string file4 = "input4.txt";
   
   cout << "Unit Test Case 1: Function Name - readfile()\n"; 
   
   cout << "\tCase 1.1: input1.txt - 6 values\n";
   inStreamFirst.open(file1.c_str());
   int int1 = readfile(array, inStreamFirst);
   assert(int1);
   inStreamFirst.close();
   cout << "\tCase 1.1 passed.\n"; 
   
   cout << "\tCase 1.2: input2.txt - 15 values\n";
   inStreamFirst.open(file2.c_str());
   int int2 = readfile(array, inStreamFirst);
   assert(int2);
   inStreamFirst.close();
   cout << "\tCase 1.2 passed.\n";
   
   cout << "\tCase 1.3: input3.txt - 2 values\n";
   inStreamFirst.open(file3.c_str());
   int int3 = readfile(array, inStreamFirst);
   assert(int3);
   inStreamFirst.close();
   cout << "\tCase 1.3 passed.\n";
   
   cout << "\tCase 1.4: input4.txt - 950 values\n";
   inStreamFirst.open(file4.c_str());
   int int4 = readfile(array, inStreamFirst);
   assert(int4);
   inStreamFirst.close();
   cout << "\tCase 1.4 passed.\n";
     
} 

void test_sort(void) {
   ifstream inStreamFirst;
   int array1[MAX_SIZE];
   int array2[MAX_SIZE];
   int array3[MAX_SIZE];
   int array4[MAX_SIZE];
   int output1[MAX_SIZE];
   int output2[MAX_SIZE];
   int output3[MAX_SIZE];
   int array1_size, array2_size, array3_size, array4_size;
   std::string file1 = "input1.txt";
   std::string file2 = "input2.txt";
   std::string file3 = "input3.txt";
   std::string file4 = "input4.txt";  
   
   inStreamFirst.open(file1.c_str());
   array1_size = readfile(array1, inStreamFirst);
   inStreamFirst.close();
   inStreamFirst.open(file2.c_str());
   array2_size = readfile(array2, inStreamFirst);
   inStreamFirst.close(); 
   inStreamFirst.open(file3.c_str());
   array3_size = readfile(array3, inStreamFirst);
   inStreamFirst.close();
   inStreamFirst.open(file4.c_str());
   array4_size = readfile(array4, inStreamFirst);
   inStreamFirst.close();
   
   cout << "Unit Test Case 2: Function Name - sort()\n";
   
   cout << "\tCase 2.1: input1.txt, input2.txt\n";
   int sort1 = sort(array1, array1_size, array2, array2_size, output1); 
   assert(sort1);
   cout << "\tCase 2.1 passed.\n";
   
   cout << "\tCase 2.2: input1.txt, input3.txt\n";
   int sort2 = sort(array1, array1_size, array3, array3_size, output2);
   assert(sort2);
   cout << "\tCase 2.2 passed.\n";
   
   cout << "\tCase 2.3: input1.txt, input4.txt\n";
   int sort3 = sort(array1, array1_size, array4, array4_size, output3);
   cout << "\tCase 2.3 passed.\n";
    
}  