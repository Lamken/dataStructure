#ifndef UI_CPP
#define UI_CPP

#include "nameTable.cpp"
#include "UI.h"

UI::UI(table *_students) : students(_students) {}

UI::~UI() {}

void UI::hint() {
    std::cout << "----------------------------\n";
    std::cout << "欢迎使用学生名单,以下是命令表:\n"
              << "1.在名单中记录一名学生\n"
              << "2.在名单中删除一名学生\n"
              << "3.通过姓名搜索一名学生\n"
              << "4.按序号显示学生名单\n"
              << "5.显示记录于名单中的学生数量\n"
              << "0.退出\n";
    std::cout << "----------------------------\n";
}

void UI::showOnesInformation(Person *person) {
    if (person != NULL) {
        std::cout << person->name << ' ' << (person->male ? "男 " : "女 ")
                  << "学号: " << person->id;
    }
}

void UI::insert() {
    if (students->getSize() == MAX_SIZE) {
        std::cout << "增加失败,已达到最大纪录人数!\n";
        std::cout << "----------------------------\n";
        return;
    }

    std::string name;
    bool male;
    int id;
    std::cout << "记录一名学生:\n"
              << "----------------------------\n"
              << "学生姓名(拼音): ";
    std::cin >> name;
    std::cout << "学生性别: ";
    std::cin >> male;
    std::cout << "学生学号: ";
    std::cin >> id;
    Person *person = new Person(name, male, id);
    students->insert(person);
    std::cout << "\n增加学生 " << name << ' ' << (male ? "男 " : "女 ") << id << " 成功!\n";
    std::cout << "----------------------------\n";
}

void UI::erase() {
    if (students->getSize() == 0) {
        std::cout << "删除失败,名单为空!\n";
        return;
    }

    std::cout << "删除一名学生:\n"
              << "----------------------------\n"
              << "学生姓名(拼音): ";
    std::string name;
    std::cin >> name;
    int hashNumber = students->search(name);
    if (hashNumber == -1) {
        std::cout << "删除失败,查无此人!\n";
        std::cout << "----------------------------\n";
        return;
    }
    std::cout << "删除学生　";
    showOnesInformation(students->getAPerson(hashNumber));
    std::cout << " 成功\n";
    students->erase(name);
    std::cout << "----------------------------\n";
}

void UI::search() {
    std::cout << "查询一名学生:\n"
              << "----------------------------\n"
              << "学生姓名(拼音): ";
    std::string name;
    std::cin >> name;
    int hashNumber = students->search(name);
    if (hashNumber == -1) {
        std::cout << "查询失败,您所查找的学生没有记录在册!\n";
    } else {
        showOnesInformation(students->getAPerson(hashNumber));
        std::cout << std::endl;
    }
    std::cout << "----------------------------\n";
}

void UI::showTable() {
    std::cout << "学生名单如下:\n";
    std::cout << "----------------------------\n";
    std::cout << "序号  名字            性别  学号\n";
    students->showTable();
    std::cout << "----------------------------\n";
}

void UI::getSize() {
    std::cout << "----------------------------\n";
    std::cout << "目前记录在册的学生人数为: " << students->getSize() << std::endl;
    std::cout << "----------------------------\n";
}

#endif
