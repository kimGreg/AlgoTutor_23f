#!/bin/python3

from multiprocessing import Pool
import os
import subprocess
import argparse

class Testcase:
  def run_test(self, tc_number):
    input_path = os.path.join(self.inputs_path, tc_number)

    test = subprocess.run(f"{self.run_cmd} < {input_path}", shell=True, stdout=subprocess.PIPE, timeout=self.timeout)
    result = test.stdout.decode("utf-8").strip()
    return result
  
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
    self.timeout = args.timeout
    self.inputs_path = os.path.join(self.tc_path, "in")
    self.outputs_path = os.path.join(self.tc_path, "out")
    self.tc_num = self.get_file_cnt(self.inputs_path)


  def work(self, tc_name):
    answer = self.get_content(os.path.join(self.outputs_path, tc_name))
    result = self.run_test(tc_name)
    if result == answer:
      return 1
    return 0

  def run_testcase(self):
    pool=Pool()
    result = [] # async result

    for i in range(1, self.tc_num+1):
      result.append(pool.apply_async(self.work, args=(str(i),)))
    
    suc = 0
    for res in result:
      suc += res.get()
    
    pool.close()
    pool.join()
 
    print(f"{suc}/{self.tc_num}")

parser = argparse.ArgumentParser('test case')
parser.add_argument('--path', dest='tc_path', help='testcase base directory', type=str)
parser.add_argument('--cmd', dest='cmd', help='rum command', type=str)
parser.add_argument('--timeout', dest='timeout', help='timeout', type=int, default=2)
args = parser.parse_args()

if __name__ == "__main__":
  tc = Testcase(args)
  tc.run_testcase()