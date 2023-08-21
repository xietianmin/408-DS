#include <iostream>
using namespace std ;

#define initialsize 10

struct seqlist{
    int *data;//指示动态分配数组的指针
    int length,maxsize;//表明顺序表的长度
};
void initial(seqlist &list);
void increasesize(seqlist &list,int len);//函数声明
bool insert(seqlist &list,int i,int num);
bool remove(seqlist &list,int i,int &num);
int  find(seqlist list,int num);
int main(){
    seqlist list;
    initial(list);
    increasesize(list,5);
    for(int i=1;i<=5;i++) insert(list,i,i);
    cout<<find(list,5)<<endl;
    cout<<find(list,6)<<endl;

}

void initial(seqlist &list){//初始化一个固定长度的空顺序表
     list.data=new int[initialsize];
     list.length=0;
     list.maxsize=initialsize;
}
void increasesize(seqlist &list,int len){//增加顺序表的长度
   int *p= list.data;
   list.data=new int[list.maxsize+len];
   for(int i=0;i<list.maxsize;i++){
    list.data[i]==p[i];
   }
   list.maxsize+=len;
}

bool insert(seqlist &list,int i,int num){//在第i位插入数字num
 if(list.length==list.maxsize) return 0;
 if(i<1||i>list.length+1) return 0;
 for (int j=list.length;j>=i-1;j--){
    list.data[j]=list.data[j-1];
 }
    list.data[i-1]=num;
    list.length++;
    return 1;
}
bool remove(seqlist &list,int i,int &num){//删除第i个位置处的数字，并返回保存到num
    if(i<1||i>list.length) return 0;
    num=list.data[i-1];
    for(int j=i-1;j<list.length-1;j++){
        list.data[j]=list.data[j+1];
    }
    list.length--;
    return 1;
}
int  find(seqlist list,int num){//找到目标数所在的位置，返回值代表是第几个数字
   for(int i=0;i<list.length;i++){
       if(list.data[i]==num) return i+1;
   }
   return 0;
}