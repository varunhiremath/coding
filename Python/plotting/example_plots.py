#!/usr/bin/python

# Author: Varun Hiremath <vh63@cornell.edu>

import scipy, pylab
import plot_settings as ps
from scipy.special import jn

x = scipy.arange(0,10,0.2)

# small size image
ps.setSmallSize()
pylab.figure(1)
for i in range(5):
    y = jn(i,x)
    pylab.plot(x, y, ps.line_symbols[i], label="$J_{%d}(x)$" % i)

pylab.legend(numpoints=1)
pylab.xlabel("$x$")
pylab.ylabel("J(x)")
pylab.title("Bessel Functions")
pylab.savefig("bessel_small.eps")
pylab.savefig("bessel_small.png")

# medium size image
ps.setMediumSize()
pylab.figure(2)
for i in range(5):
    y = jn(i,x)
    pylab.plot(x, y, ps.line_symbols[i], label="$J_{%d}(x)$" % i)

pylab.legend(numpoints=1)
pylab.xlabel("$x$")
pylab.ylabel("J(x)")
pylab.title("Bessel Functions")
pylab.savefig("bessel_medium.eps")
pylab.savefig("bessel_medium.png")

# large size image
ps.setLargeSize()
pylab.figure(3)
for i in range(5):
    y = jn(i,x)
    pylab.plot(x, y, ps.line_symbols[i], label="$J_{%d}(x)$" % i)

pylab.legend(numpoints=1)
pylab.xlabel("$x$")
pylab.ylabel("J(x)")
pylab.title("Bessel Functions")
pylab.savefig("bessel_large.eps")
pylab.savefig("bessel_large.png")
