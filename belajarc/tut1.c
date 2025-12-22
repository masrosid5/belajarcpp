#include <stdio.h>

struct item_t{
    char* name;
    int quantity;
    float price;
} item_t;

void reduce_stock(struct item_t *item, int q){
    item->quantity -= q;
}

void change_price(struct item_t *item, float new_price){
    item->price = new_price;
}

int main(){
    struct item_t item;

    item.name = "Apple";
    item.quantity = 20;
    item.price = 0.8;

    printf("%s - %d pieces - %.2f each\n", item.name, item.quantity, item.price);

    reduce_stock(&item, 7);

    printf("%s - %d pieces - %.2f each\n", item.name, item.quantity, item.price);

    change_price(&item, 0.97);

    printf("%s - %d pieces - %.2f each\n", item.name, item.quantity, item.price);
    return 0;
}