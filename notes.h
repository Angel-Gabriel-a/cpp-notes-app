#ifndef NOTES_H
#define NOTES_H

#include <string>
#include <vector>

// 代表一条笔记
struct Note {
    int id;
    std::string title;
    std::string content;
    std::string date;
};

// 笔记管理器
class NoteManager {
private:
    std::vector<Note> notes;
    std::string filename;
    int next_id;

    void load_from_file();   // 从文件读取
    void save_to_file();     // 保存到文件

public:
    NoteManager(std::string file);  // 构造函数

    void add_note(std::string title, std::string content);
    void delete_note(int id);
    void list_notes();
    void view_note(int id);
    void search_notes(std::string keyword);
};

#endif