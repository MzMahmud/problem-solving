import java.util.HashMap;
import java.util.Map;

public class FileSystem {
    private static class FileNode {
        public String name;
        public final Map<String, FileNode> children;

        public FileNode(String name) {
            this.name = name;
            this.children = new HashMap<>();
        }

        public boolean addChildren(String[] filePath, int startingIndex) {
            if (startingIndex == filePath.length) {
                return false;
            }
            String childName = filePath[startingIndex];
            boolean createdNewChild = false;
            if (!children.containsKey(childName)) {
                createdNewChild = true;
                children.put(childName, new FileNode(childName));
            }
            FileNode childFileNode = children.get(childName);
            boolean createdInBelowLevel = childFileNode.addChildren(filePath, startingIndex + 1);
            return createdNewChild || createdInBelowLevel;
        }

        public void printTree(String indent) {
            System.out.println(indent + FileSystem.SEPARATOR + name);
            children.values()
                    .forEach(childFileNode -> childFileNode.printTree(indent + "|\t"));
        }
    }

    private static final String SEPARATOR = "/";

    private final Map<String, FileNode> rootFileNodesByName;

    public FileSystem() {
        this.rootFileNodesByName = new HashMap<>();
    }

    private boolean addFile(String[] filePath) {
        String root = filePath[0];
        boolean isAdded = false;
        if(!rootFileNodesByName.containsKey(root)) {
            isAdded = true;
            rootFileNodesByName.put(root, new FileNode(root));
        }
        FileNode rootFileNode = rootFileNodesByName.get(root);
        isAdded |= rootFileNode.addChildren(filePath, 1);
        return isAdded;
    }

    public boolean addFile(String filePath) {
        String[] filePathArray = filePath.split(SEPARATOR);
        if (filePathArray.length == 0) {
            return false;
        }
        return addFile(filePathArray);
    }

    public void printFilesTree() {
        rootFileNodesByName.values()
                           .forEach(childFileNode -> childFileNode.printTree(""));
    }
}
