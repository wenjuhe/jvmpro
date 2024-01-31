#include <stdio.h>
#include <windows.h>

/*
 * todo  C/C++如何兼容各大平台
 *      简单的代码依赖编译器 windows ---> mingw64  linux ---> gcc
 *      复杂的代码 条件编译
 * */


/**
 * 子线程
 */
DWORD WINAPI threadCallBack(LPVOID lpParam) {
    for (int i = 0; i < 3; i++) {
        Sleep(1000);
        printf("This is a thread.\n");
    }
    return 0;
}

/**
 * 主函数
 */
int main() {
    HANDLE hThread;
    DWORD dwThreadId;
    //win下创建线程用CreateThread接口
    hThread = CreateThread(NULL, 0, threadCallBack, NULL, 0, &dwThreadId);

    if (hThread == NULL) {
        printf("Create thread error\n");
        return 1;
    }
    //主线程执行3次
    for (int i = 0; i < 3; i++) {
        Sleep(1000);
        printf("This is main thread.\n");
    }
    //相当于join
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}
