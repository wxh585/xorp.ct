#!/usr/bin/env python

import getopt, re, sys, time

# main links in the header
xorp_main = [
# --
#    ("XORP Project", ""),
    ("Home<span class='separator'>&nbsp;|&nbsp;</span>", "index.html"),
    ("About", "about.html"),
#    ("About XORP<span class='separator'>&nbsp;|&nbsp;</span>", "about.html"),
#    ("Roadmap<span class='separator'>&nbsp;|&nbsp;</span>", "roadmap.html"),
#    ("News", "news.html"),
    ]

# nav bar tree
xorp_links = [
# --
    ("Get XORP", ""),
    ("Download Live CD", "livecd.html"),
    ("Download Code", "downloads.html"),
    ("Browse Code", "http://cvsweb.xorp.org/cgi-bin/cvsweb.cgi/xorp/"),
    ("Mirror Sites", "mirrors.html"),
    ("Security Advisories", "advisories.html"),

# --
    ("Documentation", ""),
    ("Getting Started", "getting_started.html"),
    ("User Manual (PDF)", "releases/current/docs/user_manual/user_manual.pdf"),
#    ("Frequently Asked Questions", "faq.html"),
#    ("Architecture", "architecture.html"),
    ("Design Documentation", "design_docs.html"),
    ("API Documentation", "releases/current/docs/kdoc/html/index.html"),
    ("Porting Guide", "porting.html"),
    ("Publications", "papers.html"),
# --
    ("Community", ""),
    ("Mailing Lists", "mailing_lists.html"),
#    ("Contributing", "contributing.html"),
#    ("Developers", "people.html"),
    ("Source Repository", "cvs.html"),
    ("Bug Reporting", "http://bugzilla.xorp.org/bugzilla/index.cgi"),
    ("Operating a mirror", "mirror_operation.html"),
    ("News", "news.html"),
    ]

def usage():
    print "www.xorp.org-gen.py -d <directory> <source_html>file>"
    sys.exit(0)

def write_navbar(filename):
    open_div("navbar")
    write_navbar_depth(filename, 1, xorp_links)
    close_div("navbar")

def listify(links, type="ul"):
    if len(links) == 0:
        return
    links.insert(0, "<%s>" % type)
    links.append('</%s>' % type)
    for l in links:
        print l
    links = []

def write_navbar_depth(filename, depth, links):
    lx = []
    for l in links:
        desc, url = l
        if filename == url:
            style = ' id="selected"'
        else:
            style = ''

        if len(url) == 0:
            listify(lx, 'dl')
            lx = [ "<dt>%s</dt>" % desc ]
        else:
            lx.append("<dd %s><a href=\"%s\">%s</a></dd>" % (style, url, desc))
    listify(lx, 'dl')

def open_div(name):
    print "<div id=\"%s\">" % name

def close_div(name):
    print "</div> <!-- end of div id=\"%s\" -->" % name

def write_main_begin():
    open_div("main");

def write_main_end():
#    print "<hr noshade>"
#    open_div("feedback")
#    print "<p><em>Document id $XORP: www/scripts/XorpOrgGenerator.py,v 1.18 2008/07/23 03:44:40 atanu Exp $."
#    print "<br>Generated on %s.</em>" \
#          % time.strftime('%d/%b/%Y at %H:%M:%S')
#    print "<em>Feedback, comments, flames to feedback&#64;xorp&#46;org</em>"
#    close_div("feedback")
    close_div("main")
    
def write_search_form():
    open_div("search")
    print """<form action="http://www.google.com/cse" id="cse-search-box">
        <input type="hidden" name="cx" value="017869558586786398708:zlic-3ntnvg" />
        <input type="hidden" name="ie" value="UTF-8" />
        <input type="text" name="q" size="20" />
        <input type="submit" name="sa" value="Search" />
      </form>"""
    close_div("search")

def write_footer():
    open_div("footer")
    print """&copy; 2008 XORP, Inc. All Rights Reserved"""
    close_div("footer")

def write_header(filename, headextras = []):
    print """<!-- $XORP: www/scripts/XorpOrgGenerator.py,v 1.18 2008/07/23 03:44:40 atanu Exp $ -->
    <!-- DO NOT EDIT THIS FILE . IT IS GENERATED BY A SCRIPT -->

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
    "http://www.w3.org/TR/html4/loose.dtd">
<html>

<head>
<meta content="text/html; charset=iso-8859-1" http-equiv="Content-Type"/>
<link rel="stylesheet" type="text/css" href="xorp.css"/>
"""
    for item in headextras:
        print item
    print"""</head>

<body>
"""
    open_div("container")

    open_div("left")
    print """<a href="http://xorp.org"><img src="images/mad/logo-xorp_org.gif" ALT="XORP Logo" border="0"/></a>"""
    close_div("left")
    open_div("header")
    write_navbar_depth(filename, 1, xorp_main)
    print """<div id="net"><span class="selected">.ORG</span>&nbsp;&nbsp;|&nbsp;&nbsp;<a href="http://xorp.net">.NET</a></div>"""
    write_search_form()
    print """<div id="open">eXtensible Open Router Platform</div>"""
    close_div("header")

def write_close():

    close_div("container")
    print"""
</body>
</html>"""

if __name__ == '__main__':
    srcdir = "."

    try:
        opts, args = getopt.getopt(sys.argv[1:], "d:")
    except getopt.GetoptError:
        usage()

    if len(args) == 0:
        usage()

    for o in opts:
        if o[0] == '-d':
            srcdir = o[1].rstrip('/')

    title_matcher = re.compile(r'<[Hh]1>(.*)</[hH]1>')

    for filename in args:
        src_filename = "%s/%s" % (srcdir, filename)
        dst_filename = filename

        # If this is index.html then it has its own div markup.
        if filename == 'index.html':
            write_main = False
        else:
            write_main = True

        lines = []
        header_extras = []
        input = open(src_filename, 'r')
        for line in input:
            lines.append(line)
            m = title_matcher.match(line)
            if m:
                header_extras.append("<title>%s</title>" % m.group(1))
        input.close()

        saveout = sys.stdout
        out = open(dst_filename, 'w')

        sys.stdout = out
        write_header(dst_filename, header_extras)
        write_navbar(dst_filename)
        if write_main:
            write_main_begin()
        for line in lines:
            print line,
        if write_main:
            write_main_end()
        write_footer()
        write_close()

        out.close()
        sys.stdout = saveout
