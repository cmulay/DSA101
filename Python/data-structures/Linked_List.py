class Node:
	def __init__(self,data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None
		self.length = 0		# to keep track of  no of Nodes in the list

	def printlist(self):
		if self.head:
			temp = self.head
			while temp:
				print(temp.data,end=' ')
				if temp.next:
					print('-->',end=' ')
					temp = temp.next
				else:
					print()
					break
		else:
			print('List is Empty')

	# insert node at the end of the list
	def appendNode(self,new_node):
		if self.head is None:
			self.head = new_node
			print('Node added as a Head Node')

		else:
			temp = self.head
			while temp.next:
					temp = temp.next
			temp.next = new_node
			print('Node appended')
		self.length += 1

	# insert node at the start of the list	
	def prepandNode(self,new_node):
		new_node.next = self.head
		self.head = new_node
		print('Node prepended')
		self.length += 1

	# insert new Node after a existing Node by passing the existing node's value
	def insertNode(self,new_node,value):
		prev_node = self.searchNode(value)
		if prev_node:
			new_node.next = prev_node.next
			prev_node.next = new_node
			self.length +=1
			print(f'Node is inserted after {prev_node.data}')
		else:
			print(f"Node with value {value} does'nt exists..can't insert the new Node")

	def deleteNode(self,value):
		if self.head:
			# checking if head Node is the one which is to be deleted
			if self.head.data == value:	
				self.head = self.head.next
				print(f'Node with {value} deleted')
				self.length -= 1				# decrement the length of the list
			else:
				temp = self.head
				prev = self.head
				while temp:
					if temp.data == value:
						prev.next = temp.next
						print(f'Node with {value} deleted')
						self.length -= 1		# decrement the length of the list
						return
					else:
						prev = temp
						temp = temp.next
				print(f"Node with value {value} does'nt exists")
		else:
			print(f"List is Empty..Cannot Delete")

	# returns the node if a node with the value exists, if not returns None
	def searchNode(self,value):
		if self.head:
			temp = self.head
			while temp:
				if temp.data == value:					
					return temp
				temp = temp.next
			return None
		else:
			print('List is Empty')
			return None

	# update the value of a existing Node based on the value
	def updateNode(self,old_value,new_value):
		# searchNode() returns the node if a node with old_value exists, if not returns None
		node = self.searchNode(old_value)		
		if node:
			node.data = new_value
			print('Value updated')
		else:
			print(f"Node with value {old_value} does'nt exists..can't update")

	# sorts the List
	def sortList(self):
		if self.length >1:		
			temp = self.head
			temp_2 = None
											# every time when outer loop iterates 
			while temp.next:						# smallest node is being set from the start
				temp_2 = temp.next
				while temp_2:
					if temp.data > temp_2.data:
						temp.data, temp_2.data = temp_2.data, temp.data
					temp_2 = temp_2.next
				temp = temp.next
			

def main():
	l = LinkedList()
	print('1. Append Node\n2. Prepand Node\n3. Insert Node \n4. Delete Node\n5. Print list\n6. Search Node\n7. Update Node\n')

	# MENU Driven Program 
	while True:
		choice = int(input("\nWhat do you want to do: "))
		if choice == 1:
			print('APPEND MODE')
			value = int(input("Enter the new value of node: "))
			new_node = Node(value)
			l.appendNode(new_node)

		elif choice == 2:
			print('PREPEND MODE')
			value = int(input("Enter the new value of node: "))
			new_node = Node(value)
			l.prepandNode(new_node)

		elif choice == 3:
			print('INSERT MODE')
			value_new_node = int(input("Enter the new value of node: "))
			new_node = Node(value_new_node)
			value = int(input("Enter the value of node after which new node to be inserted: "))
			l.insertNode(new_node,value)


		elif choice == 4:
			print('DELETE MODE')
			value = int(input("Enter the value of node which is to be Deleted: "))
			l.deleteNode(value)

		elif choice == 5:
			print('PRINT MODE')
			l.printlist()

		elif choice == 6:
			print('SEARCH MODE')
			value = int(input("Enter the value of node which is to be Searched: "))
			result = l.searchNode(value)
			if result:
				print(f'Node with value {result.data} exists')
			else:
				print(f"Node with value {value} does'nt exists")

		elif choice == 7:
			print('UPDATE MODE')
			old_value = int(input("Enter the value of node which is to be updated: "))
			new_value = int(input("Enter the new value: "))
			l.updateNode(old_value,new_value)

		elif choice == 8:
			print('SORT MODE')
			l.sortList()

		else:
			print('Exit')
			break


if __name__ == '__main__':
	main()
