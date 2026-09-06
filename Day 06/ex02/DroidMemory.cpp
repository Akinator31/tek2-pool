/*
** EPITECH PROJECT, 2026
** DroidMemory
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"
#include <cstddef>
#include <ostream>

size_t DroidMemory::getFingerprint(void) const
{
    return this->_fingerprint;
}

size_t DroidMemory::getExp(void) const
{
    return this->_exp;
}

void DroidMemory::setFingerprint(const size_t new_fingerprint)
{
    this->_fingerprint = new_fingerprint;
}

void DroidMemory::setExp(const size_t new_exp)
{
    this->_exp = new_exp;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &mem)
{
    this->_exp += mem.getExp();
    this->_fingerprint = (mem._fingerprint ^ this->_fingerprint);

    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &mem) const
{
    mem._exp += this->getExp();
    mem._fingerprint = (this->_fingerprint ^ mem._fingerprint);

    return mem;
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &mem)
{
    return *this << mem;
}

DroidMemory &DroidMemory::operator+=(const size_t exp)
{
    this->_exp += exp;
    this->_fingerprint ^= exp;

    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &droid) const
{
    DroidMemory new_mem(*this);
    new_mem += droid;
    return new_mem;
}

DroidMemory DroidMemory::operator+(size_t exp) const
{
    DroidMemory new_mem(*this);
    new_mem += exp;
    return new_mem;
}

std::ostream &operator<<(std::ostream &stream, const DroidMemory &mem)
{
    return stream << "DroidMemory '" << mem.getFingerprint() << "', " << mem.getExp();
}

bool DroidMemory::operator==(const DroidMemory &mem) const
{
    return ((this->_exp == mem._exp) && (this->_fingerprint == mem._fingerprint));
}

bool DroidMemory::operator!=(const DroidMemory &mem) const
{
    return ((this->_exp != mem._exp) || (this->_fingerprint != mem._fingerprint));
}

bool DroidMemory::operator<(const DroidMemory &mem) const
{
    return this->_exp < mem._exp;
}

bool DroidMemory::operator>(const DroidMemory &mem) const
{
    return this->_exp > mem._exp;
}

bool DroidMemory::operator<=(const DroidMemory &mem) const
{
    return this->_exp <= mem._exp;
}

bool DroidMemory::operator>=(const DroidMemory &mem) const
{
    return this->_exp >= mem._exp;
}

bool DroidMemory::operator==(const size_t &exp) const
{
    return this->_exp == exp;
}

bool DroidMemory::operator!=(const size_t &exp) const
{
    return this->_exp != exp;
}

bool DroidMemory::operator<(const size_t &exp) const
{
    return this->_exp < exp;
}

bool DroidMemory::operator>(const size_t &exp) const
{
    return this->_exp > exp;
}

bool DroidMemory::operator<=(const size_t &exp) const
{
    return this->_exp <= exp;
}

bool DroidMemory::operator>=(const size_t &exp) const
{
    return this->_exp >= exp;
}
