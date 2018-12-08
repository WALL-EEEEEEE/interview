from functools import wraps

def requires_auth(f):
    @wraps(f)
    def decorated(*args,**kwargs):
        auth = request.authorization
        if not auth or not check_auth(auth.username,auth.password):
            autheticate()
        return f(*args,**kwargs)
    return decorated


