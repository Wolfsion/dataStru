#include "main.h"

//for cmake
#include "./linear/linear.h"
#include "./algorithm/algorithm.h"
#include "./tree/binaryTree.h"

// //for vs beta
// #include "./linear/linear.cpp"
// #include "./algorithm/expEval.cpp"
// #include "./algorithm/LRU.cpp"
// #include "./tree/binaryTree.cpp"
// #include "log.cpp"

void procSpace() {

}

void procExit(SqList &L) {
    if (destroySqList(L)) {
        LogHandle(LOG_INFO, "procExit", "success");
    }else {
        LogHandle(LOG_ERROR, "procExit", "error");
    }
}

void procExit(SeqList &L) {
    if (destroySeqList(L)) {
        LogHandle(LOG_INFO, "procExit", "success");
    }else {
        LogHandle(LOG_ERROR, "procExit", "error");
    }
}

//中途执行异常时释放单链表
void procExit(LinkList &L) {
    if (destroyLinkList(L)) {
        LogHandle(LOG_INFO, "procExit", "success");
    }else {
        LogHandle(LOG_ERROR, "procExit", "error");
    }
}

void procExit(DLinkList &L) {
    
}

void testForSqList() {
    SqList list;
    initSqList(list);
    serAssignSqList(list);

    insertSqList(list, 2, 4);

    int element;
    deleteSqList(list, 2, element);
    string strTest = " delete:" + to_string(element);
    LogHandle(LOG_INFO, "testForSqList", strTest);
    showSqList(list);

    cout << "search num 2:" << locateSqList(list, 2) <<endl;
    cout << "get order 1:" << getElementSqList(list, 1) <<endl;

    procExit(list);
}

void testForSeqList() {
    SeqList list;
    initSeqList(list);
    increaseSizeSeqList(list, 5);
    procExit(list);
}

//测试脚本
void testForLinkList() {
    LinkList list;
    serInitLinkList(list);
    int len = getLenLinkList(list);
    string strTest1 = "length:" + to_string(len);
    LogHandle(LOG_INFO, "testForLinkList", strTest1);
    insertLinkList(list, 4, 4);
    int element1, element2 = 0;
    deleteLinkList(list, 3, element1);
    deleteLinkList(list, 3, element2);
    string strTest2 = "del:" + to_string(element1) + " del:" + to_string(element2);
    LogHandle(LOG_INFO, "testForLinkList", strTest2);

    //最标准的测试实例编写，包括异常判断，发生异常时释放堆空间并直接返回不执行下面内容
    int ret1 = getElementLinkList(list, 2);
    int ret2 = locateLinkList(list, 2);
    if (ret1 == EXE_FAILURE || ret2 == EXE_FAILURE) {
        procExit(list);
        return;
    }
    string strTest3 = "get elem-2:" + to_string(ret1) + " locate ord-2:" + to_string(ret2);
    LogHandle(LOG_INFO, "testForLinkList", strTest3);

    reverseLinkList(list);
    showLinkList(list);
    destroyLinkList(list);                 //无异常执行时释放单链表
}

void testForAlg() {
    //printf("%d",getExpressionValue("1*(2+3)-8/4"));
    LRUCache cache = LRUCache(3);
    cache.put(1,1);
    cache.put(2,2);
    cache.put(3,3);
    cache.put(4,4);
    cache.view();
}

void testForBinTree() {
    vector<int> nums{1, 2, STOP_NUM, 4, STOP_NUM, STOP_NUM, 3};
    Tree root;
    initBinaryTree(root, nums);
    showBinaryTree(root);
    destoryBinaryTree(root);
}

int main() {
    testForBinTree();
    system("pause");
    return 0;
}