# 数据结构之**排序**
****
### Author:Lovemefan
### QQ:450489712
### E-mail:450489712@qq.com
****
## 排序
#### 点击查看源代码
* [冒泡排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/冒泡排序_BubbleSort.c )
* [选择排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/选择排序_SelectSort.c  )
* [插入排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/插入排序_InsertSort.c )
* [快速排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/快速排序_QiuckSort.c  )
* [堆排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/堆排序_HeapSort.c  )
* [希尔排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/希尔排序_ShellSort.c )
* [归并排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/冒泡排序_BubbleSort.c )
* [基数排序](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/冒泡排序_BubbleSort.c )
* [数组排序(基数排序的一种极端方式)](https://github.com/lovemefan/C_Data_Structure/blob/master/排序/数组排序_ArraySort.c  )
## 排序效率比较
```
为了演示效果此程序将用各种排序方式排序100组10000个
元素的随机数组并且取其平均比较次数和平均时间来对比
```
|排序|平均情况 |平均时间(秒)|最坏情况|最好情况|空间复杂度|稳定性|复杂性|
|---|------|----|---|---|---|---|---|
|冒泡排序|O(N^2)|0.457370|O(N^2)|O(N)|O(L)|稳定|简单|
|选择排序|O(N^2)|0.152200|O(N^2)|O(N)|O(L)|不稳定|简单|
|插入排序|O(N^2)|0.079670|O(N^2)|O(N)|O(L)|稳定|简单|
|快速排序|O(N logN)|0.002310|O(N^2)|O(N logN)|O(L)|不稳定|较复杂|
|堆排序|O(N logN)|0.001070|O(N logN)|O(N logN)|O(L)|不稳定|较复杂|
|希尔排序|O(N^1.3)|0.004750|||O(L)|不稳定|较复杂|
|数组排序|O(n)|0.000210|O(n)|O(n)|O(n)|稳定|较复杂|


