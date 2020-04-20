#pragma once
#include <iostream>
using	namespace std;
typedef	void(*ACTION)(void* callBackOwner);//A和Machine类约定接口，这个定义中当调用ACTION时，需要指定callBackOwner，即对象，是谁执行对象。
class Machine
{
public:
	Machine();
	~Machine();
	void	function(ACTION	pAction, void* callbackOwner)//Machine中定义一个函数，当事件发生时，调用pAction，并指定是谁调用的
	{
		cout << "输入1，执行action" << endl;
		int	a = 0;
		cin >> a;
		if (a == 1)
		{
			pAction(callbackOwner);//函数（参数）形式，这样，即有了函数，又有了参数列表，就可以执行了
		}
	}
	
	void	registOwner(void	*owner)
	{
		cout << "注册函数" << endl;
		cb_owner = owner;
	}
	void	registActionAndOnwe(ACTION	pAction, void* callbackOwner)
	{
		registOwner(callbackOwner);
		this->pACTION = pAction;
	}
	void	function(ACTION pAction)
	{
		cout << "输入1，执行action" << endl;
		int	a = 0;
		cin >> a;
		if (a == 1)
		{
			cout << "pAction"<< pAction << endl;
			cout << "cb_owner" << cb_owner << endl;
			pAction(cb_owner);//函数（参数）形式，这样，即有了函数，又有了参数列表，就可以执行了
		}
	}
	void	function()
	{
		cout << "本函数使用前，需要将函数和对象注册！" << endl;
		if (pACTION==NULL)
		{
			cout << "pACTION未注册！" << endl;
			return;
		}
		if (cb_owner==NULL)
		{
			cout << "cb_owner未注册！" << endl;
			return;
		}
		cout << "输入1，执行action" << endl;
		int	a = 0;
		cin >> a;
		if (a == 1)
		{
			cout << "pAction" << pACTION << endl;
			cout << "cb_owner" << cb_owner << endl;
			pACTION(cb_owner);//函数（参数）形式，这样，即有了函数，又有了参数列表，就可以执行了
		}
	}
private:
	void* cb_owner;
	ACTION	pACTION;

};

Machine::Machine()
{
}
Machine::~Machine()
{
}
void action(void* lp);//前置声明
class A
{
public:
	A();
	~A();
	std::string	name;
	void	printname()
	{
		cout << name << endl;
	}
	void	actionByA()//执行回调时，指定函数和对象
	{
		machine.function(action, this);
	}
	void	actionByA1()//执行回调时，先注册对象，这样function中只需要函数指针作为参数
	{
		machine.registOwner(this);
		machine.function(action);
	}
	void	actionByA2()
	{
		machine.registActionAndOnwe(action,this);//执行回调时，先注册函数和对象，这样function中不需要参数。
		machine.function();
	}
	Machine	machine;//machine是设备，设备能监控设备的事件，当某事件发生时，执行回调函数。
	
	
private:
	

};

A::A()
{
	name = "frank";
}

A::~A()
{
}
void action(void* lp)
{
	if (lp==NULL)
	{
		cout << "没有指定对象！" << endl;
		return;
	}
	A* a = (A*)lp;//指针强制转换
	a->printname();
}