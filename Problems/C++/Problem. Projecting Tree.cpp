#include <iostream>
using namespace std;

class Node
{
public:
	int Value;
	Node* Left = nullptr;
	Node* Right = nullptr;
	Node* Parent = nullptr;
};

class Tree
{
public:
	Node* Root = nullptr;
	void Add(int elem)
	{
		if (Root == nullptr)
		{
			Root = new Node();
			Root->Value = elem;
		}
		else
		{
			Node* tmp = Root;
			while (tmp != nullptr)
			{
				if (tmp->Value >= elem)
				{
					if (tmp -> Left == nullptr)
					{
						tmp->Left = new Node();
						tmp->Left->Value = elem;
						tmp->Left->Parent = tmp;
						break;
					}
					tmp = tmp->Left;
				}
				else
				{
					if (tmp->Right == nullptr)
					{
						tmp->Right = new Node();
						tmp->Right->Value = elem;
						tmp->Right->Parent = tmp;
						break;
					}
					tmp = tmp->Right;
				}
			}
		}
	}

	bool IsExist(int elem)
	{
		Node* tmp = Root;
		
		while (tmp != nullptr && tmp -> Value != elem)
			if (tmp -> Value > elem)
				tmp = tmp->Left;
			else
				tmp = tmp->Right;
		return tmp != nullptr;
	}

	void Delete(int elem)
	{
		Node* tmp = Root;
		while (tmp != nullptr && tmp->Value != elem)
			if (tmp->Value > elem)
				tmp = tmp->Left;
			else
				tmp = tmp->Right;
		if (tmp)
		{
			Node *Parent = tmp->Parent,
				*r = tmp->Right,
				*l = tmp -> Left;
			if (r != nullptr)
			{
				if (Parent->Left == tmp)
					Parent->Left = r;
				else
					Parent->Right = r;
				r->Parent = Parent;
				while (r->Left != nullptr)
					r = r->Left;
				r->Left = l;
				l->Parent = r;

			}
			else if (l != nullptr)
			{
				if (Parent->Left == tmp)
				{
					Parent->Left = l;
				}
				else
				{
					Parent->Right = l;
				}
				l->Parent = Parent;
			}
			else
			{
				if (Parent->Left == tmp)
					Parent->Left = nullptr;
				else
					Parent->Right = nullptr;
			}
			delete tmp;
		}
	}
};

int main()
{
	Tree test;
	test.Add(5);
	test.Add(6);
	test.Add(8);
	test.Add(1);
	test.Add(4);
	cout << test.IsExist(8);
	test.Delete(8);
	cout << test.IsExist(8);
	system("pause");
}
