// 1、从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删元素的值，
// 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
bool remove(seqlist &list,int &num){
    if(list.length==0) return 0;
    int tmp=0;
    for (int i=0;i<list.length;i++){
        if(list.data[i]<list.data[tmp]) tmp=i;
    }
    num=list.data[i];
    list.data[i]=list.data[list.length-1];
    list.length--;
    return 1; 
} 
// 2、设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
void reverse(seqlist &L){
    int tmp;
    for(int i=0;i<L.length/2;i++){
      tmp=L.data[i];
      L.data[i]=L.data[L.length-1-i];
      L.data[L.length-i-1]=tmp;
    }
}
// 3、对长度为n的顺序表L，编写一个时间复杂度为O(n)，空间复杂度为O(1)的算法，删除线性表中所有值为x的数据元素
void remove(seqlist &L,int x){
    int k=0;//代表已经找到几个x
    for(int i=0;i<L.length;){
        if(L.data[i+k]!=x){
          L.data[i]=L.data[i+k];
          i++;
        }
        else{
            k++;
            L.length--;
        }
    }
}

