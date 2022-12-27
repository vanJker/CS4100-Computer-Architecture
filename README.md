# CS4100: Computer Architecture

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
write through只需要1个时钟周期，是因为不管tag是否命中，重写cache的数据不会影响memory的数据（正确数据已被写入memory）。
如果下一周期发现tag命中，不用作任何处理，如果tag未命中，则阻塞并搬运cache中此块的其他数据进来（一般写一个word，而一个block通常不止一个word，所以需要搬其他的word进来并修改tag）。

write back不能像write through一样无需判断tag命中就重写数据，因为被覆盖的数据可能是唯一（cache与memory的数据不一致）。
需要先判断tag命中再写入数据，所以需要2个时钟周期。


[cs4100]: https://ocw.nthu.edu.tw/ocw/index.php?page=course&cid=76&
[video]: https://www.bilibili.com/video/BV1r4411s7Hj/?spm_id_from=333.1007.top_right_bar_window_custom_collection.content.click&vd_source=99b5a7ef7355e5c62fe79d489b7711ca
