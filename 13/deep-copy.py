

class Node:
    def __init__(self, val, children=None):
        self.val = val
        self.children = children if children is not None else []
    
people = {
    'bob': 23,
    'alice': 30,
    'john': 25,
    'dave': 35,
    'sara': 28,
    'jason': 40,
    'tom': 21
}

def build_binary_search_tree(people):
    if not people:
        return None

    # Convert the dictionary to a sorted list of tuples
    sorted_people = sorted(people.items(), key=lambda x: x[0])

    def build_tree(sorted_people):
        if not sorted_people:
            return None
        
        mid = len(sorted_people) // 2
        node = Node(sorted_people[mid][0])
        
        node.children.append(build_tree(sorted_people[:mid]))  # Left subtree
        node.children.append(build_tree(sorted_people[mid + 1:]))  # Right subtree
        
        return node

    return build_tree(sorted_people)

def print_tree(node, level=0):
    if node is not None:
        print_tree(node.children[1], level + 1)  # Right child
        print(' ' * 4 * level + '->', node.val)
        print_tree(node.children[0], level + 1)  # Left child

def print_mermaid_tree(node):
    def traverse(node):
        if node is None:
            return ""
        
        result = ""
        for child in node.children:
            if child is not None:
                result += f'    {node.val} --> {child.val}\n'
                result += traverse(child)
        return result

    mermaid_str = "graph TD\n"
    mermaid_str += traverse(node)
    return mermaid_str

bst_root = build_binary_search_tree(people)
print_tree(bst_root)
mermaid_output = print_mermaid_tree(bst_root)
print("\nMermaid Diagram:\n")
print(mermaid_output)