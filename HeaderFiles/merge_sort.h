#ifndef MERGE_SORT_H
#define MERGE_SORT_H


template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst,
	   int rightLast, ItemType tempArray[])
{
  int index = leftFirst;
  int saveFirst = leftFirst;
  while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
      if (values[leftFirst] < values[rightFirst])
	{
	  tempArray[index] = values[leftFirst];
	  leftFirst++;
	}// if
      else
	{
	  tempArray[index] = values[rightFirst];
	  rightFirst++;
	}
      index++;

    }// while 
  while (leftFirst <= leftLast)
    {
      tempArray[index] = values[leftFirst];
      leftFirst++;
      index++;

    }// while

  while (rightFirst <= rightLast)
    {
      tempArray[index] = values[rightFirst];
      rightFirst++;
      index++;

    }// while

  for (index = saveFirst; index <= rightLast; index++)
    values[index] = tempArray[index];

}//Merge

template<class ItemType>
void MergeSort(ItemType values[], int first, int last, ItemType tempArray[])
{
  if(first < last)
    {
      int middle = (first + last) / 2;
      MergeSort<ItemType>(values, first, middle, tempArray);
      MergeSort<ItemType>(values, middle+1, last, tempArray);
      Merge<ItemType>(values, first, middle, middle+1, last, tempArray);
    }// if

}// MergeSort

#endif
