#!/bin/python3

from multiprocessing import Pool
import os
import subprocess, psutil
import argparse
import time


class Testcase:
  def run_test(self, tc_number):
    input_path = os.path.join(self.inputs_path, tc_number)
    
    timeStarted = time.time()   

    # parent=subprocess.Popen(f"{self.run_cmd} {self.run_arg} < {input_path}", shell=False, stdout=subprocess.PIPE)
    # for _ in range(self.timeout*10): # sleep for 0.1 second
    #     if parent.poll() is not None:  # process just ended
    #       break
    #     time.sleep(0.1)
    # else:
    #   # the for loop ended without break: timeout
    #   parent = psutil.Process(parent.pid)
    #   for child in parent.children(recursive=True):  # or parent.children() for recursive=False
    #       child.kill()
    #   parent.kill()
    
    # (res, err) = parent.communicate()
    
    try:
      input = open(input_path, 'rb')
      content = input.read()
      test = subprocess.run([self.run_cmd, self.run_arg], input=content , shell=False, stdout=subprocess.PIPE, timeout=self.timeout)
    except subprocess.TimeoutExpired:
      return "", self.timeout

    result = test.stdout.decode("utf-8").strip()

    timeDelta = time.time()-timeStarted

    return result, timeDelta
  
  @staticmethod
  def get_content(file_path):
     contents = open(file_path).read()
     return contents.strip()
  
  @staticmethod
  def get_file_cnt(dir_path):
    res = 0
    for path in os.listdir(dir_path):
      if (os.path.isfile(os.path.join(dir_path, path))):
        res += 1
    return res

  def __init__(self, args):
    self.tc_path = args.tc_path
    self.run_cmd = args.cmd
    self.run_arg = args.cmd_arg
    self.timeout = args.timeout
    self.inputs_path = os.path.join(self.tc_path, "in")
    self.outputs_path = os.path.join(self.tc_path, "out")
    self.tc_num = self.get_file_cnt(self.inputs_path)


  def work(self, tc_name):
    answer = self.get_content(os.path.join(self.outputs_path, tc_name))
    result, time = self.run_test(tc_name)
    if result == answer:
      return 1, time
    return 0, time

  def run_testcase(self):
    pool=Pool()
    result = [] # async result

    for i in range(1, self.tc_num+1):
      result.append(pool.apply_async(self.work, args=(str(i),)))
    
    tot_suc = 0
    tot_time = 0
    cnt = 0
    is_timeout = False
    for res in result:
      suc, time = res.get()
      tot_suc += suc
      tot_time += time
      cnt += 1

      if(time == self.timeout):
        is_timeout = True
    
    pool.close()
    pool.join()
    
    if is_timeout:
      print(f"{tot_suc}/{cnt}, (timeout)")
    else:

      print(f"{tot_suc}/{cnt}, {int(tot_time/cnt*10000)/10} ms")

parser = argparse.ArgumentParser('test case')
parser.add_argument('--path', dest='tc_path', help='testcase base directory', type=str)
parser.add_argument('--cmd', dest='cmd', help='rum command', type=str)
parser.add_argument('--arg', dest='cmd_arg', help='rum command argument', type=str)
parser.add_argument('--timeout', dest='timeout', help='timeout', type=float, default=1)
args = parser.parse_args()

if __name__ == "__main__":
  tc = Testcase(args)
  tc.run_testcase()