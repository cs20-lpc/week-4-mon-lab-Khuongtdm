template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    this->head = nullptr;
    this->length = 0;
    if (copyObj.head ==nullptr)
        return;

    this->head = new Node(copyObj.head->value);
    this->length++;

    Node* sourHead = copyObj.head->next;
    Node* destHead = this->head;
    while (sourHead != nullptr)
    {
        Node* newNode = new Node(sourHead->value);
        destHead->next = newNode;
        sourHead = sourHead->next;
        destHead = destHead->next;
        this->length++;
    }
    destHead->next = nullptr;
    
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO
    //empty list 
    //
    if (position < 0 || position>this->length )
        throw string("out of index");
    Node* curr = head;

    if(curr == nullptr || position==this->length)
    {
        append(elem);
        return;
    }
    Node* previous = head;
    Node* newNode = new Node(elem);
    /// in case when you insert at the beginning
    if (position ==0)
    {
        head = newNode;
        newNode->next = curr;
        this->length++;
        return;
    }

    for (int i = 0;i < position - 1;i++)
    {
        curr = curr->next;
        previous = previous->next;
    }
    curr = curr->next;
    previous->next = newNode;
    newNode->next = curr;
    this->length++;
    return;

}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
    //out of index
    if (position <0 || position >= this->length){
        throw string("Out of index");
        }
    Node* curr = head;
    //if there is no element in the list
    if (curr == nullptr)
        throw string("The linkedlist is empty\n");
    if (position == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        this->length--;
        return;
    }
    Node* previous = head;
    for (int i = 0;i < position-1;i++)
    {
        curr = curr->next;
        previous = previous->next;
    }
    curr = curr->next;
    previous->next = curr->next;
    delete curr;
    this->length--;
    return;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
