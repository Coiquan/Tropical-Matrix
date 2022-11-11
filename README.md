# 11.11更新
今天把之前的上传历史读了一遍, 发现最精彩的部分完全没有写啊, 10.5之后的几天几乎是重构了代码.  
今天把昨天提到的bug改掉了, 下次要记得统一用从0开始的下标来标.
给一些麻烦的地方加了断言, 以后如果出了问题就会直接停止了.
不过似乎某种程度上也没用, 因为昨天这个越界断言也解决不了.
解释一下, 这次更新在doc里增加了四个文件, 其中用*隔开了在不同的同态下可能不一样的和一定一样的.  
下面的工作是理论性质的, 只需要证明可能不一样的会被一定一样的"覆盖"掉就可以了.

# 11.10更新
上~~好几~~次更新没有写干了啥啊.   
由于摸鱼的时间太长我也不记得上~~好几~~次写了啥了. 看提交记录的话, 十月六号写了一个新的生成器(?), 把整个main分成了不同的函数放在了头文件里, 为了避免命名撞车用了命名空间, 是这样吧, 大概.   
这两天把verify改了改, 之前的旧verify写的就是一个小规模屎山, 虽然我也没有上传.   
这个verify是用来把两个字在任意同态下经过运算之后得到的热带矩阵中的四个位置的热带多项式中一定相等的项和可能不相等的项分开的, 不知道为啥, 这个程序目前没办法处理第二行第二列的热带多项式, 一跑就bad_alloc, 我打断点试了试, 是在输出到文件的时候抛的异常, 很怪, 我怀疑是之前是从0开始数的数, 这次从1开始数所以越界了.   
明天排查一下bug出在哪. 

# 10.5更新  
把昨天晚上加的毫无必要的int数组去掉了, 现在数组会以构造函数的参数的形式传入.   
为了多线程, 尝试把main分割成不同函数, 还没有完成.   
加入了随机数生成函数. 

# 10.4更新  
今天吃饭的时候突然想到一个问题, 这个程序似乎默认研究的对象是全序集了.   
因为在输出的时候, 是按照排序之后vector里的前后两个对象的abcd是不是完全一致来输出的.   
但是程序里定义的序关系只排了a, 后面的bcd没排, 所以在输出的时候很有可能落下一些.   
所以修改了排序规则, 在这个定义下就没问题了.   
发现问题总归是个好消息. 但之前的数据全都作废了挺可惜的.   
下一步想这么改：  
想把程序改成从n=2开始, 对每一个n分别筛选. 因为目前一次循环只能处理一个文件, 所以文件一多筛选效率会大打折扣, 出结果很慢.   
还有就是要把验证的过程实现完全自动化. 关于这一点我想让程序自己产生8个随机数, 然后把随机数存在一个文件里, 用这8个随机数来定义字到矩阵的同态, 然后一次次循环下去. 为了实现这个目标, 这个版本给terms类加了个私有int数组, 或许这里用指针会更好？main.cpp还没做相应的改动.    
最后, 目前的效率真的很慢, 要不下一个版本用俩线程, 边输出边读, 应该可以提高不少效率. 

 # 热带半环上矩阵半群的性质的研究

初版的代码丢了.   
事情是这样的, 因为几个数据的压缩包比较大, 比如output5二百多m, 但GitHub只支持100m内文件上传, 所以我想用Git Large File Stroage（下面简称为lfs）来把数据传上去, 但是大概是因为网络问题, 数据传不上去. 但是, 虽然lfs的服务器没收到我的文件, 但是它记住了我的操作. 在我把这几个数据包传上去之前其他的东西它一概不让我传. 于是程序的上传就在这卡住了. 我尝试在本地卸载lfs然后以正常方式上传没超过100m的文件, 然而lfs服务器也不让. 这时我想出了个馊招, 我想我重建一个git库lfs服务器是不是就认不出我来了. 俗话说不破不立, 要建新库就要删旧库...  
然后一通操作之后, 我就这么成功把我写的代码搞丢了.    
好在我用lfs前的版本是有备份的, 但是main.cpp,  generator.cpp我改动的部分是找不回来了.     
故事到这还没完.   
lfs认的应该是我在github上的库, 因为我重新建的库还能被lfs服务器认出来. 我尝试删上传记录, 又试了不少办法, 但是不管我怎么试, 执着的lfs服务器总是能一眼把我认出来. 最后我决定把github上的库删了.     
这次终于是成功了. 我感觉自己好像一个驱魔的老道士, 一个费了九牛二虎之力终于把顽固的诅咒赶走的老道士.   
后面就是战后重建工作了. 我凭记忆重新把main.cpp写了一遍, 测试了一下应该是没问题.   
generator.cpp还没改, 不过这个版本已经可以生成和output0里的内容一致的文件了, 虽然名字不一样. 从这个老版本的generter可以看出来一开始的我是准备按照n和a来分类的, 这种分类法不太好进行后面的进一步筛选, 于是改成了后面的纯数字.   
但是比较麻烦的是, 我后面改过include里的几个头文件, 而且我不记得我是怎么改的.   
所以尽管docs里面的几个压缩包里的数据都是真实的（我在压缩output3456的时候忘记把程序生成.exe文件删掉了, 运行那个.exe文件可以得到一样的数据）, 但是因为不记得反例, 这些数据都没用了.    
还是把前面的内容重新跑一遍吧.   
至于大文件, 我就不上传了. 反正解压出来成千上万个文件也没啥可读性. 我只把筛选用的头文件, 也就是同态的规则上传. 把最开始生成的文件作为示例上传. 最后把经过足够多次筛选、已经比较小的文件传上来. 没在最后的文件里的字就是对所有其他的字在上面给出的某几条同态的规则中总有至少一条, 使两个字在同态下不相等, 所以这个字是孤立项. 也还挺严谨的. 