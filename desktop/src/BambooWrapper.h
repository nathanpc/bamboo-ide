/**
 * BambooWrapper.h
 * A C++ wrapper for the Bamboo Lisp interpreter C library.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#if !defined(AFX_BAMBOOLISP_H__758F6A83_C64F_4861_B2E8_9BBFFAB7465B__INCLUDED_)
#define AFX_BAMBOOLISP_H__758F6A83_C64F_4861_B2E8_9BBFFAB7465B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <exception>
#include "../../lib/lisp/src/bamboo.h"

/**
 * Bamboo exception abstraction to handle errors.
 */
class BambooException : public exception {
protected:
	bamboo_error_t err;

public:
	BambooException(bamboo_error_t err);
	virtual const char* what() const throw();

	bamboo_error_t ErrorCode();
};

/**
 * Bamboo wrapper class.
 */
class Bamboo {
protected:
	env_t env;

public:
	Bamboo();
	virtual ~Bamboo();
};

#endif // !defined(AFX_BAMBOOLISP_H__758F6A83_C64F_4861_B2E8_9BBFFAB7465B__INCLUDED_)
