#pragma once

namespace jh {
	
	template <typename T>
	struct Node {
		T data;
		Node<T>* next;
	};

	template <typename T>
	class LinkedList
	{
	public:

		Node<T>* GetHead() {
			return head;
		}

		// 노드 앞에 추가 
		void PushFront(const T& value) {

			// 노드 구조체 value 와 머리 부분을 넣음
			// head 가 없을 경우 
			Node<T>* node = new Node<T>{ value,head };
			// 헤드를 새로 대입함
			head = node;

			if (tail == nullptr) {
				tail = node;
			}

		}

		void PushBack(const T& value) {
			Node<T>* node = new Node<T>{value ,nullptr};

			if (tail == nullptr || head == nullptr) {
				tail = node;
				head = node;
				return;
			}

			tail->next = node;
			tail = node;
		}

		void PopBack() {
		
			if (head == nullptr) {
				return;
			}

			if (head == tail) {
				
			}

			// tail 이전 노드 찾기
			Node<T>* currentNode = head;
			while (currentNode->next != tail) {
				currentNode = currentNode->next;
			}

			delete tail;
			tail = currentNode;
			currentNode->next = nullptr;
		}

		~LinkedList() {
			Node<T>* current = head;

			while (current != nullptr) {
				Node<T>* next = current->next;
				delete current;
				current = next;
			}
		}

	private:
		Node<T>* head;
		Node<T>* tail;
	};
}