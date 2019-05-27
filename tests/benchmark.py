#!/usr/bin/python3

import os
import sys
import subprocess
import time
import progressbar
import argparse

PATH_SAT = '../sat/sat'
SATLIB_DIR = '../input_files/satlib'
TIME_P = '/usr/bin/time -p'

def get_rnd3sat():
    dirs = os.listdir(SATLIB_DIR)
    dirs = [dir for dir in dirs if 'RND3SAT' in dir]
    dirs.sort()
    dirs = [SATLIB_DIR + '/' + dir for dir in dirs]
    return (dirs)

def get_all_files(dir):
    files = []

    for (root, dirnames, filenames) in os.walk(dir):
        filenames = [os.path.join(root, file) for file in filenames]
        files.extend(filenames)
    
    files.sort()
    return (files)

def exec_time(file, algo):
    res = subprocess.run(PATH_SAT + ' ' + algo + ' ' + file, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    assert(res.returncode == 0)

def bench_folder(dir, algo):

    files = get_all_files(dir)
    pbar = progressbar.ProgressBar(widgets=[progressbar.Percentage(), progressbar.Bar()], maxval=len(files)).start()
    start_time = time.time()

    i = 0
    for file in files:
        exec_time(file, algo)
        pbar.update(i + 1)
        i = i + 1

    endtime = time.time()
    pbar.finish()
    tot_time = endtime - start_time
    tot_time = ("%.2f" % tot_time) + 's'
    print(os.path.basename(dir), algo, tot_time)


def main():

    parser = argparse.ArgumentParser(description='Helper to some benchmark stuff.')

    parser.add_argument('--only', type=int, default=0, help='only run on N foler')

    args = parser.parse_args()

    subdir = get_rnd3sat()

    if args.only != 0:
        st = str(args.only) + '_'
        if args.only < 10:
            st = '0' + st
        subdir = [dir for dir in subdir if st in os.path.basename(dir)]
    
    print(subdir)

    for dir in subdir:
        bench_folder(dir, 'cdcl')
        bench_folder(dir, 'dpll')

main()