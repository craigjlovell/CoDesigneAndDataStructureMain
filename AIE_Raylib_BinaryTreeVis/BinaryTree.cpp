

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

void BinaryTree::InsertMain(TreeNode*& root, TreeNode* nodeToInsert)
{
	// TODO    	

	if (nodeToInsert == nullptr)
	{
		return;
	}

	if (IsEmpty())
	{
		root = new TreeNode(nodeToInsert->GetData());
		return;
	}
	
	TreeNode* current = root;
	TreeNode* previous = nullptr;
	
	while (current != nullptr)
	{
		if (nodeToInsert->GetData() == current->GetData())
		{
			return;
		}
		else if (nodeToInsert->GetData() < current->GetData())
		{
			previous = current;
			current = current->GetLeft();
		}
		else if (nodeToInsert->GetData() > current->GetData())
		{
			previous = current;
			current = current->GetRight();				
	    }		
	}
	
	if (nodeToInsert->GetData() < previous->GetData())
	{
		previous->SetLeft(new TreeNode(nodeToInsert->GetData()));
	}
	else
	{
		previous->SetRight(new TreeNode(nodeToInsert->GetData()));
	}
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	InsertMain(m_pRoot, new TreeNode(a_nValue));

	return;

}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* n = m_pRoot;

	bool find = false;
	while (!find)
	{
		if (n == nullptr)
		{
			find = true;
		}
		else if (n->GetData() == a_nValue)
		{
			find = true;
		}
		else if (a_nValue < n->GetData())
		{
			if (n != nullptr)
			{
				n = n->GetLeft();
			}
		}
		else if (a_nValue > n->GetData())
		{
			if (n != nullptr)
			{
				n = n->GetRight();
			}
		}
	}

	return n;

	// return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	RemoveMain(a_nValue, m_pRoot, m_pRoot);
}

void BinaryTree::RemoveMain(int val, TreeNode* root, TreeNode* n)
{
	if (n->GetData() == val)
	{
		TreeNode* child = n;
		
		InsertMain(root, child->GetLeft());
		InsertMain(root, child->GetRight());
		child = nullptr;
		delete child;

	}
	else if (n->GetLeft()->GetData() == val)
	{
		TreeNode* child = n->GetLeft();
		n->SetLeft(nullptr);
		InsertMain(root, child->GetLeft());
		InsertMain(root, child->GetRight());
		delete child;
	}
	else if (n->GetRight()->GetData() == val)
	{
		TreeNode* child = n->GetRight();
		n->SetRight(nullptr);
		InsertMain(root, child->GetLeft());
		InsertMain(root, child->GetRight());
		delete child;
	}
	else if (val < n->GetData())
	{
		RemoveMain(val, root, n->GetLeft());
	}
	else if (val > n->GetData())
	{
		RemoveMain(val, root, n->GetRight());
	}
	else if (val == n->GetData())
	{
		RemoveMain(val, root, n);
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