#include <iostream>
void rm(int **mtx, size_t r);
void output(const int * const *mtx, int r, const size_t * lns);
void input(int *mtx, size_t n);
int **convert (const int * t, size_t n, const size_t * lns, size_t rows);

int **make(int r, const size_t *lns)
{
	int **mtx = new int *[r];
	for (size_t i = 0; i < r; ++i)
	{
		try 
		{
			mtx[i] = new int[lns[i]];
		}
		catch(const std::bad_alloc &)
		{
			rm(mtx,i);
			throw;
		}
	}
	return mtx;
}

void rm(int **mtx, size_t r)
{
	for (size_t i = 0; i < r; ++i) 
	{
		delete[] mtx[i];
	}
	delete[] mtx;
}

void input(int *mtx, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		std::cin >> mtx[i];
	}
}

void output(const int * const *mtx, int r, const size_t * lns)
{
	for (size_t i = 0; i < r; ++i)
	{
		for (size_t j = 0; j < lns[i]; ++j)
		{
			std::cout << mtx[i][j] << " ";	
		}
		std::cout << "\n";
	}
}

int **convert (const int * t, size_t n, const size_t * lns, size_t rows)
{
	int **res = make(rows, lns);
	size_t a = 0;
	while (a < n)
	{
		for (size_t j = 0; j < rows; ++j) 
		{
			for (size_t i = 0; i < lns[j]; ++i)
			{	
				res[j][i] = t[a];
				++a;
			}
		}
	}
	return res;
}

int main()
{
	size_t n = 0;
	size_t rows = 0;
	std::cin >> n >> rows;
	
	if (std::cin.fail())
	{
		return 1;
	}
	int * t = new int[n];
	input(t, n);
	if (std::cin.fail()) 
	{
		return 1;
	}
	for (size_t i = 0; i<n; ++i)
	{
		std::cout << t[i] << " ";
	}
	std::cout << "\n";
	delete[] t;

	size_t * lns = new size_t[rows];
	for (size_t i = 0; i < rows; ++i)
	{
		std::cin >> lns[i];
		if (std::cin.fail())
		{
			return 1;
		}
	}
	for (size_t j = 0; j < rows; ++j)
	{
		std::cout << lns[j] << " ";
	}
	std::cout << "\n";
	delete[] lns;
		
	int ** res = nullptr;
	res = convert(t, n, lns, rows);
	output(res, rows, lns);
	rm(res,rows);
}	
	
	
	/*
	int rows = 0;
	int cols = 0;
	std::cin >> rows >> cols;
	if (std::cin.fail())
	{
		return 1;
	}
	int *t = nullptr;
	try
	{
		mtx = make(rows, cols);
	}
	catch (const std::bad_alloc&)
	{
		return 2;
	}
	input(mtx, rows, cols);
	if (std::cin.fail())
	{
		rm(mtx, rows);
		ret
	*/
