#pragma once
#include <iostream>

namespace ht {
	class HashTable {
		class Node {
		public:
			Node();
			Node(std::string, long);
			Node* next;
			std::string getKey();
			long getValue();
		private:
			std::string key;
			long value;
		};
		class List {
		public:
			List();
			Node* node;
			void insert(Node* node);
		};
	public:
		HashTable();
		bool insert(std::string, long);
		long find(std::string);
		bool remove(std::string);
	private:
		unsigned keyToHash(std::string);
		List* arr;
		size_t length;
	};
}