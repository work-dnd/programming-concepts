// Linked-list version 01 : building in-depth concept

#include <iostream>

class LinkedList
{
private:
	class Node
	{
	private:
		int m_data;
		Node* m_next;

		friend class LinkedList;
	
	public: 
		Node(const int& data)
			: m_data(data), m_next(nullptr) {
		}
	};

	Node* m_head;

public:
	LinkedList()
		: m_head(nullptr) {
	}

	~LinkedList()
	{
		Node* temp;
		while (m_head != nullptr)
		{
			temp = m_head;
			m_head = m_head->m_next;
			delete temp;
		}
	}

	void display()  const
	{
		if (m_head == nullptr) return;

		Node* temp = m_head;
		while (temp != nullptr)
		{
			std::cout << temp->m_data << "->";
			temp = temp->m_next;
		}
		std::cout << "nullptr" << std::endl;
	}

	void insert_at_front(const int& data)
	{
		Node* node = new Node(data);
		if (!node)
			throw std::bad_alloc();

		node->m_next = m_head;
		m_head = node;
	}

};


int main()
{
	LinkedList new_list;
	new_list.insert_at_front(12);
	new_list.insert_at_front(11);
	new_list.insert_at_front(10);

	new_list.display();
}