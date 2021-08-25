
<p align="center"><img src="https://github.com/weipeng-jiao/XBLAS/blob/master/logo.JPG" alt="matrix" height="170px" width="550px"></img></p>

![](https://img.shields.io/badge/license-MIT-blue)
![](https://img.shields.io/badge/language-C%2B%2B-9cf)
![](https://img.shields.io/badge/Directive-OpenMP-ff69b4)

### 简介
**BLAS（basic linear algebra subroutine）是一系列基本线性代数运算函数的接口（interface）标准，本项目根据标准接口实现新的BLAS版本。**

### 计划实现版本
|方法|函数库|类库|
|---|---|---|
|串行|SFBLAS|SCBLAS|
|并行|PFBLAS|PCBLAS|

### 优化策略
* 低复杂度算法
* 消除重复计算
* 内存优化
* OpenMP多线程
* 分片执行
* 指令集优化SIMD

### 当前进度
- [x] BLAS LEVEL1&#x1F600; 


### 待解决的问题
- [ ] 异常处理系统&#x1F611; 
