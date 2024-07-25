Задание: есть книжки, есть авторы. Автор может написать много книжек, книжка может быть написана несколькими авторами. Нужно: хранить в базе структуры данных, создать rest API для работы с ними. Использовать spring boot.

Пока не готово, скоро будет.

База создаётся автоматически, необходимо только исправить файл application.properties под свою СУБД
пример файла для PostgresSQL

spring.application.name=SB01
spring.jpa.hibernate.ddl-auto=create-drop
spring.datasource.url=jdbc:postgresql://localhost:5432/postgres
spring.datasource.username=postgres
spring.datasource.password=postgres
