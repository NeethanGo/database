# database
Linux下数据库使用，主要关于SQLite3基础实践操作。  

# 介绍
以下是一些常见的Linux上使用的数据库以及它们的特性：

MySQL： MySQL是一个流行的关系型数据库管理系统（RDBMS），它支持SQL查询语言。特性包括：
开源和免费。
高性能，能够处理大量的并发连接。
支持复制和分布式架构，适用于高可用性需求。
有丰富的社区和生态系统支持。

PostgreSQL： PostgreSQL是另一个流行的关系型数据库管理系统，它强调标准兼容性和扩展性。特性包括：
开源和免费。
高度可定制，支持自定义数据类型和函数。
强大的事务支持和ACID兼容性。
支持复制和分布式架构。

SQLite： SQLite是一个轻量级的嵌入式关系型数据库，通常用于嵌入式系统和移动应用程序。特性包括：
服务器不需要，数据库以单个文件形式存储。
零配置，易于使用。
支持事务和SQL查询。

MongoDB： MongoDB是一个面向文档的NoSQL数据库，适用于存储非结构化或半结构化数据。特性包括：
面向文档的数据存储，JSON格式。
高度可伸缩，支持水平扩展。
自动分片和复制。
适用于大数据和实时应用。

Redis： Redis是一个高性能的键值存储数据库，通常用于缓存和实时数据处理。特性包括：
非常快的内存存储和检索。
支持丰富的数据类型，如字符串、列表、集合等。
支持发布/订阅模式。
适用于高速缓存和消息队列。

Cassandra： Apache Cassandra是一个分布式NoSQL数据库，适用于大规模分布式数据存储。特性包括：
分布式架构，高可用性和容错性。
支持列族数据模型。
可线性扩展，适用于大规模数据。

Oracle Database： Oracle Database是一个强大的商业级关系型数据库管理系统，广泛用于企业级应用。特性包括：
高度可用性和安全性。
强大的事务处理和分析功能。
支持多种数据类型和数据分区。

这只是一些常见的数据库，Linux上还有许多其他数据库可以满足不同的需求。选择数据库时，需根据项目的需求、性能、可用性、数据模型和开发团队的熟悉程度来权衡不同数据库的特性。  

# Linux环境安装
sudo apt install sqlite3
