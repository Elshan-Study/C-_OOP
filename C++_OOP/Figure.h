#pragma once
#include <iostream>

class Figure
{
protected:
    bool _is_Black;
    char _col;
    int _row;
    std::string _skin;
public:
    Figure();
    explicit Figure(char c, int r, bool is_black);
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;

    virtual ~Figure();
    virtual void move(char c, int r) = 0;
    void SetSkin(std::string skin);
    std::string GetSkin() const;
    char GetCol() const;
    int GetRow() const;
};

class Pawn : public Figure
{
public:
    Pawn();
    Pawn(char c, int r, bool is_black);

    Pawn(const Pawn& other);
    Pawn(Pawn&& other) noexcept;
    void move(char c, int r) override;
};

class Knight : public Figure
{
public:
    Knight();
    Knight(char c, int r, bool is_black);
    Knight(const Knight& other);
    Knight(Knight&& other) noexcept;
    void move(char c, int r) override;
};

class Bishop : public Figure
{
public:
    Bishop();
    Bishop(char c, int r, bool is_black);
    Bishop(const Bishop& other);
    Bishop(Bishop&& other) noexcept;

    void move(char c, int r) override;
};

class Rook : public Figure
{
public:
    Rook();
    Rook(char c, int r, bool is_black);
    Rook(const Rook& other);
    Rook(Rook&& other) noexcept;
    void move(char c, int r) override;
};

class Queen : public Figure
{
public:
    Queen();
    Queen(char c, int r, bool is_black);
    Queen(const Queen& other);
    Queen(Queen&& other) noexcept;
    void move(char c, int r) override;
   
};

class King : public Figure
{
public:
    King();
    King(char c, int r, bool is_black);
    King(const King& other);
    King(King&& other) noexcept;
    void move(char c, int r) override;
};


