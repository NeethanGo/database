#ifndef __TEST_DB_H
#define __TEST_DB_H

#include <iostream>
#include <sqlite3.h>


// 打开或创建数据库并返回数据库连接
sqlite3 *openDatabase(const char *dbName);

// 关闭数据库连接
void closeDatabase(sqlite3 *db);

// 创建学生表
bool createStudentTable(sqlite3 *db);

// 插入学生信息
bool insertStudent(sqlite3 *db, const char *name, double score);

// 查询并打印学生信息
void queryStudents(sqlite3 *db);

bool updateStudentScore(sqlite3* db, int studentId, double newScore);

#endif /* __TEST_DB_H */
