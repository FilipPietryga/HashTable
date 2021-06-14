#include "HashTable.h"

ht::HashTable::HashTable() : arr(nullptr), length(0) {}

bool ht::HashTable::insert(std::string key, long value) {
	unsigned hash = keyToHash(key);
	if (hash > this->length) {
		if (this->arr) {
			ht::HashTable::List* tmp = this->arr;
			this->arr = new ht::HashTable::List[hash + 1];
			for (size_t i = 0; i <= hash; i++) {
				this->arr[i].node = nullptr;
			}
			for (size_t i = 0; i <= length; i++) {
				if (tmp[i].node) {
					while (tmp[i].node->next) {
						this->arr[i].insert(tmp[i].node);
						tmp[i].node = tmp[i].node->next;
					}
					this->arr[i].insert(tmp[i].node);
				}
			}
			this->length = hash;
		}
		else {
			this->arr = new ht::HashTable::List[hash + 1];
			for (size_t i = 0; i <= hash; i++) {
				this->arr[i].node = nullptr;
			}
			this->length = hash;
		}
	}
	arr[hash].insert(new Node(key, value));
	return true;
}

void ht::HashTable::List::insert(Node* node) {
	if (!this->node) {
		this->node = node;
	}
	else {
		Node *temp = this->node;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = node;
		temp = temp->next;
		temp->next = nullptr;
	}
}

unsigned ht::HashTable::keyToHash(std::string key) {
	unsigned ones = 0;
	unsigned asciiSum = 0;
	for (size_t i = 0; i < key.length(); i++) {
		asciiSum += key[i];
	}
	while (asciiSum) {
		if (asciiSum % 2 == 0) {
			ones += 1;
		}
		asciiSum /= 2;
	}
	return ones;
}

ht::HashTable::Node::Node() : key(""), value(0), next(nullptr) {

}

ht::HashTable::Node::Node(std::string key, long value) : key(key), value(value), next(nullptr) {

}

ht::HashTable::List::List() : node(nullptr) {

}

long ht::HashTable::find(std::string key) {
	size_t hash = keyToHash(key);
	ht::HashTable::Node* temp = arr[hash].node;
	while (temp->next) {
		if (temp->getKey() == key) {
			break;
		}
		temp = temp->next;
	}
	long val = temp->getValue();
	return val;
}

std::string ht::HashTable::Node::getKey() {
	return key;
}

long ht::HashTable::Node::getValue() {
	return value;
}