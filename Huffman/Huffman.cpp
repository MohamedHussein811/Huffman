#include <iostream>
using namespace std;
class cNode
{
public:
	int info = NULL;
	int ct = NULL;
	char Alpha = NULL;
	char* CompCode = NULL;
	cNode* pNext;
	cNode* pLeft;
	cNode* pRight;
	cNode()
	{
		pNext = NULL;
		pLeft = NULL;
		pRight = NULL;
	}
};

class clist
{
public:
	cNode* phead;
	cNode* ptail;
	clist()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist()
	{
		cNode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pNext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cNode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pNext = pnn;
			ptail = pnn;
		}
	}
	void display()
	{
		cNode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			ptrav = ptrav->pNext;
		}
	}
};
class cstack
{
public:
	cNode* phead;
	cstack()
	{
		phead = NULL;
	}
	~cstack()
	{
		cNode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pNext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void display()
	{
		cNode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			cout << ptrav->Alpha << ",";
			cout << ptrav->info;
			ptrav = ptrav->pNext;
			cout << endl;
		}
	}
	void push(cNode* pnn)
	{
		pnn->pNext = phead;
		phead = pnn;
	}
	cNode* pop()
	{
		cNode* ptrav;
		ptrav = phead;
		phead = ptrav->pNext;
		ptrav->pNext = NULL;
		return ptrav;
	}
};
class CSList
{
public:
	cNode* phead;
	CSList()
	{
		phead = NULL;
	}
	~CSList()
	{
		cNode* ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pNext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void insert(cNode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
		}
		else
		{
			cNode* pb = NULL;
			cNode* ptrav = phead;
			while (ptrav != NULL && ptrav->info < pnn->info)
			{
				pb = ptrav;
				ptrav = ptrav->pNext;
			}
			if (pb != NULL)
			{
				pnn->pNext = ptrav;
				pb->pNext = pnn;
			}
			else
			{
				pnn->pNext = ptrav;
				phead = pnn;
			}
		}
	}
	void display()
	{
		cNode* trav = phead;
		while (trav != NULL)
		{
			cout << trav->Alpha;
			cout << trav->info;
			trav = trav->pNext;
			cout << endl;
		}
		cout << endl;
	}
	cNode* pop()
	{
		cNode* ptrav;
		ptrav = phead;
		phead = ptrav->pNext;
		ptrav->pNext = NULL;
		return ptrav;
	}
	cNode* remove(int v)
	{
		cNode* ptrav = phead;
		cNode* pb = NULL;
		while (ptrav != NULL && ptrav->info != v)
		{
			pb = ptrav;
			ptrav = ptrav->pNext;
		}
		if (pb == NULL)
		{
			//phead = ptrav->pNext;
		}
		return ptrav;
	}
};
class CBTree
{
public:
	cNode* pRoot;
	CBTree()
	{
		pRoot = NULL;
	}
	void attach(cNode* pnn)
	{
		if (pRoot == NULL)
		{
			pRoot = pnn;
		}
		else
		{
			cNode* ptrv = pRoot;
			cNode* pb = NULL;
			while (ptrv != NULL)
			{
				pb = ptrv;
				if (ptrv->info > pnn->info)
				{
					ptrv = ptrv->pLeft;
				}
				else
				{
					ptrv = ptrv->pRight;
				}
			}
			if (pb->info > pnn->info)
			{
				pb->pLeft = pnn;
			}
			else
			{
				pb->pRight = pnn;
			}
		}
	}

};
void Display(cNode* pnn, char Binary[], int value)
{
	if (pnn->Alpha != NULL)
	{
		pnn->CompCode = new char[value];

		cout << pnn->Alpha << " -> ";

		for (int i = 0; i < value; i++)
		{
			pnn->ct++;
			pnn->CompCode[i] = Binary[i];
		}
		pnn->CompCode[value] = NULL;
		cout << pnn->CompCode;
		cout << endl;
		cout << "Bit Counter: " << pnn->ct;
		cout << endl << endl;
		return;
	}
	Binary[value] = '0';
	Display(pnn->pLeft, Binary, value + 1);
	Binary[value] = '1';
	Display(pnn->pRight, Binary, value + 1);
}
void Converter(cNode* ptrav, CSList& L, cNode* pnn)
{
	if (ptrav == NULL)
	{
		return;
	}
	Converter(ptrav->pLeft, L, pnn);
	if (ptrav->Alpha != NULL)
	{
		pnn = new cNode;
		pnn = ptrav;
		pnn->pNext = NULL;
		pnn->pRight = NULL;
		pnn->pLeft = NULL;
		L.insert(pnn);
	}
	Converter(ptrav->pRight, L, pnn);
}
int main()
{
	CSList L, L2;
	cNode* pnn;
	char x[9999];
	cout << "Enter your paragraph" << endl;
	gets_s(x);
	cout << "\n----------------------------\n";
	pnn = new cNode;
	pnn->Alpha = x[0];
	pnn->info = 0;
	pnn->ct = 0;
	L.insert(pnn);
	//Phase One
	//Counting frequency
	for (int i = 0; x[i] != NULL; i++)
	{
		int flag = 0;
		cNode* ptrav = L.phead;
		while (ptrav != NULL)
		{
			if (ptrav->Alpha == x[i])
			{
				ptrav->info++;
				flag = 1;
			}
			else
			{
				if (flag == 0 && ptrav->pNext == NULL)
				{
					pnn = new cNode;
					pnn->Alpha = x[i];
					pnn->info = 1;
					pnn->ct = 0;
					pnn->pNext = NULL;
					pnn->pRight = NULL;
					pnn->pLeft = NULL;
					L.insert(pnn);
				}
			}
			ptrav = ptrav->pNext;
		}
	}
	//Sorting List
	cNode* ptrav = L.phead;
	while (ptrav != NULL)
	{
		ptrav = ptrav->pNext;
		pnn = L.pop();
		pnn->pNext = NULL;
		pnn->pRight = NULL;
		pnn->pLeft = NULL;
		L2.insert(pnn);
	}
	//Creating Binary Tree 
	while (L2.phead->pNext != NULL)
	{
		cNode* PTrav1 = L2.pop();
		cNode* PTrav2 = L2.pop();
		pnn = new cNode;
		pnn->Alpha = NULL;
		pnn->info = PTrav1->info * 2;
		pnn->pNext = NULL;
		//Inserting Values
		if (PTrav1->info > PTrav2->info)
		{
			pnn->pLeft = PTrav1;
			pnn->pRight = PTrav2;
		}
		else
		{
			pnn->pRight = PTrav1;
			pnn->pLeft = PTrav2;
		}
		L2.insert(pnn);
	}
	pnn = L2.pop();
	CBTree T;
	char Binary[999];
	T.pRoot = pnn;

	cout << endl;
	Display(T.pRoot, Binary, 0);
	cout << "\n---------------------------\n";

	//Phase Two
	int Xct = 0;
	for (int i = 0; x[i] != NULL; i++)
	{
		Xct++;
	}
	Converter(T.pRoot, L, pnn);

	//Compression
	char Encrypto[9999] = {}, mask = 1;
	int iBit = 7, temp = 0, k = 0, c = 0;
	cNode* CompTrav = NULL;
	for (int i = 0; x[i] != NULL; i++)
	{
		k = 0;
		CompTrav = NULL;
		CompTrav = L.phead;
		while (1)
		{
			if (CompTrav->CompCode[k] == NULL)
			{
				break;
			}
			//Searching for target Alpha
			if (CompTrav->Alpha == x[i])
			{
				if (CompTrav->CompCode[k] == '1')
				{
					temp = temp | (mask << iBit);
				}
				iBit--;
				k++;
				if (iBit < 0)
				{
					Encrypto[c] = temp;
					c++;
					iBit = 7;
					temp = 0;
				}
			}
			else
			{
				while (CompTrav->Alpha != x[i])
				{
					CompTrav = CompTrav->pNext;
				}
			}
		}
	}
	Encrypto[c] = NULL;
	cout << endl << "Encrypto:\n\n";
	for (int i = 0; Encrypto[i] != NULL; i++)
	{
		cout << Encrypto[i];
	}
	//End of Compression

	//Decompression
	char Decrypto[9999] = {};
	int Res = 0, ct = 0, i = 0, D = 0;
	cNode* DeTrav = NULL;
	clist L3;
	CompTrav = L.phead;
	iBit = 7;
	for (i = 0; Encrypto[i] != NULL; )
	{
		Res = Encrypto[i] & (mask << iBit);
		if (Res != 0)
		{
			DeTrav = new cNode;
			DeTrav->pNext = NULL;
			DeTrav->info = '1';
		}
		else
		{
			DeTrav = new cNode;
			DeTrav->pNext = NULL;
			DeTrav->info = '0';
		}
		L3.attach(DeTrav);
		CompTrav = L.phead;
		while (CompTrav != NULL && DeTrav != NULL)
		{
			ct = 0;
			DeTrav = L3.phead;
			for (int k = 0; k < CompTrav->ct; k++)
			{
				if (DeTrav->info == CompTrav->CompCode[k])
				{
					ct++;
					if (DeTrav->pNext == NULL)
					{
						break;
					}
					DeTrav = DeTrav->pNext;
					if (ct == CompTrav->ct)
					{
						break;
					}
				}
				else
				{
					ct = 0;
					break;
				}
			}
			if (ct == CompTrav->ct)
			{
				Decrypto[D] = CompTrav->Alpha;
				D++;
				L3.~clist();
				break;
			}
			CompTrav = CompTrav->pNext;
		}
		iBit--;
		if (iBit < 0)
		{
			iBit = 7;
			Res = 0;
			i++;
		}
	}

	Decrypto[D] = NULL;
	cout << endl << endl << "Decrypto:\n\n";
	for (int Dec = 0; Decrypto[Dec] != NULL; Dec++)
	{
		cout << Decrypto[Dec];
	}
	cout << endl;
	//End of Decompression
}
