
Packages generated by critcl have the following basic structure:

[example {
<TOP>
+- pkgIndex.tcl
+- critcl-rt.tcl
+- license.terms (optional)
|
+- tcl (optional)
|  +- <tsources files>
|
+- <platform>
   +- <shared library>
}]

[para][emph Notes]
[list_begin enumerated]

[enum] The file [file pkgIndex.tcl] is the standard package index file
expected by Tcl's package management. It is sourced during a search
for packages, and declares the package to Tcl with its files, and how
to handle them.

[enum] The file [file critcl-rt.tcl] is a helper file containing the
common code used by [file pkgIndex.tcl] to perform its tasks.

[enum] The file [file license.terms] is optional and appears only if
the [file .critcl] file the package is generated from used the command
[cmd critcl::license] to declare package author and license.

[enum] All files declared with the command [cmd critcl::tsources] are
put into the sub-directory [file tcl].

[enum] The shared library generated by critcl is put into a
platform-specific sub-directory.

[list_end]

[para] The whole structure, and especially the last point, enable us
to later merge the results (for the same package, and version) for
multiple target platforms into a single directory structure without
conflict, by simply copying the top directories over each other. The
only files which can conflict are in the <TOP> and [file tcl]
directories, and for these we know that they are identical across
targets. The result of such a merge would look like:

[example {
<TOP>
+- pkgIndex.tcl
+- critcl-rt.tcl
+- license.terms (optional)
|
+- tcl (optional)
|  +- <tsources files>
|
+- <platform1>
|  +- <shared library1>
+- <platform2>
|  +- <shared library2>
...
+- <platformN>
   +- <shared libraryN>
}]
