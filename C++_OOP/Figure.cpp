#include "Figure.h"

Figure::Figure() : _col(' '), _row(0), _skin(" "), _is_Black(false) {}
Figure::Figure(char c, int r, bool is_black) : _col(c), _row(r), _skin(" "), _is_Black(is_black) {}
Figure::Figure(const Figure& other) : _col(other._col), _row(other._row), _skin(other._skin), _is_Black(other._is_Black) {}
Figure::Figure(Figure&& other) noexcept : _col(other._col), _row(other._row), _skin(other._skin), _is_Black(other._is_Black) {
    other._col = ' ';
    other._row = 0;
    other._skin = ' ';
}
Figure::~Figure() = default;
void Figure::SetSkin(std::string skin) { _skin = skin; }
std::string Figure::GetSkin() const { return _skin; }
char Figure::GetCol() const { return _col; }
int Figure::GetRow() const { return _row; }

Pawn::Pawn() { SetSkin("♟");}
Pawn::Pawn(char c, int r, bool is_black) : Figure(c, r, is_black)
{
    SetSkin(is_black ? "♟" : "♙");
}
Pawn::Pawn(const Pawn& other) : Figure(other) {};
Pawn::Pawn(Pawn&& other) noexcept : Figure(std::move(other)) {};
void Pawn::move(char c, int r) 
{
    if (!_is_Black && (c == _col && r == _row + 1)) {
        _col = c;
        _row = r;
    }
    else if (_is_Black && (c == _col && r == _row - 1)) {
        _col = c;
        _row = r;
    }
}

Knight::Knight() { SetSkin("♞"); }
Knight::Knight(char c, int r, bool is_black) : Figure(c, r, is_black)
{
    SetSkin(is_black ? "♞" : "♘");
}
void Knight::move(char c, int r)
{
    int dx = c - _col;
    if (dx < 0) dx = -dx;
    int dy = r - _row;
    if (dy < 0) dy = -dy;

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
        _col = c;
        _row = r;
    }
}
Knight::Knight(const Knight& other) : Figure(other) {};
Knight::Knight(Knight&& other) noexcept : Figure(std::move(other)) {};

Bishop::Bishop() { SetSkin("♝"); _is_Black = false; }
Bishop::Bishop(char c, int r, bool is_black) : Figure(c, r, is_black)
{
    SetSkin(is_black ? "♝" : "♗");
}
void Bishop::move(char c, int r)
{
    int dx = c - _col;
    if (dx < 0) dx = -dx;
    int dy = r - _row;
    if (dy < 0) dy = -dy;

    if (dx == dy) {
        _col = c;
        _row = r;
    }
}
Bishop::Bishop(const Bishop& other) : Figure(other) {};
Bishop::Bishop(Bishop&& other) noexcept : Figure(std::move(other)) {};


Rook::Rook() { SetSkin("♜"); _is_Black = false; }
Rook::Rook(char c, int r, bool is_black) : Figure(c, r, is_black)
{
    SetSkin(is_black ? "♜" : "♖");
}
void Rook::move(char c, int r)
{
    if (_col == c || _row == r) {
        _col = c;
        _row = r;
    }
}
Rook::Rook(const Rook& other) : Figure(other) {};
Rook::Rook(Rook&& other) noexcept : Figure(std::move(other)) {};


Queen::Queen() { SetSkin("♛"); _is_Black = false; }
Queen::Queen(char c, int r, bool is_black) : Figure(c, r, is_black)
{
    SetSkin(is_black ? "♛" : "♕");
}
void Queen::move(char c, int r) 
{
    int dx = c - _col;
    if (dx < 0) dx = -dx;
    int dy = r - _row;
    if (dy < 0) dy = -dy;

    if (_col == c || _row == r || dx == dy) {
        _col = c;
        _row = r;
    }
}
Queen::Queen(const Queen& other) : Figure(other) {};
Queen::Queen(Queen&& other) noexcept : Figure(std::move(other)) {};


King::King() { SetSkin("♚"); _is_Black = false; }
King::King(char c, int r, bool is_black) : Figure(c, r, is_black)
{
    SetSkin(is_black ? "♚" : "♔");
}
void King::move(char c, int r)
{
    int dx = c - _col;
    if (dx < 0) dx = -dx;
    int dy = r - _row;
    if (dy < 0) dy = -dy;

    if (dx <= 1 && dy <= 1) {
        _col = c;
        _row = r;
    }
}
King::King(const King& other) : Figure(other) {};
King::King(King&& other) noexcept : Figure(std::move(other)) {};
