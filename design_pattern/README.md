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

2. 利用 `元类` 实现

&ensp;&ensp;&ensp;&ensp; `python` 中 `元类(metaclass)` 可以控制类的创建过程。我们可以利用它来实现单例模式。

```python
class singleton(type):
    _instances = {}
    def __call__(cls,*args,**kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(singleton,cls).__call__(*args,**kwargs)
        return cls._instances[cls]


class MyClass(metaclass=singleton):
    pass

myclass = MyClass()
myclass1 = MyClass()
print(myclass1 == myclass)
print("myclass:"+str(id(myclass)))
print("myclass1:"+str(id(myclass1)))
```

3. 利用装饰器模式实现单例模式

&ensp;&ensp;&ensp;&ensp; 设计模式中的装饰器模式也可以动态的修改一个类或者函数的功能，所以我们也可以使用它来实现单例模式。

```python
from functools import wraps

def singleton(cls):
    instances = {}
    @wraps(cls)
    def getinstance(*args,**kw):
        if cls not in instances:
            instances[cls]= cls(*args,**kw)
        return instances[cls]
    return getinstance

@singleton
class MyClass:
    name = "MyClass"

myclass = MyClass()
myclass.name = "myclass"
myclass1 = MyClass()
myclass1.name = "myclass1"
myclass2 = MyClass()
myclass2.name = "myclass2"

print(myclass.name)
print(myclass1.name)
print(myclass2.name)
```

4. 利用共享属性的方法实现单例模式

&ensp;&ensp;&ensp;&ensp; 我们可以在创建实例时把所有的实例的 `__dict__` 指向同一个字典，这样它们具有同样的属性和方法, 但是它们只是共用相同的属性和方法，类并不是同一个类，类的地址也并不相同。

```python
class singleton(object):
    _state = {}
    def __new__(cls,*args, **kwargs):
        ob = super(singleton,cls).__new__(cls,*args,**kwargs)
        ob.__dict__ = cls._state
        return ob

class MyClass(singleton):
    name = "MyClass"

myclass = MyClass()
myclass.name = "myclass"
myclass1 = MyClass()
myclass1.name = "myclass1"
myclass2 = MyClass()
myclass2.name = "myclass2"
myclass3 = MyClass()
myclass3.name = "myclass3"

print(myclass1.name)
print(myclass2.name)
print(myclass3.name)
```
