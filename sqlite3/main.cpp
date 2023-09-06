#include "test_db.h"
#include <iostream>
#include <sqlite3.h>

int main()
{
    sqlite3 *db = openDatabase("students.db");
    if (db)
    {
        // 创建学生表
        if (createStudentTable(db))
        {
            std::cout << "成功创建表" << std::endl;
        }

        // 插入学生信息
        insertStudent(db, "Alice", 95.5);
        insertStudent(db, "Bob", 88.0);
        insertStudent(db, "Charlie", 92.3);

        // 查询学生信息并打印
        std::cout << "学生信息1：" << std::endl;
        queryStudents(db);

        // 修改学生成绩
        updateStudentScore(db, 1, 98.5); // 假设要将学号为1的学生成绩更新为98.5
        // 查询学生信息并打印
        std::cout << "学生信息2：" << std::endl;
        queryStudents(db);

        // 关闭数据库连接
        closeDatabase(db);
    }

    return 0;
}
