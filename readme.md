
<div align=center> <img src="https://github.com/weipeng-jiao/XBLAS/blob/master/logo.JPG" > </div>

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
- [x] 目录&#x1F600;
- [ ] BLAS Level1&#x1F611; 


### BLAS命名规范
**BLAS是一个涉及基本线性代数操作的数学函数标准，BLAS一般分为三级。**  
`level 1: 主要完成向量与向量或者向量与标量以及范数之间的运算。`  
`level 2: 主要涉及矩阵与向量之间的操作。`  
`lecel 3：主要涉及矩阵与矩阵之间的操作。`

**BLAS**函数命名结构:   `<character><name><mod>()`

`<character>:表示数据类型和精度`
* `S` 实数 单精度
* `d` 实数 双精度
* `c` 复数 单精度
* `z` 复数 双精度

`<name>:表示运算方式和矩阵类型`  
**level 1表明计算类型**  
* `dot` 向量点积
* `rot` 向量旋转
* `swap` 向量交换

**level 2-3表明矩阵参数类型**
* `ge` 一般矩阵
* `gb` 一般的带状矩阵
* `sy` 对称矩阵
* `sp` 对称矩阵(压缩存储的)
* `sb` 带状对称矩阵
* `he` Hermitian矩阵
* `hb` Hermitian矩阵(压缩存储的)
* `tr` 三角矩阵
* `tp` 三角矩阵(压缩存储的)
* `tb` 带状三角矩阵
  
`<mod>：表示补充说明`  
**level 1**

* `c` 共轭向量
* `u` 不共轭向量
* `g` Givens rotation construction
* `m` modified Givens rotation
* `mg` modified Givens rotation construction  

**level 2**
* `mv` 矩阵与向量的乘积
* `sv` 计算只有一个未知向量的线性方程组
* `r` 秩 k 更新
* `r2` 秩 2k 更新

**level 3**  
* `mm` 矩阵与矩阵的乘积
* `sm` 计算有多个未知向量的线性方程组
* `rk` rank-k update of a matrix
* `r2k` rank-2k update of a matrix