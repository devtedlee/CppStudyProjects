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

		std::shared_ptr<TreeNode<T>> returnNode;
		if (nodeData >= data)
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
				node->Left = std::make_shared<TreeNode<T>>(node, std::move(data));
				tempNode->Parent = node->Left;
				if (tempNode->Data >= data)
				{
					node->Left->Left = tempNode;
				}
				else
				{
					node->Left->Right = tempNode;
				}
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
				node->Right = std::make_shared<TreeNode<T>>(node, std::move(data));
				tempNode->Parent = node->Right;
				if (tempNode->Data >= data)
				{
					node->Left->Left = tempNode;
				}
				else
				{
					node->Left->Right = tempNode;
				}
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
		if (mRootNode == nullptr)
		{
			return false;
		}

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
		if (mRootNode == nullptr)
		{
			return false;
		}

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
				if (*parentNode->Data > *node->Data)
				{
					parentNode->Left.reset();
					parentNode->Left = rightNode;
				}
				else
				{
					parentNode->Right.reset();
					parentNode->Right = rightNode;
				}

				rightNode->Parent = parentNode;
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
					rightNode->Left->Parent = rightNode;
				}
				else
				{
					std::shared_ptr<TreeNode<T>> rightNodeLeft = rightNode->Left;
					while (rightNodeLeft->Left != nullptr)
					{
						rightNodeLeft = rightNodeLeft->Left;
					}

					rightNodeLeft->Left = node->Left;
					rightNodeLeft->Left->Parent = rightNodeLeft;
				}
			}
		}
		else if (node->Left != nullptr)
		{
			std::shared_ptr<TreeNode<T>> leftNode = node->Left;

			if (parentNode != nullptr)
			{
				if (*parentNode->Data > *node->Data)
				{
					parentNode->Left.reset();
					parentNode->Left = leftNode;
				}
				else
				{
					parentNode->Right.reset();
					parentNode->Right = leftNode;
				}

				leftNode->Parent = parentNode;
			}
			else
			{
				mRootNode.reset();
				mRootNode = leftNode;
			}
		}
		else
		{
			if (parentNode != nullptr)
			{
				if (*parentNode->Data > *node->Data)
				{
					parentNode->Left.reset();
				}
				else
				{
					parentNode->Right.reset();
				}
			}
			else
			{
				mRootNode.reset();
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