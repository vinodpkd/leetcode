#include <iostream>
#include <string>

int num_even_digits(int* arr,int len)
{
	if (0 == len)
		return -1;
	
	int even_count = 0;
	
	for(int i = 0; i < len;i++)
	{
		if(0 == (std::to_string(arr[i]).length() % 2))
			even_count++;
			
	}

	return even_count;	
}

int main()
{
	int arr[] = {1,12,0,24,23,3,31};
	int len = sizeof(arr)/sizeof(int);
	std::cout << "The number of even numbers in array is " << num_even_digits(arr,len) << '\n';
	
	return 0;
}
