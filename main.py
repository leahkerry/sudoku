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
boards = []

@app.get("/")
def root():
    return {"Hello": "World"}

@app.post("/boards")
def create_board():
    boards.append(sudoku.generate_board(3, sudoku.difficulty.HARD))
    return boards

@app.post("/items")
def create_item(item: Item):
    items.append(item)
    return items


@app.get("/items", response_model=list[Item])
def list_items(limit: int = 10):
    return items[0:limit]

@app.get("/items/{item_id}", response_model=Item)
def get_item(item_id: int) -> Item:
    if item_id < len(items):
        return items[item_id]
    else: 
        raise HTTPException(status_code=404, detail=f"Item {item_id} not found")

@app.get("/boards", response_model=list[str])
def get_boards():
    return boards

