#pragma once
#include<functional>
#include<vector>
namespace IceCola
{

	template<class T, class container = std::vector<T>, class compare = std::less<T>>
	class priority_queue
	{
	public:
		priority_queue(){}
		template<class InputIterator>
		priority_queue(InputIterator begin, InputIterator end):_data(begin, end)
		{
			for (int i = _data.size() - 1; i > 0; i--)
			{
				adjustUp(i);
			}
		}

		bool empty() const
		{
			return _data.empty();
		}
		
		size_t size() const
		{
			return _data.size();
		}

		const T& top()
		{
			return _data[0];
		}

		void push(const T& x)
		{
			_data.push_back(x);
			adjustUp(_data.size()-1);
		}

		void pop()
		{
			swap(_data[0], _data[_data.size() - 1]);
			_data.pop_back();
			AdjustDown();
		}

	private:
		container _data;
		compare comp;
		template<class T>
		void swap(T& a, T& b)
		{
			T tmp = a;
			a = b;
			b = tmp;
		}
		void adjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (parent >= 0)
			{
				if (comp(parent, child))
				{
					swap(_data[child],_data[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown()
		{
			int parent = 0;
			int child = parent * 2 + 1;
			while (child < _data.size())
			{
				if (child + 1 < _data.size() && _data[child + 1] > _data[child])
				{
					child = child + 1;
				}
				if (comp(_data[parent], _data[child]))
				{
					swap(_data[parent], _data[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	};
}
