class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def display(self):
        result = []
        current = self.head
        while current:
            result.append(current.data)
            current = current.next
        return result

    def find_middle(self):
        if not self.head:
            return None

        slow = self.head
        fast = self.head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        return slow.data

def main():
    ll = LinkedList()

    values = [1, 2, 3, 4, 5]
    for val in values:
        ll.insert(val)

    print("Linked List:", ll.display())
    middle = ll.find_middle()
    print("Middle element:", middle)

    ll2 = LinkedList()
    values2 = [1, 2, 3, 4]
    for val in values2:
        ll2.insert(val)

    print("\nLinked List:", ll2.display())
    middle2 = ll2.find_middle()
    print("Middle element:", middle2)

if __name__ == "__main__":
    main()