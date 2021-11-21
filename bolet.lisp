(defparameter *stack* (list))
(defparameter *continue* t)

(declaim (inline start-with-quote-p))
(defun start-with-quote-p (str)
  (eq #\" (char str 0)))

(declaim (inline start-with-space-p))
(defun start-with-space-p (str)
  (eq #\Space (char str 0)))

(defun exe (op)
  "Execute op"
  (case (intern op)
	(||)
	(|exit| (setf *continue* nil))
   	(+ (push (+ (pop *stack*) (pop *stack*)) *stack*))
   	(- (push (- (pop *stack*) (pop *stack*)) *stack*))
   	(* (push (* (pop *stack*) (pop *stack*)) *stack*))
   	(/ (push (/ (pop *stack*) (pop *stack*)) *stack*))
   	(% (push (mod (pop *stack*) (pop *stack*)) *stack*))
   	(|.| (format t "~a~%" (pop *stack*)))
   	(|.s| (format t "[~{~a; ~}]~%" *stack*))
	(|print| (format t "~a~%" (car *stack*)))
	(|swp| (let ((a (pop *stack*)) (b (pop *stack*))) (push a *stack*) (push b *stack*)))
	(|dup| (push (car *stack*) *stack*))
	(|drp| (pop *stack*))
	(|nip| (let ((a (pop *stack*))) (pop *stack*) (push a *stack*)))
	(|over| (push (cadr *stack*) *stack*))
   	(otherwise (format t "[Error] ~a is not a valid operator.~%" op))))

(defun parse (atom &optional bolet-string-p)
  "Parse atom"
  (if bolet-string-p
      (push atom *stack*)
      (if (ignore-errors (parse-integer atom))
	  (push (parse-integer atom) *stack*)
	  (exe atom))))

(defun beval (str)
  "Eval str as bolet code"
  (let ((splitted-str (uiop:split-string str :separator '(#\"))))
    (loop for part in splitted-str
	  for i from 0 to (length splitted-str)
	  do (if (evenp i)
		 (dolist (atom (uiop:split-string part)) (parse atom))
		 (parse part t)))))

(defun main ()
  "The bolet REPL"
  (loop while *continue* do (beval (read-line))))
