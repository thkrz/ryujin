import json  # alt. ijson
from pathlib import Path

database = Path("./db/sensor.json")
builtin = {
    "%": {"sensor": "PCB", "label": "Station health"},
}


def insert(o):
    if database.exists():
        with database.open() as f:
            j = json.load(f)
    else:
        j = []
    j.append(o)
    with database.open("w") as f:
        json.dump(j, f)


def catalogue():
    with database.open() as f:
        return json.load(f)
