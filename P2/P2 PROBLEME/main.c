#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PROBLEMA 2

#define SIZE 100

/*typedef struct STUDENT {
    char nume[20];
}STUDENT;

typedef struct CONFERINTA {
    STUDENT studenti[SIZE];
    int nr_studenti;
    int id;
    char parola[20];
    struct CONFERINTA *next;
}CONFERINTA;

CONFERINTA *creare_nod(int id,const char *parola,CONFERINTA *next) {
    CONFERINTA *aux=NULL;
    if ((aux=(CONFERINTA*)malloc(sizeof(CONFERINTA)))==NULL) {
        perror(NULL);
        exit(-1);
    }
    aux->id=id;
    strcpy(aux->parola,parola);
    aux->next=next;
    aux->nr_studenti=0;
    return aux;
}

CONFERINTA *add_conferinta(CONFERINTA *lista,int id,const char *parola) {
    CONFERINTA *p=NULL;
    p=lista;
    while (p) {
        if (p->id==id) {
            printf("it's already here bro:(\n");
            return lista;
        }
        p=p->next;
    }

    if (lista==NULL || lista->id>id)
        lista=creare_nod(id,parola,lista);
    else {
        p=lista;
        while (p->next!=NULL && p->next->id<id)
            p=p->next;
        if (p->next==NULL)
            p->next=creare_nod(id,parola,NULL);
        else {
            CONFERINTA *q=p->next;
            p->next=creare_nod(id,parola,q);
        }
    }
    return lista;
}

void afisare(CONFERINTA *lista) {
    CONFERINTA *p=lista;
    while (p) {
        printf("CONFERINTA %d - ",p->id);
        for (int i=0;i<p->nr_studenti;i++)
            printf("%s ",p->studenti[i].nume);
        p=p->next;
        printf("\n");
    }
    printf("\n");
}

CONFERINTA *add_student(CONFERINTA *lista,const char *nume,int id) {
    CONFERINTA *p=lista;
    while (p) {
        if (p->id==id) {
            if (p->nr_studenti>=SIZE) {
                printf("no more space for students bro:(\n");
                return lista;
            }
            strcpy(p->studenti[p->nr_studenti].nume,nume);
            p->nr_studenti++;
        }
        p=p->next;
    }
    return lista;
}

CONFERINTA *reverse(CONFERINTA *lista,int id) {
    CONFERINTA *p=lista;
    int ok=0;

    while (p) {
        if (p->id==id) {
            ok=1;
            STUDENT aux[SIZE];
            int index=0;
            for (int i=p->nr_studenti-1;i>=0;i--) {
                aux[index]=p->studenti[i];
                index++;
            }
            for (int i=0;i<p->nr_studenti;i++)
                p->studenti[i]=aux[i];
        }
        p=p->next;
    }
    return lista;
}

void eliberare(CONFERINTA *lista) {
    CONFERINTA *p=NULL;
    while (lista) {
        p=lista->next;
        free(lista);
        lista=p;
    }
}

void liste() {
    CONFERINTA *lista=NULL;
    lista=add_conferinta(lista,2,"abcdef");
    lista=add_conferinta(lista,1,"abcdef");
    lista=add_conferinta(lista,4,"abcdef");
    lista=add_conferinta(lista,3,"abcdef");

    lista=add_student(lista,"Alexandra",1);
    lista=add_student(lista,"Nicoleta",1);
    lista=add_student(lista,"Lica",1);
    lista=add_student(lista,"Lica",2);
    lista=add_student(lista,"Bogdan",2);
    lista=add_student(lista,"Livi",3);
    lista=add_student(lista,"Alexandra",3);
    lista=add_student(lista,"Nicoleta",4);
    lista=add_student(lista,"Levi",4);

    afisare(lista);
    lista=reverse(lista,3);
    lista=reverse(lista,1);
    afisare(lista);
    eliberare(lista);
}*/

/*void inserare_ordonata(int v[],int x,int *size) {
    int j;
    for (int i=0;i<*size;i++) {
        if (v[i]>x) {
            (*size)++;
            for (j=*size-1;j>i;j--)
                v[j]=v[j-1];
            v[i]=x;
            return;
        }
    }
    v[*size]=x;
    (*size)++;
}*/

//PROBLEMA 3

int n=7;
int v[8]={0};

int valid(int k) {
    if (k+1>n)
        return 0;
    for (int i=1;i<=k;i++)
        if (v[i-1]%2==v[i]%2)
            return 0;
    return 1;
}

int solutie(int k) {
    if (v[k]==2 || v[k]==5 || v[k]==7)
        return 1;
    return 0;
}

void afisare(int k) {
    for (int i=0;i<=k;i++)
        printf("%d",v[i]);
    printf("\n");
}

void back(int k) {
    if (k-1==n)
        return;
    for (int i=0;i<9;i++) {
        v[k]=i;
        if (valid(k)) {
            if (solutie(k))
                afisare(k);
            else
                back(k+1);
        }
    }
}

void backtracking() {
    back(0);
}

int main(void) {
    //liste();
    backtracking();
    return 0;
}