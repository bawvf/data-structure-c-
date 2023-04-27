#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct List {
    E * array;
    E capactity;
    E size;
};

typedef struct List * ArrayList;

_Bool initList(ArrayList list) {
    list->array = malloc(sizeof (E) * 10);  //�ֶ������ڴ�ռ�
    if (list->array == NULL)
        return 0;
    list->capactity = 10;
    list->size = 0;
    return 1;
}

//����һ��Ԫ��
_Bool insertList(ArrayList list, E element, int index) {
    if (index < 1 || index > list->size + 1 )
        return 0;

    if(list->size == list->capactity) {
        int newcapactity = list->capactity + (list->capactity >> 1);
        E * newArray = realloc(list->array, newcapactity * sizeof(E));
        if (newArray == NULL)
            return 0;
        list->array = newArray;
        list->capactity = newcapactity;
    }

    for (int i = list->size; i > index - 1; --i)
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = element;
    list->size++;
    return 1;
}

//ɾ��һ��Ԫ��
_Bool deletList(ArrayList list, int index) {
    if(index < 1 || index > list->size)
        return 0;
    for (int i = index - 1; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];
    list->size--;
    return 1;
}

//��ȡ����
int sizelist(ArrayList list) {
    return list->size;
}

//��ȡָ��λ���ϵ�Ԫ��
E * getList(ArrayList list, int index) {
    if (index < 1 || index > list->size)
        return NULL;
    return &list->array[index - 1];
}

//Ѱ�ұ����Ԫ�ص�λ��
int findList(ArrayList list, E element) {
    for (int i = 0; i < list->size; ++i)
        if (list->array[i] == element)
            return i + 1;
    return -1;
}

//��дһ���������ڴ�ӡ��ǰ������
void printList(ArrayList list) {
    for (int i = 0; i < list->size; ++i)
        printf("%d ", list->array[i]);
    printf("\n");
}

int main() {
    struct List list;  //�����µĽṹ�����
    if (initList(&list)) {
        for (int i = 0; i < 30; ++i)
            insertList(&list, i * 10, i + 1);
        deletList(&list, 10);
        deletList(&list, 10);
        printList(&list);
        printf("%d\n", list.capactity);
        printf("%d\n", *getList(&list, 3));
        printf("%d", findList(&list, 40));
    } else {
        printf("˳����ʼ��ʧ�ܣ��޷���������");
    }

}