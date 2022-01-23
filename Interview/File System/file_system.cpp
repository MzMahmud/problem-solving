#ifndef __FILE_SYSTEM_CPP__
#define __FILE_SYSTEM_CPP__
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class FileSystem {
  private:
    struct Node {
        std::string name;
        std::unordered_map<std::string, Node *> children;

        Node(std::string name) : name(name) {}

        Node() : Node("") {}

        bool add_child_from_path(const std::vector<std::string> &path_list,
                                 int start_index = 0) {
            if (start_index == path_list.size()) {
                return false;
            }
            const std::string &child_name = path_list[start_index];
            bool is_child_added           = false;
            if (!contains_child(child_name)) {
                is_child_added       = true;
                children[child_name] = new Node(child_name);
            }
            bool added_in_lower_layer
                = children[child_name]->add_child_from_path(path_list, start_index + 1);
            return is_child_added || added_in_lower_layer;
        }

        void print_tree(std::string indent = "", std::ostream &sout = std::cout) {
            sout << indent << FileSystem::SEPARTOR << name << std::endl;
            for (const auto &[_, child_node] : children) {
                child_node->print_tree(indent + "|\t", sout);
            }
        }

      private:
        bool contains_child(const std::string &name) {
            std::unordered_map<std::string, Node *>::const_iterator child_iterator
                = children.find(name);
            return child_iterator != children.end();
        }
    };

    static std::string SEPARTOR;
    Node virtual_root;

    static std::vector<std::string> split(const std::string &s, const std::string &del) {
        std::vector<std::string> split_string;
        int start = 0;
        int end   = s.find(del);
        while (end != -1) {
            split_string.emplace_back(s.substr(start, end - start));
            start = end + del.size();
            end   = s.find(del, start);
        }
        split_string.emplace_back(s.substr(start, end - start));
        return split_string;
    }

  public:
    bool add_file(const std::string &file_path) {
        return add_file(split(file_path, SEPARTOR));
    }

    bool add_file(const std::vector<std::string> &file_path) {
        return virtual_root.add_child_from_path(file_path, 0);
    }

    void print_as_tree(std::ostream &sout = std::cout) {
        for (const auto &[_, child_node] : virtual_root.children) {
            child_node->print_tree("", sout);
        }
    }
};

std::string FileSystem::SEPARTOR = "/";

#endif // __FILE_SYSTEM__
