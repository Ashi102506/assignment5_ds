class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def insert_before_value(self, data, target):
        if not self.head:
            return
        if self.head.data == target:
            self.insert_at_beginning(data)
            return
        current = self.head
        while current.next and current.next.data != target:
            current = current.next
        if current.next:
            new_node = Node(data)
            new_node.next = current.next
            current.next = new_node

    def insert_after_value(self, data, target):
        current = self.head
        while current and current.data != target:
            current = current.next
        if current:
            new_node = Node(data)
            new_node.next = current.next
            current.next = new_node

    def delete_from_beginning(self):
        if self.head:
            self.head = self.head.next

    def delete_from_end(self):
        if not self.head:
            return
        if not self.head.next:
            self.head = None
            return
        current = self.head
        while current.next.next:
            current = current.next
        current.next = None

    def delete_specific_value(self, target):
        if not self.head:
            return
        if self.head.data == target:
            self.head = self.head.next
            return
        current = self.head
        while current.next and current.next.data != target:
            current = current.next
        if current.next:
            current.next = current.next.next

    def search_node(self, target):
        current = self.head
        position = 0
        while current:
            if current.data == target:
                return position
            current = current.next
            position += 1
        return -1

    def display(self):
        if not self.head:
            print("List is empty")
            return
        current = self.head
        while current:
            print(current.data, end=" -> " if current.next else " -> NULL\n")
            current = current.next

def main():
    ll = LinkedList()

    while True:
        print("\n--- Linked List Operations ---")
        print("1. Insert at beginning")
        print("2. Insert at end")
        print("3. Insert before specific value")
        print("4. Insert after specific value")
        print("5. Delete from beginning")
        print("6. Delete from end")
        print("7. Delete specific node")
        print("8. Search for a node")
        print("9. Display all nodes")
        print("10. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            data = int(input("Enter data: "))
            ll.insert_at_beginning(data)
            print(f"Inserted {data} at beginning")

        elif choice == 2:
            data = int(input("Enter data: "))
            ll.insert_at_end(data)
            print(f"Inserted {data} at end")

        elif choice == 3:
            data = int(input("Enter data to insert: "))
            target = int(input("Enter target value: "))
            ll.insert_before_value(data, target)
            print(f"Inserted {data} before {target}")

        elif choice == 4:
            data = int(input("Enter data to insert: "))
            target = int(input("Enter target value: "))
            ll.insert_after_value(data, target)
            print(f"Inserted {data} after {target}")

        elif choice == 5:
            ll.delete_from_beginning()
            print("Deleted from beginning")

        elif choice == 6:
            ll.delete_from_end()
            print("Deleted from end")

        elif choice == 7:
            target = int(input("Enter value to delete: "))
            ll.delete_specific_value(target)
            print(f"Deleted {target}")

        elif choice == 8:
            target = int(input("Enter value to search: "))
            pos = ll.search_node(target)
            if pos != -1:
                print(f"Node {target} found at position {pos}")
            else:
                print(f"Node {target} not found")

        elif choice == 9:
            print("Current list:")
            ll.display()

        elif choice == 10:
            print("Exiting...")
            break

        else:
            print("Invalid choice!")

if __name__ == "__main__":
    main()

