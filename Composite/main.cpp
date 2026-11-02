#include <iostream> 
#include <vector> 
#include <memory> 
#include <string> 
using namespace std;

class FileSystem { 
     public: virtual void show(int indent = 0) const = 0;
virtual ~FileSystem() = default;
};

class File : public FileSystem {
     private: string name;
public: File(const string& name) : name(name) {}
void show(int indent = 0) const override {
    cout << string(indent, ' ') << "File: "
         << name << endl;
}
};

class Folder : public FileSystem {
     private: string name;
vector<shared_ptr<FileSystem>> children;
public: Folder(const string& name) : name(name) {}

void add(shared_ptr<FileSystem> item) {
    children.push_back(item);
}

void remove(shared_ptr<FileSystem> item) {
    for (auto it = children.begin();
         it != children.end(); ++it) {
                if (*it == item) {
            children.erase(it);
            return;
        }
    }
}

void show(int indent = 0) const override {
    cout << string(indent, ' ') << "Folder: " << name << endl;

    for (const auto& child : children) {
        child->show(indent + 4);
    }
}
};

int main() {
         auto root = make_shared<Folder>("Root");
         auto documents = make_shared<Folder>("Documents");
         auto images = make_shared<Folder>("Images");
         auto file1 = make_shared<File>("report.txt");
         auto file2 = make_shared<File>("photo.jpg");
         auto file3 = make_shared<File>("notes.txt");

documents->add(file1);
documents->add(file3);
images->add(file2);

root->add(documents);
root->add(images);

root->show();

return 0;
}