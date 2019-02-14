#include <bits/stdc++.h>
using namespace std;
class LRU {
	private : 
		int cache_size;
		list<int> lru;
		unordered_map<int, list<int> :: iterator> hashx;
	public :
		LRU(int);
		void Insert(int);
		void Display();
};

LRU :: LRU(int _size) {
	cache_size = _size;
}

void LRU :: Insert(int elm) {
	if(hashx.find(elm) != hashx.end()) {
		lru.erase(hashx[elm]);
		hashx.erase(elm);
	}
	
	if(lru.size() == cache_size) {
		int last = lru.back();
		lru.pop_back();
		hashx.erase(last);
	}
	lru.push_front(elm);
	hashx.insert({elm,lru.begin()});
}

void LRU :: Display() {
	for(auto it = lru.begin(); it != lru.end(); it++) {
		cout<<*it<<endl;
	}	
}

int main() {
	LRU obj(4);
	obj.Insert(1);
	
	obj.Insert(12);
	
	obj.Insert(13);
	
	obj.Insert(14);
	
	obj.Insert(3);
	
	obj.Insert(1);
	
	obj.Display();
	
	return 0;
}
