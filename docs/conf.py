# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------

project = 'Mastering Embedded Linux'
copyright = '2025, Ridha Noomane'
author = 'Ridha Noomane'

# The full version, including alpha/beta/rc tags
release = '1.0.0'

# Strip problematic Unicode chars during build
suppress_warnings = ['rest.unicode']

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.viewcode',
    'sphinx.ext.autosectionlabel',
    'sphinx.ext.todo',
]
# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = "classic"

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
html_css_files   = ["cover.css"]

# -- Options for PDF output -------------------------------------------------

latex_elements = {
    'preamble': r'''
        \DeclareUnicodeCharacter{2212}{-}
        \usepackage{textcomp}  
    ''',
    'preamble': r'''
        \DeclareUnicodeCharacter{200B}{\hspace{0pt}}
    ''',
    'preamble': r'''
        \DeclareUnicodeCharacter{2003}{\hspace{1em}}
    ''',
    'preamble': r'''
        \DeclareUnicodeCharacter{200B}{\hskip0pt} % treat ZWSP as zero-width
    ''',
    "preamble": r"""
        \usepackage{xcolor}
        \usepackage{pagecolor}
    """,
    # completely replace Sphinx’s default title-page
    "maketitle": r"""
        \begin{titlepage}
        \pagecolor{blue}\color{white}        % deep blue bg + white text
        \centering
        \vspace*{5cm}

        {\Huge\bfseries Mastering\\[0.5em]Embedded Linux\par}
        \vspace{1em}
        {\large\itshape From Power-On to Production\par}
        \vspace{4cm}
        {\Large Ridha Os\par}
        \vspace{0.5cm}
        {\normalsize Version 1.0 — June 2025\par}

        \vfill
        \thispagestyle{empty}
        \clearpage
        \nopagecolor                          % restore white for remainder
        \end{titlepage}
        """
    
}