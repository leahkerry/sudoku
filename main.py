from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel 
import build.sudoku as sudoku

from enum import Enum

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],  # You can restrict this to specific domains
    allow_methods=["*"],
    allow_headers=["*"],
)


class Item(BaseModel):
    text: str = None
    is_done: bool = False
items = []
hard_boards = []
med_boards = []
easy_boards = []

@app.get("/")
def root():
    return {"Hello": "World"}

@app.post("/boards/hard")
def create_hard_board():
    hard_boards.append(sudoku.generate_board(3, sudoku.difficulty.HARD))
    return hard_boards

@app.post("/boards/med")
def create_med_board():
    med_boards.append(sudoku.generate_board(3, sudoku.difficulty.HARD))
    return med_boards

@app.post("/boards/easy")
def create_easy_board():
    easy_boards.append(sudoku.generate_board(3, sudoku.difficulty.HARD))
    return easy_boards




# @app.get("/items/{item_id}", response_model=Item)
# def get_item(item_id: int) -> Item:
#     if item_id < len(items):
#         return items[item_id]
#     else: 
#         raise HTTPException(status_code=404, detail=f"Item {item_id} not found")

# @app.get("/boards", response_model=list[str])
# def get_boards():
#     return boards

@app.get("/boards", response_model=list[str])
def get_hard_boards():
    return hard_boards

@app.get("/boards", response_model=list[str])
def get_med_boards():
    return med_boards

@app.get("/boards", response_model=list[str])
def get_easy_boards():
    return easy_boards

