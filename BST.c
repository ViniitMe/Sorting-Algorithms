#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert(struct node *root,int x)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else
	{
		if(x<root->data)
		{
			root->left=insert(root->left,x);
		}
		else if(x>root->data)
		{
			root->right=insert(root->right,x);
		}
		return root;
	}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void main()
{
	int i,n,ch,x;
	struct node *root=NULL;
	printf("choices");
	printf("\n1.Create the BST");
	printf("\n2.Inoder Traverse");
	printf("\n3.exit");
	

	while(1)
	{
		printf("\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the no. of nodes:");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("Enter the data:");
				scanf("%d",& x);
				root=insert(root,x);
			}
			printf("ready");
			break;

			case 2:
			printf("Soterd list:");
			inorder(root);
			break;

			case 3:
			exit(0);
			break;

			default:
			printf("Wrong input!!");
			break;
		}
	}
}