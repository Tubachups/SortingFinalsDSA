#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Sorting
{
public:
	int swapCount = 0;
	int iterationSwapCount = 0;

	void getArray(vector<int>& userArrayElements, int& userArrayLength)
	{
		cout << "What is the size of your array? ";
		cin >> userArrayLength;
		cout << "Enter your array (non-negative integers only)" << endl;

		for (int i = 0; i < userArrayLength; ++i) {
			int element;

			do {
				cout << "Element " << i + 1 << ": ";
				cin >> element;

				if (element < 0) {
					cout << "Please enter a non-negative integer." << endl;
				}
			} while (element < 0);

			userArrayElements.push_back(element);
		}
	}

	void BubbleSortAscending(int arrayLength, int arrayElements[])
	{
		int iterations = 0;
		int totalSwaps = 0;

		for (int i = 0; i < arrayLength; i++)
		{
			bool swapped = false;

			for (int j = 0; j < arrayLength - 1; j++)
			{
				if (arrayElements[j] > arrayElements[j + 1])
				{

					int temp = arrayElements[j];
					arrayElements[j] = arrayElements[j + 1];
					arrayElements[j + 1] = temp;

					swapped = true;
					totalSwaps++;


					cout << "Swap " << totalSwaps << " in iteration " << iterations + 1 << ": ";
					for (int k = 0; k < arrayLength; k++)
					{
						cout << arrayElements[k] << " ";
					}
					cout << endl;
				}
			}

			iterations++;


			if (!swapped)
			{
				cout << "Array is already sorted. Exiting early." << endl;
				break;
			}
		}
		cout << "Total iterations: " << iterations << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl;
	}
	void BubbleSortDescending(int arrayLength, int arrayElements[])
	{
		int iterations = 0;
		int totalSwaps = 0;

		for (int i = 0; i < arrayLength; i++)
		{
			bool swapped = false;

			for (int j = 0; j < arrayLength - 1; j++)
			{
				if (arrayElements[j] < arrayElements[j + 1])
				{
					int temp = arrayElements[j];
					arrayElements[j] = arrayElements[j + 1];
					arrayElements[j + 1] = temp;

					swapped = true;
					totalSwaps++;

					cout << "Swap " << totalSwaps << " in iteration " << iterations + 1 << ": ";
					for (int k = 0; k < arrayLength; k++)
					{
						cout << arrayElements[k] << " ";
					}
					cout << endl;
				}
			}

			iterations++;

			if (!swapped)
			{
				cout << "Array is already sorted. Exiting early." << endl;
				break;
			}
		}
		cout << "Total iterations: " << iterations << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl;
	}

	void SelectionSortAscending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0;
		int minIndexChanges = 0;

		for (int i = 0; i < arrayLength - 1; i++)
		{
			int minPosition = i;
			for (int j = i + 1; j < arrayLength; j++)
			{
				if (arrayElements[j] < arrayElements[minPosition])
				{
					minPosition = j;
					minIndexChanges++;
				}
			}

			if (minPosition != i)
			{
				int temp = arrayElements[i];
				arrayElements[i] = arrayElements[minPosition];
				arrayElements[minPosition] = temp;

				totalSwaps++;

				cout << "Swap " << totalSwaps << " in iteration " << iteration + 1 << ": ";
				for (int k = 0; k < arrayLength; k++)
				{
					cout << arrayElements[k] << " ";
				}
				cout << endl;
			}

			iteration++;
		}
		cout << "Total iterations: " << iteration << endl;
		
		cout << "Total minimum index changes: " << minIndexChanges << endl;
	}
	void SelectionSortDescending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0;
		int maxIndexChanges = 0;

		for (int i = 0; i < arrayLength - 1; i++)
		{
			int maxPosition = i;
			for (int j = i + 1; j < arrayLength; j++)
			{
				if (arrayElements[j] > arrayElements[maxPosition])
				{
					maxPosition = j;
					maxIndexChanges++;
				}
			}

			if (maxPosition != i)
			{
				int temp = arrayElements[i];
				arrayElements[i] = arrayElements[maxPosition];
				arrayElements[maxPosition] = temp;

				totalSwaps++;


				cout << "Swap " << totalSwaps << " in iteration " << iteration + 1 << ": ";
				for (int k = 0; k < arrayLength; k++)
				{
					cout << arrayElements[k] << " ";
				}
				cout << endl;
			}

			iteration++;
		}
		cout << "Total iterations: " << iteration << endl;
		
		cout << "Total maximum index changes: " << maxIndexChanges << endl;
	}

	void heapify(int arr[], int n, int i, int& iteration, int& steps)
	{
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && arr[left] > arr[largest])
		{
			largest = left;
		}


		if (right < n && arr[right] > arr[largest])
		{
			largest = right;
		}


		if (largest != i)
		{
			swap(arr[i], arr[largest]);
			steps++;
			iteration++;


			heapify(arr, n, largest, iteration, steps);
		}
	}
	void HeapSortAscending(int n, int arr[])
	{
		int iteration = 0;
		int steps = 0;


		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i, iteration, steps);
		}

		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			steps++;
			iteration++;

			heapify(arr, i, 0, iteration, steps);
		}

		cout << "Sorted array in ascending order: ";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << n - 1 << endl;
		cout << "Total steps: " << steps << endl;
	}

	void HeapSortDescending(int n, int arr[])
	{
		int iteration = 0;
		int steps = 0;

		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i, iteration, steps);
		}

		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			steps++;
			iteration++;

			heapify(arr, i, 0, iteration, steps);
		}

		cout << "Sorted array in descending order: ";
		for (int i = n - 1; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << n - 1 << endl;
		cout << "Total steps: " << steps << endl;
	}
};

int main()
{
	int userResponseForSortType;
	int userResponseForOperationRepeat;
	int userArrayLength;
	int userResponseForPattern;
	vector<int> userArrayElements;
	bool invalidInput = false;
	bool invalidInputForPattern = false;
	Sorting sorter;
	do
	{
		invalidInput = false;
		cout << "Menu!" << endl;
		cout << "[1] Merge Sort" << endl;
		cout << "[2] Bubble Sort" << endl;
		cout << "[3] Selection Sort" << endl;
		cout << "[4] Heap Sort\n"
			<< endl;
		cout << "What type of sorting would you use?" << endl;

		do
		{
			invalidInputForPattern = false;
			cin >> userResponseForSortType;
			switch (userResponseForSortType)
			{
			case 1:
				cout << "Merge Sort chosen." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select sorting arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						break;

					case 2:
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 2:
				cout << "Bubble Sort chosen." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select sorting arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.BubbleSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.BubbleSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 3:
				cout << "Selection Sort chosen." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select sorting arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.SelectionSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.SelectionSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 4:
				cout << "Heap Sort chosen." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select sorting arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.HeapSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.HeapSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			default:
				cout << "Input Error. Try Again" << endl;
				invalidInput = true;
				break;
			}
		} while (invalidInput);
		if (!invalidInput)
		{
			cout << "Do you want to try again? (1 for Yes, 0 for No)" << endl;
			cin >> userResponseForOperationRepeat;
		}
	} while (userResponseForOperationRepeat == 1);
	return 0;
}