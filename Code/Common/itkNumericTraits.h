/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkNumericTraits.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#ifndef __itkNumericTraits_h
#define __itkNumericTraits_h

#include "itkMacro.h"
#undef min
#undef max

#if (defined(_MSC_VER))  || (defined(__sgi) && !defined(__GNUC__))
#include <limits>
#define ITK_NUMERIC_LIMITS std::numeric_limits
#else
#include "vnl/vnl_numeric_limits.h"
#define ITK_NUMERIC_LIMITS vnl_numeric_limits
#endif

namespace itk
{

/** \class NumericTraits
 * \brief Define additional traits for native types such as int or float.
 *
 * NumericTraits is used to extend the traits associated with native types
 * such as float, char, int, and so on. These traits are extensions of the
 * standard <numeric_limits> defined by the C++ compilers. Some of the added
 * traits include minimum and maximum value; accumulation type; etc.  
 */
template <class T>
class NumericTraits : public ITK_NUMERIC_LIMITS<T> {
public:
  /** Return the type of this native type. */
  typedef T ValueType; 

  /** Return value of abs(). */
  typedef T AbsType; 

  /** Accumulation of addition and multiplication. */
  typedef double AccumulateType; 

  /** Additive identity. */
  static const T Zero;

  /** Multiplicative identity. */
  static const T One;

  /** Smallest (most nonpositive) value **/
  static T NonpositiveMin() { return min(); }

  /** Is a given value positive? **/
  static bool IsPositive(T val) { return val > Zero; }

  /** Is a given value nonpositive? **/
  static bool IsNonpositive(T val) { return val <= Zero; }

  /** Is a given value negative? **/
  static bool IsNegative(T val) { return val < Zero; }

  /** Is a given value nonnegative? **/
  static bool IsNonnegative(T val) { return val >= Zero; }
};

/** \class NumericTraits<bool>
 * \brief Define traits for type bool.
 */
template <>
class NumericTraits<bool> : public ITK_NUMERIC_LIMITS<bool> {
public:
  typedef bool ValueType;
  typedef unsigned char AbsType;
  typedef unsigned char AccumulateType;
  static const bool Zero;
  static const bool One;

  static bool NonpositiveMin() { return false; }
  static bool IsPositive(bool val) { return val; }
  static bool IsNonpositive(bool val) { return !val; }
  static bool IsNegative(bool val) { return false; }
  static bool IsNonnegative(bool val) {return true; }
};

/** \class NumericTraits<char>
 * \brief Define traits for type char.
 */
template <>
class NumericTraits<char> : public ITK_NUMERIC_LIMITS<char> {
public:
  typedef char ValueType;
  typedef unsigned char AbsType;
  typedef short AccumulateType;
  static const char Zero;
  static const char One;

  static char NonpositiveMin() { return min(); }
  static bool IsPositive(char val) { return val > Zero; }
  static bool IsNonpositive(char val) { return val <= Zero; }
  static bool IsNegative(char val) { return val < Zero; }
  static bool IsNonnegative(char val) {return val >= Zero; }
};

/** \class NumericTraits<unsigned char>
 * \brief Define traits for type unsigned char.
 */
template <>
class NumericTraits<unsigned char> : public ITK_NUMERIC_LIMITS<unsigned char> {
public:
  typedef unsigned char ValueType;
  typedef unsigned char AbsType;
  typedef unsigned short AccumulateType;
  static const unsigned char Zero;
  static const unsigned char One;

  static unsigned char NonpositiveMin() { return min(); }
  static bool IsPositive(unsigned char val) { return val != Zero; }
  static bool IsNonpositive(unsigned char val) { return val == Zero; }
  static bool IsNegative(unsigned char val) { return false; }
  static bool IsNonnegative(unsigned char val) {return true; }
};

/** \class NumericTraits<short>
 * \brief Define traits for type short.
 */
template <>
class NumericTraits<short> : public ITK_NUMERIC_LIMITS<short> {
public:
  typedef short ValueType;
  typedef unsigned short AbsType;
  typedef int AccumulateType;
  static const short Zero;
  static const short One;

  static short NonpositiveMin() { return min(); }
  static bool IsPositive(short val) { return val > Zero; }
  static bool IsNonpositive(short val) { return val <= Zero; }
  static bool IsNegative(short val) { return val < Zero; }
  static bool IsNonnegative(short val) {return val >= Zero; }
};

/** \class NumericTraits<unsigned short>
 * \brief Define traits for type unsigned short.
 */
template <>
class NumericTraits<unsigned short> : public ITK_NUMERIC_LIMITS<unsigned short> {
public:
  typedef unsigned short ValueType;
  typedef unsigned short AbsType;
  typedef unsigned int AccumulateType;
  static const unsigned short Zero;
  static const unsigned short One;

  static unsigned short NonpositiveMin() { return min(); }
  static unsigned short IsPositive(unsigned short val) { return val != Zero; }
  static bool IsNonpositive(unsigned short val) { return val == Zero; }
  static bool IsNegative(unsigned short val) { return false; }
  static bool IsNonnegative(unsigned short val) {return true; }
};

/** \class NumericTraits<int>
 * \brief Define traits for type int.
 */
template <>
class NumericTraits<int> : public ITK_NUMERIC_LIMITS<int> {
public:
  typedef int ValueType;
  typedef unsigned int AbsType;
  typedef long AccumulateType;
  static const int Zero;
  static const int One;

  static int NonpositiveMin() { return min(); }
  static bool IsPositive(int val) { return val > Zero; }
  static bool IsNonpositive(int val) { return val <= Zero; }
  static bool IsNegative(int val) { return val < Zero; }
  static bool IsNonnegative(int val) {return val >= Zero; }
};

/** \class NumericTraits<unsigned int>
 * \brief Define traits for type unsigned int.
 */
template <>
class NumericTraits<unsigned int> : public ITK_NUMERIC_LIMITS<unsigned int> {
public:
  typedef unsigned int ValueType;
  typedef unsigned int AbsType;
  typedef unsigned int AccumulateType;
  static const unsigned int Zero;
  static const unsigned int One;

  static unsigned int NonpositiveMin() { return min(); }
  static bool IsPositive(unsigned int val) { return val != Zero; }
  static bool IsNonpositive(unsigned int val) { return  val == Zero; }
  static bool IsNegative(unsigned int val) { return false; }
  static bool IsNonnegative(unsigned int val) {return true; }
};

/** \class NumericTraits<long>
 * \brief Define traits for type long.
 */
template <>
class NumericTraits<long> : public ITK_NUMERIC_LIMITS<long> {
public:
  typedef long ValueType;
  typedef unsigned long AbsType;
  typedef long AccumulateType;
  static const long Zero;
  static const long One;

  static long NonpositiveMin() { return min(); }
  static bool IsPositive(long val) { return val > Zero; }
  static bool IsNonpositive(long val) { return val <= Zero; }
  static bool IsNegative(long val) { return val < Zero; }
  static bool IsNonnegative(long val) {return val >= Zero; }
};

/** \class NumericTraits<unsigned long>
 * \brief Define traits for type unsigned long.
 */
template <>
class NumericTraits<unsigned long> : public ITK_NUMERIC_LIMITS<unsigned long> {
public:
  typedef unsigned long ValueType;
  typedef unsigned long AbsType;
  typedef unsigned long AccumulateType;
  static const unsigned long Zero;
  static const unsigned long One;

  static unsigned long NonpositiveMin() { return min(); }
  static bool IsPositive(unsigned long val) { return val != Zero; }
  static bool IsNonpositive(unsigned long val) { return val == Zero; }
  static bool IsNegative(unsigned long val) { return false; }
  static bool IsNonnegative(unsigned long val) {return true; }
};

/** \class NumericTraits<float>
 * \brief Define traits for type float.
 */
template <>
class NumericTraits<float> : public ITK_NUMERIC_LIMITS<float> {
public:
  typedef float ValueType;
  typedef float AbsType;
  typedef double AccumulateType;
  static const float Zero;
  static const float One;

  static float NonpositiveMin() { return -max(); }
  static bool IsPositive(float val) { return val > Zero; }
  static bool IsNonpositive(float val) { return val <= Zero; }
  static bool IsNegative(float val) { return val < Zero; }
  static bool IsNonnegative(float val) {return val >= Zero; }
};

/** \class NumericTraits<double>
 * \brief Define traits for type double.
 */
template <>
class NumericTraits<double> : public ITK_NUMERIC_LIMITS<double> {
public:
  typedef double ValueType;
  typedef double AbsType;
  typedef double AccumulateType;
  static const double Zero;
  static const double One;

  static double NonpositiveMin() { return -max(); }
  static bool IsPositive(double val) { return val > Zero; }
  static bool IsNonpositive(double val) { return val <= Zero; }
  static bool IsNegative(double val) { return val < Zero; }
  static bool IsNonnegative(double val) {return val >= Zero; }
};

/** \class NumericTraits<long double>
 * \brief Define traits for type long double.
 */
template <>
class NumericTraits<long double> : public ITK_NUMERIC_LIMITS<long double> {
public:
  typedef long double ValueType;
  typedef long double AbsType;
  typedef long double AccumulateType;
  static const long double Zero;
  static const long double One;

  static long double NonpositiveMin() { return -max(); }
  static bool IsPositive(long double val) { return val > Zero; }
  static bool IsNonpositive(long double val) { return val <= Zero; }
  static bool IsNegative(long double val) { return val < Zero; }
  static bool IsNonnegative(long double val) {return val >= Zero; }
};

} // end namespace itk

#endif // __itkNumericTraits_h
