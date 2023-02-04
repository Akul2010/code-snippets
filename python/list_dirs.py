import os

def list_directories(path):
    return [entry for entry in os.scandir(path) if entry.is_dir()]

directories = list_directories(".")

for directory in directories:
    print(directory.path)
