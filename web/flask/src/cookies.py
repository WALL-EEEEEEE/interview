from flask import request

@app.route('/')
def index():
    username = request.cookies.get('username')
    # use cookies.get(key) instead of cookies[key] to not get a
    # KeyError if the cookie is missing.
@app.route('/2')
def index2():
    resp = make_response(render_template(...))
    resp.set_cookie('username','the username')
    return resp

