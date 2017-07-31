#ifndef SELECT_SORT_H
#define SELECT_SORT_H

template<class ItemType>
int MinIndex(ItemType values[], int startIndex, int endIndex)
{
  int indexOfMin = startIndex;
  for(int index = startIndex + 1; index <= endIndex; index++)
    if(values[index] < values[indexOfMin])
      indexOfMin = index;
  return indexOfMin;
}// MinIndex

template<class ItemType>
void SelectionSort(ItemType values[], int numValues)
{
  int endIndex = numValues-1;
  for(int current = 0; current < endIndex; current++)
    Swap(values[current], values[MinIndex(values, current, endIndex)]);
}// SelectionSort

#endif
