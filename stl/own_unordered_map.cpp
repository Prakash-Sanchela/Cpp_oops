#include <iostream>
#include <list>
#include <vector>
#include <functional> // for std::hash

template<typename Key, typename Value>
class MyUnorderedMap {
public:
    MyUnorderedMap(size_t size = 10) : table(size) {}

    // Insert key-value pair
    void insert(const Key& key, const Value& value) {
        size_t index = hash(key) % table.size();  // Hash the key to get the index
        for (auto& pair : table[index]) {         // Check if the key already exists
            if (pair.first == key) {
                pair.second = value;              // Update the value if key exists
                return;
            }
        }
        table[index].emplace_back(key, value);    // Insert the new key-value pair
    }

    // Find the value associated with the key
    Value* find(const Key& key) {
        size_t index = hash(key) % table.size();
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return &pair.second;              // Return pointer to the value
            }
        }
        return nullptr;                           // Return nullptr if key not found
    }

    // Erase the key-value pair
    void erase(const Key& key) {
        size_t index = hash(key) % table.size();
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);           // Erase the key-value pair
                return;
            }
        }
    }

private:
    std::vector<std::list<std::pair<Key, Value>>> table;  // Hash table (array of linked lists)
    std::hash<Key> hash;                                  // Default hash function for keys
};

int main() {
    MyUnorderedMap<std::string, int> myMap;

    // Insert key-value pairs
    myMap.insert("Alice", 25);
    myMap.insert("Bob", 30);
    myMap.insert("Charlie", 22);

    // Find and print values
    if (auto* age = myMap.find("Alice")) {
        std::cout << "Alice's age: " << *age << std::endl;
    }

    // Erase a key-value pair
    myMap.erase("Bob");

    // Try to find a removed key
    if (myMap.find("Bob") == nullptr) {
        std::cout << "Bob not found in the map." << std::endl;
    }

    return 0;
}
