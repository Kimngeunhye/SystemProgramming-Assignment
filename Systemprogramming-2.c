#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct CalculatorNode* startLocation = NULL;

struct CalculatorNode {
   float a;
   float b;
   char name[20];
   int(*fptr)(int, int);
   struct CalculatorNode* next; //���� ����� �ּҸ� ������ ������
};

int add(int, int);
int sub(int, int);
int mul(int, int);
int divs(int, int);

int add(int a, int b)
{
   int result = a + b;
   return result;
}
int sub(int a, int b)
{
   int result = a - b;
   return result;
}
int mul(int a, int b)
{
   int result = a * b;
   return result;
}
int divs(int a, int b)
{
   float result = (float)a / (float)b;
   return result;
}

int main()
{
   while (1) {
      printf("Choose->1.������ 2.�������� 3.����������� 4.����λ��� 5.����:\n");

      int i;
      scanf("%d", &i);

      if (i == 5)
      {
         printf("�����մϴ�");
         break;
      }
      switch (i)
      {
      case 1:
         printf("��� ���� ����Դϴ�. ���� 2�� �Է�\n");

         float a;
         float b;
         char sign;
         printf("Enter the num1:");
         scanf("%f", &a);
         printf("Enter the num2:");
         scanf("%f", &b);
         printf("Enter the Calculator sing(e.g. '+', '-', '*', '/'):");
         scanf("\n%c", &sign);
         struct CalculatorNode* node =malloc(sizeof(struct CalculatorNode));
         node->a = a;
         node->b = b;
         node->next = NULL;

         int(*fptr)(int, int)=NULL;
         int x;

         if (sign == '+')
         {
            fptr = add;
            x = fptr(a, b);
            printf("%d\n", x);
         }
         if (sign == '-')
         {
            fptr = sub;
            x = fptr(a, b);
            printf("%d\n", x);
         }
         if (sign == '*')
         {
            fptr = mul;
            x = fptr(a, b);
            printf("%d\n", x);
         }
         if (sign == '/')
         {
            fptr = divs;
            x = fptr(a, b);
            printf("%d\n", x);
         }

         node->fptr = fptr;

         if (startLocation == NULL) {
            startLocation = node;
         }

         else
         {
            struct CalculatorNode* temp = startLocation;
            if (temp == NULL) {
               startLocation = temp;
            }
            else {
               while (1)
               {
                  if (temp->next == NULL)
                  {
                     temp->next = node;
                     break;
                  }

                  else
                     temp = temp->next;
               }
            }
            printf("��带 �����ϰ� �߰��߽��ϴ�.");
         }

         break;
      case 2:
         if (startLocation == NULL)
         {
            printf("��尡 �ϳ��� ����\n");
         }
         else
         {
            struct CalculatorNode* temp = startLocation;
            while (1)
            {
               if (temp->next == NULL)
                  break;
               else
                  temp = temp->next;
            }
         }

         break;
      case 3:
         if (startLocation == NULL)
         {
            printf("��尡 �ϳ��� ����\n");
         }
         else
         {
            struct CalculatorNode* temp = startLocation;
            while (1)
            {
               printf("%d\n",temp->fptr(temp->a, temp->b));
               if (temp->next == NULL)
               {
                  break;
               }
               else
                  temp = temp->next;
            }
         }

         break;
      case 4:
         if (startLocation == NULL)
         {
            printf("��尡 �ϳ��� �����ϴ�.\n");
         }
         else
         {
            struct CalculatorNode* temp = startLocation;
            while (1)
            {
               struct CalculatorNode* temp2 = temp->next;
               free(temp);
               if (temp2 == NULL)
                  break;
               else
                  temp = temp2;

            }
         }

         break;
      case 5:
         break;
      }
   }
}