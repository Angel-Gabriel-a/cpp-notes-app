#include "notes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

static std::string get_current_time() {
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M");
    return oss.str();
}

NoteManager::NoteManager(std::string file) : filename(file), next_id(1) {
    load_from_file();
}

void NoteManager::load_from_file() {
    std::ifstream fin(filename);
    if (!fin.is_open()) return;

    std::string line;
    while (std::getline(fin, line)) {
        if (line == "---NOTE---") {
            Note n;
            std::string id_str;
            std::getline(fin, id_str);
            n.id = std::stoi(id_str);
            std::getline(fin, n.title);
            std::getline(fin, n.date);
            std::getline(fin, n.content);
            notes.push_back(n);
            if (n.id >= next_id) next_id = n.id + 1;
        }
    }
    fin.close();
}

void NoteManager::save_to_file() {
    std::ofstream fout(filename);
    for (const Note& n : notes) {
        fout << "---NOTE---\n";
        fout << n.id << "\n";
        fout << n.title << "\n";
        fout << n.date << "\n";
        fout << n.content << "\n";
    }
    fout.close();
}

void NoteManager::add_note(std::string title, std::string content) {
    Note n;
    n.id = next_id++;
    n.title = title;
    n.content = content;
    n.date = get_current_time();
    notes.push_back(n);
    save_to_file();
    std::cout << "[OK] Note saved! ID = " << n.id << "\n";
}

void NoteManager::delete_note(int id) {
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        if (it->id == id) {
            notes.erase(it);
            save_to_file();
            std::cout << "[OK] Deleted note ID=" << id << "\n";
            return;
        }
    }
    std::cout << "[ERR] Note ID=" << id << " not found.\n";
}

void NoteManager::list_notes() {
    if (notes.empty()) {
        std::cout << "No notes yet.\n";
        return;
    }
    std::cout << "\n===== All Notes =====\n";
    for (const Note& n : notes) {
        std::cout << "[" << n.id << "] " << n.title
                  << "  (" << n.date << ")\n";
    }
    std::cout << "=====================\n";
}

void NoteManager::view_note(int id) {
    for (const Note& n : notes) {
        if (n.id == id) {
            std::cout << "\n=====================\n";
            std::cout << "Title  : " << n.title << "\n";
            std::cout << "Date   : " << n.date << "\n";
            std::cout << "Content: " << n.content << "\n";
            std::cout << "=====================\n";
            return;
        }
    }
    std::cout << "[ERR] Note ID=" << id << " not found.\n";
}

void NoteManager::search_notes(std::string keyword) {
    std::cout << "\nSearch: " << keyword << "\n";
    bool found = false;
    for (const Note& n : notes) {
        if (n.title.find(keyword) != std::string::npos ||
            n.content.find(keyword) != std::string::npos) {
            std::cout << "[" << n.id << "] " << n.title
                      << "  (" << n.date << ")\n";
            found = true;
        }
    }
    if (!found) std::cout << "No matching notes found.\n";
}