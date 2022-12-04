297. Serialize and Deserialize Binary Tree
Hard

8123

298

Add to List

Share
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    string str="";
	queue<TreeNode*>q;
	q.push(root);
	
	while(!q.empty())
	{
		int size = q.size();
		
		for(int i=0;i<size;i++)
		{
			TreeNode* temp = q.front();
			q.pop();
			
			if(temp==NULL)
			{
				str.append(to_string(-1002));
				str.push_back(',');
				continue;
			}
			else if(temp!=NULL)
			{
				str.append(to_string(temp->val));
				str.push_back(',');
			}
			
			q.push(temp->left);   //if the temp->left is null or not null we will push
			q.push(temp->right);  //if the temp->right is null or not null we will push			
		}
	}
	return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) 
    {

     vector<int>v;
     int idx=0;
     
     while(idx < str.length())
     {
     	string temp="";
     	bool flag=false;  //the num is not neg
     	if(str[idx]=='-')
     	{
     		flag=true;
     		idx++;
        }
     	while(idx<str.length() and str[idx]!=',')
     	{
	    	temp.push_back(str[idx]);
	    	idx++;
        }
        while(idx<str.length() and str[idx]==',')
        {
        	idx++;
		}
		int n = stoi(temp);
		if(flag==true) //if the num is neg
		{
			v.push_back(-1*(n));
		}
		else
		{
			v.push_back(n);
		}
	 }
	//  for(int i=0;i<v.size();i++)
	//  {
	//  	cout<<v[i]<<endl;
	//  }
     if(v.size()==1 and v[0]==-1002)
     return NULL;
     
	 idx=0;
     
	 TreeNode* root=NULL;
	 root=new TreeNode(v[idx]);
	 idx++;
	 
	 queue<TreeNode*>q;
	 q.push(root);
	 
	 while(!q.empty())
	 {
	     int size = q.size();
		 for(int i=0;i<size;i++)
		 {
		    TreeNode* temp = q.front();
			q.pop();	
			
			if(idx<v.size() and v[idx]==-1002)
			{
				temp->left=NULL;
			}
			else if(idx<v.size() and v[idx]!=(-1002))
			{
				temp->left = new TreeNode(v[idx]);
				q.push(temp->left);
			}
			idx++;
			
			
			if(idx<v.size() and v[idx]==-1002)
			{
				temp->right=NULL;
			}
			else if(idx<v.size() and v[idx]!=(-1002))
			{
				temp->right = new TreeNode(v[idx]);
				q.push(temp->right);
			}
			idx++;
		 }	
	 }       
	 
	 return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
