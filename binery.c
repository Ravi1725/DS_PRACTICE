//This program is of basic implementation of binery tree(data structure) and performing basic operation on it.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *right;
	struct node *left;
};

struct node* new_node(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->right =NULL;
	node->left =NULL;

	return(node);
}

//This function is to find out Inorder of binery tree
void Inorder(struct node* node)
{
	if(node==NULL)
		return;


	Inorder(node->left);
	printf("%d",node->data);
	Inorder(node->right);

	}


//This function is to find out pre-order of binery tree
void pre_order(struct node* node)
{
	if(node==NULL)
		return;


	printf("%d",node->data);

	pre_order(node->left);
	pre_order(node->right);

}

//This function is to find post order of binery tree
void post_order(struct node* node)
{
	if(node==NULL)
		return;

	post_order(node->left);
	post_order(node->right);
	printf("%d",node->data);


}

//This function is to insert node with data in tree
struct node* insert(struct node* node,int data)
{
	if(node ==NULL)
		return(new_node(data));

	else
	{
		if(data<=node->data)
			node->left=insert(node->left,data);

		else
		{
			if(data>node->data)
				node->right=insert(node->right,data);
		}

		return node;
	}

	

}

//To find out the minimum value in binery tree
int min_value(struct node* node)
{
	struct node* ref=node;

	while(ref->left!=NULL)
	{
		ref=ref->left;
	}
	return(ref->data);
}


//to find the size(number of nodes in tree) of tree
int size(struct node* node)
{
	if(node==NULL)
		return 0;

	return(size(node->left )+1+ size(node->right));
}

//To check Input data exist in tree or not
int find_data(struct node* node,int x)
{
	if(node->data==x)
		return(node->data);
	else
	{
		if(x<=node->data)
		{
			node=node->left;
			find_data(node,x);
		}

		else
		{
			node=node->right;
			find_data(node,x);
		}

	}
}

int main()
{
	/*struct node *root=new_node(5);
	root->left =new_node(2);
	root->right=new_node(9);
	root->left->left =new_node(3);
	root->left->left->right =new_node(6);*/

	struct node* root =NULL;
	root = insert(root, 4); 
	insert(root,5);
	insert(root,6);
	insert(root,2);
	insert(root,1);
	insert(root,11);
	insert(root,9);


	//printf("%d\n\n\n",root->left->left->right->data);
	Inorder(root);
	printf("\n");
	pre_order(root);
	printf("\n\n");
	post_order(root);

	printf("\n\nMinimum value is %d",min_value(root));
	printf("\n\nsize of binery tree is  %d",size(root));
	printf("\n\nData exist or not is %d",find_data(root, 1));

	printf("\n\n%d",root->right->right->right->left->data);

	return 0;
}