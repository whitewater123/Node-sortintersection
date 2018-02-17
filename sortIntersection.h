/***********************************************************************
* Header:
*    INSERTION SORT
* Summary:
*    This will contain just the prototype for insertionSortTest(). You may
*    want to put other class definitions here as well.
* Author
*    Derek Washburn
************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
* INSERTION SORT
* Sort the items in the array
**********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
	Node <T> * n = NULL;
	Node <T> * temp = n;

	for (int i = 0; i < num; i++)
	{
		cerr << "FOR LOOP!\n";
		//Node <T> * temp = n;

		while (temp != NULL)
		{
			if (temp->data >= array[i])
			{
				//temp = array[i] and move all values right
				/*temp->pNext->data = temp->data;
				temp->pNext-> = temp;
				temp->data = array[i];
				temp = temp->pNext;*/
				T prev = temp->data;
				T hold;
				temp->data = array[i];
				temp = temp->pNext;
				while (temp->pNext != NULL)
				{
					hold = temp->data;
					temp->data = prev;
					prev = hold;
					temp = temp->pNext;

					/*temp->pNext->data = temp->data;
					temp->pNext = temp;
					temp = temp->pNext;*/
				}

				//insert()
			}
			else //if (temp < array[i])
			{
				if (temp->pNext->data >= array[i] || temp->pNext == NULL)
				{
					//put array[i] at pNext and move everything to the right
					T prev = temp->pNext->data;
					T hold;// = temp->pNext->data;
					temp->pNext->data = array[i];
					temp = temp->pNext->pNext;
					while (temp->pNext != NULL)
					{
						//temp->data = temp->pNext->data;
						hold = temp->data;
						temp->data = prev;
						prev = hold;
						temp = temp->pNext;
					}
				}
				else
					temp = temp->pNext;
			}
		}
		//insert(array[i], n);
		//array[i] = NULL;
		n = temp;
	}
	cerr << "END FOR LOOP!\n";
	for (int i = 0; i < num; i++)
	{
		cerr << "num = " << num << endl;
		cerr << "i = " << i << endl;
		cerr << "array[i] = " << array[i] << endl;
		array[i] = n->data;
		//array[i] = 9.9;
		cerr << "new array[i] = " << array[i] << endl;
		n = n->pNext;
	}
	cerr << "BREAK LOOP!\n";
}

#endif // INSERTION_SORT_H

