# Remaining imports
# Testas
import traceback
import chess
from flask import Flask, Response, request
import webbrowser
import time
import chess.svg
# Searching Ai's Move
def aimove():
    move = selectmove(3)
    board.push(move)
# Searching Stockfish's Move
def stockfish():
    engine = chess.engine.SimpleEngine.popen_uci(
        "your_path/stockfish.exe")
    move = engine.play(board, chess.engine.Limit(time=0.1))
    board.push(move.move)
app = Flask(__name__)
# Front Page of the Flask Web Page
@app.route("/")
def main():
    global count, board
    ret = '<html><head>'
    ret += '<style>input {font-size: 20px; } button { font-size: 20px; }</style>'
    ret += '</head><body>'
    ret += '<img width=510 height=510 src="/board.svg?%f"></img></br></br>' % time.time()
    ret += '<form action="/game/" method="post"><button name="New Game" type="submit">Pradėti iš naujo</button></form>'
    ret += '<form action="/undo/" method="post"><button name="Undo" type="submit">Sugrįžti ėjimu atgal</button></form>'
    ret += '<form action="/move/"><input type="submit" value="Atlikti ėjimą:"><input name="move" type="text"></input></form>'
    ret += '<form action="/dev/" method="post"><button name="Comp Move" type="submit">Priešininko ėjimas</button></form>'
    return ret
# Display Board
@app.route("/board.svg/")
def board():
    return Response(chess.svg.board(board=board, size=700), mimetype='image/svg+xml')
# Human Move
@app.route("/move/")
def move():
    try:
        move = request.args.get('move', default="")
        board.push_san(move)
    except Exception:
        traceback.print_exc()
    return main()
# Make Ai’s Move
@app.route("/dev/", methods=['POST'])
def dev():
    try:
        aimove()
    except Exception:
        traceback.print_exc()
    return main()
# Make UCI Compatible engine's move
@app.route("/engine/", methods=['POST'])
def engine():
    try:
        stockfish()
    except Exception:
        traceback.print_exc()
    return main()
# New Game
@app.route("/game/", methods=['POST'])
def game():
    board.reset()
    return main()
# Undo
@app.route("/undo/", methods=['POST'])
def undo():
    try:
        board.pop()
    except Exception:
        traceback.print_exc()
    return main()



board = chess.Board()
webbrowser.open("http://127.0.0.1:5000/")
app.run()
