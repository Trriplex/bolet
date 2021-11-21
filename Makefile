build:
	sbcl --load "bolet.lisp" --eval "(sb-ext:save-lisp-and-die \"bolet\" :toplevel #'main :executable t)"
