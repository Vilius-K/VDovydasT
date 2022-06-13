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

Ejimas = "-"

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

Pestininko_pervertimas = False

# Front Page of the Flask Web Page
@app.route("/")
def main():

    global count, board

    if Pestininko_pervertimas == True:
        #board = chess.Board()
        board = chess.Board(FEN_eilute)

    ret = render_template('sablonas.html')
    ret += render_template('lenta.html')

    fen = board.fen()
    from pprint import pprint

    Lenta = fen_to_board(fen)
    pprint( fen_to_board(fen) )

    if (Lenta[1][0] == 'wp' and Lenta[0][0] == '--' and Ejimas = 'a7a8'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][0] == 'wp' and Ejimas = 'a7a8'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][1] == 'wp' and Lenta[0][1] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][2] == 'wp' and Lenta[0][2] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][3] == 'wp' and Lenta[0][3] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][4] == 'wp' and Lenta[0][4] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][5] == 'wp' and Lenta[0][5] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][6] == 'wp' and Lenta[0][6] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
    elif (Lenta[1][7] == 'wp' and Lenta[0][7] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")

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

def fen_to_board(fen):
    board = []
    for row in fen.split('/'):
        brow = []
        for c in row:
            if c == ' ':
                break
            elif c in '12345678':
                brow.extend( ['--'] * int(c) )
            elif c == 'p':
                brow.append( 'bp' )
            elif c == 'P':
                brow.append( 'wp' )
            elif c > 'Z':
                brow.append( 'b'+c.upper() )
            else:
                brow.append( 'w'+c )

        board.append( brow )
    return board


def Fen_eilutes_generavimas(Lenta):

    tusciu_langeliu_sk = 0
    for i in Lenta:
        for j in i:
            if Lenta[i][j] == '--':
                tusciu_langeliu_sk += 1
            if j != 7 and Lenta[i][j] == '--' and Lenta[i][j+1] != '--':
                tusciu_langeliu_sk_char = '0' + tusciu_langeliu_sk
                if i == 0:
                    Galima_FEN_eilute = tusciu_langeliu_sk_char
                elif i != 0:
                    Galima_FEN_eilute += tusciu_langeliu_sk_char
                tusciu_langeliu_sk = 0
            if j == 7 and Lenta[i][j] == '--':
                tusciu_langeliu_sk_char = '0' + tusciu_langeliu_sk
                Galima_FEN_eilute += tusciu_langeliu_sk_char
                tusciu_langeliu_sk = 0
            if Lenta[i][j] == 'bp':
                if i == 0:
                    Galima_FEN_eilute = 'p'
                elif i != 0:
                    Galima_FEN_eilute += 'p'
            if Lenta[i][j] == 'wp':
                if i == 0:
                    Galima_FEN_eilute = 'P'
                elif i != 0:
                    Galima_FEN_eilute += 'P'
            if Lenta[i][j] == 'bR':
                if i == 0:
                    Galima_FEN_eilute = 'r'
                elif i != 0:
                    Galima_FEN_eilute += 'r'
            if Lenta[i][j] == 'wR':
                if i == 0:
                    Galima_FEN_eilute = 'R'
                elif i != 0:
                    Galima_FEN_eilute += 'R'
            if Lenta[i][j] == 'bN':
                if i == 0:
                    Galima_FEN_eilute = 'n'
                elif i != 0:
                    Galima_FEN_eilute += 'n'
            if Lenta[i][j] == 'wN':
                if i == 0:
                    Galima_FEN_eilute = 'N'
                elif i != 0:
                    Galima_FEN_eilute += 'N'
            if Lenta[i][j] == 'bB':
                if i == 0:
                    Galima_FEN_eilute = 'b'
                elif i != 0:
                    Galima_FEN_eilute += 'b'
            if Lenta[i][j] == 'wB':
                if i == 0:
                    Galima_FEN_eilute = 'B'
                elif i != 0:
                    Galima_FEN_eilute += 'B'
            if Lenta[i][j] == 'bQ':
                if i == 0:
                    Galima_FEN_eilute = 'q'
                elif i != 0:
                    Galima_FEN_eilute += 'q'
            if Lenta[i][j] == 'wQ':
                if i == 0:
                    Galima_FEN_eilute = 'Q'
                elif i != 0:
                    Galima_FEN_eilute += 'Q'
            if Lenta[i][j] == 'bK':
                if i == 0:
                    Galima_FEN_eilute = 'k'
                elif i != 0:
                    Galima_FEN_eilute += 'k'
            if Lenta[i][j] == 'wK':
                if i == 0:
                    Galima_FEN_eilute = 'K'
                elif i != 0:
                    Galima_FEN_eilute += 'K'
        if i != 7:
            Galima_FEN_eilute += '/'

    return Galima_FEN_eilute


@app.route("/test" , methods=['GET', 'POST'])
def test():
    select = request.form.get('comp_select')
    print (select)

    if (Lenta[1][0] == 'wp' and Lenta[0][0] == '--'):
        Lenta[1][0] == '--'
        Lenta[0][0] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        Pestininko_pervertimas(True)
        #board = chess.Board(FEN_eilute)
    elif (Lenta[1][1] == 'wp' and Lenta[0][1] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
        Lenta[1][1] == '--'
        Lenta[0][1] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        #board = chess.Board(FEN_eilute)
    elif (Lenta[1][2] == 'wp' and Lenta[0][2] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
        Lenta[1][2] == '--'
        Lenta[0][2] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        #board = chess.Board(FEN_eilute)
    elif (Lenta[1][3] == 'wp' and Lenta[0][3] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
        Lenta[1][3] == '--'
        Lenta[0][3] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        #board = chess.Board(FEN_eilute)
    elif (Lenta[1][4] == 'wp' and Lenta[0][4] == '--'):
        print("AAAA")
        Lenta[1][4] == '--'
        Lenta[0][4] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        #board = chess.Board(FEN_eilute)
    elif (Lenta[1][5] == 'wp' and Lenta[0][5] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
        Lenta[1][5] == '--'
        Lenta[0][5] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        #board = chess.Board(FEN_eilute)
    elif (Lenta[1][6] == 'wp' and Lenta[0][6] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
        Lenta[1][6] == '--'
        Lenta[0][6] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        #board = chess.Board(FEN_eilute)
    elif (Lenta[1][7] == 'wp' and Lenta[0][7] == '--'):
        print("AAAA")
        ret += render_template("PASIRINKIMAS.html")
        Lenta[1][7] == '--'
        Lenta[0][7] == 'wQ'
        FEN_eilute = Fen_eilutes_generavimas(Lenta)
        print(FEN_eilute)
        #board = chess.Board(FEN_eilute)

    return main()

# Human Move
@app.route("/move/", methods=['GET', 'POST'])
def move():

    try:
        move = request.args.get('move', default="")
        Ejimas = move
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
