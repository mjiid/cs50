import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

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

        #Get the data of the owned stocks from the database
        username = db.execute("SELECT username FROM users WHERE id = ?", session['user_id'])[0]['username']
        symbols = db.execute("SELECT symbol FROM owned WHERE username = ?", username)
        shares = db.execute("SELECT shares FROM owned WHERE username = ?", username)
        prices = db.execute("SELECT price FROM owned WHERE username = ?", username)
        holdings = db.execute("SELECT holding FROM owned WHERE username = ?", username)
        balances = db.execute("SELECT balance FROM owned WHERE username = ?", username)
        totals = db.execute("SELECT total FROM owned WHERE username = ?", username)

        return render_template("index.html",symbols = symbols, shares = shares, prices = prices, holdings = holdings, balances = balances, totals = totals, n = len(symbols), usd = usd)


    return apology("Invalid request method")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")

    #Getting the data from the user:
    symbol = request.form.get("symbol")
    num_shares = request.form.get("shares")

    #Check if the data entered is valid :
    if symbol == '':
        return apology("You should enter a symbol")
    elif lookup(symbol) == None:
        return apology("This symbol does not exist")

    if num_shares == '':
        return apology("You should enter the number of shares")
    elif int(num_shares) < 0:
        return apology("The number of shares should be positive")

    num_shares = int(num_shares)

    #now that the input is valid, Store the user purchase in the database:
    #Get the data about the user from the database:
    price = lookup(symbol)['price']
    owned_cash = db.execute("SELECT cash FROM users WHERE id = ?", session['user_id'])[0]['cash']
    username = db.execute("SELECT username FROM users WHERE id = ?", session['user_id'])[0]['username']

    #Check if the user can afford the symbol:
    if num_shares * price > owned_cash:
        return apology("Sorry but you can't afford this deal")

    #The purchase is now valid, let's add it to the database:
    db.execute("INSERT INTO purchases (username, symbol, PRICE, date, shares) VALUES (?, ?, ?, ?, ?)", username, symbol, price, date.today(), num_shares)
    db.execute("UPDATE users SET cash = ? WHERE id = ?", owned_cash - (num_shares * price), session['user_id'])
    owned_cash = db.execute("SELECT cash FROM users WHERE id = ?", session['user_id'])[0]['cash']
    #add the data to the owned table:
    username = db.execute("SELECT username FROM users WHERE id = ?", session['user_id'])[0]['username']
    owned_symbols = db.execute("SELECT symbol FROM owned WHERE username = ?", username)
    owned = False
    for sym in owned_symbols:
        if sym['symbol'] == symbol:
            owned = True

    if owned:
        owned_cash = db.execute("SELECT cash FROM users WHERE id = ?", session['user_id'])[0]['cash']
        shares = db.execute("SELECT shares FROM owned WHERE username = ?", username)[0]['shares']
        db.execute("UPDATE owned SET shares = ?, price = ?, holding = holding + ?, balance = ?, total = ?", shares + num_shares, price, num_shares * price, owned_cash, (owned_cash + (num_shares + shares) * lookup(symbol)['price']))
    else:
        db.execute("INSERT INTO owned (username, symbol, shares, price, holding, balance, total) VALUES (?, ?, ?, ?, ?, ?, ?)", username, symbol, num_shares, price, num_shares * price, owned_cash, owned_cash + num_shares * lookup(symbol)['price'])

    #Now that everything is good, we send the user to the home page:
    return redirect("/")




@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    if request.method == "GET":

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

    #Getting the stock symbol from the user:
    symbol = request.form.get("symbol")

    #Get the data about the symbol from the API:
    symbol_data = lookup(symbol)

    #Check if the symbol is valid:
    if symbol_data == None:
        return apology("Your symbol is not valid")

    #send the user to the page where the data about the symbol is displayed:
    return render_template("quoted.html", symbol_data = symbol_data, usd = usd)




@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
    #Getting the data from the user:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

    #Checking if the username is blank or already exist:
        if username == '':
            return apology("Try entering a username")
        else:
            used_usernames = db.execute("SELECT username FROM users;")
            for name in used_usernames:
                if username == name['username']:
                    return apology("This username is already used")

    #Check if the password is blank or do not match the confirmation:
        if password == '':
            return apology("You have to enter a password")
        elif password != confirmation:
            return apology("The password and the confirmation you entered do not match")
        else:
            #hashing the password:
            password = generate_password_hash(password)

    #Adding the new user to the data base:
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, password)
        #the user now is registered and their data is in the data base.

    #Take the user to login after registration:
    return render_template("login.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    username = db.execute("SELECT username FROM users WHERE id = ?", session['user_id'])[0]['username']
    symbols = db.execute("SELECT symbol FROM owned WHERE username = ?", username)

    if request.method == "GET":
        return render_template('sell.html', symbols = symbols, n = len(symbols))

    #Check if the user input is valid :
    selected_symbol = request.form.get("symbol")
    selected_shares = request.form.get("shares")

    #if the user fails to choose a symbol:
    if selected_symbol == None :
        return apology("You should select a symbol")

    #if the user doesn't own the symbol:
    owned = False
    for sym in symbols:
        if selected_symbol == sym['symbol']:
            owned = True
    if not owned :
        return apology("You don't own this symbol!")

    #if the user enters a negative number of shares:
    if selected_shares == "" or (int(selected_shares)) <= 0:
        return apology("The number of shares should be a positive number")
    selected_shares = int(selected_shares)

    #if the user doesn't own enough shares:
    owned_shares = db.execute("SELECT shares FROM owned WHERE username = ? AND symbol = ?", username, selected_symbol)[0]['shares']
    if selected_shares > owned_shares:
        return apology("You don't own enough shares")

    #The user input is now valid, let's modify the database:
    price = lookup(selected_symbol)['price']
    db.execute("INSERT INTO sells VALUES (?, ?, ?, ?, ?)", username, selected_symbol, price, datetime.now(), selected_shares)
    db.execute("UPDATE owned SET shares = shares - ?, holding = holding - ?, balance = balance + ? WHERE username = ?", selected_shares, selected_shares * price, (owned_shares - selected_shares) * price, username)
    db.execute("UPDATE owned SET total = balance + ? WHERE username = ?", (owned_shares - selected_shares) * price, username)
    return redirect("/")




