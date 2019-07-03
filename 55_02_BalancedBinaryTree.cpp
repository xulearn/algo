struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

int TreeDepth(BinaryTreeNode* pRoot){
    if(pRoot == nullptr)
        return 0;
    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);

    return (left>right) ? (left+1):(right+1);
}


bool IsBalanced(BinaryTreeNode* pRoot){
    if(pRoot == nullptr)
        return true;
    int left = TreeDepth(pRoot->m_pLeft);//一层递归
    int right = TreeDepth(pRoot->m_pRight);
    int diff = left - right;

    if(diff>1 || diff<-1){
        return false;
    }

    return IsBalanced(pRoot->m_pLeft) && IsBalanced(pRoot->m_pRight);//另一层递归

    //两层递归，有的节点会被重复遍历

}

/*-----------------------------------------------------------------------------------------*/
//以下采用后续遍历的方式

bool IsBalanced(BinaryTreeNode* pRoot,int* pDepth){
    if(pRoot == nullptr){
        *pDepth = 0;    //&left,&right 就是*pDepth。 即第一次更新left和right就是在这里
        return true;
    }

    int left,right;
    if(IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)){
        int diff = left - right;
        if(diff<=1 && diff>=-1){
            *pDepth = 1+(left>right ? left: right);
            return true;
        }

    }
    return false;


}

