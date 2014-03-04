/*
 * Node.h
 *
 *
 *      Author: kaya
 */


class Node
{
	public:
		typedef double value_type;
		Node(const value_type& init_data = value_type(), Node* init_link = NULL )
		{
			data_field = init_data;
			link_field = init_link;
		}
		//member function
		void setData(const value_type& new_data)
		{
			data_field = new_data;
		}
		void setLink(Node* new_link)
		{
			link_field = new_link;
		}
		value_type data() const
		{
			return data_field;
		}
		const Node* link() const
		{
			return link_field;
		}
		Node* link()
		{
			return link_field;
		}
		//other functions
		std::size_t list_length(const Node* head_ptr);
		void list_head_insert(const Node*& head_ptr, const Node::value_type& entry);
		void list_insert(Node* previous_ptr, const Node::value_type& entry);
		Node* list_search(Node* head_ptr, const Node::value_type& target);
		const Node* list_search(const Node head_ptr, const value_type& target);
		Node* list_locate(Node* head_ptr, std::size_t position);
		const Node* list_locate(const Node* head_ptr,std::size_t position);
		void list_head_remove(Node*& head_ptr);
		void list_remove(Node* previous_ptr);
		void list_clear(Node*& head_ptr);
		void list_copy(const Node* source_ptr, Node*& head_ptr, Node*& tail_ptr);
		//string toString();

	private:
		value_type data_field;
		Node* link_field;
};

