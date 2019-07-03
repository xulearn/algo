struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot,unsigned int k){
    if(pRoot == nullptr || k == 0)
        return nullptr;

    return KthNodeCore(pRoot,k);

}

BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot,unsigned int& k){
    BinaryTreeNode* target = nullptr;

    if(pRoot->m_pLeft != nullptr)
        target = KthNodeCore(pRoot->m_pLeft,k);

    if(target == nullptr){
        if(k==1)
            target = pRoot;//   target只在这里赋值，其他地方都赋值为nullptr
        k--;
    }

    if(target == nullptr && pRoot->m_pRight != nullptr){
        target = KthNodeCore(pRoot->m_pRight,k);
    }

    return target;

}