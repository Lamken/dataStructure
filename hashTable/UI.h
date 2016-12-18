#ifndef UI_H
#define UI_H


class UI {
public:
    UI(table *_students);

    ~UI();

    void hint();

    void showOnesInformation(Person *person);

    void insert();

    void erase();

    void search();

    void showTable();

    void getSize();

private:
    table *students;
};

#endif
