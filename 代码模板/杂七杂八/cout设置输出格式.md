# cout设置输出格式

```c++
cout << setiosflags(ios::left) << setw(5) << 10 << '\n';  // 设置左对齐输出，空格在后

cout << setiosflags(ios::right) << setw(5) << 10 << '\n'; // 设置右对齐输出，空格在前

cout << setfill('0') << setw(8) << 10 << '\n';            // 输出前导0（或任何前导）
```

