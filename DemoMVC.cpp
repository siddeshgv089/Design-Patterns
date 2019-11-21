#include<iostream>
#include<string>
#include<vector>



class Observer
{
public:
	virtual void notify(int data) = 0;
	virtual std::string getClassName() = 0;
};

class ViewClass1 : public Observer
{
public:
	void notify(int data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	}

	std::string getClassName()
	{
		return "ViewClass1";
	}
};

class ViewClass2 : public Observer
{
public:
	void notify(int data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	}

	std::string getClassName()
	{
		return "ViewClass2";
	}
};

class ViewClass3 : public Observer
{
public:
	void notify(int data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	}

	std::string getClassName()
	{
		return "ViewClass3";
	}
};

class Model
{
	int model_data1;
	int model_data2;
	int model_data3;

	std::vector<Observer*> v1;
	std::vector<Observer*> v2;
	std::vector<Observer*> v3;

public:


	void dataChangedForData1()
	{
		for (std::vector<Observer*>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			(*it)->notify(model_data1);
			std::cout << (*it)->getClassName() << std::endl;
		}
	}
	void dataChangedForData2()
	{
		for (std::vector<Observer*>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			(*it)->notify(model_data2);
			std::cout << (*it)->getClassName() << std::endl;
		}
	}

	void dataChangedForData3()
	{
		for (std::vector<Observer*>::iterator it = v3.begin(); it != v3.end(); it++)
		{
			(*it)->notify(model_data3);
			std::cout << (*it)->getClassName() << std::endl;
		}
	}

	void registerForData1(Observer* o)
	{
		v1.push_back(o);
	}

	void registerForData2(Observer* o)
	{
		v2.push_back(o);
	}

	void registerForData3(Observer* o)
	{
		v3.push_back(o);
	
	}

	void unregisteredData1(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v1.begin(); it != v1.end(); ++it)
		{
			
			if (*it == o)
			{
				v1.erase(it);
				break;
			}
		}
	}

	void unregisteredData2(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v2.begin(); it != v2.end(); ++it)
		{
			if (*it == o)
			{
				v2.erase(it);
				break;
			}
		}
	}

	void unregisteredData3(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v3.begin(); it != v3.end(); ++it)
		{
			if (*it == o)
			{
				v3.erase(it);
				break;
			}
		}
	}
	void setData1(int data)
	{
		model_data1 = data;
		dataChangedForData1();
	}

	void setData2(int data)
	{
		model_data2 = data;
		dataChangedForData2();
	}

	void setData3(int data)
	{
		model_data3 = data;
		dataChangedForData3();
	}

	int getData3()
	{
		return model_data3;
	}

	int getData2()
	{
		return model_data2;
	}

	int getData1()
	{
		return model_data1;
	}

};

class Controller
{
private:
	Model* _m;
public:
	Controller(Model* m) :_m(m) {}

	Model* getModel()
	{
		return _m;
	}
};

int main()
{
	Model* model = new Model();
	Controller* c = new Controller(model);
	ViewClass1* vc1 = new ViewClass1();
	ViewClass2* vc2 = new ViewClass2();
	ViewClass3* vc3 = new ViewClass3();

	//initial SetUp 
	//register screens for data
	c->getModel()->registerForData1(vc1);
	c->getModel()->registerForData1(vc2);
	c->getModel()->registerForData1(vc3);
	c->getModel()->registerForData2(vc2);
	c->getModel()->registerForData3(vc3);

	//unregister screens for data
	c->getModel()->unregisteredData1(vc3);


	//setting data notify all the registerred class
	c->getModel()->setData1(1);
	c->getModel()->setData2(2);
	c->getModel()->setData3(3);

	return 0;
}