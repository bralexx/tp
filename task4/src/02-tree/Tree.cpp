#include "Tree.h"

#include <boost/filesystem.hpp>

using boost::filesystem::exists;
using boost::filesystem::is_directory;
using boost::filesystem::path;
using boost::filesystem::directory_iterator;

FileNode GetTree(const std::string& path, bool dirs_only) {
  FileNode answer;
  if (!exists(path)) {
	std::cout << 1 << '\n';
    throw std::invalid_argument("Path not exist");
  }

  if (!is_directory(path)) {
	std::cout << 2 << '\n';
    throw std::invalid_argument("Path is not directory");
  }
  answer.name = boost::filesystem::path(path).filename().string();
  answer.is_dir = true;
  for (auto& child: directory_iterator(path)) {
    if (is_directory(child)){
	std::cout << 3 << '\n';
      answer.children.push_back(
          GetTree(boost::filesystem::path(child).string(), dirs_only)
      );
    } else {
	std::cout << 4 << '\n';
      if (dirs_only) {
        continue;
      }
	std::cout << 5 << '\n';
      answer.children.push_back({
        boost::filesystem::path(child).filename().string(), false, {}
      });
    }
  }
  return answer;
}


void FilterEmptyNodes(const FileNode& node, const path& current_path=".") {
    if (!node.is_dir) {
	std::cout << 6  << '\n';
        return;
    }

    if (node.children.empty()) {
std::cout << 7 << '\n';
        boost::filesystem::remove(current_path);
    }
    for (auto& child: node.children) {
	std::cout << 8 << '\n';
FilterEmptyNodes(child, current_path / child.name); 
    }
}

bool operator == (const FileNode& f1, const FileNode& f2) {
  return f1.name == f2.name && f1.is_dir == f2.is_dir && f1.children == f2.children;
}

