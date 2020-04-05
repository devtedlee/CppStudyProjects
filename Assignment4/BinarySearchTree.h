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
		std::shared_ptr<TreeNode<T>> searchTreeRecursive(std::shared_ptr<TreeNode<T>> node, const T& data);
		static void traverseRecursive(const std::shared_ptr<TreeNode<T>> node, std::vector<T>& outVector);
	};

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::searchTreeRecursive(std::shared_ptr<TreeNode<T>> node, const T& data)
	{
		T nodeData = *node->Data;

		if (nodeData == data)
		{
			return node;
		}

		std::shared_ptr<TreeNode<T>> returnNode;
		if (nodeData > data)
		{
			if (node->Left != nullptr)
			{
				returnNode = searchTreeRecursive(node->Left, data);
			}
			else
			{
				return node;
			}
		}
		else
		{
			if (node->Right != nullptr)
			{
				returnNode = searchTreeRecursive(node->Right, data);
			}
			else
			{
				return node;
			}
		}

		return returnNode;
	}

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = std::make_shared<TreeNode<T>>(std::move(data));

			return;
		}

		std::shared_ptr<TreeNode<T>> node = searchTreeRecursive(mRootNode, *data);
		if (*node->Data >= *data)
		{
			if (node->Left == nullptr)
			{
				node->Left = std::make_shared<TreeNode<T>>(node, std::move(data));
			}
			else
			{
				std::shared_ptr<TreeNode<T>> tempNode = node->Left;
				node->Left.reset();
				node->Left = std::make_shared<TreeNode<T>>(node, std::move(data));
				node->Left->Left = tempNode;
				tempNode->Parent = node->Left;
			}
		}
		else
		{
			if (node->Right == nullptr)
			{
				node->Right = std::make_shared<TreeNode<T>>(node, std::move(data));
			}
			else
			{
				std::shared_ptr<TreeNode<T>> tempNode = node->Right;
				node->Right.reset();
				node->Right = std::make_shared<TreeNode<T>>(node, std::move(data));
				node->Right->Right = tempNode;
				tempNode->Parent = node->Right;
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRootNode;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> node = searchTreeRecursive(mRootNode, data);
		if (*node->Data != data)
		{
			return false;
		}

		return true;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> node = searchTreeRecursive(mRootNode, data);
		if (*node->Data != data)
		{
			return false;
		}

		std::shared_ptr<TreeNode<T>> parentNode;
		if (!node->Parent.expired())
		{
			parentNode = node->Parent.lock();
		}

		if (node->Right != nullptr)
		{
			std::shared_ptr<TreeNode<T>> rightNode = node->Right;

			if (parentNode != nullptr)
			{
				if (*parentNode->Data > *rightNode->Data)
				{
					parentNode->Left.reset();
					parentNode->Left = rightNode;
				}
				else
				{
					parentNode->Right.reset();
					parentNode->Right = rightNode;
				}
			}
			else
			{
				mRootNode.reset();
				mRootNode = rightNode;
			}

			if (node->Left != nullptr)
			{
				if (rightNode->Left == nullptr)
				{
					rightNode->Left = node->Left;
				}
				else
				{
					std::shared_ptr<TreeNode<T>> rightNodeLeft = rightNode->Left;
					while (rightNodeLeft->Left != nullptr)
					{
						rightNodeLeft.reset();
						rightNodeLeft = rightNodeLeft->Left;
					}

					rightNodeLeft->Left = node->Left;
				}
			}
		}
		else if (node->Left != nullptr)
		{
			std::shared_ptr<TreeNode<T>> leftNode = node->Left;

			if (parentNode != nullptr)
			{
				if (*parentNode->Data > *leftNode->Data)
				{
					parentNode->Left.reset();
					parentNode->Left = leftNode;
				}
				else
				{
					parentNode->Right.reset();
					parentNode->Right = leftNode;
				}
			}
			else
			{
				mRootNode.reset();
				mRootNode = leftNode;
			}
		}

		return true;
	}

	template<typename T>
	void BinarySearchTree<T>::traverseRecursive(const std::shared_ptr<TreeNode<T>> node, std::vector<T>& outVector)
	{
		if (node == nullptr)
		{
			return;
		}

		traverseRecursive(node->Left, outVector);

		outVector.push_back(*(node->Data));

		traverseRecursive(node->Right, outVector);
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;

		traverseRecursive(startNode, v);

		return v;
	}
}