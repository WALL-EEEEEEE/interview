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
