class FileSystem:

    SEPERATOR = "/"

    class Node:
        def __init__(self, name):
            self.name = name
            self.children = dict()

        def set_children(self, path_array, start_index=0):
            if start_index == len(path_array):
                return False

            children_name = path_array[start_index]
            is_child_added = False
            if children_name not in self.children:
                is_child_added = True
                self.children[children_name] = FileSystem.Node(children_name)

            child_node = self.children.get(children_name)
            added_in_beloy_layer = child_node.set_children(
                path_array, start_index + 1)

            return is_child_added or added_in_beloy_layer

        def print_tree(self, indent=""):
            print(f'{indent}{FileSystem.SEPERATOR}{self.name}')
            for child_node in self.children.values():
                child_node.print_tree(f'{indent}|\t')

    def __init__(self):
        self.virtual_root = FileSystem.Node("")

    def add_file(self, file_path):
        file_path_array = file_path.split(FileSystem.SEPERATOR)
        if not file_path_array:
            return False
        return self.virtual_root.set_children(file_path_array)

    def print_as_tree(self):
        for root in self.virtual_root.children.values():
            root.print_tree()
