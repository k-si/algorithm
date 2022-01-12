cmake_minimum_required(VERSION 3.20)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        algorithm
        main.cpp
        acwing/basic/ch01/quick_sort/785/main.cpp
        acwing/basic/ch01/quick_sort/786/main.cpp
        acwing/basic/ch01/merge_sort/787/main.cpp
        acwing/basic/ch01/merge_sort/788/main.cpp
        acwing/basic/ch01/binary_search/789/main.cpp
        acwing/basic/ch01/binary_search/790/main.cpp
        acwing/basic/ch01/high_precision/791/main.cpp
        acwing/basic/ch01/high_precision/792/main.cpp
        acwing/basic/ch01/high_precision/793/main.cpp
        acwing/basic/ch01/high_precision/794/main.cpp
        acwing/basic/ch01/prefix_sum_difference/795/main.cpp
        acwing/basic/ch01/prefix_sum_difference/796/main.cpp
        acwing/basic/ch01/prefix_sum_difference/797/main.cpp
        acwing/basic/ch01/prefix_sum_difference/798/main.cpp
        acwing/basic/ch01/double_pointer/799/main.cpp
        acwing/basic/ch01/double_pointer/800/main.cpp
        acwing/basic/ch01/double_pointer/2816/main.cpp
        acwing/basic/ch01/discretization/802/main.cpp
        acwing/basic/ch01/section_merge/803/main.cpp
        leetcode/algorithm/ds.h
        leetcode/algorithm/1_两数之和/solution.cpp
        leetcode/algorithm/2_两数相加/solution.cpp
        leetcode/algorithm/3_无重复字符的最长子串/solution.cpp
        leetcode/algorithm/4_寻找两个正序数组的中位数_/solution.cpp
        leetcode/algorithm/5_最长回文子串/solution.cpp
        leetcode/algorithm/6_Z字形变换/solution.cpp
        leetcode/algorithm/7_整数反转/solution.cpp
        leetcode/algorithm/7_整数反转/solution2.cpp
        leetcode/algorithm/8_字符串转换整数/ssolution.cpp
        leetcode/algorithm/9_回文数/solution.cpp
        leetcode/algorithm/10_正则表达式匹配_/solution.cpp
        leetcode/algorithm/11_盛最多水的容器/solution.cpp
        leetcode/algorithm/12_整数转罗马数字/solution.cpp
        leetcode/algorithm/13_罗马数字转整数/solution.cpp
        acwing/basic/ch02/linked_list_single/826/main.cpp
        leetcode/algorithm/14_最长公共前缀/solution.cpp
        acwing/basic/ch02/linked_list_double/827/main.cpp
        acwing/basic/ch02/stack/828/main.cpp
        acwing/basic/ch02/stack/3302/main.cpp
        acwing/basic/ch02/queue/829/main.cpp
        acwing/basic/ch02/stack_monotone/830/main.cpp
        acwing/basic/ch02/queue_monotone/154/main.cpp
        acwing/basic/ch02/kmp/831/main.cpp
        acwing/basic/ch02/trie/143/main.cpp
        acwing/basic/ch02/trie/835/main.cpp acwing/basic/ch02/joint_search_set/836/main.cpp acwing/basic/ch02/joint_search_set/837/main.cpp acwing/basic/ch02/joint_search_set/240/main.cpp acwing/basic/ch02/hash_table/840/main.cpp)
