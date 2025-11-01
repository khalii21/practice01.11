#include <iostream>
int **make(int r, int c);
int main()
{
int rows = 0;
int cols = 0;
std::cin >> rows >> cols;
if (std::cin.fail())
{
	return 1;
}
int **mtx = nullptr;
mtx = make(rows, cols); 
}

