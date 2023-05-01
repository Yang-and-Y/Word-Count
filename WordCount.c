#include <stdio.h>
#include <stdlib.h> //����exit�����ĵ���
#include <string.h>

int main(int argc, char *argv[]) {
    int cNum = 0, wNum = 0; //�洢�ַ����͵�����
    int ch = 0;
    int judge = 0;          //�����Ƿ����
    FILE *fpr;              //�ļ�ָ�룬���ڴ��ļ�
    char name[100] = {0};   //���ڴ洢�ļ�·����
    char type[2];           //���ڴ洢��������ͣ��ַ���-c�򵥴���-w��
    //�жϲ����Ƿ���ȷ
    if(argc != 3) {
        printf("Usage: %s -c/-w filename\n", argv[0]);
        return 1;
    }
    strcpy(type,argv[1]);
    strcpy(name,argv[2]);
    if ((fpr = fopen(name, "r")) == NULL) {     //���ļ�������ʧ�����˳�����
        printf("Can't open %s\n", name);
        exit(1);
    }
    if (type[1] == 'c') {       //ͳ���ַ���
        while ((ch = fgetc(fpr)) != EOF) {
            //���֡���д��ĸ��Сд��ĸ�����з����Ʊ����ո�
            if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 10 || ch == 9 ||
                ch == 32) {
                cNum++;
            }
        }
        printf("�ַ�����%d\n", cNum);
    } else if (type[1] == 'w') {    //ͳ�Ƶ�����
        while ((ch = fgetc(fpr)) != EOF) {
            if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 10 || ch == 9) {
                if (judge == 0) {   //һ�����ʵĿ�ͷ
                    wNum++;
                    judge++;
                }
            } else if (ch == 32 || ch == 44) {  //�ո�Ͷ��ţ��ո�򶺺ŷָ�Ķ���Ϊ����
                judge = 0;          //���ʵĽ���
            }
        }
        printf("��������%d\n", wNum);
    }
    fclose(fpr);    //�ر��ļ���
    return 0;
}
