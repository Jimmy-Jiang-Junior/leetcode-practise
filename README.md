# leetcode-practis
基于gtest完成C/C++测试，包括：如何将googletest的代码编译成动态库，基本cmake的书写

step1: sh GetGtest.sh
       如果本地没有googletest的版本, 运行GetGest的版本获取googletest, 并编译生成动态库

step2: cd base/build && sh build.sh
       可以根据自己的需要在src目录下添加源文件, 在testcase目录下添加测试用例, 需要注意的是文件gtest_main.cpp是运行必须的


最终googletest运行的结果如下：

[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from GTEST_BASE
[ RUN      ] GTEST_BASE.CASE_001
This is the base gtest case
Hello world!
[       OK ] GTEST_BASE.CASE_001 (0 ms)
[----------] 1 test from GTEST_BASE (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.

基于gtest完成leetcode代码编写和测试用例构造

增加leetcode刷题记录:

L0127 单词接龙 （图、BFS、带测试case)
L0200 岛屿数量 (图、DFS、并查集)
L0211 添加与搜索单词-数据结构设计 （字典树）
L0648 单词替换 （字典树、带测试case）
