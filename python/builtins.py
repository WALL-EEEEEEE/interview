import builtins # pylint3: disable-msg

def open(path): # Bad Idea... pylint3: disable=redefined-builtin
    """Rewrite builtins open"""
    f = builtins.open(path, 'r') 
    return UpperCaser(f)


class UpperCaser:
    '''Wrapper around a file that converts output  to upper-case.'''
    def __init__(self, f):
        self._f = f
    def read(self, count=-1):
        """decorate for read"""
        return self._f.read(count).upper()

upper = open('out2.log').read()
print(upper)
