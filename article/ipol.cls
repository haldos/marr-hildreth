%-------------------------------------------------------------------------------
% ipol.cls
% LaTeX class for IPOL articles
%
% rafael grompone von gioi - 2011.12.22
%-------------------------------------------------------------------------------
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{ipol}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions
\LoadClass[a4paper,12pt]{article}
\RequirePackage[myheadings,cm]{fullpage}
\newcommand{\ipolMaketitle}{\maketitle\thispagestyle{myheadings}}
\newenvironment{ipolAbstract}{\renewcommand{\abstractname}{Abstract}%
                               \begin{abstract}%
                               \noindent}{\end{abstract}}
\newenvironment{ipolCode}{\renewcommand{\abstractname}{Source Code}%
                           \begin{abstract}%
                           \noindent}{\end{abstract}}
\newenvironment{ipolSupp}{\renewcommand{\abstractname}{Supplementary Material}%
                           \begin{abstract}%
                           \noindent}{\end{abstract}}
\newcommand{\ipolYear}{XXXX}
\newcommand{\ipolDOI}{xx.xxxx/ipol.xxxx.xxxxx}
\newcommand{\ipolSetYear}[1]{\renewcommand{\ipolYear}{#1}}
\newcommand{\ipolSetDOI}[1]{\renewcommand{\ipolDOI}{#1}}
\AtBeginDocument{\markboth{}%
{\small\copyright\ \ipolYear\ Image Processing On Line doi:\ipolDOI}}
%-------------------------------------------------------------------------------
