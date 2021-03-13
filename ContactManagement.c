#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct Contact {
    char name[50];
    long long number;
};
struct Contact *c[200];
int length=0;
void sort();
void add(int i,char name[50],long long number) {
    c[i]=(struct Contact*)malloc(sizeof(struct Contact));
    strcpy(c[i]->name,name);
    c[i]->number=number;
    sort();
}

void insert(char name[50],long long number) {
    c[length++]=(struct Contact*)malloc(sizeof(struct Contact));
    strcpy(c[length-1]->name,name);
    c[length-1]->number=number;
    sort();
}

void display() {
    printf("\n--------contacts--------\n");
    printf("------------------------\n");
    for(int i=0;i<length;i++)
        printf("%d.\n%s\n%lld\n\n",i+1,c[i]->name,c[i]->number);
        
}
void sort() {
    for(int i=0;i<length-1;i++) {
        for(int j=i+1;j<length;j++) {
            for(int k=0;c[i]->name[k]!='\0'&&c[j]->name[k]!='\0';k++) {
                if(c[i]->name[k]>c[j]->name[k]) {
                    struct Contact* t=c[i];
                    c[i]=c[j];
                    c[j]=t;
                    break;
                }
                else if(c[i]->name[k]<c[j]->name[k]) {
                    break;
                }
            }
        }
        //printf("%d   ",sizeof(c[i]->name));
    }
}
void Delete(int i) { 
    for(int j=i;j<length-1;j++) 
        c[j]=c[j+1];
    length--;
}
//(struct Contact*)malloc(sizeof(struct Contact))
void main() {
    /*
    long long l=9583672357LL;
    insert(c,"SBR",l);
    printf("Calling..... %lld",c->number);
    */
    while(1)
    {
        char s[50];
        long long l;
        printf("\n1:create new contact\n");
        printf("2:show all contacts\n");
        printf("3:add to existing contact\n");
        printf("4:delete the contact\n");
        printf("5:exit\n");
        printf("Choose any option to perform : ");
        int choice,i;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter name : ");
            scanf("%s",s);
            printf("Enter number : ");
            scanf("%lld",&l);
            insert(s,l);
            break;
        case 2:
            display();
            break;
        case 3:
            display();
            printf("Enter the number\nWhich contact do you want to replace : ");
            scanf("%d",&i);
            if(i<1&&i<length) {
                printf("Invalid number");
                break;
            }
            printf("\nEnter name : ");
            scanf("%s",s);
            printf("Enter number : ");
            scanf("%lld",&l);
            add(i-1,s,l);
            break;
        case 4:
            display();
            printf("Enter the number\nWhich contact do you want to delete : ");
            scanf("%d",&i);
            if(i<1&&i<length) {
                printf("Invalid number");
                break;
            }
            Delete(i-1);
            break;
        case 5:
            return;
        default:
            printf("Invalid option ....");
        }
    }
}