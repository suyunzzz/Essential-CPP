<!--
 * @Author: your name
 * @Date: 2020-12-18 20:41:53
 * @LastEditTime: 2020-12-19 00:22:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\readme.md
-->


## vector中的resize()和reserve()
>`resize`控制`length`

>`reserve`控制`capacity`

>容器调用`resize()`函数后，所有的空间都已经初始化了，所以可以直接访问。
>而`reserve()`函数预分配出的空间没有被初始化，所以不可访问。
