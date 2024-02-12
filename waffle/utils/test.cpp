//
// Created by Peter Pan on 2/11/2024.
//

// Test TS_key_master.h
#include <cassert>
#include <iostream>
#include "TS_key_master.h"
#include "serialization.h"

static void test_keyGenerationDecomposition() {
    ItemIdGenerator item_id_generator;
    std::string item_id = item_id_generator.generate_item_ids(1)[0];
    std::string user_id = "user_id";
    std::string timestamp = UNIX_TIMESTAMP::current_time();
    KeyGenerationDecomposition keyGenerationDecomposition(item_id, user_id, timestamp);
    std::cout << keyGenerationDecomposition.key << std::endl;
    assert(keyGenerationDecomposition.item_id == item_id);
    assert(keyGenerationDecomposition.user_id.substr(keyGenerationDecomposition.user_id.length() - user_id.length(), user_id.length()) == user_id);
    assert(keyGenerationDecomposition.timestamp == timestamp);
    KeyGenerationDecomposition keyGenerationDecomposition2(keyGenerationDecomposition.key);
    assert(keyGenerationDecomposition2.item_id == item_id);
    assert(keyGenerationDecomposition.user_id.substr(keyGenerationDecomposition.user_id.length() - user_id.length(), user_id.length()) == user_id);
    assert(keyGenerationDecomposition2.timestamp == timestamp);
    KeyGenerationDecomposition keyGenerationDecomposition3(item_id, user_id);
    assert(keyGenerationDecomposition3.item_id == item_id);
    assert(keyGenerationDecomposition.user_id.substr(keyGenerationDecomposition.user_id.length() - user_id.length(), user_id.length()) == user_id);
    assert(keyGenerationDecomposition3.timestamp == keyGenerationDecomposition3.current_time());
    std::cout << keyGenerationDecomposition3.get_data_type() << std::endl;
}

static void test_ItemIdGenerator() {
    ItemIdGenerator item_id_generator;
    std::vector<std::string> item_ids1 = item_id_generator.generate_item_ids(10);
    std::vector<std::string> item_ids2 = item_id_generator.generate_item_ids(10);
    for (int i = 0; i < item_ids1.size() ; i++) {
        std::cout << item_ids1[i] << std::endl;
        std::cout << item_ids2[i] << std::endl;
        assert(item_ids1[i] != item_ids2[i]);
    }
}

static void test_serialize() {
    Serialization serialization;
    std::vector<unsigned char> blob = {1, 2, 3};
    std::cout<<serialization.serialize(1)<<std::endl;
    std::cout<<serialization.serialize(1.0f)<<std::endl;
    std::cout<<serialization.serialize("hello")<<std::endl;
    std::cout<<serialization.serialize(true)<<std::endl;
    std::cout<<serialization.serialize(blob)<<std::endl;
    assert(serialization.deserializeString(serialization.serialize("hello")) == "hello");
    assert(serialization.deserializeInt(serialization.serialize(1)) == 1);
    assert(serialization.deserializeFloat(serialization.serialize(1.0f)) == 1.0f);
    assert(serialization.deserializeBool(serialization.serialize(true)) == true);
    std::vector<unsigned char> blob2 = serialization.deserializeBlob(serialization.serialize(blob));

}

int main() {
    test_keyGenerationDecomposition();
    test_ItemIdGenerator();
    test_serialize();
    return 0;
}