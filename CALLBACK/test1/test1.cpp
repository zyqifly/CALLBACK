// test1.cpp: 定义应用程序的入口点。
//

#include "test1.h"

using namespace std;


void basketball()//函数1
{
    printf("选择篮球");
}
void football()//函数2
{
    printf("选择足球");
}
void selectball(void (*ball)())//函数3
{
    printf("选择什么球？");
    ball();
}
int main(void)
{
    selectball(basketball);
    selectball(football);
    return 0;
}
