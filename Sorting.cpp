//Sorting

//Quick
template <typename Q>
void quick_sort(Q* Arr, int size, int& compar, int& permut, int left, int right)
{
	int i = left, j = right;
	Q mid = Arr[(left + right) / 2];
	do
	{
		compar++;
		while (Arr[i] < mid)
			i++;
		while (Arr[j] > mid) 
			j--;

		if (i <= j)
		{
			Q temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
			i++; 
			j--;
			permut++;
			
			
		}
	} while (i < j);

	if (left < j) QuickSort(Arr, size, compar, permut, left, j);
	if (i < right) QuickSort(Arr, size, compar, permut, i, right);
}


////////////////////////////////////////////////////////////////

//Insertion
template <typename I>
void insertion_sort(I* Arr, int size, int& compar, int& permut)
{
	for (int i = 1; i < size; i++)
	{
		I x = Arr[i];
		int j = i - 1;
		while (x < Arr[j])
		{
			Arr[j + 1] = Arr[j];
			j--;
			if (j < 0)
				break;
			permut++;
		}
		Arr[j + 1] = x;
		compar++;
	}
}