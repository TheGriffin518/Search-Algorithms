#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
const int SIZE = 10000;

typedef int ItemType;
void Swap(ItemType& item1, ItemType& item2);
#include "HeaderFiles/bubble_sort.h"
#include "HeaderFiles/heap_sort.h"
#include "HeaderFiles/insert_sort.h"
#include "HeaderFiles/merge_sort.h"
#include "HeaderFiles/select_sort.h"
#include "HeaderFiles/quick_sort.h"

using namespace std;
using ns = chrono::nanoseconds;
using get_time = chrono::steady_clock;

void Print(ofstream&, int, string, string);
int InitValues(string, ItemType[]);

int main() 
{
  ifstream inFile;        // file containing operations
  ofstream outFile;
  string inFileName;      // input file external name
  string command;         // operation to be executed
  ItemType values[SIZE];
  int System_time;
  int numElems;
  string Sort_type;
  string inputFileType;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return: " << endl;
  cin >> inFileName;
  inFile.open(inFileName.c_str());
  inFile >> command;
  outFile.open("TimeResults.txt");
  
  while (command != "Quit")
    {
      //extract inputFile parameter
      string inputFileType;
      inFile >> inputFileType;

      // load data from input file into values array
      numElems = InitValues(inputFileType, values);

      //cout << command << "  " << inputFileType << endl;
      auto start = get_time::now();
      // save system begin time
      if (command == "SelectionSort")
	{
	  cout << "Executing SelectionSort" << endl;
	  SelectionSort(values, numElems);
	}
      else if(command == "ShortBubble")
	{
	  cout << "Executing BubbleSort" << endl;
	  BubbleSort(values,numElems);
	}
      else if(command == "MergeSort")
	{
	  cout << "Executing MergeSort" << endl;
	  ItemType tempArray[SIZE];
	  MergeSort(values, 0, numElems, tempArray);
	}
      else if(command == "QuickSort")
	{
	  cout << "Executing QuickSort" << endl;
	  QuickSort(values, 0, numElems);
	}
      else if(command == "InsertionSort")
	{
	  cout << "Executing InsertionSort" << endl;
	  InsertionSort(values, numElems);
	}
      else if(command == "HeapSort")
	{
	  cout << "Executing HeapSort" << endl;
	  HeapSort(values, numElems);
	}
      else
	outFile << "Input not recognized." << endl;
      
      // save system end time
      // system time = system end time - system begin time
      // print system time, sort type used, input file data
      auto end = get_time::now();
      auto diff = end - start;
      System_time = chrono::duration_cast<ns>(diff).count();
      Print(outFile, System_time, command, inputFileType);
      inFile >> command;
    }// while
  inFile.close();
  outFile.close();
  return EXIT_SUCCESS;
} //main

void Swap(ItemType& item1, ItemType& item2)
{
  ItemType tempItem;
  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

int InitValues(string InputFile, ItemType values[])
{
  InputFile += ".txt";
  ifstream input;
  input.open(InputFile.c_str());
  int count = -1;

  do
    {
      count++;
      input >> values[count];
    } while(values[count] != '\0');

  input.close();
  return count;
}// InitValues

void Print(ofstream& outFile, int System_time, string Sort_type, string inputFileType)
{
  float seconds = System_time * .000000001;
  outFile << "### " << Sort_type << " ###" << endl;
  outFile << "\tFile Type: " << inputFileType << endl;
  outFile << "\tTime taken (Nano Seconds): " << System_time << endl;
  outFile << "\tTime Taken (Seconds): " << seconds << endl;
  outFile << endl;

}
