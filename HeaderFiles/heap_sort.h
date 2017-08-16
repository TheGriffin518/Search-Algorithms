#ifndef HEAP_SORT_H
#define HEAP_SORT_H

template<class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom)
{
  int maxChild;
  int rightChild;
  int leftChild;
  leftChild = root*2+1;
  rightChild = root*2+2;
  if(leftChild <= bottom)
    {
      if(leftChild == bottom)
	maxChild = leftChild;
      else
	{
	  if(elements[leftChild] <= elements[rightChild])
	    maxChild = rightChild;
	  else
	    maxChild = leftChild;
	}// else
      if(elements[root] < elements[maxChild])
	{
	  Swap(elements[root], elements[maxChild]);
	  ReheapDown(elements, maxChild, bottom);
	}// if
    }// if(leftChild <= bottom)
}// ReheapDown

template<class ItemType>
void HeapSort(ItemType values[], int numValues)
{
  int index;
  for (index = numValues/2 - 1; index >= 0; index--)
    ReheapDown(values, index, numValues-1);

  for(index = numValues-1; index >=1; index--)
    {
      Swap(values[0], values[index]);
      ReheapDown(values, 0, index-1);
    }// for
}// HeapSort

#endif
