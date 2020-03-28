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
		: mRootNode(std::make_shared<Node<T>>(std::make_unique<T>(0)))
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<Node<T>> node = mRootNode;
		node->Next;
		Node<T>* nodeP = node.get();
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		auto x = std::make_unique<T>();
		std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(std::move(x));
		return temp;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return 0;
	}
}
