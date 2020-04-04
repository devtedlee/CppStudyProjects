#pragma once

#include <memory>
#include <vector>
#include "TreeNode.h"

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRootNode;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = std::make_shared<TreeNode<T>>(std::move(data));

			return;
		}

		std::shared_ptr<TreeNode<T>> node = mRootNode;
		while (node != nullptr)
		{
			if (node->Data <= data)
			{
				if (node->Left == nullptr)
				{
					node->Left = std::make_shared<TreeNode<T>>(node, std::move(data));
					
					break;
				}

				node = node->Left;
			}
			else if (node->Data > data)
			{
				if (node->Right == nullptr)
				{
					node->Right = std::make_shared<TreeNode<T>>(node, std::move(data));

					break;
				}

				node = node->Right;
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		std::shared_ptr<TreeNode<T>> n;
		return n;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		return v;
	}
}