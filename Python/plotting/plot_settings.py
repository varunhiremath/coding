#!/usr/bin/python

# Module: plot_settings.py
# Author: Varun Hiremath <vh63@cornell.edu>
# License: GPL-3+

import pylab, math

# Symbols
symbols = ['-','--','-.',':','.',',','o','^','v','<','>','s','+','x','D','d','1','2','3','4','h','H','p']

# Symbols + line
line_symbols = [k+'-' for k in ['o','^','v','<','>','s','+','x','D','d','1','2','3','4','h','H','p']]

# Colors
colors= ['b','g','r','c','m','y','k','w']

def get_figsize(fig_width_pt):
    inches_per_pt = 1.0/72.0                # Convert pt to inch
    golden_mean = (math.sqrt(5)-1.0)/2.0    # Aesthetic ratio
    fig_width = fig_width_pt*inches_per_pt  # width in inches
    fig_height = fig_width*golden_mean      # height in inches
    fig_size =  [fig_width,fig_height]      # exact figsize
    return fig_size

# check the below link for all available settings:
# https://matplotlib.org/tutorials/introductory/customizing.html

# small sized image
psmall = {'backend': 'ps',
          'axes.labelsize': 10,
          'xtick.labelsize': 10,
          'ytick.labelsize': 10,
          'legend.borderpad': 0.15,
          'legend.fontsize': 8,
          'lines.markersize': 3,
          'font.size': 10,
          'text.usetex': True,
          'figure.autolayout': True,
          'figure.figsize': get_figsize(300)}

# medium sized images
pmedium = {'backend': 'ps',
          'axes.labelsize': 15,
          'xtick.labelsize': 15,
          'ytick.labelsize': 15,
          'legend.borderpad': 0.15,
          'legend.fontsize': 15,
          'lines.markersize': 5,
          'font.size': 15,
          'text.usetex': True,
          'figure.autolayout': True,
          'figure.figsize': get_figsize(500)}

# large sized images (default)
plarge = {'backend': 'ps',
          'axes.labelsize': 20,
          'xtick.labelsize': 20,
          'ytick.labelsize': 20,
          'legend.borderpad': 0.2,
          'legend.fontsize': 20,
          'lines.markersize': 8,
          'font.size': 20,
          'text.usetex': True,
          'figure.autolayout': True,
          'figure.figsize': get_figsize(900)}

def setSmallSize():
    pylab.rcParams.update(psmall)

def setMediumSize():
    pylab.rcParams.update(pmedium)

def setLargeSize():
    pylab.rcParams.update(plarge)

def setFigSize(fig_width_pt):
    pylab.rcParams['figure.figsize'] = get_figsize(fig_width_pt)

pylab.rcParams.update(plarge)
