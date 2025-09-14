
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

    def count_and_delete_occurrences(self, key):
        count = 0
        current = self.head

        while current:
            if current.data == key:
                count += 1
            current = current.next

        while self.head and self.head.data == key:
            self.head = self.head.next

        current = self.head
        while current and current.next:
            if current.next.data == key:
                current.next = current.next.next
            else:
                current = current.next

        return count

def main():
    ll = LinkedList()

    values = [1, 2, 1, 2, 1, 3, 1]
    for val in values:
        ll.insert(val)

    print("Original Linked List:", ll.display())

    key = 1
    count = ll.count_and_delete_occurrences(key)

    print(f"Count of {key}: {count}")
    print("Updated Linked List:", ll.display())

if __name__ == "__main__":
    main()
