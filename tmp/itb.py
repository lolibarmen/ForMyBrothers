from PIL import Image
import os
import struct

# Путь к исходному изображению
source_image_path = './lisa.jpg'

# Путь к сохраненному черно-белому изображению в формате txt
text_file_path = 'image.txt'

# Открытие исходного изображения
image = Image.open(source_image_path)

# Изменение размера изображения до 100x100 пикселей
resized_image = image.resize((100, 100))

# Преобразование изображения в черно-белое
grayscale_image = resized_image.convert('L')

# Создание списка, содержащего только пиксели 0 (черные) и 255 (белые)
pixels = [int(pixel) for pixel in grayscale_image.getdata()]

# Бинарная строка под запись
outbstr = b''
for i, pixel in enumerate(pixels):
    print(i, pixel)
    outbstr += struct.pack('i', pixel)

# Запись пикселей в текстовый файл
with open(text_file_path, 'wb') as file:
   file.write(outbstr)

print("Черно-белое изображение успешно сохранено в:", text_file_path)
