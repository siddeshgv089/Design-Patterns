//problem to solve using strategy design patterns 
//Binding the comparision logic to sorting algorithm dynamically to change Algorithm's strategy

#include<iostream>
#include<vector>

class SortingAscendingAlgorithm
{
public:

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	bool comparisionLogic(int &a, int &b)
	{
		if (a > b)
			return true;
		else
			return false;
	}

	void sort(std::vector<int>& v)
	{

		int x = 0;
		bool isSwapped = true;

		while (isSwapped)
		{
			x++;
			isSwapped = false;

			for (int i = 0; i < (v.size() - x); i++)
			{
				if (comparisionLogic(v[i], v[i+1]))
				{
					swap(v[i], v[i+1]);
					isSwapped = true;
				}
			}
		}


	}

};

class SortingDescendingAlgorithm
{
public:

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	bool comparisionLogic(int& a, int& b)
	{
		if (a < b)
			return true;
		else
			return false;
	}

	void sort(std::vector<int>& v)
	{

		int x = 0;
		bool isSwapped = true;

		while (isSwapped)
		{
			x++;
			isSwapped = false;

			for (int i = 0; i < v.size() - x; i++)
			{
				if (comparisionLogic(v[i], v[i + 1]))
				{
					swap(v[i], v[i + 1]);
					isSwapped = true;
				}
			}
		}


	}

};

//implementing a strategy patterns for the alogorithm


class Icomparator
{
public:
	virtual bool compare(int a, int b) = 0;
	~Icomparator()
	{

	}
};


class LesserComparator : public Icomparator
{
public:
	bool compare(int a, int b)
	{
		if (a > b)
			return true;
		else
			return false;
	}

};

class GreaterComparator : public Icomparator
{
public:

	bool compare(int a, int b)
	{
		if (a < b)
			return true;
		else
			return false;
	}
};


class SortingAlgorithm
{
private:
	Icomparator* compare;

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

public:
	void sort(std::vector<int>& v, Icomparator * comp = nullptr)
	{
		if (comp != nullptr)
			compare = comp;

		bool isSwapped = true;
		int x = 0;

		while (isSwapped)
		{
			isSwapped = false;
			x++;
			
			for (int i = 0; i < v.size() - x; i++)
			{				
				if (compare->compare(v[i], v[i+1]))
				{
					swap(v[i], v[i+1]);
					isSwapped = true;
				}
			}
		}

	}
};


int main()
{
	std::vector<int> vec = { 2,3,1,5,4 };
	
	Icomparator* clp = new LesserComparator();
	Icomparator* cgp = new GreaterComparator();

	SortingAlgorithm s;

	s.sort(vec, cgp);
	
	for (auto& i : vec)
	{
		std::cout << i << std::endl;
	}

	/*
	SortingAscendingAlgorithm sa;
	sa.sort(vec);

	for (auto& i : vec)
	{
		std::cout << i << std::endl;
	}

	SortingDescendingAlgorithm da;
	da.sort(vec);

	for (auto& i : vec)
	{
		std::cout << i << std::endl;
	}
	*/

	return 0;
}
