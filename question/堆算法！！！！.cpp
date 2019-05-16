#include<vector>
#include<iostream>

using namespace std;


class heap_algorith
{
public:
	//最大堆放入元素
	void push_heap(int value)
	{
		
		heap.push_back(value);
		__push_heap_aux();
	}
	//最大堆弹出元素
	int pop_heap()
	{
		int res = heap[0];
		__pop_heap_aux(heap.begin(),heap.end());
		heap.pop_back();
		return res;
	}
	//堆排序算法
	void sort_heap()
	{
		__sort_heap();
	}
	int size() const
	{
		return heap.size();
	}
	void print()
	{
		for (auto it : heap)
		{
			cout << it << " ";
		}
		cout << " print over " << endl;
	}
private:
	void __push_heap_aux()
	{
		int value = heap.back();
		int index = heap.size() - 1;
		__push_heap(heap.size() - 1, 0, value);
	}

	void __push_heap(int holeIndex, int topIndex, int value)
	{
		vector<int>::iterator first = heap.begin();
		int parent = (holeIndex - 1) / 2;
		while (holeIndex > topIndex && *(first + parent) < value)
		{
			*(first + holeIndex) = *(first + parent);
			holeIndex = parent;
			parent = (holeIndex - 1) / 2;
		}
		*(first + holeIndex) = value;
	}
	
private:
	void __pop_heap_aux(vector<int>::iterator first,vector<int>::iterator last)
	{
		int value = *(last - 1);
		*(last - 1) = *first;
		__adjust_heap(first,0, last - 1 - first, value);
		
	}

	void __adjust_heap(vector<int>::iterator first,int holeIndex, int len, int value)
	{
		int topIndex = holeIndex;
		int secondChild = 2 * holeIndex + 2;
		while (secondChild < len)
		{
			if (*(first + secondChild) < *(first + secondChild - 1))
				secondChild--;
			*(first + holeIndex) = *(first + secondChild);
			holeIndex = secondChild;
			secondChild = 2 * holeIndex + 2;
		}
		if (secondChild == len)
		{
			*(first + holeIndex) = *(first + secondChild - 1);
			holeIndex = secondChild - 1;
		}
		__push_heap(holeIndex, topIndex, value);
	}
private:
	void __sort_heap()
	{
		vector<int>::iterator first = heap.begin();
		vector<int>::iterator last = heap.end();
		while (last - first > 1)
		{
			__pop_heap_aux(first, last--);
		}
	}

private:
	vector<int> heap;
};
