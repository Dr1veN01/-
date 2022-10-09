#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 1000
#define MAX_NAME 20
#define MAX_PHONE 12
#define MAX_REL 30
 
//ö�٣�ѡ����
enum Choose
{
    EXIT,  //0
    ADD,   //1
    DEL,   //2
    SEARCH,//3
    REVISE,//4
    SHOW,  //5
};
 
//�ṹ�壺ͨѶ¼��ÿ����Ա����Ϣ
typedef struct str
{
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char rel[MAX_REL];
}str;
 
////////////////////////////////////////////////////////////////////////////////////
struct Contact
{
    struct str data[MAX];
    int size;//���size�ͽṹ�� 
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void menu()//��ͷ 
{
	printf("\t\t*********************************************\n");
	printf("\t\t*****************ͨѶ¼**********************\n");
	printf("\t\t*********************************************\n");
	printf("\t\t**               0.�˳�                    **\n");
	printf("\t\t**               1.������ϵ��              **\n");
	printf("\t\t**               2.ɾ����ϵ��              **\n");
	printf("\t\t**               3.��ѯ��ϵ��              **\n");
	printf("\t\t**               4.�޸���ϵ��              **\n");
	printf("\t\t**               5.��ʾ������ϵ��************\n");
	printf("\t\t*********************************************\n");
	printf("\t\t*********************************************\n");
	printf("\t\t*********************************************\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////// 

//����һ����Ϣ��ͨѶ¼
void Add(struct Contact *ps)
{
    if(ps->size == MAX)
    {
        printf("ͨѶ¼�������޷�����\n");
    }
    else
    {
        printf("����������:");
        scanf("%s", ps->data[ps->size].name);
        printf("������绰:");
        scanf("%s", ps->data[ps->size].phone);
        printf("�������ϵ:");
        scanf("%s", ps->data[ps->size].rel);
 
        ps->size++;
        printf("��ӳɹ�\n");
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////// 

static int FindByName(const struct Contact *ps, char name[MAX_NAME])
{
    int i = 0;
    for(i = 0; i < ps->size; i++)
    {
        if(0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;//�Ҳ��������
}
//////////////////////////////////////////////////////////////////////////////////////////////////////


//ɾ��ָ������ϵ��
void Del(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("������Ҫɾ���˵�����:>");
    scanf("%s", name);
    
    int pos = FindByName(ps, name);
    
    if (pos == -1)
    {
        printf("��ѯ����Ҫɾ������ϵ�ˣ�������\n");
    }
    else
    {
        //ɾ������
        int j = 0;
        for(j = pos; j < ps->size-1; j++)
        {
            ps->data[j] = ps->data[j + 1];
            //����ɾ����������ݣ����Ժ�������ݻᶥ������
        }
        ps->size--;
        printf("ɾ���ɹ�\n");
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////// /////////

//����ָ�����˵���Ϣ
void Search(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("������Ҫ�����˵�����:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("Ҫ���ҵ��˲�����,������\n");
    }
    else
    {
        printf("%-20s\t%-12s\t%-20s\n", "����","�绰", "��ϵ");
        printf("%-20s\t%-12s\t%-20s\n",
            ps->data[pos].name,
            ps->data[pos].phone,
            ps->data[pos].rel);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

//�޸�ָ����ϵ�˵���Ϣ
void Revise(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("������Ҫ�޸���ϵ�˵�����:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("Ҫ�޸���ϵ�˵���Ϣ�����ڣ�������\n");
    }
    else
    {
        printf("����������:");
        scanf("%s", ps->data[pos].name);
        printf("������绰:");
        scanf("%s", ps->data[pos].phone);
        printf("�������ϵ:");
        scanf("%s", ps->data[pos].rel);
 
        printf("�޸����\n");
    }
}
 
////////////////////////////////////////////////////////////////////////////////////// ////////////////////////////////////

//չʾͨѶ¼�е���Ϣ
void ShowContact(const struct Contact *ps)
{
    if(ps->size == 0)
    {
        printf("ͨѶ¼Ϊ��\n");
    }
    else
    {
        int i = 0;
        
		printf("%-20s\t%-12s\t%-20s\n", "����","�绰", "��ϵ"); //����
        
        for(i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-12s\t%-20s\n",
            ps->data[i].name,
            ps->data[i].phone,
            ps->data[i].rel);
        }//����
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////// 

//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact *ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
int main()
{
    int input = 0;
    //����ͨѶ¼
    struct Contact con;//con����ͨѶ¼�����������1000��Ԫ�ص�����size
    //��ʼ��ͨѶ¼
    InitContact(&con);
    do
    {
        menu();
        printf("��ѡ��:");
        scanf("%d", &input);
        switch(input)
        {
        case ADD:
            Add(&con);
            break;
        case DEL:
            Del(&con);
            break;
        case SEARCH:
            Search(&con);
            break;
        case REVISE:
        	Revise(&con);
        case SHOW:
            ShowContact(&con);
            break;
        case EXIT:
            printf("�˳�ͨѶ¼\n");
            break;
        default:
            printf("ѡ�����\n");
            break;
        }
    } while (input);
    return 0;
}
