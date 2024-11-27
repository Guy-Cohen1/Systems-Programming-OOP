#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


/**************************************************************************************************/
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
// #define DEBUGON
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
/**************************************************************************************************/
/* Submitters
Name1: Liav Ben Or     ID: 315909390
Name2: Guy Cohen     ID: 207881004
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
typedef struct item {
    char* name;
    int  id;
    struct wlst* warehouses;
} item;

typedef struct warehouse {
    char* location;
    int  code;
    struct itemlst* items;
} warehouse;

typedef struct itemlst {
    item* data;
    struct itemlst* next;
} itemlst;

typedef struct wlst {
    warehouse* data;
    struct wlst* next;
} wlst;


/******************************************* your's prototypes *******************************************************************************/

void new_item(char name[], int id, struct itemlst** items);
void new_warehouse(char location[], int code,struct wlst** warehouses);
void assign_an_item(int id, int code, wlst** warehouses, itemlst** items);
void unassign(int id, int code, wlst** warehouses, itemlst** items);
void unassign1(int id, int code, wlst** warehouses, itemlst** items);
void print_items(struct itemlst** items);
void print_warehouses(struct wlst** warehouses);
void generating_items(struct itemlst** items, struct wlst** warehouses);
void print_error_message(int errid);
void clearBuffer();
/******************************************* your's functions ********************************************************************************/



/*****************************************new objects and insert object functions******************************************************/

void new_item(char name[], int id, struct itemlst** items)
{
    itemlst* newnode = (itemlst*)malloc(sizeof(itemlst) + 1); //malloc for new item
    if (!newnode)
    {
        print_error_message(0);
        return;
    }
    item* newitem = (item*)malloc(sizeof(item) + 1);//malloc for name
    if (!newitem)
    {
        free(newnode);
        print_error_message(0);
        return;
    }
    newitem->name = (char*)malloc(strlen(name) + 1);
    if (!newitem->name)
    {
        free(newnode);
        free(newitem);
        print_error_message(0);
        return;
    }

    strcpy(newitem->name, name);
    newitem->id = id;
    newitem->warehouses = NULL;
    newnode->data = newitem;
    newnode->next = NULL;
    itemlst* current = *items;
    itemlst* prev = NULL;
    if (*items == NULL || id < current->data->id)//inserting at the beginning
    {
        newnode->next = *items;
        *items = newnode;
        return;
    }
    while (current != NULL && id >= current->data->id)// find the correct position
    {
        if (id == current->data->id)
        {
            free(newitem->name);
            free(newitem);
            free(newnode);
            return;
        }
        prev = current;
        current = current->next;
    }
    newnode->next = current; // Insert the new node into the sorted list
    prev->next = newnode;
}


/*------------------------------------------------------------------------------------------------------------------------*/

void new_warehouse(char location[], int code,struct wlst** warehouses)
{
    wlst* current1 = *warehouses; //check if exist
    while (current1 != NULL)
    {
        if(current1 ->data -> code == code)
            return;
        current1 = current1->next;
    }
    warehouse* newwarehouse = (warehouse *) malloc(sizeof(warehouse)+1); // malloc for new warehouse
    if (!newwarehouse)
    {
        print_error_message(0);
        return;
    }
    else
    {
        newwarehouse -> location = (char *)malloc(sizeof(strlen(location)+1));// malloc for new location
        if(!newwarehouse->location)
        {
            free(newwarehouse);
            print_error_message(0);
            return;
        }
        else
        {
            strcpy(newwarehouse->location, location);
            newwarehouse->code = code;
            newwarehouse->items = NULL;
        }
    }
    wlst* newnode = (wlst*)malloc(sizeof(wlst));
    if(!newnode)
    {
        free(newwarehouse -> location);
        free(newwarehouse);
        print_error_message(0);
        return;
    }
    newnode -> data = newwarehouse;
    newnode -> next = NULL;
    wlst * current = *warehouses;
    itemlst* prev = NULL;
    if (*warehouses == NULL || code < current->data->code)// inserting at the beginning
    {
        newnode->next = *warehouses;
        *warehouses = newnode;
        return;
    }
    while (current != NULL && code >= current->data->code)//find the correct position
    {
        if (code == current->data->code)
        {
            free(newwarehouse->location);
            free(newwarehouse);
            free(newnode);
            return;
        }
        prev = current;
        current = current->next;
    }
    newnode->next = current;
    prev->next = newnode;
}

/*------------------------------------------------------------------------------------------------------------------------*/
void assign_an_item(int id, int code, wlst** warehouses, itemlst** items)
{
    item* my_item = NULL;
    warehouse* my_warehouse = NULL;
    wlst* current1 = *warehouses;
    itemlst* current = *items;
    while (current != NULL) {// Searching for the item
        if (current->data->id == id) {
            my_item = current->data;
            break;
        }
        current = current->next;
    }
    if (my_item == NULL) {
        print_error_message(0);
        return;
    }
    current1 = *warehouses;  // save the head
    while (current1 != NULL) { // Searching for the warehouse
        if (current1->data->code == code) {
            my_warehouse = current1->data;
            break;
        }
        current1 = current1->next;
    }
    if (my_warehouse == NULL) {
        print_error_message(0);
        return;
    }
    wlst* current2 = my_item->warehouses;
    wlst* prev2 = NULL;
    while (current2 != NULL && code > current2->data->code) {
        prev2 = current2;
        current2 = current2->next;
    }
    wlst* new_node2 = (wlst*)malloc(sizeof(wlst));
    if (!new_node2) {
        print_error_message(0);
        return;
    }
    new_node2->data = my_warehouse;
    if (prev2 == NULL) {
        new_node2->next = my_item->warehouses;// Insert at the beginning
        my_item->warehouses = new_node2;
    } else {
        new_node2->next = current2;// Insert in the middle or at the end
        prev2->next = new_node2;
    }
    itemlst* current3 = my_warehouse->items;
    itemlst* prev3 = NULL;
    while (current3 != NULL && id > current3->data->id) {
        prev3 = current3;
        current3 = current3->next;
    }
    itemlst* new_node3 = (itemlst*)malloc(sizeof(itemlst));
    if (!new_node3) {
        print_error_message(0);
        return;
    }
    new_node3->data = my_item;
    if (prev3 == NULL) {
        new_node3->next = my_warehouse->items;// Insert at the beginning
        my_warehouse->items = new_node3;
    } else {
        new_node3->next = current3;// Insert in the middle or at the end
        prev3->next = new_node3;
    }
}

/****************************************find Matchings and register item to Warehouse*************************************************/

/*------------------------------------------------------------------------------------------------------------------------*/


/********************************************uregisters objects*************************************************************************/

/*------------------------------------------------------------------------------------------------------------------------*/

void unassign(int id, int code, wlst** warehouses, itemlst** items)
{
    warehouse* my_warehouse = NULL;
    wlst* current1 = *warehouses;
    while (current1 != NULL) //searching for the warehouse
    {
        if (current1->data->code == code) {
            my_warehouse = current1->data;
            break;
        }
        current1 = current1->next;
    }
    if (my_warehouse == NULL)
    {
        print_error_message(0);
        return;
    }
    itemlst* current = my_warehouse->items; //searching for the item
    if (current == NULL)
    {
        print_error_message(0);
        return;
    }
    if (current != NULL)
    {
        if (current->data->id == id)
        {
            my_warehouse->items = current->next;
            free(current);
            return;
        }
    }
    itemlst* current2 = current;
    while (current2->next != NULL)//remove the item if it exists in the warehouse
    {
        if (current2->next->data->id == id)
        {
            itemlst* temp = current2->next;
            current2->next = current2->next->next;
            free(temp);
            return;
        }
        current2 = current2->next;
    }
    print_error_message(0);
}
/*------------------------------------------------------------------------------------------------------------------------*/

void unassign1(int id, int code, wlst** warehouses, itemlst** items)
{
    item* my_item = NULL;
    itemlst * current4 = *items;
    while (current4 != NULL) //searching for the item
    {
        if (current4->data->id == id) {
            my_item = current4->data;
            break;
        }
        current4 = current4->next;
    }
    if (my_item == NULL)
    {
        print_error_message(0);
        return;
    }
    wlst * current5 = my_item->warehouses; //searching for the item
    if (current5 == NULL)//if the warehouse is empty
    {
        print_error_message(0);
        return;
    }
    if (current5 != NULL)
    {
        if (current5->data->code == code)
        {
            my_item->warehouses = current5->next;
            free(current5);
            return;
        }
    }
    wlst * current6 = current5->next;
    while (current6 != NULL)//remove the warehouse if it exists
    {
        if (current6->data->code== code)
        {
            current5->next = current6->next;
            free(current6);
            return;
        }
        current5 = current5->next;
        current6 = current6->next;
    }
    print_error_message(0);
}

/***********************************************printout functions***********************************************************************/

void print_items(struct itemlst** items) {
    itemlst* current = *items;

    if (current == NULL) {
        printf("item LIST: EMPTY!\n");
    } else {
        printf("item LIST: \n");
        while (current != NULL) {
            printf("%d:%s\n", current->data->id, current->data->name);
            if(current->data->warehouses != NULL)
                printf("Item Warehouses: ");
            wlst* currentWarehouses = current->data->warehouses;
            while (currentWarehouses != NULL) {
                printf("%d-%s ",  currentWarehouses->data->code, currentWarehouses->data->location);
                if(currentWarehouses->next != NULL)
                {
                    printf(", ");
                }
                else{
                    printf("\n");
                }
                currentWarehouses = currentWarehouses->next;
            }
            current = current->next;
        }
    }
}

/*------------------------------------------------------------------------------------------------------------------------*/

void print_warehouses(struct wlst** warehouses) {
    wlst* current = *warehouses;

    if (current == NULL) {
        printf("warehouse LIST: EMPTY!\n");
    } else {
        printf("warehouse LIST:\n");
        while (current != NULL) {
            printf("Warehouse code %d, Warehouse name: %s\n", current->data->code, current->data->location);
            if(current->data->items != NULL)
                printf("items:");
            itemlst* currentItems = current->data->items;
            while (currentItems != NULL) {
                printf(" ID %d Name %s |", currentItems->data->id, currentItems->data->name);
                currentItems = currentItems->next;
            }
            if(current->data->items != NULL)
                printf("\n");
            current = current->next;
        }
    }
    printf("\n");
}
/***************************************************free**********************************************************************************/
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != '\0');
}
/*******************************************Generate And Assign Items And Warehouses******************************************************/
void generating_items(struct itemlst** items, struct wlst** warehouses)
{
    srand(1948);
    for (int i = 0; i < 10; i++)
    {
        char str[11] = {'w','a','r','e','h', 'o', 'u', 's', 'e', '0' + i, '\0'};
        new_warehouse(str, i, warehouses);
    }
    for (int i = 0; i < 100; i++)
    {
        if (i<10)
        {
            char str2[6] = {'I','t','e','m', '0' + i % 10, '\0'};
            new_item(str2, i, items);
            assign_an_item(i, rand() % 10, warehouses, items);
        }
        else {
            char str2[7] = {'I', 't', 'e', 'm', '0' + i / 10, '0' + i % 10, '\0'};
            new_item(str2, i, items);
            assign_an_item(i, rand() % 10, warehouses, items);
        }
    }
}

/*DO NOT TOUCH THIS FUNCTION */
void getstring(char* buf, int length) {
    int len;
    //buf = fgets(buf, length, stdin);
    scanf("%s", buf);
    len = (int)strlen(buf);
    if (buf[len - 1] == '\n')
        buf[len - 1] = '\0';
}


/*DO NOT TOUCH THIS FUNCTION */

void print_error_message(int errid) {
#ifdef DEBUGON
    fprintf(stderr, "BGU ERROR %d\n", errid);
#else
    fprintf(stderr, "BGU ERROR\n");
#endif
    exit(-1);
}

/*DO NOT TOUCH THIS MAIN TEMPLATE - ONLY ADD YOUR FUNCTIONS CALLS */
int main() {
    itemlst* items = 0;
    wlst* warehouses = 0;
    char  c;
    char  buf[100];
    int   id, num;



    do {
        printf("Choose:\n"
               "    i - new item\n"
               "    w - new warehouse\n"
               "    a - assign an item to a warehouse\n"
               "    u - unassign an item from a warehouse(not delete!)\n"
               "    p - print status\n"
               "    g - generating and assigning 100 items to 10 warehouses\n"
               "    q - quit\n");

        while ((c = (char)getchar()) == '\n');
        getchar();

        switch (c) {
            case 'i':
                printf("Adding new item.\n");

                printf("item name: ");
                getstring(buf, 100);


                printf("item ID: ");
                scanf("%d", &id);

                printf("\n Add new item: name %s item id: %d",buf, id);
                new_item(buf, id, &items);

                break;

            case 'w':
                printf("Adding new warehouse.\n");

                printf("\n warehouse name: ");
                getstring(buf, 100);

                printf("\n warehouse code: ");
                scanf("%d", &num);

                printf("\n Add new warehouse: name %s warehouse code: %d",buf, num);

                new_warehouse(buf, num, &warehouses);

                break;

            case 'a':
                printf("Assign an item to a warehouse.\n");

                printf("item ID: ");
                scanf("%d", &id);

                printf("warehouse code: ");
                scanf("%d", &num);

                assign_an_item(id, num, &warehouses, &items);
                break;

            case 'u':
                printf("Remove an item from a warehouse.\n");

                printf("item ID: ");
                scanf("%d", &id);

                printf("warehouse code: ");
                scanf("%d", &num);

                unassign(id, num, &warehouses, &items);
                unassign1(id, num, &warehouses, &items);
                break;

            case 'p':
                printf("Printing status.\n");

                print_items(&items);
                print_warehouses(&warehouses);
                break;

            case 'g':  // generating and assigning items and warehouses
                printf("Generating and assigning items to warehouses\n");

                generating_items(&items, &warehouses);
                break;

            case 'q':
                printf("Quitting...\n");
                break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    //your free functions
    exit(0);

}




