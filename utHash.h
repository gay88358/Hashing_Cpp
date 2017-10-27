#ifndef UTHASH_H
#define UTHASH_H

#include "./include/hash.h"


TEST(Hash, hashing_add_item_and_number_item_in_index) {
    Hash hashObject;
    hashObject.addItemByIndex(0, "Z-Xuan Hong", "Bubble Tea");
    hashObject.addItemByIndex(0, "Hong", "Black Tea");
    hashObject.addItemByIndex(0, "Lin", "Red Tea");
    ASSERT_EQ(3, hashObject.numberOfItemsInIndex(0));

    hashObject.addItemByIndex(5, "Z-Xuan Hong", "Bubble Tea");
    hashObject.addItemByIndex(0, "Hong", "Black Tea");
    hashObject.addItemByIndex(5, "Lin", "Red Tea");
    ASSERT_EQ(4, hashObject.numberOfItemsInIndex(0));
    ASSERT_EQ(2, hashObject.numberOfItemsInIndex(5));
}

TEST(Hash, print_table) {
    Hash hashObject;
    hashObject.addItem("Z-Xuan Hong", "Bubble Tea");
    hashObject.addItem("Hong", "Black Tea");
    hashObject.addItem("Lin", "Red Tea");
    hashObject.printTable();
}

TEST(Hash, print_item_in_index) {
    Hash hashObject;
    hashObject.addItem("Z-Xuan Hong", "Bubble Tea");
    hashObject.addItem("Hong", "Black Tea");
    hashObject.addItem("Lin", "Red Tea");
    for (int i = 0; i < 10; i++) {
        hashObject.printItemInIndex(i);
    }
}

TEST(Hash, find_drink) {
    Hash hashObject;
    hashObject.addItem("Z-Xuan Hong", "Bubble Tea");
    hashObject.addItem("Hong", "Black Tea");
    hashObject.addItem("Lin", "Red Tea");
    hashObject.findDrink("Z-Xuan Hong");
    hashObject.findDrink("Hong");
    hashObject.findDrink("Lin");   
}

TEST(Hash, delete_drink_by_name_case_1) {
    Hash hashObject;
    hashObject.addItem("Z-Xuan Hong", "Bubble Tea");
    hashObject.addItem("Hong", "Black Tea");
    hashObject.addItem("Lin", "Red Tea");
    ASSERT_FALSE(hashObject.removeItem("123")); 
    ASSERT_FALSE(hashObject.removeItem("Bigbang"));   
}


TEST(Hash, delete_drink_by_name_case_2) {
    Hash hashObject;
    hashObject.addItem("Z-Xuan Hong", "Bubble Tea");
    hashObject.addItem("Hong", "Black Tea");
    hashObject.addItem("Lin", "Red Tea");
    ASSERT_TRUE(hashObject.removeItem("Z-Xuan Hong")); 
    ASSERT_TRUE(hashObject.removeItem("Hong")); 
}

TEST(Hash, delete_drink_by_name_case_2_1) {
    Hash hashObject;
    hashObject.addItem("Z-Xuan Hong", "Bubble Tea");
    hashObject.addItem("Hong", "Black Tea");
    hashObject.addItem("Lin", "Red Tea");
    ASSERT_FALSE(hashObject.removeItem("Bigbang"));   
    ASSERT_TRUE(hashObject.removeItem("Hong"));   
    hashObject.printItemInIndex(hashObject.hash("Hong"));
    ASSERT_FALSE(hashObject.removeItem("Hong"));   
}

/*
TEST(Hash, delete_drink_by_name_case_3_match) {
    Hash hashObject;
    hashObject.addItemByIndex(0, "Z-Xuan Hong", "Bubble Tea");
    hashObject.addItemByIndex(0, "Z-aHong", "Bubble");
    hashObject.addItemByIndex(0, "ZHong", "Tea");
    hashObject.printItemInIndex(0);
    ASSERT_TRUE(hashObject.removeItem(0, "Z-aHong"));   
    hashObject.printItemInIndex(0);
    ASSERT_FALSE(hashObject.removeItem(0, "Z-aHong"));   
    hashObject.printItemInIndex(0);
    ASSERT_TRUE(hashObject.removeItem(0, "ZHong"));   
    hashObject.printItemInIndex(0);
    ASSERT_FALSE(hashObject.removeItem(0, "ZHong"));   
    hashObject.printItemInIndex(0);
    ASSERT_TRUE(hashObject.removeItem(0, "Z-Xuan Hong"));   
    hashObject.printItemInIndex(0);
    
}
*/



#endif