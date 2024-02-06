# CS4100: Computer Architecture

在 CS4100 计算机结构这门课，黄婷婷教授大致按 Computer Organization and Design: The Hardway/Software Interface 这本书的顺序对计算机结构进行了详尽的讲解，着重讲解了1-5章的内容，课程与该教材搭配学习效果极佳。由于在这门课程的开课时间，教材只出到了 4ed，所以选用教材是 4ed，但是 5ed 和 4ed 内容差别不大，所以笔者采用了 5ed 进行学习。

个人认为能力是在实作中提升，但遗憾的是，该课程并未公开作业部分，经过一番搜寻，发现阳明交大李毅郎教授和科技大学刘一宇副教授均有开发 Cache 相关的实作，遂以这些作为本课程的作业。

> 交大李毅郎教授讲授的 [計算機組織][nycu-co] 同样基于 MIPS 指令集，同时还开放了[课程录影](https://www.youtube.com/playlist?list=PLj6E8qlqmkFvSHyGAFqY4sX0Ee7eLqmq2)，可以与本课程进行比照学习。

阳明交大李毅郎教授相关 Labs (Lab6 为 Cache Lab):

- https://github.com/nctu-ms07/Computer-Organization [Spring 2020]
- https://github.com/wishx97/Computer-Organization-NCTU [Spring 2018]
- https://github.com/Sea-n/NCTU-109B-Comp-Org [Spring 2021]

科技大学刘一宇副教授关于 Cache 的 Labs:

- [快取記憶體組織](https://www.youtube.com/playlist?list=PLu7X08EhejdqIV5-9bqZ6u9uZOg1sBdwO) [YouTube]

## Course Description

To understand how a computer system work. Emphasis will be placed on 
1. What characterizes the performance of a computer 
2. Instruction set design and its interaction with compiler 
3. Basic building blocks: I/O, Memory, Datapath, Control 
4. Pipelined datapath

- Website: [10002 資訊工程學系 計算機結構][cs4100]
- Video: [计算机结构 Computer Architecture][video]

## Textbook

P.A.Patterson and J.L. Hennessy, Computer Organization and Design:      
The Hardway/Software Interface, 5th Edition.

![PH](https://images-cn.ssl-images-amazon.cn/images/I/51c-Cwiob8L._SX421_BO1,204,203,200_.jpg)


## Syllabus

1. Computer abstractions and technology 
2. The role of performance
3. Instructions:language of the machine
4. Arithmetic for computers
5. The processor: datapath and control
6. Enhancing performance with pipelining
7. Large and fast: exploiting memory hierarchy
8. Interfacing processors and peripherals

## Notes

### Computer Abstractions and Technology

#### 1.6 Performance 

ISA影响Clock Rate，这是因为ISA所提供的指令会影响Clock Rate。
例如，单周期处理器，提供单周期乘法指令和不提供单周期乘法指令的处理器，它们的Clock Rate是极有可能不同的。

### Memory

#### 5.3 The Basics of Caches

write through 只需要1个时钟周期，是因为不管 tag 是否命中，重写 cache 的数据不会影响 memory 的数据 (正确数据已被写入memory)。如果下一周期发现 tag 命中，不用作任何处理，如果 tag 未命中，则阻塞并搬运 cache 中此块的其他数据进来 (一般写一个 word，而一个 block 通常不止一个 word，所以需要搬其他的 word 进来并修改 tag)。

write back 不能像 write through 一样无需判断 tag 命中就重写数据，因为被覆盖的数据可能是唯一 (cache 与 memory 的数据不一致)。需要先判断 tag 命中再写入数据，所以需要 2 个时钟周期。

## References

- 國立陽明交通大學 李毅郎教授   [計算機組織 Computer Organization – 100學年度][nycu-co]
- 國立臺灣科技大學 劉一宇副教授 [Computer Organization](https://www.youtube.com/playlist?list=PLu7X08EhejdrFth-Y-or8vL2GW0GEnvDM)
- [資工所考試 資源連結](https://fjuedu-my.sharepoint.com/:f:/g/personal/406401484_m365_fju_edu_tw/EnpviC9MYHVMjzJFgZAKeQMByJBWpgwRFXpN3_56bn2B-A?e=S7OkMH)

[cs4100]: https://ocw.nthu.edu.tw/ocw/index.php?page=course&cid=76&
[video]: https://www.bilibili.com/video/BV1r4411s7Hj
[nycu-co]: https://ocw.nycu.edu.tw/?course_page=all-course%2Fcollege-of-computer-science%2F%E8%A8%88%E7%AE%97%E6%A9%9F%E7%B5%84%E7%B9%94-computer-organization-100%E5%AD%B8%E5%B9%B4%E5%BA%A6-%E8%B3%87%E8%A8%8A%E5%B7%A5%E7%A8%8B%E5%AD%B8%E7%B3%BB-%E6%9D%8E%E6%AF%85%E9%83%8E%E8%80%81
