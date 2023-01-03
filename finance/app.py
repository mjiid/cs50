import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "GET":
        symbol = db.execute("SELECT symbol FROM purchases WHERE id = ?", session["user_id"])
        shares = db.execute("SELECT shares FROM purchases WHERE id = ?", session["user_id"])[0]['shares']
        price = lookup(symbol[0]['symbol'])['price']
        holding = shares * price
        cash = db.execute("SELECT cash FROM users where id = ?", session["user_id"])
        cash = cash[0]['cash']
        total = cash + holding
        return render_template("index.html")

    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    elif request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if lookup(symbol) == None:
            return apology("There is some problem with your symbol!")
        if shares < 0:
            return apology("The number of shares cannot be negative")

        price = lookup(symbol)['price']
        cash = db.execute("SELECT cash FROM users where id = ?", session["user_id"] )

        if shares*price > cash[0]['cash']:
            return apology("Sorry You can't afford this number of shares")
        owned_sym = db.execute("SELECT symbol FROM purchases WHERE id = ?", session["user_id"])
        owned = False
        for sym in owned_sym:
            if sym['symbol'] == symbol:
                owned = True
        if owned:
            old = db.execute("SELECT shares FROM purchases WHERE symbol = ?", symbol)[0]['shares']
            db.execute("UPDATE purchases SET shares = ? WHERE symbol = ? and id = ?", old + shares, symbol, session['user_id'])
        else:
            db.execute("INSERT INTO purchases (id, symbol, price, shares) VALUES (?, ?, ?, ?)", session["user_id"], symbol, price, shares)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", (cash[0]['cash'] - shares * price), session["user_id"])
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    elif request.method == "POST":
        symbol = request.form.get("symbol")
        if lookup(symbol) != None:
            return render_template("quoted.html", symbol = symbol, lookup = lookup )
    return apology("The symbol you entered doesn't exist")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        name = request.form.get("username")
        usedName = False
        for el in db.execute("SELECT username FROM users;"):
            if el['username'] == name:
                usedName = True
        if len(name)==0 or usedName == True:
            return apology("Try out another username!")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if len(password) == 0 or len(confirmation) == 0 or password != confirmation:
            return apology("There is some problem with your password!")
        password = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", name, password)
        return redirect("/")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
