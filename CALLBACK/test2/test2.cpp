// test1.cpp: 定义应用程序的入口点。
//

#include "test2.h"





int main(void)
{
    A   a;
    //a.machine.function(action, &a);
    a.actionByA1();
    a.actionByA2();
    //Machine m;
    //m.function(action, NULL);//这样也能运行，只不过，不知道让谁执行action；如果没有对象A，可以执行别的事情
    return 0;
}
