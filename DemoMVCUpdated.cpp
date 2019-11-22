#include<iostream>
#include<string>
#include<vector>


class ModelObserver
{

public:
	virtual bool operator=(bool a) {
		return false;
	}
	
	virtual int operator=(int a) {
		return 0;
	}
	
	virtual float operator=(float a) {
		return 0.0f;
	}

};

class Observer
{
public: 
	virtual void notify(int data) = 0;
	virtual void notify(float data) = 0;
	virtual void notify(bool data) = 0;
	virtual std::string getClassName() = 0;
	
};

class ViewClass1 : public Observer
{
public:
	int x = 10;

	void notify(bool data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	} 

	void notify(int data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	} 
	void notify(float data)
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
	void notify(float data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	}

	void notify(int data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	} 

	void notify(bool data)
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
		std::cout << "Notification from datamodel value = " << data << " for class " ;
	}

	void notify(float data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	} 
	void notify(bool data)
	{
		std::cout << "Notification from datamodel value = " << data << " for class ";
	} 
	std::string getClassName()
	{
		return "ViewClass3";
	}
};

class BoolModel :public ModelObserver
{

private:
	std::vector<Observer*> v;

public:
	bool BooleanData;

	BoolModel():BooleanData(false){}
	
	bool operator=(bool a)
	{
		BooleanData = a;
		dataChanged();
		return a;
	}

	void dataChanged()
	{
		for (std::vector<Observer*>::iterator it = v.begin(); it != v.end(); it++ )
		{
			(*it)->notify(BooleanData);
			std::cout << (*it)->getClassName()<<std::endl;
		}
	}

	void registerScreenForData(Observer *o)
	{
		v.push_back(o);
	}

	void unregisterData(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v.begin(); it != v.end(); it++)
		{
			if ((*it == o))
			{
				std::cout << "unregistering data for " << (*it)->getClassName()<<std::endl;
				v.erase(it);
				break;
			}
		}
	}

};

class IntModel :public ModelObserver
{

private:
	std::vector<Observer*> v;

public:
	int IntData;

	IntModel():IntData(false){}

	int operator=(int a)
	{
		IntData = a;
		dataChanged();
		return a;
	}

	void dataChanged()
	{
		for (std::vector<Observer*>::iterator it = v.begin(); it != v.end(); it++ )
		{
			(*it)->notify(IntData);
			std::cout << (*it)->getClassName()<<std::endl;
		}
	}

	void registerScreenForData(Observer *o)
	{
		v.push_back(o);
	}

	void unregisterData(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v.begin(); it != v.end(); it++)
		{
			if ((*it == o))
			{
				std::cout << "unregistering data for " << (*it)->getClassName()<<std::endl;
				v.erase(it);
				break;
			}
		}
	}

};


class FloatModel :public ModelObserver
{

private:
	std::vector<Observer*> v;

public:
	float FloatData;

	FloatModel():FloatData(false){}

	float operator=(float a)
	{
		FloatData = a;
		dataChanged();
		return a;
	}

	void dataChanged()
	{
		for (std::vector<Observer*>::iterator it = v.begin(); it != v.end(); it++ )
		{
			(*it)->notify(FloatData);
			std::cout << (*it)->getClassName()<<std::endl;
		}
	}

	void registerScreenForData(Observer *o)
	{
		v.push_back(o);
	}

	void unregisterData(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v.begin(); it != v.end(); it++)
		{
			if ((*it == o))
			{
				std::cout << "unregistering data for " << (*it)->getClassName()<<std::endl;
				v.erase(it);
				break;
			}
		}
	}

};

class WidgetModel
{
public:
	BoolModel* b;
	IntModel* i;
	FloatModel* f;

	WidgetModel()
	{
		b = new BoolModel();
		i = new IntModel();
		f = new FloatModel();
	}

	~WidgetModel()
	{
		delete b;
		delete i;
		delete f;

	}

	
};

/*class Model : public ModelObserver
{


	std::vector<Observer*> v1;
	std::vector<Observer*> v2;
	std::vector<Observer*> v3;

public:

	int operator=(int a)
	{
		return a;
	}

	int model_data1;
	int model_data2;
	int model_data3;

	void dataChangedForData1()
	{
		for (std::vector<Observer*>::iterator it = v1.begin(); it != v1.end(); it++ )
		{
			(*it)->notify(model_data1);
			std::cout << (*it)->getClassName()<<std::endl;
		}
	}
	void dataChangedForData2()
	{
		for (std::vector<Observer*>::iterator it = v2.begin(); it != v2.end(); it++ )
		{
			(*it)->notify(model_data2);
			std::cout << (*it)->getClassName() << std::endl;
		}
	}

	void dataChangedForData3()
	{
		for (std::vector<Observer*>::iterator it = v3.begin(); it != v3.end(); it++ )
		{
			(*it)->notify(model_data3);
			std::cout << (*it)->getClassName() <<std::endl;
		}
	}

	void registerForData1(Observer *o)
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

	void unregisterData1(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			if ((*it == o))
			{
				std::cout << "unregistering data for " << (*it)->getClassName()<<std::endl;
				v1.erase(it);
				break;
			}
		}

		//std::vector<Observer*>::iterator it = std::find(v1.begin(), v1.end(), o);
		//if(it != v1.end())
		//	v1.erase(it);
	

	}

	void unregisterData2(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			if ((*it == o))
			{
				std::cout << "unregistering data for " << (*it)->getClassName()<<std::endl;
				v2.erase(it);
				break;
			}
		}
	}

	void unregisterData3(Observer* o)
	{
		for (std::vector<Observer*>::iterator it = v3.begin(); it != v3.end(); it++)
		{
			if ((*it == o))
			{
				std::cout << "unregistering data for " << (*it)->getClassName()<<std::endl;
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

};*/

class Controller
{
private:
	WidgetModel *_m;
public:
	Controller(WidgetModel *m):_m(m){}

	BoolModel* getBoolModel()
	{
		return _m->b;
	}

	IntModel* getIntModel()
	{
		return _m->i;
	}

	FloatModel* getFloatModel()
	{
		return _m->f;
	}


};

int main()
{
	WidgetModel *model = new WidgetModel();
	Controller *c = new Controller(model);
	ViewClass1* vc1 = new ViewClass1();
	ViewClass2* vc2 = new ViewClass2();
	ViewClass3* vc3 = new ViewClass3();

	

	//initial SetUp
	/*c->getModel()->registerForData1(vc1);
	c->getModel()->registerForData1(vc2);
	c->getModel()->registerForData1(vc3);
	c->getModel()->registerForData2(vc2);
	c->getModel()->registerForData3(vc3);
	*/
	//c->getModel()->unregisterData1(vc2);
	//c->getModel()->unregisterData1(vc3);
	//c->getModel()->unregisterData3(vc3);

	//setting data notify all the registerred class
	//c->getModel()->setData1(1);
	//c->getModel()->setData2(2);
	//c->getModel()->setData3(3);
	
	//c->getModel()->model_data1 = 10;
	
	c->getIntModel()->registerScreenForData(vc1);
	c->getIntModel()->registerScreenForData(vc2);
	c->getFloatModel()->registerScreenForData(vc3);

	//c->getBoolModel()->unregisterData(vc1);
	
	*c->getIntModel() = 10;
	*c->getFloatModel() = 100.0;

	std::cout << c->getFloatModel()->FloatData << std::endl;
	std::cout << c->getIntModel()->IntData << std::endl;
	
	
	return 0;
}