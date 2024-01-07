CREATE TABLE user (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT UNIQUE,
    password TEXT,
    role TEXT
);