/*Multiton class using Singleton 
creates LIMIT number of objects by tracking currentIndex */

#include<iostream>
#include<vector>

#define LIMIT 5

class Multiton
{
private:

	static std::vector<Multiton*>listofInstances;
	static int limit;
	static int currentIndex;
	int mId;

	Multiton()
	{
		mId = currentIndex + 1;
	}

public:
	
	int getId()
	{
		return mId;
	}

	static int reserverSize()
	{
		Multiton::listofInstances.reserve(LIMIT);
		for (int i = 0; i < LIMIT; i++)
		{
			Multiton::listofInstances[i] = nullptr;
		}
		return LIMIT;
	}

	static Multiton* getInstance()
	{

		currentIndex = currentIndex % LIMIT;

		if (!Multiton::listofInstances[currentIndex % limit])
		{
			Multiton::listofInstances[currentIndex % limit] = new Multiton();
		}

		return Multiton::listofInstances[currentIndex++ % limit];
	}

};


std::vector<Multiton*> Multiton::listofInstances(LIMIT);
int Multiton::currentIndex = 0;
int Multiton::limit = Multiton::reserverSize();



int main()
{
	std::cout << Multiton::getInstance()->getId() << std::endl;
	std::cout << Multiton::getInstance()->getId() << std::endl;
	std::cout << Multiton::getInstance()->getId() << std::endl; 
	std::cout << Multiton::getInstance()->getId() << std::endl;
	std::cout << Multiton::getInstance()->getId() << std::endl;
	std::cout << Multiton::getInstance()->getId() << std::endl;
	std::cout << Multiton::getInstance()->getId() << std::endl;
	std::cout << Multiton::getInstance()->getId() << std::endl;
}