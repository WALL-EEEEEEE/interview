class logit(object):
    _logfile = 'out.log'

    def __init__(self,func):
        self.func = func
    def __call__(self,*args):
        log_string = self.func.__name__ + " was called"
        print(log_string)
        # Open the logfile and append
        with open(self._logfile,'a') as opened_file:
            opened_file.write(log_string + '\n')
        self.notify()
        return self.func(*args)
    def notify(self):
        pass

class email_logit(logit):
    """ 
    A logit implementation for sending emails to admins
    when the function is called
    """
    def __init__(self,email="admin@myproject.com",*args,**kwargs):
        self.email = email
        super(email_logit,self).__init__(*args,**kwargs)
    def notify(self):
        # Send an email to self.email
        # Will not be implemented here

logit._logfile = 'out2.log'
@logit
def myfunc1():
    pass
myfunc1()
