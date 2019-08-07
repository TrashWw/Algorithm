#pragma once
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
public:
	int size = 0;
	list<pair<int, int>>cache;
	unordered_map<int, list<pair<int, int>>::iterator> hash;


	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		auto it = hash.find(key);
		if (it == hash.end())
			return -1;
		auto kv = *hash[key];
		cache.erase(hash[key]);
		cache.push_front(kv);
		hash[key] = cache.begin();
		return kv.second;
	}

	void put(int key, int value) {
		auto it = hash.find(key);
		if (it == hash.end()) {
			pair<int, int>kv{ key,value };
			if (size <= cache.size()) {
				
				auto dkey = cache.back().first;
				cache.pop_back();
				cache.push_front(kv);
				hash.erase(dkey);
				hash[key] = cache.begin();
			}
			else {
				cache.push_front(kv);
				hash[key] = cache.begin();
				
			}
		}
		else {
			auto kv = *hash[key];
			kv.second = value;
			cache.erase(hash[key]);
			cache.push_front(kv);
			hash[key] = cache.begin();
		}
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/