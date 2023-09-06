#include "test_db.h"


// 打开或创建数据库并返回数据库连接
sqlite3* openDatabase(const char* dbName) {
    sqlite3* db;
    char* errMsg = 0;

    int rc = sqlite3_open(dbName, &db);
    if (rc) {
        std::cerr << "无法打开/创建数据库: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return nullptr;
    }

    return db;
}

// 关闭数据库连接
void closeDatabase(sqlite3* db) {
    sqlite3_close(db);
}

// 创建学生表
bool createStudentTable(sqlite3* db) {
    const char* createTableSQL = "CREATE TABLE students ("
                                  "    student_id INTEGER PRIMARY KEY,"
                                  "    name TEXT NOT NULL,"
                                  "    score REAL"
                                  ");";

    char* errMsg = 0;
    int rc = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "无法创建表: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}

// 插入学生信息
bool insertStudent(sqlite3* db, const char* name, double score) {
    const char* insertSQL = "INSERT INTO students (name, score) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "无法准备插入语句: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, score);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "无法插入数据: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

// 查询并打印学生信息
void queryStudents(sqlite3* db) {
    const char* selectSQL = "SELECT * FROM students;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "查询失败: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int studentId = sqlite3_column_int(stmt, 0);
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        double score = sqlite3_column_double(stmt, 2);

        std::cout << "学号: " << studentId << ", 姓名: " << name << ", 成绩: " << score << std::endl;
    }

    sqlite3_finalize(stmt);
}

// 修改学生成绩
bool updateStudentScore(sqlite3* db, int studentId, double newScore) {
    const char* updateSQL = "UPDATE students SET score = ? WHERE student_id = ?;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, updateSQL, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "无法准备更新语句: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_double(stmt, 1, newScore);
    sqlite3_bind_int(stmt, 2, studentId);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "无法更新数据: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}
