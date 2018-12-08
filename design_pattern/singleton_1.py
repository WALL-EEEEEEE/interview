#
# Singleton
# Based by shared properties
#
#
#
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


 
print("myclass1's id:"+str(id(myclass1)))
print("myclass2's id:"+str(id(myclass2)))
print("myclass3's id:"+str(id(myclass3)))
    

