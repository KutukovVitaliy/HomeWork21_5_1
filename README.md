Задание 1. Реализация ведомости учёта

Что нужно сделать

Вы уже создавали программу чтения и записи ведомости. Теперь её надо будет
обобщить и дополнить использованием структур.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных
средств, далее — дата выдачи в формате ДД.ММ.ГГГГ., затем — сумма выплаты
в рублях. Данные разделяются между собой пробелами. В конце каждой записи
должен быть перевод строки.
Структура данных записи должна соответствовать указанному формату.
При старте программы пользователь указывает команду, которую следует
осуществить: list или add. Команда read осуществляет чтение из файла
ведомости как и прежде, только уже в структуры данных и отображает их на
экране.
Команда add добавляет новую запись в конец ведомости.

Советы и рекомендации

Чтобы определить конец файла, используйте функцию file.eof() как и прежде.
Из-за завершающего переноса строки, также стоит проверить и имя. Если оно
было считает пустым, то можно считать, что файл закончился.