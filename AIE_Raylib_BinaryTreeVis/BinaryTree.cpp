

#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{

	if (IsEmpty())
	{
		m_pRoot = new TreeNode(a_nValue);
		return;
	}

    TreeNode* current = m_pRoot;
    TreeNode* previous = nullptr;

    while (current != nullptr)
    {
		if (a_nValue == current->GetData())
		{
			return;
		}
		else if (a_nValue < current->GetData())
		{
			previous = current;
			current = current->GetLeft();
		}
		else if (a_nValue > current->GetData())
		{
			previous = current;
			current = current->GetRight();				
        }		
    }

	if (a_nValue < previous->GetData())
	{
		previous->SetLeft(new TreeNode(a_nValue));
	}
	else
	{
		previous->SetRight(new TreeNode(a_nValue));		
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = m_pRoot;
	TreeNode* pParent = nullptr;

	bool find = false;
	while (pCurrent != nullptr)
	{
		if (pCurrent == nullptr)
		{
			find = true;
		}
		else if (pCurrent->GetData() == a_nValue)
		{
			find = true;
		}
		else if (a_nValue < pCurrent->GetData())
		{
			if (pCurrent != nullptr)
			{
				pCurrent = pCurrent->GetLeft();
			}
		}
		else if (a_nValue > pCurrent->GetData())
		{
			if (pCurrent != nullptr)
			{
				pCurrent = pCurrent->GetRight();
			}
		}
	}
	return pCurrent;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{


	return false;
}

void BinaryTree::Remove(int a_nValue)
{

}

void BinaryTree::RemoveMain(int val, TreeNode* m_pRoot, TreeNode* n)
{
	if (n->GetLeft->value == val)
	{
		TreeNode* child = n->GetLeft;
		n->GetLeft = nullptr;
		Insert(m_pRoot, child->GetLeft);
		Insert(m_pRoot, child->GetRight);
		delete child;
	}
	else if (n->GetRight->GetData == val)
	{
		TreeNode* child = n->GetRight;
		n->GetRight = nullptr;
		Insert(root, child->GetLeft);
		Insert(root, child->GetRight);
		delete child;
	}
	else if (val < n->value)
	{
		RemoveMain(val, root, n->GetLeft);
	}
	else if (val > n->value)
	{
		RemoveMain(val, root, n->GetRight);
	}
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}