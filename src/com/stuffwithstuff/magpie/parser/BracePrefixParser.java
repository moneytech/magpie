package com.stuffwithstuff.magpie.parser;

import java.util.ArrayList;
import java.util.List;

import com.stuffwithstuff.magpie.ast.Expr;

public class BracePrefixParser implements PrefixParser {
  @Override
  public Expr parse(MagpieParser parser, Token token) {
    parser.pushQuote();
    
    PositionSpan span = parser.span();
    
    // Ignore a line after {
    parser.match(TokenType.LINE);
    
    // Parse a sequence of expressions.
    List<Expr> exprs = new ArrayList<Expr>();
    while (true) {
      exprs.add(parser.parseStatement());
      
      // Stop when we hit the closing }.
      if (parser.match(TokenType.RIGHT_BRACE)) break;
      if (parser.match(TokenType.LINE, TokenType.RIGHT_BRACE)) break;
      
      // Each expression is separated by a line.
      parser.consume(TokenType.LINE);
    }
    
    parser.popQuote();
    
    if (exprs.size() == 1) {
      return Expr.quote(span.end(), exprs.get(0));
    } else {
      return Expr.quote(span.end(), Expr.sequence(exprs));
    }
  }
}
