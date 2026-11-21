#include "easyfind.tpp"

int main()
{
	std::cout << "TEST INT 01" << std::endl;
	{
		int arr[] = {1, 2, 3, -4, 5};
		std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = -4;
		try
		{
			std::vector<int>::iterator it = easyfind(nums, valueToFind);
			std::cout << "Found value: " << *it << std::endl;
			std::cout << "Index: " << std::distance(nums.begin(), it) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout <<  "\nERROR THROWN: \"" << e.what() ;
		}
	}
    
	std::cout << "\nTEST CHAR 02" << std::endl;
	{
		char arr[] = {'A', 'B', 'V', 'f', 'y'};
		std::vector<char> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

		char valueToFind = 'f';

		try
		{
			std::vector<char>::iterator it = easyfind(nums, valueToFind);
			std::cout << "Found value: " << *it << std::endl;
			std::cout << "Index: " << std::distance(nums.begin(), it) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\nERROR THROWN: \"" << e.what();
		}
}
	std::cout << "\nTEST LIST 03" << std::endl;
	{
		int arr[] = {4, 5, 55, 89, 10};
		std::list<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int valueToFind = 10;

		try
		{
			std::list<int>::iterator it = easyfind(nums, valueToFind);
			std::cout << "Found value: " << *it << std::endl;
			std::cout << "Index: " << std::distance(nums.begin(), it) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\nERROR THROWN: \"" << e.what();
		}
}
}