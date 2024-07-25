package org.example.sb01.models;

import lombok.Data;
import org.example.sb01.entity.Books;

@Data
public class BookModel {
    private String title;

    public static BookModel toModel(Books books) {
        BookModel model = new BookModel();
        model.title = books.getName();
        return model;
    }


}
