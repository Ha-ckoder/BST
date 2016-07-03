#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
 }node;
//create newnode
 node *getnode(int key)
 {
 	node *temp = (node *)malloc(sizeof(node));
 	temp->data=key;
 	temp->left=NULL;
 	temp->right=NULL;
 	return temp;
 }
 //minimum node in subtree
 node *min(node *note)
 {
 		node *current = note;
 	while(current->left!=NULL)
 	{
 		current=current->left;
	}
	 return current;
 }
 //insertion in bst
 node * insert(node *node,int key)
 {
 	if(node==NULL)
 		return getnode(key);
 	if(key<node->data)
 		node->left=insert(node->left,key);
 	else if(node->data<key)
 		node->right=insert(node->right,key);
 	return node;
 }
 
 //detion in bst
 node *deletenode(node *root,int key)
 {
 	if(root==NULL)
 		return root;
 	if(key < (root->data))
 		root->left=deletenode(root->left,key);
 	else if(key>(root->data))
 		root->right=deletenode(root->right,key);
 	else
 	{
 		if(root->left==NULL)
 		{	node  *temp= root->right;
 			
			 free(root);
 			return temp;
 		}
 		else
 		{
 			if(root->right==NULL)
 			{
 				node *temp=root->left;
 				free(root);
 				return temp;
			 }
		 }
		 node * temp = min(root->right);
		 root->data = temp->data;
		 root->right= deletenode(root->right,temp->data);
	 }
	return root;	 
 }
 
 //max height in bst
 int maxheight(node *root)
 {
 	int lchild,rchild;
 	if(root==NULL)
 		return -1;
 	else
 	{
 		lchild = maxheight(root->left);
 		rchild = maxheight(root->right);
 		if(lchild>rchild)
 			return(lchild+1);
 			else
 			return(rchild+1);
 			
	 }
 }
 
 //inorder traversal
void inorder(node *root)
 {
 	if(root!=NULL)
 	{
 		inorder(root->left);
 		printf("%d_",root->data);
 		inorder(root->right);
	}
	
 }
 
 //if the path sum is same as given
 int haspathsum(node *root,int sum)
 {
 	if(root==NULL)
	 	return(sum ==0);
	else
	{
		int subsum = sum - root->data;
		return(haspathsum(root->left,subsum)||haspathsum(root->right,subsum));
		}	
 }
 //max pathsum
  int pathsum(node *root,int subsum,int *max)
 {
 	int sum1,sum2;
 	if(root==NULL)
	 	return;
	 	 subsum = subsum + root->data;
	 	
	 if(root->left==NULL&& root->right==NULL)
	{
		if(*max<subsum)
		{
			*max=subsum;
		//	*leaf=root;
		}
		
		}
		pathsum(root->left,subsum,max);
		pathsum(root->right,subsum,max);
	return (*max);
		
	/*	if(sum1<sum2)
		printf("%d\n",sum2);
		else
		printf("%d\n",sum1);	*/
 }
 
 //mirror bst
 void mirror(node *root)
 {
 	if(root==NULL)
 		return;
 	else
 	{
 		node *temp;
 		mirror(root->left);
 		mirror(root->right);
 		temp = root->left;
 		root->left = root->right;
 		root->right= temp;
	 }
 }
 
 //copying same tree in bst
 void doubletree(node *root)
 {
 	node *temp1;
 	if(root==NULL)
 	return;
 	else
 	{
 		doubletree(root->left);
 		doubletree(root->right);
 		temp1 = root->left;
 		root->left= getnode(root->data);
 		(root->left)->left= temp1;
	 }
 }
 
 //level order traversal
 void printgivenlevel(node *root,int i)
 {
 	if(root==NULL)
 	return;
 	 if(i ==1)
 	printf("%d",root->data);
 	else if(i>1)
 	{
 		printgivenlevel(root->left,i-1);
 		printgivenlevel(root->right,i-1);
	 }
 }
 void levelorder(node *root)
 {
 	int h = maxheight(root)+1;
 	int i;
 	for(i=1;i<=h;i++)
 	{
 		printgivenlevel(root,i);
 		printf("\n");
	 }
	 //printf("\n");
 }
 
 //print path of every subtree
 void printpathrecr(node *root,int path[],int len)
 {
 	if(root==NULL)
 	return;
 	path[len]=root->data;
 	len++;
 	if(root->left==NULL&&root->right==NULL)
 	{
 		int i;
 		for(i=0;i<len;i++)
 		{
 			printf("%d",path[i]);
		 }
		 printf("\n");
	 }
	 else
	 {
	 	printpathrecr(root->left,path,len);
	 	printpathrecr(root->right,path,len);
	 }
 }
 void printpath(node *root)
 {
 	int path[1000];
 	printpathrecr(root,path,0);
 }
 int counttree(int numkey)
 {
 	if(numkey<=1)
 	return 1;
 	else
 	{
 		int sum=0;
 		int left,right,i;
 		for(i=1;i<=numkey;i++)
 		{
 			left=counttree(i-1);
 			right = counttree(numkey-i);
 			sum+= left*right;
 			
		 }
		return sum;
	 }
 	
 }
 // 
  int size(node* node) { 
  if (node==NULL) { 
    return(0); 
  } else { 
    return(node->data+size(node->left)  + size(node->right)); 
  } 
} 
 
 int main()
 {
 	int rslt,n,i,m,key,ht,sum,max=INT_MIN;
 	node *root=NULL,*newnode,*temp,*leaf;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&key);
 		root = insert(root,key);
 		}
 			inorder(root);
 		printf("\n");
 			ht = maxheight(root);
 		printf("%d\n",ht);
 		scanf("%d",&m);	
 			root = deletenode(root,m);
 			inorder(root);
 			ht = maxheight(root);
 		printf("\n%d\n",ht);
 				printpath(root); 
 		
 				printf("%d\n",pathsum(root,0,&max));
 		scanf("%d",&sum);
 			rslt=haspathsum(root,sum);
 		if(rslt==1)
 		{
 		printf("YES\n");
 	}
 		else
 			printf("NO\n");
 				int k = size(root);
 					printf("%d\n",k);

 					//pathsum(root,0,max);
		 			mirror(root);
 					levelorder(root);
 				printf("\n");
 					doubletree(root);
 					levelorder(root);
 					int numkeys,num;
 					scanf("%d",&numkeys);
 					num=counttree(numkeys);
 					printf("%d\n",num);
 					int l = size(root);
 					printf("%d\n",l);
		 return 0;
	 
 }
