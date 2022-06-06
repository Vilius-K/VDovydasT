# Remaining imports
import traceback
import chess
from flask import Flask, render_template, Response, request
import webbrowser
import time
import chess.svg
import ctypes
import numpy
import glob
from ctypes import *

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
    ret = render_template('lenta.html')
    
    # Sacho ir mato nustatymas
    if board.is_stalemate():
        ret += render_template('lygiosios(stalemate).html')
    elif board.is_checkmate():
        ret += render_template('sahasirmatas.html')
    elif board.is_insufficient_material():
        ret += render_template('insufficient_material.html')
    elif board.is_check():
        ret += render_template('sachas.html')
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

    ### Randamas optimaliausias priesininko ejimas
    FEN_eilute = board.fen()

    sourceFile = open('duota.txt', 'w')
    sourceFile.truncate(0)
    print(FEN_eilute, file = sourceFile)
    sourceFile.close()

    libfile = glob.glob('build/*/variklis*.so')[0]
    variklis = ctypes.CDLL(libfile)
    variklis.Ejimo_generavimas()

    sourceFile = open('rezultatai.txt', 'r')
    AI_ejimas = sourceFile.readline()
    sourceFile.close()
    sourceFile = open('rezultatai.txt', 'w')
    sourceFile.truncate(0)
    sourceFile.close()

    print(AI_ejimas)


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
