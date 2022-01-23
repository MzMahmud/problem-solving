from file_system import FileSystem

files = [
    "/mnt/sdcard/folder1/file1.txt",
    "/mnt/sdcard/folder1/file2.txt",
    "/mnt/sdcard/folder2/file3.txt",
    "/tmp/folder3/file4.txt",
    "config/config.json",
    "/tmp/folder3/file4.txt",
]

file_system = FileSystem()

for file_name in files:
    print(f'{file_name} is_added = {file_system.add_file(file_name)}')

print('\n\nFile System Tree:')
file_system.print_as_tree()
