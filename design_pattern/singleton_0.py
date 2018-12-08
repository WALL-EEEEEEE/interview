#
# Singleton 
#
# Implemented by __new__ feature 
#
#

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

