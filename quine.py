#!/usr/bin/python
import sys

def escape (s):
  inputs = {"\a": "\\a",
            "\b": "\\b",
            "\f": "\\f",
            "\n": "\\n",
            "\r": "\\r",
            "\t": "\\t",
            "\v": "\\v",
            "\\": "\\\\",
            "\"": "\\\"",
            "\'": "\\\'"}
  return ''.join([inputs.setdefault(c,c) for c in s])

s = sys.stdin.read()
sys.stdout.write (s % escape(s))
