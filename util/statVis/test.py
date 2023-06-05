import matplotlib.pyplot as plt

categories = ['Category 1', 'Category 2', 'Category 3']
values = [30, 40, 20]

plt.bar(range(len(categories)), values)
plt.xticks(range(len(categories)), categories)
plt.xlabel('Categories')
plt.ylabel('Values')
plt.title('Bar Chart')

plt.show()