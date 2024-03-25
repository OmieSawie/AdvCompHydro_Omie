# Import libraries
from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt
import csv

# with open('Output.csv', newline='\n') as f:
#     reader = csv.reader(f)
#     data = list(reader,delimeter)
#     Z = np.array(data, dtype=np.double)
# Creating dataset
# x = np.outer(np.linspace(-3, 3, 32), np.ones(32))
x = np.outer(np.linspace(0, 300, 31), np.ones(11))
y = np.outer(np.linspace(0, 100, 11), np.ones(31))
x=x.T

X,Y = np.meshgrid(x,y)

Z = np.array([
[69.8, 27.416, 16.7878, 11.578, 8.17195, 5.60622, 3.63526, 2.21027, 1.27048, 0.702196, 0.379414, 0.202666, 0.107719, 0.0572663, 0.0307382, 0.0171233, 0.0107223, 0.00884508, 0.0107033, 0.0170859, 0.0307016, 0.0573507, 0.108482, 0.206445, 0.395556 ,0.767396 ,1.52759 ,3.21991 ,7.86367 ,34.5158 ,68.6],
[69.8,27.416, 16.7878, 11.578, 8.17195, 5.60622 ,3.63526, 2.21027, 1.27048, 0.702196, 0.379414, 0.202666, 0.107719, 0.0572663 ,0.0307382 ,0.0171233, 0.0107223, 0.00884508, 0.0107033, 0.0170859, 0.0307016, 0.0573507, 0.108482, 0.206445, 0.395556 ,0.767396, 1.52759, 3.21991 ,7.86367, 34.5158, 68.6],
[69.6, 40.0639, 27.0874, 19.2244, 13.4633, 8.96154, 5.5795, 3.2616, 1.82034, 0.988448, 0.529208, 0.281459, 0.149416, 0.0796491, 0.0433036, 0.0251897, 0.0176994, 0.017681, 0.0251323, 0.0432114, 0.0795949, 0.149808, 0.284121, 0.541657, 1.04057, 2.02902, 4.08135, 8.79829, 22.6564, 46.4067 ,68.2],
[69.4, 46.6518, 33.3321, 23.8158 ,16.2594 ,10.3452 ,6.12724 ,3.43839, 1.87028, 1.0019 ,0.532848 ,0.282601 ,0.150079, 0.0805134, 0.0448397, 0.0280737, 0.0231567 ,0.028019, 0.044721 ,0.0803373, 0.14999, 0.283409, 0.538149, 1.02648, 1.97284 ,3.84825, 7.72965, 16.3799, 31.8662, 50.6449, 67.8],
[69.2, 50.256, 36.7604, 25.815, 16.7978, 10.0421, 5.62578 ,3.04583, 1.62651, 0.863443 ,0.457282, 0.242248, 0.129002, 0.0700996 ,0.0407662, 0.0286399, 0.0286068, 0.0406564, 0.0698843, 0.128659, 0.241899, 0.457806, 0.869011, 1.65468, 3.16707, 6.11556, 11.9234, 22.1416, 36.2602, 51.7126, 67.4],
[69, 52.0403 ,37.8533, 25.3316, 15.255, 8.44086, 4.49665, 2.37801, 1.25584, 0.663183, 0.350497 ,0.185815, 0.0995999, 0.0554456, 0.0347061, 0.0286232, 0.0346284 ,0.0552574, 0.0992216, 0.185087, 0.349112, 0.660556, 1.25086, 2.36856, 4.47864, 8.40569, 15.1783 ,25.1419 ,37.3878 ,51.0176, 67],
[68.8, 52.3447, 36.493 ,22.2207, 11.9593 ,6.1363, 3.17869, 1.66101, 0.8724, 0.459608, 0.242852, 0.129158, 0.0701402, 0.0407766 ,0.0286419 ,0.0286047, 0.0406459, 0.0698432 ,0.1285, 0.241289, 0.455455, 0.859952, 1.61979, 3.0327, 5.59924 ,9.98455, 16.6638, 25.502 ,36.0764, 48.8815 ,66.6],
[68.6, 50.8851, 31.9022, 16.3939 ,7.74743, 3.86027, 1.97984, 1.03035, 0.540232 ,0.284518, 0.150576, 0.0806426 ,0.0448731, 0.0280819 ,0.0231567 ,0.0280108, 0.0446872, 0.0802067, 0.149487, 0.28147 ,0.53068 ,0.997713, 1.86203, 3.42157, 6.09105, 10.2631, 16.0719 ,23.4063, 32.4941 ,45.0143, 66.2],
[68.4, 46.3028, 22.5922, 8.80344, 4.09068, 2.03538 ,1.04427, 0.5437, 0.285221, 0.150393, 0.0799027 ,0.0433694 ,0.0252065, 0.0177027, 0.0176776, 0.0251153, 0.0431449, 0.0793384, 0.14882, 0.280316, 0.527, 0.984107, 1.81153, 3.24283, 5.53759, 8.86662, 13.2551, 18.7917, 26.2267, 38.3488, 65.8],
[68.2, 34.2237 ,7.8489 ,3.22353, 1.53152, 0.769914, 0.396993, 0.20723, 0.108903, 0.0575739, 0.030818, 0.0171439, 0.0107273, 0.00884506, 0.0106982, 0.017065, 0.0306208, 0.0570396, 0.107284, 0.201829, 0.377777, 0.698908, 1.26359, 2.1951, 3.60105, 5.53042, 8.01168, 11.2546, 16.1439, 26.0372, 65.4],
[68.2, 34.2237, 7.8489, 3.22353, 1.53152, 0.769914, 0.396993, 0.20723, 0.108903, 0.0575739, 0.030818, 0.0171439, 0.0107273, 0.00884506, 0.0106982, 0.017065 ,0.0306208, 0.0570396, 0.107284, 0.201829, 0.377777, 0.698908, 1.26359, 2.1951, 3.60105, 5.53042 ,8.01168, 11.2546, 16.1439, 26.0372 ,65.4]
])
# z = np.linspace(0, 100, 11)
# z = np.array([])
print(Z) 
# Creating figure
fig = plt.figure(figsize =(14, 9))
ax = plt.axes(projection ='3d')
 
# Creating plot
ax.plot_surface(x, y, Z)
 
# show plot
plt.show()