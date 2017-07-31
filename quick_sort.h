#ifndef QUICK_SORT_H
#define QUICK_SORT_H

template<class ItemType>
void Split(ItemType values[], int first, int last, int& splitPoint) 
{
  ItemType splitVal = values[first];
  int saveFirst = first;
  bool onCorrectSide;
  first++;
  do
    {
      onCorrectSide = true;
      while (onCorrectSide)
	if (values[first] > splitVal)
	  onCorrectSide = false;
	else 
	  {
	    first++;
	    onCorrectSide = (first <= last);
	  }// else

      onCorrectSide = (first <= last);
      while (onCorrectSide)
	if(values[last] <= splitVal)
	  onCorrectSide = false;
	else 
	  {
	    last--;
	    onCorrectSide = (first <= last);
	  }// else
      if (first < last)
	{
	  Swap(values[first], values[last]);
	  first++;
	  last--;
	}// if

    } while (first <= last); // do while

  splitPoint = last;
  Swap(values[saveFirst], values[splitPoint]);
}// Split

template<class ItemType>
void QuickSort(ItemType values[], int first, int last)
{
  if (first < last)
    {
      int splitPoint;
      Split(values, first, last, splitPoint);
      QuickSort(values, first, splitPoint-1);
      QuickSort(values, splitPoint+1, last);
    }// if
}// QuickSort
#endif
