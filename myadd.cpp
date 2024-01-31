#include <iostream>
#include <windows.h>
int addx(int a, int b);

const unsigned char codes[] = {0x55,0x48,0x89,0xe5,0x89,0x4d,0x10,0x89,0x55,0x18,0x8b,0x55,0x10,0x8b,0x45,0x18,0x01,0xd0,0x5d,0xc3};

int main() {
    int a = 5;
    int b = 6;
    int (*func_ptr) (int x, int y);
    /*
     * 在windows的进程中分配一块内存区域(虚拟内存中分配的)
     * todo 在进程地址空间分配一块内存,大小为sizeof(codes),并设置为可执行,可读写
     * */
    void * exec_mem = VirtualAlloc(0,sizeof(codes),MEM_COMMIT,PAGE_EXECUTE_READWRITE);
    /*
     * todo 将机器指令拷贝到刚刚分配的执行内存中
     * */
    memcpy(exec_mem, codes, sizeof(codes));
    func_ptr = (int(*)(int,int))exec_mem;
    int ret = func_ptr(a,b);
    std::cout << "ret: " << ret << std::endl;
    /*
     * todo 释放内存
     * */
    VirtualFree(exec_mem,0,MEM_RELEASE);
    return 0;
}

//将这段代码转换为机器码之后执行
int addx(int x, int y) {
    return x + y;
}