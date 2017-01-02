#include <iostream>
using namespace std;

//template<class T>
//class Stack
//{
//public:
//	Stack() 
//	{ 
//		top = -1; 
//	}
//	bool Empty() 
//	{ 
//		return top == -1;
//	}
//	bool IsEmpty() const 
//	{
//		return top == -1;
//	}  
//	bool IsFull() const 
//	{
//		return top == MAXSIZE-1 ;
//	}
//	T Top() const;
//	void Push(T x);     //压栈
//	T Pop();           //删除顶层元素
//
//private:
//	int top;
//	T data[MAXSIZE];
//	int	MAXSIZE=10;
//};
//template<class T>  
//T Stack<T>::Top() const  // 返回栈顶元素
//{  
//	if (!IsEmpty())    
//		return date[top];  
//}  
//
//template<class T>    
//bool Stack<T>::Push(T x)
//{
//	if (top >= MAXSIZE-1)
//	{
//		return false;
//	}
//	data[++top] = x;
//	return ture;
//}
//template<typename T>
//T Stack<T>::Pop()
//{
//	T temp = data[top];
//	top--;
//	return temp;
//}
//
//
//int main()
//{
//
//	return 0;
//}


template <class T> class Queue;
template <class T>
class linknode
{
	friend class Queue<T>;
private:
	T data;
	linknode<T>* next;
};
template <class T>
class Queue
{
public:
	Queue()
	{
		front=tail=0;
	};
	bool Isempty();
	void Front();
	void Tail();
	void Push(T x);
	void Pop();
private:
	linknode<T> *front;
	linknode<T> *tail;
};

template <class T>
bool Queue<T>::Isempty()
{
	return front==0; 
}

template <class T>
void Queue<T>::Push(T x)
{
	linknode<T> *p=new linknode<T>();
	p->data=x;
	p->next=0;
	cout<<x<<endl;
	if(Isempty())
	{   
		front=tail=p;
	}
	else
	{
		tail->next=p;
		tail=p;
	}  
}

template <class T>
void Queue<T>::Pop()
{   
	if(Isempty())
	{
		cout<<"队列为空，不能出列"<<endl;
	}
	else
	{
		linknode<T>* p=front;
		cout<<front->data<<endl;
		front=front->next;  
		delete p;
	}
}

template <class T>
inline void Queue<T>::Front()
{
	if(!Isempty())
	{
		cout<<"队首元素为"<< front->data<<endl;
	}
	else
	{
		cout<< "队列为空"<<endl;
	}
}

template <class T>
inline void Queue<T>::Tail()
{
	if(!Isempty())
	{
		cout<<"队尾元素为"<< tail->data<<endl;
	}
	else
	{
		cout<< "队列为空"<<endl;
	}
}

int main()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Front();
	q.Tail();
	q.Pop();
	q.Pop();
	q.Pop();
	system("pause");
	return 0;
}