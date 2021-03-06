#pragma once

#include <string>

#include "base/util/logging.h"
#include "tile/lang/type.h"
#include "tile/math/polynomial.h"

namespace vertexai {
namespace tile {
namespace lang {

class BoundFunction;
class FunctionApplication;
class Value;

class SymbolicPolynomial {
 public:
  static SymbolicPolynomialPtr MakeLiteral(int64_t value);
  static SymbolicPolynomialPtr MakeSymbol(const std::string& sym);
  static SymbolicPolynomialPtr MakeIndex(const std::string& idx);
  static SymbolicPolynomialPtr MakeUnaryOp(const std::string& op, const SymbolicPolynomialPtr& val);
  static SymbolicPolynomialPtr MakeBinaryOp(const std::string& op, const SymbolicPolynomialPtr& lhs,
                                            const SymbolicPolynomialPtr& rhs);

  virtual ~SymbolicPolynomial() {}
  virtual SymbolicPolynomialPtr Xify() const = 0;
  virtual SymbolicPolynomialPtr DeXify() const = 0;
  virtual SymbolicPolynomialPtr Compose(const FunctionApplication& fa) const = 0;
  virtual SymbolicPolynomialPtr Decompose(BoundFunction* bf) const = 0;
  virtual math::Polynomial<math::Rational> Evaluate(const Bindings& bindings) const = 0;
  virtual std::string ToString() const = 0;
  virtual std::shared_ptr<Value> value() const = 0;
  virtual SymbolicSpec subspec() const = 0;
};

class ValuePolynomial;
class LookupPolynomial;

}  // namespace lang
}  // namespace tile
}  // namespace vertexai
