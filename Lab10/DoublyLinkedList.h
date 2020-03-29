#pragma once

#include <memory>
#include "Node.h"

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		std::shared_ptr<Node<T>> mRootNode;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = std::make_shared<Node<T>>(std::move(data));
			return;
		}

		std::shared_ptr<Node<T>> node = mRootNode;
		while (node->Next != nullptr)
		{
			node = node->Next;
		}

		node->Next = std::make_shared<Node<T>>(std::move(data), node);
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = std::make_shared<Node<T>>(std::move(data));
			return;
		}

		std::shared_ptr<Node<T>> node = mRootNode;
		for (unsigned int i = 1; i < index; ++i)
		{
			if (node->Next == nullptr)
			{
				break;
			}

			node = node->Next;
		}

		if (index == 0)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
			newNode->Next = node;
			newNode->Next->Previous = newNode;
			mRootNode.reset();
			mRootNode = newNode;

			return;
		}

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), node);
		if (node->Next != nullptr)
		{
			newNode->Next = node->Next;
			newNode->Next->Previous = newNode;
			node->Next.reset();
		}
		node->Next = newNode;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> node = mRootNode;
		while (node != nullptr)
		{
			if (*(node->Data) == data)
			{
				std::shared_ptr<Node<T>> previousNode;
				std::shared_ptr<Node<T>> nextNode;

				if (node->Previous.expired())
				{
					nextNode = node->Next;
					node->Next.reset();
					node.reset();
					mRootNode = nextNode;
				}
				else
				{
					previousNode = node->Previous.lock();

					if (node->Next != nullptr)
					{
						previousNode->Next = node->Next;
						previousNode->Next->Previous = previousNode;
						node->Next.reset();
					}
					else
					{
						previousNode->Next.reset();
					}

					node.reset();
				}

				return true;
			}

			node = node->Next;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> node = mRootNode;
		while (node != nullptr)
		{
			if (*(node->Data) == data)
			{
				return true;
			}

			node = node->Next;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		std::shared_ptr<Node<T>> node = mRootNode;
		for (unsigned int i = 0; i < index; ++i)
		{
			if (node == nullptr)
			{
				break;
			}

			node = node->Next;
		}

		return node;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		unsigned int count = 0;
		std::shared_ptr<Node<T>> node = mRootNode;
		while (node != nullptr)
		{
			++count;
			node = node->Next;
		}

		return count;
	}
}
