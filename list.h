#ifndef LIST_HEADER_FILE
#define LIST_HEADER_FILE

#include <iostream>
#include <functional>

using std::cin;
using std::cout;
using std::string;

const string empty_error = "LIST IS EMPTY";
const string range_error = "RANGE ERROR";
const string item_notpresent = "ITEM NOT PRESENT IN LIST";

class ListUnderflow : public std::exception
{
public:
    string what()
    {
        return empty_error;
    }
};
class ListRangeError : public std::exception
{
public:
    string what()
    {
        return range_error;
    }
};
class ListItemNotPresent : public std::exception
{
public:
    string what()
    {
        return item_notpresent;
    }
};

template <typename T>
class Node
{
public:
    Node *link;
    T data;

    Node(T data)
    {
        this->data = data;
        this->link = NULL;
    }
};

template <typename T>
class List
{
    size_t len = 0;
    Node<T> *start = NULL;

public:
    size_t length()
    {
        return len;
    }
    // Returns item at a specific index
    T item_at(int index)
    {
        Node<T> *ptr = start;
        size_t i = 0;
        while (ptr != NULL)
        {
            if (i == index)
                break;
            ptr = ptr->link;
            i++;
        }

        if (ptr != NULL)
        {
            return ptr->data;
        }
        else
            throw ListRangeError();
    }

    T operator[](int index)
    {
        Node<T> *ptr = start;
        size_t i = 0;
        while (ptr != NULL)
        {
            if (i == index)
                break;
            ptr = ptr->link;
            i++;
        }

        if (ptr != NULL)
        {
            return ptr->data;
        }
        else
            throw ListRangeError();
    }
    // Pushes a new node at the back of the list
    void push(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        if (start != NULL)
        {
            Node<T> *current_node = start;
            while (current_node->link != NULL)
                current_node = current_node->link;

            len++;
            current_node->link = new_node;
            return;
        }
        else
        {
            start = new_node;
            len++;
            return;
        }
    }

    // Removes the last element in the lists
    T pop()
    {
        T data;
        Node<T> *ptr = start;
        if (start == NULL)
        {
            throw ListUnderflow();
        }
        size_t length = 0;
        if (ptr->link == NULL)
        {
            start = NULL;
            data = ptr->data;
            delete ptr->link;
            ptr->link = NULL;

            len--;
            return data;
        }

        while (ptr->link != NULL)
        {
            if (ptr->link->link == NULL)
                break;
            else
                ptr = ptr->link;
        }

        data = ptr->data;
        delete ptr->link;
        ptr->link = NULL;
        len--;
        return data;
    }

    // Removes element at specific index
    void remove(T data)
    {
        Node<T> *ptr = start;
        if (start == NULL)
            throw ListItemNotPresent();

        if (start->data == data)
        {
            start = ptr->link;
            delete ptr;
            len--;
            return;
        }
        while (ptr->link != NULL)
        {
            if (ptr->link->data == data)
            {
                ptr->link = ptr->link->link;
                len--;
                return;
            }
            ptr = ptr->link;
        }
    }

    // Returns the size of list
    size_t size()
    {
        Node<T> *ptr = start;
        size_t length = 0;
        while (ptr != NULL)
        {
            ptr = ptr->link;
            length++;
        }
        return length;
    }

    // Returns true if list is empty
    bool is_empty()
    {
        return (start == NULL);
    }

    // Returns the index of item if present in the list
    signed long int index_of(T data)
    {
        signed long int index = 0;
        Node<T> *ptr = start;
        while (ptr != NULL)
        {
            if (ptr->data == data)
                return index;
            ptr = ptr->link;
            index++;
        }
        return -1;
    }

    // Returns true if the value is found in list
    bool includes(T data)
    {
        Node<T> *ptr = start;
        while (ptr != NULL)
        {
            if (ptr->data == data)
                return true;
            ptr = ptr->link;
        }
        return false;
    }

    // Inserts value at a specified index
    void insert_at(size_t index, T data)
    {
        if (index > length())
            throw ListRangeError();

        size_t i = 0;
        Node<T> *temp = new Node<T>(data);
        Node<T> *ptr = start;
        if (start == NULL)
        {
            start = temp;
        }
        if (index == 0)
        {
            temp->link = start->link;
            start->link = temp;
            return;
        }
        while (ptr != NULL)
        {
            if (i == (index - 1))
            {
                temp->link = ptr->link;
                ptr->link = temp;
                return;
            }
            ptr = ptr->link;
            i++;
        }
    }

    // Removes element at specific index
    void remove_at(size_t index)
    {
        long long int length = this->size(),
                      curr_indx = 0;
        if (index > (length - 1))
            throw ListRangeError();

        Node<T> *ptr = start;
        if (start == NULL)
            return;

        if (index == 0)
        {
            if (start->link == NULL)
            {
                delete start;
                start = NULL;
            }
            else
            {
                start = ptr->link;
                delete ptr;
            }
            len--;
            return;
        }

        while (ptr->link != NULL)
        {
            if ((curr_indx + 1) == index)
            {
                Node<T> *del_ptr;
                del_ptr = ptr->link;
                ptr->link = ptr->link->link;
                delete del_ptr;
                len--;
                return;
            }
            ptr = ptr->link;
            curr_indx++;
        }
    }

    void update(size_t index, T data)
    {
        size_t i = 0;
        Node<T> *ptr = start;
        if (index > this->length() - 1)
            throw ListRangeError();

        while (ptr != NULL)
        {
            if (i == index)
            {
                ptr->data = data;
                return;
            }
            ptr = ptr->link;
            i++;
        }
    }
    // Prints all values present the list
    void print_values()
    {
        Node<T> *ptr = start;
        if (start == NULL)
        {
            cout << empty_error << std::endl;
            return;
        }
        size_t i = 0;
        cout << "--------------"
             << " List Items "
             << "--------------"
             << std::endl;

        while (ptr != NULL)
        {
            cout
                << i
                << " : "
                << ptr->data
                << std::endl;
            ptr = ptr->link;
            i++;
        }

        cout << std::endl
             << "Total items : "
             << i
             << std::endl;
    }

    /**
     * High order functions
     */

    // Callback param provides each value present in list with index
    void each(const std::function<void(int, T)> &cb)
    {
        size_t i = 0;
        Node<T> *ptr = start;
        while (ptr != NULL)
        {
            cb(i, ptr->data);
            ptr = ptr->link;
        }
        return;
    }

    // Returns a new list ptr .. it is an semi open closed interval where start is closed and stop is open end
    List *slice(size_t start, size_t stop, size_t step = 1)
    {
        size_t i = 0, next_index = start;
        List *li = new List();
        if (this->start != NULL)
        {
            Node<T> *ptr = this->start;
            while (ptr != NULL)
            {
                if (next_index == i && i < stop)
                {
                    li->push(ptr->data);
                    next_index += step;
                }
                if (i > stop)
                    break;
                ptr = ptr->link;
                i++;
            }
            return li;
        }
        else
            throw ListUnderflow();
    }

    // Maps a new list i.e returns a new list by applying mapper function to it
    List *map(const std::function<T(int, T)> &cb)
    {
        size_t i = 0;
        List<T> *li = new List<T>();
        Node<T> *ptr = start;
        while (ptr != NULL)
        {
            li->push(func(i, ptr->data));
            ptr = ptr->link;
        }
        return li;
    }

    // Filters and returns a new list based on boolean values
    List *filter(const std::function<bool(int, T)> &cb)
    {
        size_t i = 0;
        List<T> *li = new List<T>();
        Node<T> *ptr = start;
        while (ptr != NULL)
        {
            if (cb(i, ptr->data))
                li->push(ptr->data);
            ptr = ptr->link;
        }
        return li;
    }
};

#endif