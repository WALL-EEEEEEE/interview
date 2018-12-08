#
# Singleton
#
# decorator model 
#

def singleton(cls):
    instances = {}
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
