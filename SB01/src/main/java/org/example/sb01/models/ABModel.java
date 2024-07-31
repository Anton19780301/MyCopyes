package org.example.sb01.models;


import lombok.Data;
import org.example.sb01.entity.Authors;
import org.example.sb01.entity.AuthorsBooks;
import org.example.sb01.entity.Books;

@Data
public class ABModel {
    private String name;
    private String title;

    public static ABModel toModel(AuthorsBooks ab) {
        ABModel model = new ABModel();
        model.name = ab.getAuthors().getName();
        model.title = ab.getBooks().getName();
        return model;
    }

}
