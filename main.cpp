#include "notes.h"
#include <iostream>
#include <string>
#include <limits>

void print_menu() {
    std::cout << "\n====== Notes App ======\n";
    std::cout << "  1. Add note\n";
    std::cout << "  2. List all notes\n";
    std::cout << "  3. View a note\n";
    std::cout << "  4. Delete a note\n";
    std::cout << "  5. Search notes\n";
    std::cout << "  0. Exit\n";
    std::cout << "=======================\n";
    std::cout << "Enter choice: ";
}

int main() {
    NoteManager manager("notes_data.txt");

    int choice;
    while (true) {
        print_menu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) {
            std::cout << "Goodbye!\n";
            break;
        } else if (choice == 1) {
            std::string title, content;
            std::cout << "Title: ";
            std::getline(std::cin, title);
            std::cout << "Content: ";
            std::getline(std::cin, content);
            manager.add_note(title, content);
        } else if (choice == 2) {
            manager.list_notes();
        } else if (choice == 3) {
            int id;
            std::cout << "Enter note ID: ";
            std::cin >> id;
            manager.view_note(id);
        } else if (choice == 4) {
            int id;
            std::cout << "Enter note ID to delete: ";
            std::cin >> id;
            manager.delete_note(id);
        } else if (choice == 5) {
            std::string keyword;
            std::cout << "Enter keyword: ";
            std::getline(std::cin, keyword);
            manager.search_notes(keyword);
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}