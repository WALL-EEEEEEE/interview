# 面试中常用的设计模式

### 单例模式

#### python实现
&ensp;&ensp;&ensp;&ensp; `python` 实现单例模式有很多种方法。

1. 利用 `__new__` 实现
```python
class singleton():

    def __new__(cls,*args,**kwargs):
        if not hasattr(cls,'_instance'):
            parent = super(singleton,cls)
            cls._instance = parent.__new__(cls,*args,**kwargs)
        return cls._instance

class myClass(singleton):
    name = 'myClass'
    pass

myClass1 = myClass()
myClass1.name = 'myClass1'
myClass2 = myClass()
myClass2.name = 'myClass2'
print("myClass1's name: " + myClass1.name)
print("myClass2's name: " + myClass2.name)
```
