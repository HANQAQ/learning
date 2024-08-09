import sys
import os

# 添加 MinGW64 到 DLL 搜索路径
os.add_dll_directory(os.environ['minGwPath'])

# 获取当前文件所在目录的路径
#current_dir = os.path.dirname(__file__)

# 获取构建目录的绝对路径
#build_dir = os.path.abspath(os.path.join(current_dir, "../../build"))

# 添加构建目录到 sys.path
#sys.path.append(build_dir)

# 打印 sys.path 检查路径是否正确
#print("sys.path:", sys.path)

# 导入生成的 pybind 模块
from build import pybindDemo

# 测试模块功能
print(pybindDemo.add(1, 2))
