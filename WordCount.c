#include <stdio.h>
#include <stdlib.h> //用于exit函数的调用
#include <string.h>

int main(int argc, char *argv[]) {
    int cNum = 0, wNum = 0; //存储字符数和单词数
    int ch = 0;
    int judge = 0;          //单词是否结束
    FILE *fpr;              //文件指针，用于打开文件
    char name[100] = {0};   //用于存储文件路径名
    char type[2];           //用于存储输入的类型（字符数-c或单词数-w）
    //判断参数是否正确
    if(argc != 3) {
        printf("Usage: %s -c/-w filename\n", argv[0]);
        return 1;
    }
    strcpy(type,argv[1]);
    strcpy(name,argv[2]);
    if ((fpr = fopen(name, "r")) == NULL) {     //打开文件，若打开失败则退出程序
        printf("Can't open %s\n", name);
        exit(1);
    }
    if (type[1] == 'c') {       //统计字符数
        while ((ch = fgetc(fpr)) != EOF) {
            //数字、大写字母、小写字母、换行符、制表符或空格
            if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 10 || ch == 9 ||
                ch == 32) {
                cNum++;
            }
        }
        printf("字符数：%d\n", cNum);
    } else if (type[1] == 'w') {    //统计单词数
        while ((ch = fgetc(fpr)) != EOF) {
            if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 10 || ch == 9) {
                if (judge == 0) {   //一个单词的开头
                    wNum++;
                    judge++;
                }
            } else if (ch == 32 || ch == 44) {  //空格和逗号，空格或逗号分割开的都视为单词
                judge = 0;          //单词的结束
            }
        }
        printf("单词数：%d\n", wNum);
    }
    fclose(fpr);    //关闭文件流
    return 0;
}
