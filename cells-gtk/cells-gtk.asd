
(in-package :common-lisp-user)

(defpackage #:cells-gtk-asd
  (:use :cl :asdf))

(in-package :cells-gtk-asd)

;;;
;;; features
;;;

;;; run gtk in its own thread (requires bordeaux-threads)
(pushnew :cells-gtk-threads *features*)

;;; drawing-area widget using cairo (requires cl-cairo2)
(pushnew :cells-gtk-cairo *features*)

;;; drawing-area widget using OpenGL (requires libgtkglext1)
(pushnew :cells-gtk-opengl *features*)

(asdf:defsystem :cells-gtk
  :name "cells-gtk"
  :depends-on (:cells
	       :utils-kt
	       :pod-utils
	       :gtk-ffi
	       :ph-maths
	       #+cells-gtk-cairo :cl-cairo2
	       #+cells-gtk-threads :bordeaux-threads
	       #+cells-gtk-opengl :cl-opengl
	       #+cells-gtk-opengl :cl-glu
	       #+cells-gtk-opengl :cl-glut)
  :serial t
  :components
  ((:file "packages")   
   (:file "conditions")
   (:file "compat")
   (:file "cells3-porting-notes" :depends-on ("packages"))
   (:file "widgets" :depends-on ("conditions"))
   (:file "layout" :depends-on ("widgets"))
   (:file "display" :depends-on ("widgets"))
   (:file "drawing-area" :depends-on ("widgets"))
   #+cells-gtk-cairo (:file "cairo-drawing-area" :depends-on ("widgets"))
   #+cells-gtk-opengl (:file "gl-drawing-area" :depends-on ("widgets"))
   (:file "buttons" :depends-on ("widgets"))
   (:file "entry" :depends-on ("widgets"))
   (:file "tree-view" :depends-on ("widgets"))
   (:file "menus" :depends-on ("widgets"))
   (:file "dialogs" :depends-on ("widgets"))
   (:file "textview" :depends-on ("widgets"))
   (:file "addon" :depends-on ("widgets"))
   (:file "gtk-app")
   ))

