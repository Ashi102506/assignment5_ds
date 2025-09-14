
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

    def reverse(self):
        prev = None
        current = self.head

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        self.head = prev

def main():
    ll = LinkedList()

    values = [1, 2, 3, 4]
    for val in values:
        ll.insert(val)

    print("Original Linked List:", ll.display())

    ll.reverse()

    print("Reversed Linked List:", ll.display())

if __name__ == "__main__":
    main()