### 动态环境  吾爱破解winxp虚拟机 

​	Process Explorer监视程序 有一瞬间能看到拉起了一个叫做svchost的进程  svchost这是系统进程 在`Windows\\system32`目录下

![image.png](https://i.loli.net/2021/11/03/7VeIYKoyTsmZjFa.png)

这个东西还是有点意思的

首先静态IDA看看 简单分析一下

![image.png](https://i.loli.net/2021/11/03/eGwupDQz9NaxUZo.png)

进4010EA看看

![](https://i.loli.net/2021/11/03/74pOrQzTmiyB8MW.png)

大概就是先自己拉起系统文件svchost.exe 然后抹掉内容换成自己解密出来的资源文件  按照分别拷贝文件头和每一个节进入，这样自己的恶意代码权限就比较高，不容易被杀掉，最后稍微清理了一下痕迹

直接用Resource Hacker把资源文件LOCALIZATION dump下来 写脚本解密一下继续IDA静态分析

```python
with open('./source.bin','rb+') as f:
    with open('./source_dec.bin','wb+') as ff:
        s = list(f.read())
        for i in range(len(s)):
            s[i] = s[i] ^ 65
        ff.write(bytes(s))
```



![image.png](https://i.loli.net/2021/11/03/vhOAx9m7cu28MUG.png)

大概就是使用SetWindowsHookExA来监听键盘按钮事件 具体的使用方法可以看仓库里面的idb文件

![image.png](https://i.loli.net/2021/11/03/DjmT7FCnrXpK3Ua.png)

这里获取当前输出窗口的信息  然后做记录到当前文件目录的`practicalmalwareanalysis.log`文件中



总结以下这个写的挺丑的，要是多拉起几个监听就会出现复写的情况
